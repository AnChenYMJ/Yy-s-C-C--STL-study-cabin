#define _CRT_SECURE_NO_WARNINGS//新版VS编译器是使用fopen_s

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//注意：读写的格式一般来说要对应上，比如fwrite写入，就用fread来读
//因为都是按字节数来读写的，不会混乱，算是一个规范
//按字节数写入，能按行来读，但是容易弄错，所以一般怎么写的就怎么读
int main(void)
{
	FILE* pfile = fopen("66.2 测试.txt", "r");//读的话不要用w，因为w会擦除掉内容
	
	char YU[30] = {0};
			//fread的返回值是读取的字节数，但如果没有字节可读了，就返回0
	//int a = fread(YU, sizeof(char), 2, pfile);//一个中文字符刚好两字节
			//我们可以把fread放到循环中去读
	int a;	//fread参数形式与fwile一样，
	//c3包东华老师的课程里，fread的返回值是size_t类型的，这里用int不知道为什么没提示
	//size_t在64位环境里是unsigened int类型
	while ( a = fread(YU, sizeof(char), 2, pfile))
	{
		printf("%s", YU);//空有一腔苦和愁 yuana//会发现多打印了一个单词，原因是读最后1位时
		//不足2个了，然后就覆盖掉倒数第3个，强行读两个出来，我们可以用以下方法避免
		YU[0] = 0;//这样每次读完2字节，就把这2字节清空
		YU[1] = 0;//原理是读完后，指针就向后移动2字节，指针所指的位置就是新的YU[0]
	}
 
	fclose(pfile);//记得保存关闭


	system("pause");
	return 0;
}