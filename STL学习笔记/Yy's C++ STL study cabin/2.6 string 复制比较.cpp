#include <iostream>
using namespace std;

#pragma	warning(disable:4996)			//�������ζ�Ӧ��ŵľ���

//���ƱȽ�
void Compare()
{
	string str1("abcdef");
	string str2("abcdefg");

//��������������Ƚ�						//���ֻ�� 0 �� 1���� �� �٣�
{
	cout << "��������رȽϣ�" << endl;

	cout << (str1 == str2) << endl;		//���������Ƚ�

	cout << (str1 >= "abcdef") << endl;	//�������ַ����Ƚ�

	cout << (str1 <= "abcdef") << endl;	//��6�������

	cout << (str1 > "abcdef") << endl;

	cout << (str1 < "abcdef") << endl;

	cout << (str1 != "abcdef") << endl;
}

//��compare�����бȽ�						//�����򷵻�1 ��С���򷵻�-1 �������򷵻�0��
{
	cout << "compare�Ƚϣ�" << endl;

	cout << str1.compare(str2) << endl;//-1			//�����������бȽ�

	cout << str1.compare("abcdef") << endl;//0		//�������ַ������бȽ�

	cout << str2.compare(0, 7, str1) << endl;//1	//�������ĳһ���������бȽ�	//������0��6�������

	cout << str1.compare(1, 4, str2, 1, 4) << endl;//0 //�������һ��������һ�ν��бȽ�
						//ǰ�������Ǳ�����str1�ķ�Χ��index��length����������������Ƕ���str2�ķ�Χ��index��length��
}

//���ƶ������ݵ�������
{
	cout << "copy():" << endl;

	char chs[30] = { 0 };				//ʹ�ø���ʱ����Խ�磬�ͻ���warning��ʾ������ʾ��һ�����,�������ʾ����
										//��ȫ���������#pragma warning��disable��4996��;����������ʾ��4996����ʾ��ţ�
	str2.copy(chs, 5, 2);				//����5���ַ����ӵ�2���ַ���ʼ�����Ƶ�chs��
	
	cout << chs << endl;
}

}

int main()
{
	Compare();							//compare���Ƚ�

	//����ѧϰSTL��ʲô����string��vector�ȡ�
	//��·���ǣ����塢���ԡ�������޸ġ���������


	system("pause");
	return 0;
}