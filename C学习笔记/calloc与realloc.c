#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>//malloc, calloc, realloc的头文件都是<malloc.h>与<stdlib.h>

int main(void)
{
	int* p = (int*)calloc(6, 4);  //与malloc一样，不要越界
	//(6, 4)的意思是申请6个元素的连续空间，每个元素4字节。
	//返回首元素的地址赋值给指针p，此时的指针p是指向首元素的，不是数组指针

	int i;

	for (i = 0; i < 6; i++)
	{
		printf("%d  ", p[i]);//此时输出为6个0，calloc对比malloc，calloc会把元素初始化为0，malloc不会初始化
	}						//遵循下标运算，此时的p是指向首元素的，不是数组指针

	free(p);



	system("pause");
	return 0;
}