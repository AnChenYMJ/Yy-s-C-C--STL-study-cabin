#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int main(void)//fseek与ftell是很实用的函数，看需求去用吧
{
	FILE* pfile = fopen("67.4 测试.txt", "r"); //记住，读的话用r，不要用w，否则w会清空内容.
	
	char i[30] = {0};
	fread(i, sizeof(char), 15, pfile);
	printf(i);
	printf("\n");


	char j[30] = { 0 };
	//fseek(pfile, 0L, SEEK_SET);//指针指向文件开头
	//fseek(pfile, 13L, SEEK_SET);//指针指向文件第13个字节
	//fseek(pfile, 2L, SEEK_CUR);//指针从当前位置向右->移动2字节
	//fseek(pfile, -5L, SEEK_CUR);//指针从当前位置向左<-移动2字节
	//fseek(pfile, -5L, SEEK_END); //从末尾位置向左移动5字节
	fseek(pfile, 0L, SEEK_END);//指针指向文件末尾
	//参数1：操作的文件空间地址；参数2：设置指针的位置；参数3：操作指针的方式
	//注意这里用L是因为，参数2的类型是long类型，要加L的后缀

	fread(j, sizeof(char), 5, pfile);
	printf(j);
	printf("\n");

	int a;
	a = ftell(pfile);//ftell:参数1：操作的文件的地址
	printf("%d\n", a);//返回值：内容当前的位置下标，配合(0L,SEEK_END)就能返回文件内容的字节数


	fclose(pfile);//fclose的作用：关闭文件，并更新文件内容，释放操作文件时申请的物理空间。


	system("pause");
	return 0;
}