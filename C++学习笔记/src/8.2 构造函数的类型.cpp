#include <iostream>
#include "8.2.h"
using namespace std;

class Cabin
{
public:
	int a;
	float f;

	//Cabin()	//C++Ĭ�ϵĹ��캯������������ʲô��û�У��������Զ����˹��캯�����ͻ�����Ĭ�ϵĸ��ǵ�
	//{
	//}

	Cabin()//���ò���������Ա��ֵ
	{					//���캯���ܹ���������
		a = 156;
		f = 257.89f;
	}

	Cabin(int b, float t = 56.35f)//������������һ����Ĭ��ֵ��ע��˳���Ǵ�������������ֵ
	{
		a = b;
		f = t;
	}
};


//���ⶨ�幹�캯��ǰ�������������
Ctea::Ctea()	//�������������8.2.h��ͷ�ļ���
{
	a = 156;
	f = 257.89f;
}
				//����ԭ������Ĭ��ֵ����Ͳ�Ҫ��д�ˣ�����ᱨ��
Ctea::Ctea(int b, float t)
{
	a = b;
	f = t;
}
	//���⺯���������������ں�����ǰ
int Ctea::fun()
{
	cout << f << endl;
	return 0;		//C++�б���Ҫ�ӷ���ֵ������ᱨ��
}

int main()
{
	Cabin st(25, 17.25f);
	cout << st.a << " " << st.f << endl;

	Ctea te(85, 78.00f);
	te.fun();
	cout << te.a << " " << te.f << endl;

	system("pause");
	return 0;
}