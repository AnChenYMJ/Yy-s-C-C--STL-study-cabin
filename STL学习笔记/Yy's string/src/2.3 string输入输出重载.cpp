#include "2.2 Mystream.h"


//�������
ostream& operator << (ostream& os, Mystring& str)		//��Ϊ���������⣬���Բ��ü�����������
{
	os << str.c_str();
	return os;
}

//��������				//������һ��д�������ܼ�д��ʲô�̶�
istream& operator >> (istream& is, Mystring& str)
{

//��¼�����ַ���
	char* n_str = new char[60];		//�����¼�Ŀռ�
												//.gcount()��istream���м�¼�����ַ����ĺ���
	is >> n_str;

//ȷ���ַ���
	size_t num ;		//����������ѭ���ڵĻ������Ǿֲ������ˣ�����ѭ�����ͷŵ������޷���¼num��ֵ
	for (num = 0; n_str[num] != '\0'; num++);

//�ͷŶ���ռ�
	delete[] str.m_str;

//����ռ�
	str.m_str = new char[num + 1];		//ȷ���ַ����Ĳ���õ������±꣨��0��ʼ����ʵ���ַ���Ҫ+1

//������ֵ��ʵ�ָ��Ƕ���ԭ���ݣ�
	size_t i;							//����ֲ����������������ַ������ı�ʱʹ��
	for ( i = 0; i <= num; i++)
	{
		str.m_str[i] = n_str[i];
	}

//TODO:�ַ������ı�
	str.nlength = i;					//�˴�����ʹ��.size����,��Ϊ��const���ε�
										//���û��nlength���ã��͸ı�zise�������Ƶ�ȡ����дһ�������ַ���������

//����is
	return is;
}