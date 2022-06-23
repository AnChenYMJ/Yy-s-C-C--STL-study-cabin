#include <iostream>
using namespace std;

class Cstu		//ostream是一个对象（输出）
{
private:		//实际情况中，绝大部分的数据成员是私有的，防止被修改,所以友元的作用就体现出来了
	int ange;
public:
	Cstu(int ang)
	{
		ange = ang;
	}
//因为有两个参数，且第一个参数是ostream的引用，所以不能类内定义，
	friend ostream& operator<<(ostream& a, Cstu& b);//因为类内函数第一个参数默认为this指针
};

		
//void operator<<(ostream& a, Cstu& b)//不带返回值的，就只能输出一个
//{
//	a << b.ange;
//}
			//参数一：ostream的引用。参数二：对象的引用
ostream& operator << (ostream& a, Cstu& b)//实际情况数据类型基本都是保护的，所以需要友元来修饰
{
	a << b.ange;
	return a;
}

int main()
{
	Cstu te(18);
	cout << te ;	//<<是一个输出运算符，所以也有重载
	//cout << te << endl;//不带返回值的自定义重载只能输出一个

	cout << " " << te << " " << te << endl;//当输出字符串或者空格变量常量时，调用的是系统

	system("pause");
	return 0;
}