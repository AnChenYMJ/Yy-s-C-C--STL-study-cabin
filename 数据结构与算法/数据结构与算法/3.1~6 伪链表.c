#include <stdio.h>
#include <stdlib.h>				//system ��ͷ�ļ�
#include <string.h>				//memset ��ͷ�ļ�

//���Ƿ�װ�����������ú������ܵ�һ���õ�ʱ���ٵ��ã���Ҫ��ѧϰ��ʱ��һ������ں��������⴦���ӡ����

//α������
void WLB()
{
	//α�����������ʽ��������֣�ʵ��Ӧ���в����ܻ��ã�����ѧϰ��Ϊ�˽�����ѧϰ�������̵�
	//�㷨��������һֱ�ڱ仯������Ҫ��������˼ά��
	
	//������ص㣺Ԫ�ؿռ��ַ������һ��������õĹ̶���С�ռ䣬������������ȷ����������ʱ������һЩ����ֹԽ�磨���¿ռ��˷ѣ�
	//�ռ䲻��ʱ���������������ռ䣬�Ҹ���ԭ���ݵ��¿ռ�
	//�������Ԫ�أ������ٶȺܿ죬�����ڵ�ַ�������ܽ����±����㣨������ַƫ�ƣ��׵�ַ���Ӽ���

	//����ڵ�ռ���Զ��������ӿռ������������ĸ��ƣ�ֱ����ӽڵ�ռ䣬�ʽڵ�ռ��ַ������

	//������η���Ԫ���أ�
	//��������Ŀռ��ڲ�ͬʱ������룬��ַ�������������޷������±�����������
	//���Ծ���Ҫÿ���ڵ��¼��һ�ڵ�ĵ�ַ�������������е�Ҳ��¼��һ�ڵ��ַ��˫������
	//������ڵ������Ҫ������Ա��һ����¼���ݣ�һ����¼��һ�ڵ�ĵ�ַ����������ڵ���һ���ṹ������.
	
}

//����Ĵ���
struct WeiLianBiao
{
	int iValue;					//������
	struct WeiLianBiao* pNext;	//����һ�ڵ�ĵ�ַ
};
//�������ṹ�壺�����г����õ�����ѧϰ����ʱ���ã���������һ����Ӱ��˼·
//typedef struct WeiLianBiao
//{
//	int iValue;					//������
//	struct WeiLianBiao* pNext;	//����һ�ڵ�ĵ�ַ
//}_WeiLianBiao;

//������ҷ��ص�ַ��װ����
void FindShow(struct WeiLianBiao* pJiLu);

//�飺1.��������
void BianLiShow(struct WeiLianBiao* pJiLu);	

//�飺2.1����ָ������������
struct WeiLianBiao* FindByData(struct WeiLianBiao* pJiLu, int ShuJu);

//�飺2.2����ָ���������±����(�ڼ��������±궼�У��±�Ļ����Ǹ���-1)
struct WeiLianBiao* FindByIndex(struct WeiLianBiao* pJiLu, int Index);

//�飺2.3.1����ָ�������ݸ�����ͳ���ظ����ֵ�������
int Count(struct WeiLianBiao* pJiLu, int ShuJu);		//count������

//�飺2.3.2����ָ�������ݸ�������¼���ݣ����Լ��ģ���2.3.1��ϣ�
int GetNode(struct WeiLianBiao* pJiLu, struct WeiLianBiao* arr[5], int Data);

//�ģ�3.1���������޸�		�޸�==���� + �ģ�����Ҳ��Ϊ���������޸ģ������±��޸�
void ChangeByData(struct WeiLianBiao* pJiLu, int iValue1, int iData);

//�ģ�3.2�����±꣨�ڼ������޸�	
void ChangeByIndex(struct WeiLianBiao* pJiLu, int iIndex, int iData);


