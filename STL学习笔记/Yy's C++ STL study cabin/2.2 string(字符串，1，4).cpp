#include <iostream>
using namespace std;


int main()
{
	string stc("abcdefghij", 5);		//���ַ�����ǰ5���ַ�������ֵ
	cout << stc.c_str() << endl;

	string stc1(stc, 1, 3);				//��������ַ������м���ַ����������ʼ��
	cout << stc1.c_str() << endl;		//ԭ��ֻ��ӡbc�ģ���Ƶ�������ҵı�������ӡ��bcd��Ӧ���Ǵӵ�1����ʼ����3��

	system("pause");
	return 0;
}