#include <iostream>
using namespace std;

class Cstu
{
public:
	int a;
	int& b;
	const int f;
	/*Cstu() :a(15), b(a), f(56)//�ɹ���ֵ
	{
		cout << a << " " << b << " " << f << endl;
	}*/

	/*Cstu(int g) :a(g), b(g), f(56)//show��Ĵ�ӡb����ԭ����int g �Ǿֲ�����������������ᱻ����
	{								//���������ֵ������������ɲ�֪�����ĸ�
		cout << a << " " << b << " " << f << endl;
	}*/

	Cstu(int &g) :a(g), b(g), f(g)//�ɹ���ֵ��ӡ����Ϊ���û�һֱ���ڣ�ֱ������û����
	{
		cout << a << " " << b << " " << f << endl;
	}
	void show()
	{
		cout << a << " " << b << " " << f << endl;
	}


};

int main()
{
	int o = 99;
	Cstu su(o);
	su.show();

	system("pause");
	return 0;
}