int main()
{

//��������
	struct WeiLianBiao	a = {5, NULL},		//�趨�ڵ�
						b = {8, NULL},		
						c = {6, NULL}, 
						d = {5, NULL}, 
						e = {3, NULL};		//��pNext��ʼ����NULL���᷽��ܶ�������뿴����� ��ɾ��� ����

	a.pNext = &b;		//����һ�ڵ�ĵ�ַ�浽��ǰ�ڵ�ĳ�Ա��
	b.pNext = &c;		//������¼��һ�ڵ�ĵ�ַ
	c.pNext = &d;		//ÿ���ӽڵ㶼��ôд������鷳��������ѭ�������
	d.pNext = &e;		//���һ���ڵ���Ϊû������һ���ڵ��ַ���ǵ�����pNext����������pNext������NULL��ֱ����һ���ڵ�������

//�� ����
// 
	//1.��������
	{

	struct WeiLianBiao* pJiLu;				//��һ��ָ���¼����ͷ�ĵ�ַ���������
	pJiLu = &a;

	printf("����Ϊ��һ����д������\n");
	printf("%d  ", a.iValue);								//a	�������ó�Ա �� .   ָ����ַ���ó�Ա�� ->
	printf("%d  ", (&a)->pNext->iValue);					//b	(&a)�� a �� pJiLu ���Ǵ���һ����ַ
	printf("%d  ", pJiLu->pNext->pNext->iValue);			//c
	printf("%d  ", a.pNext->pNext->pNext->iValue);			//d
	printf("%d  ", a.pNext->pNext->pNext->pNext->iValue);	//e
	printf("\n\n");
	//�ᷢ�֣�����д�����ڵ�һ�࣬��Խ��Խ�鷳������Ҫ�ù�����д��ѭ��

	//�������£�
	printf("����Ϊ���ҹ��ɵļ�д������\n");
	printf("%d  ", pJiLu->iValue);		//a

	pJiLu = pJiLu->pNext;				//��һ���ڵ�ĵ�ַ���ǵ���ǰ��ָ��
	printf("%d  ", pJiLu->iValue);		//b

	pJiLu = pJiLu->pNext;				//����ÿ��pJiLu����һ�ڵ��ַ���Ǽ���ʵ�ֱ���
	printf("%d  ", pJiLu->iValue);		//c

	pJiLu = pJiLu->pNext;
	printf("%d  ", pJiLu->iValue);		//d

	pJiLu = pJiLu->pNext;
	printf("%d  ", pJiLu->iValue);		//e

	printf("\n\n");

	//ѭ������
	printf("����Ϊѭ��������\n");			//�ɹ���ӡ
	BianLiShow(&a);						//ѭ���ܼ�࣬ע��ĩ�˽ڵ��pNext��NULL����㲻���
	printf("\n\n");


	}

	//2.����ָ��
	{
		//����ָ���У�1.�������ݡ�2.�鿴�ڼ�����3.���ݸ���

		//1.��������
		{
			//1.1�������ݣ���������
			printf("����Ϊ����ָ�����ݣ�\n");
			FindByData(&a, 6);
			if (FindByData(&a, 6) == NULL)				//1.�����ݴ��������ַ�ʽ���������Ҫ�����ݽ��в�����������һ�㣬���ֻ���жϣ��ٶ������һЩ
			{											//��д����װ����
				printf("δ�鵽�����ݡ�\n");
			}
			else
			{
				printf("�鵽ָ�����ݣ�����Ϊ�� %d \n", FindByData(&a, 6)->iValue);
			}											//���ݴ�����һЩ��ԭ������if else���������κ���
			printf("\n");

			//1.2�������ݣ�����û�е�
			printf("����Ϊ����û�е����ݣ�\n");
			FindByData(&a, 11);
			struct WeiLianBiao* pHead = FindByData(&a, 11);//2.���ǵڶ��ַ�ʽ�������ݽ��в���������һЩ����Ҫ��������ָ�븳ֵ
			if(pHead != NULL)
				printf("�鵽ָ�����ݣ�����Ϊ�� %d \n", pHead->iValue);
			else											//if else����{}���Զ�ִ�п������������һ�����
				printf("δ�鵽�����ݡ�\n");						
			printf("\n");
		
		}
		
		//2.�鿴�ڼ���
		{
			//2.1 �鿴�ڼ������������е�
			printf("����Ϊ���Ҷ�Ӧ���������ݣ�\n");
			FindShow(FindByIndex(&a, 5));					//�˴��õ�����װ�ĺ�������д��FindShow������FindByIndex��������鿴��������
			printf("\n");

			//2.2�鿴�ڼ���������û�е�
			printf("����Ϊ���Ҷ�Ӧ����û�е����ݣ�\n");
			struct WeiLianBiao* pHead1 = FindByIndex(&a, 8);//������һ���ģ��������˸����裬�鷳�˵㣬��������
			FindShow(pHead1);
			printf("\n");
		}

		//3.���ݸ���
		{
			//3.1ͳ���ظ����ֵĴ���
			printf("�����ظ��Ĵ�����%d \n", Count(&a, 5));	
			printf("\n");

			printf("�����ظ��Ĵ�����%d \n", Count(&a, 23));
			printf("\n");

			//3.2��¼�ظ����ֵ�����
			struct WeiLianBiao* arr[5] = { NULL };			//�������ǲ�ȷ�������Ļ������԰��ն�̬�����˼ά����Ҫ���پ����䣬5����Ϊ������������ڵ����Ϊ5
			GetNode(&a, arr, 5);
			for (int i = 0; i < 5 && arr[i] != NULL; i++)	//������ʦ�и����飺i < 4�ŵ�ǰ�棬�ͱ�����arr[4]��Խ�磬��Ϊ���±������3
			{												//arr[i] != NULL�ŵ�ǰ���Խ��ȡ���ݱȽϣ��������ã�������ʱ��ע��
				printf("�ظ�������Ϊ��%d \n",arr[i]->iValue);
			}
			if(GetNode(&a, arr, 5) == 0)
				printf("û���ظ������ݡ�\n");
			else
				printf("���ֵĴ���Ϊ��%d\n", GetNode(&a, arr,5));//�ҰѺ����ķ���ֵ��Ϊ�ظ��Ĵ������Ͱ�3.1�Ľ����
			printf("\n");

			//����û�е�����
			memset(arr, NULL, 5);							//������arr��ʼ��,��Ϊ����Ĳ���������ֵ��
			GetNode(&a, arr, 11);
			for (int i = 0; i < 5 && arr[i] != NULL; i++)	//������ʦ�и����飺i < 4�ŵ�ǰ�棬�ͱ�����arr[4]��Խ�磬��Ϊ���±������3
			{												//arr[i] != NULL�ŵ�ǰ���Խ��ȡ���ݱȽϣ��������ã�������ʱ��ע��
				printf("�ظ�������Ϊ��%d \n", arr[i]->iValue);
			}
			if (GetNode(&a, arr, 11) == 0)
				printf("û���ظ������ݡ�\n");
			else
				printf("���ֵĴ���Ϊ��%d\n", GetNode(&a, arr, 11));//�ҰѺ����ķ���ֵ��Ϊ�ظ��Ĵ������Ͱ�3.1�Ľ����
			printf("\n");
		}
		
	}

//����ɾ
{
//�������						����һЩ����ĸ�������ܻ�ͼȥ����˼��������ܶ�
	//ͷ���						����һ���ڵ��¼ԭͷ�ڵ�ĵ�ַ���������ͷ�ڵ�
	struct WeiLianBiao	a1 = { 55, NULL };
	a1.pNext = &a;
	printf("����Ϊͷ��ӣ�\n");
	BianLiShow(&a1);
	printf("\n\n");

	//β���						����һ���ڵ㣬ԭβ�ڵ��¼����ڵ�ĵ�ַ���������β�ڵ㣨ע�⣬�κ�β�ڵ��pNext��������NULL�����鿴���Ƿ�װ�ĺ��������֪���ˣ�
	struct WeiLianBiao	f = { 26, NULL };
	e.pNext = &f;
	printf("����Ϊβ��ӣ�\n");
	BianLiShow(&a1);
	printf("\n\n");

	//�м����					����һ���ڵ㣬������a,c�м����b��˵��b��¼c�ĵ�ַ��a��¼�ĵ�ַ�޸�Ϊ��¼b����ʵ�����м���루��ͼ����⣩
	struct WeiLianBiao	c1 = { 48, NULL };
	c.pNext = &c1;
	c1.pNext = &d;
	printf("����Ϊ�м���ӣ�\n");
	BianLiShow(&a1);
	printf("\n\n");


//ɾ��ɾ��
	//ͷɾ��
	a1.pNext = NULL;			//������ͷ��¼�ĵ�ַ��ΪNULL��Ȼ�����ͷŵ�����ڵ�ռ伴��
	//free(&a1);				//������α������ʾ����������������û��malloc���������ͷţ����Ǿֲ�����
	printf("����Ϊͷɾ����\n");
	BianLiShow(&a);
	printf("\n\n");

	//βɾ��
	e.pNext = NULL;				//������2�Ľڵ��¼��ַ���ΪNULL��Ȼ�����ͷŵ�ԭβ�ڵ�ռ伴��
	//free(&f);					
	printf("����Ϊβɾ����\n");
	BianLiShow(&a);
	printf("\n\n");

	//�м�ɾ��
	c.pNext = &d;				//�� a->b->c ɾbΪ����a��Ϊ��¼c�ĵ�ַ��Ȼ�����ͷ�b�ڵ�ռ伴��
	//free(&c1);					
	printf("����Ϊ�м�ɾ����\n");
	BianLiShow(&a);
	printf("\n\n");
	
}

//�ģ��޸�	�� == ����+�޸�
{
	//ָ�������޸�
	printf("����Ϊָ�������޸ģ�\n");
	ChangeByData(&a, 5, 99);
	BianLiShow(&a);
	printf("\n\n");

	printf("����Ϊ�Ҳ���ָ�����ݣ�\n");
	ChangeByData(&a, 56, 99);

	//ָ���ڼ����޸�
	printf("����Ϊָ���ڼ����޸ģ�\n");
	ChangeByIndex(&a, 1, 88);
	BianLiShow(&a);
	printf("\n\n");

	printf("����Ϊ��������Ԫ�ظ�����\n");
	ChangeByIndex(&a, 18, 666);
}


	system ("pause>0");			//�����������̨����ʾ���밴����������������������ڼ���>0�󣬾Ͳ���ʾ��仰�������ǹ�Ч���ڣ������������
	return 0;
}



