#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int main(void)//fseek��ftell�Ǻ�ʵ�õĺ�����������ȥ�ð�
{
	FILE* pfile = fopen("67.4 ����.txt", "r"); //��ס�����Ļ���r����Ҫ��w������w���������.
	
	char i[30] = {0};
	fread(i, sizeof(char), 15, pfile);
	printf(i);
	printf("\n");


	char j[30] = { 0 };
	//fseek(pfile, 0L, SEEK_SET);//ָ��ָ���ļ���ͷ
	//fseek(pfile, 13L, SEEK_SET);//ָ��ָ���ļ���13���ֽ�
	//fseek(pfile, 2L, SEEK_CUR);//ָ��ӵ�ǰλ������->�ƶ�2�ֽ�
	//fseek(pfile, -5L, SEEK_CUR);//ָ��ӵ�ǰλ������<-�ƶ�2�ֽ�
	//fseek(pfile, -5L, SEEK_END); //��ĩβλ�������ƶ�5�ֽ�
	fseek(pfile, 0L, SEEK_END);//ָ��ָ���ļ�ĩβ
	//����1���������ļ��ռ��ַ������2������ָ���λ�ã�����3������ָ��ķ�ʽ
	//ע��������L����Ϊ������2��������long���ͣ�Ҫ��L�ĺ�׺

	fread(j, sizeof(char), 5, pfile);
	printf(j);
	printf("\n");

	int a;
	a = ftell(pfile);//ftell:����1���������ļ��ĵ�ַ
	printf("%d\n", a);//����ֵ�����ݵ�ǰ��λ���±꣬���(0L,SEEK_END)���ܷ����ļ����ݵ��ֽ���


	fclose(pfile);//fclose�����ã��ر��ļ����������ļ����ݣ��ͷŲ����ļ�ʱ���������ռ䡣


	system("pause");
	return 0;
}