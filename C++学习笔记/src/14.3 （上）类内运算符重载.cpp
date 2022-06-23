#include <iostream>
using namespace std;

class CTea
{
public:
	int ange;
	int bear;
	CTea() :ange(10)
	{
		bear = 20;
	}

	//类内运算符重载因为第一个隐藏的参数已经指向当前对象了，也只能写一个参数，
	//所以不能写成基本数据 + 对象的形式，也不能写成被别的数据或对象减的形式
	int operator+(int a)//理解一：类内运算符重载也是函数，所以第一个参数是隐藏的this指针指向这个对象
	{	//所以只能写第二个数据或对象的参数，外观上就是只写了一个参数，但是第一个是隐藏的this指针参数
		//return (this->ange + a);
		return (ange + a);//两种写法都可以
	}//理解二：这就是固定写法
};

//int operator+(int a , CTea& b)//类外运算符重载就能写多种情况了
//{
//	return (a + b.bear);	//注意：尽量把运算符重载的符号与执行内容相对应，否则就没什么意义了
//}							//比如 + 的符号却执行了减法，就没多大意义了

int main()
{
	CTea su;
	
	cout << su.operator+(2) << endl;//这两种写法都执行了运算符重载
	cout << (su + 5) << endl;	

	//(5 + su);// error:没有找到接受“CTea”类型的全局运算符(或没有可接受的转换)
		//类内运算符重载不可以计算这种基本数据在前面的情况

	system("pause");
	return 0;
}