#include <iostream>
using namespace std;

class Cfather
{
public:
	//virtual	int aa;		//虚 只针对函数成员，不针对数据成员
	//int aa;

	//virtual Cfather(): aa(11)//“inline”是构造函数的唯一合法存储类
	//{}					//构造函数默认是inline类型，不可以是别的如虚函数类型

	virtual inline void show()	//内联函数不可以是虚函数，虽然没有报错，但是这个函数不是内联函数
	{								//即inline失去了作用
		cout << "i am father" << endl;
	}

	virtual void show(int a)	//参数必须与子类一样
	{
		cout << "i am father" << endl;
	}

	//virtual int show()//重写虚函数返回类型有差异，且不是来自“Cfather::show”的协变
	//{				//只有协变函数才能与子类的返回值类型不同
	//	cout << "i am father" << endl;
	//}

	////virtual Cfather& show()//协变，即返回值是当前类（对象）的引用
	////{
	////	cout << "i am father" << endl;
	////	return (*this);
	////}

	//virtual void show()	//如果在覆盖的关系上使用虚函数，则是重写
	//{
	//	cout << "i am father" << endl;
	//}
};

class Cson:public Cfather
{
public:
	int aa;
	//virtual void show()//子类重写的函数默认是虚函数，下面有测试

	void show()			//前面隐藏的virtual可加可不加
	{
		cout << "i am son" << endl;
	}
	////virtual Cson& show()//协变，即返回值是当前类（对象）的引用
	////{
	////	cout << "i am son" << endl;
	////	return (*this);
	////}
	Cson():aa(1)
	{}
};

class Csonson:public Cson
{
public:
	void show()
	{
		cout << "i am child" << endl;
	}
};

int main()
{
	Cson* so = new Csonson;
	so->show();		//会发现调用的是sonson孙子辈的函数，证明了子类son重写的函数默认是虚函数

	Cfather* fa = new Cson;
	fa->show(1);	//掉用的是自己的函数，证明参数必须要与子类的参数一致
	fa->show();		//无法打印，证明了返回值除了协变，否则必须与子类一样
					//父类与子类的参数与返回值必须一样，返回值有一个特例就是协变

	//注：笔记有点乱，就结合Xmail课件看

	delete fa;
	delete so;//注意释放空间，别忘了


	system("pause");
	return 0;
}