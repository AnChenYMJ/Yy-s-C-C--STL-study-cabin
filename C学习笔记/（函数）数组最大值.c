#include <stdio.h>
#include <stdlib.h>

int main(void)   //���Ҫѡ�ܶ������зֱ�����ֵ����Сֵ����Ҫ����ճ�������޸�
{				 //�ͻ���鷳����һ���оͻ���ܺ���������������
	int a[8] = { 56, 78, 12, 3, 45, 94, 656, 89 };
	
	int MaxNum = a[0];
	int MixNum = a[0];
	int i;

	for (i = 0; i < 8; i++)  //����ѭ��ѡ������������ֵ����Сֵ
	{						 //�Ƚ�һ��ʼִ��������Ƚϣ���һ����ʵ����ʡ�Ե�
		if (MaxNum < a[i])
		{
			MaxNum = a[i];
		}
		if (MixNum > a[i])
		{
			MixNum = a[i];
		}
	}

	printf("a�������ֵ��%d \n", MaxNum);
	printf("a������Сֵ��%d \n", MixNum);


	int b[7] = { 1, 56, 98, 78, 60, 54, 23 };

	int MaxNumb = b[0];
	int MixNumb = b[0];

	for (i = 1; i < 7; i++)
	{
		if (MaxNumb < b[i])
		{
			MaxNumb = b[i];
		}
		if (MixNumb > b[i])
		{
			MixNumb = b[i];
		}
	}

	printf("b�������ֵ��%d \n", MaxNumb);
	printf("b������Сֵ��%d \n", MixNumb);


	system("pause");
	return 0;
}