#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	FILE* pfile = fopen("66.1 ����.txt", "wb"); //���л�r��r + ��w��a�����²�ͬ��Ч��

	char* YU1 = "Keep going!";//��������ʵ�ֶ��д���ļ�
	//�ı�ģʽ���������ַ�ʽ����һ��
	char HH = '\n';
		//�ı�ģʽ���з�ʽ�������
	char* YU2 = "don't hesitate~\n";//���ֿ��ܿ����е㲻������ʵ����ȫû�����
		//�����ƻ��з�ʽ��\r\n
	char* YU3 = "please!";
	char *HH1 = "\r\n";//�����ַ����ַ���
	char* YU4 = "ʫ�Ƴ��껪";

	fwrite(YU1, sizeof(char), strlen(YU1) + 1, pfile);
	fwrite(&HH, sizeof(char), 1, pfile);//��Ϊ���ǳ����ַ����ˣ�����Ҫ�ֶ���ȡ��ַ��&
	//strlen�Ǽ����ַ������ȵģ������ǵ����ַ����ò��ˣ��ֶ�д1.//��û�пո��ˣ��Ͳ��ü�1
	fwrite(YU2, sizeof(char), strlen(YU2), pfile);//��Ϊ�����ˣ�����Ҫ�ո����Բ���+1
	fwrite(YU3, sizeof(char), strlen(YU3) + 1, pfile);
	fwrite(HH1, sizeof(char), strlen(HH1), pfile);//��Ϊ�����ˣ�����Ҫ�ո����Բ���+1
	fwrite(YU4, sizeof(char), strlen(YU4) + 1, pfile);

	fclose(pfile);//ע��Ҫ����ر�
	//����д��������ݵ�ԭ���ǣ��ļ�ָ����ƶ�


	system("pause");
	return 0;
}