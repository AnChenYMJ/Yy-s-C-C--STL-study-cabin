#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int i = 6;

	for (i = 6; i >= 1; i--)
	{
		printf("ǰ���  ");
		continue;               //continue:������ִ�е�������������ִ����һ��ѭ��
		printf("���� \n");    //ִ�е���һ��ѭ���ǵ�ǰ����ѭ������������ѭ��
	}


	int k = 20;  //Ŀ�꣺���Ŵ�ӡ20~1��������ż��

	for (k = 20; k >= 1; k--)
	{
		if (k % 2 == 0)     //ż����2ȡģ���ࣩΪ0����Ҫ��ӡż������������ k%2 != 0
		{			
			continue;       //����ż��������ӡִ����һ��ѭ��
		}					//continue��������ǰѭ������ֻ����ѭ����ʹ��
		printf("%d ", k);
	}

	system("pause");
	return 0;
}