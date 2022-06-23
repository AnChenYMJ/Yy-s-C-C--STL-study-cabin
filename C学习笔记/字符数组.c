#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char ar[6] = { 'f', 'g', 'h', 'j' };
	int o = 0;

	ar[2] = 'y';//数组的下标运算

	for (o = 0; o < 6; o++)
	{
		printf("%c  ", ar[o]);//当字符数组中一些符号没有给初始值时，系统默认为0
		printf("%d  \n", ar[o]);//而zaiacs2码中，0对应的是NULL，什么也没有，所以在输出字符时，不打印NULL
	}

	int t;
	sizeof(ar);
	t = sizeof(char[6]);
	printf("%d  %d \n", sizeof(ar), t); //输出结果都是6，说明字符数组大小就是元素大小相加


	char arr[5] = { 'q', 'w', 'e', 'r', 49 };//49是字符‘1’的编号
	int i;
	char* ptr = arr;
	for (i = 0; i < 5; i++)
	{							//不能写成*ptr + i, *的优先级比+高，会表达成另一个意思
		printf("%c  ", *ptr++); //*(ptr + i)  ptr[i]  arr[i]
		//* 与 ++ 的优先级别一样，当优先级别一样时看结合性，而*与++对应的结合性从右往左执行
	}

	system("pause");
	return 0;
}