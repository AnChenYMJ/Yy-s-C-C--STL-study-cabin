#include <stdio.h>
#include <stdlib.h>


void fun(void)
{
	printf("keep going~\n");
}

struct Stu
{
	int* p;//指针成员
};

struct Stu1
{
	int* p;//指针成员
};

struct Stu2
{				//函数类型要与自己需要调用的函数对应上
	void (*p)(void);//但是可以放函数指针


	/*void fun(void)  //结构体当中不可以直接放函数
	{
		printf("keep going~");
	}*/
};

int main(void)
{
	struct Stu sd = { NULL };//指针成员的初始化与赋值
	sd.p = (int*)malloc(8);//当结构体变量初始化为NULL时，一定要手动malloc一块空间
	sd.p[0] = 45;  //我们malloc一块空间，要依次根据空间类型来挨个赋值
	sd.p[1] = 98;
	printf("%d, %d \n", sd.p[0], (&sd)->p[1]);
	free(sd.p);


	int a[6] = { 9, 8, 7, 6, 5, 4 };//指针成员的初始化与赋值
	struct Stu1 sd1 = { &a };//用a或&a[0]都可以，反正都表示同一个地址
	////这是初始化内容为数组时调用数组的方式
	printf("%d, %d, %d, %d \n", sd1.p[0], sd1.p[5], (&sd1)->p[3], (&sd1) -> p[2]);


				//用&fun也可以
	struct Stu2 sd2 = { fun };//在结构体里的成员是函数指针类型，所以我们把需要的函数的地址赋值进去
	sd2.p();//在用这句就能调用函数了
	//注意.与（）的优先级是一样的，结合性从左向右，所以这里.先与p结合

	system("pause");
	return 0;
}