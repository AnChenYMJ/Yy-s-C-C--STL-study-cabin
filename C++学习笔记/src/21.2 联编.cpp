#include <iostream>
using namespace std;

class Coldman
{
public:
	void fun()
	{
		cout << "keep going Yy" << endl;
	}

	void show()
	{
		cout << "so old" << endl;
	}
};

class Cman : public Coldman
{
public:
	void show()
	{
		cout << "so strong" << endl;
	}
};

class Cwoman : public Coldman
{
public:
	void show()
	{
		cout << "so pretty" << endl;
	}
};

int main()//动态联编是针对C++多态的，C语言里全部是静态联编
{
	//就是将模块或者函数合并在一起生成可执行代码的处理过程（函数调用），
	//按照联编所进行的阶段不同，可分为两种不同的联编方法：静态联编和动态联编。

	//静态联编：指在编译阶段就将函数实现和函数调用关联
	Coldman om;
	om.fun();		//这样就一定会调用Coldman中的fun函数//属于静态联编

	Coldman* ol = new Cman;
	ol->show();		//这样以一定调用的是子类的show函数（覆盖重写）//属于静态联编


	//动态联编：指在程序执行的时候才将函数实现和函数调用关联
	Coldman* old;
	int n;
	cin >> n;

	switch (n)
	{
	case 1: old = new Cman; break;
	case 2: old = new Cwoman; break;
	}

	old->show();	//这样的话，就只能在正在编译的时候才能将函数整合输出，才能知道调用的是哪个函数
					//这就是动态联编//书上的例子


	system("pause");
	return 0;
}