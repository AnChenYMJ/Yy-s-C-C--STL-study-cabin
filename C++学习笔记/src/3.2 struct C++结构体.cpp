#include <iostream>
using namespace std;

struct SM	//����һ���ṹ�����ͣ�C++�нṹ�����һ���������
{
	int a;
	char b;

	void fun()	//C++�Ľṹ�����ܶ��庯����C�����в��ܶ��庯��
	{
		cout << "Keep going! you're strong!" << endl;
	}

};


int main()
{	//C++�в��ü�struct����ʹ�ýṹ��
	SM ST;//����һ���ṹ�����
	ST.fun();//���ñ����ĳ�Ա


	system("pause");
	return 0;
}