#include <stdio.h>         //包含头文件 std：standard：标准 i：in：输入  o：out：输出
#include <stdlib.h>        //如何判断函数对应的头文件：百度，或者选中函数右键转到定义可看到头文件
int main(void)
{
	printf("hello yy 坚持住哦~\n");  //函数主体在头文件内，为了让编译器使用函数的时候认得它
	printf("hello yy 坚持住哦~\n");  //printf的函数定义在stdio的头文件中，没有头文件编译器就不知道这个函数是干嘛的

	system("pause");                 //system的函数定义在stdlib的头文件里
	return 0;
}