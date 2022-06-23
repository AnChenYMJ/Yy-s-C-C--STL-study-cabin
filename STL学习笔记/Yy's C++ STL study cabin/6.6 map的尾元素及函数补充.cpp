#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

void STLmap()
{
	//尾元素的深入了解
	{
	typedef pair<int, char> in_pair;
	map<int, char> mp;

	mp.insert(in_pair(1, 'a'));
	mp.insert(in_pair(3, 'a'));
	mp.insert(in_pair(5, 'a'));
	mp.insert(in_pair(9, 'a'));
	mp.insert(in_pair(12, 'a'));

	//cout << mp.find(6)->first << endl;		//因为元素中不存在6这个键值所以运行错误了
				//注意==才是等于；=是赋值
	if (mp.find(6) == mp.end())					//成功打印，证明了find没找到对应元素，则返回尾元素的迭代器
	{
		cout << "find没有对应元素的话，则返回尾元素，即mp.end()" << endl << endl;
	}

	if (mp.find(6) == mp.find(12))				//没有打印，则证明了对象中尾元素end（）不是最后一个元素，而是最后一个元素的下一位
	{
		cout << "find没有对应元素的话，则返回尾元素，即mp.end()" << endl << endl;
	}

	}
	
	//其它函数	//接上节课的补充（不重要）
	{
		typedef pair<int, char> in_pair;
		map<int, char> mp;

		mp.insert(in_pair(1, 'a'));
		mp.insert(in_pair(3, 'a'));
		mp.insert(in_pair(5, 'a'));
		mp.insert(in_pair(9, 'a'));
		mp.insert(in_pair(12, 'a'));

		//1.lower_bound()
			//返回参数的位置，参数为键值key，如果没有这个键值，则会返回大于这个参数的存在的键值
			//比如7，如果不存在7这个键值，则返回9回来，即key <= 返回值
			//有两个作用：1.确定这个节点是否存在。2.没有这个节点，那这个节点应该插入的位置
		cout << mp.lower_bound(7)->first << endl;		//成功返回9，注意，因为返回的是迭代器，而迭代器有键值实值，所以要指定first还是second

		//2.upper_bound()
		//与lower_bound对比：key < 返回值		即返回大于参数的键值
		cout << mp.upper_bound(9)->first << endl;		//c成功返回12

		//3.equal_range()
		//返回一个区间:即返回迭代器，这个迭代器的成员也是迭代器，这两个元素迭代器则是lower_bound()与upper_bound()的结果组合起来
		cout << mp.equal_range(9).first->first << ' ' << mp.equal_range(9).second->first << endl;
	}

}

int main()
{
	STLmap();

	return 0;
}