#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	float f = 55.45871111;  //ANSI C规定float最小值6位（从零数开始算），实测精度7位
	double d = 55.123456789123456789;//ANSI C规定最小值10位，实测16位精度
	                                 //long double规定位数与double相同，在windows里18位精度
	                                 

	printf("%f \n %.20lf \n", f, d);   //%.20lf  意思是打印20位的%lf输出位


	system("pause");
	return 0;
}