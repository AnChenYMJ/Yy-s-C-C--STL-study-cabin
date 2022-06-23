#include <stdio.h>
#include <stdlib.h>

		//返回值不写不会报错，但会默认为int的有返回值，返回值也叫函数类型分为有类型与无类型
void fun(void) //格式：返回值 标识符（无参数），这里是无返回值，无参数
{				//主函数的形式返回值那里是int，表明有返回值，括号里的void是无参数
	printf("我是函数fun \n");//函数名（标识符）注意不要与编译器自带的如malloc这些函数冲突
}						//函数本质相当于变量，int a，a就是变量名，函数名也类似，尽量起的名有含义，表达函数的功能
						//如FindMaxMunberFromArray,或者小写find_max_number_from_array,这是命名规范
						//函数名不可以数字开头，可以_下划线字母开头，后面的可以数字下划线字母
int main(void)
{

	fun(); //这里就是在主程序调用函数的形式


	system("pause");
	return 0;
}