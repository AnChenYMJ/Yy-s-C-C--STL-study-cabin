#include <stdio.h>
#include <stdlib.h>

void fun1(void);
void fun2(void);
void fun3(void);
void fun4(void);
void fun5(void);
void fun6(void);
void fun7(void);// 一个函数可以有多个声明
void fun7(void);// 一个函数可以有多个声明
void fun7(void);// 一个函数可以有多个声明
void fun8(void);


void fun1(void)
{
	printf("我是函数fun1 \n");
	fun2();
}

void fun2(void)
{
	printf("我是函数fun2 \n");
	fun1();
}


void fun3(void)
{
	printf("我是函数fun3 \n");
	fun3();
}


void fun4(void)
{
	fun4();
	printf("我是函数fun4 \n");
}


void fun6(void)
{
	//函数定义的实体里可以没有任何东西，是没有任何问题的。
}

void fun7(void)
{
	printf("我是函数fun7 \n");
} 

void fun8(void)//一个函数只能有一个定义
{
	printf("我是函数fun8 \n");
}

void fun8(void)//一个函数只能有一个定义
{
	pritf("我是函数fun8 \n");
}
int main(void)
{
	//fun1(); //结果是反复打印我是函数fun1，我是函数fun2，这是相互调用
	//因为程序先执行进入fun1打印1后因为调用fun2进入fun2，打印2后又因为调用fun1进入fun1，陷入死循环

	//fun3(); //这是自己调用自己，结果是反复循环打印3，

	//fun4();//调试直接报错，提示：Stack overflow （爆栈）
	//因为执行fun4函数时，从上往下执行，而自身调用在打印语句前面，导致反复调用自己，导致爆栈

	//fun5();//生成时警告：: 无法解析的外部符号 _fun5，函数 _main 中引用了该符号
		//意思是这个函数没有实体，只是声明了，但没有定义，

	fun6();//这个函数的定义里没有实体，就是没有代码，运行调试没有任何问题，不过没有意义

	void fun7(void);// 一个函数可以有多个声明
	fun7();//这个函数有多个声明，一个定义，完全正常运行

	fun8();//这个函数有多个定义，提示： 函数“void fun8(void)”已有主体， 参见“fun8”的前一个定义
	//一个函数只能有一个定义，多了调试会报错

	system("pause");
	return 0;
}