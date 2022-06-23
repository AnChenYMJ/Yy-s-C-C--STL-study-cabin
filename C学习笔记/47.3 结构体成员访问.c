#define  _crt_secure_no_warnings
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stu
{
	char name[10];
	int age;
	double height;
};


int main(void)
{
	struct stu sd = { "彧", 24, 1.65 };
					//这里可以证明，地址用 -> 访问成员， 而实例变量用变量名+.访问成员
	printf("%s, %u, %lf \n", (&sd)->name, sd.age, sd.height);//这是实例变量：有空间的就是实例变量
	//sd.age 变量名+.+成员名，就是取成员的形式了，成员变量不可以直接使用
	//int a = 12;//结构体变量就跟基本数据变量一样的使用方法


	struct stu* p = (struct stu*)malloc(sizeof(struct stu));//这是申请一块空间，类型为struct stu*
	//大小为sizeof(struct stu)，这块空间的地址被指针p装着

	p->age = 18;//* &的优先级要比 . ->低，所以一定要注意运算符的优先级
	(*p).height = 1.75;//这里可以证明，地址用 -> 访问成员， 而实例变量用变量名+.访问成员
	strcpy(p->name, "yu");//（*p）就是变量本身，所以就是实例变量

	printf("%s, %u, %lf \n", (*p).name, (*p).age, (*p).height);
	//* &的优先级要比 . ->低，所以一定要注意运算符的优先级

	system("pause");
	return 0;
}