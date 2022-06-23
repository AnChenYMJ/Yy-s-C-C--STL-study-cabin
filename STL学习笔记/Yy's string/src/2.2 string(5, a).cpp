#include "2.2 Mystream.h"


Mystring::Mystring(size_t length, char ch)
{
	m_str = new char[length + 1];	//因为多出一个来装\0,所以要+1

	for (unsigned int i = 0; i < length; i++)//unsigned int == size_t == size_type
	{										//因为传进来的参数是size_t类型，所以与之比较的i也得是这种类型的
		m_str[i] = ch;						//否则会有wangning， 非得用int也是可行的
	}
	m_str[length] = '\0';			//最后一个空间装\0

	nlength = length + 1;				//给字符串空间大小的标志赋值
}
