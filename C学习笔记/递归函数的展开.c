#include <stdio.h>
#include <stdlib.h>


void fun(int n)
{
	if (n > 0)  //�ڵݹ麯���ıʼ����Ѿ�˵������ӡ���Ϊ��5 4 3 2 1 1 2 3 4 5
	{
		printf("%d  ", n);//���·����ǰ���չ��������������й��̣�
		fun(n - 1);
		printf("%d  ", n);//ע�⣺չ���Ĵ��벻��ִ�У������ﲻ�ܶ��庯��������ֻ�Ƿ�������õģ�
	}					  //��ʦʹ��word�ܱ�ע��ɫ���Ҿ�ֱ��д�������
}

void fun(int n)//��ʱn == 5
{
	if (n > 0)//5 > 0 ���� 
	{
		printf("%d  ", n);//��ӡn��n == 5
		void fun(int n)//ִ��n-1
		{
			if (n > 0)//4 > 0 ����
			{
				printf("%d  ", n);//��ӡn��n == 4
				void fun(int n)//ִ��n-1
				{
					if (n > 0)//3 > 0 ����
					{
						printf("%d  ", n);//��ӡn��n == 3
						void fun(int n)//ִ��n-1
						{
							if (n > 0)//2 > 0 ����
							{
								printf("%d  ", n);//��ӡn��n == 2
								void fun(int n)//ִ��n-1
								{
									if (n > 0)//1 > 0 ����
									{
										printf("%d  ", n);//��ӡn��n == 1
										void fun(int n)//ִ��n-1
										{
											if (n > 0)//0 ��> 0 ����ȥ
											{
												printf("%d  ", n);//��ִ��
												fun(n - 1);		  //��ִ��
												printf("%d  ", n);//��ִ��
											}
										}
										printf("%d  ", n);//���⿪ʼ����ִ�д�ӡ��n == 1
									}
								}
								printf("%d  ", n);//n == 2
							}
						}
						printf("%d  ", n);//n == 3
					}
				}
				printf("%d  ", n);//n == 4
			}
		}
		printf("%d  ", n);//n == 5
	}					
}

//���Ͼ��Ƿ������Ǽ�������̣�����ִ�е�n-1�������ڽ��룬�����n==0ʱ���ִ�������ִ���°�ߴ���
//���ͱ����5 4 3 2 1 1 2 3 4 5

int main(void)
{
	fun(5);


	system("pause");
	return 0;
}