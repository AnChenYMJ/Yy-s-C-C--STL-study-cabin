#include <iostream>
using namespace std;

void testiterator()
{
//构建对象
string str1("Keep going Yy! you're strong! Go the distance!");
string str2("Don't be afraid.");

//begin()  与  end()
{
	//begin()	返回一个迭代器，指向字符串首元素
	str1.begin()[12] = 'Y';				//迭代器本质就是指针

	cout << str1.begin()[3] << endl;
	cout << str1 << endl;

	//end()		返回一个迭代器，指向最后一个元素的下一位
	str1.end()[-1] = '~';				//下标运算能用负数
	str1.end()[-34] = 'y';

	cout << str1 << endl;
}

//append拼接						//利用迭代器来控制拼接的大小
{
	//拼接str2的所有内容
	str1.append(str2.begin(), str2.end());
	cout << str1 << endl;

	//拼接str2的部分内容
	str1.append(str2.begin() + 6, str2.begin() + 16);		//下标为6的字符开始到下标为16的前一个
	cout << str1 << endl;
}

//erase删除						//利用迭代器来控制删除的范围
{
	str1.erase(str1.end() - 10, str1.end());		//删除末尾10个字符
	cout << str1 << endl;

	str1.erase(str1.begin() + 12);					//删除下标为12的字符
	cout << str1 << endl;
}

//insert插入						//利用迭代器来控制插入的位置
{
	str1.insert(str1.begin() + 12, 1, 'y');				//在下标为12的字符前插入 1 个 y
	cout << str1 << endl;		

	cout << str1.length() << endl;

	str1.insert(str1.begin()+46, str2.begin()+1, str2.end()-1);
	cout << str1 << endl;								//在本对象下标为46的字符前插入str2的下标为（1~15）的字符串
}

}

int main()
{
	testiterator();


	system("pause");
	return 0;
}