#include <stdio.h>

//���⣺
//����ѭ������ӡ99�˷������α���ϰ�⣩
//��ӡ�ĸ��ǿ�i j �Ĵ�С��ϵ�Լ��Ƿ��ÿո�����
//%dx%d=%2d �е� %2d ���ڿ���̨ռ��2λ�Ŀռ䣨���81Ҳ��2λ������������˷��������λ��1 �����������ǰ�ƣ����¶Բ���
//�˷���������Ĺ�ϵ�أ���Ҫ���Ǿ�һ������������Ԫ�أ��±꣩���뵽i j��ȥ˼�� 

//�����99�˷���
void JuZhen99()
{
	for (int i = 1; i <= 9; i++)
	{
		for (int j = 1; j <= 9; j++)
		{
			printf("%dx%d=%2d  ", i, j, i * j);
		}
		printf("\n");
	}
}

//���½ǵ�99�˷���
void ZuoXia99()
{
	for (int i = 1; i <= 9; i++)
	{
		
		for (int j = 1; j <= 9; j++)
		{
			if (i >= j)
			printf("%dx%d=%2d  ", i, j, i * j);
		}
		printf("\n");
	}
}

//���Ͻǵ�99�˷���
void ZuoShang99()
{
	for (int i = 1; i <= 9; i++)
	{

		for (int j = 1; j <= 9; j++)
		{
			if (i <= j)
				printf("%dx%d=%2d  ", i, j, i * j);
		}
		printf("\n");
	}
}

//���½ǵ�99�˷���
void YouXia99()
{
	for (int i = 1; i <= 9; i++)
	{
		for (int k = i; k < 9; k++)		//ʹ�ÿո����½ǵĳ˷����������½ǵ���ʽ��
		{								//���� i ����ֵ��С�������뼸�οո�
			printf("        ");
		}
		for (int j = 1; j <= 9; j++)
		{
			if (i >= j)
				printf("%dx%d=%2d  ", i, j, i * j);
		}
		printf("\n");
	}
}

//���Ͻǵ�99�˷���
void YouShang99()
{
	for (int i = 1; i <= 9; i++)
	{
		for (int k = i; k > 1; k--)		//ʹ�ÿո����½ǵĳ˷����������½ǵ���ʽ��
		{								//���� i ����ֵ��С�������뼸�οո�
			printf("        ");
		}
		for (int j = 1; j <= 9; j++)
		{
			if (i <= j)
				printf("%dx%d=%2d  ", i, j, i * j);
		}
		printf("\n");
	}
}

int main(void)
{
	printf("�����99�˷���\n");
	JuZhen99();
	printf("\n");

	printf("���½ǵ�99�˷���\n");
	ZuoXia99();
	printf("\n");

	printf("���Ͻǵ�99�˷���\n");
	ZuoShang99();
	printf("\n");

	printf("���½ǵ�99�˷���\n");
	YouXia99();
	printf("\n");

	printf("���Ͻǵ�99�˷���\n");
	YouShang99();
	printf("\n");


	return 0;
}