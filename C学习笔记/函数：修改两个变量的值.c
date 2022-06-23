#include <stdio.h>
#include <stdlib.h>

void fun1(int* p1, int* p2)
{
	printf("%d, %d \n", *p1, *p2);
	int m = *p1;     //这是一种变量交换的方法
	*p1 = *p2;  //如果写成*p2 = *p1
	*p2 = m;	//*p1 = m     则都变成*p1的值了
	printf("%d, %d \n", *p1, *p2);

}

void fun2(int* p3, int* p4)
{
	printf("%d, %d \n", *p3, *p4);
	int m = *p3;     //这是另一种变量交换的方法
	int n = *p4;
	*p4 = m;
	*p3 = n;
	printf("%d, %d \n", *p3, *p4);

}

void fun3(int a3, int a4)
{
	printf("%d, %d \n", a3, a4);
	int k = a3;
	a3 = a4;
	a4 = k;
	printf("%d, %d \n", a3, a4);//这里只是函数里的变量互换了，外部的没有
}
int main(void)
{
	int a = 5;
	int b = 7;
	printf("%d, %d \n", a, b);
	fun1(&a, &b);


	int c = 8;
	int d = 3;
	printf("%d, %d \n", c, d);
	fun1(&c, &d);


	int e = 8;
	int f = 3;
	printf("%d, %d \n", e, f);
	fun3(e, f);

	system("pause");
	return 0;
}