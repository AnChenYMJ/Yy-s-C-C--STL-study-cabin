#include <stdio.h>
#include <stdlib.h>

void fun1(int* p, int nLength)
{
	int i;//这里的第二个参数可以不用变量表示，下面用到数组时不同的数组每次都要修改元素个数，很麻烦
	for (i = 0; i < nLength; i++) //注意for循环的条件间用分号隔开
	{
		printf("%d, %d \n", p[i], sizeof(p));
	}
}

		//在形式参数里，这里的p1[2536]C语言不论写多少元素个数只要是p1[]形式的，都认为是*p指针类型
void fun2(int p1[2536], int nLength1)
{		//后面的参数可认为是数组的元素个数或者连续的内存空间长度，
	int j;
	int k[200];
	int kw = sizeof(k);
	printf("%d \n", kw);  //与下面的输出p1的大小做对比就能看出，p1是指针，而这里的k是数组
	for (j = 0; j < nLength1; j++)
	{
		printf("%d, %d \n", p1[j], sizeof(p1));//这里输出p1的字节大小就能证明
	}
}

int main(void)
{
	int a[9] = { 9, 8, 7, 4, 5, 6, 3, 2, 1 };
	fun1(a, 9); //数组名字就是元素的首地址

	int b[5] = { 2, 5, 8, 7, 4 };
	fun1(&b, 5); //这也表示数组的首地址

	int c[3] = { 9, 6, 3 };
	fun1(&c[0], 3);//这也表示数组的首地址

	int d[4] = { 7, 4, 1, 2 };
	fun2(d, 4);

	system("pause");
	return 0;
}