#include <iostream>
using namespace std;

//函数原型（函数声明）
void fun1(int i = 26, char c = 'y');//参数可以全部指定缺省值（默认值）

	//断开不连续指定或者从左向右指定，就会报错
//void fun2(int i = 27, char c, float f = 164.87)//error C2548: “fun2”: 缺少形参 2 的默认实参
void fun2(int i , char c = 'Y', float f = 164.87)//参数也可以部分指定默认值
{						//但是C++部分指定有固定规则，必须从右向左连续指定
	cout << i << ' ' << c << ' ' << f << endl;
}

int main()
{
	fun1();//全部指定参数默认值的函数，可以不加实参调用//成功打印

	fun2(27);//部分指定的函数，我们可以传递实参给缺少值的参数//成功打印
	//fun2();// error C2660: “fun2”: 函数不接受 0 个参数//必须把缺少值的参数补上

	fun1(28, 'n');//有参数默认值的函数，我们再传递实参，实参会将默认值覆盖掉
	fun2(28, 'n', 160.56F);//float要加f的后缀，否则默认为double类型
	//不传递实参，则会按默认值来执行，提高了灵活性。

	return 0;
}

//void fun1(int i = 26, char c = 'y')//error C2572: “fun1”: 重定义默认参数 : 参数 1
//当我们使用函数原型（函数声明）时写了参数默认，下面的定义就不需要再写默认值了，写了会报错
void fun1(int i, char c)
{
	cout << i << ' ' << c << endl;
}