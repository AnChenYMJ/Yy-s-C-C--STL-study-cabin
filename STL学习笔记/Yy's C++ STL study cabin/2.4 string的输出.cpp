#include <iostream>
using namespace std;

void StrOut()
{
//��������
	string stc("Don't be afraid! GO the distance!");
	cout << stc << endl;			//string�������������

//c_str()������ԭ��					//�еı�����û��<<���أ�������c_strҪ��ͨ��һЩ
	cout << stc.c_str() << endl;	//c_str()�ǽ��ַ������Ƶ���һ���ռ��У�Ȼ�󷵻��¿ռ�ĵ�ַ�������Ⲣ����ԭ�����ַ����ռ�

//string������±�����				//ָ������ַ�����һ���ַ�
	cout << stc[12] << endl;		//�����ǲ������±�������ģ����������������±������[]
									//��Խ�����ʱ�����л�����������˼�д�ĺð���

//at()����	//at()��������һ�����ã�ָ����indexλ�õ��ַ�
	cout << stc.at(12) << endl;

	//cout << stc.at(36) << endl;		//��index������Χ����Խ�����ʱ�������쳣��ʾ"out of range"����
									//���׳�out_of_range�쳣
	try								//����Էŵ�try�д����쳣
	{
		cout << stc.at(36) << endl;
	}
	//catch (...)					//��֪���׳����쳣����ʱ����...������
	//{
	//	cout << "at��������Խ������ˣ�" << endl;
	//}
	catch(out_of_range& v)			//���ֲ�֪���쳣��������out_of_range//�ò������ö����ԣ�����ֱ��дout_of_range
	{
		cout << "at��������Խ������ˣ�" << endl;
	}
}

int main()
{
	StrOut();						//ָ����������ַ�ʽ��str[]�����±����㡢at()����ָ���ַ�������


	system("pause");
	return 0;
}