#include <iostream>
using namespace std;

struct STU
	{
		int i;
		float f;
	};

class Cstu
{
public:
	int a[6];
	STU sr;
	
	//Cstu() :a()//���������г�ʼ���ķ�ʽһ����ͬ�ı��������ܻ�����鲻ͬ��ֵ
	//{
	//}

	/*Cstu()
	{			//���������г�ʼ���ķ�ʽ��������ѭ����ӡ
		for (int i = 0; i < 6; i++)
		{
			a[i] = 0;
		}
	}*/

	Cstu()
	{			//����������������ʼ���ķ�ʽ��������memset������
		memset(&a[0], 0, 24);//����1��Ҫ�޸ĵ������ռ���׵�ַ������2��Ҫ��ÿ���ռ丳��ֵ
	}					 //����3����������ռ���ܴ�С��ע�ⲻҪԽ�磬������к����ҵ����⣩
	//ע�⣺�ռ�����������ģ���memset�������ʱ������Ĳ��ֿ��ܾ��ǽṹ��Ŀռ䣬
	//�ṹ�帳ֵ��ʾ���ṹ�屻Խ������Ĳ��־Ϳ��ܱ�memset��ֵΪ�����������������ڴ�ʱҪʮ��С��

	

	/*Cstu(STU en) :sr(en)//�ṹ�崫�ݲ�����ʼ��
	{
		cout << sr.i << " " << sr.f << endl;
	}*/

	Cstu(STU& en) :sr(en)//���ýṹ�������ʼ��
	{
		cout << sr.i << " " << sr.f << endl;
	}
	void show()
	{
		for (int i = 0; i < 6; i++)
		{
			cout << a[i] << endl;
		}
	}


};

int main()
{
	//Cstu st;
	//st.show();

	STU fg = {26, 165.22f};//�ṹ���໥��ֵ
	STU yu = fg;
	cout << yu.i << " " << yu.f << endl;

	Cstu bo(fg);
	cout << bo.sr.i << " " << bo.sr.f << endl;

	//��ʼ���ķ�ʽѡ�����ֶ����ԣ���Ҫ������ס
	system("pause");
	return 0;
}