#include <iostream>
using namespace std;

class Coji		//�������η��ķ�Χ�ǳ��ֹؼ��ֿ�ʼ������������һ�����η�
{
public:			//public��������  ʹ�����εĳ�Ա��������ɼ�������֮���ܵ��������εĳ�Ա
	int a;
	void fun1()
	{
		cout << "fun1" << " " << a << endl;
	}
private:		//private��˽�е�  ʹ�����εĳ�Ա�����ⲻ�ɼ����������޷����������εĳ�Ա
	void fun2()
	{			//private �а�ȫ�Ե����ã���ֹ���ⱻ�޸ĵ�����
		fun1();
	}

public:			//���飺�������η��ɵ����Լ����ʱ����ı�־��
	int b;
	int c;

public:			//�������η�д���ٶ��У�û������
	double e;
	double d;
};

void gi()
{
	Coji op1;	//�������Ա��ʽһ����������
	op1.fun1();
}

class CUI		//���в����������Ļ���Ĭ��Ϊprivate//�ṹ��Ĭ��Ϊpublic
{
public:
	Coji bu;
	void fun3()	//��һ�����е��ó�Ա������Ҫ�ں����е��ã�
	{			//��Ϊִ��������޷���Ϊ��Ա�ģ�ֻ�������ݻ������͡�

		bu.fun1();	//�������Ա��ʽ������һ�������
	}
};

struct Stu	//C++�нṹ�������һ���ض����
{			//�ṹ�岻�����η���Ĭ��Ϊpublic
public:
	int a = 27;	//�ṹ���ܼ����η���C++��׼���е�
private:		//C���Եı�׼���ǲ��ܹ����������η���
	int b = 26;
};

int main()
{
	Coji lkj;
	lkj.a = 26;	//�������Ա��ʽ��������������
	lkj.fun1();

	gi();

	CUI hg;
	hg.fun3();

	//lkj.fun2();//��Coji::fun2��: �޷����� private ��Ա(�ڡ�Coji����������)

	system("pause");
	return 0;
}