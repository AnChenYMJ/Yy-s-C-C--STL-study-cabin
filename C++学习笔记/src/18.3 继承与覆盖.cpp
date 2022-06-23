#include <iostream>
using namespace std;

class COldman
{
public:
	const static int b = 1;
	int a;
	COldman() :a(56)
	{
	}
};

class Cman : public COldman	//没加继承限定词，发现默认的是private,
{								//我的编译器不知道怎么回事private继承没有保护父类数据
public:
	const static int k = 3;
	int a;
	Cman()
	{
		a = 89;
		//cout << (COldman::a = 98) << endl;//不知道怎么回事private继承没有从子类内保护父类数据
	}
	void fun()
	{
		cout << (COldman::a = 98) << endl;
	}
	void fun1()
	{
		cout << "i am man" << endl;
	}
	void fun1(int a)
	{
		cout << "i am man" << endl;
	}

	friend void show2();
};

class Cchild:public Cman
{
private:
	int c;
public:
	int a;
	Cchild() :a(11)
	{
		c = 55;
	}
	void show1()
	{
		cout << a << endl;
	}
	void fun1()
	{
		cout << "i am child" << endl;
	}
};

//void show2()
//{
//	Cchild ma;				//下面的error证明了父类的友元不能继承给子类
//	cout << ma.c << endl;	// “Cchild::c”: 无法访问 private 成员(在“Cchild”类中声明)
//	cout << "i am 友元" << endl;
//}

int main()
{
	Cman man;
	cout << man.COldman::a << endl;//类外private继承限定词起作用了，无法输出，换成public继承限定词
									//就可以输出了，证明了类外private继承限定词起作用
	man.fun();	//但是子类内能用函数调用父类的成员，private继承限定词没有起作用

	Cchild su;//子类的对象
	su.show1();//11 父类的a没有调用，而是优先调用了子类中的a，子类中的a把父类中的a覆盖了
	cout << su.Cman::a << endl;//要想使用父a，就要用类名作用域调用

	su.fun1();//对于函数名称一样来讲，也是默认优先输出子类函数，不是函数重载,而是覆盖关系
	//su.fun1(15);//error C2660: “Cchild::fun1”: 函数不接受 1 个参数//证明了父子类的函数同名，不是重载
	su.Cman::fun1(15);		//要想调用父类同名函数，必须使用类名作用域

	//show2();

	cout << su.b << endl;//静态成员是公用的，大家都能用，且只有一份（即只有一个空间，大家公用）
	cout << man.b << endl;//静态成员是公用的，大家都能用，且只有一份（即只有一个空间，大家公用）


	delete su;
	delete man;//注意释放空间，别忘了

	system("pause");
	return 0;
}