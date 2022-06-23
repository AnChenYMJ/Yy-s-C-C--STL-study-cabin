//#pragma once		//防止头文件重复包含方法一

#ifndef _MYSTREAM		//防止头文件重复包含方法一

#define	_MYSTREAM

#include <iostream>
using namespace std;

class Mystring
{
private:						
	char* m_str;
	size_t nlength;
public:
	Mystring();		//指针内容填入'\0'，'\0'是在new申请的空间里	//2.1

	Mystring(size_t length, char ch);							//2.2 string(5, a)
		
	Mystring(const char* str);									//2.2 string("abcdefg")

	Mystring(const char* str, size_t length);					//2.2 string("abcdefghij", 3);

	Mystring(Mystring& str, size_t index, size_t length);		//2.2 string("abcdefghij", 2, 5);

	Mystring(const Mystring& str);								//2.2 string(const Mystring& str)
	
	~Mystring();	//释放构造函数new的空间
public:
	const char* c_str() const;	//返回指针
	const size_t size()	const;	//返回字符串空间值大小

	friend istream& operator >> (istream& is, Mystring& str);	//要用到私有成员m_str,所以使用友元
	
};

//输出重载
ostream& operator << (ostream& os, Mystring& str);	//输出运算符重载		//类外，写在全局区算作面向过程
																		//类内，写在类内算作面向对象
//输入重载
istream& operator >> (istream& is, Mystring& str);	//输入运算符重载		


#endif