#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char ar[6] = { 'f', 'g', 'h', 'j' };
	int o = 0;

	ar[2] = 'y';//������±�����

	for (o = 0; o < 6; o++)
	{
		printf("%c  ", ar[o]);//���ַ�������һЩ����û�и���ʼֵʱ��ϵͳĬ��Ϊ0
		printf("%d  \n", ar[o]);//��zaiacs2���У�0��Ӧ����NULL��ʲôҲû�У�����������ַ�ʱ������ӡNULL
	}

	int t;
	sizeof(ar);
	t = sizeof(char[6]);
	printf("%d  %d \n", sizeof(ar), t); //����������6��˵���ַ������С����Ԫ�ش�С���


	char arr[5] = { 'q', 'w', 'e', 'r', 49 };//49���ַ���1���ı��
	int i;
	char* ptr = arr;
	for (i = 0; i < 5; i++)
	{							//����д��*ptr + i, *�����ȼ���+�ߣ��������һ����˼
		printf("%c  ", *ptr++); //*(ptr + i)  ptr[i]  arr[i]
		//* �� ++ �����ȼ���һ���������ȼ���һ��ʱ������ԣ���*��++��Ӧ�Ľ���Դ�������ִ��
	}

	system("pause");
	return 0;
}