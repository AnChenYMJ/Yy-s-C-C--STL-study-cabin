#include <iostream>
using namespace std;

void can1(int& a)//����������
{
	a = 27;
	cout << a << endl;
}

void can2(int a)//����������
{
	a = 28;
	cout << a << endl;
}

void can3(int* a)//ָ��������
{
	*a = 29;
	cout << *a << endl;
}

int main()
{
	int b = 26;
	can1(b);		//��Ϊ�����ǽ�װ��ֵ�Ŀռ���˸���ڣ������ں�����ͨ�������ܸı�ؼ���ֵ
	cout << "can1�� b = " << b << endl;//�����ڸı��˱���b��ֵ

	can2(b);		//����2ֻ�ǽ�b��ֵ��������2�еı��������Բ���ı�bԭ����ֵ
	cout << "can2�� b = " << b << endl;//b��ֵ�ں���2��δ�ı�

	can3(&b);		//����3ͨ��ָ�������ݲ��������Ժ���3�ڵ�ָ��ָ��b�������ͨ���ڴ�������޸�b�Ŀռ�
	cout << "can3�� b = " << b << endl;//b��ֵ�ں���3�ڱ��޸�

	return 0;
}