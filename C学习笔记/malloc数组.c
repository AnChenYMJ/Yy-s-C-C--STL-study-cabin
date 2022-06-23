#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>  //memset的头文件

int main(void)
{
	int* p = (int*)malloc(sizeof(int) * 5);//可以写成sizeof（4），这都可以的，不过直接写类型名会更直观

	int a[5];      
	int* p1 = &a[0];//数组指针的声明


	int i = 0;
	for ( i = 0; i < 5; i++)
	{
		printf("%d  ", *(p + i));
	}

	printf("\n"); //换行

	memset(p, 0, 20);
	for (i = 0; i < 5; i++)
	{
		printf("%d  ", *(p + i));
	}

	free(p); //free不论你是什么类型的，通过首地址查到就释放


	unsigned int b;
	int* p2;

	scanf_s("%u", &b); //无符号的类型用%u
	p2 = (int*)malloc(b);

	free(p2);
	printf("\n");


	//const int c = 13;//VS系列的编译器不通过 是变长数组的写法
	////scanf_s("%d", c);	/大部分的编译器都不通过
	//int d[c];

	/*int e = 13;  //一样，大部分编译器不通过，还是使用malloc这种通用的方便
	scanf_s("%d", &e);     //使用意义与上面的malloc一样：通过变量改变数组大小
	int f[e];*/

	system("pause");
	return 0;
}