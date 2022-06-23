#include <iostream>
#include <vector>
using namespace std;

//普通类
class Ctre
{
public:
	int i;
	float g;
};

void DeFine()
{

	struct str
	{
		int a = 56;
		double b;
		char c;
		float f;
	};

//定义vector
{
	//vector是向量操作（动态数组）的容器
	//与string的内存分配是一样的，重新申请空间时，迭代器失效。(初始空间与溢出增加容量的大小都一样)
	//vector要在<>中加参数，参数是要操作的容器数据类型。
	//string因为是专用针对字符串和字符的，所以不必加参数。
	
	//vector容器数据的类型有四类：基本数据类型，结构体类型，指针类型，对象类型。
	//基本数据类型：
	vector<int>		vec;		//基本数据类型int

	vector<float>	vecf;		//基本数据类型float

	//结构体类型：
	vector<str>		vecs;		//结构体类型

	//指针类型：
	vector<double*> vecb;		//指针类型

	//对象类型：
	vector<Ctre>	vecc;		//普通类对象类型

	vector<string>	veci;		//其它容器对象类型
								//vector<string> 的作用就与string容器的作用是一样的了，都是对字符串进行操作。
								//但是string容器对字符操作的功能要更多，更好用。
}
	
//补充点：s
{
	//除vector外，数组的容器还有：
	//array（固定数组）：某些版本不支持array，VS2013以后好像都支持。
	//valarray：属于数学计算的容器，是<cmath.h>的函数封装的。比如开方，次幂，log等。

	//vector是最常用的，所以一般来说，能用vector就用。
}



}


int main()
{
	DeFine();



	system("pause");
	return 0;
}