#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int a[3][2] = { 1,2,3,4,5,6 };

	printf("%d, %d, %d, %d, %d, %d  \n", &a[0][0], &a[0][1], &a[1][0], &a[1][1], &a[2][0], &a[2][1]);
	printf("%d, %d  \n", &a[0][0], &a[0][0]+1); //元素地址+1为下一个元素地址

	printf("%d, %d, %d  \n", &a[0], &a[1], &a[2]);
	printf("%d, %d  \n", &a[0], &a[0]+1);//一维数组地址+1为下一个一维数组地址

	printf("%d  \n", &a);          //&a，&a[0]，&a[0][0]，三者地址数值相同，因为都显示的是整个数组的开头
	printf("%d, %d  \n", &a, &a+1);//二维数组地址+1为下一个二维数组地址


	system("pause");
	return 0;
}