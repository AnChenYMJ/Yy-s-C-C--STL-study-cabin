#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int i = 0;

	for (i = 0; i <= 5; i++)
	{
		printf("%d  ", i);
		break;               //��ϵͳִ�е�breakʱͣס������ѭ����
	}


	printf("\n");  //����
	int k = 0;

	for (k = 0; k <= 5; k++)
	{
		if (k == 3)
		{
			break;     //brerk�������ifʹ�ã�������ѭ��������if����������ִ��if��ִ�����
		}
		printf("%d  ", k);
	}


	printf("\n");  //����
	int p ;
	int o ;

	for (p = 6; p >=1; --p)
	{
		printf("%d  ", p);
		for (o = 0; o <= 5; o++)
		{
			printf("%d  ", o);
			if (o == 2)
			{
				break;   //breakֻ��������ǰѭ����
			}
		}
		if (o == 2)    //Ҫ����������ѭ��ֻ����������ѭ������break
		{
			break;     //break��ü����������������������
		}
		printf("\n");
	}

	//break;             //breakֻ����ѭ����ʹ�ã�������ѭ����ʹ�ã�VS2019���ɻᱨ��

	system("pause");
	return 0;
}