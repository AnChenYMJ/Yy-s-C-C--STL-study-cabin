#include <iostream>
#include <map>
#include <algorithm>
#include <functional>	//仿函数greater的头文件 

using namespace std;

//属性
void STLmap1()
{
	
	//1.容量
	//与list一样，map是没有容量的概念的，不会提前申请空间，添加一个元素就添加一个空间

	typedef pair<int, char> in_pair;	//重命名，使‘pair<int, char>’简化成 ‘in_pair’来使用
	map<int, char> mp;					//定义一个map

	mp.insert(in_pair(5, 'o'));			//给map赋值：插入元素的方式
	mp.insert(in_pair(1, 'g'));			
	mp.insert(in_pair(3, 'k'));
	mp.insert(in_pair(9, 't'));
	mp.insert(in_pair(7, 'u'));

	//2.得到元素个数	size()
	cout << mp.size() << endl;			//打印mp的元素个数
	cout << "以上是得到元素个数" << endl << endl;

	//3.查找某一个键值是否存在	count（）
	cout << mp.count(3) << endl;		//查找键值为3的元素是否存在，返回1 或 0
	cout << mp.count(7) << endl;		//MultiMap中是返回这个键值出现的次数，因为MultiMap键值能重复，map键值不能重复
	cout << mp.count(11) << endl;
	cout << "以上是查找指定键值是否存在，返回1或0" << endl << endl;
		
	//4.判断map是否为空
	map<int, char> mp1;					//创建空map来对照
	cout << mp.empty() << endl;
	cout << mp1.empty() << endl;
	cout << "以上是判断map是否为空，返回1或0" << endl << endl;

	//5.头尾迭代器 iterator
	map<int, char>::iterator ite = mp.begin();				//创建一个迭代器并赋值为mp的尾部

	for (ite; ite != mp.end(); ite++)
	{														//迭代器就相当于指针，指针调用成员要用->
		cout << ite->first << ' ' << ite->second << endl;	//遍历打印mp的元素，map分为键值与实值，所以要分别打印，first为键值，second为实值
	}
	cout << "以上是迭代器遍历打印元素" << endl << endl;		//似乎不能倒着打印，崩溃了

	

}

