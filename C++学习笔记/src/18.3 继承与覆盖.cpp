#include <iostream>
using namespace std;

class COldman
{
public:
	const static int b = 1;
	int a;
	COldman() :a(56)
	{
	}
};

class Cman : public COldman	//û�Ӽ̳��޶��ʣ�����Ĭ�ϵ���private,
{								//�ҵı�������֪����ô����private�̳�û�б�����������
public:
	const static int k = 3;
	int a;
	Cman()
	{
		a = 89;
		//cout << (COldman::a = 98) << endl;//��֪����ô����private�̳�û�д������ڱ�����������
	}
	void fun()
	{
		cout << (COldman::a = 98) << endl;
	}
	void fun1()
	{
		cout << "i am man" << endl;
	}
	void fun1(int a)
	{
		cout << "i am man" << endl;
	}

	friend void show2();
};

class Cchild:public Cman
{
private:
	int c;
public:
	int a;
	Cchild() :a(11)
	{
		c = 55;
	}
	void show1()
	{
		cout << a << endl;
	}
	void fun1()
	{
		cout << "i am child" << endl;
	}
};

//void show2()
//{
//	Cchild ma;				//�����error֤���˸������Ԫ���ܼ̳и�����
//	cout << ma.c << endl;	// ��Cchild::c��: �޷����� private ��Ա(�ڡ�Cchild����������)
//	cout << "i am ��Ԫ" << endl;
//}

int main()
{
	Cman man;
	cout << man.COldman::a << endl;//����private�̳��޶����������ˣ��޷����������public�̳��޶���
									//�Ϳ�������ˣ�֤��������private�̳��޶���������
	man.fun();	//�������������ú������ø���ĳ�Ա��private�̳��޶���û��������

	Cchild su;//����Ķ���
	su.show1();//11 �����aû�е��ã��������ȵ����������е�a�������е�a�Ѹ����е�a������
	cout << su.Cman::a << endl;//Ҫ��ʹ�ø�a����Ҫ���������������

	su.fun1();//���ں�������һ��������Ҳ��Ĭ������������ຯ�������Ǻ�������,���Ǹ��ǹ�ϵ
	//su.fun1(15);//error C2660: ��Cchild::fun1��: ���������� 1 ������//֤���˸�����ĺ���ͬ������������
	su.Cman::fun1(15);		//Ҫ����ø���ͬ������������ʹ������������

	//show2();

	cout << su.b << endl;//��̬��Ա�ǹ��õģ���Ҷ����ã���ֻ��һ�ݣ���ֻ��һ���ռ䣬��ҹ��ã�
	cout << man.b << endl;//��̬��Ա�ǹ��õģ���Ҷ����ã���ֻ��һ�ݣ���ֻ��һ���ռ䣬��ҹ��ã�


	delete su;
	delete man;//ע���ͷſռ䣬������

	system("pause");
	return 0;
}