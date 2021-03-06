#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int a = -154;
	int b = ~a;

	printf("%d \n", b);//打印的结果是153，下面分析下为什么得到这个结果
	//先看计算机内的存储方式：（负数的存储方式）(有符号)
		---- ----
-154：	1001 1010 //先把154的二进制转换出来，这些都是数据位
	   10110 0101 //最前面的1，是符号位，表示这是个负数，
			   +1 //数据位取反之后再加1
	   10110 0110 //这就是在计算机内，-154的存储方式

	//再来看怎么得到b的值：
	   10110 0110 //这是-154在计算机内存储的方式
	  ~10110 0110 //执行运算符~（按位取反）
	   01001 1001 //直接取反 ~ 是按位取反，连最前面的符号位1也取反了
	   01001 1001 == 153//二进制01001 1001就是153的二进制

	
	int c = 165;
	int d = ~c;

	printf("%d \n", d);//打印的结果是-166，下面分析下为什么得到这个结果
	//先看计算机内的存储方式：（正数的存储方式）（有符号）
		---- ----
  165：	1010 0101 //不用任何操作，这就是正数在计算机内的存储方式
	   01010 0101 //最前面的0是符号位，0代表这是个正数
				  //正数还是负数都是按补码形式在计算机内存储的，
				  //正数的补码就是它本身，负数的补码就是数据位取反，再+1

	//再来看怎么得到d的值：
		---- ----
  165：01010 0101 //计算机内165的存储形式，最前面的0是符号位，0代表这是个正数
	  ~01010 0101 //执行运算符~（按位取反）
	   10101 1010 //注意：运算符~（按位取反）会把符号位也取反，这时符号位变成1，代表这个数是负数

			//现在要把改变后的值还原成数据d
	   10101 1010 //这就是把c按位取反~后得到的d在计算机里存储的形式
			   -1 //因为负数转变成计算机存储的补码形式时+1了，现在还原要-1
	   10101 1001 //再把数据位取反（负数存储时的步骤逆着来一遍）
	   11010 0110 //符号位1代表这是负数，1010 0110 == 166
				  //再加上符号-就得到了-166

		//为什么这里超出了8位呢，是因为我们的数超出了char的-128~127，是int类型
		//有符号的char7位二进制就能表示完，所以c3程序员的演示是8位，第一位是符号位，剩下的7位是数据位
		//char的有符号最高的127对应的二进制：0111 1111，
		//而无符号的char不需要符号位对应的最大值255的二进制：1111 1111
		//其实还有一点问题，详见63.2的笔记


	system("pause");
	return 0;
}