#include "2.2 Mystream.h"


Mystring::Mystring()	//要加类名作用域			//没有参数的函数构造
{
	m_str = new char('\0');	//指针装着new出的空间里的'\0'。
	nlength = 1;
}

Mystring::~Mystring()
{
	delete m_str;
}
	

const char* Mystring::c_str() const	//用const修饰函数，使函数内容不可变，const修饰返回值，使返回值不可变，更安全
{
	return m_str;			//返回字符串地址，因为是类内操作，所以能对数据成员操作，但传递出去有风险，用const修饰
}


const size_t Mystring::size() const	//返回字符串空间值大小，nlength的大小在不同的构造函数中被赋值
{
		return nlength;
}
