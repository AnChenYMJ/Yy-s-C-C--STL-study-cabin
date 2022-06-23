#include <iostream>
using namespace std;


int main()//* 的三种作用
{	//作用一：在声明指针时，表示这是一个指针变量
	int a = 26;
	int* p = &a;


	cout << *p << endl;
	*p = 27;		//作用二：地址操作符，指针变量加上*，就能操作所指向的空间
	cout << *p << endl;


	int b = 28;		//作用三：乘法运算符，在运算式中做乘法运算
	int c = 28 * 5 * b;
	cout << c << endl;

	//内存操作：读、写、取地址。（三种）
	//奇怪的写法有可能让自己理解更深刻，因为错误了自己要找究竟是哪里错误
	//编写代码不要拘泥于形式，想怎么写就怎么写，只要符合逻辑


	system("pause");
	return 0;
}