#include <iostream>
using namespace std;

struct SM	//定义一个结构体类型，C++中结构体就是一个特殊的类
{
	int a;
	char b;

	void fun()	//C++的结构体中能定义函数，C语言中不能定义函数
	{
		cout << "Keep going! you're strong!" << endl;
	}

};


int main()
{	//C++中不用加struct就能使用结构体
	SM ST;//声明一个结构体变量
	ST.fun();//调用变量的成员


	system("pause");
	return 0;
}