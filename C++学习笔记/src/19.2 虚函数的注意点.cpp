#include <iostream>
using namespace std;

class Cfather
{
public:
	//virtual	int aa;		//�� ֻ��Ժ�����Ա����������ݳ�Ա
	//int aa;

	//virtual Cfather(): aa(11)//��inline���ǹ��캯����Ψһ�Ϸ��洢��
	//{}					//���캯��Ĭ����inline���ͣ��������Ǳ�����麯������

	virtual inline void show()	//�����������������麯������Ȼû�б��������������������������
	{								//��inlineʧȥ������
		cout << "i am father" << endl;
	}

	virtual void show(int a)	//��������������һ��
	{
		cout << "i am father" << endl;
	}

	//virtual int show()//��д�麯�����������в��죬�Ҳ������ԡ�Cfather::show����Э��
	//{				//ֻ��Э�亯������������ķ���ֵ���Ͳ�ͬ
	//	cout << "i am father" << endl;
	//}

	////virtual Cfather& show()//Э�䣬������ֵ�ǵ�ǰ�ࣨ���󣩵�����
	////{
	////	cout << "i am father" << endl;
	////	return (*this);
	////}

	//virtual void show()	//����ڸ��ǵĹ�ϵ��ʹ���麯����������д
	//{
	//	cout << "i am father" << endl;
	//}
};

class Cson:public Cfather
{
public:
	int aa;
	//virtual void show()//������д�ĺ���Ĭ�����麯���������в���

	void show()			//ǰ�����ص�virtual�ɼӿɲ���
	{
		cout << "i am son" << endl;
	}
	////virtual Cson& show()//Э�䣬������ֵ�ǵ�ǰ�ࣨ���󣩵�����
	////{
	////	cout << "i am son" << endl;
	////	return (*this);
	////}
	Cson():aa(1)
	{}
};

class Csonson:public Cson
{
public:
	void show()
	{
		cout << "i am child" << endl;
	}
};

int main()
{
	Cson* so = new Csonson;
	so->show();		//�ᷢ�ֵ��õ���sonson���ӱ��ĺ�����֤��������son��д�ĺ���Ĭ�����麯��

	Cfather* fa = new Cson;
	fa->show(1);	//���õ����Լ��ĺ�����֤����������Ҫ������Ĳ���һ��
	fa->show();		//�޷���ӡ��֤���˷���ֵ����Э�䣬�������������һ��
					//����������Ĳ����뷵��ֵ����һ��������ֵ��һ����������Э��

	//ע���ʼ��е��ң��ͽ��Xmail�μ���

	delete fa;
	delete so;//ע���ͷſռ䣬������


	system("pause");
	return 0;
}