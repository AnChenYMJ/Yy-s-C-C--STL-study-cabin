#include <iostream>
using namespace std;


template <typename T, typename Y>
class Cfather
{
public:
	T age;
	Y tired;

	Cfather()
	{}

	Cfather(T t, Y y):age(t), tired(y)
	{}

	void show()
	{
		cout << age << " " << tired << endl;
	}
};

class Cson : public Cfather<int, double>	//固定形式的继承模板
{					//缺点是，通过子类传递的参数就只能是子类写好的类型，不能变化
public:
	Cson(int a, double b):Cfather<int, double>(a, b)//如果父类的构造函数没有参数，就可以不写传递参数
	{

	}
};


template <typename X, typename Z>	//加上模板
class Cdaughter : public Cfather<X, Z>	//灵活形式的继承模板
{					//这样就能实现子类智能的传递数据类型了
public:
	Cdaughter(X a, Z b) :Cfather<X, Z>(a, b)//如果父类没有参数，那就不用写传递参数了
	{

	}
};


int main()
{
	Cson so(156, 'y');//可以发现，没有打印字符，而打印了对应的ASC码
	so.show();		//因为子类中传递的参数类型固定了是int，double

				//字符串类型是const char*//因为字符串是常量
	Cdaughter<char, const char*> du('o', "Keep going Yy~ if tired ,Just take a rest");
	du.show();		

	system("pause");
	return 0;
}