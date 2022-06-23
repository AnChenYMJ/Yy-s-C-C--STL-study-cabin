#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int b = 6,
		c = 4,
		d = 7,
		e = 6,
		f = 9;
	//int* 是表明每个元素的类型为int*
	int* a[5] = { &b, &c, &d, &e, &f }; //这就是指针数组：一个数组，它的装载的元素是各个地址
										//也叫地址数组

	printf("%d \n", d);
	*a[2] = 16;          //通过指针下标修改元素指向的值d
	printf("%d \n", d);
	*&d = 14;
	printf("%d \n", d);


	system("pause");
	return 0;
}