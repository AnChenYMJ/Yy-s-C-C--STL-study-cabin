#include <iostream>
using namespace std;

class Cfather
{
public:				//看来virtual只能使用在函数上，数据成员不能修饰
	//virtual int aa;	//“Cfather::aa”: 不允许在数据声明中使用“virtual”
	int aa;
	Cfather()		
	{
		aa = 22;
	}
	virtual void show()	//有virtual就调用子类的函数，没有virtual就调用自己的函数
	{
		cout << "i am father" << endl;
	}
};

class Cson : public Cfather
{
public:
	int aa;
	Cson() :aa(11)
	{

	}
	void show()		//父类和子类中函数名字相同，想使用哪个函数就使用虚函数
	{
		cout << "i'm son \n";
	}
};

class Cman : public Cfather
{
public:
	void show()
	{
		cout << 250 << endl;
	}
};

class Coldman : Cson
{
public:
	void show()
	{
		cout << 250 << endl;
	}
};



int main()
{
	//本课的测试要分为两种情况：基类中不加virtual 修饰函数
							//基类中加上virtual 来修饰函数，使函数变成虚函数


	//int* ii = new char;		// “初始化”: 无法从“char *”转换为“int *”
								//普通的数据类型指针不能申请其它类型的空间

	//Cfather* fat = new Coldman;// 无法从“Coldman *”转换为“Cfather *”//无法隔代申请
	Cfather* fat = new Cson;	//对象指针能申请其它类的空间，编译器完全允许这种做法，这是多态的基础
								//但仅限于父类对子类的申请空间
	//Cson* so = new Cfather;	//子类指针无法指向父类
	fat->show();				//虽然指向了子类空间，但只能调用自己的成员	
	cout << fat->aa << endl;	//原因是，指针如何访问空间，由空间的类型决定，而这里空间类型是父类的
	//此处仍打印了基类的int aa	//后面的子类只是空间大小，所以只能访问自己的成员
	
	fat->show();				//在父类内，使用virtual修饰与子类同名的函数（仅限于函数），则会把父类中的该函数变成
								//虚函数，我们调用父类的该虚函数成员时，就变成调用子类的同名函数了

	Cfather* so = new Cman;		//与上面的一对比，我们只需要修改指向的空间就能够完成，多种状态切换
	so->show();					//这一行不用改变，改变上面指向空间就实现了多种状态的切换，执行不同的结果
								//这就是多态

	//注意：这种多态 只能申请栈区变量，不能申请堆区变量（老师也不知道咋申请）
	//堆区就是操作系统申请，操作系统释放的空间。


	delete fat;
	delete so;//注意释放空间，别忘了

	system("pause");
	return 0;
}