#include <stdio.h>
#include <stdlib.h>

int fun(int* a, int nLength)  //函数就是完成特定任务的程序代码单元
{							  //就是把一个小功能封装成一个独立的代码块
	int i;					  //如这次所示，哪怕有一百个数组都可以复用这个封装好的函数
	int MaxNum = a[0];		  //这就是函数的复用性
	/*int MixNum = a[0];*/		  //通常，会把一个功能封装成一个函数
							  //一个函数尽量就是一个单一的功能，函数的封装无关代码量，有可能就一条函数
	for (i = 0; i < nLength; i++)//所以取最大值与最小值的函数还是尽量分开，虽然我也不知道怎么结合
	{						  //函数能使主逻辑清晰，便于确定问题所在
		if (MaxNum < a[i])	  //使用函数比起直接写代码的运行效率会慢一点，但是很微小
		{					  //满一点点的原因是程序运行到函数时，会跳转到函数位置运行，运行完函数里的
			MaxNum = a[i];	  //代码再跳转到主程序里继续运行下一步
		}
		/*if (MixNum > a[i])
		{
			MixNum = a[i];
		}*/
	}
	return MaxNum;
}

int main(void)
{
	int a[8] = { 1, 8, 56, 98, 45, 12, 44, 52 };
	int b[3] = { 2, 35, 999 };
	int c[5] = { 56, 98, 23, 55, 0 };

	printf("a数组最大值：%d \n", fun(a, 8));
	printf("b数组最大值：%d \n", fun(b, 3));
	printf("c数组最大值：%d \n", fun(c, 5));




	system("pause");
	return 0; 
}