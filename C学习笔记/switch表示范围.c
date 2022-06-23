#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int a = 64;

	switch (a)
	{
	case 60:
	case 61:
	case 62:
	case 63:
	case 64:          //从上往下找匹配，找到64后，往下执行
	case 65:
	case 66:          //这些都没有可执行的代码，继续往下执行
	case 67:
	case 68:
	case 69:
		printf("及格\n"); //到这里开始执行
		break;            //跳出结构，实现表示范围的灵活性
	case 70:
		break;
	}



	system("pause");
	return 0;
}