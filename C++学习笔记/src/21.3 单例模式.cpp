#include <iostream>
using namespace std;

class Cteach	//单例模式即一个类只能创建一个对象，一般来说一个类能实例化许多个对象，但用以下四部来构成一个限制创建次数的类，即单例模式
{				//单例模式的类无法继承

private:
//protected:		//第一步，用private protected来修饰使构造函数私有
	Cteach()
	{
	
	}
public:									//静态的话一开始就存在了，有自己单独的空间，就能将类内申请的对象空间地址返回
	static int tea;				//第三步，创建一个静态常量且初始化用作标记，

	static Cteach* Ctea()		//第二步：构建一个public的静态函数，返回一个new当前类的空间地址，
	{
		if (tea == 1)
		{
			tea = 0;				//创建完一个对象后改变标志，注意：一定要在return之前，否则执行return就直接跳出，不执行这一句了
			return (new Cteach);	//原理是现在是在类内申请空间并调用，所以private无法阻碍		
		}
		else
		{
			return NULL;			//如果标志不等于1，说明已经创建了一次对象了，此时返回NULL，使对象内容为空
		}	
	}
	~Cteach()
	{
		tea = 1;					//第四步，使用析构函数使第一个空间释放后，能重新申请一个
	}
};

class Cstudy:public Cteach
{
public:

};

int Cteach::tea = 1;//静态常量初始化

int main()
{				//构造函数被private 或 protected修饰的话，就无法创建对象，因为构造函数是私有的
	//Cteach ta;// “Cteach::Cteach”: 无法访问 private 成员(在“Cteach”类中声明)

	Cteach* ta = Cteach::Ctea();	//用一个指针装静态函数返回的对象地址
	delete ta;						//释放对象空间，且使用第四步的析构函数来使静态标志回复1，可重新申请空间

	//Cteach* te = Cteach::Ctea();	//没有进行第四步，指针还是内容为空,因为标志还是为0；可以使用析构函数来完成标志回复1，
	Cteach* tc = Cteach::Ctea();	//进行了第四步后，释放第一个对象后，得到了对象地址

	Cstudy su;			//被private修饰的构造函数，子类无法实例化对象
	Cteach* stu = su.Ctea();//但是构造函数被protected修饰的话，就能实例化对象了，且能调用静态函数返回父类对象指针，
							//但还是遵守着单例模式的只能有一个父类对象,即函数返回值为NULL
					

	system("pause");
	return 0;
}