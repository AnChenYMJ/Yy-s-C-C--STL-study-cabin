#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int a = -1;

	printf("��¼��ɼ���");
	scanf_s("%d", &a);

	if (60 > a)      //������if��else if��else����һ�������ṹ����Ҫ���룬�м���Կո񣬵�����������
	{
		printf("�ɼ�������\n");
	}
	else if (60 <= a && 70 > a)   //������ṹ�У���if elseһ�����ܹ�Ƕ�׵ģ�ע���������
	{
		printf("�ɼ�����\n");     //�Աȶ��if�ṹ�����ضϵ���ʱ��else if�м�ضϽ�ִ�нض�֮�ϵĳ��򣬲���������β
	}
	else if (70 <= a && 80 > a)  //�����if���ض�ʱ������ִ�г���
	{
		printf("�ɼ��е�\n");
	}
	else if (80 <= a && 90 > a)
	{
		printf("�ɼ�����\n");
	}
	else if (90 <= a && 100 >= a)                       //else��ͬ�������else if��ƥ��
	{
		printf("�ɼ�����\n");
	}
	else
	{
		printf("�ɼ�¼�����\n");
	}


	system("pause");
	return 0;
}