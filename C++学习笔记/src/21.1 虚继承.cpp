#include <iostream>
using namespace std;

class CA	//������̳еĸ�������������
{
public:
	int o;
	CA() : o(5)
	{}
};

class CB : virtual public CA	//CB��̳�CA
{
public:
};

class CC : virtual public CA	//CC��̳�CA
{
public:
};

class CD : public CB , public CC//CD�̳�CB��CC
{
public:
};


class B : public CA	//ʵ�̳�ʾ��
{
public:
};

class C : public CA
{
public:
};

class D : public B, public C
{
public:
};
int main()//��̳���Ϊ�˽����̳��з��ʲ���ȷ������
{			//һ�㲻�����ã��ṹ���ӣ��ڴ濪����
			//��̳��Ƕ��ؼ̳������еĸ�����������Ϊ�˽�����ؼ̳ж����ֵ�

			//���ؼ̳п��Ժܸ��ӣ�������ͼһ���������ľ�����

	CD d;	//CB CC ��̳�CA
	cout << d.o << endl;//��Ϊ��̳о��൱����һ��ʹ��Ȩ�ޣ������Ǹ��������������Ļ���ֻ��CA����һ��o
	//��̳оͲ����������������oҲ������CD����������CB CC ֻ����CA


	D n;	//B C ʵ�̳�CA
	cout << n.o << endl;//error C2385: �ԡ�o���ķ��ʲ���ȷ
	//��ΪB C ʵ�̳�CA �� ������B C �����Լ���o��n����oʱ�Ͳ�֪�����ĸ���
	//B C ���ǰѸ��ิ���������Լ�����

	system("pause");
	return 0;
}