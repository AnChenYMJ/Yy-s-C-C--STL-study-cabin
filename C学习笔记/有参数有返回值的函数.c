#include <stdio.h>
#include <stdlib.h>
 

		}
	}
	*p1 = MaxNum;//��������ⲿ����n��Ҳ��������ڲ�����MaxNum
	return MaxNum;
}

int main(void)
{
	int a[8] = { 8, 6, 87, 46, 21, 13, 595, 911 };
	int n = 0;  //ע�⣺�еı����������ʼ�������˺�������ᱨ��
	printf("%d %d\n", FindMaxNum(a, 8, &n), n);//n����д�������������������������������ʼ����ֵ
	printf("%d \n", n);						   //��Ϊ��û���뺯������ֵ�任�������

	system("pause");
	return 0;
}