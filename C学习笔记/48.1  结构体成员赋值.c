#define _crt_secure_no_warnings
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stu
{
	char name[10];
	int age;
	double height;
};


int main(void)
{
	struct stu sd = { "�Ϲ����", 25, 1.65 };//������ʼ������
	printf("������ %s  \n���䣺 %d\n��ߣ� %lf \n\n", sd.name, sd.age, sd.height);

				//ע��strcpy�����ַ����������������͵Ļ������Ϊ���Զ��ڽ�β��\0
	strcpy(sd.name, "�Ϲ�����");	//��Щ���ǵ�����Ա��ֵ
	sd.age = 36;  //ʵ������������.
	(&sd)->height = 1.21;//��ַ������->
	printf("������ %s  \n���䣺 %d\n��ߣ� %lf \n\n", sd.name, sd.age, sd.height);


	sd = (struct stu){ "����С��", 8, 1.11 };//�����޸ĸ������ֽṹ�ķ�ʽ//ע������c99�±�׼����vis 2013�Ժ�汾����
	printf("������ %s  \n���䣺 %d\n��ߣ� %lf \n\n", sd.name, sd.age, sd.height);


	struct stu sd1 = { .name = "���7��" };//���ǳ�ʼ��ָ��Ԫ�صķ�ʽ��������һ��������δ��ʼ����Ĭ��Ϊ0
	printf("������ %s  \n���䣺 %d\n��ߣ� %lf \n\n", sd1.name, sd1.age, sd1.height);
			//��ʵ�ṹ��ı��ʾ�������


	system("pause");
	return 0;
}