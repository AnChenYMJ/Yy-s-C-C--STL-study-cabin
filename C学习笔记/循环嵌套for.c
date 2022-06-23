#include <stdio.h>
#include <stdlib.h>

int main(void)         //入口条件循环：条件判断设置在循环入口处
{
	int neiCount = 0;  //内循环次数变量
	int waiCount = 0;  //外循环次数变量
	int nCount = 0;  //计数器，count：计数， 这只是一个变量名，可以换成其他的字母或单词，count方便记忆
	int i;			   //外部循环控制变量
	int k;			   //内部循环控制变量
	for (i = 0; i <= 5; i++)            //外部循环要经历6次，分别为012345，6跳出不循环
	{
		waiCount++;                     //外部循环次数
		printf("外部循环 %d \n", waiCount);
		for (k = 0; k < 3; k++)         //内部循环要经历3次，0一次，1一次，2一次，3跳出不循环
		{
			nCount++;                   //这样的话打印的次数就打印了18次，6*3=18，每次外部循环内循环都要重新开始
			printf("次数：%d \n", nCount);
			printf("内部循环 %d \n", ++neiCount);//内部循环次数
		}
	}

	int a = 0;
	int b = 0;
	int c = 0;

	while (a <= 3)
	{
		//int b = 0;               
		while (b <= 2)
		{
			b++;
			c++;                             //注意，这样写内循环只执行了3次，
			printf("while次数： %d \n", c);  //因为变量b的定义初始化在整个循环之外
		}									 //导致内循环过后b的值没有从头开始，执行外循环时
		a++;                                 //内循环就不执行了，所以要在循环内给b定义初始化
	}


	int d = 1;
	int dcount = 0;

	for (d = 1; d <= 3; d++)
	{
		for (d = 1; d <= 3; d++)
		{
			dcount++;								//内循环过后d=4，再经过外循环d=5，就跳出整体循环了
			printf("相同变量的次数 %d \n", dcount);  //结果显示为3次，
		}											//因为内外循环使用了相同循环控制变量
	}
	system("pause");
	return 0;
}