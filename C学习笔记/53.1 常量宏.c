#include <stdio.h>
#include <stdlib.h>

#define ONE 1  //ONE������������֣���д�淶��ȫ��д���ո�������滻������
#define ONE 3  //�����ǿ��Եģ��������λ���������Ч
#define ONE2 2
#define ONEONE ONE2 //���������е��񣬵���ͬ���������滻��ONEONE �滻��ONE2 ONE2���滻��1


#define ONE3 1+5*6-3


#define PRINTF printf("%d, %d, %d \n\n", ONE, ONEONE, ONE3);

#define PRINTF1 printf("%d, %d, %d \n\n", ONE, 



#define THREE  //�����ǿ��Եģ��൱�������˵�δ��ʼ��

#define ONE4 1+3
#define ONE5 (1+3)

int main(void)
{
	printf("%d, %d, %d\n", ONE, ONE2, ONEONE);//��ı������滻��ʹ��ONEʱ��ONE�滻��1
	printf("%d, %d, %d\n\n", 1, 2, 2);//����һ�д��룬��ʵ�����滻�������������ӡ


	printf("%d \n", ONE3);//��ONE3�滻��1+5*6-3���������ӡ���͸�����һ��һ��
	printf("%d \n\n", 1 + 5 * 6 - 3);//����Ǻ��滻�ı��ʣ���ONE3�����ݣ���ȫ�滻��������


	PRINTF  //ֱ��ʹ�ú������ԭ���ǣ�����������ȫ�滻������
	//���printf("%d, %d, %d \n\n", ONE, ONEONE, ONE3);������һ����������䣬����������

	PRINTF1 ONEONE, ONE3);//��������ֺ��滻�ı��ʣ���������ǰ�벿���滻�����λ�ã�������д��
	//��벿�����һ���������


	printf("%d \n\n", 2 * ONE4);//���Ϊ5��ONE4�滻��1+3������2*1+3==5
								//�����Ҫ����2����ONE4��ֵ�������ʱд��(1+3)�������滻�����������С����
	printf("%d \n\n", 2 * ONE5);//���Ϊ8��ʽ�ӳ���2*(1+3)


	system("pause");
	return 0;
}