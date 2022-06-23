#include <stdio.h>
#include <stdlib.h>

//加上小括号能避免二义性，根据需要加还是不加，加了就有优先级
#define PRINTF(x) printf("%d \n\n", (x)* 3);

#define PRINTF1(x, y) printf("%d \n\n", x * y)


#define PRINTF2(x, y) printf("%d \n", x * y);//对比查看加不加小括号的差别
#define PRINTF3(x, y) printf("%d \n\n", (x) * (y));


#define SUM(x, y) ((x) + (y)) //加小括号避免二义性
#define MUL(x, y) (x) * (y)   //宏可以像这样来替换为特定运算


#define MYMAX(x, y) ((x) > (y) ? (x) : (y))//求最大值，x>y，输出x，x!>y，输出y

//在宏当中想要换行就只能用反斜杠，但注意，但反斜杠后面什么都不能加，空格也好，注释也好，都不行
#define SUM1(x, y) 3 + 2\
				  -5 - 1\
				 + 1 + 2   //最后一个语句可以不加反斜杠


// \是换行拼接反斜杠后面什么都不能加，空格也好，注释也好，都不行
#define PRI printf("我老婆：");\
			printf("新垣");\
			printf("结衣~");\
			printf("明年结婚\n\n");


#define PJ(x, y) #x ## #y   //#+参数：意思是把传进来的参数都变成字符串，相当于给参数加上""
							//## ：意思是把两个字符串拼接起来

int main(void)
{
	PRINTF(5)
		//printf("%d \n\n", (5) * 3);//这就是上面的宏替换成的结果

	PRINTF1(5, 8);//因为宏定义时未加分号，我们这里手动加上
	//printf("%d \n\n", 5 * 8)  //这就是替换过来的内容


	PRINTF2(2 + 2, 5 - 1)  //结果为11    没加括号：2+2*5-1 == 11
	PRINTF3(2 + 2, 5 - 1)	//结果为16  加了括号：(2+2)*(5-1)
							//根据自己需要家还是不加，但是要清楚它们的差别

		//PRINTF(qwe) //这样就直接报错了，宏是不管类型的，有内容就替换过来
		//printf("%d \n\n", (qwe) * 3);//替换过来运行时才报错的


	printf("%d \n\n", SUM(3+1, 5) * 4);//这里也体现了加小括号的必要性
	printf("%d \n\n", MUL(3+1, 5) * 4);//*法的优先级比较高，可不加


	printf("%d \n\n", MYMAX(3 + 1, 5 - 2));//输出两个数的最大值


	printf("%d \n\n", SUM1(1, 2));//查看换行运算是否成功，这里的两个参数就相当于没用上


	PRI  //测试宏中多行换行打印


	printf("%s \n\n", PJ(结衣酱~, 和我结婚吧！));//测试字符串拼接
	printf("%s \n\n", PJ(Keep going~, 1234));//测试字符串拼接


	system("pause");
	return 0;
}