#include <stdio.h>
#include <stdlib.h>

void fun1(int* p)
{
	printf("p = %p \n", p);
	p = NULL;
	printf("p = %p \n", p);
	//*p = 848;  //���е��˴�ʱ�������󣬿���������*p���޸�ԭֵ����Ϊp�ĵ�ַ��p1����
	//printf("*p = %d \n", *p);
}

void fun2(int** p2)//ע�⣬p3��ָ�룬��p2��װp3�ĵ�ַ�ģ�����p2�Ƕ���ָ������
{					//ע�⣬��ַ��Ҫ�޸�˭�ʹ�˭�ĵ�ַ������˵ֻҪ�ǵ�ַ���;Ϳ���
	printf("p2 = %p \n", p2);
	*p2 = NULL;  //��ַ�������޸�ԭֵp3
	printf("p2 = %p \n", p2);//��p2�����ֵ����
}

int main(void)
{
	int a = 56;
	int* p1 = &a;
	printf("p1 = %p \n", p1);
	fun1(p1);				 //����ͨ������p���޸�p1ָ��ĵ�ַ����Ϊp�Ǳ�p1��ֵ��a�ĵ�ַ
	printf("p1 = %p \n", p1);//�������޸�pֻ���޸���pװ�����ݣ�û���޸ĵ�p1
	//printf("a = %d \n", a);
	

	int b = 98;
	int* p3 = &b;
	printf("p3 = %p \n", p3);
	fun2(&p3);//ע�⣬��ַ��Ҫ�޸�˭�ʹ�˭�ĵ�ַ������˵ֻҪ�ǵ�ַ���;Ϳ���
	printf("p3 = %p \n", p3);//ͨ��װ��p3��ַ�Ķ���ָ��p2�ĵ�ַ�������ɹ��޸�ָ��p3�����ݣ�ָ��


	system("pause");
	return 0;
}