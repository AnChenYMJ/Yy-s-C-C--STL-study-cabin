#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

struct ok
{
	int			a;
	double		b;
	const char* c;			//const char* c[40];	֮ǰ��ôд����ʾ�޷���floatת��const char* 
	float		f;			//ԭ��������д�ͳ��ַ�ָ�������ˣ���40���ַ���Ԫ�ص����飬���Ե��ĸ�����������Ԫ����
};							//char* ���ǽ����ַ�����ַ��ָ��

void show(ok o)
{
	cout << o.a << ' ' << o.b << ' ' << o.c << ' ' << o.f << '\n';
}

void STLlistdefine()
{
	ok ok1 = { 27, 164.03, "Yy, keep going , Don't stop!!", 60.14f };
	list<ok> li1(8, ok1);

	cout << size(li1)  << endl;						//size()  ����Ԫ�ظ���
	cout << empty(li1) << endl;						//empty() �鿴�����Ƿ���Ԫ�أ����򷵻�0�����򷵻�1
	//cout << li1.capacity() << endl;				//listû��������һ�����ˣ���Ҫ�½ڵ㣬����β������¿ռ�
													//����û�з���������С�ĺ�����
	for_each(li1.begin(), li1.end(), show);


	li1.resize(2);									//��������Ԫ�ظ���

	cout << li1.size()  << endl;						//2		//��size(li1)��д����һ����������һ��Ч������˼
	cout << li1.empty() << endl;						//0
	for_each(li1.begin(), li1.end(), show);


	li1.resize(0);									//���ó�0��Ԫ��

	cout << size(li1) << endl;						//0
	cout << empty(li1) << endl;						//1
	for_each(li1.begin(), li1.end(), show);			//û��Ԫ���ˣ����Բ���ӡ
}

int main()
{
	STLlistdefine();

	system("pause");
	return 0;
}