//������ҷ��ص�ַ��װ����
void FindShow(struct WeiLianBiao* pJiLu)
{
	if (pJiLu == NULL)
		printf("δ�鵽�����ݡ�\n");
	else
		printf("�鵽ָ�����ݣ�����Ϊ�� %d \n", pJiLu->iValue);
}

//�飺1.��������
void BianLiShow(struct WeiLianBiao* pJiLu)	//����Ϊǰ���ܽ�Ĺ����뾭�飬�ܼ�࣬ע��˼��
{											//ֻҪ��������ͷ��ַ����
	while (pJiLu != NULL)					//pJiLu == NULLʱ ������Ѿ����˽ڵ��ĩ��//���һ���ڵ��pNext��Ϊû�������ڵ��ַ���ǣ�����һֱ��NULL
	{
		printf("%d  ", pJiLu->iValue);		//�ӵ�һ����ʼ����
		pJiLu = pJiLu->pNext;
	}
}

//�飺2.1����ָ������������
struct WeiLianBiao* FindByData(struct WeiLianBiao* pJiLu, int ShuJu)		//�ҵ����ظýڵ��ַ��û�ҵ�����NULL
{																			//struct WeiLianBiao*Ϊ���صĵ�ַ�����ͣ����ṹ��ָ�����ͣ�
	while (pJiLu != NULL)
	{
		if (pJiLu->iValue == ShuJu)
		{
			return pJiLu;													//�ҵ������˵�ַ���˳�����
		}
		pJiLu = pJiLu->pNext;
	}
	return NULL;															//û�ҵ�����NULL
}

