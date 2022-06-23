#include <iostream>
using namespace std;

//参数列表类型的默认值和函数参数指定默认值一样，必须从右向左连续赋值
template<typename T, typename Y = char>//会被类外所写的覆盖掉
class Ctea			//指定模板参数列表默认值，只有类模板能做到
{
public:
	T ange;	//可以把成员类型也定义成模板参数列表的类型
	Y high;

	Ctea()
	{
		ange = 88;
		high = 'g';
	}
	Ctea(T t, Y y):ange(t), high(y)
	{}

	void show();
	/*{
		cout << ange << " " << high << endl;
	}*/
};


template<typename T = char>
void fun(T u)	//只可以类模板有默认值
{}

void Ctea<float, double>::show()	//类外实现函数模板的方法一，类名作用域的类名后要加上模板参数列表
{													//类外只要出现类名，就要加上模板参数列表
	cout << ange << " " << high << endl;
}

template<typename T, typename Y>	//类外实现函数模板的方法二
void Ctea<T, Y>::show()				//模板参数列表的参数类型换成 T Y
{													
	cout << ange << " " << high << endl;
}

int main()
{	
	//Ctea su;//error: 使用 类 模板 需要 模板 参数列表
	Ctea<int> su(15, 'Y');//只要在类外，类名后一定要加上模板即<>和里面的类型
	su.show();	//类模板可以给参数指定默认类型，有默认值的话类外就不用写类型了，但<>一定要有
			//如果类内有给变量赋值，我们就可以不传参数
			//参数列表指定默认值如果有写，我们类外再写，就会把默认值覆盖掉

	Ctea<int> ta;//如果成员有初始值，就可以不传递参数，但<>模板参数列表一定要有
	ta.show();

	//Ctea* tsu = new Ctea;
	//Ctea<int, double>* tsu = new Ctea<int>;//前后的参数列表应保持一致，否则报错
	Ctea<int, double>* tsu = new Ctea<int, double>(66, 55.77);//在类名后加上模板参数列表
	tsu->show();		//指针类型，传递参数放在最后面的小括号内

	system("pause");
	return 0;
}