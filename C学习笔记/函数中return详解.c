#include <stdio.h>
#include <stdlib.h>

int fun1(void);
int fun2(void);
int fun3(void);
void fun4(void);  //ע���Ƿ��з���ֵҪ�붨��ʱ��ͬ������ᱨ��

int fun1(void)
{
	printf("���Ǻ���fun1 \n");
	printf("���Ǻ���fun1 \n");
	return 3; //��ֹ������������˳��ִ�е�returnʱ��ֱ����ֹ��������������β��
	printf("���Ǻ���fun1 \n");
	return 4;  //�����ж��return ��ִֻ���߼�˳���е�һ����Ȼ���������β��
	printf("���Ǻ���fun1 \n");//�����Լ��ضϵ��Թ۲����ִ�е�˳����̣��ض�ʱ	F10��һ��
	printf("���Ǻ���fun1 \n");
}

int fun2(void)
{
	int a = 32;  //���return������if�ṹ�У��ǲ�ͬ�ķ���ֵ�����ͬ����˼
	if (a >= 10 && a <= 20)
	{
		return 0;
	}
	else if (a > 20 && a <= 30)
	{
		return 1;
	}
	else if (a > 30 && a <= 40)
	{
		return 2;
	}
	else
	{
		return 3;
	}
}

int fun3(void)//����ʱ����ʾ���������еĿؼ�·��������ֵ
{			//��Ϊ�����b��ֵ�����ж���Χ�����û����returnֵ�����Ի���ʾ
	int b = 24;//else����else�����ܸ������з�Χ

	if (b >= 10 && b <= 20)
	{
		return 0;
	}
	if (b > 20 && b <= 30)//return�ܼ򻯳�������Ч�ʣ���ִ��returnʱ���Ͳ�ִ������������
	{					  
		return 1;
	}
	if (b > 30 && b <= 40)
	{
		return 2;
	}
}

void fun4(void)
{
	printf("���Ǻ���fun4 \n");
	return;   //���޷���ֵ�����У�return�͵���ֹʹ�ã�û�б������
	printf("���Ǻ���fun4 \n");
}

int main(void)
{
	fun1();

	fun4();

	system("pause");
	return 0; //����ķ���ֵ�ǲ���ϵͳ����ģ�����ֱ��ʹ�þͺ��ˣ������ǳ�����������
}			  //���������Ƕ����ע��