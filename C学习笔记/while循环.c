#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int i = 0;

	while (i <= 5)    //while ：循环的关键字，从这里判断条件是否满足，满足则进入执行，
		         //执行后再回来进行判断条件是否满足，直到不满足条件，跳出循环。
	{                         //通常计算机里，1（非0）代表真，0为假，执行循环时满足条件为真，不满足条件为假
		printf("%d   ", i);   //打印当前值
		i++;                  //当前值自动加1
	}                         //再返回判断，直到i>5


	int k = 1;
	printf("\n");            //换行

	while (k <= 6)           //while循环下只会执行while下第一条语句，
		printf("%d   ", k++);    //想要在while循环中执行多条语句，必须用{}括起来
	    printf(">>");            //这行只执行一次没有进入循环，想要执行多行必须用{}括起来


	int o = 2;
	printf("\n");
	                          //；前面可以什么都没有,算空语句
	while (o <= 7)            //while 后面不用跟 ; 只有一个语句后面才跟；  
	{
		printf("%d ", o++);         //同一层次记得要缩进，提高可读性，增加自己编程规范
		printf("》》");             //缩进的方法：在代码开头按TAB建，或选中单行或多行按TAB键
	}								//取消缩进：选中shift+TAB键
	

	system("pause");
	return 0;
}