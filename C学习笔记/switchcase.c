#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int order = -1;

	scanf_s("%d", &order);

	if (1 == order)
	{
		printf("���һ��ѧ��\n");
	}
	else if (2 == order)
	{
		printf("ɾ��һ��ѧ��\n");
	}
	else if (3 == order)
	{
		printf("���һ��ѧ��\n");
	}
	else if (4 == order)
	{
		printf("�˳�ϵͳ\n");
	}
	else
	{
		printf("ϵͳ�޸�ָ��\n");
	}


	switch (order)      //������else if��ͬ��ִ��˳���ȼ�����ʽ�е�ֵ���ٰ�˳��ɨ���ǩ
	case 1:
		printf("���һ��ѧ��\n");		//ɨ�赽��ƥ��ı�ǩ������ִ�б�ǩ�µĴ���飬ִ�е�break����switch�ṹ
		break;
	case 2:
		printf("ɾ��һ��ѧ��\n");
		break;
	case 3:
		printf("���һ��ѧ��\n");
		break;
	case 4:
		printf("�˳�ϵͳ\n");
		break;
	default:                     //���û�з���һ���ģ�ƥ�䣩��ֵ��ִ��Ĭ�ϵĴ����ֱ�������Ž���
		printf("ϵͳ�޸�ָ��\n");
	}


	system("pause");
	return 0;
}