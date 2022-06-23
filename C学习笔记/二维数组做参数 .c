#include <stdio.h>
#include <stdlib.h>
//这里的形参也可以写成(*p)[3][2]
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
{		//第一个元素的地址，从这个地址往下读取遍历
	int i;//虽然是二维数组，但空间是连续紧挨的，所以使用这种方式也能成功
	for (i = 0; i < hang * lie; i++)
	{			//这样也实现了遍历二维数组
		printf("%d, %d \n", p[i], sizeof(p));
	}
}

void fun3(int(*p)[3][2], int hang, int lie)
{
	int i, j;
	for (i = 0; i < hang; i++)
	{
		for (j = 0; j < lie; j++)
		{//因为输入的是二维数组的地址所以*p就是二维数组本身
			printf("%d, %d \n", (*p)[i][j], sizeof(p));
		}
	}
}

int main(void)
{
	int a[3][2] = { {3, 2}, {5, 4}, {8, 7} };
	int(*p)[2] = a;//数组名字就是首元素的地址，二维数组的首元素是一个一维数组，
	fun1(a, 3, 2);//一维数组的指针类型就是int(*p)[]
	fun2(&a[0][0], 3, 2);
	fun3(&a, 3, 2);//直接输入二维数组的地址

	system("pause");
	return 0;
}