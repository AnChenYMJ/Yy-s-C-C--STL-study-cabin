#include<iostream>
using namespace std;

class Coldman
{
public:
	~Coldman()
	{
		cout << "so old" << endl;
	}
};

class Cman:public Coldman
{
public:
	~Cman()
	{
		cout << "so strong" << endl;
	}
};

class Cfather
{
public:
	virtual ~Cfather()
	{
		cout << "father" << endl;
	}
};

class Cchild :public Cfather
{
public:
	virtual ~Cchild()
	{
		cout << "child" << endl;
	}
};

class Cwoman
{
public:
	~Cwoman()
	{
		cout << "pretty girl" << endl;
	}
};

int main()
{
	Coldman* ol = new Cman;

	//delete ol;//发现只调用了父类的析构函数，这时候子类的空间并没有被释放掉
	delete (Cman*)ol;//没有利用虚析构	//利用这种方式，父类和子类的析构函数都调用了，且两个空间都释放掉了

	Cfather* fa = new Cchild;

	//delete fa;//利用了虚析构 //发现父类和子类的析构函数都调用了，这时候父类和子类的空间都释放掉了

	delete (Cwoman*)fa;//利用了虚析构	//发现只调用了指针所指向的不相干的Cwoman的析构函数
			//但此时父类和子类的空间都释放掉了，因为虚析构的原因。
			//delete的属性就是，写谁的指针，它就调用谁的析构函数
			//这样就有一个问题：如果父类和子类中的析构函数里有释放申请空间的成员的语句
			//那这样无法调用父类和子类的析构函数，那些成员空间就无法释放
	//所以要注意成员空间无法释放的问题，只要用了虚析构，两块空间就都会释放，但成员空间就不一定了，看delete后的指针是谁


	system("pause");
	return 0;
}