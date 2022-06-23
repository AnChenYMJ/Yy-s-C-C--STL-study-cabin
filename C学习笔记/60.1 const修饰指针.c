#include <stdio.h>
#include <stdlib.h>


const int fun(const int a)//const能修饰函数的返回值与参数
{						//这样的话就不能修改返回值
	int b;				//也不能在函数内修改传进来的参数了
}



int main(void)
{
	int a = 12;
	int b = 13;

	//int const* p = &a;//这两行定义指针的语法是一样的效果
	const int* p = &a;//const能修饰指针，这里修饰的是*p，那就不能通过*p操作a的空间了
	printf("%d \n\n", *p);	
	//*p = 21;//错误：左值指定 const 对象
	a = 21;   //在59.3也提过，一块空间的入口有指针与变量名
	//上面修饰了*p，*p不能修改空间，但没有修饰变量名，现在变量名能修改
	printf("%d \n\n", *p);

	p = &b;		//但是因为修饰的是*p， p本身还是能够更换指向地址的
	printf("%d \n\n", *p);



	int c = 14;
	int d = 15;

	int* const p2 = &c;//这样的写法，把const放在*与指针之间，这样就只是修饰p2了
	//p2 = &d;//提示：左值指定 const 对象，p2就不能修改指向对象了
	printf("%d \n\n", *p2);

	*p2 = 41;//但因为只是修饰p2，*p2是没被修饰的，可以正常使用*p2修改空间内容
	printf("%d \n\n", *p2);



	int e = 16;
	int f = 17;

	const int* const p3 = &e;//这样的写法就能把*p3与p3都修饰了
	//p3 = &f;//报错：左值指定 const 对象
	//*p3 = 61;//报错：左值指定 const 对象	两个都不能修改



	const char* g = "Keep going~";//要是存在用指针修改常量字符串，在编译时就会报错提示
	//*g = "woeoeo";//错误提示：左值指定 const 对象

	char* h = "just go";
	*h = 'h';//某些编译器编译不会给这里提示，要运行时才会报错，有些编译器还不知道是哪里出错了
	//就很麻烦，要是使用const就能在编译时就报错提示

	system("pause");
	return 0;
}