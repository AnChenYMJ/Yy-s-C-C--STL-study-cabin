#include <iostream>
using namespace std;

//�����б����͵�Ĭ��ֵ�ͺ�������ָ��Ĭ��ֵһ���������������������ֵ
template<typename T, typename Y = char>//�ᱻ������д�ĸ��ǵ�
class Ctea			//ָ��ģ������б�Ĭ��ֵ��ֻ����ģ��������
{
public:
	T ange;	//���԰ѳ�Ա����Ҳ�����ģ������б������
	Y high;

	Ctea()
	{
		ange = 88;
		high = 'g';
	}
	Ctea(T t, Y y):ange(t), high(y)
	{}

	void show();
	/*{
		cout << ange << " " << high << endl;
	}*/
};


template<typename T = char>
void fun(T u)	//ֻ������ģ����Ĭ��ֵ
{}

void Ctea<float, double>::show()	//����ʵ�ֺ���ģ��ķ���һ�������������������Ҫ����ģ������б�
{													//����ֻҪ������������Ҫ����ģ������б�
	cout << ange << " " << high << endl;
}

template<typename T, typename Y>	//����ʵ�ֺ���ģ��ķ�����
void Ctea<T, Y>::show()				//ģ������б�Ĳ������ͻ��� T Y
{													
	cout << ange << " " << high << endl;
}

int main()
{	
	//Ctea su;//error: ʹ�� �� ģ�� ��Ҫ ģ�� �����б�
	Ctea<int> su(15, 'Y');//ֻҪ�����⣬������һ��Ҫ����ģ�弴<>�����������
	su.show();	//��ģ����Ը�����ָ��Ĭ�����ͣ���Ĭ��ֵ�Ļ�����Ͳ���д�����ˣ���<>һ��Ҫ��
			//��������и�������ֵ�����ǾͿ��Բ�������
			//�����б�ָ��Ĭ��ֵ�����д������������д���ͻ��Ĭ��ֵ���ǵ�

	Ctea<int> ta;//�����Ա�г�ʼֵ���Ϳ��Բ����ݲ�������<>ģ������б�һ��Ҫ��
	ta.show();

	//Ctea* tsu = new Ctea;
	//Ctea<int, double>* tsu = new Ctea<int>;//ǰ��Ĳ����б�Ӧ����һ�£����򱨴�
	Ctea<int, double>* tsu = new Ctea<int, double>(66, 55.77);//�����������ģ������б�
	tsu->show();		//ָ�����ͣ����ݲ�������������С������

	system("pause");
	return 0;
}