#include <iostream>
#include "13.2.h"
using namespace std;

#define SUM(x) (x*x)  //要想真正两数相乘，必须（（x）*（x））

inline void fun(int i)//在类外，必须加上inline的前缀才算内联函数
{						//内联函数可以有多个定义
	cout << (i * i) << endl;//一般来说内联函数把定义写在头文件中，注意是定义不是声明
}

class CST
{
public:		//在类内，所有普通函数都默认为内联函数
	//void fun()		 //隐式内联函数
	//{

	//}
	inline void fun()//显式内联函数
	{

	}
};

int main()
{
	cout << SUM(2 + 3) << endl;//结果为11，因为宏是单纯的替换，这里执行的是（2+3*2+3）先乘后加为11
			
	fun(5);//可见，内联函数相比宏要更加智能一些


	return 0;
}