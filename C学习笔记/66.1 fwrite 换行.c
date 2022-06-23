#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	FILE* pfile = fopen("66.1 测试.txt", "wb"); //可切换r，r + ，w，a来试下不同的效果

	char* YU1 = "Keep going!";//这样即可实现多次写入文件
	//文本模式换行有两种方式，其一：
	char HH = '\n';
		//文本模式换行方式，其二：
	char* YU2 = "don't hesitate~\n";//这种可能看着有点不合理，其实是完全没问题的
		//二进制换行方式：\r\n
	char* YU3 = "please!";
	char *HH1 = "\r\n";//两个字符是字符串
	char* YU4 = "诗酒趁年华";

	fwrite(YU1, sizeof(char), strlen(YU1) + 1, pfile);
	fwrite(&HH, sizeof(char), 1, pfile);//因为不是常量字符串了，所以要手动加取地址符&
	//strlen是计算字符串长度的，这里是单个字符，用不了，手动写1.//且没有空格了，就不用加1
	fwrite(YU2, sizeof(char), strlen(YU2), pfile);//因为换行了，不需要空格，所以不用+1
	fwrite(YU3, sizeof(char), strlen(YU3) + 1, pfile);
	fwrite(HH1, sizeof(char), strlen(HH1), pfile);//因为换行了，不需要空格，所以不用+1
	fwrite(YU4, sizeof(char), strlen(YU4) + 1, pfile);

	fclose(pfile);//注意要保存关闭
	//连续写入多组数据的原理是：文件指针的移动


	system("pause");
	return 0;
}