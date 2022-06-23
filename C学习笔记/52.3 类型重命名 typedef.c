#include <stdio.h>
#include <stdlib.h>

//把重命名写在全局区，这样下面的所有函数就都能用了。
typedef int maint;//maint 就是 int
typedef maint niint;//niint 也是 int，它们使用上没任何区别，只是给int换了个名字

typedef unsigned int unin;//无符号整型换名字就能方便打代码了，因为原名字长
typedef unsigned int unin;//同一个类型能起一样的名字
//typedef double unin;//不同类型不能起一样的名字，会提示：“unin”: 重定义；不同的基类型


typedef int* zhizhen;//指针类型重定义  type：类型 define：定义


typedef struct UN
{
	int a;
}_ST;//因为加了typedef的关系，这里不能当做声明结构体变量使用了
	 //只能当作结构体的新名字来使用

typedef struct  //这是没有名字的结构体
{
	int a;
}_ST1;//如果是没名字的结构体，通过typedef与这里的名字就能给结构体一个名字了



void fun(int a, double b)
{
	printf("%d, %lf \n\n", a, b);
}
//void (*)(int , double)//这就是上述的函数地址类型
typedef void (*pzhi)(int, double);//这就是函数指针类型的重命名

int main(void)
{
	int i = 321654;
	maint a = 515;   //都是int类型，只是给类型换了个名字，使用无区别
	niint b = 9596;
	printf("%d, %d, %d \n\n", i, a, b);

	unin c = 789456;  //可以看到，比起使用原名字unsigned int，要方便一些
	unsigned int d = 55555;
	printf("%d, %d \n\n", c, d);//无符号整型


	zhizhen p = &i;//这样zhizhen'就跟 int* 一样了，只是换个名字而已
	*p = 97456;		//指针类型重命名
	printf("%p, %p, %d, %d\n\n",&i, p, i, *p);


	struct UN n = { 6 };
	_ST u = { 5 };  //结构体类型的重命名，_ST 就相当于struct UN来使用
	printf("%d, %d \n\n", n.a, u.a);

	
	void (*p1)(int, double) = fun;//这是函数指针的声明
	pzhi p2 = fun;//这是函数指针的声明,可以看到，比起上面一行，要简化很多，pzhi直接当作函数指针类型使用
	//void(*)(int, double)//这就是上述的函数地址类型
	p1(55, 89.98);//这是函数调用
	p2(66, 78.12);
	

	system("pause");
	return 0;
}