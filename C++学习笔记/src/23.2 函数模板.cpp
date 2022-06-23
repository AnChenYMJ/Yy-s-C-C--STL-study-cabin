#include <iostream>
using namespace std;

	//TT即代表所有参数类型，格式就是这样，可以起任何名字，用大写比较能区分而已
template <typename TT>		//函数模板的形式，多态和模板是泛型编程的思想
void cat(TT o)				//泛型编程即同样的代码实现不同的功能
{
	cout << o << endl;		//对比下面的函数重载，会发现函数模板缩减了很多代码，只用一段代码即可
}							//而且实现的功能更全面

//template:模板    //class与typename的作用是一样的，用type感觉更能体现模板，但都一样
template <class TT, typename TR>		//这一句只对挨着的代码段有效
void cat1(TT o, TR i)				
{
	cout << o << ' ' << i << endl;		
}							


void dog(int a)		//函数重载，C++支持，C语言不支持
{
	cout << a << endl;
}
void dog(double b)	//又多又繁琐，对于传递进来的参数
{
	cout << b << endl;
}
void dog(char c)
{
	cout << c << endl;
}

int main()
{
	cat(12.98);

	cat1("Yy keep going", "26岁了，不年轻了啊");



	system("pause");
	return 0;
}