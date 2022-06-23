#include <iostream>
using namespace std;

#pragma	warning(disable:4996)			//用来屏蔽对应标号的警告

//复制比较
void Compare()
{
	string str1("abcdef");
	string str2("abcdefg");

//用运算符重载来比较						//结果只有 0 或 1（真 或 假）
{
	cout << "运算符重载比较：" << endl;

	cout << (str1 == str2) << endl;		//对象与对象比较

	cout << (str1 >= "abcdef") << endl;	//对象与字符串比较

	cout << (str1 <= "abcdef") << endl;	//有6种运算符

	cout << (str1 > "abcdef") << endl;

	cout << (str1 < "abcdef") << endl;

	cout << (str1 != "abcdef") << endl;
}

//用compare来进行比较						//大于则返回1 ，小于则返回-1 ，等于则返回0；
{
	cout << "compare比较：" << endl;

	cout << str1.compare(str2) << endl;//-1			//对象与对象进行比较

	cout << str1.compare("abcdef") << endl;//0		//对象与字符串进行比较

	cout << str2.compare(0, 7, str1) << endl;//1	//本对象的某一段与对象进行比较	//若换成0，6，则相等

	cout << str1.compare(1, 4, str2, 1, 4) << endl;//0 //本对象的一段与对象的一段进行比较
						//前两参数是本对象str1的范围（index，length），最后两个参数是对象str2的范围（index，length）
}

//复制对象内容到对象外
{
	cout << "copy():" << endl;

	char chs[30] = { 0 };				//使用复制时容易越界，就会有warning提示，且提示有一个标号,如果嫌提示烦，
										//在全局区上面加#pragma warning（disable：4996）;即可屏蔽提示（4996是提示标号）
	str2.copy(chs, 5, 2);				//复制5个字符，从第2个字符开始，复制到chs中
	
	cout << chs << endl;
}

}

int main()
{
	Compare();							//compare：比较

	//不论学习STL的什么，如string、vector等。
	//套路就是：定义、属性、输出、修改、操作函数


	system("pause");
	return 0;
}