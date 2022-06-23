#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>


int main(void)
{
	int* p = (int*)malloc(4);
	if (NULL == p) //这相当于一种编写规范，减少编写程序时错误概率，因为不知道p会不会是0
	{
		//特殊处理
	}
	*p = 12;

	printf("%p, %d \n", p, *p);

	free(p);   //这是释放空间，当空间释放后，那块空间地址依旧没变，但空间清零了
	p = NULL; //一般指针释放完了之后，就赋值NULL，赋值NULL之后，就叫空指针
	if (NULL == p) //这相当于一种编写规范，减少编写程序时错误概率，因为不知道p会不会是0
	{
		//特殊处理
	}

	//printf("%p, %d \n", p, *p);//此时的*p就属于越界操作了，因为这块空间已经被释放，p叫野指针不能直接使用


	int* p1 = (int*)malloc(8);

	free(p1);
	//free(p1);  //不能重复释放同一块空间


	//int a[5];
	//free(a);  //运行到此处时触发断,int a[5]是栈区，栈区：由操作系统申请，由操作系统释放
	          //而现在我们人为的去释放是不符合规范的


	/*int* p2 = (int*)malloc(8);
	p2++;

	free(p2);*/  //运行到此处触发断点，原因是头地址+1，就变成了第二个类型空间的地址了
				//此时就不知道释放谁，又不能只释放后半段，所以这里是不符合规范的
				//类似这种运行中的崩溃，一定是某一行代码引起的，一定挨个截断调试找到


	//还有一种崩溃是运行结束时的崩溃，这种基本是内存越界操作了，非常难找，所以在编写时要十分细心指针的操作

	//在实际工作中，服务器是不可能轻易重启的，虽然malloc在程序结束时释放空间，但服务器上的程序往往不会停止
	//所以一定要记住free的使用

	system("pause");
	return 0;
}