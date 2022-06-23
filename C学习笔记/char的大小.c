#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char c = 'H';
											  //char是字符类型
	printf("%d, %u", sizeof(c), sizeof(char));//char类型的大小为1字节

		//char类型的范围：-128~127,(-2^7~-2^7-1),无符号的范围：2^8-1(255)
		//在asc2码表中，有些预留的是暂时还没有给定义的负号，是留着以后有需求再填入的
		//中文字符asc2码表示不完，所以有别的码表


	system("pause");
	return 0;
}