#include <iostream>
using namespace std;

class CSTu
{
public:
	int a;
	float f;
	double d;
	int y;
	//CSTu() : a(13), f(56.54f), d(987.456)//初始化列表的形式
	//{
	//	cout << a << " " << f << " " << d << endl;//构造函数也可以用来装其他语句
	//}				//在构建对象时自动执行构造函数，但一般构造函数是用来初始化变量成员的

	/*CSTu(int q, float w, double e = 123.654) : a(13), f(56.54f), d(987.456)
	{
		a = q;
		f = w;
		d = e;
	}*/	

	/*CSTu(int q) : a(13), f(56.54f), d(987.456)
	{
		a = q;
	}*/

	//CSTu() : y(88),d(987.456),f(56.54f),a(y)
	//{	//这里用最后声明的y给a赋值，赋值失败了
	//}

	CSTu() : y(a), d(987.456), f(56.54f), a(88)
	{	//这里用最先声明的a给y赋值，赋值成功
	}

	void show()
	{
		cout << a << " " << f << " " << d << " " << y <<endl;
	}
};

int main()
{
	//CSTu stu(65, 78.58f);//13 56.54 123.654  //可见参数优先级比初始化列表高 
	//stu.show();

	//CSTu stu(99);//99 56.54 987.456  //可以只传递一个参数
	//stu.show();

	//CSTu stu;//-858993460 56.54 987.456 88//类成员初始化的执行顺序只与变量声明顺序有关
	//stu.show();//这里用最后声明的y给a赋值，赋值失败了

	CSTu stu;//88 56.54 987.456 88//最先声明的a给最后声明的y赋值，成功了
	stu.show();//证明了类成员初始化的执行顺序只与变量声明顺序有关

	return 0;
}