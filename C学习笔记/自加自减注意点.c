#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int a = 10;           //加上小括号也是错的，但是能提高阅读性
	//int b = (a++) + (++a) + (a--);  //同一个变量的自加自减不能在同一个语句中出现两次以上，一个就行了
	                          //c语言中未规定这样的计算，不同编译器的结果是不同的.
	//int b = a++ + a;  这样也是不行的，只要有自加自减，相同的变量就不能重复出现。
	//printf("%d \n", b);

	printf("%d %d %d \n", a, a++, ++a);  //大学教材上有这样的题目，但是这是有歧义的
	//不同编译器的结果是不同的             //在 ; 之前的都算一个语句，就不满足不能出现两次的条件了
	
	int b = 10;
	//如果想要测试，就用单独语句测试
	printf("%d", b);            //10    未变
	printf("%d", b++);          //10    因为后置++用自加前的数参与运算
	printf("%d \n", ++b);          //12    上一句b++在那个语句运算后加1，到了这句再加1，变成12

	int c = 10;
	int d = c++;

	printf("%d %d \n", c, d);    //输出结果为：11 10
	  //在执行 c++ 的自加命令时，先创造一个内存空间，存入原值，使用原值c=10来运算，上面则是把原值赋值给d
	  //而后c本身的内存空间加1，就变成了c=11.

	system("pause");
	return 0;
}