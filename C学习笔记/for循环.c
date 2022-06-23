#include <stdio.h>
#include <stdlib.h>

//实现功能的思路
//分析功能，实现功能
//比如开平方，搜索靠平方函数aqrt（上网搜）
//1，返回值，参数。  2，搜索对应头文件math.h。


int main(void)
{
	int i ;
								//for循环的括号里，刚好对应可控循环的三要素
	for (i = 0; i <= 5; i++)    //循环控制变量的初始化；循环执行条件；循环控制变量值的变化
	{
		printf("%d  ", i);      //执行顺序是这样：语句1 》语句2 》执行程序 》语句3 》语句2
	}

	int o = 0;                  //对比for循环，while有个缺点，
	printf("\n");  //换行

	while (o <= 5)				//如果执行的语句过多，可能不容易找到循环控制变量值的变化语句
	{
		printf("%d  ", o);










		o++;
	}

	int p;
	printf("\n"); //换行

	for (p = 9; p >= 1; p /= 2)   //vs2013与2015能在语句1中定义变量(int p = 9;)
	{								//执行顺序要记住，语句2>执行程序>3>2
		printf("%d  ", p);
	}

	printf("i= %d ", p);   //因为最后p变为0跳出了for循环，所以要打印0，就单独打印


	system("pause");
	return 0;
}