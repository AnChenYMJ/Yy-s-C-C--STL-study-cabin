#include <iostream>
using namespace std;

class Coji		//访问修饰符的范围是出现关键字开始到结束或者另一个修饰符
{
public:			//public：公共的  使它修饰的成员对类以外可见，即类之外能调用它修饰的成员
	int a;
	void fun1()
	{
		cout << "fun1" << " " << a << endl;
	}
private:		//private：私有的  使它修饰的成员对类外不可见，即类外无法调用它修饰的成员
	void fun2()
	{			//private 有安全性的作用，防止类外被修改等作用
		fun1();
	}

public:			//经验：访问修饰符可当作自己编程时分类的标志。
	int b;
	int c;

public:			//访问修饰符写多少都行，没有限制
	double e;
	double d;
};

void gi()
{
	Coji op1;	//调用类成员方式一：函数调用
	op1.fun1();
}

class CUI		//类中不主动声明的话，默认为private//结构体默认为public
{
public:
	Coji bu;
	void fun3()	//另一个类中调用成员，必须要在函数中调用，
	{			//因为执行语句是无法作为成员的，只能是数据或函数类型。

		bu.fun1();	//调用类成员方式二：另一个类调用
	}
};

struct Stu	//C++中结构体是类的一种特定情况
{			//结构体不加修饰符则默认为public
public:
	int a = 27;	//结构体能加修饰符是C++标准特有的
private:		//C语言的标准中是不能够这样加修饰符的
	int b = 26;
};

int main()
{
	Coji lkj;
	lkj.a = 26;	//调用类成员方式三：主函数调用
	lkj.fun1();

	gi();

	CUI hg;
	hg.fun3();

	//lkj.fun2();//“Coji::fun2”: 无法访问 private 成员(在“Coji”类中声明)

	system("pause");
	return 0;
}