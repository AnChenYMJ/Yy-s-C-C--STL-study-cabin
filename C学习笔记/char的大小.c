#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char c = 'H';
											  //char���ַ�����
	printf("%d, %u", sizeof(c), sizeof(char));//char���͵Ĵ�СΪ1�ֽ�

		//char���͵ķ�Χ��-128~127,(-2^7~-2^7-1),�޷��ŵķ�Χ��2^8-1(255)
		//��asc2����У���ЩԤ��������ʱ��û�и�����ĸ��ţ��������Ժ��������������
		//�����ַ�asc2���ʾ���꣬�����б�����


	system("pause");
	return 0;
}