//�飺2.2����ָ���������±����(�ڼ��������±궼�У��±�Ļ����Ǹ���-1)
struct WeiLianBiao* FindByIndex(struct WeiLianBiao* pJiLu, int Index)
{
	int Num = 1;			//��һ��������¼�Աȣ�������±���ң���Num=0���ɣ��ڼ����Ļ�Num=1
	while (pJiLu != NULL)
	{
		if (Num == Index)	//��Num������Ҫ�ĸ������ʱ�����ص�ǰ�ĵ�ַ
			return pJiLu;
		Num++;
		pJiLu = pJiLu->pNext;
	}
	return NULL;
}

//�飺2.3.1����ָ�������ݸ�����ͳ���ظ����ֵ�������
int Count(struct WeiLianBiao* pJiLu, int ShuJu)		//count:����
{
	int Num = 0;
	while (pJiLu != NULL)
	{
		if (pJiLu->iValue == ShuJu)
			Num++;
		pJiLu = pJiLu->pNext;
	}
	return Num;
}

//�飺2.3.2����ָ�������ݸ�������¼���ݣ����Լ��ģ���2.3.1��ϣ�
int GetNode(struct WeiLianBiao* pJiLu, struct WeiLianBiao* arr[5], int Data)
{										//�����Ĳ������Ǿֲ������������Ĳ���ͬһ�������ֲ�ͬҲ��Ҫ���ģ����Ҫע��
	int i = 0;
	while (pJiLu != NULL)
	{
		if (pJiLu->iValue == Data)
		{
			arr[i++] = pJiLu;			//i++��ȡֵ��+1���ŵ������ʡ�˴���
		}
		pJiLu = pJiLu->pNext;
	}
	return i;							//�Ұ�����ͳ���ظ���������ˣ�����ֵ�����ظ��Ĵ���
}

