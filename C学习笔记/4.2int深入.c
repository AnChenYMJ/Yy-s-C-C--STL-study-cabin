#include <stdio.h>
#include <stdlib.h>


int main(void)
{
	int a = 13;         //�г�ʼֵ���ǳ�ʼ��������ÿ��������������ʼ��
	int b = 15;         //���壬����һ��int���͵ı���b������ֵ15
    //int c;            //����������һ������c
	

	a = 11;               //������������ֵ
	printf("%d %d \n", a, b);
	


	a = b;             //������������ֵ
	printf("%d %d \n", a, b);



	a = b = 20;        //������ֵ����������ִ�У��Ȱ�20��ֵ��b��b�ٸ�ֵ��a
	printf("%d %d \n", a, b);


	system("pause");
	return 0;
}