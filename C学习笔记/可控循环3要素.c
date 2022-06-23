#include <stdio.h>
#include <stdlib.h>

int main(void)
{							//循环控制变量：参与到循环中的变量
	int i = 0;              //要素1：循环控制变量要有初始值

	while (i <= 5)          //要素2：条件中要有循环控制变量参与
	{
		printf("%d  ", i);  //要素3：循环控制变量有规律的值的变化
		i++;
	}

	system("pause");
	return 0;
}