#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int i = 0,
		a = 120;

	printf("��ӭʹ�ñ�ϵͳ\n");
	printf("������Χ��0~100\n");

	while(1)  //for (i = 0; -1 <= i; i++)  //��ʵ���������while��1������������ѭ��
	{	
		printf("������ɼ��� ");
		scanf_s("%d", &a);      //ע�⣬��д�������ʱ��һ��Ҫ�ڱ���ǰ��ȡ��ַ��&

		if (-1 == a)
		{
			printf("��лʹ�ñ�ϵͳ���ټ���\n");
			break;
		}

		if (60 > a)
		{
			printf("������\n");
		}
		else if (60 <= a && 70 > a)
		{
			printf("����\n");
		}
		else if (70 <= a && 80 > a)
		{
			printf("�е�\n");
		}
		else if (80 <= a && 90 > a)
		{
			printf("����\n");
		}
		else if (90 <= a && 100 > a)
		{
			printf("����\n");
		}
		else if (100 == a)
		{
			printf("����ţ\n");
		}
		else
		{
			printf("�������,����������\n");
			continue;     //����������ѭ����ͷ���¿�ʼ
		}
	}

	system("pause");
	return 0;
}