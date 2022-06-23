#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>  //memset的头文件

int main(void)
{
	int a = 12;//这是声明变量，并且初始化赋值

	int* p = malloc(4);//可以不加（int*），VS编译器会强制类型转换，但有的编译器不支持
		//malloc函数申请的空间是不可以直接赋值的
	*p = 12; //一个空间类型可以这样赋值

	printf("%d \n", *p);


	int* p1 = (int*)malloc(40);//当申请的空间变多，上面的一个个赋值的方式就不好使了
	int i;                     //这里使用循环挨个对申请的空间赋值

	for (i = 0; i < 10; i++)
	{
		p1[i] = 0;  //这里的p1[i]是下标运算：地址+[偏移量]
	}

	for (i = 0; i < 10; i++)
	{
		printf("%d \n", p1[i]);
	}


	int* p2 = (int*)malloc(44); //需要赋值为0时，这个比循环要方便一些
	memset(p2, 0, 44);  //这种方式是用函数赋值，头文件为<memory.h>，这个函数是内建函数（编译器带的），为了移植性还是添加头文件
	//但是要注意：这个函数是字节赋值，挨个对44个字节每个赋值为0
	//不能给每个空间赋如3这样的值，因为是挨个字节赋值，一个int类型空间4字节，

	int k = 0;
	for (k = 0; k < 10; k++)
	{
		printf("%d \n", p2[i]);
	}


	system("pause");
	return 0;
}