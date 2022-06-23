#include <stdio.h>
#include <stdlib.h>


int main (void)
{
    int a = 123;

    //&a：  &a  是取变量a的地址，每个变量都有自己唯一的地址
    printf("%p \n", &a);     //%p ：是以地址形式（16进制）输出，
    printf("%#p \n", &a);    //%#p：是在地址前面加上前缀0X输出


    //&a  是一个表达式   2+3 是一个表达式，每个表达式有一个结果
    //&a；是一个语句     2+3； 是一个语句，在表达式加分号就是语句

    system ("pause");
	return 0;
}