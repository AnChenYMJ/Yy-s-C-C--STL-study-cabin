#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int a = -1;

	printf("请录入成绩：");
	scanf_s("%d", &a);

	if (60 > a)      //整个从if到else if到else，是一个完整结构，不要分离，中间可以空格，但不能有内容
	{
		printf("成绩不及格\n");
	}
	else if (60 <= a && 70 > a)   //在这个结构中，跟if else一样是能够嵌套的，注意所属层次
	{
		printf("成绩及格\n");     //对比多个if结构，当截断调试时，else if中间截断将执行截断之上的程序，并跳出到结尾
	}
	else if (70 <= a && 80 > a)  //当多个if被截断时，将不执行程序
	{
		printf("成绩中等\n");
	}
	else if (80 <= a && 90 > a)
	{
		printf("成绩良好\n");
	}
	else if (90 <= a && 100 >= a)                       //else与同层最近的else if相匹配
	{
		printf("成绩优秀\n");
	}
	else
	{
		printf("成绩录入错误！\n");
	}


	system("pause");
	return 0;
}