#include <stdio.h>
#include <stdlib.h>

void fun1(int* p1, int* p2)
{
	printf("%d, %d \n", *p1, *p2);
	int m = *p1;     //����һ�ֱ��������ķ���
	*p1 = *p2;  //���д��*p2 = *p1
	*p2 = m;	//*p1 = m     �򶼱��*p1��ֵ��
	printf("%d, %d \n", *p1, *p2);

}

void fun2(int* p3, int* p4)
{
	printf("%d, %d \n", *p3, *p4);
	int m = *p3;     //������һ�ֱ��������ķ���
	int n = *p4;
	*p4 = m;
	*p3 = n;
	printf("%d, %d \n", *p3, *p4);

}

void fun3(int a3, int a4)
{
	printf("%d, %d \n", a3, a4);
	int k = a3;
	a3 = a4;
	a4 = k;
	printf("%d, %d \n", a3, a4);//����ֻ�Ǻ�����ı��������ˣ��ⲿ��û��
}
int main(void)
{
	int a = 5;
	int b = 7;
	printf("%d, %d \n", a, b);
	fun1(&a, &b);


	int c = 8;
	int d = 3;
	printf("%d, %d \n", c, d);
	fun1(&c, &d);


	int e = 8;
	int f = 3;
	printf("%d, %d \n", e, f);
	fun3(e, f);

	system("pause");
	return 0;
}