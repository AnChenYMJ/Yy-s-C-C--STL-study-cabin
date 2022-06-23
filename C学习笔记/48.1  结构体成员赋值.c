#define _crt_secure_no_warnings
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
	struct stu sd = { "上官婉儿", 25, 1.65 };//声明初始化变量
	printf("姓名： %s  \n年龄： %d\n身高： %lf \n\n", sd.name, sd.age, sd.height);

				//注意strcpy拷贝字符串，拷贝其它类型的会出错，因为它自动在结尾加\0
	strcpy(sd.name, "上官丸子");	//这些就是单个成员赋值
	sd.age = 36;  //实例变量类型用.
	(&sd)->height = 1.21;//地址类型用->
	printf("姓名： %s  \n年龄： %d\n身高： %lf \n\n", sd.name, sd.age, sd.height);


	sd = (struct stu){ "电玩小子", 8, 1.11 };//这是修改复合文字结构的方式//注意这是c99新标准，在vis 2013以后版本才行
	printf("姓名： %s  \n年龄： %d\n身高： %lf \n\n", sd.name, sd.age, sd.height);


	struct stu sd1 = { .name = "提款7号" };//这是初始化指定元素的方式，与数组一样，其它未初始化的默认为0
	printf("姓名： %s  \n年龄： %d\n身高： %lf \n\n", sd1.name, sd1.age, sd1.height);
			//其实结构体的本质就是数组


	system("pause");
	return 0;
}