#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int a = 54;
	int *p;              //定义时的*p是一个标记
	p = &a;  //一定要是一个合法地址     //就像数组定义时 int a[5],此时a[5]是个标记

	  //读
	printf("%p, %d, %d \n",p, *p, a); //此时的*p代表指向的空间对应的数值，c3老师叫做内存运算符
	                     //此时的*p是一个运算符，就像赋值时的a[4] = 4，此时a[4]表示第五个元素

	//写
	*p = 48;     //p与*p可理解为：p指向一个变量a(变量a的地址)，*p就是这个变量a本身
	printf("%p, %d, %d \n", p, *p, a);

	//取地址
	printf("%p, %p, %p \n", p, &*p, &a);


	system("pause");
	return 0;
}