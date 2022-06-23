#include <iostream>
using namespace std;

void test(char c);//函数声明则能增加函数的作用域 ////此函数作用域，从此向下

void test(int a)
{
	cout << a << endl;
}						//此函数作用域，从此向下

//int test(int a)//error C2371: “test”: 重定义；不同的基类型
//{				//可以证明返回值不作为重载函数的条件
//	cout << a << endl;
//	return 0;
//}

//void test(int a, int b = 27)//error C2668: “test”: 对重载函数的调用不明确
void test(int a, int b)//如果给参数默认值，就可能会导致上面的情况，调用不明确
{
	cout << a << ' ' << b << endl;
}						//此函数作用域，从此向下

void test(float a)
{
	cout << a << endl;
}


						//以下则是上诉函数的公共作用域
int main()				//以上函数的公共作用域即是重载作用域
{
	test(165.34f);//注意float或long等数据类型，一定要加后缀，否则会出问题

	return 0;
}

void test(char c)
{
	cout << c << endl;
}				