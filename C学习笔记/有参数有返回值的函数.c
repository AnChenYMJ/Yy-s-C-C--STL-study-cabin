#include <stdio.h>
#include <stdlib.h>
 

		}
	}
	*p1 = MaxNum;//可以输出外部变量n，也可以输出内部变量MaxNum
	return MaxNum;
}

int main(void)
{
	int a[8] = { 8, 6, 87, 46, 21, 13, 595, 911 };
	int n = 0;  //注意：有的编译器必须初始化，到了函数里面会报错
	printf("%d %d\n", FindMaxNum(a, 8, &n), n);//n不能写在这行输出，否则输出的是主函数里初始化的值
	printf("%d \n", n);						   //因为还没进入函数进行值变换就输出了

	system("pause");
	return 0;
}