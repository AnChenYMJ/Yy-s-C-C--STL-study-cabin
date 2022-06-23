#include <iostream>
#include <vector>
#include <algorithm>		//for_each()  的头文件
#include <functional>		//greater<> ()的头文件	
using namespace std;

void show(int i)			//有无返回值都可以，参数要与容器元素类型一致
{	
	cout << i << ' ';
}

void STLadd()
{
//添加
{
	vector<int> vec1;
	vector<int> vec2(5, 99);
	vector<int> vec3(4, 18);

	//尾添加
	{
		vec1.push_back(55);			//在容器对象尾部添加一个值

		for (size_t i = 0; i < vec1.size(); i++)
		{
			cout << vec1[i] << ' ';
		}
		cout << endl;

		vec1.push_back(55);
		vec1.push_back(55);
	}

	//中间插入
	{
		for_each(vec2.begin(), vec2.end(), show);
		cout << endl;

		vec2.insert(vec2.begin()+2, 26);		//在指定位置添加一个元素
		for_each(vec2.begin(), vec2.end(), show);
		cout << endl;

		vec2.insert(vec2.begin() + 5, 6, 30);	//在指定位置添加num个值为val的元素
		for_each(vec2.begin(), vec2.end(), show);
		cout << endl;

		vec2.insert(vec2.end() - 2, vec3.begin() + 1, vec3.begin() + 3);
		for_each(vec2.begin(), vec2.end(), show);//在指定位置添加另一个向量的一段
		cout << endl;

		vec2.insert(vec2.end(), 11);			//也可以利用规则在尾部添加
		for_each(vec2.begin(), vec2.end(), show);
		cout << endl;
	}

	//总结
	{
		//数组不是链表，数组有自己的排序组装规则。
		//所以添加时，比如中间插入就会变得麻烦，插入位置之后的值要整体后移。
		//所以push_back 要比 insert 的效率来得更高。
		//尾部添加 比 中间插入 效率更高，不必考虑重新增加空间。
	}
}

//删
{
	vector<int> vec2(5, 99);
	vector<int> vec3(4, 18);

	//尾删除		pop_back()
	{
		for_each(vec3.begin(), vec3.end(), show);
		cout << endl;

		vec3.pop_back();			//一次删除一个

		for_each(vec3.begin(), vec3.end(), show);
		cout << endl;

		vec3.erase(vec3.end()-1);	//必须-1 因为end（）指向最后一个元素的下一位，否则导致崩溃

		for_each(vec3.begin(), vec3.end(), show);
		cout << endl;
	}

	//删除指定	erase()
	{
		vec2.erase(vec2.begin() + 4);

		for_each(vec2.begin(), vec2.end(), show);
		cout << endl;

		vec2.erase(vec2.begin() + 1, vec2.begin() + 3);

		for_each(vec2.begin(), vec2.end(), show);
		cout << endl;

		vec2.erase(vec2.end() - 1);				//删除尾部，必须-1，因为迭代器指向末尾元素的下一位。越界操作了。

		for_each(vec2.begin(), vec2.end(), show);
		cout << endl;
	}

	//删除全部	clear()
	{
		cout << "删除全部 clear：" << endl;
		for_each(vec2.begin(), vec2.end(), show);
		cout << endl;
		for_each(vec3.begin(), vec3.end(), show);
		cout << endl;

		vec2.clear();				//clear函数：删除全部
		vec3.clear();				//也是很常用的函数

		for_each(vec2.begin(), vec2.end(), show);
		cout << endl;
		for_each(vec3.begin(), vec3.end(), show);
		cout << endl;
	}
}

//修改
{
	//利用3.4中的输出的知识去修改

	//利用assign 重新赋值
	vector<int> vec2(5, 99);
	vector<int> vec3(4, 18);

	vec2.assign(45, 5);								//45个5给向量赋值,容量也从5变成了45
	vec3.assign(vec2.begin() + 1, vec2.begin() + 7);//用另一个向量的某一段给本向量赋值

	cout << "修改赋值 assign：" << endl;
	for_each(vec2.begin(), vec2.end(), show);
	cout << endl;
	for_each(vec3.begin(), vec3.end(), show);
	cout << endl;
	cout << vec2.capacity() << endl;				//容量变成了45

	vec2 = vec3;									//用另一个向量直接赋值给本向量

	for_each(vec2.begin(), vec2.end(), show);
	cout << endl;		
	cout << vec2.capacity() << endl;				//容量并没有变化，除非溢出容量
}

//交换
{
	vector<int> vec2(5, 99);
	vector<int> vec3(4, 18);

	for_each(vec2.begin(), vec2.end(), show);
	cout << endl;

	for_each(vec3.begin(), vec3.end(), show);
	cout << endl;

	//交换
	vec2.swap(vec3);			//交换两向量的内容

	for_each(vec2.begin(), vec2.end(), show);
	cout << endl;

	for_each(vec3.begin(), vec3.end(), show);
	cout << endl;
}

//运算符重载 比较 与 []
{
	vector<int> vec2(5, 99);
	vector<int> vec3(4, 18);

	//比较
	{
		cout << (vec2 >= vec3) << endl;		//成功返回 1 

		cout << (vec2 <= vec3) << endl;		//失败返回 0

		cout << (vec2 == vec3) << endl;		//失败返回 0
	}

	//下标运算符
	{
		cout << vec2[2] << endl;
	}
}

//两个算法
{
	vector<int> vec2(5, 99);
	vector<int> vec3(4, 18);

	//算法一：for_each 遍历
	{
		for_each(vec3.begin(), vec3.end(), show);		//与string一样的用法
		cout << endl;
	}

	//算法二：sort 排序
	{
		vec2.push_back(46);
		vec2.push_back(7);
		vec2.push_back(32);
		vec2.push_back(27);
			
		vec2.insert(vec2.begin() + 1, 135);				//指定位置插入元素
		vec2.insert(vec2.begin() + 3, 65);

		sort(vec2.begin()+4, vec2.end()-1);				//与string一样的用法功能：指定范围内排序
														//默认从小到大排序
		for_each(vec2.begin(), vec2.end(), show);		
		cout << endl;

		sort(vec2.begin(), vec2.end(), greater<int>());	//从大到小排序，要添加第三个参数greater<>()伪函数
														//greater<int>() <>内的类型要与元素类型一致
		for_each(vec2.begin(), vec2.end(), show);
		cout << endl;
	}
}

}

int main()
{
	STLadd();				//除了vector，还有array，valarray这俩容器
							//array在VS2015中不支持，2013以后支持，不常用
							//valarray是一些数学函数的封装，用到数学计算的话，可以直接调用函数。
							//不过如果计算量大，公式多，肯定是用valarray要更有效率方便。


	system("pause");
	return 0;
}