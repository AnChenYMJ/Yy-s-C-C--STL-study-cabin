#include <stdio.h>
#include <stdlib.h>


int main(void)
{
	int a = 10;
	a = a + 7;  //�������Խ����Լ�����
	a += 7;     //+= ����һ��������������������һ���������Լ�����

	a = a - 7;
	a -= 7;

	a = a * 7;
	a *= 7;

	a = a / 7;
	a /= 7;

	a = a % 7;
	a %= 7;

	printf("%d \n", a);


	system("pause");
	return 0;
}