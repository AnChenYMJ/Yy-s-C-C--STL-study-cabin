#include "2.2 Mystream.h"

int main()
{
	Mystring str;					//2.1
	const char* stb = str.c_str();	//�ϵ���ԣ�ʵ���˺�ԭ��׼����ͬ�Ĺ���
	cout << stb << endl;			//new�Ŀռ���װ��'\0',�ٸ�ֵ��ָ��m_str
	


	Mystring str1(4, 'b');			//2.2 string(5, 'a')
	cout << str1.c_str() << endl;	//�ɹ�ʵ����4��b������ֵ	//c_str()������������ַ����ռ��ַ
								

									//2.2 string("abcdefg")
	Mystring str2("Keep going! Yy, Don't stop.");	//�ɹ�ʵ�����ַ�����ʼ��
	cout << str2.c_str() << endl;//���Դ�ӡstr2.c_str()+2 �������Ƿ��\0��ֵ��m_str������ȥ�ˣ��򲻻�������룬���涼�ǿ�


									//2.2 string("abcdefghij", 3)
	Mystring str3("Keep going! Yy, Don't stop.", 13);//�ɹ�ʵ�����ַ���ǰ13���ַ�������ֵ
	cout << str3.c_str() << endl;


	Mystring str4(str3, 1, 5);		//2.2 string("abcdefghij", 2, 5);
	cout << str4.c_str() << endl;	//�ɹ�ʵ������һ��������м��1~4���ַ������г�ʼ��


	Mystring str5(str2);			//2.2 string(const Mystring& str)
	cout << str5.c_str()+12 << endl;//�ɹ�ʵ����һ���������һ�������ʼ����


	Mystring str6("keep going! Yy, you're strong!");//�ɹ�ʵ��ֱ�������������������ַ���
	cout << str6 << endl;			//2.3 ������������

	Mystring str7("keep going! Yy, you're strong!");
	cout << str7 << endl;
	cout << str7.size() << endl;	
	cin	 >> str7;					//2.3 �������������
	cout << str7 << endl;			//�ɹ�ʵ�������ַ����Ƕ����ַ�������
	cout << str7.size() << endl;	//��ӡ�鿴�ַ����Ƿ�ı�




	system("pause");
	return 0;
}