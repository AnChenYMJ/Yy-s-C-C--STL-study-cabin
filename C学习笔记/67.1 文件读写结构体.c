#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

struct YU  //�ṹ����ļ���дֻ��ͨ��fwrite��fread������
{
	char name[10];
	int num;
	short age;
	double hight;
	float weight;
};


int main(void)
{
	struct YU bu = { "��֪����", 112, 25, 165.2, 48.5 };
	struct YU nu;
	FILE* pfile = fopen("67.1 ����.txt", "w");

	//fwrite(&bu, sizeof(bu), 1, pfile);//����д��Ļ������ļ����д�txt�ļ����ᷢ���������
	//ԭ���Ǵ����ڴ���룬�ڴ����ɲο��ʼ�49.2����Ϊ�����Ч�ʣ������ֽ�ϣ����Ծ���cpu��һ��
	//���ܰ�һ�����Ͷ��������Ͱѷֶβ�����װ����һ���͵Ŀռ䲹�ϣ�����һ��������һ���ֶ���
	//�ֶδ�С�ǿ�cpuһ���Զ�ȡ���ֽ�����32λ�̶�4�ֽڣ�64λ�̶�8�ֽ�
	//�����Ļ�����txt���������ⲿ����������򿪿����Ķ������룬��Ϊ����֪���ڴ����
	//����������freadȥ��������ȷ�������ˣ����Բ��ù��ļ�����ʲô��fread����ȫ����fwriteд��
	//ʱ�ĸ�ʽȥ��������֪���ڴ���롣

	fread(&bu, sizeof(bu), 1, pfile);//�ضϵ��Ծ��ܿ���&bu�����������ȷ��

	//fwrite(&bu, sizeof(bu.age), 1, pfile);//��Ҫд��ʱ����
	//fwrite("\n", 1, 1, pfile);//�������ܻ�����
	//fwrite(&bu, sizeof(bu.hight), 1, pfile);//������Ա����д��

	printf("%d \n", sizeof(nu));//40
	//��Ϊ�ṹ���л��������������һ��Ϊ׼
	//�Խṹ��YUΪ������Ϊdouble��8�ֽڣ�
	//��һ������char����װ����
	//�ڶ�����ǰ4�ֽڣ�2�ֽ���char���飬����2�ֽڣ���4�ֽڣ�int numװ��
	//��������short��2�ֽڼ���2λ���룬��4λҲ����
	//���ĸ���double����װ��
	//�������float4�ֽڣ���4�ֽڲ���
	//��40�ֽڿռ��С���ɴ�ӡ������

	fclose(pfile);

	


	system("pause");
	return 0;
}