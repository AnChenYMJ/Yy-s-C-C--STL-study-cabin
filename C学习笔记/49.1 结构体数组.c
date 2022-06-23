#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct wzry
{
	char truename[10];
	int age;
};


int main(void)
{		//这是结构体数组的声明初始化方式，不同变量用花括号隔开能更清晰，还可以部分初始化
		//不用花括号隔开的话就会像二维数组一样挨个赋值，容易导致类型不同的报错
	struct wzry fs[3] = { {"不知火舞", 24}, {"小乔"}, {"妲己", 4000} };
	printf("姓名： %s\n年纪： %d\n\n", fs[0].truename, fs[0].age);
	printf("姓名： %s\n年纪： %d\n\n", fs[1].truename, fs[1].age);
	printf("姓名： %s\n年纪： %d\n\n", fs[2].truename, fs[2].age);


	strcpy(fs[1].truename, "大头老太");//结构体数组的字符串赋值方式，注意strcpy是字符串的赋值方式
	printf("姓名： %s\n年纪： %d\n\n", fs[1].truename, fs[1].age);


	fs[1] = (struct wzry){ "装嫩太婆", 40 };
	printf("姓名： %s\n年纪： %d\n\n", fs[1].truename, fs[1].age);


	system("pause");
	return 0;
}