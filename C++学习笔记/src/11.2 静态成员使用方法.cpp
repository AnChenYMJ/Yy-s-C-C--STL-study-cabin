#include <iostream>
using namespace std;

class Ctea
{
private:
	//static int a;//静态成员也是受private的控制的
public:
	static int a;//静态成员的生命周期与程序共存亡
	int i;
	//static float f = 123.321f;//无法初始化
	static const char c = 56;//只能是静态常量整型变量才能够这样初始化

	Ctea()//:a(15),f(56.54)//“a”: 无法通过构造函数初始化静态类数据//静态成员无法通过初始化列表初始化
	{
		//a = 89;	//这样也不行，要类外初始化
					//教程视频里这样是赋值，是能够做到的，但我这里就不行
	}

	static void stc()//静态函数成员没有this指针，不能调用普通成员，只能调用静态成员
	{		//this指针是对象成员的默认参数
		a = 45;
		//i = 69;//错误
		cout << "static" << endl;
	}
	void show()
	{
		cout << a << endl;
	}

};

int Ctea::a = 58;//这就是给静态成员类外初始化//不要在前面加上static

int main()
{	//类名作用域
	cout << Ctea::a << endl;//通过类名作用域就能调用静态成员
	//因为静态成员不算是模板，与对象构建无关，而是有自己的内存空间，所以能直接调用
	Ctea::stc();//静态函数的调用方式也是两种：类名作用域、对象调用
	//与静态变量成员的性质一样，有自己的空间，与对象无关

	Ctea st;
	st.show();
	st.stc();

	system("pause");
	return 0;
}