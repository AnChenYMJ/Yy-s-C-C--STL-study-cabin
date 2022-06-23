#include <iostream>
using namespace std;


template <typename T, typename Y>
class Cfather
{
public:
	T age;
	Y tired;

	Cfather()
	{}

	Cfather(T t, Y y):age(t), tired(y)
	{}

	void show()
	{
		cout << age << " " << tired << endl;
	}
};

class Cson : public Cfather<int, double>	//�̶���ʽ�ļ̳�ģ��
{					//ȱ���ǣ�ͨ�����ഫ�ݵĲ�����ֻ��������д�õ����ͣ����ܱ仯
public:
	Cson(int a, double b):Cfather<int, double>(a, b)//�������Ĺ��캯��û�в������Ϳ��Բ�д���ݲ���
	{

	}
};


template <typename X, typename Z>	//����ģ��
class Cdaughter : public Cfather<X, Z>	//�����ʽ�ļ̳�ģ��
{					//��������ʵ���������ܵĴ�������������
public:
	Cdaughter(X a, Z b) :Cfather<X, Z>(a, b)//�������û�в������ǾͲ���д���ݲ�����
	{

	}
};


int main()
{
	Cson so(156, 'y');//���Է��֣�û�д�ӡ�ַ�������ӡ�˶�Ӧ��ASC��
	so.show();		//��Ϊ�����д��ݵĲ������͹̶�����int��double

				//�ַ���������const char*//��Ϊ�ַ����ǳ���
	Cdaughter<char, const char*> du('o', "Keep going Yy~ if tired ,Just take a rest");
	du.show();		

	system("pause");
	return 0;
}