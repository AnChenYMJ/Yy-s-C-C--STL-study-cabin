#define _CRT_SECURE_NO_WARNINGS   //因为scanf报错的原因，加上这个，或者把scanf改为scanf_s

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int score = -1;  //成绩变量，score：得分。

	printf("录入成绩：");    //输入提示
	scanf("%d", &score);    //输入成绩

	if (score >= 60 && score <= 120 && score >=0)  //条件判断，最高120分，最低0分，60分及格
	{
		printf("分数：%d，成绩及格 \n", score);
	}
	//跳出，程序结束


	system("pause");
	return 0;
}