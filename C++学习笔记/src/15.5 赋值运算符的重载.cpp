#include <iostream>
using namespace std;

class Cstu
{
private:
	int ange;
	double high;
public:
	Cstu() :ange(27)
	{
		high = 165.897;
	}

	int operator = ( int b)//��operator =�������ǷǾ�̬��Ա�������ڳ�Ա��
	{
		ange = b;
		return ange;
	}

	void show()
	{
		cout << ange << endl;
	}

	friend int operator += (Cstu& a, int b);

	friend int operator += (Cstu& a, Cstu& b);
};

//void operator = (Cstu& a, int b)//error C2801: ��operator =�������ǷǾ�̬��Ա�������ڳ�Ա��
//{
//	a.ange = b;					//operator = ���������ڳ�Ա
//}
	//���ﷵ�����õĻ����ǲ���ҲҪ�ĳ�����
int operator += (Cstu& a, int b)	//���ظ�ֵ���������
{									//���Ͻ���д�����ڣ�������д������
	a.ange += b;
	return a.ange;
}

//int operator += (Cstu& a, Cstu& b)	//��������������һ�������Ƕ���Ļ����ͱ���д���������
//{										//����������������һ�������ǳ����Ļ�����д������һ��������
//	a.ange += b.ange;
//	return a.ange;
//}

int main()
{
	Cstu te;
	cout << (te = 56) << endl;

	//cout << (te = 56 = 89) << endl;//������������ֵ����Ϊ=����Դ������󣬶������������Ϊ��ֵ

	Cstu su;
	Cstu ta;
	su.show();
	cout << (te += su += ta += 15) << endl;//���÷���ֵ��ʵ����������
	su.show();		//+= �Ľ���Դ������󣬾����������������һ�������������ֵ
	//cout << (te += su += ta) << endl;//������Ҫ����+=���������

	system("pause");
	return 0;
}