#include <iostream>
using namespace std;

class Cstu		//ostream��һ�����������
{
private:		//ʵ������У����󲿷ֵ����ݳ�Ա��˽�еģ���ֹ���޸�,������Ԫ�����þ����ֳ�����
	int ange;
public:
	Cstu(int ang)
	{
		ange = ang;
	}
//��Ϊ�������������ҵ�һ��������ostream�����ã����Բ������ڶ��壬
	friend ostream& operator<<(ostream& a, Cstu& b);//��Ϊ���ں�����һ������Ĭ��Ϊthisָ��
};

		
//void operator<<(ostream& a, Cstu& b)//��������ֵ�ģ���ֻ�����һ��
//{
//	a << b.ange;
//}
			//����һ��ostream�����á������������������
ostream& operator << (ostream& a, Cstu& b)//ʵ������������ͻ������Ǳ����ģ�������Ҫ��Ԫ������
{
	a << b.ange;
	return a;
}

int main()
{
	Cstu te(18);
	cout << te ;	//<<��һ����������������Ҳ������
	//cout << te << endl;//��������ֵ���Զ�������ֻ�����һ��

	cout << " " << te << " " << te << endl;//������ַ������߿ո��������ʱ�����õ���ϵͳ

	system("pause");
	return 0;
}