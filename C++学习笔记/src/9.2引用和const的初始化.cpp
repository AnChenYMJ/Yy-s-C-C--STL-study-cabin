#include <iostream>
using namespace std;

class Cstu
{
public:
	int a;
	int& b;
	const int f;
	/*Cstu() :a(15), b(a), f(56)//成功赋值
	{
		cout << a << " " << b << " " << f << endl;
	}*/

	/*Cstu(int g) :a(g), b(g), f(56)//show里的打印b出错，原因是int g 是局部变量，超出作用域会被回收
	{								//所以里面的值超出作用域会变成不知道是哪个
		cout << a << " " << b << " " << f << endl;
	}*/

	Cstu(int &g) :a(g), b(g), f(g)//成功赋值打印，因为引用会一直存在，直到对象没有了
	{
		cout << a << " " << b << " " << f << endl;
	}
	void show()
	{
		cout << a << " " << b << " " << f << endl;
	}


};

int main()
{
	int o = 99;
	Cstu su(o);
	su.show();

	system("pause");
	return 0;
}