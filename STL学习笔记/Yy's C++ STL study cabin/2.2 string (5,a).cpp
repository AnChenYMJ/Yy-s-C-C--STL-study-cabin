#include <iostream>
using namespace std;


int main()
{
						//size_typeת������MSDN�ܿ�����size_t(unsignet int)���͵�������
					   //string(size_type length, char ch);
	string stc(6, 'a');//��һ���������ַ��ĸ������ڶ����������ַ���ע����ַ����ţ������ţ�
	cout << stc << endl;//��6��a�������ʼ��


	system("pause");
	return 0;
}