#include<iostream>
using namespace std;

class Coldman
{
public:
	~Coldman()
	{
		cout << "so old" << endl;
	}
};

class Cman:public Coldman
{
public:
	~Cman()
	{
		cout << "so strong" << endl;
	}
};

class Cfather
{
public:
	virtual ~Cfather()
	{
		cout << "father" << endl;
	}
};

class Cchild :public Cfather
{
public:
	virtual ~Cchild()
	{
		cout << "child" << endl;
	}
};

class Cwoman
{
public:
	~Cwoman()
	{
		cout << "pretty girl" << endl;
	}
};

int main()
{
	Coldman* ol = new Cman;

	//delete ol;//����ֻ�����˸����������������ʱ������Ŀռ䲢û�б��ͷŵ�
	delete (Cman*)ol;//û������������	//�������ַ�ʽ���������������������������ˣ��������ռ䶼�ͷŵ���

	Cfather* fa = new Cchild;

	//delete fa;//������������ //���ָ������������������������ˣ���ʱ���������Ŀռ䶼�ͷŵ���

	delete (Cwoman*)fa;//������������	//����ֻ������ָ����ָ��Ĳ���ɵ�Cwoman����������
			//����ʱ���������Ŀռ䶼�ͷŵ��ˣ���Ϊ��������ԭ��
			//delete�����Ծ��ǣ�д˭��ָ�룬���͵���˭����������
			//��������һ�����⣺�������������е��������������ͷ�����ռ�ĳ�Ա�����
			//�������޷����ø���������������������Щ��Ա�ռ���޷��ͷ�
	//����Ҫע���Ա�ռ��޷��ͷŵ����⣬ֻҪ����������������ռ�Ͷ����ͷţ�����Ա�ռ�Ͳ�һ���ˣ���delete���ָ����˭


	system("pause");
	return 0;
}