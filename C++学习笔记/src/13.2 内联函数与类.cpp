#include <iostream>
#include "13.2.h"
using namespace std;

#define SUM(x) (x*x)  //Ҫ������������ˣ����루��x��*��x����

inline void fun(int i)//�����⣬�������inline��ǰ׺������������
{						//�������������ж������
	cout << (i * i) << endl;//һ����˵���������Ѷ���д��ͷ�ļ��У�ע���Ƕ��岻������
}

class CST
{
public:		//�����ڣ�������ͨ������Ĭ��Ϊ��������
	//void fun()		 //��ʽ��������
	//{

	//}
	inline void fun()//��ʽ��������
	{

	}
};

int main()
{
	cout << SUM(2 + 3) << endl;//���Ϊ11����Ϊ���ǵ������滻������ִ�е��ǣ�2+3*2+3���ȳ˺��Ϊ11
			
	fun(5);//�ɼ�������������Ⱥ�Ҫ��������һЩ


	return 0;
}