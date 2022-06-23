#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int a = 55;
	int b = 65;

	if (60 <= a)
	{
		printf("成绩及格\n");
	}
	else            //if else与条件运算符对比，条件运算符可能会写出更简洁的代码
	{               //当if else短时，使用条件运算符可能会更简洁，
		printf("成绩不及格\n");
	}
	         //条件运算符是c语言为if else提供的简写模式
	60 <= b ? printf("成绩及格啦\n") : printf("成绩太差啦\n");
	         //是唯一一个三元运算符（有三个操作数）
	60 <= b ? printf("成绩牛批啊\n") : 60 <= b ? printf("成绩吊哇\n") : printf("成绩垃圾呀\n");;
	         //优先级低，综合性：从右往左执行，
	         //在system处截断，右键转到反汇编，能查看汇编代码，可以对比条件运算符与if else的简洁性
			 //是否简介要看编译器的，不同编译器是可能产生不同的汇编代码
	system("pause");//比如上面这条，先判断后半部分得出结果，再拿后半部结果与前半部运算
	return 0;
}