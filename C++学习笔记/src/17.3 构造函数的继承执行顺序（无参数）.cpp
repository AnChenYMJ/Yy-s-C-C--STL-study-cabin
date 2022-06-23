#include <iostream>
using namespace std;

class CPeople
{
public:
	CPeople()
	{
		cout << "CPeople" << endl;
	}
};

class xiaoxi : public CPeople
{
public:
	xiaoxi()
	{
		cout << "xiaoxi" << endl;
	}
};

class xiaojiao : public xiaoxi
{
public:
	xiaojiao()
	{
		cout << "xiaojiao" << endl;
	}
};

int main()
{
	xiaoxi xi;//可以看到构建xiaoxi对象时，构造函数的执行顺序：父类 》》子类

	xiaojiao zhi;//多层继承时，构造函数的执行顺序是：最基类一直到最子类

	//对象构建时的空间也是按照 最基类到最子类 的顺序来申请空间的。
	//构建xiaojiao时发现继承了xiaoxi，构建xiaoxi时发现继承了Cpeople，然后按顺序再从最基类开始构建出来

	system("pause");
	return 0;
}