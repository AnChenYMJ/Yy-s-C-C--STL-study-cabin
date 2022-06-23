#include <iostream>
using namespace std;

class CTea
{
public:
	CTea()
	{

	}
	CTea(const CTea& a)
	{

	}
};

void fun(CTea a)
{

}

CTea fun()
{
	CTea a;
	return a;				//此步调用了拷贝构造
}

int main()
{						//调用拷贝构造：现有对象对一个新的对象进行初始化
	CTea su;				//拷贝构造我个人理解就是一种构造函数的重载
	//CTea su0 = su;		//调用了拷贝构造（1）
	//CTea su1(su);			//调用了拷贝构造（2）
	//CTea su2 = CTea(su);	//调用了拷贝构造（3）
	//CTea* su3 = new CTea(su);//调用了拷贝构造(常用形式)（4）

	//CTea su4;				//赋值不会调用构造函数
	//su4 = su;

	//fun(su);				//调用了拷贝构造（5）
			//原理：因为参数是局部对象，所以进行了以su对新的对象初始化，就和（1）（2）一样了

	//fun();					//调用了拷贝构造（6）
			//原理：返回值是一种临时变量或对象，所以进行了对新的对象初始化
	//CTea(su);//临时对象在不同的编译器里有不同的处理方式（过程），有的就直接当作su来看
			//我的就提示重定义
	return 0;
}