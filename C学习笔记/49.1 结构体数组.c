#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct wzry
{
	char truename[10];
	int age;
};


int main(void)
{		//���ǽṹ�������������ʼ����ʽ����ͬ�����û����Ÿ����ܸ������������Բ��ֳ�ʼ��
		//���û����Ÿ����Ļ��ͻ����ά����һ��������ֵ�����׵������Ͳ�ͬ�ı���
	struct wzry fs[3] = { {"��֪����", 24}, {"С��"}, {"槼�", 4000} };
	printf("������ %s\n��ͣ� %d\n\n", fs[0].truename, fs[0].age);
	printf("������ %s\n��ͣ� %d\n\n", fs[1].truename, fs[1].age);
	printf("������ %s\n��ͣ� %d\n\n", fs[2].truename, fs[2].age);


	strcpy(fs[1].truename, "��ͷ��̫");//�ṹ��������ַ�����ֵ��ʽ��ע��strcpy���ַ����ĸ�ֵ��ʽ
	printf("������ %s\n��ͣ� %d\n\n", fs[1].truename, fs[1].age);


	fs[1] = (struct wzry){ "װ��̫��", 40 };
	printf("������ %s\n��ͣ� %d\n\n", fs[1].truename, fs[1].age);


	system("pause");
	return 0;
}