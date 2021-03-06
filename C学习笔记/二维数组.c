#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int a[4][3];  //二维数组的声明方式就是这样，
	//这里的a的意思是，二维数组a有4个一维数组作为它的元素，而每个一维数组有3个元素数值

	printf("%d \n", sizeof(a));//查看二维数组的所占内存大小
	       //4 * 3 * 4 = 48  4个一维数组，每个一维数组有3个数值元素，每个数值是int类型有4字节内存

	int b[4][3] = { {3, 5, 8}, {5, 8, 9}, {8, 8, 8}, {9, 9, 9} };
	             //可截断调试查看对应数组的元素个数与数值


	int b1[4][3] = { {3, 5, 8},    //这就是行列式的看法，也可以看作坐标的看法
					{5, 8, 9},     //比如第3个一维数组的第1个元素，坐标是3行1列
					{8, 8, 8},
					{9, 9, 9} };	//这是完整初始化

	int b2[4][3] = { {3, 5, 8}, {5, 8, 9} };//这是不完整初始化，未指定的元素默认是0

	int b3[4][3] = { {3}, {5, 8, 9}, {8, 8}, {9, 9, 9} };
									//这种初始化，未指定的元素默认为0

	int b4[4][3] = { 3, 5, 8, 5, 8, 8, 8, 9 };//这样的初始化就依次从第一个一维数组的第一个元素
											   //依次排序下去，为指定的默认为0

	int b5[][3] = { {3, 5, 8}, {5, 8, 9}, {8, 8, 8}, {9, 9, 9} };
	   //一维数组的元素个数框不能为0，跟一维数组一样，未定义有多少个一维数组，
	   //有多少初始化的一维数组数量就算多少个

	int b6[][3] = { 3, 5, 8, 5, 8, 9, 8, 8};
	  //从第一个一维数组的元素排序，最后有多少一维数组算多少，

	system("pause");
	return 0;
}