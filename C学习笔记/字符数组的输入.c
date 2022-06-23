#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(void)
{
	//char str[15];
	//char srr[5];

	//scanf("%s", str);//scanf是把空格当作分隔符，就不能把空格当作字符输入
	//printf("%s \n", str);//%s会自动给我们输入的字符串加\0

	//scanf("%s", srr);//当我们越界时，会在整个程序结束时报错，这样就不知道究竟具体哪里错误了
	//printf("%s \n", srr);


	//char str1[15];			//可以先打印未初始化的对比越界时的显示，说明执行scanf时%s已经把\0加进去了
	//printf("%s  \n", str1);	//我们越界时，会什么都不显示，这是_s的保护，不显示是因为里面有%s加的\0
	//scanf_s("%s", str1, 14);//比起scanf多了一个参数，就是限制字节大小的参数
	//printf("%s  \n", str1);//注意这个参数要比声明时的元素个数-1，因为%s给我们自动加了\0,
	//						//这个\0已经加进去我们要预留出来


	char str2[16];

	gets(str2); //对比scanf它能输入空格，这个越界时也会结束异常，错误点很难找
	printf("%s  \n", str2);


	char str3[16];

	gets_s(str3, 15); //多了个限制字节参数，有一个预留给了\0，能读空格
	printf("%s  \n", str3);//报错会表明就是这里出问题的，

	system("pause");
	return 0;
}