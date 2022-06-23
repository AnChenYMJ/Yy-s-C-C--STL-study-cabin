#include <iostream>
using namespace std;

int main()
{//基本数据类型
	int a = 26;		//初始化
	cout << a << endl;
					//对基本数据类型来说两种作用一样
	int b;			//赋值
	b = 27;
	cout << b << endl;


//数组
	int f[6] = { 1, 2, 3, 4, 5, 6 };	//初始化

	int g[6];							//赋值
	g[0] = 9;
	g[1] = 8;							//数组不能连续赋值，初始化可以

//结构体
	struct ST
	{
		int f;
		double h;
	};

	ST st = { 56, 87.78 };			//结构体变量初始化

	ST ts;
	ts.f = 99;						//结构体变量赋值
	ts.h = 99.11;

//引用与const
	int& k = a;//引用		//只能初始化，不能赋值(不初始化会报错)

	const int i = 55;		//只能初始化，不能赋值(不初始化会报错)


//函数定义与声明的区别也注意一下

	system("pause");
	return 0;
}