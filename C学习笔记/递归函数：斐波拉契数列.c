#include <stdio.h>
#include <stdlib.h>

int fun1(int n) //运行流程是这样的，超过2以上执行else，运行到fun1，展开，还是遇到fun1再展开
{				//直到展开到else if的基本数再挨个再展开加起来，直到加完所有基本数就得到我们的值
	if (1 == n)
	{
		return 1;//有通项公式的写法里起码有一个基本数的具体值
	}
	if (2 == n)
	{
		return 1;
	}
	else
	{
		return fun1(n - 1) + fun1(n - 2);
	}
}

int fun2(int n)
{
	if (n == 1)
	{
		return 1;
	}
	else
	{							//这样就实现了数的阶乘
		return n * fun2(n - 1);//不要写成fun2(n) * fun2(n-1)
	}							//因为每执行到fun2(n)就再进入函数再遇到fun2(n)再进入
}								//这就进入了死循环导致爆栈

int main(void)
{
	printf("%d \n", fun1(5));//这是斐波拉契数列

	printf("%d \n", fun2(5));//这是数的阶乘，就是1*2*3*4*5


	system("pause");
	return 0;
}