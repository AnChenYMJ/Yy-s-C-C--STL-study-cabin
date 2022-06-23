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
	    // 注意：在win32运行环境中，指针大小为4字节
		//在win64的运行环境中，指针大小为8字节
		//在上方工具栏可以直接切换32或64，但32位的计算机只能32位


	system("pause");
	return 0;
}