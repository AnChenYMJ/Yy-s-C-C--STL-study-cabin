#include <stdio.h>
#include <stdlib.h>

#include <float.h>              //使用宏 FLT_MIN必须的头文件

int main(void)
{
	
	printf("%e \n", FLT_MIN);   //FLT_MIN表示一个宏，意思是float最小的，选中它右键转到定义
	                            //就能找到float与其他浮点型的最小正值与最大负值
	                     
	printf("%e \n", 0);       
	printf("%e \n", 0.0);    //浮点型中输出0时，不能使用0，而是使用0.0

	system("pause");
	return 0;
}