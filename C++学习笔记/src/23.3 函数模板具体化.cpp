#include <iostream>
using namespace std;


template <typename TT>		//一般来说，函数模板覆盖大多数类型，但是特殊类型如结构体就无法传递
void cat(TT o)				//原理是根据参数类型在这里生成函数定义
{
	cout << o << endl;		
}		

struct ui
{
	int a ;
	int b ;
};

template <> void cat<ui>(ui ii)	//模板的具体化，就是将特殊的参数类型提出来单独处理
{
	cout << ii.a << " " << ii.b << endl;
}

template <> void cat<int>(int n)	//具体化和函数模板的原理是：当传递进参数时，
{									//根据参数类型在这里生成函数定义
	cout << n << endl;
}

void cat(int c)
{
	cout << c << endl;
}

	//没有函数实现					//函数模板是传递什么类型就生成什么的函数定义
template void cat<double>(double d);//实例化就是将double类型的函数定义单独声明出来
									//底层实现的，我们宏观上理解就好了
int main()
{	//具体化
	cat(12.98);

	ui iu = {11, 77};//执行顺序是这样，如果满足具体化条件，优先执行具体化，不执行函数模板
	cat(iu);		//没有具体化时，传递结构体参数，会有报错，因为不知道传递结构体哪个成员

	cat(16);		//如果自定义了普通类型的具体化，执行优先级是：自定义>函数模板
	cat(55);		//如果有普通函数，优先级是：普通函数>具体化>函数模板


	//实例化
	//实例化就是将函数定义单独声明出来，就不需要执行时在函数模板那里生成函数声明


	system("pause");
	return 0;
}