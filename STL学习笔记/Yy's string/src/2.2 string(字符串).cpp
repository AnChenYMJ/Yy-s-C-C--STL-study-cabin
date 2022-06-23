#include "2.2 Mystream.h"

				//string(const char* str)	//用字符串给对象初始化
Mystring::Mystring(const char* str)
{
	const char* cop = str;
	unsigned int num = 0;

	//获取字符数
	while ('\0' != *cop)
	{
		++cop ;			//地址根据类型+1
		++num ;			//字符数标志+1
	}

	//申请空间
	m_str = new char[num+1];		//num+1是因为，这是申请空间字节大小，而不是从0开始计数的下标运算，比如0~8是9字节大小，所以+1

	//遍历赋值
	for (size_t i = 0; i <= num; i++)//warning C4018: “<”: 有符号/无符号不匹配//是因为之前num写成了signed int类型，而i是unsigned int类型
	{									//使用<的话循环到num时就跳出了，\0就没复制进去，所以+1或是用<=
		m_str[i] = str[i];
	}

	nlength = num + 1;
}