#define _CRT_SECURE_NO_WARNINGS//�°�VS��������ʹ��fopen_s

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//ע�⣺��д�ĸ�ʽһ����˵Ҫ��Ӧ�ϣ�����fwriteд�룬����fread����
//��Ϊ���ǰ��ֽ�������д�ģ�������ң�����һ���淶
//���ֽ���д�룬�ܰ�����������������Ū������һ����ôд�ľ���ô��
int main(void)
{
	FILE* pfile = fopen("66.2 ����.txt", "r");//���Ļ���Ҫ��w����Ϊw�����������
	
	char YU[30] = {0};
			//fread�ķ���ֵ�Ƕ�ȡ���ֽ����������û���ֽڿɶ��ˣ��ͷ���0
	//int a = fread(YU, sizeof(char), 2, pfile);//һ�������ַ��պ����ֽ�
			//���ǿ��԰�fread�ŵ�ѭ����ȥ��
	int a;	//fread������ʽ��fwileһ����
	//c3��������ʦ�Ŀγ��fread�ķ���ֵ��size_t���͵ģ�������int��֪��Ϊʲôû��ʾ
	//size_t��64λ��������unsigened int����
	while ( a = fread(YU, sizeof(char), 2, pfile))
	{
		printf("%s", YU);//����һǻ��ͳ� yuana//�ᷢ�ֶ��ӡ��һ�����ʣ�ԭ���Ƕ����1λʱ
		//����2���ˣ�Ȼ��͸��ǵ�������3����ǿ�ж��������������ǿ��������·�������
		YU[0] = 0;//����ÿ�ζ���2�ֽڣ��Ͱ���2�ֽ����
		YU[1] = 0;//ԭ���Ƕ����ָ�������ƶ�2�ֽڣ�ָ����ָ��λ�þ����µ�YU[0]
	}
 
	fclose(pfile);//�ǵñ���ر�


	system("pause");
	return 0;
}