#include "2.2 Mystream.h"

				//string(const char* str)	//���ַ����������ʼ��
Mystring::Mystring(const char* str)
{
	const char* cop = str;
	unsigned int num = 0;

	//��ȡ�ַ���
	while ('\0' != *cop)
	{
		++cop ;			//��ַ��������+1
		++num ;			//�ַ�����־+1
	}

	//����ռ�
	m_str = new char[num+1];		//num+1����Ϊ����������ռ��ֽڴ�С�������Ǵ�0��ʼ�������±����㣬����0~8��9�ֽڴ�С������+1

	//������ֵ
	for (size_t i = 0; i <= num; i++)//warning C4018: ��<��: �з���/�޷��Ų�ƥ��//����Ϊ֮ǰnumд����signed int���ͣ���i��unsigned int����
	{									//ʹ��<�Ļ�ѭ����numʱ�������ˣ�\0��û���ƽ�ȥ������+1������<=
		m_str[i] = str[i];
	}

	nlength = num + 1;
}