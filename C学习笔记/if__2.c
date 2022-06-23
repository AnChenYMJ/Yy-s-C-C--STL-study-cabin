#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int a = 65;
	int b = 28;

	if (60 <= a)             //用两个if来判断是否及格，将会判断两次，挨个判断执行
	{
		printf("成绩及格\n");
	}

	if (60 >= a)
	{
		printf("成绩不及格\n");
	}
/////////////////////////////////////if else比两个if运行得更快，因为不用判断两次

	if (60 <= b)                  //用if else来判断，则只判断一次，非上即下的执行
	{
		printf("成绩及格\n");
	}
	else                         //满足条件则执行上面的代码块，不满足则执行下面的代码块
	{
		printf("成绩不及格\n");
	}


	system("pause");
	return 0;
}