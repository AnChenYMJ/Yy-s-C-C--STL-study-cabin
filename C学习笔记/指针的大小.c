#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int* p;
	int(*p1)[1];
	int(*p2)[3][2];
	double* p3;
	short* p4;
	float* p5;

	printf("%d, %d \n", sizeof(p), sizeof(int *));
	printf("%d, %d \n", sizeof(p1), sizeof(int(*)[1]));
	printf("%d, %d \n", sizeof(p2), sizeof(int(*)[3][2]));
	printf("%d, %d \n", sizeof(p3), sizeof(double *));
	printf("%d, %d \n", sizeof(p4), sizeof(short *));
	printf("%d, %d \n", sizeof(p5), sizeof(float*));
	    // ע�⣺��win32���л����У�ָ���СΪ4�ֽ�
		//��win64�����л����У�ָ���СΪ8�ֽ�
		//���Ϸ�����������ֱ���л�32��64����32λ�ļ����ֻ��32λ


	system("pause");
	return 0;
}