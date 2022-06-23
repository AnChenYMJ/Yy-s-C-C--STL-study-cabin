#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int i = 6;

	for (i = 6; i >= 1; i--)
	{
		printf("前半句  ");
		continue;               //continue:持续，执行到这个语句则立马执行下一次循环
		printf("后半句 \n");    //执行的下一次循环是当前所在循环，不是所有循环
	}


	int k = 20;  //目标：倒着打印20~1的奇数或偶数

	for (k = 20; k >= 1; k--)
	{
		if (k % 2 == 0)     //偶数对2取模（余）为0，想要打印偶数则设置条件 k%2 != 0
		{			
			continue;       //遇到偶数跳过打印执行下一次循环
		}					//continue是跳出当前循环，且只能在循环中使用
		printf("%d ", k);
	}

	system("pause");
	return 0;
}