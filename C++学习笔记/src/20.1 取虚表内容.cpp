#include <iostream>
using namespace std;

class Coldman
{
private:
	int a;
	virtual void fun()
	{
		cout << "fun" << endl;
	}
public:
	virtual void show()
	{
		cout << "show" << endl;
	}
	Coldman():a(3)
	{}
};

class Cman: public Coldman
{
private:
	void fun()
	{
		cout << "no fun" << endl;
	}
public:
	void show()
	{
		cout << "no show" << endl;
	}
};

int main()//_main����ʱ�����ܳ��ֵ����⣺������д�����������ˣ�������ûд���ļ���д��
{
	//��ڿε�������ȡ�Ͻڿ���˵���麯���б������
	//����ռ��ʼ��4�ֽ����ݾ�������麯���б��ĵ�ַ��������ָ��

	Coldman* fa = new Cman;//�����������м̳й�ϵ���Ҹ���ָ��ָ������
	//fa->show();
	//(int*)fa//�������ַת����int*����
	//*(int*)fa//���������ַָ��Ķ���ռ�
	//(int*)(*(int*)fa)//������ռ�ת����int*����
	//*(int*)(*(int*)fa)//�����������ռ�

	//���ﲻ̫��Ϊʲô��Ӧ�ò������һ��
	typedef void (*p)();//(*p)()�ʹ���void����ֵ���������ͣ�void�������͵ı���

	//һ��ʼ����(*p) ������//��������private�ķ�����ֱ�ӷ��ʵ���������������ĺ�����ַ����
	((p)(*((int*)*(int*)fa + 0)))();	//��ʦд
	((p)(*((int*)*((int*)fa) + 0)))();	//��д

	((p)(*((int*)*((int*)fa) + 1)))();//�ɹ���ӡ���

	//��������ռ�����⻯�б��β������0000��Ҫ�ѵ������ռ�ת��int*����װ��ָ��pp��
	int* pp = (int *)*((int*)*((int*)fa) + 2);
	cout << pp << endl;//��ӡ��0000��֤��������βװ����0000

	//ע�⣺�����ÿ�������ĵ�ַ�����������һϯ֮�أ�����������д���������������

	delete fa;//ע��Ҫ�ͷſռ䣬������

	system("pause");
	return 0;
}