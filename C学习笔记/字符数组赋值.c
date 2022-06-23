#define _CRT_SECURE_NO_WARNINGS//strcpy不安全提示要加这个宏，
//strcpy会把多数量字符串赋值给空间小的字符数组，造成内存越界，所以我们要手动确定字符数组的大小
#include <stdio.h>
#include <stdlib.h>
#include <string.h>  //strcpy的头文件


int main(void)
{
	char str1[7] = "hello~";

	char str2[5] = "worl";
	char* p = str2;

	printf("%s  \n", str1);

	int i = 0;
	for (; *p != '\0'; p++)  //因为不能在初始化之外直接赋值，所以要一个个的赋值，所以利用循环
	{
		str1[i] = *p;   //注意我们操作的是栈区的空间，就是字符数组，不是常量字符串
		i++;
	}
	str1[i] = '\0';//在循环中没有把最后的\0也赋值过去，所以要在循环外手动添加

	printf("%s  \n", str1);


	char str3[30] = "hello~ yy";
	char str4[] = "world~ its beautiful!";

	strcpy(str3, str4);//这个函数是将第二个参数的字符串赋值给第一个参数
	//所以第一个参数必须是字符数组，第二个参数可以是常量字符串
	//因为可能将字节量大的字符串赋值给空间小的字符数组，容易越界，头文件：string.h
	//所以第一个参数空间要 >= 第二个参数字节大小
	printf("%s  \n", str3);

	strcpy(str3, "world~ its beautiful!！！");//第一个参数必须是字符数组，第二个参数可以是常量字符串
	printf("%s  \n", str3);


	char str5[10] = "hello~ yy";
	char str6[30] = "world~ its beautiful!";

	strcpy(str5, str6);//不知道我为什么运行没有报错，多字节赋值给小空间会在所有执行结束时报错
	printf("%s  \n", str5);//这样的错误要是有很多行代码时，就难找错误在哪里


	char str7[10] = "hello~ yy";
	char str8[30] = "world~ its beautiful!!";

	strcpy_s(str7, 30, str8);//strcpy_s相比strcpy多了一个参数，就是表明第一个参数的字节大小
	printf("%s  \n", str7);//作用是赋值时最大装到那个字节就结束了，目的是防止越界
							//且如果运行出错会表明就是这一行出错


	char str9[10] = "hello~ yy";
	char str10[30] = "world~ its beautiful!!";

	strncpy(str9, str10, 5);//参数三表示，指定赋值多少个字符，用替换更准确，就是替换多少个字符
	printf("%s  \n", str9);


	char str11[10] = "hello~ yy";
	char str12[30] = "world~ its beautiful!!";

	strncpy(str11,30, str12, 5);//参数二表示指定第一个参数的字符数组的字节大小
	printf("%s  \n", str11);//参数三表示，指定赋值多少个字符，用替换更准确，就是替换多少个字符
				//且所有加_s的函数都是微软定的更安全的函数，不是c语言标准的
		        //且如果运行出错会表明就是这一行出错

	system("pause");
	return 0;
}