#include <iostream>
using namespace std;

class CTea
{
public:
	CTea()
	{
		a = 15;
	}
	/*~CTea() const //���������͹��캯��������const����
	{

	}*/
	int a;

	//�������ܶԺ������ܽ��и���ȷ�ķ��࣬�����ӡ�ĺ������ܼ���const��������ҪҲ�����޸����ݳ�Ա
	void show(int b) const//��������ָ���� const CTea*
	{		//����ӵ�в���
		//a = 48;//error����������ͨ������������ʡ�a��������޷���������޸�
		//int c = 66;//�����������ı��������޸ĵġ�
		b = a + b;//const���εĺ����������޸Ķ�������ݳ�Ա���������������ı��������޸ĵġ�
		cout << a << " " << b <<  " " << "keep going Yy!" << endl;
	}

	void fun()//const���εĳ������ܵ�����ͨ����
	{
		cout << "keep going! Yy ~ Don't stop!" << endl;
	}
};

int main()
{
	CTea su;
	su.show(15);
	
	const CTea te;//������ֻ�ܵ��� �����������ܵ�����ͨ����
	te.show(11);
	//te.fun();//���ܽ���this��ָ��ӡ�const CTea��ת��Ϊ��CTea &��


	system("pause");
	return 0;
}