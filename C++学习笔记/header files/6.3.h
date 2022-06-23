
#ifndef	AAA		//这是C语言的防止头文件重复包含，移植性比较好
#define AAA

void kfihiko();

#endif 


#pragma once//这是C++的防止头文件重复包含的方法，比起C语言要更简洁，但是移植性不太好，部分编译器支持

void jdbgfy(int y, double c, char o, float f);
//刚才只写头文件编译报错了，说无法解析的外部符号，原来是工程里没有主函数，所以报错