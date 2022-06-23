#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void show(int i)		//这个函数的参数的类型，必须要与容器的元素类型一致，我写成char输出了乱码
{
	cout << i << ' ';
}

void STLost()
{
//单个输出
{
	//at()
	{
		vector<int> vec1;

		//循环添加元素
		for (int i = 0; i < 11; i++)
		{
			vec1.push_back(i);			//push_back()	在容器尾部添加一个元素，参数即这个元素的值
		}

		//at() 单个输出
		cout << vec1.at(7)  << endl;

		//cout << vec1.at(11) << endl;	//越界时at（）会抛出一个异常，我们可以对这个异常进行处理与过滤

		//at 循环遍历输出
		for (size_t i = 0; i < vec1.size(); i++)
		{
			cout << vec1.at(i) << ' ';
		}
		cout << endl;
		
	}

	//[] 下标运算
	{
		vector<int> vec1;

		//循环添加元素
		for (int i = 0; i < 7; i++)
		{
			vec1.push_back(i + 2);			//push_back() 在尾部添加一个元素，参数是此元素的值
		}

		//输出单个元素
		cout << vec1[6] << endl;

		//cout << vec1[7] << endl;			//下标越界直接就崩溃了	//at（）越界是抛出一个异常

		//[]循环遍历输出
		for (size_t i = 0; i < vec1.size(); i++)	//size()的返回值是size_t类型的，即unsigned int
		{
			cout << vec1[i] << ' ';
		}
		cout << endl;
	}

	//back() 返回尾巴的元素
	{
		vector<int> vec1;

		//循环添加元素
		for (int i = 0; i < 5; i++)
		{
			vec1.push_back(i * i);
		}

		//输出单个元素
		cout << vec1.back() << endl;	//16

		cout << vec1.back()-3 << endl;	//16-3 ==13
		//back（）没有参数，也不能进行地址偏移

	}

	//begin（）返回头部迭代器
	{
		vector<int> vec1;

		//循环添加元素
		for (int i = 0; i < 8; i++)
		{
			vec1.push_back(i * i * i * i);
		}

		//输出单个元素
		cout << vec1.begin()[0]		<< endl;

		cout << (vec1.begin()+2)[0] << endl;	//begin()能够进行地址偏移，这个写法与*(vec1.begin() + 2)效果一样

		//循环遍历输出
		for (size_t i = 0; i < vec1.size(); i++)
		{
			cout << *(vec1.begin() + i) << ' ';	//迭代器本质就是指针，所以能用地址操作符
		}
		cout << endl;
	}
}

//全部输出
{
//循环 迭代器  与 下标
{
	vector<int> vec1;

	//循环添加元素
	for (int i = 0; i < 7; i++)
	{
		vec1.push_back(i * i * i * i * i * i);			//push_back() 在尾部添加一个元素，参数是此元素的值
	}

	vector<int>::iterator ite = vec1.begin();

	//下标循环遍历输出
	for (size_t i = 0; i < vec1.size(); i++)	//size()的返回值是size_t类型的，即unsigned int
	{
		cout << vec1[i] << ' ';
	}
	cout << endl;

	//begin（）循环遍历输出
	for (size_t i = 0; i < vec1.size(); i++)
	{
		cout << *(vec1.begin() + i) << ' ';	//迭代器本质就是指针，所以能用地址操作符
	}
	cout << endl;

	//迭代器循环遍历输出
	for (ite; ite != vec1.end(); ite++)
	{
		cout << *ite << ' ';
	}
	cout << endl;
}

//for_each 算法遍历输出	//遍历头文件是<algorithm>
{
	vector<int> vec1(12);

	//循环添加元素
	for (int i = 0; i < vec1.size(); i++)
	{
		vec1[i] = (i * i * i * i * i * i);			//push_back() 在尾部添加一个元素，参数是此元素的值
	}

	//for_each 算法输出
	for_each(vec1.begin(), vec1.end(), show);		//最后一个参数为函数，且不需要写参数，for_each自动会将参数传递

	cout << endl;
}
}


}

int main()
{
	STLost();			//学习不要使用番茄助手，否则像结构体声明后要加分号等经常交给番茄助手的话，
						//就会以后换编译器，就会忘掉，且不利于我们记忆关键字等
						//且在以后工作中编写工程，程序员的思绪会被一些语法小问题给打断，会很难受。
						//而这些小问题，就是我们使用番茄助手带来的副作用。

						//某些时候我们运行错误时会有提示：是否继续运行上次成功时的...
						//点 否，不要点 是；因为 是 将运行程序改动前没问题的程序。就看不到当前程序的问题了


	system("pause");
	return 0;
}