#include <iostream>
using namespace std;

class Cstu
{
private:
	int ange;
	double high;
public:
	Cstu() :ange(27)
	{
		high = 165.897;
	}

	int operator = ( int b)//“operator =”必须是非静态成员（即类内成员）
	{
		ange = b;
		return ange;
	}

	void show()
	{
		cout << ange << endl;
	}

	friend int operator += (Cstu& a, int b);

	friend int operator += (Cstu& a, Cstu& b);
};

//void operator = (Cstu& a, int b)//error C2801: “operator =”必须是非静态成员（即类内成员）
//{
//	a.ange = b;					//operator = 必须是类内成员
//}
	//这里返回引用的话，那参数也要改成引用
int operator += (Cstu& a, int b)	//多重赋值运算符重载
{									//书上建议写在类内，但是能写在类外
	a.ange += b;
	return a.ange;
}

//int operator += (Cstu& a, Cstu& b)	//当连续运算的最后一个类型是对象的话，就必须写这个重载了
//{										//但如果连续运算最后一个类型是常量的话，就写上面那一个就行了
//	a.ange += b.ange;
//	return a.ange;
//}

int main()
{
	Cstu te;
	cout << (te = 56) << endl;

	//cout << (te = 56 = 89) << endl;//不可以连续赋值，因为=结合性从右向左，而左操作数必须为左值

	Cstu su;
	Cstu ta;
	su.show();
	cout << (te += su += ta += 15) << endl;//利用返回值来实现连续运算
	su.show();		//+= 的结合性从右向左，就是最后两个数即第一个参与运算的数值
	//cout << (te += su += ta) << endl;//这种需要对象+=对象的重载

	system("pause");
	return 0;
}