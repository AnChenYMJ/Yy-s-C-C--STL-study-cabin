//#define _CRT_SECURE_NO_WARNINGS   //��������ʹ��scanf���·�����󣬻���ʾ����������д���д����ͷ��
                                  //����д���·������ܽ��scanf�汾�����ݵ�����

#include <stdio.h>
#include <stdlib.h>

#pragma warning(disable:4996)    //�������������λ��д���д��룬�����4996�Ǳ����Ӧ�ı�ţ�
                                 //ÿ������ı�����Ψһ�ģ����ᴦ����Ļ����԰��������������һ�¡�

int main(void)
{
	int a = 222,
		b = 333;
	
	printf("ǰ��%d %d \n", a, b);

	scanf("%d %d", &a, &b);       //����һ��ʹ��scanf_s,��vs2012�汾���ϣ�ʹ��scanf�ᱨ��
	                              //scanf_s��΢��Ϊ�˰�ȫ���Լ�Ū�ģ�ʹ��scanf��ֲ�Ի�ߺܶ࣬��Ϊscanf�Ǳ�׼c�Ĺ涨

	printf("��%d %d \n", a, b);

	system("pause");
	return 0;
}