#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char str1[5] = { 'd', 'f', 'g', 'h', '\0' };
	char str2[5] = { 'd', 'f', 'g', 0 };
	char str3[5] = { 'd', 'f' };  //����������Ԫ�ظ������ַ��������һ���ַ�Ϊ0��ע���Խ��

	printf("%s  \n", str3);
	//setbuf(stdin, NULL);

	char str4[5];   //��Ҳ����Ԫ�ظ������ַ���
	//str4 = { 'q', 'w', 'e', '\0' }; //������ʱû�г�ʼ�������ܹ�������ֵ��
	str4[0] = 'q' ;  //����ʱ���û�г�ʼ����ֻ������һ��һ���ĸ�ֵ
	str4[1] = 'w' ;
	str4[2] = 'e' ;
	str4[3] = '\0' ;//ע�������0��β,һ��Ҫ�ֶ����\0

	printf("%s  \n", str4);


	char str5[] = { 'z', 'x', 'c', 'v', 'b', 'n', '\0' };//������Ԫ�ظ������ַ���
		//��ʼ�����ٸ��ַ������ж��ٸ�Ԫ�أ�������7��Ԫ�أ�ע�⣬һ��Ҫ�ֶ����\0
	puts(str5);//����ר���ַ����Ĵ�ӡ����


	"hello yy~ try again~";//���ǳ����ַ���
	printf("hello yy~ try again~" );//�����ַ����Դ�\0��hello yy~ try again~'\0' �����ַ�������
	printf("\n");  //printf�����ĵ�һ��������char*�� ��""����char*����
	//printf(2);//�����Ͳ��ܴ�ӡ����ʾ����const char *const ���롰int���ļ�Ӽ���ͬ

	char* p = "hello yy~ try again~"; //�����ַ�������������ɣ��ַ�+""
	//""�������ǰ��ַ������׵�ַ�����������൱��char*��""�����ַ���
	//p = 'w';//�����ַ����൱�ڳ�����������ַ��ǲ����޸ĵ�
	puts(p);

	p = "adadhfhjj";//ָ�����޸�ָ����ַ��������ַ����������޸�
	printf(p);

	system("pause");
	return 0;
}