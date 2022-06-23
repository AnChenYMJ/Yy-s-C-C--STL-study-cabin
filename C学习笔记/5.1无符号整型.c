#include <stdio.h>
#include <stdlib.h>

int main(void)
{

	unsigned int a = 3147483648;   //unsigned int 是无符号整型的声明，范围是0-4294967295,所占内存为4字节

	printf("%u \n", a);             //%u:表示10进制无符号整型的输出，
	                                //%d再没超出范围时与%u输出一样，超出范围后结果就不同了，用对应的不要混用
	printf("%u \n", sizeof(unsigned int));   //sizeof()  括号里的不能省略，

	system("pause");
	return 0;
}