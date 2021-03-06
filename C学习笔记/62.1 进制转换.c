#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	//基数相加法
	10 -> 10		//按10进制的运算规则来算
		5643 == 3*10^0 + 4*10^1 + 6*10^2 + 5*10^3 == 5643(10进制)

	16 -> 10
	0xFB9				//B		  //F
		0xFB9 == 9*16^0 + 11*16^1 + 15*16^2 == 4025(10进制)

	8 -> 10
		5732 == 2*8^0 + 3*8^1 + 7*8^2 + 5*8^3 == 5732(10进制)


//要转换成什么进制，就按什么进制的规则来算，所以一般转换成10进制
//转换成10进制更符合我们从小学到的10进制的运算规则的思维
	16 -> 8			//按8进制的运算规则来算
		0xFB9 == 11*8^0 + 13*8^1 + 17*8^2 == 7671(8进制)



//反转取余法
	10 -> 8        //就是按10进制运算规则，把余数倒着拼接在一起，就变成了8进制
		645 == {645/8 == 80-----5},{80/8 == 10-----0},{10/8 == 1-----2},{2/8 == 0-----1} == 1205

	16 -> 8			//不符合我们习惯的10进制的算法，所以一般把反转取余法跟基数相加法结合方便我们运算
		0xFB9 == (好麻烦不算了)

		//一般把反转取余法跟基数相加法结合方便我们运算，先转换成10进制，再转换成想要的进制
		//两种算法都能独立在任意进制间转换，只不过一般人脑会很麻烦，所以一般要先变成10进制再算


	//16进制的一位，刚好对应着二进制的4位
	16：	 B		D		4		9
	2： 1011   1101    0100    1001

	16:	8		4		2		1	//8421码的对应关系，
	2: 1000	   0100    0010    0001

	16: BA9
	2:	1011 1010 1001
	system("pause");
	return 0;
}