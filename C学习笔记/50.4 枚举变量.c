#include <stdio.h>
#include <stdlib.h>

enum color{ enum_blue = 56, enum_white, enum_black, enum_green, enum_yellow, enum_red};


int main(void)
{
	enum color oc = enum_blue;//�����������һ��ö�ٱ�����ʵ�ʾ���һ�����ͱ���
	printf("%d \n\n", oc);

	oc = 89;  //��ȫ���Ե���int���͵ı���ʹ��
	printf("%d \n\n", oc);//������Ӧ��ֵö�����������ֵ����֣���ʵ���ϸ�ֵ�����Ҳû����

	int a = enum_white;//ͬ�ϣ���ͨ����Ҳ�ܱ���ֵö������������ֵ���
	printf("%d \n\n", a);


	printf("a = %d\nenum_blue = %d\nenum color = %d\n\n", sizeof(a), sizeof(enum_blue), sizeof(enum color));
	//�ᷢ�ֶ���4�ֽڴ�С��enum color���Կ�������intһ�������ͣ�int���ʹ�СΪ4�ֽ�
	//��ö�ٱ��ʾ���int����ö�ٵ�����Ҳ��4�ֽڣ�ֻ��ö�����ͱ�����ʽ�ǣ�enum color
	system("pause");
	return 0;
}