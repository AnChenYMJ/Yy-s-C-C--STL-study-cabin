#define _CRT_SECURE_NO_WARNINGS   //��Ϊscanf�����ԭ�򣬼�����������߰�scanf��Ϊscanf_s

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int score = -1;  //�ɼ�������score���÷֡�

	printf("¼��ɼ���");    //������ʾ
	scanf("%d", &score);    //����ɼ�

	if (score >= 60 && score <= 120 && score >=0)  //�����жϣ����120�֣����0�֣�60�ּ���
	{
		printf("������%d���ɼ����� \n", score);
	}
	//�������������


	system("pause");
	return 0;
}