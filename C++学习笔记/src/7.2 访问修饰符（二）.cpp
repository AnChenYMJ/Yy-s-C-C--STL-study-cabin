#include <iostream>
using namespace std;

class OPJ
{
protected:
	int a;
	void fun()
	{
		cout << "fun" << " " << a << endl;
	}

public:		//������  ����ʹ��
private:	//˽�е�  ֻ������ʹ��
protected:	//�ܱ�����  ���� �� ���� ��ʹ��  //��������ѧ��
};

void yu()
{
	OPJ FT1;
	//FT1.fun();	//�ɼ������ַ�ʽ�����ܷ���
}

class TU
{
public:
	OPJ FT;
	void fun1()
	{
		//FT.fun();	//�ɼ������ַ�ʽ�����ܷ���
	}
};

class XYT : public OPJ		//����OPJ������
{
	void fun2()
	{
		fun();		//�ܹ�ʹ�ö�������֤��protected���η����������ʹ��
	}
};

int main()
{
	OPJ FT2;
	//FT2.fun();		//�ɼ������ַ�ʽ�����ܷ���

	system("pause");
	return 0;
}