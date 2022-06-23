//#define _CRT_SECURE_NO_WARNINGS   //方法二：使用scanf在下方报错后，会提示这个，把这行代码写到开头，
                                  //不能写在下方，就能解决scanf版本不兼容的问题

#include <stdio.h>
#include <stdlib.h>

#pragma warning(disable:4996)    //方法三：在这个位置写这行代码，后面的4996是报错对应的编号，
                                 //每个报错的编码是唯一的，不会处理报错的话可以把这个编码上网查一下。

int main(void)
{
	int a = 222,
		b = 333;
	
	printf("前：%d %d \n", a, b);

	scanf("%d %d", &a, &b);       //方法一：使用scanf_s,在vs2012版本以上，使用scanf会报错，
	                              //scanf_s是微软为了安全性自己弄的，使用scanf移植性会高很多，因为scanf是标准c的规定

	printf("后：%d %d \n", a, b);

	system("pause");
	return 0;
}