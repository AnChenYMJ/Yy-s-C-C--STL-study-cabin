#include <iostream>
using namespace std;

class Cst
{
private:
	int ange;
	double high;
public:
	Cst():ange(16)
	{
		high = 165.22;
	}

	void show()
	{
		cout << ange << endl << high << endl;
	}
			//һ�����ݳ�Ա���ܱ����ģ���������Ԫ
	friend istream& operator >> (istream& ist, Cst& sa);
};

istream& operator >> (istream& ist, Cst& sa)
{		//��������Ҫ�ͱ��������Ͷ�Ӧ��
	ist >> sa.ange >> sa.high; //���������룬����ʱ�ÿո��س��������C++�Զ��ģ���ע������˳��

				//����ĸ�ʽ�������ʽ��ƥ��ʱ���������һ���ᱻ�޸ĳ�0
				//����double���������ַ���qew���ͻ���0

	if (ist.fail())//�������������ĸ�ʽ�����ԭ����ʽ��ƥ��ʱ������1��������ȷʱ����0��
	{				//�������������ֻҪ��������1������ȫ���ָ�Ĭ��ֵ��������Ҫ�ı�����ֵ��//���ϵĽ���
		cout << "�������fail�� �ѻָ���ʼֵ��" << endl;

		sa.ange = 0;		//��Ϊ���ֻ���������һ����ֻ��Ѵ����һ�����0����ʣ��������ȷ��û�޸ģ�
							//��ʵ��Ӧ���п��ܵ������д���
		sa.high = 0.00;		//��������fail������������ֵ���ָ�Ĭ�ϣ������������ж��Ƿ���������Ұ�ȫ
	}

	return ist;
}


int main()
{
	Cst su;
	cin >> su;
	su.show();

	return 0;
}