#include <stdio.h>
#include <stdlib.h>

void fun1(int* p, int nLength)
{
	int i;//����ĵڶ����������Բ��ñ�����ʾ�������õ�����ʱ��ͬ������ÿ�ζ�Ҫ�޸�Ԫ�ظ��������鷳
	for (i = 0; i < nLength; i++) //ע��forѭ�����������÷ֺŸ���
	{
		printf("%d, %d \n", p[i], sizeof(p));
	}
}

		//����ʽ����������p1[2536]C���Բ���д����Ԫ�ظ���ֻҪ��p1[]��ʽ�ģ�����Ϊ��*pָ������
void fun2(int p1[2536], int nLength1)
{		//����Ĳ�������Ϊ�������Ԫ�ظ��������������ڴ�ռ䳤�ȣ�
	int j;
	int k[200];
	int kw = sizeof(k);
	printf("%d \n", kw);  //����������p1�Ĵ�С���ԱȾ��ܿ�����p1��ָ�룬�������k������
	for (j = 0; j < nLength1; j++)
	{
		printf("%d, %d \n", p1[j], sizeof(p1));//�������p1���ֽڴ�С����֤��
	}
}

int main(void)
{
	int a[9] = { 9, 8, 7, 4, 5, 6, 3, 2, 1 };
	fun1(a, 9); //�������־���Ԫ�ص��׵�ַ

	int b[5] = { 2, 5, 8, 7, 4 };
	fun1(&b, 5); //��Ҳ��ʾ������׵�ַ

	int c[3] = { 9, 6, 3 };
	fun1(&c[0], 3);//��Ҳ��ʾ������׵�ַ

	int d[4] = { 7, 4, 1, 2 };
	fun2(d, 4);

	system("pause");
	return 0;
}