#include <iostream>
using namespace std;

class CTea
{
public:
	int anger;
	int bear;
	double d;
	CTea() : anger(12), bear(15),d(12.35)
	{

	}
};

//运算符重载	//用函数重载的方式来理解	//重载就和函数重载一样，一样的名字 比如+，但执行的内容却有所区别
void operator+(CTea& e, int c)//参数尽量用引用，避免拷贝构造的问题（构建临时对象或局部对象），还提高了运行效率，
{
	cout << (e.anger + c) << endl;
}

void operator+(CTea& e, CTea& g)//传递的参数也由我们来决定，
{
	cout << (e.anger + g.d) << endl;//执行内容由我们来指定成员与运算规则
}

void operator-(CTea& e, CTea& g)
{
	cout << (e.anger - g.d) << endl;
}

void operator-(int e, CTea& g)
{
	cout << (e - g.d) << endl;
}

//void operator-(int e, int g)//error C2803: “operator -”必须至少有一个类类型的形参
//{
//	cout << (e - g) << endl;//系统制定好的运算规则我们是无法修改的
//}

int main()
{		//类也是一种数据类型 
	int a = 13;
	//a + 15;	//这种算法 + 加法之类的是我们系统自动帮我们算的

	CTea te,//连续多次声明对象时，这样可以帮助我们注释标注是干嘛的。
		 ta,//测试用
		 su;//测试用

	te + ta;//error C2676: 二进制“+”:“CTea”不定义该运算符或到预定义运算符可接收的类型的转换
			//系统会不知道这两个类当中的哪个成员 + 哪个成员，怎么 + 是自己全部加再加另一个，还是成员分别与对面成员相加
	su + 13;//这种就会匹配到我们自己写的运算符重载函数

	//13 + su;//运算符两侧数据类型顺序要与我们的参数顺序一致，否则会报错。

	15 + 16;//这是由系统默认的函数规则来执行的，所以会匹配到系统的运算函数

	return 0;
}