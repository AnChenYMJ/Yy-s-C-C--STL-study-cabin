#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	FILE* pfile = fopen("67.2 测试.txt", "r");

	//fputs返回值：成功写入返回0，失败返回EOF（-1）.
	//char yu[40] = { "Keep going~  don't desitate. please\n"};//
	//fputs(yu, pfile);//fputs只能写入字符串，所以要换行的话就在字符串的末尾加上\n
	//fputs("Just react earlier than tomorrow", pfile);
	//参数1：要输入的字符串的地址，参数二：要写入的文件的空间地址



	char hang1[50] = { 0 };//一定要初始化，否则可能出现乱码
	char hang2[50] = { 0 };//不要用同一个数组装多行字符串，否则后面的会把前面的内容覆盖掉
	//注意：数组大小要我们来估计一行的长度，一行可能非常长，有时候太长，文本软件因为界面原因给我们
	//显示了多行，这是软件显示的原因，不是真正的数据的多行，
	//所以我们要根据记忆了解来确定要读多少，避免漏读
	fgets(hang1, 50, pfile);//可截断调试来查看读取结果
	fgets(hang2, 50, pfile);//fgets读取是一行一行的读，不用手动换行，fputs换行写入要手动加\n
	//参数1：读出的数据所装位置；参数2：读取的最大字节亮（不要超出所装数组大小，否则越界）
	//参数3：读取的文件的地址。


	fclose(pfile);


	system("pause");
	return 0;
}