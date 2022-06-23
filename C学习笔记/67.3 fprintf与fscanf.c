#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	FILE* pfile = fopen("67.3 测试.txt", "r");//记住，读的话用r，不要用w，否则w会清空内容，
	//因为w是清除写。

	//printf是在命令提示符里输出打印，而fprintf是在文件里输出
	//这样就有一个问题，fwrite写入不改变数据类型，是什么类型就写入什么
	//而fprintf是把各种类型转换为字符串再输出到文件里，效率就慢了
	//返回值：成功返回写入的字节数，失败返回负数
	//fprintf(pfile, "%d, %.3lf, %s, %c", 13, 165.023, "keep going", '!');
	//参数1：写入的文件的地址，参数2：与printf一样，是输出的类型与数量
	//参数3：与printf一样，是要输出的数据

	int a = 0;
	float f = 0;
	char st[20] = {0};
	char c = '0';
	//fscanf(pfile, "%d,%f,%s,%c", &a, &f, st, &c);//这样去读我们上面fprintf输出到文件中的内容
	//会发现读%s时只读了keep，而且%c没读到

	//fscanf(pfile, "%d,%f,%s %c", &a, &f, st, &c);
	//会发现读%s时只读了keep，%c读的是g
				
	//fscanf(pfile, "%d,%.3f,%s,%c", &a, &f, st, &c);
	//不能用%.3f的形式，会读取错误，没读到

	//返回值：成功返回读入的参数的个数，失败返回EOF(-1)。
	fscanf(pfile, "%d,%f,%c,%s", &a, &f, &c, st);//这样的话，写的时候也要按照这个顺序来写
	//所以常常把字符串放到最后读，因为读字符串遇到空格就不读了，或者把,当作字符串连着后面数据也读了
	//尽管这样，还是没太弄懂字符串该怎么正确读，或许如果字符串有空格，就分开读吧，
	//或者写的时候连在一起写，不加空格，注意%s后用空格隔开，否则会把逗号当作字符。
	//百度：fscanf读数据遇到空格和换行时结束


	fclose(pfile);

	system("pause");
	return 0;
}