#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

struct YU  //结构体的文件读写只能通过fwrite与fread来操作
{
	char name[10];
	int num;
	short age;
	double hight;
	float weight;
};


int main(void)
{
	struct YU bu = { "不知火舞", 112, 25, 165.2, 48.5 };
	struct YU nu;
	FILE* pfile = fopen("67.1 测试.txt", "w");

	//fwrite(&bu, sizeof(bu), 1, pfile);//这样写入的话，在文件夹中打开txt文件，会发现是乱码的
	//原因是存在内存对齐，内存对齐可参考笔记49.2，是为了提高效率，避免拆分结合，所以尽量cpu读一次
	//就能把一个类型读出来，就把分段不足以装下另一类型的空间补上，让另一类型在下一个分段中
	//分段大小是看cpu一次性读取的字节数，32位固定4字节，64位固定8字节
	//这样的话，在txt或者我们外部用其他软件打开看到的都是乱码，因为它不知道内存对齐
	//但是我们用fread去读就能正确读出来了，所以不用管文件里存的什么，fread会完全按照fwrite写入
	//时的格式去读，他会知道内存对齐。

	fread(&bu, sizeof(bu), 1, pfile);//截断调试就能看到&bu里的数据是正确的

	//fwrite(&bu, sizeof(bu.age), 1, pfile);//想要写入时换行
	//fwrite("\n", 1, 1, pfile);//这样就能换行了
	//fwrite(&bu, sizeof(bu.hight), 1, pfile);//两个成员换行写入

	printf("%d \n", sizeof(nu));//40
	//宽为结构体中基本数据类型最长的一个为准
	//以结构体YU为例：宽为double的8字节，
	//第一个宽：被char数组装满，
	//第二个宽：前4字节：2字节是char数组，补齐2字节；后4字节：int num装满
	//第三个宽：short的2字节加上2位补齐，后4位也补齐
	//第四个宽：double类型装满
	//第五个宽：float4字节，后4字节补齐
	//共40字节空间大小，可打印看看。

	fclose(pfile);

	


	system("pause");
	return 0;
}