#include "2.2 Mystream.h"


Mystring::Mystring(Mystring& str, size_t index, size_t length)
{
	//����ռ�
	m_str = new char[length - index + 1];//��һ��װ\0

	//������ֵ
	for (size_t i = 0, j = index - 1; j < length - 1; j++, i++)
	{
		m_str[i] = str.c_str()[j];
	}

	//װ���β
	m_str[length - index] = '\0';

	nlength = length - index + 1;
}