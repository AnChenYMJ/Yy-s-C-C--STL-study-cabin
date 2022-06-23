#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int a[3][2] = { {4, 5} , {6, 7} , {2, 1} };
	int* p = &a[2][1]; //指针初始化某个元素地址赋值给指针
	int(*p1)[2] = &a[2];  //赋值前的方括号里，是要指向的数组的元素个数，这是一维数组的数组指针声明
	int(*p2)[3][2] = &a;  //这是二维数组的数组指针声明

	printf("%p, %p, %p, %p \n", p, &a[2][1], &(*p1)[1], &(*p2)[2][1]);
	printf("%d, %d, %d, %d \n", *p, a[2][1], (*p1)[1], (*p2)[2][1]);
	//同一个元素的不同表达形式

	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 2; j++)
		{
			printf("%d  ", a[i][j]); //a[i][j] 可以换成(*p2)[i][j],同一个意思（*p2）就是数组a
		}
	}

	system("pause");
	return 0;
}