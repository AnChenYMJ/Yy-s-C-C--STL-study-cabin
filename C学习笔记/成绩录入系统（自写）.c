#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int i = 0,
		a = 120;

	printf("欢迎使用本系统\n");
	printf("分数范围：0~100\n");

	while(1)  //for (i = 0; -1 <= i; i++)  //其实这里可以用while（1），更简洁的死循环
	{	
		printf("请输入成绩： ");
		scanf_s("%d", &a);      //注意，在写输入代码时，一定要在变量前加取地址符&

		if (-1 == a)
		{
			printf("感谢使用本系统，再见。\n");
			break;
		}

		if (60 > a)
		{
			printf("不及格\n");
		}
		else if (60 <= a && 70 > a)
		{
			printf("及格\n");
		}
		else if (70 <= a && 80 > a)
		{
			printf("中等\n");
		}
		else if (80 <= a && 90 > a)
		{
			printf("良好\n");
		}
		else if (90 <= a && 100 > a)
		{
			printf("优秀\n");
		}
		else if (100 == a)
		{
			printf("超级牛\n");
		}
		else
		{
			printf("输入错误,请重新输入\n");
			continue;     //从这里跳到循环开头重新开始
		}
	}

	system("pause");
	return 0;
}