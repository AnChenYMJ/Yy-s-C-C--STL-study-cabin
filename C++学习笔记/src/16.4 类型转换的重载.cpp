#include <iostream>
using namespace std;

class Cstu		//��������غ���Ҫ
{
private:
	int ange;
	double high;
	float big;
public:
	Cstu() :ange(28), big(125.43f)
	{
		high = 164.111;
	}

	operator int() const//��Ϊ����ת����Ӧ�øı�������ݣ�����Ӧ�ü���const
	{
		return ange;	//����ת��������ʲô�ã�����Ŀλὲ��
	}

	//double operator double() const//��Ҫд����ֵ���ͣ����򱨴�
	operator double() const
	{
		return high;				//����Ҫ����ֵ
	}

	operator float() const		//����ת�������ر���д�����ڣ�û�в���
	{
		//return big;
		return ange;//�����float������ת�������з���int���ͣ�����ʾ�ڴ�ض�
	}
};

int main()
{							//ʹ������ת�����أ����Զ�����ת������ȥ��ͬ�����غ���
	Cstu su;					//�¶ϵ���Իᷢ�����˲�ͬ������
	cout << (int)su		<< endl;//C������ֻ��һ�ַ�ʽ������ת�����ǣ�int������
	cout << double(su)	<< endl;//��C++�����֣���һ����double��su�����֣���������ʹ��
	cout << (float)su	<< endl;//��Ϊ���ײ������壬��һ�ָ��淶�������׳���
								//�������ʹ������ת������
	cout << su.b << endl;		//�����÷����ֱ��
	system("pause");
	return 0;
}