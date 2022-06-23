#include <iostream>
using namespace std;


template <typename T, typename Y>
class Ctea
{
public:
	int age;
	Ctea()
	{}

	virtual void show()
	{
		cout << "teacher" << endl;
	}
};

//子类可以有许多模板参数类型，但传递给父类的只有两个，多余的类型可以自己用
template <typename X, typename Z, typename U, typename I>
class Cstud : public Ctea<Z,I>//传递给父类哪些，下面申请对象时，给父类的顺序要对应上
{
public:
	void show()		
	{
		cout << "student1" << endl;
	}
};


class Cstudn : public Ctea<int, const char*>//固定形式的写法
{
public:
	void show()
	{
		cout << "student2" << endl;
	}
};

int main()
{	//上面的模板参数传递给父类的是第2、4个，所以这里父类的模板参数列表要对应上
	Ctea<const char*, float>* te = new Cstud<char, const char*, int, float>;
										//上面模板有多少个参数，这里就要写多少个
	te->show();//成功打印

	//类型要与传递给父类的类型一致，否则报错
	Ctea<int, const char*>* su = new Cstudn;//固定形式的指针构建对象
	su->show();			//后面就不用加模板参数列表了，因为子类没有模板，父类有


	system("pause");
	return 0;
}