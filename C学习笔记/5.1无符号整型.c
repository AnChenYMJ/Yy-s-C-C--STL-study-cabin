#include <stdio.h>
#include <stdlib.h>

int main(void)
{

	unsigned int a = 3147483648;   //unsigned int ���޷������͵���������Χ��0-4294967295,��ռ�ڴ�Ϊ4�ֽ�

	printf("%u \n", a);             //%u:��ʾ10�����޷������͵������
	                                //%d��û������Χʱ��%u���һ����������Χ�����Ͳ�ͬ�ˣ��ö�Ӧ�Ĳ�Ҫ����
	printf("%u \n", sizeof(unsigned int));   //sizeof()  ������Ĳ���ʡ�ԣ�

	system("pause");
	return 0;
}