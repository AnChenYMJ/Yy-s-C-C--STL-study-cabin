#include <stdio.h>
#include <stdlib.h>


int main(void)
{
	int a = 10;
	a = a + 7;  //这样可以进行自加运算
	a += 7;     //+= 这是一个运算符，功能与上面的一样，都是自加运算

	a = a - 7;
	a -= 7;

	a = a * 7;
	a *= 7;

	a = a / 7;
	a /= 7;

	a = a % 7;
	a %= 7;

	printf("%d \n", a);


	system("pause");
	return 0;
}