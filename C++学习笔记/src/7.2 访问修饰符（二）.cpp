#include <iostream>
using namespace std;

class OPJ
{
protected:
	int a;
	void fun()
	{
		cout << "fun" << " " << a << endl;
	}

public:		//公共的  都能使用
private:	//私有的  只有类内使用
protected:	//受保护的  类内 与 子类 可使用  //子类后面会学到
};

void yu()
{
	OPJ FT1;
	//FT1.fun();	//可见，三种方式都不能访问
}

class TU
{
public:
	OPJ FT;
	void fun1()
	{
		//FT.fun();	//可见，三种方式都不能访问
	}
};

class XYT : public OPJ		//这是OPJ的子类
{
	void fun2()
	{
		fun();		//能够使用而不报错，证明protected修饰符，子类可以使用
	}
};

int main()
{
	OPJ FT2;
	//FT2.fun();		//可见，三种方式都不能访问

	system("pause");
	return 0;
}