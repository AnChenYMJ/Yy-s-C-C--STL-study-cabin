#include <stdio.h>
#include <stdlib.h>

//��������д��ȫ������������������к����Ͷ������ˡ�
typedef int maint;//maint ���� int
typedef maint niint;//niint Ҳ�� int������ʹ����û�κ�����ֻ�Ǹ�int���˸�����

typedef unsigned int unin;//�޷������ͻ����־��ܷ��������ˣ���Ϊԭ���ֳ�
typedef unsigned int unin;//ͬһ����������һ��������
//typedef double unin;//��ͬ���Ͳ�����һ�������֣�����ʾ����unin��: �ض��壻��ͬ�Ļ�����


typedef int* zhizhen;//ָ�������ض���  type������ define������


typedef struct UN
{
	int a;
}_ST;//��Ϊ����typedef�Ĺ�ϵ�����ﲻ�ܵ��������ṹ�����ʹ����
	 //ֻ�ܵ����ṹ�����������ʹ��

typedef struct  //����û�����ֵĽṹ��
{
	int a;
}_ST1;//�����û���ֵĽṹ�壬ͨ��typedef����������־��ܸ��ṹ��һ��������



void fun(int a, double b)
{
	printf("%d, %lf \n\n", a, b);
}
//void (*)(int , double)//����������ĺ�����ַ����
typedef void (*pzhi)(int, double);//����Ǻ���ָ�����͵�������

int main(void)
{
	int i = 321654;
	maint a = 515;   //����int���ͣ�ֻ�Ǹ����ͻ��˸����֣�ʹ��������
	niint b = 9596;
	printf("%d, %d, %d \n\n", i, a, b);

	unin c = 789456;  //���Կ���������ʹ��ԭ����unsigned int��Ҫ����һЩ
	unsigned int d = 55555;
	printf("%d, %d \n\n", c, d);//�޷�������


	zhizhen p = &i;//����zhizhen'�͸� int* һ���ˣ�ֻ�ǻ������ֶ���
	*p = 97456;		//ָ������������
	printf("%p, %p, %d, %d\n\n",&i, p, i, *p);


	struct UN n = { 6 };
	_ST u = { 5 };  //�ṹ�����͵���������_ST ���൱��struct UN��ʹ��
	printf("%d, %d \n\n", n.a, u.a);

	
	void (*p1)(int, double) = fun;//���Ǻ���ָ�������
	pzhi p2 = fun;//���Ǻ���ָ�������,���Կ�������������һ�У�Ҫ�򻯺ܶ࣬pzhiֱ�ӵ�������ָ������ʹ��
	//void(*)(int, double)//����������ĺ�����ַ����
	p1(55, 89.98);//���Ǻ�������
	p2(66, 78.12);
	

	system("pause");
	return 0;
}