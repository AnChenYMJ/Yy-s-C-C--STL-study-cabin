#include <stdio.h>
#include <stdlib.h>

void fun1(int a)
{
	printf("a = %d \n", a);//这种传递方式叫做值传，意思是值传递
	a = 455;			   //值转给a，最终操作的是a
	printf("a = %d \n", a);//修改函数内部参数，观察外部的变量b有无改变（无变化）
}

void fun2(int* p)//这种传递方式叫做址传，意思是地址传递
{
	printf("*p = %d \n", *p);//这里对*p操作，相当于直接对d操作，因为p是指向d的地址的
	*p = 999;                //通过地址间接修改d值
	printf("*p = %d \n", *p);
}

//通过函数修改外部变量的值    把函数内部的值传递到函数外部

int main(void)
{
	int b = 188;
	printf("b = %d \n", b);//值传，通过外部的值赋值给函数内的参数
	fun1(b);
	printf("b = %d \n", b);//函数内部的值修改后，外部的值依旧没有改变
			//因为a，b两个变量是不同的空间，有不同的地址，修改a改变不了另一个地址空间的b


	int d = 333;
	//int* p = &d;
	printf("d = %d \n", d);
	fun2(&d);
	printf("d = %d \n", d);//因为是通过地址间接修改d值，函数内的数值传递到外部了

	system("pause");
	return 0;
}