#include <stdio.h>
#include <stdlib.h>
//������β�Ҳ����д��(*p)[3][2]
void fun1(int (*p)[2], int hang, int lie)
{
	int i, j;
	for (i = 0; i < hang; i++)
	{
		for (j = 0; j < lie; j++)
		{
			printf("%d, %d \n", p[i][j], sizeof(p));
		}
	}
}

void fun2(int* p, int hang, int lie)
{		//��һ��Ԫ�صĵ�ַ���������ַ���¶�ȡ����
	int i;//��Ȼ�Ƕ�ά���飬���ռ������������ģ�����ʹ�����ַ�ʽҲ�ܳɹ�
	for (i = 0; i < hang * lie; i++)
	{			//����Ҳʵ���˱�����ά����
		printf("%d, %d \n", p[i], sizeof(p));
	}
}

void fun3(int(*p)[3][2], int hang, int lie)
{
	int i, j;
	for (i = 0; i < hang; i++)
	{
		for (j = 0; j < lie; j++)
		{//��Ϊ������Ƕ�ά����ĵ�ַ����*p���Ƕ�ά���鱾��
			printf("%d, %d \n", (*p)[i][j], sizeof(p));
		}
	}
}

int main(void)
{
	int a[3][2] = { {3, 2}, {5, 4}, {8, 7} };
	int(*p)[2] = a;//�������־�����Ԫ�صĵ�ַ����ά�������Ԫ����һ��һά���飬
	fun1(a, 3, 2);//һά�����ָ�����;���int(*p)[]
	fun2(&a[0][0], 3, 2);
	fun3(&a, 3, 2);//ֱ�������ά����ĵ�ַ

	system("pause");
	return 0;
}