#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int i = 1;

	while (i <= 5)
	{
		printf("%d  ", i);
		i++;
	}
		

	int k = 1;
	printf("\n");    //换行

	while (k <= 5)
	{		//通常计算机里，1（非0）代表真，0为假，执行循环时满足条件为真，不满足条件为假
		printf("%d  ", k <= 5); //此时输出的都为1（真），都满足条件
		k++;
	}
	printf("%d  \n", k <= 5); //此时输出为0（假），此时的k经过循环跳出为6，不满足条件


	
	printf("%d  \n", 3 < 5); //1（真）
	printf("%d  \n", 3 > 5); //0（假）
	printf("%d  \n", 3 == 5);//0   == :等于
	printf("%d  \n", 3 != 5);//1   != :不等于
	printf("%d  \n", 3 <= 5);//1  
	printf("%d  \n", 3 >= 5);//0


	//while (3)    //非零即为真，这样会陷入死循环，
	//{            //在死循环界面CTRL+C退出死循环
	//	printf("%d   ", i);
	//	i++;
	//}

	int p = 2;
	printf("\n");

	//while (p <= 7 && p > 1 || p >= 3)    //陷入死循环了，&&比||优先级高，这样总体就成了（真）,并且前两个条件无法跳出
	//while (p <= 7 || p > 1 || p >= 3)    //死循环，||（或），无法跳出条件，
	//while (p <= 7 && p > 1 && p >= 3)    //无法启动，&&（与），无法达成条件
	while ( !3 )                           //五大启动，!（非），条件为非真（假）
	{
		printf("%d  ", p++);
	}

	system("pause");
	return 0;
}