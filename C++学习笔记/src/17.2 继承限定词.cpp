#include <iostream>
using namespace std;

class Cpep
{
private:
	int a = 1;
	void kee1()
	{
		cout << "father:keep1" << endl;
	}
protected:
	int b = 2;
	void kee2()
	{
		cout << "father:keep2" << endl;
	}
public:
	int c = 3;
	void kee3()
	{
		cout << "father:keep3" << endl;
	}
};

class Cxiaoxi : private Cpep//�̳����η�
{
public:
	void kee4()			//private�ļ̳����η����������������ж���˽�е�private
	{
		
		kee3();			//�����ﾹȻͨ������������kee3������
	}
};

class Cxiaoliang : protected Cpep
{
public:
	void kee5()
	{
		kee3();
	}
};

class Cxiaojiao : public Cxiaoliang//����ɶ��̳�
{
public:
	void kee6()
	{
		kee5();
	}
};

//�̳����η�������
//private�������е����з������η���Ȩ�޶����private�������ɼ�
//protected�������е�piublic���protected����protected��private����private���൱�ڽ����������Ȩ��
//public�������еķ���Ȩ�ޱ�����ʲô�������հ������û�иı�

int main()
{
	Cxiaoxi xi;
	xi.kee4();

	Cxiaoliang liang;
	liang.kee5();

	Cxiaojiao zhi;//������̳�
	zhi.kee6();
	zhi.kee5();

	system("pause");
	return 0;
}