#include<iostream>
using namespace std;

class Cfather
{
public:
	double a;
};

class Cson:public Cfather
{
public:
	char b;
};

class Cother
{
public:
	int c;
};

int main()
{
	Cfather* p;
	Cson* s;
	Cother* o;

	//p = (Cson*)s;	//�ɵ�ǿ������ת���������֣���һ��C��C++ͨ�ã��ڶ���C++����
					//һ�����������ʽ��type��value���ڶ�������type��value��

		//����ת�������		//static_cast<type>(expression)
	p = static_cast<Cfather*>(s);//������ʽ������ת������Ҫ��������Ҫ��
							//yepe��expression����������໥��ʽת���Ĺ�ϵ������ǺϷ���

	//o = static_cast<Cother*>(s);//Cother��Cson����û���κι�ϵ���޷���ʽת�������Իᱨ��
						//error: �޷��ӡ�Cson *��ת��Ϊ��Cother *��//���������ת��

	o = (Cother*)s;//���Ǿɵ�ǿ������ת����û�����ƣ�ǿ��ת��
				//���������һЩ���⣬����Cson�̳���Cfather�����Ŀռ����������Լ��ĺ͸����
				//�����ռ�ĳ�Ա����Ҳ������ͬ��ǿ�кϲ�ת����Cother���ͻ���ڰ�ȫ������Σ��
				//������ʽ��ת������ȫ����Ȼ������Ƕ��ڴ��Ų�ʲô���ر���Ϥ����ǿ��ת��Ҳû����

	system("pause");
	return 0;
}