#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>  //memset��ͷ�ļ�

int main(void)
{
	int* p = (int*)malloc(sizeof(int) * 5);//����д��sizeof��4�����ⶼ���Եģ�����ֱ��д���������ֱ��

	int a[5];      
	int* p1 = &a[0];//����ָ�������


	int i = 0;
	for ( i = 0; i < 5; i++)
	{
		printf("%d  ", *(p + i));
	}

	printf("\n"); //����

	memset(p, 0, 20);
	for (i = 0; i < 5; i++)
	{
		printf("%d  ", *(p + i));
	}

	free(p); //free��������ʲô���͵ģ�ͨ���׵�ַ�鵽���ͷ�


	unsigned int b;
	int* p2;

	scanf_s("%u", &b); //�޷��ŵ�������%u
	p2 = (int*)malloc(b);

	free(p2);
	printf("\n");


	//const int c = 13;//VSϵ�еı�������ͨ�� �Ǳ䳤�����д��
	////scanf_s("%d", c);	/�󲿷ֵı���������ͨ��
	//int d[c];

	/*int e = 13;  //һ�����󲿷ֱ�������ͨ��������ʹ��malloc����ͨ�õķ���
	scanf_s("%d", &e);     //ʹ�������������mallocһ����ͨ�������ı������С
	int f[e];*/

	system("pause");
	return 0;
}