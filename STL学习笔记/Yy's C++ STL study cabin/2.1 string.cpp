#include <iostream>
#include <string>//不要写成string.h， .h是C语言中另一些操作字符串的函数们
using namespace std;//string是封装在标准命名空间std中的，如果不写标准命名空间，就得用std::string来调用

int main()			//string的属性，笔试面试会经常问到
{
	string str;//当申请string的对象没有传递参数时，字符串的指针究竟是传递一个NULL,还是申请空间装入'\0'呢
	const char* stc = str.c_str();//发现测试结果，断点调试发现stc里装的是'\0'
	//.c_str函数的作用是将对象的字符串空间的指针装到一个指针m_str里，再返回给我们
	cout << stc << endl;		

	//在另一个项目2.1 Mystring中，写了相关无参数时string类中的操作
	//两个工程同时打开时，右击工程，启动调试或设为启动项目，因为调试一次只能调试一个工程

	//STL学习意见：先会用，再去研究源码是怎么实现的，能提高不少效率，学习源码能提高我们的水平
	
	
	//不论学习STL的什么，如string、vector等
	//套路就是：定义、属性、输出、修改、操作函数


	cout << stc << endl;

	system("pause");
	return 0;
}