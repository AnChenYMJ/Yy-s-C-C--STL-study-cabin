#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int a = 10,
		b = 10;

	//a++, ++b;               //这里分别叫做后置++，前置++

	//printf("%d %d \n", a, b);

	
	                //12++;  //注意：常量的值不能自加，自加是指变量本身的值加1
	int c = a++,               
		d = ++b;

	printf("前置++与后置++： \n");
	printf("%d %d \n", a, b);  //结果为：  11 11  只要出现++，不论前置后置变量本身加1。
	printf("%d %d \n", c, d);  //结果为：  10 11  后置++：a++在参与运算时，只用自加前的值参与运算
	                                           //前置++: ++b在参与运算时，使用自加后的值参与运算

	int q = 11,
		w = 11;

	int e = (q--) + 1,               //与后置++一样，后置--在参与运算时，是自减前的数值参与运算
		r = (--w);

	printf("前置--与后置--： \n");
	printf("%d %d \n", q, w);
	printf("%d %d \n", e, r);


	system("pause");
	return 0;
}