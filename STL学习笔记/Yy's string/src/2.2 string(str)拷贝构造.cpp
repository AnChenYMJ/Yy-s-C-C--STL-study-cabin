#include "2.2 Mystream.h"

Mystring::Mystring(const Mystring& str)
{
	//����ռ�						//��֪Ϊ����������ռ��Ҫ+1
	m_str = new char[str.size()+1];	//����Ŀռ��СΪ��Ķ�����ַ�����С
	nlength = str.size();			

	//������ֵ
	for (size_t i = 0; i < str.size(); i++)
	{
		m_str[i] = str.m_str[i];	//������ֵ
	}
}