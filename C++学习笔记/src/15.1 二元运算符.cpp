#include <iostream>
using namespace std;

class Cstu		//�����C++��C���Զ���һЩ�����ǿ��Է��鿴һ������Щ�������ҵ��Ӱ����
{					//C++ primer plus �����������˳����C���Ժ����е㲻̫һ��
public:
	int ange;
	Cstu(int b)
	{
		ange = b;
	}

	int operator >= ( Cstu& b)	//���ڹ�ϵ�����
	{
		return (this->ange >= b.ange);//��ϵ��������������õ�1���棩����������õ�0�����棩
	}

	int operator|( Cstu& b)//����λ�����
	{
		return (ange | b.ange);
	}

	int operator||( Cstu& b)		//�����߼������
	{
		return (this->ange || b.ange);
	}
};

int operator <= (Cstu& a, Cstu& b)	//�����ϵ�����
{
	return (a.ange <= b.ange);//��ϵ��������������õ�1���棩����������õ�0�����棩
}

int operator&(Cstu& a, Cstu& b)		//����λ�����
{
	return (a.ange & b.ange);
}
int operator&&(Cstu& a, Cstu& b)		//�����߼������
{
	return (a.ange && b.ange);
}
int main()
{
	//Cstu te;//������캯���в�������������������ʱ����������������û�й����ɹ���
			//����û�гɹ������Ķ���ռ�ռ�

	Cstu te(5);
	Cstu su(7);

//��Ԫ�������
	//�����������+ - * / % 
	//��ϵ�������>= <= > < != ==
	//λ�������^ & |
	//�߼��������&&	||

	cout << (te <= su) << endl;//��ϵ�����
	cout << (te >= su) << endl;

	cout << (te & su) << endl;//λ�����
	cout << (te | su) << endl;

	cout << (te || su) << endl;//�߼������
	cout << (te && su) << endl;

	//ע�⣺����ϵ���ԡ��ϵ����ûЧ��������һ�±������Ϳ��ܻ����
	system("pause");
	return 0;
}