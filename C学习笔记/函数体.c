#include <stdio.h>
#include <stdlib.h>

		//括号里不写void表示参数个数不确定，写了表示不接受任何参数
void fun() {printf("我是函数fun \n");}	//函数可以这样写，这是合法的形式，在语句少的时候还能分辩，但语句一多就难以阅读了
	//函数实体部分要用花括号括起来
	//这是我们写的自定义函数，与主函数一样的，只是主函数是系统调用的
	//以后会学到很多系统函数，系统函数如printf，scanf是微软的人定义的，与我们写的没区别
	//不过我们能直接调用，以后会学到很多系统函数
int main(void)
{

	fun(123); //这是演示加参数的情况


	system("pause");
	return 0;
}