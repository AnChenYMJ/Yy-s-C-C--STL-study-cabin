#include <iostream>
using namespace std;

class Cte
{
public:
	int ange;
	Cte(int age)
	{
		ange = age;
	}

	int operator~()//��Ϊ���ز���this�Ѿ�ָ��ǰ�������Բ�����д��	//����һԪ�������ȡ���ɣ�
	{
		//return (~ange);		//����д��������
		return (~this->ange);
	}
};

int operator-(Cte& a)//����һԪ�����
{
	return (-a.ange);
}

int main()
{
	Cte su(56);

	cout << -su << endl;	//-56

	cout << ~su << endl;	//-57

	system("pause");
	return 0;
}