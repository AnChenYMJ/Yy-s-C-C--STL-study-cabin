#include <iostream>
#include <vector>			//C++标准的头文件基本不带.h，可能是为了与C语言区分开，某些头文件内容其实是差不多的
#include <algorithm>		//for_each()  的头文件
#include <ctime>			//time()函数的头文件
using namespace std;

void show(int i)
{
	cout << i << ' ';
}

void STLran()
{
	vector<int> vec1;

	//循环遍历添加元素
	for (size_t i = 0; i < 16; i++)
	{
		vec1.push_back(i * i * i);
	}
	//打印
	for_each(vec1.begin(), vec1.end(), show);
	cout << endl;

	//乱序算法 random_shuffle()			//乱序不变的情况
	random_shuffle(vec1.begin(), vec1.end());
	//打印
	for_each(vec1.begin(), vec1.end(), show);
	cout << endl;				//这样发现一个问题，每次运行程序，虽然顺序乱了，但每次打开的顺序都是一模一样的
								//原因是这个算法利用了随机数函数，而随机数函数不是真正的随机
								//除非有一个不断变化不重复的触发值，否则触发值相同，乱序也就相同
		

	//乱序算法 random_shuffle()			//乱序变化的情况
	srand((unsigned int)time(0));		//加上这么一个，利用当前的系统时间来当作触发值
										//因为时间是变化的，且不会重复，所以每一次的乱序都不同

	random_shuffle(vec1.begin(), vec1.end());
	//打印
	for_each(vec1.begin(), vec1.end(), show);
	cout << endl;

}

int main()
{
	STLran();



	system("pause");
	return 0;
}