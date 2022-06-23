#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(void)//注意：考试面试笔试常会问到这两个关键字
{
	//volatile：易变的，易挥发的
	int b, c, d, e, f;
	volatile int a = 12;
	b = a;
	c = a; //当一个变量被使用太多太多次时，
	d = a;//系统会优化把这个变量放到寄存器或缓存里
	e = a;//volatile就是让变量不断更新，避免被放到寄存器或缓存里的
	f = a;
	//...
	//在程序中多次使用了a，那么如果这个变量a没有volatile修饰，
	//那么系统就会认为a是不变的，就是认为它一直是12，然后在程序运行中就会对a进行优化，
	//比如放在寄存器中（或者缓存中），以增加对a的读取速度，从而增加程序的执行速度。

	//那么如果在定义a的时候加了volatile，那么结果，就是标记a是随时改变的，易变的，
	//这样，系统就不会对其优化进缓存或者寄存器。

	//这个啊，咱们宏观上也看不到效果，所以，只可意会不可言传。哈哈



	//restrict：限制，约束。只能用于指针，表示该指针是访问对应空间的 唯一 且 初始的方式。
	int* restrict p = (int*)malloc(sizeof(int) * 4);
	
	p[0] += 3;
	p[0] -= 5;//restrict会把这两个式子合并到一起计算，优化了算法
			//有多少个式子都合并到一起去算
			//这也是我们见不到的，只在编译生成可执行文件时有效

	system("pause");
	return 0;
}