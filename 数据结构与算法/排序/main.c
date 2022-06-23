#include <stdio.h>
#include <stdlib.h>


//查找算法
//顺序查找，时间复杂度O(2n)
int Sq_Search(int* a, int n, int key)//a为要查找的数组，n为要查找的数组的长度，key为要查找的关键字
{
	for (int i = 0; i < n; i++)
	{
		if (a[i] == key)
			return i;
	}
	return 0;
}
//顺序查找优化版：时间复杂度O(n)
int Sq_Search2(int* a, int n, int key)
{
	int i = n;
	a[0] = key;
	while (a[i] != key)
		i--;
	return i;
}
//输出姓名、学号，成绩
struct XueSheng
{
	int XH;
	char* XM;
	int CJ;
};
int ShuChu(struct XueSheng wo[], int n, int key)
{

	for (int i = 0; i < n; i++)
	{
		if (wo[i].XH == key)
			return i;
	}
	return -1;
}




int main(void)
{
	//查找算法
	{
		struct XueSheng XS[4] = { {2012, "小甲鱼", 88},
							  {2013, "Yy", 30},
							  {2014, "dream", 90}
		};
		int a = ShuChu(XS, 4, 2013);
		printf("%d\n%s\n%d", XS[a].XH, XS[a].XM, XS[a].CJ);
	}
	

	system("pause>0");
	return 0;
}