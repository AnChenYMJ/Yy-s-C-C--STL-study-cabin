#include "2.2 Mystream.h"


Mystring::Mystring()	//Ҫ������������			//û�в����ĺ�������
{
	m_str = new char('\0');	//ָ��װ��new���Ŀռ����'\0'��
	nlength = 1;
}

Mystring::~Mystring()
{
	delete m_str;
}
	

const char* Mystring::c_str() const	//��const���κ�����ʹ�������ݲ��ɱ䣬const���η���ֵ��ʹ����ֵ���ɱ䣬����ȫ
{
	return m_str;			//�����ַ�����ַ����Ϊ�����ڲ����������ܶ����ݳ�Ա�����������ݳ�ȥ�з��գ���const����
}


const size_t Mystring::size() const	//�����ַ����ռ�ֵ��С��nlength�Ĵ�С�ڲ�ͬ�Ĺ��캯���б���ֵ
{
		return nlength;
}
