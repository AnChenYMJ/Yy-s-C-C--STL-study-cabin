#include <iostream>
using namespace std;


template <typename T, typename Y>
class Ctea
{
public:
	int age;
	Ctea()
	{}

	virtual void show()
	{
		cout << "teacher" << endl;
	}
};

//������������ģ��������ͣ������ݸ������ֻ����������������Ϳ����Լ���
template <typename X, typename Z, typename U, typename I>
class Cstud : public Ctea<Z,I>//���ݸ�������Щ�������������ʱ���������˳��Ҫ��Ӧ��
{
public:
	void show()		
	{
		cout << "student1" << endl;
	}
};


class Cstudn : public Ctea<int, const char*>//�̶���ʽ��д��
{
public:
	void show()
	{
		cout << "student2" << endl;
	}
};

int main()
{	//�����ģ��������ݸ�������ǵ�2��4�����������︸���ģ������б�Ҫ��Ӧ��
	Ctea<const char*, float>* te = new Cstud<char, const char*, int, float>;
										//����ģ���ж��ٸ������������Ҫд���ٸ�
	te->show();//�ɹ���ӡ

	//����Ҫ�봫�ݸ����������һ�£����򱨴�
	Ctea<int, const char*>* su = new Cstudn;//�̶���ʽ��ָ�빹������
	su->show();			//����Ͳ��ü�ģ������б��ˣ���Ϊ����û��ģ�壬������


	system("pause");
	return 0;
}