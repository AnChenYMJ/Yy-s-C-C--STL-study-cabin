#include <stdio.h>
#include <stdlib.h>


void fun()
{
		printf("Don't waver,Yy, you're strong!\n");
}

struct SM
{
	int a;
	char b;

	void (*p)();//����������ͨ������ָ���������Ӻ�����Ա�Ĳ���

	//void fun()//C���Ա�׼�У������ڽṹ�����������庯��
	//{
	//	printf("Don't waver,Yy, you're strong!");
	//}

};


int main(void)
{	//C������ʹ�ýṹ��Ҫ��suruct
	struct SM ST = {1, 'Y', fun};//����Ҫ��ʼ���ṹ�������������ָ�벻֪��ָ���Ǹ�����
	ST.p();//��������ͨ��ָ�����ĸ��ṹ����Ӻ�����Ա
	for (int o = 0; o <= 3; o++)
	{
		for (int i = 10; i >= 5; i--)
		{
			printf("%d \n", i);
		}
	}

	printf("%d \n", i);//error C2065: ��i��: δ�����ı�ʶ��

	for (int i = 10; i >= 5; i--)
	{
		printf("%d \n", i);
	}

	system("pause");
	return 0;
}