#include <stdio.h>
#include <stdlib.h>

int fun1(int n) //���������������ģ�����2����ִ��else�����е�fun1��չ������������fun1��չ��
{				//ֱ��չ����else if�Ļ������ٰ�����չ����������ֱ���������л������͵õ����ǵ�ֵ
	if (1 == n)
	{
		return 1;//��ͨ�ʽ��д����������һ���������ľ���ֵ
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
	{							//������ʵ�������Ľ׳�
		return n * fun2(n - 1);//��Ҫд��fun2(n) * fun2(n-1)
	}							//��Ϊÿִ�е�fun2(n)���ٽ��뺯��������fun2(n)�ٽ���
}								//��ͽ�������ѭ�����±�ջ

int main(void)
{
	printf("%d \n", fun1(5));//����쳲���������

	printf("%d \n", fun2(5));//�������Ľ׳ˣ�����1*2*3*4*5


	system("pause");
	return 0;
}