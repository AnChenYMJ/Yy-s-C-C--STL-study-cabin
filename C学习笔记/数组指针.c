#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int a[5] = { 5, 8, 4, 6, 2 };

	int* p = &a[4];  //指针p指向数组a第5个元素，这是元素的指针声明

	//int p1 = &a;//提示“int”与“int (*)[5]”的间接级别不同，证明这不是数组的指针说明。

	int(*p2)[5] = &a; //这是数组指针的声明，表明一个指针类型是数组指针，
					//不加括号的话，p2优先与后面的[5]结合，就成了指针数组的声明
					//注意声明时元数个数与数组的元素个数要对应上，否则会报错
					//元素个数不同就是不同类型的数组
					//int [5](*p2)这种写法C语言不让用

	printf("%p, %p \n", &a, p2);//打印数组的地址
	printf("%p, %p, %d, %d \n", &(*p2)[2], &a[2], (*p2)[2], a[2]);
	//打印对应元素的地址，记住，p是变量的地址，*p是变量本身
	//即：(*p2)[2] == a[2]  


	//int *p2[5] == int *(p2[5]) //这是是指针数组的声明

	               //指针数组：装载指针（地址）的数组
				   //数组指针：指向数组的指针，或装载数组地址的变量


	system("pause");
	return 0;
}