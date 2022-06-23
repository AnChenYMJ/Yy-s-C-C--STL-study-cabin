#include <stdio.h>
#include <stdlib.h>

#define ONE 1  //ONE是我们起的名字，书写规范是全大写，空格后面是替换的内容
#define ONE 3  //重名是可以的，以离调用位置最近的生效
#define ONE2 2
#define ONEONE ONE2 //跟重命名有点像，但不同，这里是替换，ONEONE 替换成ONE2 ONE2又替换成1


#define ONE3 1+5*6-3


#define PRINTF printf("%d, %d, %d \n\n", ONE, ONEONE, ONE3);

#define PRINTF1 printf("%d, %d, %d \n\n", ONE, 



#define THREE  //这样是可以的，相当于声明了但未初始化

#define ONE4 1+3
#define ONE5 (1+3)

int main(void)
{
	printf("%d, %d, %d\n", ONE, ONE2, ONEONE);//宏的本质是替换，使用ONE时把ONE替换成1
	printf("%d, %d, %d\n\n", 1, 2, 2);//上面一行代码，其实就是替换成这行再运算打印


	printf("%d \n", ONE3);//把ONE3替换成1+5*6-3，再运算打印，就跟下面一行一样
	printf("%d \n\n", 1 + 5 * 6 - 3);//这就是宏替换的本质，把ONE3的内容，完全替换到这里来


	PRINTF  //直接使用宏的名字原因是，宏会把内容完全替换过来，
	//变成printf("%d, %d, %d \n\n", ONE, ONEONE, ONE3);而这是一条完整的语句，能正常运行

	PRINTF1 ONEONE, ONE3);//这更能体现宏替换的本质，完整语句的前半部分替换到宏的位置，与我们写的
	//后半部分组成一条完整语句


	printf("%d \n\n", 2 * ONE4);//结果为5，ONE4替换成1+3，成了2*1+3==5
								//如果想要计算2倍的ONE4的值，定义宏时写成(1+3)，这样替换过来就添加了小括号
	printf("%d \n\n", 2 * ONE5);//结果为8，式子成了2*(1+3)


	system("pause");
	return 0;
}