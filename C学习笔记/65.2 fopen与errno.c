#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>


int main(void)
{

	FILE* pfile = NULL;
	errno_t a = fopen_s(&pfile, "65.2 ����.txt", "r");//���ǰ��ļ�ɾ����r�����·��صĴ�����
	//�ضϵ��ԣ��õ�a�ķ���ֵ��2������ͨ���Ϸ�������>�������>�����������ң��õ���ϵͳ�Ҳ���ָ�����ļ���
			//fopen_s�Ĺ��ܸ�fopen��һ����
	//����fopen��ͨ������ֵ�����ļ�ָ��
	//����fopen_s:ͨ������1�����ļ�ָ�룬���ķ���ֵ��Ϊ�����뷵��
	fclose(pfile);//�ǵùرձ����ļ���fclose�Ĺ����ǣ��رղ�����
	//close���ر�



	FILE* ffile = fopen("65.2 ����.txt", "r");//fopen��ͨ�����·�ʽ���ش�����
	if (ffile == NULL)				//����ɾ���ļ���r���Դ�����
	{
		printf("�ļ���ʧ�ܡ�");
	}
	int b = errno;		//���ԽضϿ�b��ֵ��Ȼ���ڹ��ߵĴ�����ҿ���Ӧ��ֵ����˼
	//�ⲻ�Ǳ���ʹ�ã���һ���Ҵ���ķ�ʽ���������ǲ��Ҵ���
	fclose(ffile);//�ǵùرձ����ļ���fclose�Ĺ����ǣ��رղ�����
	//close���ر�


	system("pause");
	return 0;
}