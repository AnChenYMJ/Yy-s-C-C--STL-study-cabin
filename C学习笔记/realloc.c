#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

int main(void)
{
	int* p = (int*)malloc(sizeof(int) * 5);

	size_t a = _msize(p);//�º�����_msize��������С����������Ŀռ��С

	printf("%d \n", a);



	//�������¿ռ�󣬸�mallocһ��Ҳ�᷵��һ����ַ	��
	//���ԭ���ռ����ڵĿ����ڴ���Ƭ��С֧���޸ĺ�Ŀռ䣬�򷵻صĵ�ַ����
	//���ԭ�����ڵ��ڴ�ռ䲻����չ�����Ѱ����һ���㹻������ڴ���Ϊ�¿ռ䣬���صĵ�ַ�ͻ�ı�
	//�����������²�����Ϊ�·��ص�ַ��ָ�룬
	int* p1 = (int*)realloc(p, 40);//realloc�� �����������һ��������Ҫ�޸ĵĿռ����ƣ�
									//��һλ������ϣ���ĳɵĿռ�Ĵ�С
	if (NULL == p1)		//��mallocһ������ҪԽ��
	{				//Ϊ�˷�ֹ��չ�Ŀռ䳬���ڴ��ܸ������ޣ�����NULL��0ֵ����Ҫ����if�ж�
		//���⴦��
	}
	size_t b = _msize(p);

	printf("%d \n", b);

	free(p); //ע�⼴ʱ�ͷ��ڴ�

	system("pause");
	return 0;
}