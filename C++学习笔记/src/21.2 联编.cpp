#include <iostream>
using namespace std;

class Coldman
{
public:
	void fun()
	{
		cout << "keep going Yy" << endl;
	}

	void show()
	{
		cout << "so old" << endl;
	}
};

class Cman : public Coldman
{
public:
	void show()
	{
		cout << "so strong" << endl;
	}
};

class Cwoman : public Coldman
{
public:
	void show()
	{
		cout << "so pretty" << endl;
	}
};

int main()//��̬���������C++��̬�ģ�C������ȫ���Ǿ�̬����
{
	//���ǽ�ģ����ߺ����ϲ���һ�����ɿ�ִ�д���Ĵ�����̣��������ã���
	//�������������еĽ׶β�ͬ���ɷ�Ϊ���ֲ�ͬ�����෽������̬����Ͷ�̬���ࡣ

	//��̬���ָࣺ�ڱ���׶ξͽ�����ʵ�ֺͺ������ù���
	Coldman om;
	om.fun();		//������һ�������Coldman�е�fun����//���ھ�̬����

	Coldman* ol = new Cman;
	ol->show();		//������һ�����õ��������show������������д��//���ھ�̬����


	//��̬���ָࣺ�ڳ���ִ�е�ʱ��Ž�����ʵ�ֺͺ������ù���
	Coldman* old;
	int n;
	cin >> n;

	switch (n)
	{
	case 1: old = new Cman; break;
	case 2: old = new Cwoman; break;
	}

	old->show();	//�����Ļ�����ֻ�������ڱ����ʱ����ܽ������������������֪�����õ����ĸ�����
					//����Ƕ�̬����//���ϵ�����


	system("pause");
	return 0;
}