#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

//分析：
//1.提示欢迎
//2.开始，循环
	//2.1输入一个数
	//2.2检测这个数
	//2.3 输入-1退出
	//2.4检测输入分数，不合法就重新输入
	//2.5分数分级


int main(void)
{
	int i = -1;

	printf("欢迎使用本系统\n");
	
	while (1)
	{
		printf("请输入成绩:\n");
		scanf("%d", &i);

		if (-1 == i)
		{
			break;       //这段if要在非法输入前面，否则会执行非法输入的提示。
		}

		if (i > 100 || i < 0)
		{
			printf("输入数值非法，请重新输入0~100的数值\n");
		}

		if (0 < i && 60 > i)
		{
			printf("不及格\n");
		}
		else if (60 <= i && 70 > i)
		{
			printf("及格\n");
		}
		else if (70 <= i && 80 > i)
		{
			printf("中等\n");
		}
		else if (80 <= i && 90 > i)
		{
			printf("良好\n");
		}
		else if (90 <= i && 100 > i)
		{
			printf("优秀\n");
		}
		else if (100 == i)
		{
			printf("超级牛\n");
		}
		
	}
	printf("系统关闭，感谢您使用本系统，有缘再见~\n");


	system("pause");
	return 0;
}