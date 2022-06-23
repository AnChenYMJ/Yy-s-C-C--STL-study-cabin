#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	printf("qwe\rbawe\n");//\r是回车，这里的过程是这样：先打印qwe，遇到回车\r，光标回到第一个q的位置
						//然后打印后面的bawe，这样就把前面面的qwe覆盖掉了
	printf("qwe\rba\n");//先打印qwe然后回到q打印ba，就变成了bae

	printf("wda\tdawd\n");//\t:水平制表符，以八位为单位空开，如果前面有内容，比如有3位有内容，则空5位，

	printf("\'  \" \\  %% \n");//这三个要特殊，因为很容易跟相同符号结合，要想打印则必须加上\
	//两个%输出一个%	不常用到// \\以后要经常用到，比如要打印绝对路径\run\wode\awm,就必须\\run\\wode\\awm
						//否则与字母结合就变成别的含义了，


	printf("%u \n", strlen("\n"));//strlen是查看字符串长度的函数
	printf("%u \n", strlen("\r"));//可以看到，这些转义字符都是1字节
	printf("%u \n", strlen("\t"));
	printf("%u \n", strlen("\\"));
	printf("%u \n", strlen("\w"));//\w没有什么作用跟意义，但是字母加了\就是1字节
								  // 提示：不可识别的字符转义序列

	//\+数字     （1~3个） 0~377  是8进制    对应10进制 0~255 
	//\ + 0 + 数字（1~2个） 0~77    是8进制    对应10进制 0~63
	//	\ + x + 数字（1~2个） 0~ff      是16进制   对应10进制 0~255

	//注意\+x+数字，只要是\x后面接的数字都当成16进制的数了

	printf("%u \n", strlen("\58"));//2
	//printf("%u \n", strlen("\555"));//报错：对字符来说太大
	//printf("%u \n", strlen("\5555"));//报错：对字符来说太大
	printf("%u \n", strlen("\077"));//1
	printf("%u \n", strlen("\fff"));//3
	printf("%u \n", strlen("\018"));//2
	printf("%u \n", strlen("\xfs"));//2



	system("pause");
	return 0;
}