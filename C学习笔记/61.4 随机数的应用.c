#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{

	int a;
	int i = 0;
	srand((unsigned int)time(NULL));

	while (i < 10)//这是正常的利用系统时间当基准数打印随机数
	{
		a = rand();
		printf("%d \n", a);
		i++;
	}
	//如果我们想打印一个范围内的数呢，比如0~89


	printf("\n");
	i = 0;
	while (i < 15)//这是正常的利用系统时间当基准数打印随机数
	{
		a = rand()%90; //对产生的随机数取余，利用余数就能产生范围内的随机数了
		printf("%d \n", a);//比如这里对90取余，那余数只能在0~89之间
		i++;				//实现了产生固定范围内的随机数
	}


	//如果要打印65~400范围内的随机数呢
	printf("\n");
	i = 0;
	while (i < 16)
	{
		a = rand() % 336 + 65; //对336取余产生0~335的随机数再加上65就变成了65~400
		printf("%d \n", a);
		i++;				
	}


	//如果我们要随机打印一个数组内的元素呢
	printf("\n");
	i = 0;
	int b[12] = { 56, 987, 456, 3254, 1557, 1, 98, 1, 23, 18, 999, 84 };
	while (i < 15)
	{
		a = rand() % 12;//产生了0~11的随机数
		printf("%d \n", b[a]);//再把随机数对应到数组下标就可以了
		i++;				//这样就实现了随机打印一个数组内的元素
	}						


	system("pause");
	return 0;
}