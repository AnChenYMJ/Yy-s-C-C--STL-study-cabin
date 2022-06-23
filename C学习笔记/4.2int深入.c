#include <stdio.h>
#include <stdlib.h>


int main(void)
{
	int a = 13;         //有初始值就是初始化，建议每次声明变量都初始化
	int b = 15;         //定义，定义一个int类型的变量b，并赋值15
    //int c;            //声明，声明一个变量c
	

	a = 11;               //常量给变量赋值
	printf("%d %d \n", a, b);
	


	a = b;             //变量给变量赋值
	printf("%d %d \n", a, b);



	a = b = 20;        //连续赋值，从右往左执行，先把20赋值给b，b再赋值给a
	printf("%d %d \n", a, b);


	system("pause");
	return 0;
}