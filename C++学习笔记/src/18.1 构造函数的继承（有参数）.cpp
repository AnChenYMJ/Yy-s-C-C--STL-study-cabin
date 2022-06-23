#include <iostream>
using namespace std;

class Cfather
{
public:
	Cfather(int a)
	{
		cout << "i am father \n";	//\n效率比endl高，都是换行
	}
};

class Cson : public Cfather
{
private:
	int na;
public:	
	//Cson()//error C2512: “Cfather”: 没有合适的默认构造函数可用
	//{		//即要把父类的参数传过去

	//}
	//如果父类的构造函数有参数，那我们就必须把父类的构造函数写出来

	//Cson(int a, int b) : Cfather()//error C2512: “Cfather::Cfather”: 没有合适的默认构造函数可用
							//父类有参数的话必须传递一个参数过去
	Cson(int a, int b) : Cfather(b)//通过初始化列表把父类的参数传递过去
	{						//可以传递变量，也可以直接传递常量比如Cfather(15)
		na = a;
	}
};



class CPeop
{
public:
	CPeop(int a)		//当基类有构造函数重载时，其子类根据传递参数的不同来选择不同的构造函数
	{
		cout << "i am people1 \n";
	}
	CPeop(int h, int l)
	{
		cout << "i am people2 \n";
	}
};

class Coldman : public CPeop
{
public:
	Coldman(int a, int b) : CPeop(a)//可以给父类传递变量，也可以传递常量
	{								//但不能隔代传递，只能父子类挨个传递
				
	}
};

class Cman : public Coldman
{
public:
	Cman(int a, int b, int c) : Coldman(b, c)//, CPeop(a) //非法的成员初始化:“CPeop”不是基或成员
	{									//孙子类只能传递参数给子类，不能给祖父类，不能隔代
			
	}	//当然，如果父类构造函数没有参数，那我们就不需要传递参数
};
	
int main()
{
	Cson doct(16, 89);//双层

	Cman su(45, 85, 78);//多层，多参数

	system("pause");
	return 0;
}