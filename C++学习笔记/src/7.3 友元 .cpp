#include <iostream>
using namespace std;

class CStu
{
private:
	int a = 26;
	void fun()
	{
		cout << "fun" << " " << a << endl;
	}
private:	//类外访问private的方式：友元
	friend void fun1();	//这就是友元的声明方式
public:					//能有多个友元
	friend class CTeach;//友元的作用是将声明的函数或类变成类内，这样调用时所有修饰符都能通过，因为是类内
protected:	//类外访问protected的方式：继承、友元
	friend int main();	//主函数也能被友元修饰

public:
	int fun3()	//接口函数，这样就能利用返回值传递被private修饰的变量值了
	{			//原理是这个接口函数是类内，调用变量没阻碍。
		return a;
	}
};
						//一般不使用友元，因为友元会破坏类的封装性
void fun1()
{
	CStu stu;
	stu.fun();
}

class CTeach
{
public:
	CStu Tea;
	void fun2()
	{
		Tea.fun();
	}
};

int main()
{
	CStu zaza;
	zaza.fun();

	fun1();

	CTeach su;
	su.fun2();

	int c = zaza.fun3();//利用接口函数把被private修饰的变量传递出来
	cout << a << endl;

	system("pause");
	return 0;
}