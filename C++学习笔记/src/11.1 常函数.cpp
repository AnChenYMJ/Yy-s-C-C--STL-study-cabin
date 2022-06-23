#include <iostream>
using namespace std;

class CTea
{
public:
	CTea()
	{
		a = 15;
	}
	/*~CTea() const //析构函数和构造函数不能用const修饰
	{

	}*/
	int a;

	//常函数能对函数功能进行更明确的分类，比如打印的函数就能加上const，它不需要也不能修改数据成员
	void show(int b) const//常函数的指针是 const CTea*
	{		//可以拥有参数
		//a = 48;//error：由于正在通过常量对象访问“a”，因此无法对其进行修改
		//int c = 66;//函数内声明的变量是能修改的。
		b = a + b;//const修饰的函数不可以修改对象的数据成员，但函数内声明的变量是能修改的。
		cout << a << " " << b <<  " " << "keep going Yy!" << endl;
	}

	void fun()//const修饰的常对象不能调用普通函数
	{
		cout << "keep going! Yy ~ Don't stop!" << endl;
	}
};

int main()
{
	CTea su;
	su.show(15);
	
	const CTea te;//常对象只能调用 常函数，不能调用普通函数
	te.show(11);
	//te.fun();//不能将“this”指针从“const CTea”转换为“CTea &”


	system("pause");
	return 0;
}