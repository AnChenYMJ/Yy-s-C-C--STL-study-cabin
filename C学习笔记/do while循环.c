#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int i = 0;        //c语言是从上到下的执行顺序。

	while (i <= 5)    //入口条件循环：条件设置在循环入口处，且结尾不用加分号 ；
	{
		printf("%d  ", i);    //当条件为0（假）时，不执行
		i++;
	}

	printf("\n");  //换行
	i = 0;         //重置i的值

	do
	{
		printf("%d  ", i);    //当条件为0（假）时，至少执行一次，因为条件判断在结尾
		i++;
	} while (i <= 5);        //推出条件循环，条件设置在结尾处，且必须加分号 ；




	system("pause");
	return 0;
}









