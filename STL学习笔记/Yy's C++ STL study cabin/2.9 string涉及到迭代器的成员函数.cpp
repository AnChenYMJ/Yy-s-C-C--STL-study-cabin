#include <iostream>
using namespace std;

void testiterator()
{
//��������
string str1("Keep going Yy! you're strong! Go the distance!");
string str2("Don't be afraid.");

//begin()  ��  end()
{
	//begin()	����һ����������ָ���ַ�����Ԫ��
	str1.begin()[12] = 'Y';				//���������ʾ���ָ��

	cout << str1.begin()[3] << endl;
	cout << str1 << endl;

	//end()		����һ����������ָ�����һ��Ԫ�ص���һλ
	str1.end()[-1] = '~';				//�±��������ø���
	str1.end()[-34] = 'y';

	cout << str1 << endl;
}

//appendƴ��						//���õ�����������ƴ�ӵĴ�С
{
	//ƴ��str2����������
	str1.append(str2.begin(), str2.end());
	cout << str1 << endl;

	//ƴ��str2�Ĳ�������
	str1.append(str2.begin() + 6, str2.begin() + 16);		//�±�Ϊ6���ַ���ʼ���±�Ϊ16��ǰһ��
	cout << str1 << endl;
}

//eraseɾ��						//���õ�����������ɾ���ķ�Χ
{
	str1.erase(str1.end() - 10, str1.end());		//ɾ��ĩβ10���ַ�
	cout << str1 << endl;

	str1.erase(str1.begin() + 12);					//ɾ���±�Ϊ12���ַ�
	cout << str1 << endl;
}

//insert����						//���õ����������Ʋ����λ��
{
	str1.insert(str1.begin() + 12, 1, 'y');				//���±�Ϊ12���ַ�ǰ���� 1 �� y
	cout << str1 << endl;		

	cout << str1.length() << endl;

	str1.insert(str1.begin()+46, str2.begin()+1, str2.end()-1);
	cout << str1 << endl;								//�ڱ������±�Ϊ46���ַ�ǰ����str2���±�Ϊ��1~15�����ַ���
}

}

int main()
{
	testiterator();


	system("pause");
	return 0;
}