#include <stdio.h>
#include <stdlib.h>

int main(void)//ԭ���ϣ�����C���Ը�������Ҫgoto���ṹ��C������continue��break 
			  //��goto��������ʽ�����仰˵��goto�Ĺ�����ȫ������break��continue���档
			  //������ʹ��goto��ʹ���ǵĳ���ṹ�ǳ��ң��Ѷ������Խ��鲻Ҫ���ã�
			  //�ܲ��þͲ��ã�������C�����У�����ʹ��goto����ǲ������ܵ�
{
	int i,
		j,
		k,
		a = 1;

step:       //����һ����ǩ
	a++;
	printf("goto \n");
	if (4 == a)
	{
		goto step1;              //��������goto��ת��step1
	}
	goto step;

step1:
	printf("����step1��\n");

/////////////////////////////////////
	for (i = 0; i < 2; i++)           //����goto����ѭ�������ǿ��ܱ��Ͽɵ�һ���÷�
	{
		for (j = 0; j < 2; j++)
		{
			for (k = 0; k < 2; k++)
			{
				printf("forѭ��\n");
				if (1 == k)
				{
					goto step2;
				}
			}
		}
	}

step2:
	printf("����ѭ����step2��\n");
	system("pause");
	return 0;
}