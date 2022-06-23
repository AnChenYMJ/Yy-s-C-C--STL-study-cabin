#include <stdio.h>
#include <stdlib.h>

int fun1(int a)//函数类型是：int (int) 就是去掉函数名 
{				//函数类型由返回值类型 参数个数及类型 决定
	printf("我是函数fun1 \n");

	return 5;
}

int fun2(int a)//函数类型是：int (int)
{
	printf("我是函数fun2 \n");
	printf("我是函数fun2 \n");
	printf("我是函数fun2 \n");
	printf("我是函数fun2 \n");

	return 6;
}

int fun3(int a,int b)//fun3的函数类型是：int （int, int)
{
	printf("我是函数fun3 \n");
	printf("我是函数fun3 \n");
	printf("我是函数fun3 \n");

	return 3;
}


int main(void)
{
	//int fun1(int a)
	//int (*p)(int a)  //int (*p)(int) = fun1是函数指针的声明形式，注意不要把*p的小括号去掉，否则
	//就变成了函数的初始化，因为p优先与（int）结合，变成函数的形式了
	//int (*p)(int) = fun2;//int (int a)就是函数的类型，就跟变量int a一样，去掉变量名就是变量类型
	int (*p)(int) = fun1; //去掉函数名就是函数类型，fun1与fun2是同一种类型的函数，类型与返回值的大小无关
	//int (*p)(int) = fun3; //提示：int(__cdecl*)(int, int)”和“int(__cdecl*)(int)”的参数列表不同
						//证明了
	p(1);//这样就是调用函数了

	int (*p1)(int) = &fun2;//fun与&fun都是函数的地址，但空间不同，fun的空间装的是函数地址，
	//而fun本身的地址与函数地址数值一样
	(*p1)(1);    //如果给指针p1装载的是函数的取地址符格式，那调用时就要用*p1

	
	system("pause");
	return 0;
}