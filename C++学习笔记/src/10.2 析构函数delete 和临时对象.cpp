#include <iostream>
using namespace std;

class CTea
{
public:
	int i;
	int* pp;
	CTea(int g):i(15)
	{
		cout << "构造函数" << endl;
		pp = new int[10];//如果我们在类中有一个成员用到了nwe的堆区空间，往往在析构函数中释放它
	}
	~CTea()
	{
		cout << "析构函数" << endl;
		delete pp;		//可以在别的函数中释放它，但一般放在析构函数中更稳妥，因为如果忘记释放
	}			//那块申请的空间将会一直存在，
};

int main()
{
	//CTea* su = new CTea;
	//delete su;//断点调试发现delete释放空间后执行析构函数

	//{
	//	CTea* du = new CTea;//只是将指针对象放到花括号内断点调试会发现跳过了析构函数。
	//}						//原因是堆区空间在出了这个对象作用域后依然不会释放
							//所以证明析构函数是在对象释放时执行

	CTea(25);//这就是临时对象的声明定义方式，作用域只在这个语句里，出了语句就自动释放
		//可以传参数，有对象的所有功能

	int f = 12;		//常量直接给f赋值了，可见比临时变量的效率要高。
	int y = int(12);//临时变量，临时变量会先制造一个变量，再给变量赋值，然后再用这个变量给y赋值

	system("pause");
	return 0;
}