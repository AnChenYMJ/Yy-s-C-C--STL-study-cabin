#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int order = -3;

	scanf_s("%d", &order);

	switch (order) //这行叫整型表达式     //注意这里无分号，变量值那里不要进行范围限定，否则值会变成0（假）与1（真）
	{                  //这里的值不可以是浮点型，必须是整型，if结构可以是浮点型
	case 1:               //case 与标签1之间要有空格，且标签后跟的是冒号：
		printf("添加一个学生\n");
		break;            //break是必不可少的，否则将会继续执行下一个命令
	case 2:
		printf("删除一个学生\n"); //可以嵌套在循环中，且break只跳出当前结构，就是switch结构
		break;
	case 3:  //这行叫：整型常量表达式
	{   
		int a = 5;    //在case里定义变量，需要加花括号
		printf("查看一个学生\n");
	}
		break;
	case 4:
		printf("退出系统\n");
		break;
	default:                      //default在switch结构中不是必要的，
		printf("系统无该指令\n");  //最后一个语句break不用写了，因为到这里就跳出结构了
	}
		
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