#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>



int main(void)
{
	//char k;
	//scanf("%c", &k);    //'1'是表示字符，他的编号为49，而1就表示1
	//printf("%d \n", k);
	//					//我们对比下两组，上面的scanf用%c字符输入去接控制台输入的值
	//char l;				//下面的用%d进制的去接控制台输入的值，我们输入1
	//scanf("%d", &l);	//上面打印的结果是49，下面一组打印的是1，
	//printf("%d \n", l); //上面一组存到scanf里时依旧是%c的字符类型，
						//下面一组用%d去接就强制类型转换，导致输入为1输出为1

	char c = 0;
	while (1)
	{
		scanf("%c", &c); //一定要记得取地址符
		if (c >= 65 && c <= 90)
		{
			printf("%c ", c + 32);
		}
		else if (c >= 97 && c <= 122)
		{
			printf("%c ", c - 32);
		}
		else if(c == 10) //输入回车时跳出循环
		{
			break;
		}
	}


	system("pause");
	return 0;
}