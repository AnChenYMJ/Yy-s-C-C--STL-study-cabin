#include <iostream>
#include "8.2.h"
using namespace std;

class Cabin
{
public:
	int a;
	float f;

	//Cabin()	//C++默认的构造函数就是这样，什么都没有，当我们自定义了构造函数，就会把这个默认的覆盖掉
	//{
	//}

	Cabin()//利用参数来给成员赋值
	{					//构造函数能够函数重载
		a = 156;
		f = 257.89f;
	}

	Cabin(int b, float t = 56.35f)//参数可以像函数一样给默认值，注意顺序是从右向左连续赋值
	{
		a = b;
		f = t;
	}
};


//类外定义构造函数前必须加上作用域
Ctea::Ctea()	//类的声明放在了8.2.h的头文件中
{
	a = 156;
	f = 257.89f;
}
				//函数原型中有默认值这里就不要再写了，否则会报错
Ctea::Ctea(int b, float t)
{
	a = b;
	f = t;
}
	//类外函数定义的作用域加在函数名前
int Ctea::fun()
{
	cout << f << endl;
	return 0;		//C++中必须要加返回值，否则会报错
}

int main()
{
	Cabin st(25, 17.25f);
	cout << st.a << " " << st.f << endl;

	Ctea te(85, 78.00f);
	te.fun();
	cout << te.a << " " << te.f << endl;

	system("pause");
	return 0;
}