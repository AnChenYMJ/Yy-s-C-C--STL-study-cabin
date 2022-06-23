#include "2.2 Mystream.h"

Mystring::Mystring(const Mystring& str)
{
	//申请空间						//不知为何这里申请空间非要+1
	m_str = new char[str.size()+1];	//申请的空间大小为别的对象的字符串大小
	nlength = str.size();			

	//遍历赋值
	for (size_t i = 0; i < str.size(); i++)
	{
		m_str[i] = str.m_str[i];	//挨个赋值
	}
}