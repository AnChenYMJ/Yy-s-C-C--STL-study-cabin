#include <iostream>
using namespace std;


int main()
{
	int a = 27;
	int& c = a;//这就是引用的形式
				//就是c也是指向a的空间，a与c是一样的了
				//就是给变量起别名，而typedef是给类起别名
	cout << a << endl;

	c = 28;
	cout << a << endl;

	int& d = c;
	d = 29;
	cout << a << endl;

	int& e = d;	//注意，引用的变量，引用后不能再指向别的变量了
	e = 30;
	cout << a << endl;

	cout << &a << ' ' << &c << ' ' << &d << ' ' << &e << endl;
	//打印这些引用的变量地址，会发现都是一样的，证明了引用的成功

	int f = 23;//注意，引用的变量，引用后不能再指向别的变量了
	//int& e = f;// “e”: 重定义；多次初始化

	//int& y;//error：“y”: 必须初始化引用   引用必须初始化

	e = f;//这是把f的值赋值给e，不是再次引用


	return 0;
}