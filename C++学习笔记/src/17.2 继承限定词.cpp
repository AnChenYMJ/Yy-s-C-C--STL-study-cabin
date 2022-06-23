#include <iostream>
using namespace std;

class Cpep
{
private:
	int a = 1;
	void kee1()
	{
		cout << "father:keep1" << endl;
	}
protected:
	int b = 2;
	void kee2()
	{
		cout << "father:keep2" << endl;
	}
public:
	int c = 3;
	void kee3()
	{
		cout << "father:keep3" << endl;
	}
};

class Cxiaoxi : private Cpep//继承修饰符
{
public:
	void kee4()			//private的继承修饰符，基类中在子类中都是私有的private
	{
		
		kee3();			//但这里竟然通过函数调用了kee3（）；
	}
};

class Cxiaoliang : protected Cpep
{
public:
	void kee5()
	{
		kee3();
	}
};

class Cxiaojiao : public Cxiaoliang//子类可多层继承
{
public:
	void kee6()
	{
		kee5();
	}
};

//继承修饰符的区别
//private：父类中的所有访问修饰符的权限都变成private，都不可见
//protected：父类中的piublic变成protected，而protected和private则变成private。相当于降低整体访问权限
//public：父类中的访问权限本来是什么样，就照搬过来，没有改变

int main()
{
	Cxiaoxi xi;
	xi.kee4();

	Cxiaoliang liang;
	liang.kee5();

	Cxiaojiao zhi;//子类多层继承
	zhi.kee6();
	zhi.kee5();

	system("pause");
	return 0;
}