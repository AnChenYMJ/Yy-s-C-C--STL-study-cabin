#include <iostream>
using namespace std;

class Cst
{
private:
	int a,
		b,
		c;
	double d;
	float e;
	int Nerror;
public:
	Cst() :a(1), b(2)
	{
		c = 56;
		d = 165.556;
		e = 156.887f;
		Nerror = -1;
	}

	//void*��ͨ������ָ�룬����װ�κ����͵ĵ�ַ
	void* operator [] (int n)//���������ø������±�������ı��ʣ�ָ�뻹��Ҫǿת���ͣ��Ӷ���
	{							//������ʦ���Ƽ�д
		switch (n)
		{
		case 0:
			return &a;	//���ص�ַ
		case 1:
			return &b;
		case 2:
			return &c;//���ڵĳ�Ա���� ��void*����ָ�� ��ǿת�������
		case 3:			//ǰ��һ��Ҫ��Ӧ�ϣ�������ֵ�ͱ仯��
			return &d;
		case 4:
			return &e;
		}
		return &Nerror;//������ʾ
	}

};

int main()
{
	Cst su;
	cout << su[1] << endl;//�����Ļ������ص���һ����ַ
	cout << su[3] << endl;

	//cout << *su[1] << endl;// error C2100: �Ƿ��ļ��Ѱַ//�޷�ֱ���õ�ַ������������
	//ϵͳ��֪�������ַ�����������Ƕ��٣�������void* ��ͨ������ָ�룬

	//int l = sizeof(void);//�޷����void�Ĵ�С��֤��voidû��ȷ���Ĵ�С��
	int l = sizeof(void*);//void*��4�ֽڴ�С
	cout << l << endl;

	cout << *(int*)su[1]	<< endl;//�����ᵽָ��������void*����֪�����������޷��Կռ����
	cout << *(double*)su[3] << endl;//����ͨ��ǿתָ�����;Ϳ�����

	*(int*)su[1] = 88;				//�ܽ��ж�д����
	cout << *(int*)su[1]	<< endl;	//���Ǳ������õķ���ֵ������Ҫд�Ķ����Ͷ���

	cout << *(double*)su[1] << endl;//ע�⣺�ڶ����ڵ�����Ҫ���������ǿת������Ͷ�Ӧ��
					//����ͳ����ˣ���������������ֵ�ͱ�ò���ʶ��

	return 0;
}