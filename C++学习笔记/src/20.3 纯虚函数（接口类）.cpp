#include <iostream>
using namespace std;

class Coldman
{					//��һ�������У������캯�������к������Ǵ��麯�����ͽнӿ��ࣨ�ӿ������ش����壩
public:				//��һ����Ϸ�нӿ����ܷ���ܶ��£���������һ�£�
	Coldman(){}		//����Ҳ�ǽӿ��࣬���캯���޷�����Ϊ�����࣬�ͺ���
	virtual void fun() = 0;//��������һ�����麯����û��ʵ�壬û�к������壬ֻ�Ǹ�����
	virtual ~Coldman() = 0;//���������ܸĳɴ��麯��
};

class Cman:public Coldman//���࣬��д�˴��麯��
{
public:
	void fun()
	{

	}
};

class Cwoman :public Coldman//���࣬û����д���麯��
{
public:
	void fun1()
	{

	}
};

class Cchild :public Cwoman//�����࣬��д�˴��麯��
{
public:
	void fun()
	{

	}
};

int main()
{
	//Coldman ol;//��Coldman��: �޷�ʵ����������//ֻҪ�д��麯�����޷���������

	Cman ma;//�����г�����������д�Ѵ��麯�����ǵ�������Ҳ�޷��������࣬��Ϊ����Ҳ�Ѵ��麯���̳���
	//Cwoman wo;//�������û����д���ǣ�Ҳ�޷�����
	Cchild ch;//������ӱ���������Ϊ��д���ǣ�Ҳ�ܴ���


	system("pause");
	return 0;
}