#include <iostream>
using namespace std;

class COUt
{
public:
	int ange;
	COUt() :ange(19), ci2(this)
	{}
		

public:
	class CIn
	{
	public:
		int high;
		CIn()
		{
			high = 27;
		}

		void show()
		{					
			//内部的类直接使用外部类成员是不行的。
			//cout << ange << endl;//error：“COUt::ange”: 不是类型名称、静态或枚举数
			COUt co;
			cout << co.ange << endl; //可以在内部类构建一个对象，用对象来与外部类来交流
		}
	};
public:
	CIn ci;		//可以在外部类构建一个内部类的对象，来实现与内部类的交流

public:
	class CIn2
	{
	public:
		int high2;
		COUt* py;
		CIn2(COUt *p):py(p)		//将外部类的指针传递进来，时间交流通信
		{
			high2 = 27;
		}

		void show()
		{								//就无需创建对象来使用外部类成员，且外部类成员改变就能传递进来了
			cout << py->ange << endl;	//通过外部类的指针来实现成员的共享调用
		}
	};
public:
	//CIn ci2(this);//类的成员是无法赋值的，这里的参数就相当于赋值
	CIn2 ci2;//上面的构造函数中给对象赋值了参数，
};

int main()
{
	COUt su;
	su.ci.show();	//通过外部类来调用内部类的函数

	su.ange = 29;	//会发现改变了ange的值，但还是打印了19
	su.ci.show();	//原因是因为su与co是不同的对象，改变了su的成员值，但没改变对象co的成员值
					//它俩有自己独立的空间，是不同的对象,注：co是show函数里的对象
	
	su.ci2.show();	//成功打印29，即对象su改变后的值，利用指针来实现外部类与内部类的共享、通讯

	system("pause");
	return 0;
}