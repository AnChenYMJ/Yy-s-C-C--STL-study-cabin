#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

int main(void)
{
	int a[6] = { 1,2,3,4,5,6 };
	//int b[6] = a[6];  错误写法
	//int b[6] = { a };  错误写法，这是将字母a当作数组b的元素

	/*int b[6];   错误写法
	b = a;*/

	int b[6];
	int i = 0;                //这是一种正确的写法，利用循环挨个赋值

	for (i = 0; i < 2; i++)
	{
		b[i] = a[3+i];        //也可以定向赋值
	}

//////////////////////////////////////
							  //还有一种方式为命令赋值
	int c[5];

	memcpy(&b[0], &a[0], sizeof(int) * 6);//这是全部赋值，memory copy:内存拷贝
	//&b[0]指的是从数组b的第一个元素开始赋值
	memcpy(&c[0], &a[3], sizeof(int) * 3);//这是部分赋值，最后的3是要赋值的元素个数，注意不要越界
	//&a[3]指的是从数组a第四个元素开始拷贝
	//sizeof(int)是指int类型的字节大小，int类型为4字节，
	//也可以直接用4代替字节大小，但是表达得不够准确，可能容易出错

	system("pause");
	return 0;
}