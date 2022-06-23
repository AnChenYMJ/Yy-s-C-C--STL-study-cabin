#include <stdio.h>
#include <stdlib.h>


void fun(int n)
{
	if (n > 0)  //在递归函数的笔记中已经说过，打印结果为：5 4 3 2 1 1 2 3 4 5
	{
		printf("%d  ", n);//在下方我们把他展开来看具体的运行过程，
		fun(n - 1);
		printf("%d  ", n);//注意：展开的代码不能执行，函数里不能定义函数，所以只是方便理解用的，
	}					  //老师使用word能标注颜色，我就直接写在这里吧
}

void fun(int n)//此时n == 5
{
	if (n > 0)//5 > 0 进入 
	{
		printf("%d  ", n);//打印n，n == 5
		void fun(int n)//执行n-1
		{
			if (n > 0)//4 > 0 进入
			{
				printf("%d  ", n);//打印n，n == 4
				void fun(int n)//执行n-1
				{
					if (n > 0)//3 > 0 进入
					{
						printf("%d  ", n);//打印n，n == 3
						void fun(int n)//执行n-1
						{
							if (n > 0)//2 > 0 进入
							{
								printf("%d  ", n);//打印n，n == 2
								void fun(int n)//执行n-1
								{
									if (n > 0)//1 > 0 进入
									{
										printf("%d  ", n);//打印n，n == 1
										void fun(int n)//执行n-1
										{
											if (n > 0)//0 ！> 0 进不去
											{
												printf("%d  ", n);//不执行
												fun(n - 1);		  //不执行
												printf("%d  ", n);//不执行
											}
										}
										printf("%d  ", n);//从这开始往下执行打印，n == 1
									}
								}
								printf("%d  ", n);//n == 2
							}
						}
						printf("%d  ", n);//n == 3
					}
				}
				printf("%d  ", n);//n == 4
			}
		}
		printf("%d  ", n);//n == 5
	}					
}

//以上就是方便我们记忆的流程，就是执行到n-1，进入在进入，到最后n==0时，又从里往外执行下半边代码
//最后就变成了5 4 3 2 1 1 2 3 4 5

int main(void)
{
	fun(5);


	system("pause");
	return 0;
}