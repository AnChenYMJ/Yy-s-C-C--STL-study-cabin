#include "2.2 Mystream.h"


Mystring::Mystring(size_t length, char ch)
{
	m_str = new char[length + 1];	//��Ϊ���һ����װ\0,����Ҫ+1

	for (unsigned int i = 0; i < length; i++)//unsigned int == size_t == size_type
	{										//��Ϊ�������Ĳ�����size_t���ͣ�������֮�Ƚϵ�iҲ�����������͵�
		m_str[i] = ch;						//�������wangning�� �ǵ���intҲ�ǿ��е�
	}
	m_str[length] = '\0';			//���һ���ռ�װ\0

	nlength = length + 1;				//���ַ����ռ��С�ı�־��ֵ
}
