#include <iostream>
using namespace std;

class Cfather
{
public:				//����virtualֻ��ʹ���ں����ϣ����ݳ�Ա��������
	//virtual int aa;	//��Cfather::aa��: ������������������ʹ�á�virtual��
	int aa;
	Cfather()		
	{
		aa = 22;
	}
	virtual void show()	//��virtual�͵�������ĺ�����û��virtual�͵����Լ��ĺ���
	{
		cout << "i am father" << endl;
	}
};

class Cson : public Cfather
{
public:
	int aa;
	Cson() :aa(11)
	{

	}
	void show()		//����������к���������ͬ����ʹ���ĸ�������ʹ���麯��
	{
		cout << "i'm son \n";
	}
};

class Cman : public Cfather
{
public:
	void show()
	{
		cout << 250 << endl;
	}
};

class Coldman : Cson
{
public:
	void show()
	{
		cout << 250 << endl;
	}
};



int main()
{
	//���εĲ���Ҫ��Ϊ��������������в���virtual ���κ���
							//�����м���virtual �����κ�����ʹ��������麯��


	//int* ii = new char;		// ����ʼ����: �޷��ӡ�char *��ת��Ϊ��int *��
								//��ͨ����������ָ�벻�������������͵Ŀռ�

	//Cfather* fat = new Coldman;// �޷��ӡ�Coldman *��ת��Ϊ��Cfather *��//�޷���������
	Cfather* fat = new Cson;	//����ָ��������������Ŀռ䣬��������ȫ�����������������Ƕ�̬�Ļ���
								//�������ڸ�������������ռ�
	//Cson* so = new Cfather;	//����ָ���޷�ָ����
	fat->show();				//��Ȼָ��������ռ䣬��ֻ�ܵ����Լ��ĳ�Ա	
	cout << fat->aa << endl;	//ԭ���ǣ�ָ����η��ʿռ䣬�ɿռ�����;�����������ռ������Ǹ����
	//�˴��Դ�ӡ�˻����int aa	//���������ֻ�ǿռ��С������ֻ�ܷ����Լ��ĳ�Ա
	
	fat->show();				//�ڸ����ڣ�ʹ��virtual����������ͬ���ĺ����������ں����������Ѹ����еĸú������
								//�麯�������ǵ��ø���ĸ��麯����Աʱ���ͱ�ɵ��������ͬ��������

	Cfather* so = new Cman;		//�������һ�Աȣ�����ֻ��Ҫ�޸�ָ��Ŀռ���ܹ���ɣ�����״̬�л�
	so->show();					//��һ�в��øı䣬�ı�����ָ��ռ��ʵ���˶���״̬���л���ִ�в�ͬ�Ľ��
								//����Ƕ�̬

	//ע�⣺���ֶ�̬ ֻ������ջ���������������������������ʦҲ��֪��զ���룩
	//�������ǲ���ϵͳ���룬����ϵͳ�ͷŵĿռ䡣


	delete fat;
	delete so;//ע���ͷſռ䣬������

	system("pause");
	return 0;
}