#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int a = 64;

	switch (a)
	{
	case 60:
	case 61:
	case 62:
	case 63:
	case 64:          //����������ƥ�䣬�ҵ�64������ִ��
	case 65:
	case 66:          //��Щ��û�п�ִ�еĴ��룬��������ִ��
	case 67:
	case 68:
	case 69:
		printf("����\n"); //�����￪ʼִ��
		break;            //�����ṹ��ʵ�ֱ�ʾ��Χ�������
	case 70:
		break;
	}



	system("pause");
	return 0;
}