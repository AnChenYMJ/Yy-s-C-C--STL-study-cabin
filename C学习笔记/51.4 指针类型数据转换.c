#include <stdio.h>
#include <stdlib.h>


int main(void)
{
	//int a = 12;//int是4字节空间
	//double* p = (double*)&a;//double是8字节空间
	//*p = 23.1;	//把a的空间类型换成double的8字节空间再赋值，就越界了
	//printf("%lf \n", *p);//这种越界操作的报错在程序结束时提醒，当代码很多，
	//引用a一多，就找不到究竟是哪里的错误了，所以我们使用指针时要特别小心。

	double b = 56.56;
	printf("%lf \n", b);
	int* p1 = (int*)&b;//把double类型空间变成int类型空间,8字节空间里操作4字节类型是完全没有问题的
	*p1 = 11;  //因为8字节空间变成int类型，所以有两个int类型的空间，能分别操作
	*(p1 + 1) = 22;//&b==p1是空间首地址，而(p1 + 1)就是首地址加上一个空间类型的地址大小
	//，上面已经变为int类型的了，所以+1就加一个int类型空间的大小
	printf("%d, %d \n\n", *p1, *(p1 + 1));//指针指向8字节空间的开头，把空间分成两个int类型分别操作

	//如果我们想操作8字节空间中间的四个字节
	double c = 89.56;
	char* p2= (char*)&c;//char类型是1字节的空间大小
	*p2 = 'a';            //先把8字节空间分成8个1字节空间
	*(p2 + 1) = 'b';	//前两个空间装char的字符
	//*(int *)((char*)&c + 2) = 889;//中间的四个字符装int（4字节）类型的数据
	*(int*)((char*)p2 + 2) = 989;//用这个给中间四个字节赋值也行或者*(int*)(p2 + 2) = 989;
	printf("%c, %c, %d \n\n",*p2, *(p2 + 1), *(int*)((short*)&c + 1));//*(int *)((short*)&c+1)
									//((short*)&c+1)是指向空间第三个字节空间的地址
									//*(int *)（p2 + 2）打印是同一个意思
	//指针/地址的类型 决定着 指针/地址的读写方式（字节数）
	//能看出，指针真的就很灵活，指向谁就能修改、读写、改变类型


	system("pause");
	return 0;
}