#include <stdio.h>
#include <stdlib.h>

#include <float.h>              //ʹ�ú� FLT_MIN�����ͷ�ļ�

int main(void)
{
	
	printf("%e \n", FLT_MIN);   //FLT_MIN��ʾһ���꣬��˼��float��С�ģ�ѡ�����Ҽ�ת������
	                            //�����ҵ�float�����������͵���С��ֵ�����ֵ
	                     
	printf("%e \n", 0);       
	printf("%e \n", 0.0);    //�����������0ʱ������ʹ��0������ʹ��0.0

	system("pause");
	return 0;
}