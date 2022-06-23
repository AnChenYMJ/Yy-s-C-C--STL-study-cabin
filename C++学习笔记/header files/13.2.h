#pragma once
#include <iostream>
using namespace std;

inline void fun(int i)//内联函数可以有多个定义
{	
	cout << (i * i) << endl;	//一般来说内联函数把定义写在头文件中，注意是定义不是声明
}