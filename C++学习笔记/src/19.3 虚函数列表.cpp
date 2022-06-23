#include <iostream>
using namespace std;

class Coldman
{
public:
	virtual void show()
	{
		cout << "i am so old" << endl;
	}
};

class Cman:public Coldman
{
public:
	void show()
	{
		cout << "i am so strong" << endl;
	}
};

int main()
{
	Coldman* ol = new Cman;
	ol->show();//这就是父类的指针指向函数，会判断是否是虚函数，是的话进入虚表查找函数地址执行


	//虚函数列表在每次父类指针申请不同子类对象空间时产生，每个对象都对应这一个虚函数列表，不会重复
	//虚函数列表的空间内容排序就是每个函数在父类中的顺序，空间内装着每个函数的地址
	//当有子类发现重写时，将子类的对应函数的地址覆盖掉虚表中父类函数的地址
	//当执行父类对象，执行到函数，如果不是虚函数，就执行自己的函数
	//如果发现virtual虚函数，就进入列表找到表中的函数地址去执行，这个地址被子类的函数覆盖掉了
	//所以执行的是子类的函数。
	//函数就是靠地址去找到执行语句执行的，函数名就是函数地址

	delete ol;//注意释放空间
	
	system("pause");
	return 0;
}