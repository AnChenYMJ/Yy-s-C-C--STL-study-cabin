#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

struct ok
{
	int a;
	double b;
	const char* c;

	ok(int i, double o, const char* l)				//结构体就是类的一种，我们自写构造函数，那结构体就不能用 = 来初始化了
	{												//只能用ok(i, o, l) 这种形式来初始化
		a = i;
		b = o;
		c = l;
	}
};

void show(ok o)
{
	cout << o.a << ' ' << o.b << ' ' << o.c << '\n';
}

void STLcoutadd()
{
//输出（查）
{
	//全部输出
	{
		//循环输出										//使用自写结构体构造函数能省力，就不必每次都定义一个结构体变量了
		//ok ok1 = { 27, 165, "keep going!" };			//当写了结构体的构造函数时，就不能用这种初始化方式了
		list<ok> li1(4, ok(27, 165, "keep going!"));	//只能用ok(27, 165, "keep going!")这种形式初始化
		//list的迭代器只能自加，不能+1 +2 那样偏移
		for (list<ok>::iterator ite = li1.begin(); ite != li1.end(); ite++)	//把迭代器的声明写在循环内，方便控制，因为ite自加变化了
		{
			cout << ite->a << ' ' << ite->b << ' ' << ite->c << '\n';		//迭代器本质是指针，指针调用成员要用->
		}
		cout << endl;

		//for_each输出
		for_each(li1.begin(), li1.end(), show);
		cout << endl;
	}

	//单个输出
	{
		list<ok> li1(1, ok(28, 163, "nothing."));				//使用自写结构体构造函数能省力，就不必每次都定义一个结构体变量了
		li1.push_back(ok(15, 155, "child."));
		//输出尾元素 back()
		cout << li1.back().a << ' ' << li1.back().c << endl;	//因为back返回的是引用，而元素是变量，所以用. 而不是->

		//输出头元素 front（）
		cout << li1.front().a << ' ' << li1.front().c << endl;	//输出头元素的成员
	}
}

//添加
{
	list<ok> li2(2, ok(20, 165, "iedot"));
	for_each(li2.begin(), li2.end(), show);

	//头添加 push_front()			//添加到第一个元素位置	front：正面
	{
		li2.push_front(ok(9, 130, "so small"));
		for_each(li2.begin(), li2.end(), show);
	}

	//尾添加 push_back()				//添加到末尾元素
	{
		li2.push_back(ok(3, 50, "how?"));
		for_each(li2.begin(), li2.end(), show);
	}
	
	//中间添加 insert()				//list不支持下标运算
	{
		list<ok>::iterator ite = li2.begin();
		ite++;											//因为list不能用+1 +2那样的地址偏移，list不支持下标运算
		ite++;											//只能用++来进行位置的确定


		li2.insert(ite, ok(14, 154, "lovely"));			//1.在迭代器指定位置添加一个元素
		for_each(li2.begin(), li2.end(), show);

		li2.insert(ite, 2, ok(30, 161, "have a girl friend."));
		for_each(li2.begin(), li2.end(), show);			//2.在指定位置添加num个值为val的元素

		list<ok> li3(5, ok(40, 160, "along"));		
		li2.insert(--ite, ++li3.begin(), li3.end());	//3.在指定位置添加另一个向量的一段，且list迭代器除了++， 还能--
		for_each(li2.begin(), li2.end(), show);

	}


}

}

int main()
{
	STLcoutadd();


	system("pause");
	return 0;
}