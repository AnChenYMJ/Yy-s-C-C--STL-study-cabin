#define _CRT_SECURE_NO_WARNINGS//strcpy����ȫ��ʾҪ������꣬
//strcpy��Ѷ������ַ�����ֵ���ռ�С���ַ����飬����ڴ�Խ�磬��������Ҫ�ֶ�ȷ���ַ�����Ĵ�С
#include <stdio.h>
#include <stdlib.h>
#include <string.h>  //strcpy��ͷ�ļ�


int main(void)
{
	char str1[7] = "hello~";

	char str2[5] = "worl";
	char* p = str2;

	printf("%s  \n", str1);

	int i = 0;
	for (; *p != '\0'; p++)  //��Ϊ�����ڳ�ʼ��֮��ֱ�Ӹ�ֵ������Ҫһ�����ĸ�ֵ����������ѭ��
	{
		str1[i] = *p;   //ע�����ǲ�������ջ���Ŀռ䣬�����ַ����飬���ǳ����ַ���
		i++;
	}
	str1[i] = '\0';//��ѭ����û�а�����\0Ҳ��ֵ��ȥ������Ҫ��ѭ�����ֶ����

	printf("%s  \n", str1);


	char str3[30] = "hello~ yy";
	char str4[] = "world~ its beautiful!";

	strcpy(str3, str4);//��������ǽ��ڶ����������ַ�����ֵ����һ������
	//���Ե�һ�������������ַ����飬�ڶ������������ǳ����ַ���
	//��Ϊ���ܽ��ֽ�������ַ�����ֵ���ռ�С���ַ����飬����Խ�磬ͷ�ļ���string.h
	//���Ե�һ�������ռ�Ҫ >= �ڶ��������ֽڴ�С
	printf("%s  \n", str3);

	strcpy(str3, "world~ its beautiful!����");//��һ�������������ַ����飬�ڶ������������ǳ����ַ���
	printf("%s  \n", str3);


	char str5[10] = "hello~ yy";
	char str6[30] = "world~ its beautiful!";

	strcpy(str5, str6);//��֪����Ϊʲô����û�б������ֽڸ�ֵ��С�ռ��������ִ�н���ʱ����
	printf("%s  \n", str5);//�����Ĵ���Ҫ���кܶ��д���ʱ�������Ҵ���������


	char str7[10] = "hello~ yy";
	char str8[30] = "world~ its beautiful!!";

	strcpy_s(str7, 30, str8);//strcpy_s���strcpy����һ�����������Ǳ�����һ���������ֽڴ�С
	printf("%s  \n", str7);//�����Ǹ�ֵʱ���װ���Ǹ��ֽھͽ����ˣ�Ŀ���Ƿ�ֹԽ��
							//��������г�������������һ�г���


	char str9[10] = "hello~ yy";
	char str10[30] = "world~ its beautiful!!";

	strncpy(str9, str10, 5);//��������ʾ��ָ����ֵ���ٸ��ַ������滻��׼ȷ�������滻���ٸ��ַ�
	printf("%s  \n", str9);


	char str11[10] = "hello~ yy";
	char str12[30] = "world~ its beautiful!!";

	strncpy(str11,30, str12, 5);//��������ʾָ����һ���������ַ�������ֽڴ�С
	printf("%s  \n", str11);//��������ʾ��ָ����ֵ���ٸ��ַ������滻��׼ȷ�������滻���ٸ��ַ�
				//�����м�_s�ĺ�������΢���ĸ���ȫ�ĺ���������c���Ա�׼��
		        //��������г�������������һ�г���

	system("pause");
	return 0;
}