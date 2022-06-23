#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	FILE* pfile = fopen("65.1 测试.txt", "w");//可打开文件夹查看是否建立文件
	// r : read缩写，只读，无文件会执行失败
	// w ：write缩写，擦除写（可读可写），有内容时把内容擦掉重新写，文件不存在时会创建文件
	// a ：appad缩写，接着写（可读可写），有内容时在内容尾部接着写，文件不存在时会创建文件
	// r+： （可读可写）其它与r一样
	// w+：与w一样
	// a+：与a一样
	// r w a 本质是‘rt’ ‘wt’ ‘at’ t是text，文本格式，写成‘rt’ ‘wt’ ‘at’也是可以的，
	//不过一般为了节省时间省略掉


	//b是bit缩写，表示二进制，以下都是二进制形式
	// rb : read缩写，只读，无文件会执行失败
	// wb ：write缩写，擦除写（可读可写），有内容时把内容擦掉重新写，文件不存在时会创建文件
	// ab ：appad缩写，接着写（可读可写），有内容时在内容尾部接着写，文件不存在时会创建文件
	// rb+（r+b）： （可读可写）其它与r一样，两种写法都可以
	// wb+（w+b）：与w一样，两种写法都可以
	// ab+（a+b）：与a一样，两种写法都可以


	system("pause");
	return 0;
}