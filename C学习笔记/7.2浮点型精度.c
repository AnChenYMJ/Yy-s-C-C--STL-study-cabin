#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	float f = 55.45871111;  //ANSI C�涨float��Сֵ6λ����������ʼ�㣩��ʵ�⾫��7λ
	double d = 55.123456789123456789;//ANSI C�涨��Сֵ10λ��ʵ��16λ����
	                                 //long double�涨λ����double��ͬ����windows��18λ����
	                                 

	printf("%f \n %.20lf \n", f, d);   //%.20lf  ��˼�Ǵ�ӡ20λ��%lf���λ


	system("pause");
	return 0;
}