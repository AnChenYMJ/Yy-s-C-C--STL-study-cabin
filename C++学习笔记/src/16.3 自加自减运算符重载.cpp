#include <iostream>
using namespace std;

class Ctea
{
private:
public:
	int ange;
	int high;
public:
	Ctea():ange(15)
	{
		high = 164.55;
	}

	int operator--()		//���ڵ�ǰ��--
	{
		this->ange -= 1;
		return ange;
	}

	int operator--(int n)		//���ڵĺ�����--����ȡֵ
	{		//n��һ����־����ǰ�����ֿ���������ȫ������
		int a = ange;
		this->ange -= 1;
		return a;
	}

	friend int operator++(Ctea& a);
};

int operator++(Ctea& a)//ǰ��++��ֱ���Լ�
{
	a.ange += 1;
	return a.ange;
}
					//n�Ǳ�־��ǰ�õ���������ûʲôʵ�����ã���Ҳ����Ϊ�˱����˷ѣ�����װ�Լ�ǰ��ֵ
int operator++(Ctea& a, int n)//����++����ȡֵ���Լ�
{
	n = a.ange;		//��һ������װ�Լ�ǰ��ֵ
	a.ange += 1;	//�Լ�
	return n;		//���Լ�ǰ��ֵ����
}					//��Ҳ��ʵ�ʱ����ĺ����Լӹ��̣���һ���ռ�װ�Լ�ǰ��ֵ�����أ���ԭ�ռ����Լ�

int main()
{
	int a = 11;
	a++;//��ȡֵ���Լ�
	++a;//���ԼӺ�ȡֵ

	Ctea su;
	cout << su.ange << endl;		//15
	cout << ++su << endl;//ǰ��++	//16
	cout << su++ << endl;			//16
	cout << su++ << endl;			//17
	cout << su.ange << endl;		//18

	return 0;
}