#include <stdio.h>
#include <stdlib.h>

int main(void)//原则上，我们C语言根本不需要goto语句结构。C语言中continue和break 
			  //是goto的特殊形式，换句话说，goto的功能完全可以用break和continue代替。
			  //大量的使用goto会使我们的程序结构非常乱，难懂。所以建议不要滥用，
			  //能不用就不用，甚至在C语言中，这种使用goto语句是不被接受的
{
	int i,
		j,
		k,
		a = 1;

step:       //这是一个标签
	a++;
	printf("goto \n");
	if (4 == a)
	{
		goto step1;              //这是利用goto跳转到step1
	}
	goto step;

step1:
	printf("跳到step1了\n");

/////////////////////////////////////
	for (i = 0; i < 2; i++)           //利用goto跳出循环，这是可能被认可的一种用法
	{
		for (j = 0; j < 2; j++)
		{
			for (k = 0; k < 2; k++)
			{
				printf("for循环\n");
				if (1 == k)
				{
					goto step2;
				}
			}
		}
	}

step2:
	printf("跳出循环到step2了\n");
	system("pause");
	return 0;
}