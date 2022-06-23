#include <stdio.h>
#include <stdlib.h>

//union是关键字
union un   //联合与结构体的声明初始化方式一样
{			//不同的是，结构体中每个变量都有自己的独立空间
	char name[10];	//而联合中，是公用一块空间，大小为最大的类型所需要的空间
	int a;			//这里是10字节为最大空间，10字节与int还有short共用空间
	short s;
}un1;

struct Stu
{
	char name[10];//结构体的成员间的地址间隔刚好是成员的所占字节空间的大小
	int a;
	short b;

};

union un1 
{			
	int a;
	char c;
	short s;
};

union un2
{
	int a;
	char c;
	short s;
};

union un3
{
	int a;
	char c[10];
	short s;
};

int main(void)
{
	struct Stu sd;
	//union un un2 = { "不知火舞" };//联合中只能初始化一项成员，初始化谁都行，
	union un un2 = { .a = 34 };//在VS2013之后版本能这样定向初始化
	printf("%d\n\n", un2.a);//想先初始化谁，就把那个成员放在最前面
	
	//打印联合中各成员的首地址，会发现地址都是一样的，证明了成员间共用一块内存空间
	printf("%p \n%p \n%p \n\n", &un2.name, &un2.a, &un2.s);

	printf("%p \n%p \n%p \n\n", &sd.name, &sd.a, &sd.b);//对比结构体的各成员首地址会更明确


	union un1 un3 = {256};//此时c的值是0，原理：256的二进制：1 0000 0000 而最小的char大小为1字节
	printf("a = %d\nc = %d\ns = %d\n\n", un3.a, un3.c, un3.s);//计算机读取地址是从高位向低位读
	//把1 0000 0000装进联合里，最低位的char装了0000 0000，所以c就变成了0，

	union un2 un4 = { 70000 };//此时c的值是112，s的值是4464，a的值是70000
	printf("a = %d\nc = %d\ns = %d\n\n", un4.a, un4.c, un4.s);
	//原理：70000的二进制：1 0001 0001 0111 0000//最后8位装在最小的空间char里0111 0000就对应10进制的112
	//同理：short两字节空间，最后十六位0001 0001 0111 0000装在short里，而这个数对应10禁止的4464
	//而完整的二进制1 0001 0001 0111 0000，因为大家公用空间，而int是4字节，能完整的读取到70000的二进制

	
	union un3 un5;//可以看到联合的空间大小，char是9字节空间，但我们打印出12
	printf("联合类型大小： %u\n联合变量大小： %u\n\n", sizeof(union un3), sizeof(un5));
	//原因是发生了内存对齐，最大的基本数据类型是int（4字节），那9往上取4的倍数就变成了12，发生了结尾补齐

	system("pause");
	return 0;
}