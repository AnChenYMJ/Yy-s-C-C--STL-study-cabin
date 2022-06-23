#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char str1[5] = { 'd', 'f', 'g', 'h', '\0' };
	char str2[5] = { 'd', 'f', 'g', 0 };
	char str3[5] = { 'd', 'f' };  //这三个是有元素个数的字符串，最后一个字符为0，注意别越界

	printf("%s  \n", str3);
	//setbuf(stdin, NULL);

	char str4[5];   //这也是有元素个数的字符串
	//str4 = { 'q', 'w', 'e', '\0' }; //当声明时没有初始化，不能够这样赋值，
	str4[0] = 'q' ;  //声明时如果没有初始化，只能这样一个一个的赋值
	str4[1] = 'w' ;
	str4[2] = 'e' ;
	str4[3] = '\0' ;//注意最后以0结尾,一定要手动添加\0

	printf("%s  \n", str4);


	char str5[] = { 'z', 'x', 'c', 'v', 'b', 'n', '\0' };//这是无元素个数的字符串
		//初始化多少个字符，则有多少个元素，这里有7个元素，注意，一定要手动添加\0
	puts(str5);//这是专属字符串的打印函数


	"hello yy~ try again~";//这是常量字符串
	printf("hello yy~ try again~" );//常量字符串自带\0，hello yy~ try again~'\0' 这是字符串本身
	printf("\n");  //printf（）的第一个参数是char*， 而""就是char*类型
	//printf(2);//这样就不能打印有提示：“const char *const ”与“int”的间接级别不同

	char* p = "hello yy~ try again~"; //常量字符串由两部分组成，字符+""
	//""的作用是把字符串的首地址返回来，就相当于char*，""不是字符串
	//p = 'w';//常量字符串相当于常量，里面的字符是不能修改的
	puts(p);

	p = "adadhfhjj";//指针能修改指向的字符串，但字符串本身不能修改
	printf(p);

	system("pause");
	return 0;
}