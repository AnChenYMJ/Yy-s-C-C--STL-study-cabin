#include <stdio.h>
#include <stdlib.h>

int fun1(int a)//���������ǣ�int (int) ����ȥ�������� 
{				//���������ɷ���ֵ���� �������������� ����
	printf("���Ǻ���fun1 \n");

	return 5;
}

int fun2(int a)//���������ǣ�int (int)
{
	printf("���Ǻ���fun2 \n");
	printf("���Ǻ���fun2 \n");
	printf("���Ǻ���fun2 \n");
	printf("���Ǻ���fun2 \n");

	return 6;
}

int fun3(int a,int b)//fun3�ĺ��������ǣ�int ��int, int)
{
	printf("���Ǻ���fun3 \n");
	printf("���Ǻ���fun3 \n");
	printf("���Ǻ���fun3 \n");

	return 3;
}


int main(void)
{
	//int fun1(int a)
	//int (*p)(int a)  //int (*p)(int) = fun1�Ǻ���ָ���������ʽ��ע�ⲻҪ��*p��С����ȥ��������
	//�ͱ���˺����ĳ�ʼ������Ϊp�����루int����ϣ���ɺ�������ʽ��
	//int (*p)(int) = fun2;//int (int a)���Ǻ��������ͣ��͸�����int aһ����ȥ�����������Ǳ�������
	int (*p)(int) = fun1; //ȥ�����������Ǻ������ͣ�fun1��fun2��ͬһ�����͵ĺ����������뷵��ֵ�Ĵ�С�޹�
	//int (*p)(int) = fun3; //��ʾ��int(__cdecl*)(int, int)���͡�int(__cdecl*)(int)���Ĳ����б�ͬ
						//֤����
	p(1);//�������ǵ��ú�����

	int (*p1)(int) = &fun2;//fun��&fun���Ǻ����ĵ�ַ�����ռ䲻ͬ��fun�Ŀռ�װ���Ǻ�����ַ��
	//��fun����ĵ�ַ�뺯����ַ��ֵһ��
	(*p1)(1);    //�����ָ��p1װ�ص��Ǻ�����ȡ��ַ����ʽ���ǵ���ʱ��Ҫ��*p1

	
	system("pause");
	return 0;
}