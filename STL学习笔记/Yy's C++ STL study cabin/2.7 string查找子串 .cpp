#include <iostream>
using namespace std;


//�����Ӵ� ������
void FindSwap()				//find:����   swap������
{
	string str1("Keep going! Don't be afraid. Yy~ Go the distance!");
	string str2("Yy~");

//�������ַ���				//find()
{
	//ȫ�ַ����ڲ���
		cout << "ȫ�ַ�����" << endl;

	cout << str1.find(str2) << endl;		//�ڱ������в��Ҷ�������ҵ����򷵻ض�Ӧ����ʼ�±�

	cout << str2.find(str1) << endl;		//���û���ҵ����򷵻�4294967295����Ϊ����ֵ���޷���ing
	cout << (int)str2.find(str1) << endl;	//ǿת����ֵΪint�����ܿ�����-1��˵���Ҳ����򷵻�-1

	cout << str1.find("Keep") << endl;		//�ڱ������в����ַ�����

	cout << str1.find('o') << endl;			//�ڱ������в����ַ������ص�һ�������ַ����±�


	//ָ��λ�ò���
		cout << "ָ��λ�ò��ң�" << endl;

	cout << str1.find(str2, 12) << endl;		//�ڱ������12�ַ��Ժ���Ҷ���
		
	cout << str2.find(str1, 3) << endl;			//�ڱ������3�ַ��Ժ���Ҷ���
	cout << (int)str2.find(str1, 3) << endl;	//�õ�4294967295��ԭ���Ǹ����Ĵ洢��ʽ���ȡ��ʽ��ԭ��

	cout << str1.find("Keep", 2) << endl;		//�ڱ������2�ַ��Ժ��в����ַ�����

	cout << str1.find('o', 7) << endl;			//�ڱ������7�ַ��Ժ��в����ַ�
}

//�������ַ���				//substr()		substr:���ַ���
{
	cout << str1.substr(1, 20) << endl;//�±�Ϊ1���ַ���ʼ������20���ַ���
}

//��������������				//swap()
{
	cout << "����ǰ��" << endl;
	cout << "str1:" << str1 << endl;
	cout << "str2:" << str2 << endl;

	str1.swap(str2);

	cout << "������" << endl;
	cout << "str1:" << str1 << endl;
	cout << "str2:" << str2 << endl;
}
	
//���������  +��				//��ǰ�Ŀγ����н�����������
{
	cout << "��Ӻ�" << (str1 + ' ' + str2) << endl;			//���� + �ַ� +����
							//����ƴ������	//��û�иı��ĸ���ֵ����Ϊû�и�ֵ���ų���
	cout << "��Ӻ�" << (str1 + " you're strong!") << endl;	//���� + �ַ���
}

}

int main()
{
	FindSwap();


	system ("pause");
	return 0;
}