#include <iostream>
using namespace std;
				
				//C�����к������ǲ�����һ����
void test(int a)//C++�У���������ͬ��������ͬ�ĺ����������غ�������Щ�����ǲ�ͬ��
{
	cout << a << endl;
}

//void test(int a, int b = 27)//error C2668: ��test��: �����غ����ĵ��ò���ȷ
void test(int a, int b)//���������Ĭ��ֵ���Ϳ��ܻᵼ���������������ò���ȷ
{							
	cout << a << ' ' << b << endl;
}

void test(char c)
{
	cout << c << endl;
}



void show(int a)//��������ʹ����������ˣ���������������show����������ʲô�������ݶ��ܴ�ӡ
{
	cout << a << endl;
}

void show(char a)
{
	cout << a << endl;
}

void show(float a)
{
	cout << a << endl;
}


int main()
{
	test(26);//���Կ�������ͬ���������������أ��ɹ�������
	test(26, 27);//���غ�������ݴ��ݵĲ������Զ�ȥ�Ҷ�Ӧ�ĺ���
	test('Y');


	show(27);//���Լ�������ͬһ�����ֵĺ��������벻ͬ�������ͣ����ܴ�ӡ����Ϊʹ���˺�������
	show('h');//����C�����У��ͱ���д������ͬ���Ƶĺ�����ʵ���ˣ�����˵����˺��������
	show(165.45f);

	return 0;
}