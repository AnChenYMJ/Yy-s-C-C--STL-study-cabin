#include <iostream>
using namespace std;

int main()		//ע�⣺�½�������ʱ�������������뺯����Ҫע�͵�������ᱨ��
					����ʱ���ܲ����Ǹ��ļ��Ĵ��󣬶��Ǳ���ļ�������˫����������������λ��
{
	char a;
	int b ;
	double c;

	//cout��cin�Ƕ��󣬲��ǹؼ��֣�Ҳ���Ǻ���
	cout << "�����룺������д�����䡢���" << endl;
	cin >> a >> b >> c;		//�����������룬��scanf�����ܣ����Զ�ʶ���������ͣ�scanfҪ�ֶ���������%f��
	cout << a << ' ' << b << ' ' << c << endl;

	system("pause");
	return 0;
}