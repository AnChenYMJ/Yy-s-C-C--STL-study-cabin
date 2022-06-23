#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int a,
		b,
		c;
								  //表达式加分号；就是一条语句，分号；是一条语句的结尾
	c = (b = 2, 8, a = b);
	printf("%d %d %d", a, b, c);  //逗号，是一个运算符，只是级别很低，
								  //逗号运算符从左往右执行，且最右侧的值是表达式的结果
								  //如这里的c则是最右侧a的值2，a被b赋值，b被2赋值，8则无用
								  //逗号表达式的结果是最右侧的值。


	system("pause");
	return 0;
}