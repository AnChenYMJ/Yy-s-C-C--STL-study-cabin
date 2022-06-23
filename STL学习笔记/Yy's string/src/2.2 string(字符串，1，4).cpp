#include "2.2 Mystream.h"


Mystring::Mystring(Mystring& str, size_t index, size_t length)
{
	//申请空间
	m_str = new char[length - index + 1];//多一个装\0

	//遍历赋值
	for (size_t i = 0, j = index - 1; j < length - 1; j++, i++)
	{
		m_str[i] = str.c_str()[j];
	}

	//装入结尾
	m_str[length - index] = '\0';

	nlength = length - index + 1;
}