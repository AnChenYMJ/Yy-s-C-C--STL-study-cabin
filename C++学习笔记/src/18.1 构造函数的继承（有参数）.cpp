#include <iostream>
using namespace std;

class Cfather
{
public:
	Cfather(int a)
	{
		cout << "i am father \n";	//\nЧ�ʱ�endl�ߣ����ǻ���
	}
};

class Cson : public Cfather
{
private:
	int na;
public:	
	//Cson()//error C2512: ��Cfather��: û�к��ʵ�Ĭ�Ϲ��캯������
	//{		//��Ҫ�Ѹ���Ĳ�������ȥ

	//}
	//�������Ĺ��캯���в����������Ǿͱ���Ѹ���Ĺ��캯��д����

	//Cson(int a, int b) : Cfather()//error C2512: ��Cfather::Cfather��: û�к��ʵ�Ĭ�Ϲ��캯������
							//�����в����Ļ����봫��һ��������ȥ
	Cson(int a, int b) : Cfather(b)//ͨ����ʼ���б�Ѹ���Ĳ������ݹ�ȥ
	{						//���Դ��ݱ�����Ҳ����ֱ�Ӵ��ݳ�������Cfather(15)
		na = a;
	}
};



class CPeop
{
public:
	CPeop(int a)		//�������й��캯������ʱ����������ݴ��ݲ����Ĳ�ͬ��ѡ��ͬ�Ĺ��캯��
	{
		cout << "i am people1 \n";
	}
	CPeop(int h, int l)
	{
		cout << "i am people2 \n";
	}
};

class Coldman : public CPeop
{
public:
	Coldman(int a, int b) : CPeop(a)//���Ը����ഫ�ݱ�����Ҳ���Դ��ݳ���
	{								//�����ܸ������ݣ�ֻ�ܸ����త������
				
	}
};

class Cman : public Coldman
{
public:
	Cman(int a, int b, int c) : Coldman(b, c)//, CPeop(a) //�Ƿ��ĳ�Ա��ʼ��:��CPeop�����ǻ����Ա
	{									//������ֻ�ܴ��ݲ��������࣬���ܸ��游�࣬���ܸ���
			
	}	//��Ȼ��������๹�캯��û�в����������ǾͲ���Ҫ���ݲ���
};
	
int main()
{
	Cson doct(16, 89);//˫��

	Cman su(45, 85, 78);//��㣬�����

	system("pause");
	return 0;
}