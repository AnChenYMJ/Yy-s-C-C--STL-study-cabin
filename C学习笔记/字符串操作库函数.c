#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	char* p = "hello";//用指针p装""返回的地址

	size_t a = strlen("hello");//这个函数是读取字符串长度，这里得到的结果是5，这个函数不计算\0
	printf("%d \n", a);

	
	int b = strcmp("zxcvb", "zxcfg");//这个函数是比较两个参数的大小：当参数1 > 参数2 时 输出 >0
	printf("%d \n", b);				 //当参数1 < 参数2 时 输出 <0  当参数1 = 参数2 时 输出 =0
	//比较的过程是这样，先从第一位开始比较，然后第二位，第三位，直到遇到不同的值，这里v比f大 输出>0
	//比较只比对应位数大小，跟字符串长度无关
	//if((strcmp("zxcvb", "zxcfg");) > 0)//以后会经常用这个函数，配合if语句使用

	int c = strncmp("zxcvb", "zxcugfaw", 4);//这个函数也是比较两个参数的大小
	printf("%d \n", c);		//比strcmp多了个参数，这个参数表示比较前多少位，这里是比较前四位
	//这个函数没有_s版本，因为他不涉及内存写入，只是比较


	char str1[20] = {'k', 'e', 'e', 'p', 0};

	//strcat(str1, " going~");//strcat 的作用是将参数二拼接到参数1上，注意别越界

	//strcat_s(str1, 20, " going~!");//strcat_s多了个限制字节的参数

	//strncat(str1, " going~!", 3);//strncat比strcat多了个can参数，是表示拼接几个的意思

	strncat_s(str1, 20, " going~!", 3);//strncat_s比strncat多了个限制字节的参数
										//参数二表示参数一的字节数
	printf("%s \n", str1);			//以上4个是字符串拼接的函数


	int d = atoi("36778asdf"); //这个函数是把字符串转换为整型，在返回来
	printf("%d \n", d);		//如：ab23，则不返回，第一位不是数字就不往下转换了
							//如12ab34，则转换为12，遇到字母就不转换了
	char* p1 = "520chenqi";
	int e = atoi(p1);  //这里不太明白，为什么指针能转换原值，可能是本来就是要输入char*的地址类型
	printf("%d \n", e);//"520chenqi"与"36778asdf"也是char*地址类型，""就是把常量字符串的地址返回来
						//原来如此，懂啦懂啦


	char str2[21] = "Keep";//一般字符数组初始化为0或者固定字符，以免出错

	//_itoa( 324, str2, 10 );//这个函数的作用是把数值转换成字符串类型
						//参数1是要转换的数值，参数2是要存放的字符数组，参数3是几进制转换
	_itoa_s(324, str2, 21, 2);//这句的参数3是参数2的数组的字节数

	printf("%s \n", str2);



	char str3[40] = { 0 };  //这个函数功能强大，叫做：格式化字符串，就是把各种类型的转换成字符串连接起来
	sprintf(str3, "%d, %c, %s, %f", 32, 'u', "keep", 26.02f);
	printf("%s \n", str3);//参数1是要存放的字符数组，参数2是要输出的类型，参数3就是具体要输出的东西



	system("pause");
	return 0;
}
