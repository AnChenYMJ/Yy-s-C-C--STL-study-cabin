#include <iostream>
using namespace std;

int main()
{
	cout << "Don't waver,you are strong!" << ' ' << 25;//cout�����������
	cout << 'y' << 56.54 << endl;	//cout�Ա�C���Ե�printf�����Զ�ʶ�������ٴ�ӡ
	//cout���ǹؼ����Ǹ����󣨺����ὲ�⣩//����printfҪ��%d �����ֶ�ȷ���������
									//��C++��cout��ֱ�������
	int a = 26;
	char c = 'Y';
	float f = 256.23F;//����ʼ����: �ӡ�double������float���ض�
					//��Ϊ������Ĭ��Ϊdouble��Ҫ��������float�������F�ĺ�׺

	cout << a		//cout�ܹ�����д����
		<< ' '
		<< c
		<< ' '
		<< f
		<< endl;

	system("pause");
	return 0;
}