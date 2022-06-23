#include <iostream>
using namespace std;

class Cte
{
public:
	int ange;
	Cte(int age)
	{
		ange = age;
	}

	int operator~()//因为隐藏参数this已经指向当前对象，所以不用再写了	//类内一元运算符（取反吧）
	{
		//return (~ange);		//两种写法都可以
		return (~this->ange);
	}
};

int operator-(Cte& a)//类外一元运算符
{
	return (-a.ange);
}

int main()
{
	Cte su(56);

	cout << -su << endl;	//-56

	cout << ~su << endl;	//-57

	system("pause");
	return 0;
}