#include <iostream>
using namespace std;

class CStu
{
private:
	int a = 26;
	void fun()
	{
		cout << "fun" << " " << a << endl;
	}
private:	//�������private�ķ�ʽ����Ԫ
	friend void fun1();	//�������Ԫ��������ʽ
public:					//���ж����Ԫ
	friend class CTeach;//��Ԫ�������ǽ������ĺ������������ڣ���������ʱ�������η�����ͨ������Ϊ������
protected:	//�������protected�ķ�ʽ���̳С���Ԫ
	friend int main();	//������Ҳ�ܱ���Ԫ����

public:
	int fun3()	//�ӿں����������������÷���ֵ���ݱ�private���εı���ֵ��
	{			//ԭ��������ӿں��������ڣ����ñ���û�谭��
		return a;
	}
};
						//һ�㲻ʹ����Ԫ����Ϊ��Ԫ���ƻ���ķ�װ��
void fun1()
{
	CStu stu;
	stu.fun();
}

class CTeach
{
public:
	CStu Tea;
	void fun2()
	{
		Tea.fun();
	}
};

int main()
{
	CStu zaza;
	zaza.fun();

	fun1();

	CTeach su;
	su.fun2();

	int c = zaza.fun3();//���ýӿں����ѱ�private���εı������ݳ���
	cout << a << endl;

	system("pause");
	return 0;
}