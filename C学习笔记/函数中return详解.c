#include <stdio.h>
#include <stdlib.h>

int fun1(void);
int fun2(void);
int fun3(void);
void fun4(void);  //注意是否有返回值要与定义时相同，否则会报错

int fun1(void)
{
	printf("我是函数fun1 \n");
	printf("我是函数fun1 \n");
	return 3; //终止，当函数程序按顺序执行到return时，直接终止程序跳到函数结尾，
	printf("我是函数fun1 \n");
	return 4;  //可以有多个return 但只执行逻辑顺序中第一个，然后就跳到结尾了
	printf("我是函数fun1 \n");//可以自己截断调试观察程序执行的顺序过程，截断时	F10下一步
	printf("我是函数fun1 \n");
}

int fun2(void)
{
	int a = 32;  //多个return可用在if结构中，那不同的返回值则代表不同的意思
	if (a >= 10 && a <= 20)
	{
		return 0;
	}
	else if (a > 20 && a <= 30)
	{
		return 1;
	}
	else if (a > 30 && a <= 40)
	{
		return 2;
	}
	else
	{
		return 3;
	}
}

int fun3(void)//生成时会提示：不是所有的控件路径都返回值
{			//因为如果当b的值超出判定范围，则就没有了return值，所以会提示
	int b = 24;//else中有else所以能覆盖所有范围

	if (b >= 10 && b <= 20)
	{
		return 0;
	}
	if (b > 20 && b <= 30)//return能简化程序运行效率，当执行return时，就不执行下面的语句了
	{					  
		return 1;
	}
	if (b > 30 && b <= 40)
	{
		return 2;
	}
}

void fun4(void)
{
	printf("我是函数fun4 \n");
	return;   //在无返回值函数中，return就当终止使用，没有别的意义
	printf("我是函数fun4 \n");
}

int main(void)
{
	fun1();

	fun4();

	system("pause");
	return 0; //这里的返回值是操作系统定义的，我们直接使用就好了，意义是程序正常运行
}			  //不是由我们定义的注意