#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	//int a = 32;     // = 是赋值运算符，读法：将32赋值给变量a
	////55 = 66;      //左侧必须是变量，右侧是常量或者变量都行

	//int b,   //可以这样给变量添加注释
	//	c,   //方便读取记忆
	//	d;   //断点调试时，光标放到变量上出现类似-858993460的数值，说明没有给变量初始化赋值

	//a = b = c = d = 24;    //从右往左赋值的顺序
	////a = b = 45 = d = 12;   //这样的赋值顺序是错误的，因为12赋值给d，d变成常量12，常量12不能给常量45赋值

	//float f = 123.321;     //左侧为目标类型，右侧会转换成左侧一样的类型
	//                       //所以如果左右类型不一样要注意，数据转换时可能会出现一些问题

	//printf("%d %d %d %d \n", a, b, c, d);



	int a = 13;
	//a + 14;
	//输出方式1：通过printf直接输出
	printf("加法的形式：%d,%d,%d,%d\n", a + 14, a + a, 13 + 13, 24 + 2);

	int b;
	int c;
	c = 22 + 33;
	b = a + 14 + c + 24;  //连续加法：变量+变量+常量

	printf("加法的形式：%d,%d,%d,%d\n", b, a + a, 13 + 13, 24 + 2);
	printf("混合运算的形式：%d %d %d %d\n", b * c, b - c, b / c + 2, b - c + a);

	printf("%d %d\n", 456 / 40, 456 % 40);//%：取模，除法分母不能为零，
	                       //浮点型数相除才会有小数点，整数型相除是整数

	printf("%d %d\n", (3 - 1) * 5 - 2 / 1, 5); //小括号与数学计算一样具有高优先级

	system("pause");
	return 0;
}