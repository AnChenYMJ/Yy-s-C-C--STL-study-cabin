#include <iostream>
using namespace std;

class CPeople
{
public:
	CPeople()
	{
		cout << "CPeople" << endl;
	}
};

class xiaoxi : public CPeople
{
public:
	xiaoxi()
	{
		cout << "xiaoxi" << endl;
	}
};

class xiaojiao : public xiaoxi
{
public:
	xiaojiao()
	{
		cout << "xiaojiao" << endl;
	}
};

int main()
{
	xiaoxi xi;//���Կ�������xiaoxi����ʱ�����캯����ִ��˳�򣺸��� ��������

	xiaojiao zhi;//���̳�ʱ�����캯����ִ��˳���ǣ������һֱ��������

	//���󹹽�ʱ�Ŀռ�Ҳ�ǰ��� ����ൽ������ ��˳��������ռ�ġ�
	//����xiaojiaoʱ���ּ̳���xiaoxi������xiaoxiʱ���ּ̳���Cpeople��Ȼ��˳���ٴ�����࿪ʼ��������

	system("pause");
	return 0;
}