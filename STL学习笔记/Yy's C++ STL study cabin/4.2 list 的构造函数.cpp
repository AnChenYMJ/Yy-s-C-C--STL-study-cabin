#include <iostream>
#include <list>				//容器的头文件就是容器的名字，以后的容器都这样
#include <algorithm>		//一些内建函数不用写头文件，或者如string，不用写头文件
using namespace std;		//因为编译器支持，但是这样的问题就是移植性差，且不利于我们学习，所以还是建议写头文件

typedef struct ko			//头加typedef 尾加* 就是给结构体重命名，但是这样有一个问题
{							//理解不到位，很容易出错。
	int		a;				//就是我们使用重命名时，往往搞不清是几级指针，不知道加多少*的问题，容易出错
	char	c;
}*_ko;						//C++调用结构体也很方便，写结构体名字就好了，所以不建议使用结构体重命名


struct ok					//用结构体作参数，更能体现链表的特性
{
	int		a;
	double	b;
	char	c;
};

void show1(ok o)			//这个函数把第三个char类型的成员强转成了基本数据类型float
{
	cout << o.a << ' ' << o.b << ' ' << (float)o.c << '\n';		// \n 比 endl 效率更高
}

void show2(ok o)
{
	cout << o.a << ' ' << o.b << ' ' << (float)o.c << '\n';	
}

void STlistdefine()	
{
	list<ok> li1;			//无参数，没有元素


	ok ok1 = { 26, 164.11, 'y' };
	list<ok> li2(3);		//用三个结构体初始化链表

	for_each(li2.begin(), li2.end(), show1);			//发现只打印了两个成员，都为0，有一个成员是char类型，
	cout << endl;										//ASC码的0 是一个不可显示字符，所以要打印的话，就强转成基本数据类型

	ok ok2 = { 28, 164.11, 'Y' };						
	list<ok> li3(6, ok2);								//用num个val给链表初始化
	for_each(li3.begin(), li3.end(), show1);
	cout << endl;

	
	list<ok> li4(li3);									//用另一个对象给本对象初始化
	for_each(li4.begin(), li4.end(), show1);
	cout << endl;


	list<ok>::iterator ite = li4.begin();				//利用迭代器，用另一个对象的一段给本对象初始化
	ite++;												//list的迭代器不能如+1 +2 这样的地址偏移，只能++
	ite++;												//想要第2个开始的话，就必须自加2次。
	list<ok> li5(ite, li4.end());						//只能自加，因为链表的元素不是连续空间，地址偏移就会越界操作
	for_each(li5.begin(), li5.end(), show1);

}

int main()
{
	STlistdefine();			//如果报错提示：未声明的标识符，一般是头文件没写



	system("pause");
	return 0;
}