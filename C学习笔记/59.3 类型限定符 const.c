#include <stdio.h>
#include <stdlib.h>


//存储类说明符5个：auto  extern  static  register   typedef//一个变量不能出现两个存储类说明符
//类型限定符有：const， volatile， restrict


int main(void)
{		//const一般也叫常量修饰符，被修饰的变量就相当于常量了，不能被修改
	const int a = 15;//作用是保护数据，增加程序的鲁棒性（稳定性）
	int const b = 16;//这两行都一样，都是在修饰变量名

	//a = 51;//报错： 左值指定 const 对象
	//b = 61;//报错： 左值指定 const 对象
	printf("%d  \n\n", a);

	//const是修饰变量名，但空间的入口除了变量名还有指针
	int* p = (int*)&a;//空间因为被const修饰，类型变成了const int类型,可以使用强转变成int*
	const int* p1 = &b;//

	*p = 51;//修改成功，因为我们通过指针强转成了int类型
	//*p1 = 61;//这个没有修改成功，因为没有强转类型，空间还是被const修饰，
	printf("%d  \n\n", a);


	const int c[5] = { 3, 5, 4, 8, 9 };
	
	//c[2] = 55;//const还能修饰数组，这样数组的元素也不能修改了
	//但也能通过指针修改

	int (*p3)[5] = (int(*)[5])&c;//强转指针类型，也就是强转空间类型
	//(*p3)[2] = 55;				 //通过指针成功修改const修饰的数组
	(*p3)[2] = 55;
	printf("%d  \n\n", c[2]);	//打印修改值成功


	system("pause");
	return 0;
}