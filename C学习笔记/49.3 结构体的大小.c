#include <stdio.h>
#include <stdlib.h>

//#pragma pack(1);//以成员中最大的基本数据类型的大小为宽，可以手动设置这个宽的大小，
//但注意，以最大的基本数据类型为基准，只能往小了设置，往大了设置系统会报错且会强制变回最大的基本数据类型
//小心使用，因为容易造成运行效率低，原因参见49.2
//我们一般不做设置，编译器会自动帮我们选择合适的对齐策略


struct Stu
{
	char c;
	double b;  //这个结构体内存空间大小为 24字节
	int a;		//原理是这样：以成员中最大的基本数据类型为宽，按顺序依次填补对齐，结尾也以宽为单位补齐
	short s;//这里c占了8字节，因为b8字节大小无法补齐，b也占了8字节，a占了4字节，s占了4字节（有2字节是结尾补齐）
};		//a与s能放在一个8字节的宽里，遵循的是要能一次读取出来，避免拆分结合，这里没有拆分
	
struct Stu1
{
	char c; //结果为16字节，更表明了按顺序补齐的原理
	short s;//c与s同时放在4字节里c与s间自动补了1字节，a占4字节，满足8字节的宽
	int a;//b占8字节，加起来16字节
	double b;  	
};

int main(void)
{
	struct Stu sd;//结果为24
	printf("结构体类型大小： %u\n结构体变量大小： %u\n\n", sizeof(struct Stu), sizeof(sd));

	struct Stu1 sd1;//结果为16
	printf("结构体类型大小： %u\n结构体变量大小： %u\n\n", sizeof(struct Stu1), sizeof(sd1));

	system("pause");
	return 0;
}