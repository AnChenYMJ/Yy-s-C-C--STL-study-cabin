#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	printf ("%d \n", 16);              //格式化输出符号  转义字符； 以10进制整数形式 输出 数据/参数

	printf ("我们的数： %d yes \n", 16);  //注意： 后面的 " 不包括参数，不然会输出错误

 	printf ("现在 %d 时 %d 分 %d 秒 \n", 18 , 54 , 56); //输出的数据间用逗号隔开

	printf ("%d , %o , %x , %X \n ", 16, 16, 16, 16);   //%d：10进制整数类型 %o：8进制整数类型 %x：16进制整数类型
	                                                    //%X：16进制整数类型，但输出为大写

	system ("pause");
	return 0;
}