#include <stdio.h>         
#include <stdlib.h>        //standard：标准     library:图书馆

int main(void)
{
	printf ("hello yy\n"); //  \n:转义字符，就像java里的转行符
	printf ("坚持住\n");   //  在这里printf 是内建函数，就是编译器本身给它定义了，不需要头文件定义也能运行
	printf ("啊~~~\n");    //建议把头文件写上，为了提高移植性，因为不是所有编译器都这么做
	                       //内建函数就是编译器为了效率与方便，把一些常用函数给定义了，就不需要用头文件来给函数定义
	system ("pause");      //pause：暂停
	return 0;              //return：返回
}