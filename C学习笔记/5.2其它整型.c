#include <stdio.h>
#include <stdlib.h>


int main(void)
{
	short s = 123;    //short int ����������д�������������붨������ķ�ʽ������ͬ�ġ�
	                  //short ���ڴ��ֽ�Ϊ2�ֽڣ��з��ŵķ�Χ�ǣ�-32768~32767
	                  //�޷��ŵķ�Χ�ǣ�0~65535

	printf("short : %hd \n", s);           //�����ʽ��Ϊ��%hd  ������%d Ҳ���ԣ�ǰһ�ָ�׼ȷ
	printf("short : %d \n", sizeof(s));    //�����ռ�ֽ�


	long l = 223;     //�����ͣ�long int ����������д����long ���ڴ��ֽڣ���Χ��С����int����һ����
	                  //4�ֽڣ��з���:-2^31~2^31-1 , �޷��ţ�0~2^32-1
	                  //��C��ָ�롷��׼ֻ�涨int��С��short�ĳ���

	printf("long : %ld \n", l);          //�����ʽ��Ϊ��%ld  ��%dҲ����
	printf("long : %d \n", sizeof(l));   

	long long ll = 333;     //c99��׼��չ�������ͣ�VC++6.0��֧�֣�����д����long long int
	                        //�ڴ�ռ8�ֽڣ��з��ţ�-2^63~2^63-1,�޷��ţ�0~VC++6.0~2^64-1
	                        //�Ƚϲ����ã����Ǿ������ĸ�������ȡ��������������ݵĴ�С

	printf("long long : %lld \n", ll);          //�����ʽ��Ϊ��%lld  ��%dҲ����
	printf("long long : %d \n", sizeof(ll));


	system("pause");  // getchar() , while(1) �����ֶ����Կ�ס�Ա�۲졣
	return 0;
}