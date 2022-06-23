#include <iostream>
using namespace std;

class Ctea
{
public:
	int ange;
	int bear;
	Ctea() :ange(15)
	{
		bear = 13;
	}
};

//运算符重载的返回值的意义：为了进行连续计算，用返回值将计算后的值与别的数据进行运算
int operator+(Ctea& a, int b)
{
	return (a.ange + b);
}

int operator+(int b, Ctea& a)//参数使用引用避免拷贝构造，提升效率
{
	return (a.ange + b);
}

Ctea& operator+(Ctea& a, Ctea& b)//对象相加
{
	a.ange += b.ange;
	return a;    //通过加等于来直接返回对象a，不过这样对象a内的值就被修改了
}

int operator*(Ctea& b, int a)
{
	return (b.ange * a);
}

int operator/(Ctea& b, int a)
{
	return (b.ange / a);
}

// warning C4552: ”-“: 未使用表达式结果
void operator-(Ctea& a, int b)//没有返回值就无法将计算后的值与其它数据再计算
{
	a.ange - b;
}

int main()
{
	Ctea su1,
		su2;

	//su1 + 12 的结果为一个int整型数据27，再与13计算：27+15，//得到的整型数据40再与su2计算：40+su2
	cout << (su1 + 12 + 13 + su2) << endl;//所以用到了两个运算符重载

	//cout << (su1 - 5 - 3) << endl;// warning C4552: ”-“: 未使用表达式结果//必须用返回值进行连续运算操作

	cout << (su2 + 11 + (su1 + su2)) << endl;//利用小括号改变运算顺序，这样就需要对象加对象的运算符重载了

	//因为上面(su1 + su2)修改了su1内的值，此时su1.ange变成了30。
	cout << (su2 * 1 + su1 / 2) << endl;//用到三种运算符重载，对象加对象，对象乘整型，对象除整型

	return 0;
}