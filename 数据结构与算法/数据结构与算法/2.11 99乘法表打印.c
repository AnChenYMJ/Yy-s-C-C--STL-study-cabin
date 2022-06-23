#include <stdio.h>

//讲解：
//利用循环来打印99乘法表，（课本练习题）
//打印哪个角看i j 的大小关系以及是否用空格来顶
//%dx%d=%2d 中的 %2d 是在控制台占用2位的空间（最高81也是2位），用来对齐乘法表，否则个位如1 ，则会整体向前移，导致对不齐
//乘法表与数组的关系呢，是要我们举一反三，将数组元素（下标）带入到i j中去思考 

//矩阵的99乘法表
void JuZhen99()
{
	for (int i = 1; i <= 9; i++)
	{
		for (int j = 1; j <= 9; j++)
		{
			printf("%dx%d=%2d  ", i, j, i * j);
		}
		printf("\n");
	}
}

//左下角的99乘法表
void ZuoXia99()
{
	for (int i = 1; i <= 9; i++)
	{
		
		for (int j = 1; j <= 9; j++)
		{
			if (i >= j)
			printf("%dx%d=%2d  ", i, j, i * j);
		}
		printf("\n");
	}
}

//左上角的99乘法表
void ZuoShang99()
{
	for (int i = 1; i <= 9; i++)
	{

		for (int j = 1; j <= 9; j++)
		{
			if (i <= j)
				printf("%dx%d=%2d  ", i, j, i * j);
		}
		printf("\n");
	}
}

//右下角的99乘法表
void YouXia99()
{
	for (int i = 1; i <= 9; i++)
	{
		for (int k = i; k < 9; k++)		//使用空格将左下角的乘法表，顶成右下角的形式，
		{								//根据 i 的数值大小决定插入几次空格
			printf("        ");
		}
		for (int j = 1; j <= 9; j++)
		{
			if (i >= j)
				printf("%dx%d=%2d  ", i, j, i * j);
		}
		printf("\n");
	}
}

//右上角的99乘法表
void YouShang99()
{
	for (int i = 1; i <= 9; i++)
	{
		for (int k = i; k > 1; k--)		//使用空格将左下角的乘法表，顶成右下角的形式，
		{								//根据 i 的数值大小决定插入几次空格
			printf("        ");
		}
		for (int j = 1; j <= 9; j++)
		{
			if (i <= j)
				printf("%dx%d=%2d  ", i, j, i * j);
		}
		printf("\n");
	}
}

int main(void)
{
	printf("矩阵的99乘法表：\n");
	JuZhen99();
	printf("\n");

	printf("左下角的99乘法表：\n");
	ZuoXia99();
	printf("\n");

	printf("左上角的99乘法表：\n");
	ZuoShang99();
	printf("\n");

	printf("右下角的99乘法表：\n");
	YouXia99();
	printf("\n");

	printf("右上角的99乘法表：\n");
	YouShang99();
	printf("\n");


	return 0;
}