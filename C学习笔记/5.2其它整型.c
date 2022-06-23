#include <stdio.h>
#include <stdlib.h>


int main(void)
{
	short s = 123;    //short int 是它的完整写法，所有声明与定义变量的方式都是相同的。
	                  //short 的内存字节为2字节，有符号的范围是：-32768~32767
	                  //无符号的范围是：0~65535

	printf("short : %hd \n", s);           //输出格式符为：%hd  但是用%d 也可以，前一种更准确
	printf("short : %d \n", sizeof(s));    //输出所占字节


	long l = 223;     //长整型：long int 是它的完整写法，long 的内存字节，范围大小都与int类型一样，
	                  //4字节，有符号:-2^31~2^31-1 , 无符号：0~2^32-1
	                  //《C和指针》标准只规定int不小于short的长度

	printf("long : %ld \n", l);          //输出格式符为：%ld  用%d也可以
	printf("long : %d \n", sizeof(l));   

	long long ll = 333;     //c99标准扩展的新类型，VC++6.0不支持，完整写法：long long int
	                        //内存占8字节，有符号：-2^63~2^63-1,无符号：0~VC++6.0~2^64-1
	                        //比较不常用，但是具体用哪个，还是取决于你所需的数据的大小

	printf("long long : %lld \n", ll);          //输出格式符为：%lld  用%d也可以
	printf("long long : %d \n", sizeof(ll));


	system("pause");  // getchar() , while(1) 这两种都可以卡住以便观察。
	return 0;
}