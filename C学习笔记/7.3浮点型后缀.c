#include <stdio.h>           //p24，8.2 浮点型内存储存，以后记得回顾看
#include <stdlib.h>

int main(void)
{
	//float f = 123.321;   //123.321默认为double类型，从double转换为float，
	                     //从“double”到“float”截断，从8字节到4字节，需要截去一些东西。
	                     //以后出现类似的从高字节到低字节的转换，都会出现截断
	float t = 123.3212356f; //123.321f就是float类型的了，这样就不会出现警告,f或F都可以
	                    //float的后缀是：f/F
	double d = 123.3212356;
	long double ld = 123.3212356L;    //long double的后缀是：l/L
	                              //c语言中123.321+123是不能直接运算的.要把整数123转换为浮点型再运算
	                              //如果数据与类型不是对应的，会转换以致截断，导致数据不是我们想要的
	printf("%10.3f \n%.5lf \n%f \n", t, d, ld); //输出%f 与%lf 都能用，没有严格要求
	                                          //不去规定小数位数时，默认第六位四舍五入
	                                          //10.3意思是第三个小数前有10位，点.也算一个，缺的用空格补上
	                                          //如果是-10.3则是左对齐，右方空出来，10.3是左对齐
	
	scanf_s("%f %lf %lf", &t, &d, &ld);       //变量输入时%f与%lf必须严格遵守规则，
	                                          //float用%f输入，double与long double用%lf输入
	                                          //记得输入时，变量要跟取地址符&
	printf("%f %lf %lf", t, d, ld);

	system("pause");
	return 0;
}