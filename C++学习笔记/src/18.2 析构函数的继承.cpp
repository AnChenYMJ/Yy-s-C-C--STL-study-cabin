#include <iostream>
using namespace std;

class CGrandFather
{
public:
	CGrandFather()
	{
		cout << "CGrandFather 构造函数 \n";
	}
	~CGrandFather()
	{
		cout << "CGrandFather 析构函数 \n";
	}
};

class Cfather:public CGrandFather
{
public:
	Cfather()
	{
		cout << "Cfather 构造函数 \n";
	}
	~Cfather()
	{
		cout << "Cfather 析构函数 \n";
	}
};

class Cson:public Cfather
{
public:
	Cson()
	{
		cout << "Cson 构造函数 \n";
	}
	~Cson()
	{
		cout << "Cson 析构函数 \n";
	}
};

int main()
{
	{				//构造函数：从辈分高到辈分低执行，从最基类到最子类，也是申请空间构建成功的顺序
		Cson xi;	//局部对象，看构造函数与析构函数的执行顺序
	}				//析构函数：从辈分低到辈分高执行，从最子类到最基类，也是空间释放的顺序
		
	system("pause");
	return 0;
}