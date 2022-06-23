#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <String.h>

int main(void)
{					//一般我们建立的文件格式是txt，能外部打开文件查看效果，方便我们读写。
	FILE* pfile = fopen("65.3 测试.txt", "a");//可切换r，r+，w，a来试下不同的效果

	char* YU = "Keep going~ don't hesitate! please~";
	int a;
	//函数fwrite的参数：参数一：写入的数据的首地址（结构体、数组、字符串的名字就代表它们的首地址）
	//参数二：一般是要写入的数据类型（sizeof）
	//参数三：数据类型的个数
	//参数二、三相乘的结果就是我们要写入的数据的字节数
	//参数四：文件指针（文件地址）

	//注意，常量字符串除了字符外，还自动加了个\0（空格），所以我们在参数三里+1了
	//可打开对应文件，会发现字符串的后面有一个空格
	a = fwrite(YU, sizeof(char), strlen(YU) + 1, pfile);
	//返回值：返回实际写入的字符数，写入失败会返回0值
	a = errno;//这样可以看错误码

	fclose(pfile);//记得保存关闭

	//如果记事本打开是乱码，就换一种打开方式

	system("pause");
	return 0;
}