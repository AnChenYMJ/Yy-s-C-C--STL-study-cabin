#include <iostream>
using namespace std;


		//C语言中为了避免一段代码重复使用而不断书写，有函数调用这种方式来避免重复书写
		//函数间调用，主函数调用等等
		//C++则是使用了继承来重复书写，派生类继承基类的属性，它就不用再书写一遍属性了（重用性）
		//所以我们把一些都会用到的属性放到一起，装在一个公共类中去继承

class COpportunists		//机会主义者		//基类、父类，
{
public:
	int a;
	COpportunists() :a(12)		//基类能调用子类，但是要到后面的课程才会讲
	{

	}
	void Arrogant()		//傲慢
	{
		cout << "arrogant" << endl;
	}
};


			//这就是继承的形式，冒号public加上父类的名字
class Cteacher : public COpportunists		//老师	//派生类、子类
{
public:
	void Teach()		//子类对基类没有影响，
	{
		cout << "teach child" << endl;
	}
};

class COfficeWorker : public COpportunists	//上班族		//派生类、子类
{
public:
	void lifeless()	//死气沉沉，
	{
		cout << "lifeless every day" << endl;
	}
};

class CPolitician : public COpportunists//政客		//派生类、子类
{
public:
	void Indifferent()	//冷漠
	{
		cout << "Indifferent" << endl;
	}
};
int main()
{
	COfficeWorker su;
	su.Arrogant();
	cout << (su.a = 15) << endl;//如果用的是public的继承修饰符，则相当于父类的成员全部继承过来了
					//变量成员也已经变成自己的了，这不算是改变父类，只是继承了变成自己的
					//父类的属性根本没有任何改变。

	Cteacher ta;
	cout << ta.a << endl;
	ta.Arrogant();


	CPolitician* yu = new Politician;//指针类声明对象

	system("pause");
	return 0;
}