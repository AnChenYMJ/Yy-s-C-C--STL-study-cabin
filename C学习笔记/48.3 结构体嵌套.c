#include <stdio.h>
#include <stdlib.h>

struct Stu
{
	char fullname[10];
	int age;
};

struct Stu1
{
	char truename[10];
	struct Stu st;      //这就是结构体嵌套，可以在结构体定义中声明另一个结构体的变量当作自己的成员
	double height;
};


struct Stu2
{

	struct Stu3
	{
		char fullname[10];//可以在一个结构体1定义中定义另一个结构体1
		int age;		//经测试2中的成员就相当于1中的成员直接调用使用如we.fullname
	};
	struct Stu3 de;//如果输出we.de.fullname，则输出的为0，估计是未初始化
};					//估计成员是从上往下的顺序，2的结构体定义的框架就被略去了，把2的成员当作自己的成员


int main(void)
{
	struct Stu1 at = { "贾克斯", {"花手男孩", 18}, 1.65 };//初始化时把嵌套的部分用花括号括起来方便阅读
	printf("姓名： %s\n英雄名： %s\n年龄： %d\n身高： %lf\n\n", at.truename, at.st.fullname, at.st.age, at.height);
	                                      //取嵌套成员就用at.st.fullname这种形式

	struct Stu2 we = {"五秒男", 30 };  
	printf("英雄名： %s\n年龄： %d\n\n", we.fullname, we.age);


	system("pause");
	return 0;
}