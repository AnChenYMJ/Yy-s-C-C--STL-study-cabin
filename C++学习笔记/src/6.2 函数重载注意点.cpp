#include <iostream>
using namespace std;

void test(char c);//���������������Ӻ����������� ////�˺��������򣬴Ӵ�����

void test(int a)
{
	cout << a << endl;
}						//�˺��������򣬴Ӵ�����

//int test(int a)//error C2371: ��test��: �ض��壻��ͬ�Ļ�����
//{				//����֤������ֵ����Ϊ���غ���������
//	cout << a << endl;
//	return 0;
//}

//void test(int a, int b = 27)//error C2668: ��test��: �����غ����ĵ��ò���ȷ
void test(int a, int b)//���������Ĭ��ֵ���Ϳ��ܻᵼ���������������ò���ȷ
{
	cout << a << ' ' << b << endl;
}						//�˺��������򣬴Ӵ�����

void test(float a)
{
	cout << a << endl;
}


						//�����������ߺ����Ĺ���������
int main()				//���Ϻ����Ĺ���������������������
{
	test(165.34f);//ע��float��long���������ͣ�һ��Ҫ�Ӻ�׺������������

	return 0;
}

void test(char c)
{
	cout << c << endl;
}				