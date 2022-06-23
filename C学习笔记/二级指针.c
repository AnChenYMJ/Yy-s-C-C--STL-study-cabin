#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int a = 456;
	int *p = &a;

	//int *p1 = &p;  //生成时提示：“初始化”:“int *”与“int **”的间接级别不同
				   //此时证明装载指针变量地址的级别与指针变量不同

	int* *p1 = &p;   //此时就可以了，**p1就是2级指针的声明，*p是1级指针的声明
					 //二级指针装载着一级指针的地址，一级指针装载着变量的地址
	int** *p2 = &p1; //三级指针装载指向二级指针的地址

	int *p3 = p;     //这样只是把p装载的内容（a的地址）赋值给p3

	printf("%p, %p, %p, %p \n", p3, p2, p1, p);//, p3
	printf("%p, %p, %p, %p, %p, %p, %p, %p, %p, %p, %p \n", a, *p, **p1, &a, p, *p1, &p, p1, *p2, &p1, p2);
	  //不管怎么变，记住：p的值是这个变量的地址，而*p就是变量本身，
	  //定义声明时的*p是个标志，表示这个变量为指针

		//对应关系如下：
		//a == *p == **p1
		//&a == p == *p1
		//&p == p1 == *p2
		//&p1 == p2


	system("pause");
	return 0;
}