//�ģ�3.1���������޸�		�޸�==���� + �ģ�����Ҳ��Ϊ���������޸ģ������±��޸�
void ChangeByData(struct WeiLianBiao* pJiLu, int iValue1, int iData)
{
	int count = 0;
	while (pJiLu != NULL)				//��д�汾�����޸��ظ�����,�����ӣ���һ��ʼ���˵��Ҳ���ʱ��ô����
	{
		if (pJiLu->iValue == iValue1)	//���������޸�
		{
			pJiLu->iValue = iData;		//����鵽ĳ�ڵ����������ҵ�ֵһ�����򽫸ýڵ��ΪiData
			count++;
		}
		pJiLu = pJiLu->pNext;
	}
	if (count == 0)
		printf("δ�ҵ������� \n\n");

	//struct WeiLianBiao* pTemp = FindByData(pJiLu, iValue1);
	//if (pTemp == NULL)					//��ʦ�İ汾���������������˴�ǰд�ĺ������Ҳ������ݷ���NULL
	//	printf("δ�ҵ������� \n\n");
	//if (pTemp != NULL)					//ע����if����while
	//	pTemp->iValue = iData;			//�޷��޸��ظ����ֵ����ݣ�ֻ���޸ģ���һ���鵽�����ݣ�����鿴FindByData�����������壩

}

//�ģ�3.2�����±꣨�ڼ������޸�	
void ChangeByIndex(struct WeiLianBiao* pJiLu, int iIndex, int iData)
{
	//int Num = 1;						//��д�汾��������
	//while (pJiLu != NULL)
	//{
	//	if (Num == iIndex)
	//		pJiLu->iValue = iData;
	//	Num++;
	//	pJiLu = pJiLu->pNext;
	//}
	//if (pJiLu == NULL)
	//	printf("��������Ԫ�ظ������� \n\n");


	struct WeiLianBiao* pTemp = FindByIndex(pJiLu, iIndex);
	if (pTemp != NULL)				//��ʦ�汾��������
		pTemp->iValue = iData;
	if (pTemp == NULL)
		printf("��������Ԫ�ظ������� \n\n");
}
