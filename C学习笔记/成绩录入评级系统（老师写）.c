#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

//������
//1.��ʾ��ӭ
//2.��ʼ��ѭ��
	//2.1����һ����
	//2.2��������
	//2.3 ����-1�˳�
	//2.4���������������Ϸ�����������
	//2.5�����ּ�


int main(void)
{
	int i = -1;

	printf("��ӭʹ�ñ�ϵͳ\n");
	
	while (1)
	{
		printf("������ɼ�:\n");
		scanf("%d", &i);

		if (-1 == i)
		{
			break;       //���ifҪ�ڷǷ�����ǰ�棬�����ִ�зǷ��������ʾ��
		}

		if (i > 100 || i < 0)
		{
			printf("������ֵ�Ƿ�������������0~100����ֵ\n");
		}

		if (0 < i && 60 > i)
		{
			printf("������\n");
		}
		else if (60 <= i && 70 > i)
		{
			printf("����\n");
		}
		else if (70 <= i && 80 > i)
		{
			printf("�е�\n");
		}
		else if (80 <= i && 90 > i)
		{
			printf("����\n");
		}
		else if (90 <= i && 100 > i)
		{
			printf("����\n");
		}
		else if (100 == i)
		{
			printf("����ţ\n");
		}
		
	}
	printf("ϵͳ�رգ���л��ʹ�ñ�ϵͳ����Ե�ټ�~\n");


	system("pause");
	return 0;
}