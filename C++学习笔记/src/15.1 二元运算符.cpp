#include <iostream>
using namespace std;

class Cstu		//运算符C++比C语言多了一些，我们可以翻书看一看有哪些，可以找电子版的书
{					//C++ primer plus 而且运算符的顺序与C语言好像有点不太一样
public:
	int ange;
	Cstu(int b)
	{
		ange = b;
	}

	int operator >= ( Cstu& b)	//类内关系运算符
	{
		return (this->ange >= b.ange);//关系运算符如果满足则得到1（真），不满足则得到0（非真）
	}

	int operator|( Cstu& b)//类内位运算符
	{
		return (ange | b.ange);
	}

	int operator||( Cstu& b)		//类内逻辑运算符
	{
		return (this->ange || b.ange);
	}
};

int operator <= (Cstu& a, Cstu& b)	//类外关系运算符
{
	return (a.ange <= b.ange);//关系运算符如果满足则得到1（真），不满足则得到0（非真）
}

int operator&(Cstu& a, Cstu& b)		//类外位运算符
{
	return (a.ange & b.ange);
}
int operator&&(Cstu& a, Cstu& b)		//类外逻辑运算符
{
	return (a.ange && b.ange);
}
int main()
{
	//Cstu te;//如果构造函数有参数，而我们声明对象时不传参数，对象是没有构建成功的
			//所以没有成功构建的对象不占空间

	Cstu te(5);
	Cstu su(7);

//二元运算符：
	//算数运算符：+ - * / % 
	//关系运算符：>= <= > < != ==
	//位运算符：^ & |
	//逻辑运算符：&&	||

	cout << (te <= su) << endl;//关系运算符
	cout << (te >= su) << endl;

	cout << (te & su) << endl;//位运算符
	cout << (te | su) << endl;

	cout << (te || su) << endl;//逻辑运算符
	cout << (te && su) << endl;

	//注意：如果断点调试、断点打上没效果，重启一下编译器就可能会好了
	system("pause");
	return 0;
}