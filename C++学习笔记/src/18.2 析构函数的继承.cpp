#include <iostream>
using namespace std;

class CGrandFather
{
public:
	CGrandFather()
	{
		cout << "CGrandFather ���캯�� \n";
	}
	~CGrandFather()
	{
		cout << "CGrandFather �������� \n";
	}
};

class Cfather:public CGrandFather
{
public:
	Cfather()
	{
		cout << "Cfather ���캯�� \n";
	}
	~Cfather()
	{
		cout << "Cfather �������� \n";
	}
};

class Cson:public Cfather
{
public:
	Cson()
	{
		cout << "Cson ���캯�� \n";
	}
	~Cson()
	{
		cout << "Cson �������� \n";
	}
};

int main()
{
	{				//���캯�����ӱ��ָߵ����ֵ�ִ�У�������ൽ�����࣬Ҳ������ռ乹���ɹ���˳��
		Cson xi;	//�ֲ����󣬿����캯��������������ִ��˳��
	}				//�����������ӱ��ֵ͵����ָ�ִ�У��������ൽ����࣬Ҳ�ǿռ��ͷŵ�˳��
		
	system("pause");
	return 0;
}