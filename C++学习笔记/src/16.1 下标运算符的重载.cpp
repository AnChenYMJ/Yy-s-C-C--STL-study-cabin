#include <iostream>
using namespace std;

class Ctea
{
private:
	int a;
	int b;
	int c;
	double d;
	float e;

	int Nerror;
public:
	Ctea():a(18),b(22)
	{
		c = 27;
		d = 165.335;
		e = 156.445f;
		Nerror = -1;//����= ����һ������ʽ������error
	}

	//��Ϊ[]�±�������ܶԿռ���ж���д�����������þ���ʵ��д�Ĳ�����
	int& operator[]( int n)//[]�����ֻ��д������
	{					//n��Ϊ�±�����ı�־
		switch(n)
		{
		case 0:
			return a;//��Ϊһִ��return����������������Ķ���ִ���ˣ����Բ���Ҫ��break�ˡ�
		case 1:
			return b;
		case 2:
			return c;
		//case 3:
			//return d;//��return��: �޷��ӡ�double��ת��Ϊ��int &��,����ֵ�����þͻ��������ľ�����
		}			//�޷������������͵ĳ�Ա���½ڿ���ָ���ܴ��ƾ�����
		return Nerror;//�������ֵ��Ϊ���޵ı�־
	}
};

//int& operator[](Ctea& a, int h)//error C2801: ��operator []�������ǷǾ�̬��Ա(���������ڳ�Ա)
//{
//
//}

int main()
{
	//[]���������ã�һ����ʾ����Ԫ�ظ����� �����ڲ�����[]��ʾָ�롣�����±��������
	int u[5] = { 6, 4, 3, 7, 8 };	//u����������׵�ַ
	u[1] = 6;//�±�����ı�����ָ��ƫ�ƣ�u[1] ���� *��u+1�������׵�ַ+1���Ҷ������


	Ctea su;
	cout << su[0] << endl;
	cout << su[2] << endl;//�Զ�����±������
	su[2] = 30;
	cout << su[2] << endl;


	system("pause");
	return 0;
}