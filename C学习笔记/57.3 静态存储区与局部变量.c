#include <stdio.h>
#include <stdlib.h>

			//静态变量存储在：静态区/静态全局区/静态存储区
int a;		//生命周期：与程序共存亡，只有程序结束了，静态变量的空间才得以释放
int b[6];	//在程序运行时，加载资源阶段申请静态变量的空间
char c;		//加载资源阶段不是编译阶段，编译阶段还没开始运行程序
int* p;		//就像游戏开始时会加载游戏资源，那个时期就是加载阶段，加载程序运行必要的资源 
			//具体过程不清楚，但大概就是加载的意思

struct STR
{
	int a;
	double b;
	char c;
	float f;
}abcf;


int o = 12;//全局变量的初始化只能用常量来初始化


int* d = (int*)malloc(8);//在全局位不能写执行语句，会报错
printf("%d \n\n", a);	 
int f = a + 1;			//在全局位，全局变量不能进行变量给变量的赋值，只能用常量赋值


int main(void)
{
	printf("%d \n\n", a);
	printf("%d, %d, %d, %d, %d, %d \n\n", b[0], b[1], b[2], b[3], b[4], b[5]);
	printf("%c \n\n", c);
	printf("%d \n\n", a);//全局变量存储在静态区，与程序共存亡
	printf("%p \n\n", p);//生命在全局区的变量叫做全局变量，会发现，全局变量会自动初始化为0

	printf("%d, %lf, %c, %f \n\n", abcf.a, abcf.b, abcf.c, abcf.f);
						//以上打印的都初始化为0了


	
	int a = 45; //全局变量全局都有效，但在局部有重名的变量时，在那个局部以局部变量为准，类似于57.2的变量a的测试
	printf("%d \n\n", a);//这里就是局部变量a，操作的也是局部变量a而不是全局变量

	system("pause");
	return 0;
}