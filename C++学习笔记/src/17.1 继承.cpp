#include <iostream>
using namespace std;


		//C������Ϊ�˱���һ�δ����ظ�ʹ�ö�������д���к����������ַ�ʽ�������ظ���д
		//��������ã����������õȵ�
		//C++����ʹ���˼̳����ظ���д��������̳л�������ԣ����Ͳ�������дһ�������ˣ������ԣ�
		//�������ǰ�һЩ�����õ������Էŵ�һ��װ��һ����������ȥ�̳�

class COpportunists		//����������		//���ࡢ���࣬
{
public:
	int a;
	COpportunists() :a(12)		//�����ܵ������࣬����Ҫ������Ŀγ̲Żὲ
	{

	}
	void Arrogant()		//����
	{
		cout << "arrogant" << endl;
	}
};


			//����Ǽ̳е���ʽ��ð��public���ϸ��������
class Cteacher : public COpportunists		//��ʦ	//�����ࡢ����
{
public:
	void Teach()		//����Ի���û��Ӱ�죬
	{
		cout << "teach child" << endl;
	}
};

class COfficeWorker : public COpportunists	//�ϰ���		//�����ࡢ����
{
public:
	void lifeless()	//����������
	{
		cout << "lifeless every day" << endl;
	}
};

class CPolitician : public COpportunists//����		//�����ࡢ����
{
public:
	void Indifferent()	//��Į
	{
		cout << "Indifferent" << endl;
	}
};
int main()
{
	COfficeWorker su;
	su.Arrogant();
	cout << (su.a = 15) << endl;//����õ���public�ļ̳����η������൱�ڸ���ĳ�Աȫ���̳й�����
					//������ԱҲ�Ѿ�����Լ����ˣ��ⲻ���Ǹı丸�ֻ࣬�Ǽ̳��˱���Լ���
					//��������Ը���û���κθı䡣

	Cteacher ta;
	cout << ta.a << endl;
	ta.Arrogant();


	CPolitician* yu = new Politician;//ָ������������

	system("pause");
	return 0;
}