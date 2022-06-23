#include <stdio.h>
#include <stdlib.h>


int main(void)
{
	
	int a = 123;
	
	printf("前：%d\n", a);
	
	scanf_s("%d", &a);        //这是变量输入的格式，后面一定要跟变量地址，否则无法输出
	                          //%d 这个一定要与变量格式相对应，否则会出错，在运行界面输入后回车确认
	                          //scanf_s中 整型输出后不要加 \n 否则会无法输入一直换行。
	printf("后：%d\n", a);

	int b = 223,
		c = 333,
		d = 443,
		e = 555;

	printf("前： %d %d %d %d \n", b, c, d, e);    //这里要注意，想要几个数，就必须对应几个输出
	
	printf("请输入：  \n");                       //如果需要输入提。示的话，可以利用printf来搭配使用

	scanf_s("%d %d,%ddsds%d", &b, &c, &d, &e);    //变量输入间，“”里相互间用什么隔开控制台里就必须用什么隔开，否则后面的数将输入失败。 
	                                              //在vs2019版本中，scanf变成了scanf_s;
	printf("后： %d %d %d %d \n", b, c, d, e);

	system("pause");
	return 0;
}