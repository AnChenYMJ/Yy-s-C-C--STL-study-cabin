#include <stdio.h>
#include <stdlib.h>


void fun()
{
		printf("Don't waver,Yy, you're strong!\n");
}

struct SM
{
	int a;
	char b;

	void (*p)();//但是我们能通过函数指针来完成添加函数成员的操作

	//void fun()//C语言标准中，不能在结构体里声明定义函数
	//{
	//	printf("Don't waver,Yy, you're strong!");
	//}

};


int main(void)
{	//C语言中使用结构体要加suruct
	struct SM ST = {1, 'Y', fun};//必须要初始化结构体变量，否则函数指针不知道指向那个函数
	ST.p();//这样就能通过指针变相的给结构体添加函数成员
	for (int o = 0; o <= 3; o++)
	{
		for (int i = 10; i >= 5; i--)
		{
			printf("%d \n", i);
		}
	}

	printf("%d \n", i);//error C2065: “i”: 未声明的标识符

	for (int i = 10; i >= 5; i--)
	{
		printf("%d \n", i);
	}

	system("pause");
	return 0;
}