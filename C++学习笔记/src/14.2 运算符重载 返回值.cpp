#include <iostream>
using namespace std;

class Ctea
{
public:
	int ange;
	int bear;
	Ctea() :ange(15)
	{
		bear = 13;
	}
};

//��������صķ���ֵ�����壺Ϊ�˽����������㣬�÷���ֵ��������ֵ�������ݽ�������
int operator+(Ctea& a, int b)
{
	return (a.ange + b);
}

int operator+(int b, Ctea& a)//����ʹ�����ñ��⿽�����죬����Ч��
{
	return (a.ange + b);
}

Ctea& operator+(Ctea& a, Ctea& b)//�������
{
	a.ange += b.ange;
	return a;    //ͨ���ӵ�����ֱ�ӷ��ض���a��������������a�ڵ�ֵ�ͱ��޸���
}

int operator*(Ctea& b, int a)
{
	return (b.ange * a);
}

int operator/(Ctea& b, int a)
{
	return (b.ange / a);
}

// warning C4552: ��-��: δʹ�ñ��ʽ���
void operator-(Ctea& a, int b)//û�з���ֵ���޷���������ֵ�����������ټ���
{
	a.ange - b;
}

int main()
{
	Ctea su1,
		su2;

	//su1 + 12 �Ľ��Ϊһ��int��������27������13���㣺27+15��//�õ�����������40����su2���㣺40+su2
	cout << (su1 + 12 + 13 + su2) << endl;//�����õ����������������

	//cout << (su1 - 5 - 3) << endl;// warning C4552: ��-��: δʹ�ñ��ʽ���//�����÷���ֵ���������������

	cout << (su2 + 11 + (su1 + su2)) << endl;//����С���Ÿı�����˳����������Ҫ����Ӷ���������������

	//��Ϊ����(su1 + su2)�޸���su1�ڵ�ֵ����ʱsu1.ange�����30��
	cout << (su2 * 1 + su1 / 2) << endl;//�õ�������������أ�����Ӷ��󣬶�������ͣ����������

	return 0;
}