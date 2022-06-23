//#pragma once		//��ֹͷ�ļ��ظ���������һ

#ifndef _MYSTREAM		//��ֹͷ�ļ��ظ���������һ

#define	_MYSTREAM

#include <iostream>
using namespace std;

class Mystring
{
private:						
	char* m_str;
	size_t nlength;
public:
	Mystring();		//ָ����������'\0'��'\0'����new����Ŀռ���	//2.1

	Mystring(size_t length, char ch);							//2.2 string(5, a)
		
	Mystring(const char* str);									//2.2 string("abcdefg")

	Mystring(const char* str, size_t length);					//2.2 string("abcdefghij", 3);

	Mystring(Mystring& str, size_t index, size_t length);		//2.2 string("abcdefghij", 2, 5);

	Mystring(const Mystring& str);								//2.2 string(const Mystring& str)
	
	~Mystring();	//�ͷŹ��캯��new�Ŀռ�
public:
	const char* c_str() const;	//����ָ��
	const size_t size()	const;	//�����ַ����ռ�ֵ��С

	friend istream& operator >> (istream& is, Mystring& str);	//Ҫ�õ�˽�г�Աm_str,����ʹ����Ԫ
	
};

//�������
ostream& operator << (ostream& os, Mystring& str);	//������������		//���⣬д��ȫ���������������
																		//���ڣ�д�����������������
//��������
istream& operator >> (istream& is, Mystring& str);	//�������������		


#endif