#include <stdio.h>
#include <stdlib.h>
#include <malloc.h> 

//C语言的优势在于指针，但问题与难点也在于指针，
//下面列举的几个例子，生成时都不会报错，C语言是不检测越界或者空间丢失的
//所以在编写C语言时要多加留意


int main(void)
{							//所以申请的空间一定要与类型对应上
	int* p = (int*)malloc(3);//申请的类型为4字节的，但是却只申请了3个字节空间
	*p = 13;				//当对这个空间进行操作时，4字节的数据放到3字节空间里，就会造成栈区崩溃

	free(p);


	int* p1 = (int*)malloc(4);
	*(p1 + 1) = 42;   //这样就越界操作了，越到申请的空间类型的下一个类型的空间去了
						//不要越界，比如申请了8字节空间，那*（p1+2）就会越界，所以注意边界


	int* p3 = (int*)malloc(12);
	//free(p3); //这样就不会丢失内存，就可以重新申请了，释放一下空间
	int* t = p3; //这样也不会丢失内存，因为把空间指针给了另一个指针，就不会被认不出
	p3 = (int*)malloc(8);//这样的话上面p3申请的空间就会被丢失，那片12字节的空间依然被占用
						//但是没有被指针指出并释放，就会造成内存丢失（内存泄漏）
						//如果陷入循环当中，就完蛋了，运行的内存不断增多





	system("pause");//正因为这行代码，编译时才会卡住，并提示：请输入任意按键继续
	return 0;
}