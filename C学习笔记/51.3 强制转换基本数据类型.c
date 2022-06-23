#include <stdio.h>
#include <stdlib.h>

int main(void)
{//显式类型转换包括：1.强制基本数据类型转换。2.指针类型数据转换
	int* p = (int*)malloc(8);
	//这里的（int *）就是强制类型转换，将返回的地址变成int*类型，就代表这个申请的空间是int4字节类型的。
		
	//12 + 12.2;//这样会有隐式转换，把12变成12.0的double类型
	//12 + (int)12.12;//在数据前加小括号与数据类型，就是强制数据类型转换
	//把12.12强制变成int类型的，就是把小数部分直接去掉拿整数12
	printf("%lf, %d \n", 12 + 12.2, 12 + (int)12.12);



	unsigned char c = (unsigned char)2356.9;//截断调试查看结果为52， 2356%256 == 9----52
	//char的范围是0~256，超出的打印则从0开始再来一遍循环，所以超出256的取256的余数就是char的结果了
	unsigned char d = (unsigned char)256;//结果为0
	unsigned char e = (unsigned char)257;//结果为1
	//在数据前加小括号与数据类型，就是强制数据类型转换


	system("pause");
	return 0;
}