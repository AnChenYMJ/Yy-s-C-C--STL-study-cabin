#include <iostream>
using namespace std;

class Coldman
{
private:
	int a;
	virtual void fun()
	{
		cout << "fun" << endl;
	}
public:
	virtual void show()
	{
		cout << "show" << endl;
	}
	Coldman():a(3)
	{}
};

class Cman: public Coldman
{
private:
	void fun()
	{
		cout << "no fun" << endl;
	}
public:
	void show()
	{
		cout << "no show" << endl;
	}
};

int main()//_main报错时，可能出现的问题：主函数写错，主函数多了，主函数没写，文件名写错
{
	//这节课的内容是取上节课所说的虚函数列表的内容
	//对象空间最开始的4字节内容就是虚表（虚函数列表）的地址，叫做虚指针

	Coldman* fa = new Cman;//创建对象，且有继承关系，且父类指针指向子类
	//fa->show();
	//(int*)fa//将对象地址转换成int*类型
	//*(int*)fa//操作对象地址指向的对象空间
	//(int*)(*(int*)fa)//将对象空间转换成int*类型
	//*(int*)(*(int*)fa)//操作这个对象空间

	//这里不太懂为什么，应该查了清楚一下
	typedef void (*p)();//(*p)()就代表void返回值函数的类型，void函数类型的别名

	//一开始用了(*p) 报错了//且跳过了private的封锁，直接访问到了虚表且用虚表里的函数地址调用
	((p)(*((int*)*(int*)fa + 0)))();	//老师写
	((p)(*((int*)*((int*)fa) + 0)))();	//自写

	((p)(*((int*)*((int*)fa) + 1)))();//成功打印输出

	//操作对象空间的虚拟化列表结尾，都是0000，要把第三个空间转成int*类型装到指针pp里
	int* pp = (int *)*((int*)*((int*)fa) + 2);
	cout << pp << endl;//打印了0000，证明了虚表结尾装的是0000

	//注意：父类的每个函数的地址都在虚表中有一席之地，根据子类重写情况覆盖虚表的内容

	delete fa;//注意要释放空间，别忘了

	system("pause");
	return 0;
}