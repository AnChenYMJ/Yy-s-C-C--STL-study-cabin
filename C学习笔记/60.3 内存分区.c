#include <stdio.h>
#include <stdlib.h>


void fun()
{
	const char* p = "Keep going~";
	printf("%p \n\n", p);
}

const int b = 55;//ȫ��const����

int main(void)//����ϸ�Ĺ����ڴ������֪ʶ����X-mind��ġ�����������
{
	{
		const char* p = "Keep going~";
		printf("%p \n\n", p);
	}

	{
		const char* p = "Keep going~";
		printf("%p \n\n", p);
	}
			//֤�����ַ��������Ӷ���λ�ÿ�ʼ������򹲴�������λ�ù̶���
	fun();//�ᷢ����������ӡ�ĵ�ַ����ͬ



	const int a = 44;
	int* p = (int*)&a;  //�ֲ�const�����洢��ջ��
	*p = 11;

	int* p1 = (int*)&b;	//ȫ��const�����洢�ڳ����������ܱ��κ���ʽ�޸ĵ�
	*p1 = 15;


	system("pause");
	return 0;
}