//操作
void STLmap2()
{
	//增		三种方式
	{
	typedef pair<int, char> in_pair;	//给‘pair<int, char>’重命名，方便使用
	map<int, char> mp;					//定义一个map对象


	//1.增加单个元素
	mp.insert(in_pair(3, 'f'));			//增加单个元素
	mp.insert(in_pair(7, 'r'));
	mp.insert(in_pair(1, 'y'));
	mp.insert(in_pair(5, 'o'));
	mp.insert(in_pair(9, 'i'));

	map<int, char>::iterator ite = mp.begin();				//声明一个迭代器，赋值为mp的起始位
	for (ite; ite != mp.end(); ite++)
	{														
		cout << ite->first << ' ' << ite->second << endl;	//利用迭代器遍历打印
	}
	cout << "以上是直接插入一个元素" << endl << endl;


	//2.指定位置插入一个元素（pair）	有返回值
	map<int, char> mp1;
	mp1.insert(in_pair(6, 'j'));

	map<int, char>::iterator ite1 = mp1.begin();			//声明一个迭代器，赋值为mp1的起始位
	ite1++;													//迭代器偏移，实现指定位置

	mp1.insert(in_pair(2, 'r'));							//指定位置添加元素
	mp1.insert(in_pair(4, 'p'));
				
	map<int, char>::iterator ite2 = mp1.begin();
	for (ite2; ite2 != mp1.end(); ite2++)
	{
		cout << ite2->first << ' ' << ite2->second << endl;	//利用迭代器遍历打印
	}
	cout << "以上是指定位置插入一个元素" << endl << endl;


	//3.插入另一对象的一段
	map<int, char> mp3;

	mp3.insert(++mp.begin(), --mp.end());					//利用迭代器偏移实现插入另一对象的一段

	map<int, char>::iterator ite3 = mp3.begin();
	for (ite3; ite3 != mp3.end(); ite3++)
	{
		cout << ite3->first << ' ' << ite3->second << endl;	//利用迭代器遍历打印
	}
	cout << "以上是插入另一对象的一段" << endl << endl;

	}

	//改
	{
	//注意：改--只能改实值，不能改键值，因为键值关乎到这个容器的结构，因为是红黑树啥的，节点不能随意变动
	//这是数据结构中的知识，记住键值改了就会破坏结构，所以只能改实值


		typedef pair<int, char> in_pair;	//重命名，使‘pair<int, char>’简化成 ‘in_pair’来使用
		map<int, char> mo;					//定义一个map

		mo.insert(in_pair(5, 'o'));			//给map赋值：插入元素的方式
		mo.insert(in_pair(1, 'g'));
		mo.insert(in_pair(3, 'k'));
		mo.insert(in_pair(9, 't'));
		mo.insert(in_pair(7, 'u'));

map<int, char>::iterator ito = mo.begin();				//声明一个迭代器，赋值为mp的起始位
for (ito; ito != mo.end(); ito++)
{
	cout << ito->first << ' ' << ito->second << endl;	//利用迭代器遍历打印
}
cout << "修改后" << endl;

mo.begin()->second = 'f';								//修改实值
//mo.end()->second	= 'f';								//这个语句运行崩溃了，不清楚原因
//++mo.begin()->second = 'f';							//这个语句没有修改成功，似乎需要声明迭代器然后偏移
ito = mo.begin();
ito++; ito++;											//迭代器偏移
ito->second = 'f';

map<int, char>::iterator it = mo.begin();
for (it; it != mo.end(); it++)
{
	cout << it->first << ' ' << it->second << endl;	//利用迭代器遍历打印
}
cout << "以上是修改实值" << endl << endl;
	}

	//查		即输出，可用循环，或者for_each来输出，或者用find（）函数来查找
	{
	typedef pair<int, char> in_pair;	//重命名，使‘pair<int, char>’简化成 ‘in_pair’来使用
	map<int, char> mo;					//定义一个map

	mo.insert(in_pair(5, 'o'));			//给map赋值：插入元素的方式
	mo.insert(in_pair(1, 'g'));
	mo.insert(in_pair(3, 'k'));
	mo.insert(in_pair(9, 't'));
	mo.insert(in_pair(7, 'u'));

	map<int, char>::iterator ui = mo.find(9);		//使用find（）查找键值，没有其它重载函数，只有这种使用键值查找的方式
	cout << ui->first << ' ' << ui->second << endl;	//利用迭代器遍历打印
	cout << "以上为：使用find（）查找输出" << endl << endl;
	}

	//删		两种方式
	{
		typedef pair<int, char> in_pair;	//重命名，使‘pair<int, char>’简化成 ‘in_pair’来使用
		map<int, char> my;					//定义一个map

		my.insert(in_pair(5, 'o'));			//给map赋值：插入元素的方式
		my.insert(in_pair(1, 'g'));
		my.insert(in_pair(3, 'k'));
		my.insert(in_pair(9, 't'));
		my.insert(in_pair(7, 'u'));

		map<int, char>::iterator ite1 = my.begin();				//声明一个迭代器，赋值为mp的起始位
		for (ite1; ite1 != my.end(); ite1++)
		{
			cout << ite1->first << ' ' << ite1->second << endl;	//利用迭代器遍历打印
		}
		cout << "以上为删除前" << endl;

		//erase	有三种情况
			//1.迭代器删除指定元素
		my.erase(my.begin());

		ite1 = my.begin();										//迭代器指向起点	
		for (ite1; ite1 != my.end(); ite1++)
		{
			cout << ite1->first << ' ' << ite1->second << endl;	//利用迭代器遍历打印
		}
		cout << "以上为：迭代器删除指定元素" << endl;

		//2.迭代器删除指定一段
		ite1 = my.begin();
		ite1++;
		my.erase(ite1, my.end());								//指定删除迭代器ite1到my.end()的部分

		ite1 = my.begin();
		for (ite1; ite1 != my.end(); ite1++)
		{
			cout << ite1->first << ' ' << ite1->second << endl;	//利用迭代器遍历打印
		}
		cout << "以上为：迭代器删除指定一段" << endl;


		//3.根据键值来删除这个元素
		my.insert(in_pair(2, 'p'));
		my.insert(in_pair(8, 'b'));

		my.erase(3);											//删除键值为3的元素

		ite1 = my.begin();
		for (ite1; ite1 != my.end(); ite1++)
		{
			cout << ite1->first << ' ' << ite1->second << endl;	//利用迭代器遍历打印
		}
		cout << "以上为：根据键值来删除这个元素" << endl;
	}



}

//其它函数
void STLmap3()
{
	//查	找	用find（）函数来查找
	{
		typedef pair<int, char> in_pair;	//重命名，使‘pair<int, char>’简化成 ‘in_pair’来使用
		map<int, char> mo;					//定义一个map

		mo.insert(in_pair(5, 'o'));			//给map赋值：插入元素的方式
		mo.insert(in_pair(1, 'g'));
		mo.insert(in_pair(3, 'k'));
		mo.insert(in_pair(9, 't'));
		mo.insert(in_pair(7, 'u'));

		map<int, char>::iterator ui = mo.find(9);		//使用find（）查找键值，没有其它重载函数，只有这种使用键值查找的方式
		cout << ui->first << ' ' << ui->second << endl;	//利用迭代器遍历打印
		cout << "以上为：使用find（）查找输出" << endl << endl;
	}

	//交换 swap（）
	{
		//与治之前学的一样，交换两相同元素类型的容器的元素
	}

	//默认排序	很重要
	{
		//map一般是从小到大的排序
		//现改为从大到小排序
		typedef pair<int, char> in_pair;	
		map<int, char, greater<int>> mo;	//加一个仿函数greater<int>	//注意这里的参数是类型，函数的参数是实参，这二者不同

		mo.insert(in_pair(5, 'o'));			//给map赋值：插入元素的方式
		mo.insert(in_pair(1, 'g'));
		mo.insert(in_pair(3, 'k'));
		mo.insert(in_pair(9, 't'));
		mo.insert(in_pair(7, 'u'));

		map<int, char, greater<int>>::iterator ito = mo.begin();//迭代器的类型要与对象的类型一致，所以也要加greater<int>
		for (ito; ito != mo.end(); ito++)
		{
			cout << ito->first << ' ' << ito->second << endl;	//利用迭代器遍历打印
		}
		cout << "以上为：修改默认排序从大到小" << endl << endl;

	}
}

int main()
{
	//STLmap1();		//属性

	//STLmap2();		//操作

	STLmap3();			//其它函数

	return 0;

}