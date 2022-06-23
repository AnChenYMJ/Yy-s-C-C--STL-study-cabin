#include <iostream>
using namespace std;


int main()
{
	string stc("abcdefghij", 5);		//将字符串的前5个字符给对象赋值
	cout << stc.c_str() << endl;

	string stc1(stc, 1, 3);				//将传入的字符串的中间的字符串给对象初始化
	cout << stc1.c_str() << endl;		//原本只打印bc的（视频），但我的编译器打印了bcd，应该是从第1个开始往后3个

	system("pause");
	return 0;
}