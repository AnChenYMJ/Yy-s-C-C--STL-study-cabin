#define _CRT_SECURE_NO_WARNINGS  //setbuf需要这个宏声明
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>


int main(void)
{
	char c;
	int d;

	scanf_s("%c%d", &c, 1, &d);//scanf_s("%c%d", &c, &d);的写法引发异常，原因是格式错误，要添加限制参数
			//这里的1是表明输入的c的类型的数量，这里为1字符，就是最多输入1字符的c类型
			//因为c语言没有边界检测，有时候把很多字符串塞进很小空间的数组里
			//scanf_s就是为了安全性而诞生的函数，那个1，就是代表输入的字符个数
	printf("%c, %d\n", c, d);
	setbuf(stdin, NULL);    // 回车后清空缓冲区

	//char a[20];
	//scanf("%s", &s, 19);//这是字符串输入的格式，19就是字符串数组元素个数-1.


	char f,
		 g;

	f = getchar();//getchar的作用就是在控制台输入一个数或字符，把这个数返回给变量，我们可以截断调试看变量的值
	//g = getchar();//与scanf一样，不清空缓冲区的话，会把回车或空格当作字符被读取
	printf("%c \n", f);
	//while ((f = getchar()) != '\n' && f != EOF);//EOF代表缓冲区结尾，就是什么都没有
	//这个语句是通用语句，在不同编译器或者操作系统都能通行，可拆分同理为下列所示：
	while (1)
	{
		char c1;
		c1 = getchar(); //就是让字符变量c1不断挨个被赋值，直到缓冲区被清空，那些字符赋值之后就释放了
		if ('\n' == c1 || EOF == c1)  //当c1为回车或者结尾时（什么都没有），跳出循环，清空完毕
		{
			break; //跳出循环
		}

	}		
	f = getchar();

	printf("%c \n",f);


	char p;
	while (1)
	{
		p = _getch(); //_getch的工作原理是在工作台输入一个数到缓冲区，然后就直接读取了，写一个读取一个
				  //如果不打印的话，就不会在控制台显示出来，以后在游戏贪吃蛇中会常用到，因为写一个就立马反应
		printf("%c \n", p);//_getch在控制台写入一个数到内存中，然后直接赋值给变量
	}


	system("pause");
	return 0;
}