#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>//malloc, calloc, realloc��ͷ�ļ�����<malloc.h>��<stdlib.h>

int main(void)
{
	int* p = (int*)calloc(6, 4);  //��mallocһ������ҪԽ��
	//(6, 4)����˼������6��Ԫ�ص������ռ䣬ÿ��Ԫ��4�ֽڡ�
	//������Ԫ�صĵ�ַ��ֵ��ָ��p����ʱ��ָ��p��ָ����Ԫ�صģ���������ָ��

	int i;

	for (i = 0; i < 6; i++)
	{
		printf("%d  ", p[i]);//��ʱ���Ϊ6��0��calloc�Ա�malloc��calloc���Ԫ�س�ʼ��Ϊ0��malloc�����ʼ��
	}						//��ѭ�±����㣬��ʱ��p��ָ����Ԫ�صģ���������ָ��

	free(p);



	system("pause");
	return 0;
}