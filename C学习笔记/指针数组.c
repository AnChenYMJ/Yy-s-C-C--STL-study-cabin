#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int b = 6,
		c = 4,
		d = 7,
		e = 6,
		f = 9;
	//int* �Ǳ���ÿ��Ԫ�ص�����Ϊint*
	int* a[5] = { &b, &c, &d, &e, &f }; //�����ָ�����飺һ�����飬����װ�ص�Ԫ���Ǹ�����ַ
										//Ҳ�е�ַ����

	printf("%d \n", d);
	*a[2] = 16;          //ͨ��ָ���±��޸�Ԫ��ָ���ֵd
	printf("%d \n", d);
	*&d = 14;
	printf("%d \n", d);


	system("pause");
	return 0;
}