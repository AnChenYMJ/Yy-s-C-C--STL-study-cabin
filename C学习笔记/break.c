#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int i = 0;

	for (i = 0; i <= 5; i++)
	{
		printf("%d  ", i);
		break;               //当系统执行到break时停住，跳出循环，
	}


	printf("\n");  //换行
	int k = 0;

	for (k = 0; k <= 5; k++)
	{
		if (k == 3)
		{
			break;     //brerk常常配合if使用，就是在循环中满足if的条件，就执行if的执行语句
		}
		printf("%d  ", k);
	}


	printf("\n");  //换行
	int p ;
	int o ;

	for (p = 6; p >=1; --p)
	{
		printf("%d  ", p);
		for (o = 0; o <= 5; o++)
		{
			printf("%d  ", o);
			if (o == 2)
			{
				break;   //break只是跳出当前循环，
			}
		}
		if (o == 2)    //要想跳出所有循环只能在最外层的循环加上break
		{
			break;     //break最好加上条件，否则是无意义的
		}
		printf("\n");
	}

	//break;             //break只能在循环中使用，不能在循环外使用，VS2019生成会报错

	system("pause");
	return 0;
}