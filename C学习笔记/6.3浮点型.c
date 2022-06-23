#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	float f = 12.11;              //float 4字节  最小值是 6，实测7位（从非零的数开始计算6位）
	double d = 1.556;             //double 8字节 最小值是10，实测16位
	long double ld = 0.56564;     //long double 至少8字节不同编译器不一样，
	long double le = 0.111155;    //可能10字节，可能12字节 2的整数倍字节，ANSI C标准规定最小值是10，windows是18位
                                  vs里double与long double的范围是一样的
                                   
	printf("%f %lf %lf %e \n", f, d, ld, le);    //注意printf后面输出的变量在声明时必须初始化（给定一个值）
	                                      //%f是flost的输出符，%lf是double与long double 的输出符
	                                      //%e是科学计数法输出，对上面三个都适用,对整数不适用

	system("pause");     //每写十多行代码记得编译一下，看提示容易改，否则写了上百行再改就会困难很多。
	return 0;
}                      //浮点型的数值不能进行直接比较，因为不是精确的值