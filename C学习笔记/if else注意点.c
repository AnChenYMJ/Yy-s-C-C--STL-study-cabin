#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int a = 60;
	int b = 75;

	if (60 <= a)       //注意不能加分号
	{
		printf("成绩及格\n");
	}
	else               //注意不能加分号，且else必须紧靠着if，之间不能有语句（可以但不建议空行），否则无法识别
	{                  //else后面是没有条件判断的
		printf("成绩不及格\n");
	}
///////////////////////////////

	//if ()          //if else是能够嵌套的，if下能嵌套if else，else下也能嵌套if else
	//{
	//	if ()		//注意要分清if else的匹配是否正确，相同层级的else与挨着的if是匹配的
	//	{			//只要执行了if那else是不会看的

	//	}
	//	else
	//	{

	//	}
	//}	
	//else
	//{
	//	if ()
	//	{

	//	}
	//	else
	//	{

	//	}
	//}

	if (60 <= b)
		if (60 <= b)     
			printf("成绩及格1\n");         //不加花括号时，else与同层就是离else最近的if匹配
		else  
			printf("成绩不及格1\n");		  //敲代码时建议加花括号跟缩进，否则难以区分谁与谁匹配

	if (2 < 3)   //if中else 与if的条件可以是相同的
	{
		printf("66");  //但是只执行一个，因为else if语句中，执行到第一个真，别的他就都不看了，跳出结构
	}
	else if (2 < 3)
	{
		printf("55");
	}

	system("pause");
	return 0;
}

