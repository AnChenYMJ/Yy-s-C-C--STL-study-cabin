#include <iostream>
#include <algorithm>		//algorithm: �㷨		for_each ��sort  ��ͷ�ļ�
#include <functional>		//function:	 ����		α����greater	 ��ͷ�ļ�
using namespace std;

int show(char ch)			//Ĭ�ϴ��ݽ����Ĳ���������char
{							//���޷���ֵ������
	cout << ch;
	return 1;
}

void testforeach()
{
	string str1("Don't be afraid. Keep going! Go the distance. Yy.");
	string str2("Don't waver.");			//waver: ��ҡ

//�㷨һ��for_each ����	ͷ�ļ���<algorithm>
{
	//����1����ʼ�±�		����2����β�±�	����3����������������������Զ���ģ�����forѭ�����ִ�����һ����
	for_each (str1.begin()+9, str1.end()-3, show);		//for_each�����������Լ�д�ı�����ӡforѭ��һ�� 
														//Ĭ�ϲ������ĺ���ԭ�͵Ĳ��������ǵ�ǰ������Ԫ������
}

cout << endl;			//����

//�㷨����sort ����		ͷ�ļ���<algorithm>
{
	//��������ͷ	�� β		��ʱĬ�ϴ�С��������
	sort(str1.begin(), str1.end());		//��������Ԫ�����ͣ���ͬ�����Ͷ������������ǰ��ַ�������
	cout << str1 << endl;

	//��������ͷ β α����	�ܴӴ�С����				//<>���ǲ������ͣ������һ�����doubleҲû�����Ȼ
	sort(str1.begin(), str1.end(), greater<char>());	//greater��ͷ�ļ���<functional>
	cout << str1 << endl;								//greater������
														//�º�������ͨ�������ò�����һ����STL�в��õõ�
}
}


int main()
{
	testforeach();



	system("pause");
	return 0;
}