#include <iostream>
using namespace std;

class Ctea
{
private:
	int a;
	int b;
	int c;
	double d;
	float e;

	int Nerror;
public:
	Ctea():a(18),b(22)
	{
		c = 27;
		d = 165.335;
		e = 156.445f;
		Nerror = -1;//不加= 就是一个运算式，不会error
	}

	//因为[]下标运算符能对空间进行读和写操作，用引用就能实现写的操作了
	int& operator[]( int n)//[]运算符只能写在类内
	{					//n作为下标运算的标志
		switch(n)
		{
		case 0:
			return a;//因为一执行return就跳出函数，下面的都不执行了，所以不需要加break了。
		case 1:
			return b;
		case 2:
			return c;
		//case 3:
			//return d;//“return”: 无法从“double”转换为“int &”,返回值用引用就会有这样的局限性
		}			//无法返回其它类型的成员，下节课用指针能打破局限性
		return Nerror;//这个返回值作为超限的标志
	}
};

//int& operator[](Ctea& a, int h)//error C2801: “operator []”必须是非静态成员(必须是类内成员)
//{
//
//}

int main()
{
	//[]的三种作用，一：表示数组元素个数。 二：在参数中[]表示指针。三：下标运算符。
	int u[5] = { 6, 4, 3, 7, 8 };	//u就是数组的首地址
	u[1] = 6;//下标运算的本质是指针偏移，u[1] 即是 *（u+1），即首地址+1，且对其操作


	Ctea su;
	cout << su[0] << endl;
	cout << su[2] << endl;//自定义的下标运算符
	su[2] = 30;
	cout << su[2] << endl;


	system("pause");
	return 0;
}