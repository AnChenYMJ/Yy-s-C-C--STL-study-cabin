#include <stdio.h>//产生随机数的两个函数的头文件是<stdio.h>
#include <stdlib.h>
#include <time.h>//函数time的头文件

//随机数能在贪吃蛇中随机出现点点的位置，棋牌游戏的洗牌等等
int main(void)
{
	int a;
	int i = 0;

	srand(1);//随机数种子，基准数， 通过这里给定的数，经过算法，给出一个随机数			
	//a = rand();//产生随机数
	//printf("%d \n\n", a);//但是会发现，给的基准数不变的话，产生的随机数也是固定不变的

	while (i <= 10)
	{
		a = rand();//但是会发现，给的基准数不变的话，产生的随机数也是固定不变的
		printf("%d \n", a);//基准数只执行一次就可以了，第二次就以第一次产生的随机数当作基准数
		i++;					//以此类推
	}


	int b;
	printf("\n\n");
	i = 0;		//rand的类型是unsigned int，time的类型是 time_t，所以要强制类型转换
	srand((unsigned int)time(NULL));//time的头文件：<stdio.h>
	while (i <= 10)//这样就使用了当前系统时间作为基准数，因为时间在不停变化的，且不会重复
	{		
		b = rand();
		printf("%d \n\n", b);//基准数只执行一次就可以了，第二次就以第一次产生的随机数当作基准数
		i++;					//以此类推
	}


	system("pause");
	return 0;
}