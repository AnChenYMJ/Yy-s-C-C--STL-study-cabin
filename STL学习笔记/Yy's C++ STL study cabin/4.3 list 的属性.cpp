#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

struct ok
{
	int			a;
	double		b;
	const char* c;			//const char* c[40];	之前这么写，提示无法从float转成const char* 
	float		f;			//原因是这样写就成字符指针数组了，有40个字符串元素的数组，所以第四个当成是数组元素了
};							//char* 才是接收字符串地址的指针

void show(ok o)
{
	cout << o.a << ' ' << o.b << ' ' << o.c << ' ' << o.f << '\n';
}

void STLlistdefine()
{
	ok ok1 = { 27, 164.03, "Yy, keep going , Don't stop!!", 60.14f };
	list<ok> li1(8, ok1);

	cout << size(li1)  << endl;						//size()  返回元素个数
	cout << empty(li1) << endl;						//empty() 查看对象是否有元素，有则返回0，无则返回1
	//cout << li1.capacity() << endl;				//list没有容量这一概念了，需要新节点，就在尾部添加新空间
													//所以没有返回容量大小的函数了
	for_each(li1.begin(), li1.end(), show);


	li1.resize(2);									//重新设置元素个数

	cout << li1.size()  << endl;						//2		//与size(li1)的写法不一样，但都是一个效果和意思
	cout << li1.empty() << endl;						//0
	for_each(li1.begin(), li1.end(), show);


	li1.resize(0);									//设置成0个元素

	cout << size(li1) << endl;						//0
	cout << empty(li1) << endl;						//1
	for_each(li1.begin(), li1.end(), show);			//没有元素了，所以不打印
}

int main()
{
	STLlistdefine();

	system("pause");
	return 0;
}