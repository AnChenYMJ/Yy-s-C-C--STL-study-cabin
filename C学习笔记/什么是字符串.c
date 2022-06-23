#include <stdio.h>
#include <stdlib.h>

void OutString(char* arr)//自定义输出字符串
{
	for (arr ; *arr != '\0'; arr++)
	{
		putchar(*arr);//arr是字符数组的指针，*arr就是字符数组本身
	}			//*arr++：++比*先跟arr结合//putchar一次输出一个字符串
	putchar('\n');
}

int main(void)
{
	char str[6] = { 'a', 's', 'd', 'f', 'g', 'h' };//这是一个纯字符数组
	char str1[6] = { 'a', 's', 'd', 'f', 'g', '\0' };//这是一个字符串
	char str2[6] = { 'a', 's', '\0', 'f', 0 };		 //这是一个字符串，0 就是'\0'的编号，就是NULL
	char str3[6] = { 'a', 's', 'd' };				 //这是一个字符串，asc2码的第一个就是'\0'
			//未定义的剩余元素默认为0		//以'\0' （0）结尾的字符数组就是字符串

	printf("%s  \n", str1);//%s输出字符串的原理：从给的地址开始依次输出，直到遇到0('\0')结束
					//这里的str1就是给定的地址：数组名字就是首元素的地址
	printf("%s  \n", &str1[1]);  //记得加取地址符
	printf("%s  \n", &str2[0]);//这个数组只打印到s，因为遇到0了，

	printf("%s  \n", &str[0]);//如过没有0就继续越界打印，停不下来，直到不知哪个空间遇到0结束


	puts(&str1[0]);//这是专门打印字符串的函数，字符串专属
	//printf("%s %d %c \n", str1[1]);//printf能输出好几种形式的数

	OutString(&str1[0]);//或str1  这是自定义函数，自定义输出字符串，了解输出字符串本质后
					//就有很多方法去输出
	system("pause");
	return 0;
}