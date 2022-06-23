#include <iostream>
#include <map>			//multimap的头文件也是map

using namespace std;

void STLmultmap()
{
	//操作函数
	{
	//操作函数与map的都一样
	}

	//与map的区别
	{
	//1.允许键值重复
		typedef pair<int, char> in_pair;
		multimap<int, char> mmap;

		mmap.insert(in_pair(1, 'a'));
		mmap.insert(in_pair(1, 'b'));
		mmap.insert(in_pair(3, 'c'));
		mmap.insert(in_pair(3, 'c'));
		mmap.insert(in_pair(3, 'd'));
		mmap.insert(in_pair(5, 'e'));
		mmap.insert(in_pair(7, 'f'));
		mmap.insert(in_pair(7, 'f'));

		multimap<int, char>::iterator ite = mmap.begin();		//声明迭代器向首元素
		for (ite; ite != mmap.end(); ite++)
		{
			cout << ite->first << ' ' << ite->second << endl;	//迭代器遍历输出，可见成功打印重复部分
		}
		cout << "以上为遍历输出" << endl << endl;


	//2.计数		count()
		//前面在map中count是用来查看元素是否存在，而它的实际作用应该是计算这个元素在对象中出现的次数
		//因为map键值不可以重复，所以只能返回0或1，而在multimap中则能返回相同键值的个数、
		cout << mmap.count(1) << endl;
		cout << mmap.count(3) << endl;
		cout << mmap.count(5) << endl;
		cout << mmap.count(7) << endl;
		cout << mmap.count(9) << endl;							//没有这个键值则返回0
		cout << "以上为count计数" << endl << endl;


	//3.find查找		找到元素，则返回第一个找到的元素的迭代器，其他重复的部分迭代器不反回
		//如果没找到，则与map一样，返回尾元素的迭代器
		cout << mmap.find(1)->first << ' ' << mmap.find(1)->second << endl;		//发现返回的是第一个出现的键值为1的元素，后面其它的1没打印
		cout << mmap.find(3)->first << ' ' << mmap.find(3)->second << endl;
		cout << mmap.find(5)->first << ' ' << mmap.find(5)->second << endl;
		cout << mmap.find(7)->first << ' ' << mmap.find(7)->second << endl;
		//cout << mmap.find(9)->first << ' ' << mmap.find(9)->second << endl;	//不存在的键值不能这样打印
		if (mmap.find(9) == mmap.end())
		{
			cout << "不存在的键值，find返回尾元素mmap.end()" << endl;
		}
		cout << "以上为find()查找" << endl << endl;
	}
}

int main()
{
	STLmultmap();

	return 0;
}