#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	FILE* pfile = fopen("66.3 测试.txt", "r");
	//换行在文本模式下去读，读出来的是10（\n），一个字符
	//换行在二进制模式下去读，读出来的是\r\n，是两个字符
	//一般用文本模式，因为文本模式在linux系统里文本与二进制模式都是\n
	//在windows里二进制效率要比文本高，因为文本要把\r\n转换成单个\n

	char c[60] = {0};//要读取或写入的内容的数据类型
	size_t a;//读取返回值的类型

	while (!feof(pfile))//!feof(pfile):未读到结尾时返回0，都到结尾后返回非0，所以一般用来作为循环条件
	{		//最开始读出乱码了，原因是那个txt文件不是ANSI格式，另存换格式就好了
		a = fread(c, sizeof(char), 2, pfile);
		printf("%s", c);
		c[0] = 0;
		c[1] = 0;
	}
	
	fclose(pfile);

	//这里要说下文件结尾与行结尾的区别：
	//文件结尾是末尾光标所在的位置是文件结尾
	//行结尾是那一行的结尾，比如未满一行时敲了回车换行，那上一行最末位就是行结尾
	//而新换的那一行也就是光标所在位置是文件结尾


	system("pause");
	return 0;
}