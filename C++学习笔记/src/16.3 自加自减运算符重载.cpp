#include <iostream>
using namespace std;

class Ctea
{
private:
public:
	int ange;
	int high;
public:
	Ctea():ange(15)
	{
		high = 164.55;
	}

	int operator--()		//类内的前置--
	{
		this->ange -= 1;
		return ange;
	}

	int operator--(int n)		//类内的后置置--，先取值
	{		//n是一个标志，与前置区分开，可以完全不用它
		int a = ange;
		this->ange -= 1;
		return a;
	}

	friend int operator++(Ctea& a);
};

int operator++(Ctea& a)//前置++，直接自加
{
	a.ange += 1;
	return a.ange;
}
					//n是标志与前置的区分来，没什么实际作用，但也可以为了避免浪费，用来装自加前的值
int operator++(Ctea& a, int n)//后置++，先取值后自加
{
	n = a.ange;		//用一个变量装自加前的值
	a.ange += 1;	//自加
	return n;		//将自加前的值返回
}					//这也是实际变量的后置自加过程，用一个空间装自加前的值并返回，而原空间则自加

int main()
{
	int a = 11;
	a++;//先取值后自加
	++a;//先自加后取值

	Ctea su;
	cout << su.ange << endl;		//15
	cout << ++su << endl;//前置++	//16
	cout << su++ << endl;			//16
	cout << su++ << endl;			//17
	cout << su.ange << endl;		//18

	return 0;
}