#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>



int main(void)
{
	//char k;
	//scanf("%c", &k);    //'1'�Ǳ�ʾ�ַ������ı��Ϊ49����1�ͱ�ʾ1
	//printf("%d \n", k);
	//					//���ǶԱ������飬�����scanf��%c�ַ�����ȥ�ӿ���̨�����ֵ
	//char l;				//�������%d���Ƶ�ȥ�ӿ���̨�����ֵ����������1
	//scanf("%d", &l);	//�����ӡ�Ľ����49������һ���ӡ����1��
	//printf("%d \n", l); //����һ��浽scanf��ʱ������%c���ַ����ͣ�
						//����һ����%dȥ�Ӿ�ǿ������ת������������Ϊ1���Ϊ1

	char c = 0;
	while (1)
	{
		scanf("%c", &c); //һ��Ҫ�ǵ�ȡ��ַ��
		if (c >= 65 && c <= 90)
		{
			printf("%c ", c + 32);
		}
		else if (c >= 97 && c <= 122)
		{
			printf("%c ", c - 32);
		}
		else if(c == 10) //����س�ʱ����ѭ��
		{
			break;
		}
	}


	system("pause");
	return 0;
}