#include "2.2 Mystream.h"


//string(const char* str, size_t length)//�ַ���ǰlength���ַ�������ֵ
Mystring::Mystring(const char* str, size_t length)
{
	//if (length < 0 || str == NULL)
	//{
	//			//ע�⣬һ����˵����������������һ�����Ϸ���⣬�����ݵĲ����������ǵķ�Χʱ��
	//			//��һ��������ʽ
	//}
	//����ռ�
	m_str = new char[length + 1];//��һ����װ\0

	//������ֵ
	for (size_t i = 0; i < length; i++)//�±������0��ʼ��length-1 ���Ǹպ�length�ĸ���
	{
		m_str[i] = str[i];
	}

	//��ӽ�β\0
	m_str[length] = '\0';		//length���±�������������һ���ַ��ռ�

	nlength = length + 1;
}