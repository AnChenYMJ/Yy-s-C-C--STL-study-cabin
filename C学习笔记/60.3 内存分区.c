#include <stdio.h>
#include <stdlib.h>


void fun()
{
	const char* p = "Keep going~";
	printf("%p \n\n", p);
}

const int b = 55;//全局const变量

int main(void)//更详细的关于内存分区的知识点在X-mind里的“其它”项下
{
	{
		const char* p = "Keep going~";
		printf("%p \n\n", p);
	}

	{
		const char* p = "Keep going~";
		printf("%p \n\n", p);
	}
			//证明了字符常量区从定义位置开始，与程序共存亡，且位置固定，
	fun();//会发现这三个打印的地址都相同



	const int a = 44;
	int* p = (int*)&a;  //局部const变量存储在栈区
	*p = 11;

	int* p1 = (int*)&b;	//全局const变量存储在常量区，不能被任何形式修改的
	*p1 = 15;


	system("pause");
	return 0;
}