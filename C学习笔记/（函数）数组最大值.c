#include <stdio.h>
#include <stdlib.h>

int main(void)   //如果要选很多数组中分别的最大值与最小值，就要挨个粘贴复制修改
{				 //就会很麻烦，下一节中就会介绍函数的作用与优势
	int a[8] = { 56, 78, 12, 3, 45, 94, 656, 89 };
	
	int MaxNum = a[0];
	int MixNum = a[0];
	int i;

	for (i = 0; i < 8; i++)  //利用循环选出数组里的最大值与最小值
	{						 //比较一开始执行了自身比较，这一步其实可以省略掉
		if (MaxNum < a[i])
		{
			MaxNum = a[i];
		}
		if (MixNum > a[i])
		{
			MixNum = a[i];
		}
	}

	printf("a数组最大值：%d \n", MaxNum);
	printf("a数组最小值：%d \n", MixNum);


	int b[7] = { 1, 56, 98, 78, 60, 54, 23 };

	int MaxNumb = b[0];
	int MixNumb = b[0];

	for (i = 1; i < 7; i++)
	{
		if (MaxNumb < b[i])
		{
			MaxNumb = b[i];
		}
		if (MixNumb > b[i])
		{
			MixNumb = b[i];
		}
	}

	printf("b数组最大值：%d \n", MaxNumb);
	printf("b数组最小值：%d \n", MixNumb);


	system("pause");
	return 0;
}