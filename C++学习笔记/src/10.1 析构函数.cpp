#include <iostream>
using namespace std;

class Ctea
{
public:
	int age;

	Ctea():age(13)	//构造函数		//在对象创建时运行，可以有参数
	{			//能够重载
		cout << "构造函数" << endl;
	}

	~Ctea()		//析构函数		//与构造函数相反，在对象消亡释放空间时时运行，没有参数，参数类型是void
	{			//作用，比如我们给成员new了空间，则能将其释放掉
		cout << "析构函数" << endl;//不能重载，类比构造函数，默认的析构函数什么都不执行
	}
};

int main()
{	
	{		//局部对象，超过}则释放空间
		Ctea su;//断点调试观察析构函数的运行次序，在局部变量中 到了}就执行析构函数
	}
	
	Ctea syu;//断点调试能发现全局析构函数在 return 0之后执行
	//原因是执行到return就结束函数，不再继续往下执行，所以主函数中return后执行析构函数

	system("pause");
	return 0;
}