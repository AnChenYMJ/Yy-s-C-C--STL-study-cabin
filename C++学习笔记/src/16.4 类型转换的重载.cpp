#include <iostream>
using namespace std;

class Cstu		//运算符重载很重要
{
private:
	int ange;
	double high;
	float big;
public:
	Cstu() :ange(28), big(125.43f)
	{
		high = 164.111;
	}

	operator int() const//因为类型转换不应该改变对象内容，所以应该加上const
	{
		return ange;	//类型转换重载有什么用，后面的课会讲到
	}

	//double operator double() const//不要写返回值类型，否则报错
	operator double() const
	{
		return high;				//但是要返回值
	}

	operator float() const		//类型转换的重载必须写在类内，没有参数
	{
		//return big;
		return ange;//如果在float的类型转换重载中返回int类型，会提示内存截断
	}
};

int main()
{							//使用类型转换重载，会自动根据转换类型去不同的重载函数
	Cstu su;					//下断点调试会发现走了不同的重载
	cout << (int)su		<< endl;//C语言中只有一种方式的类型转换就是（int）这种
	cout << double(su)	<< endl;//而C++有两种，另一种是double（su）这种，但不建议使用
	cout << (float)su	<< endl;//因为容易产生歧义，第一种更规范，不容易出错
								//避免过多使用类型转换重载
	cout << su.b << endl;		//这种用法会更直接
	system("pause");
	return 0;
}