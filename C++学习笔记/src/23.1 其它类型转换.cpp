#include<iostream>
using namespace std;

class Cfather
{
public:
	double a;
	virtual void fun()
	{
	
	}
};

class Cson:public Cfather
{
public:
	char b;
	virtual void fun() 
	{
	
	}
};

class Cother
{
public:
	int c;
};

int main()//static��const���᳣ܻ�õ���ʣ�����֣��ͺ�������
{
	//1.�������ϣ����飬
	//2.��ʽת���������ڱ������Ա��������ת�����ƣ���ʽ����ȫ����ʾ����С�ľͳ���
	//3.�ܲ��þͲ���ת��������ֱ�۲�������
	//4.����˵����������C����ȥ��



	///*const Cfather* p = new Cfather;
	//volatile Cson* p2 = new Cson;*/

	////const_cast		//ʹ�����ε�ָ��ȥ��const��volatile
	////Cfather* p1 = const_cast<Cfather*>(p);//const_cast��������ȥ����const�����������ε�ָ��
	////Cson* p3 = const_cast<Cson*>(p2);	//���߱�volatile���ε�ָ��
	////ת��ָ��ʱ��Ҫ����ַ��������
	//	
	////�Ƿ����ʽ��pȥ��const������Ҫ��ת����������ͬ����Cfatherת�����Cfather
	////Cson* p4 = const_cast<Cson*>(p);//error: ��ָ������ָ�뵽ָ���������ָ���ǿ��ת��Ҫ����ʽ����ǿ��ת��(const_cast ����)

	////Cson* p5 = (Cson*)p;//ǿת��û�й����ˣ�ֱ��ת��



	////dynamic_cast	//�������໥ת����������������Լ�ת�Լ�
	//Cfather* p = new Cfather;
	//Cson* c1 = new Cson;
	//Cother* o = new Cother;

	//Cfather* p6 = dynamic_cast<Cfather*>(p);//һ���Լ�������ת���Լ�������

	////Cson* c2 = dynamic_cast<Cson*>(p);//��һ��ʱerror: ��dynamic_cast��:��Cfather�����Ƕ�̬����
	//									//��Ϊ���Ҫ����type��expression��Ϊ���л�����߹���������
	//									//����˵����������Ҫ��virtual���麯����
	//Cson* c2 = dynamic_cast<Cson*>(p);	//�������л���ת������

	////Cfather* p7 = dynamic_cast<Cfather*>(c1);//��������������ת����
	////ʹ�ö�̬���̳У����麯������ԭ���ǣ�����С�ռ�ת�ɴ�ռ䣬���ߴ�ռ�ת��С�ռ�

	//Cother* o1 = dynamic_cast<Cother*>(c1);//������û�б��������������ǲ����еģ�����Ҳ��Ҫ��



	//reinterpret_cast		//Σ������ת��
	Cfather* p = new Cfather;
	Cson* c1 = new Cson;
	Cother* o = new Cother;

	Cother* o3 = reinterpret_cast<Cother*>(p);	//���ڽṹ���ӵ���Σ�յ�����ת�������
	Cother* o4 = reinterpret_cast<Cother*>(c1);	//���ܻ���������ת�������

	struct dat		//���ϵ�����
	{
		short a;
		short b;
	};

	long value = 0xa224B118;
	
	dat* op = reinterpret_cast<dat*>(&value);//��long��4�ֽڿռ��ֳ�����short�Ŀռ�

	//ע�⣬���ת����ת�����ڴ�һ��Ҫ�������򱨴�
	//����ָ�������ָ�벻���໥ת��
	//����ת��������ֲ����Ϊ��ͬϵͳ�Ķ����ݴ洢˳����ܲ�ͬ



	system("pause");
	return 0;
}