#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int order = -1;

	scanf_s("%d", &order);

	if (1 == order)
	{
		printf("添加一个学生\n");
	}
	else if (2 == order)
	{
		printf("删除一个学生\n");
	}
	else if (3 == order)
	{
		printf("浏览一个学生\n");
	}
	else if (4 == order)
	{
		printf("退出系统\n");
	}
	else
	{
		printf("系统无该指令\n");
	}


	switch (order)      //功能与else if相同，执行顺序：先计算表达式中的值，再按顺序扫描标签
	case 1:
		printf("添加一个学生\n");		//扫描到有匹配的标签，进入执行标签下的代码块，执行到break跳出switch结构
		break;
	case 2:
		printf("删除一个学生\n");
		break;
	case 3:
		printf("浏览一个学生\n");
		break;
	case 4:
		printf("退出系统\n");
		break;
	default:                     //如果没有发现一样的（匹配）的值，执行默认的代码块直到花括号结束
		printf("系统无该指令\n");
	}


	system("pause");
	return 0;
}