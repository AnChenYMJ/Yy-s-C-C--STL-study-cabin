#include <iostream>
using namespace std;

void change1(int& a1, int& b1)//������������������
{						//��Ϊab����ڹ�����a1��b1�������޸�a1��b1�����޸���ab�Ŀռ�
	int Temp = a1;
	a1 = b1;
	b1 = Temp;
}

void change2(int a1, int b1)
{
	int Temp = a1;
	a1 = b1;
	b1 = Temp;
}

void change3(int* a1, int* b1)//����ָ������������
{							//��Ϊָ����ֱ���޸�ָ��Ŀռ䣬����ab���޸���
	int Temp = *a1;
	*a1 = *b1;
	*b1 = Temp;
}

int main()
{
	int a = 27;
	int b = 26;
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << endl;

	change1(a, b);//����ֵ�Ѿ�����
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << endl;

	change2(a, b);//����ֵ��û�л���
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << endl;

	change3(&a, &b);//����ֵ�Ѿ�����
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << endl;

	return 0;
}