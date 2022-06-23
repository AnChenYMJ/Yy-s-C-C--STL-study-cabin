#include <iostream>
#include <list>
#include <algorithm>
#include <forward_list>					//单向链表
using namespace std;

struct okea								//因为许多函数需要用到运算符重载，所以用结构体当元素，更有学习性
{
	int a;
	const char* c;

	okea(int i, const char* cc)
	{
		a = i;
		c = cc;
	}

	bool operator< (const okea& p) const		//用于3.排序 与 4.合并
	{
		if (this->a < p.a)
			return true;
		else
			return false;
	}

	bool operator== (const okea& p) const		//用于7.算法 的查找函数 find
	{
		if (this->a == p.a && this->c == p.c)
			return true;
		else
			return false;
	}
};

void show(okea o)
{
	cout << o.a << ' ' << o.c << '\n';
}

void STLother()
{	
	list<okea> li1;							
	li1.push_front(okea(5, "blurry"));		//blurry : 模糊
	li1.push_front(okea(6, "crying"));		//cry	 : 哭泣
	li1.push_front(okea(7, "guilt"));		//guilt	 : 有罪
	li1.push_front(okea(8, "earnest"));		//earnest: 认真，热切
	li1.push_front(okea(9, "consern"));		//consern: 担心，忧虑
	li1.push_front(okea(10, "dirverse"));	//dirverse:多种，各种各样的
	li1.push_front(okea(11, "desire"));		//desire : 渴求，愿望
	li1.push_front(okea(12, "dream and humiliation"));	//humiliation : 屈辱， 羞辱， 耻辱

	list<okea> li2;
	li2.push_back(okea(27, "hope is on the way."));
	li2.push_back(okea(26, "Try to save"));
	li2.push_back(okea(25, "vague"));		//vague : 模糊，迷漫
	li2.push_back(okea(24, "lost"));		//lost  : 迷失

//1.交换	swap（）
{
		list<okea> li3(li1);
		list<okea> li4(li2);

		for_each(li3.begin(), li3.end(), show);
		cout << '\n';
		for_each(li4.begin(), li4.end(), show);
		cout << '\n';

		li3.swap(li4);							//交换两对象内容

		for_each(li3.begin(), li3.end(), show);
		cout << '\n';
		for_each(li4.begin(), li4.end(), show);
		cout << '\n';
}

//2.元素倒换	reverse() 
{
	list<okea> li5(li1);

	for_each(li5.begin(), li5.end(), show);
	cout << '\n';
											//reverse 不是 reserve list没有reserve（修改容量大小）
	li5.reverse();							//作用是翻转，不是排序，即当前的头尾顺序颠倒过来

	for_each(li5.begin(), li5.end(), show);
	cout << '\n';


}

//3.排序		sort（）
{
	//定义对象
	list<okea> li6;
	li6.push_front(okea(12, "dream and humiliation"));	
	li6.push_front(okea(8, "earnest"));	
	li6.push_front(okea(11, "desire"));
	li6.push_front(okea(7, "guilt"));		
	li6.push_front(okea(6, "crying"));
	li6.push_front(okea(10, "dirverse"));	
	li6.push_front(okea(5, "blurry"));	
	li6.push_front(okea(9, "consern"));

	for_each(li6.begin(), li6.end(), show);
	cout << '\n';

	li6.sort();								//因为排序需要进行比较，所以需要重载 < 运算符(这里只有重载<运算符才行，函数定义规定的吧)
											//怎么排序，就看自己怎么自定义了，我这里写的是只比较第一个元素，从小到大排序
	for_each(li6.begin(), li6.end(), show);
	cout << '\n';

	//想要把当前的顺序反过来
	//1.在上面的运算符重载函数内，切换< > 符号即可，但注意，重载的符号只能是 < 只是内部的执行比较可切换
	//2.利用reverse进行元素倒换，如下
	li6.reverse();

	for_each(li6.begin(), li6.end(), show);
	cout << '\n';
}

//4.合并		merge
{
	//注意：1.自动排序 2.重载小于号 3.两个链表必须有序
	list<okea> li8(li2);
	list<okea> li7;
	li7.push_front(okea(12, "dream and humiliation"));
	li7.push_front(okea(8, "earnest"));
	li7.push_front(okea(11, "desire"));
	li7.push_front(okea(7, "guilt"));
	li7.push_front(okea(6, "crying"));
	li7.push_front(okea(10, "dirverse"));
	li7.push_front(okea(5, "blurry"));
	li7.push_front(okea(9, "consern"));

	for_each(li7.begin(), li7.end(), show);
	cout << '\n';

	//li7.merge(li2);							//此处li7是无序排列，所以合并就崩溃了

	/*li7.sort();
	li7.merge(li2);*/							//此处因为排序是从小到大，而li2是从大到小，所以又崩溃了

	li7.sort();									//使li7从小到大排序
	//li7.reverse();								//使li7从大到小排序，但还是崩溃了，不清楚原因
	li8.reverse();								//使li8也从小到大排序，这下没有崩溃
	li7.merge(li8);								//合并后，不论是li8合并li7，整体排序是从小到大
	
	for_each(li7.begin(), li7.end(), show);		//C3说，除非写代码很久有经验，不然难理解崩溃原因，我们知道怎么用就好了
	cout << '\n';
}

//5.拼接		splice
{
//1.在迭代器指定位置插入另一对象
	list<okea> li9(li1);
	list<okea> li10(li2);
	list<okea>::iterator ite = li9.begin();
	ite++; ite++; ite++;

	for_each(li9.begin(), li9.end(), show);
	cout << '\n';

	li9.splice(ite, li10);					//1.在迭代器指定位置插入另一对象

	/*for_each(li9.begin(), li9.end(), show);
	cout << '\n';*/


//2.在迭代器指定位置插入另一对象的某一个节点
	list<okea> li11(li2);

	li9.splice(++ite, li11, li11.begin());	//2.在迭代器指定位置插入另一对象的某一个节点

	for_each(li10.begin(), li10.end(), show);	//此处li10的内容已经在上面拼接到li9了，所以li10已经空了没有元素
	cout << '\n';								//所以不能再用10来拼接，会崩溃，除非给10再添加元素

	for_each(li9.begin(), li9.end(), show);	//会发现迭代器指向的位置越过了之前拼接的li10，到了9，即拼接前li9的第四个元素位置
	cout << '\n';

	for_each(li11.begin(), li11.end(), show);	//拼接后，li11的第一个元素被拿走拼接到li9了，所以此时li11只剩3个元素
	cout << '\n';


//3.在迭代器指定位置拼接另一对象的一段
	++ite; ++ite;
	list<okea>::iterator ite1 = li11.begin();
	//li9.splice(ite, li11, ++ite1, ++ite);		//崩溃了，遵循自加自减不能在一个语句里重复出现
	li9.splice(ite, li11, ++ite1, li11.end());	//3.在迭代器指定位置拼接另一对象的一段

	for_each(li9.begin(), li9.end(), show);	
	cout << '\n';

	for_each(li11.begin(), li11.end(), show);	
	cout << '\n';

}

//6.运算符重载
{
	//1. == != <= >= < >	之前课程有讲过

	//2. = 赋值运算符重载		之前也讲过
}

//7.算法
{
	//1.排序		sort	(注意：list的sort是成员函数)

	//2.遍历		for_each

	//查找函数	find	(头， 尾， 值)在范围内查找到对应的值，则会返回这个值的迭代器		//需要==运算符重载
	list<okea>::iterator ite2 = find(li1.begin(), li1.end(), okea(8, "earnest"));	//因为要进行 == 比较，所以需要运算符重载
	//返回范围内找到的值的迭代器，所以用ite2接住

	cout << ite2->a << ' ' << ite2->c << endl;		//我傻了，一直用ite2.来试，试不出来，指针调用成员要用->，迭代器本质是指针


	//list<okea>::iterator ite3 = find(li1.begin(), li1.end(), okea(99, "bone"));		//bone: 骨头

	//cout << ite3->a << ' ' << ite3->c << endl;		//因为li1里没有我们要找的值，没有返回迭代器，我们再打印就崩溃了
}

//单向链表		forward_list
{
	forward_list<okea> fo1;
					//除了list还有forward_list（向前链表（单向链表））
					//但VS2005不支持，只有VS2012以上支持
}
}

int main()
{
	STLother();		


	system("pause");
	return 0;
}