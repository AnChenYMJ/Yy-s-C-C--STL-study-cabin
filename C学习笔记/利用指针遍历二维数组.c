#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int a[3][3] = { {5, 8, 6}, {3, 1, 4}, {5, 7, 1} };
	//
	////int* p = &a[0][0];
	//int* p = a[0]; //这两行都一样，数组名字就是首元素的首地址

	//printf("%d, %d, %d, %d, %d, %d, %d, %d, %d \n", *p, *(p + 1), *(p + 2), *(p + 3), *(p + 4), *(p + 5), *(p + 6), *(p + 7), *(p + 8));


	//int(*p1)[3] = a;
	//*p1 == a[0];//数组名字就是首元素的首地址
	//a[0][1] == (*p1)[1];
	//*(p1 + 1) == a[1];

	//printf("%d, %d, %d, %d \n", (*p1)[1], a[0][1], *(p1 + 1)[0], p1[1][0]);

	int(*p)[3][3] = &a;

	printf("%d, %d, %d \n", (*p)[2][1], (*p)[2][0], a[2][0]);



	system("pause");
	return 0;
}