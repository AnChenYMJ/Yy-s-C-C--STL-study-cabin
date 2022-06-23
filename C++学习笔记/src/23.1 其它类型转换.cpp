#include<iostream>
using namespace std;

class Cfather
{
public:
	double a;
	virtual void fun()
	{
	
	}
};

class Cson:public Cfather
{
public:
	char b;
	virtual void fun() 
	{
	
	}
};

class Cother
{
public:
	int c;
};

int main()//static与const可能会常用到，剩下两种，就很少用了
{
	//1.查找资料，翻书，
	//2.新式转换能在早期避免程序员犯错误，有转换限制，旧式的完全不提示，不小心就出错
	//3.能不用就不用转换，尽量直观操作数据
	//4.书上说，不服就用C语言去吧



	///*const Cfather* p = new Cfather;
	//volatile Cson* p2 = new Cson;*/

	////const_cast		//使被修饰的指针去掉const或volatile
	////Cfather* p1 = const_cast<Cfather*>(p);//const_cast的作用是去掉被const（常量）修饰的指针
	////Cson* p3 = const_cast<Cson*>(p2);	//或者被volatile修饰的指针
	////转非指针时，要传地址或者引用
	//	
	////非法表达式，p去掉const的类型要与转变后的类型相同，即Cfather转变后还是Cfather
	////Cson* p4 = const_cast<Cson*>(p);//error: 从指向基类的指针到指向派生类的指针的强制转换要求显式类型强制转换(const_cast 除外)

	////Cson* p5 = (Cson*)p;//强转就没有顾虑了，直接转换



	////dynamic_cast	//父子类相互转换的运算符，或者自己转自己
	//Cfather* p = new Cfather;
	//Cson* c1 = new Cson;
	//Cother* o = new Cother;

	//Cfather* p6 = dynamic_cast<Cfather*>(p);//一、自己的类型转成自己的类型

	////Cson* c2 = dynamic_cast<Cson*>(p);//第一次时error: “dynamic_cast”:“Cfather”不是多态类型
	//									//因为这个要满足type、expression互为共有基类或者共有派生类
	//									//就是说，这两个类要有virtual（虚函数）
	//Cson* c2 = dynamic_cast<Cson*>(p);	//二、共有基类转派生类

	////Cfather* p7 = dynamic_cast<Cfather*>(c1);//三、共有派生类转基类
	////使用多态，继承（即虚函数）的原因是，避免小空间转成大空间，或者大空间转成小空间

	//Cother* o1 = dynamic_cast<Cother*>(c1);//编译器没有报错，但理论上这是不可行的，我们也不要用



	//reinterpret_cast		//危险类型转换
	Cfather* p = new Cfather;
	Cson* c1 = new Cson;
	Cother* o = new Cother;

	Cother* o3 = reinterpret_cast<Cother*>(p);	//对于结构复杂的有危险的类型转换用这个
	Cother* o4 = reinterpret_cast<Cother*>(c1);	//可能会出错的类型转换用这个

	struct dat		//书上的例子
	{
		short a;
		short b;
	};

	long value = 0xa224B118;
	
	dat* op = reinterpret_cast<dat*>(&value);//将long的4字节空间拆分成两个short的空间

	//注意，这个转换，转换的内存一定要够，否则报错
	//函数指针和数据指针不能相互转换
	//这种转换不可移植，因为不同系统的多数据存储顺序可能不同



	system("pause");
	return 0;
}