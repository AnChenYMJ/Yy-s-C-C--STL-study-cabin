#include <iostream>
using namespace std;

class COUt
{
public:
	int ange;
	COUt() :ange(19), ci2(this)
	{}
		

public:
	class CIn
	{
	public:
		int high;
		CIn()
		{
			high = 27;
		}

		void show()
		{					
			//�ڲ�����ֱ��ʹ���ⲿ���Ա�ǲ��еġ�
			//cout << ange << endl;//error����COUt::ange��: �����������ơ���̬��ö����
			COUt co;
			cout << co.ange << endl; //�������ڲ��๹��һ�������ö��������ⲿ��������
		}
	};
public:
	CIn ci;		//�������ⲿ�๹��һ���ڲ���Ķ�����ʵ�����ڲ���Ľ���

public:
	class CIn2
	{
	public:
		int high2;
		COUt* py;
		CIn2(COUt *p):py(p)		//���ⲿ���ָ�봫�ݽ�����ʱ�佻��ͨ��
		{
			high2 = 27;
		}

		void show()
		{								//�����贴��������ʹ���ⲿ���Ա�����ⲿ���Ա�ı���ܴ��ݽ�����
			cout << py->ange << endl;	//ͨ���ⲿ���ָ����ʵ�ֳ�Ա�Ĺ������
		}
	};
public:
	//CIn ci2(this);//��ĳ�Ա���޷���ֵ�ģ�����Ĳ������൱�ڸ�ֵ
	CIn2 ci2;//����Ĺ��캯���и�����ֵ�˲�����
};

int main()
{
	COUt su;
	su.ci.show();	//ͨ���ⲿ���������ڲ���ĺ���

	su.ange = 29;	//�ᷢ�ָı���ange��ֵ�������Ǵ�ӡ��19
	su.ci.show();	//ԭ������Ϊsu��co�ǲ�ͬ�Ķ��󣬸ı���su�ĳ�Աֵ����û�ı����co�ĳ�Աֵ
					//�������Լ������Ŀռ䣬�ǲ�ͬ�Ķ���,ע��co��show������Ķ���
	
	su.ci2.show();	//�ɹ���ӡ29��������su�ı���ֵ������ָ����ʵ���ⲿ�����ڲ���Ĺ���ͨѶ

	system("pause");
	return 0;
}