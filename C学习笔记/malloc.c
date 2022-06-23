#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>//malloc函数要加上这个头文件

int main(void)
{
	int* p = (int*)malloc(4);//malloc是函数，它能在堆区申请一块空间，并将该空间的首地址返回来
			//这里的（int*）是声明返回的地址的数据类型，右边的（4）是申请的空间大小，单位是字节
			//，左边的int *p是将这个地址赋值给int类型的指针 p

			//声明返回地址的数据类型还有别的写法：
	int* p1 = (int*)malloc(sizeof(double)*5);
			//申请了double类型空间（8字节）*5 == 40（字节）的空间
	p1[2] = 15; //遵循下标运算
	printf("%d ", p1[2]);

	int* p2 = (int*)malloc(5.1);//警告：从“double”转换到“size_t”，可能丢失数据
			//size_t == unsigned int  (无符号整型)，就算写小数，c语言会自动转换成无符号的int
			//数据自动转换（如从有符号变成无符号）是c语言定义的合法的，正常的运算。
			//无符号整型的后缀是u，在数字后加u，如：4u
			//看警告时如果不知道是什么，上网查
			//以后编程会经常用到，在32位编译器环境下，4字节，64位编译器环境下，8字节
	int a = sizeof(size_t);
	printf("%d \n", a);


	system("pause");
	return 0;
}