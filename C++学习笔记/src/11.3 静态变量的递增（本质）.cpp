#include <iostream>
using namespace std;

class Cteac
{
public:
	static int i;//静态成员是类的属性，与对象无关，
	Cteac()		//无论多少个对象，它们使用的静态成员都是同一块空间
	{
		i++;
	}

};

int Cteac::i = 0;

int main()
{
	Cteac su[6];//这是一个对象数组 ，5个元素都是一个Cteac的对象
	//这样的话，每创建一个对象，就会调用一次该对象的构造函数给i自加1.

	cout << Cteac::i << endl;//输出6，证明了静态成员是自己独立空间，所有同类对象使用同一个静态成员空间

	//因此静态成员可作为控制所有同类对象的作用，只要在一个对象里修改了静态成员
	//所有的同类对象的静态成员也跟着改变


	return 0;
}