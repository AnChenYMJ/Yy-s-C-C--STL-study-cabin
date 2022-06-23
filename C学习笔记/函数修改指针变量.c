#include <stdio.h>
#include <stdlib.h>

void fun1(int* p)
{
	printf("p = %p \n", p);
	p = NULL;
	printf("p = %p \n", p);
	//*p = 848;  //运行到此处时发生错误，看来不能用*p来修改原值，因为p的地址是p1给的
	//printf("*p = %d \n", *p);
}

void fun2(int** p2)//注意，p3是指针，而p2是装p3的地址的，所以p2是二级指针类型
{					//注意，传址是要修改谁就传谁的地址，不是说只要是地址类型就可以
	printf("p2 = %p \n", p2);
	*p2 = NULL;  //地址操作符修改原值p3
	printf("p2 = %p \n", p2);//但p2本身的值不变
}

int main(void)
{
	int a = 56;
	int* p1 = &a;
	printf("p1 = %p \n", p1);
	fun1(p1);				 //不能通过操作p来修改p1指向的地址，因为p是被p1赋值了a的地址
	printf("p1 = %p \n", p1);//函数里修改p只是修改了p装的内容，没有修改到p1
	//printf("a = %d \n", a);
	

	int b = 98;
	int* p3 = &b;
	printf("p3 = %p \n", p3);
	fun2(&p3);//注意，传址是要修改谁就传谁的地址，不是说只要是地址类型就可以
	printf("p3 = %p \n", p3);//通过装载p3地址的二级指针p2的地址操作符成功修改指针p3的内容（指向）


	system("pause");
	return 0;
}