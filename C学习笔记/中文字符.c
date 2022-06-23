#include <stdio.h>
#include <stdlib.h>

int main(void)
{				//这里元素个数为3是因为中文占了2个，\0占了一个
	char str[3] = "彧";//char类型一个字符能表示256个字符，中文世界收录的有4万多个，
	printf("%s  \n", str);//2个字符的表示范围有6万多个，刚好能容纳中文符号，所以中文占2字节

	printf("%c%c  \n", str[0], str[1]);//这也能打印中文，就是把中文占的两字节合起来输出
					//注意%c%c之间不能隔东西，空格也不行，必须紧挨着

	printf("%x %x \n", str[0], str[1]);//要得到一个中文的数字码，可以百度
	//也可以利用这种方式得到，去掉两个字节的默认码，合在一起就是了，这里得到的是8faa


	//不想用计算器的话：
	printf("%x %hu \n", *(short*)str, *(short*)str);//这种方式得到的16进制会发现是反的，
	//因为计算机读多字节时地址是从高位到低位读取，导致两个字节的顺序读反了
	

	char temp;//为了解决上面的读反的问题，我们把两个字节交换一下在读取就好了

	temp = str[0];
	str[0] = str[1];
	str[1] = temp;

	printf("%x %hu \n", *(short*)str, *(short*)str);//得到8faa， 10进制：36778
	//%hu是无符号10进制short类型的输出
	//unsigned short a = *(short*)str ;//我们也可以用一个变量来装这个中文


	system("pause");
	return 0;
}