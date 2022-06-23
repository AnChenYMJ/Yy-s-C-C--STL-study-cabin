#include <iostream>
using namespace std;

//类就是所有对象的公共属性的集合
class Ccabin //类的定义方式，与结构体类似，结构体就是类的一种特定情况
{
public:	//访问修饰符，下节课再细讲
	int a;//类的成员一般就两种：数据成员、函数成员
	void fun()
	{
		cout << "fun" << " " << a << endl;
	}
};	//记得加分号

int main()
{
	Ccabin uai;//后面的uai就是对象，这是对象的声明方式,这是栈区对象，由操作系统申请，由操作系统释放
	uai.a = 26;//给对象的成员赋值、调用。
	uai.fun();

	Ccabin* jiu = new Ccabin;//类的对象可以是指针类型，这是堆区对象，由程序员申请与释放
	//但指针对象一定要申请一块类的大小的空间；
	jiu->a = 27;//指针类型的对象的调用、赋值方式用 ->
	jiu->fun();	//堆区对象成员的调用格式

	Ccabin* aid = new Ccabin;//对象可以有无数个，这些对象有统一的属性
	aid->a = 28;//这些对象都归属于一个类
	aid->fun();

	system("pause");
	return 0;
}