#include <stdio.h>
#include <stdlib.h>

int fun1(void)
{
	return(5, 6, 7, 9);//当想要多个返回值时，这样的写法是错的，因为这里写成了逗号运算符的格式，
}					   //逗号运算符从左往右执行，最右侧的值就是逗号运算符的结果

int* fun2(void)//注意，这里的int* 是因为返回的return的值是int* 类型的，所以保持一致
{				//这是获得多个返回值的方法，申请一个空间，把空间的首地址返回来，利用数组的方式相当于返回多个值
	int* p = (int*)malloc(sizeof(int) * 3);
	*p = 5;  //p代表这个数组的首地址，这里*p就相当于第一个元素
	p[1] = 7;//指针的下标运算
	p[2] = 4;

	return p;
}

//int* fun3(void)
//{
//	int b[2] = { 4, 8 };
//	int* t = &b;
//	return t;
//}


int* fun4(int* a, int nLength) //现在知道了有多个返回值怎么操作，就能继续之前的同时运算最大值与最小值
{								//的函数封装了
	int i;
	int MaxNum = a[0];
	int MixNum = a[0];

	for (i = 1; i < nLength; i++)
	{
		if (MaxNum < a[i])
		{
			MaxNum = a[i];
		}
		if (MixNum > a[i])
		{
			MixNum = a[i];
		}
	}
	int* p1 = (int*)malloc(sizeof(int) * 2);
	*p1 = MaxNum;
	p1[1] = MixNum;
	return p1;
}

int main(void)
{
	printf("%d \n", fun1());//此时打印的结果是9，说明fun1的返回值是9

	int* a = fun2();//用指针a装p，p是函数里数组的首地址
	printf("%d %d %d \n", a[0], a[1], a[2]);
	free(a); //注意，malloc是在堆区申请的空间，是由程序员申请，由程序员释放
	//，所以注意一定要释放，否则空间一直占用
	

	/*int* l = fun3();
	printf("%d %d \n", l[0], l[1]);*///生成时会提示：返回局部变量或临时变量的地址: b
	//原因是数组是由操作系统申请，是栈区的空间，由操作系统释放，当我们使用时
	//申请的空间出了那个函数，操作系统就会自动释放，但由于c语言对边界越界不扫描，所以不报错
	//我们在主函数中操作使用时，就已经是越界操作了，可能导致运行崩溃
	//所以函数中要用堆区的空间，但注意我们程序员要及时释放。

	
	int c[5] = { 88, 5, 98, 75, 66 };
	int d[6] = { 31, 21, 61, 1, 71, 91 };
	int* f = fun4(c, 5);          //利用数组指针与多个返回值的操作，
	int* g = fun4(d, 6);		  //做到了同时运算最大值最小值的函数封装
	
	printf("c数组最大值：%d  数组最小值：%d \n", f[0], f[1]);
	printf("d数组最大值：%d  数组最小值：%d \n", g[0], g[1]);


	system("pause");
	return 0; 
}