#include <iostream>
#include <list>				//������ͷ�ļ��������������֣��Ժ������������
#include <algorithm>		//һЩ�ڽ���������дͷ�ļ���������string������дͷ�ļ�
using namespace std;		//��Ϊ������֧�֣��������������������ֲ�Բ�Ҳ���������ѧϰ�����Ի��ǽ���дͷ�ļ�

typedef struct ko			//ͷ��typedef β��* ���Ǹ��ṹ��������������������һ������
{							//��ⲻ��λ�������׳���
	int		a;				//��������ʹ��������ʱ�������㲻���Ǽ���ָ�룬��֪���Ӷ���*�����⣬���׳���
	char	c;
}*_ko;						//C++���ýṹ��Ҳ�ܷ��㣬д�ṹ�����־ͺ��ˣ����Բ�����ʹ�ýṹ��������


struct ok					//�ýṹ���������������������������
{
	int		a;
	double	b;
	char	c;
};

void show1(ok o)			//��������ѵ�����char���͵ĳ�Աǿת���˻�����������float
{
	cout << o.a << ' ' << o.b << ' ' << (float)o.c << '\n';		// \n �� endl Ч�ʸ���
}

void show2(ok o)
{
	cout << o.a << ' ' << o.b << ' ' << (float)o.c << '\n';	
}

void STlistdefine()	
{
	list<ok> li1;			//�޲�����û��Ԫ��


	ok ok1 = { 26, 164.11, 'y' };
	list<ok> li2(3);		//�������ṹ���ʼ������

	for_each(li2.begin(), li2.end(), show1);			//����ֻ��ӡ��������Ա����Ϊ0����һ����Ա��char���ͣ�
	cout << endl;										//ASC���0 ��һ��������ʾ�ַ�������Ҫ��ӡ�Ļ�����ǿת�ɻ�����������

	ok ok2 = { 28, 164.11, 'Y' };						
	list<ok> li3(6, ok2);								//��num��val�������ʼ��
	for_each(li3.begin(), li3.end(), show1);
	cout << endl;

	
	list<ok> li4(li3);									//����һ��������������ʼ��
	for_each(li4.begin(), li4.end(), show1);
	cout << endl;


	list<ok>::iterator ite = li4.begin();				//���õ�����������һ�������һ�θ��������ʼ��
	ite++;												//list�ĵ�����������+1 +2 �����ĵ�ַƫ�ƣ�ֻ��++
	ite++;												//��Ҫ��2����ʼ�Ļ����ͱ����Լ�2�Ρ�
	list<ok> li5(ite, li4.end());						//ֻ���Լӣ���Ϊ�����Ԫ�ز��������ռ䣬��ַƫ�ƾͻ�Խ�����
	for_each(li5.begin(), li5.end(), show1);

}

int main()
{
	STlistdefine();			//���������ʾ��δ�����ı�ʶ����һ����ͷ�ļ�ûд



	system("pause");
	return 0;
}