#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int a = 545;
	int *p = &a;
	printf("%d, %d \n", *p, a);

	*p = 4895;
	printf("%d, %d \n", *p, a);


	double b = 545.545;  //因为指针与指向的变量类型不同，导致打印结果错误
	int *y = &b;         
	printf("%f, %f \n", *y, b); //一个小范围的指针能指向大范围的空间，操作不异常，但数据不正确
	                    
	*y = 4895;         //因为int4字节，double8字节，*y赋值后再给b，而b则空了半个内存空间
	printf("%f, %f \n", *y, b);//空的内存与*y的值相结合，就会混乱导致错误


	//int t = 545;  //
	//double *y = &t;
	//printf("%f, %d \n", *y, t);
							//一个大范围的指针能指向小范围的空间，操作异常，而且数据非常不正确
	//*y = 4895.626;         //*y是8字节，数值转给4字节int类型的t，会越界并导致数据丢失
	//printf("%f, %d \n", *y, t);//无法打印


	system("pause");
	return 0;
}