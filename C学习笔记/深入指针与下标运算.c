#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int a[6] = { 4,9,7,2,1,6 };
	int* p = &a;
						//现在要打印第5个元素：方法有如下
	printf("%d, %d, %d , %d\n", *(p + 4), *(4 + p), p[4], 4[p]);   //p[4]与4[p]是下标运算，就是进行p+4或4+p的地址运算
	printf("%p, %p, %p , %p\n", &*(p + 4), (4 + p), &p[4], &4[p]); //这是打印地址，看打印得对不对
						//都是同样的表达意思
	printf("%d, %d, %d , %d\n", *(a + 4), *(4 + a), a[4], 4[a]); //a 与 p的区别，a能参与运算，但不能被赋值
	//*(p+2) == p[2]											//p既能参与运算，也能够被赋值，指向新的地址

	//*(*(p + 3) + 2) == *(p[3] + 2) == p[3][2]
	system("pause");
	return 0;
}