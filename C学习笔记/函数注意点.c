#include <stdio.h>
#include <stdlib.h>

void fun1(void);
void fun2(void);
void fun3(void);
void fun4(void);
void fun5(void);
void fun6(void);
void fun7(void);// һ�����������ж������
void fun7(void);// һ�����������ж������
void fun7(void);// һ�����������ж������
void fun8(void);


void fun1(void)
{
	printf("���Ǻ���fun1 \n");
	fun2();
}

void fun2(void)
{
	printf("���Ǻ���fun2 \n");
	fun1();
}


void fun3(void)
{
	printf("���Ǻ���fun3 \n");
	fun3();
}


void fun4(void)
{
	fun4();
	printf("���Ǻ���fun4 \n");
}


void fun6(void)
{
	//���������ʵ�������û���κζ�������û���κ�����ġ�
}

void fun7(void)
{
	printf("���Ǻ���fun7 \n");
} 

void fun8(void)//һ������ֻ����һ������
{
	printf("���Ǻ���fun8 \n");
}

void fun8(void)//һ������ֻ����һ������
{
	pritf("���Ǻ���fun8 \n");
}
int main(void)
{
	//fun1(); //����Ƿ�����ӡ���Ǻ���fun1�����Ǻ���fun2�������໥����
	//��Ϊ������ִ�н���fun1��ӡ1����Ϊ����fun2����fun2����ӡ2������Ϊ����fun1����fun1��������ѭ��

	//fun3(); //�����Լ������Լ�������Ƿ���ѭ����ӡ3��

	//fun4();//����ֱ�ӱ�����ʾ��Stack overflow ����ջ��
	//��Ϊִ��fun4����ʱ����������ִ�У�����������ڴ�ӡ���ǰ�棬���·��������Լ������±�ջ

	//fun5();//����ʱ���棺: �޷��������ⲿ���� _fun5������ _main �������˸÷���
		//��˼���������û��ʵ�壬ֻ�������ˣ���û�ж��壬

	fun6();//��������Ķ�����û��ʵ�壬����û�д��룬���е���û���κ����⣬����û������

	void fun7(void);// һ�����������ж������
	fun7();//��������ж��������һ�����壬��ȫ��������

	fun8();//��������ж�����壬��ʾ�� ������void fun8(void)���������壬 �μ���fun8����ǰһ������
	//һ������ֻ����һ�����壬���˵��Իᱨ��

	system("pause");
	return 0;
}