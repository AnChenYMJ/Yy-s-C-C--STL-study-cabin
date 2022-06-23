#include <stdio.h>
#include <stdlib.h>

int main(void)
{				//这里每个元素就是字符串的地址，因为""会把地址返回来
	char* str1[4] = { "K", "eep ", "go", "ing~" };
				//这就是字符串数组，类似于指针数组，每个元素就是指针
	str1[1] = "woca";//而这里的操作是对栈区修改的，因为常量字符串赋值到栈区的空间里了
	//*str1[1] = 'w';//运行到这里报错，常量字符串是不能修改的
	printf("%s", str1[0]);
	printf("%s", str1[1]);//这字符串数组的每个元素就是常量字符串的地址，而常量字符串是不能修改的
	printf("%s", str1[2]);
	printf("%s", str1[3]);

	
	char str[4] = "asd";//这就相当于一维数组

	char str2[3][6] = { "Keep ", "going", "~!" };//这就是二维字符数组的声明初始化
	printf("%s", str2[0]);//会发现跟上面的字符串数组极其类似
	printf("%s", str2[1]);//对应的一维数组就是字符串，对应的一维数组元素就是每个字符
	printf("%s", str2[2]);//二维字符数组是将常量字符串复制了一份儿装进栈区数组


	system("pause");
	return 0;
}