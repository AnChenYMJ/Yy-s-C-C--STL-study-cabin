#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int order = -3;

	scanf_s("%d", &order);

	switch (order) //���н����ͱ��ʽ     //ע�������޷ֺţ�����ֵ���ﲻҪ���з�Χ�޶�������ֵ����0���٣���1���棩
	{                  //�����ֵ�������Ǹ����ͣ����������ͣ�if�ṹ�����Ǹ�����
	case 1:               //case ���ǩ1֮��Ҫ�пո��ұ�ǩ�������ð�ţ�
		printf("���һ��ѧ��\n");
		break;            //break�Ǳز����ٵģ����򽫻����ִ����һ������
	case 2:
		printf("ɾ��һ��ѧ��\n"); //����Ƕ����ѭ���У���breakֻ������ǰ�ṹ������switch�ṹ
		break;
	case 3:  //���нУ����ͳ������ʽ
	{   
		int a = 5;    //��case�ﶨ���������Ҫ�ӻ�����
		printf("�鿴һ��ѧ��\n");
	}
		break;
	case 4:
		printf("�˳�ϵͳ\n");
		break;
	default:                      //default��switch�ṹ�в��Ǳ�Ҫ�ģ�
		printf("ϵͳ�޸�ָ��\n");  //���һ�����break����д�ˣ���Ϊ������������ṹ��
	}
		
	if (2 < 3)   //if��else ��if��������������ͬ��
	{
		printf("66");  //����ִֻ��һ������Ϊelse if����У�ִ�е���һ���棬������Ͷ������ˣ������ṹ
	}
	else if (2 < 3)
	{
		printf("55");
	}	        

	system("pause");
	return 0;
}