#include "2.2 Mystream.h"

int main()
{
	Mystring str;					//2.1
	const char* stb = str.c_str();	//断点调试，实现了和原标准库相同的功能
	cout << stb << endl;			//new的空间里装了'\0',再赋值给指针m_str
	


	Mystring str1(4, 'b');			//2.2 string(5, 'a')
	cout << str1.c_str() << endl;	//成功实现用4个b给对象赋值	//c_str()这个函数返回字符串空间地址
								

									//2.2 string("abcdefg")
	Mystring str2("Keep going! Yy, Don't stop.");	//成功实现用字符串初始化
	cout << str2.c_str() << endl;//可以打印str2.c_str()+2 来试试是否把\0赋值到m_str里，如果进去了，则不会出现乱码，后面都是空


									//2.2 string("abcdefghij", 3)
	Mystring str3("Keep going! Yy, Don't stop.", 13);//成功实现用字符串前13个字符给对象赋值
	cout << str3.c_str() << endl;


	Mystring str4(str3, 1, 5);		//2.2 string("abcdefghij", 2, 5);
	cout << str4.c_str() << endl;	//成功实现用另一个对象的中间第1~4的字符来进行初始化


	Mystring str5(str2);			//2.2 string(const Mystring& str)
	cout << str5.c_str()+12 << endl;//成功实现用一个对象给另一个对象初始化。


	Mystring str6("keep going! Yy, you're strong!");//成功实现直接输出对象名就能输出字符串
	cout << str6 << endl;			//2.3 输出运算符重载

	Mystring str7("keep going! Yy, you're strong!");
	cout << str7 << endl;
	cout << str7.size() << endl;	
	cin	 >> str7;					//2.3 输入运算符重载
	cout << str7 << endl;			//成功实现输入字符覆盖对象字符串内容
	cout << str7.size() << endl;	//打印查看字符数是否改变




	system("pause");
	return 0;
}