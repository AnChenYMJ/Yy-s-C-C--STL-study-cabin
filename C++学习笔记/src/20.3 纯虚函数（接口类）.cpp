#include <iostream>
using namespace std;

class Coldman
{					//当一个函数中，除构造函数外所有函数都是纯虚函数，就叫接口类（接口类有重大意义）
public:				//在一个游戏中接口类能方便很多事（可自行搜一下）
	Coldman(){}		//这样也是接口类，构造函数无法更改为其他类，就忽略
	virtual void fun() = 0;//这样就是一个纯虚函数，没有实体，没有函数主体，只是个声明
	virtual ~Coldman() = 0;//析构函数能改成纯虚函数
};

class Cman:public Coldman//子类，重写了纯虚函数
{
public:
	void fun()
	{

	}
};

class Cwoman :public Coldman//子类，没有重写纯虚函数
{
public:
	void fun1()
	{

	}
};

class Cchild :public Cwoman//孙子类，重写了纯虚函数
{
public:
	void fun()
	{

	}
};

int main()
{
	//Coldman ol;//“Coldman”: 无法实例化抽象类//只要有纯虚函数就无法构建对象

	Cman ma;//子类中除非子类有重写把纯虚函数覆盖掉，否则也无法创建子类，因为子类也把纯虚函数继承了
	//Cwoman wo;//这个子类没有重写覆盖，也无法创建
	Cchild ch;//这个孙子辈的子类因为重写覆盖，也能创建


	system("pause");
	return 0;
}