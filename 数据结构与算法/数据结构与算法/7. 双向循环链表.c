#include <stdio.h>
#include <stdlib.h>

//˫��ѭ�������顢�ܽ�
void AAA()
{
	if (1)
	{
	//����ʱ˫��ѭ���������п�ͷ����
	//˫��ѭ����������ͷ�ڵ��ǰһλ���������β�ڵ㣬��β�ڵ���ͷ�ڵ��������γɻ�״
	//˫��ѭ�����������л�����������۷壬��������õĽṹ
	//��������Ҳ���޸ĳ�ѭ������
	//��ǰѧ������ṹ���ᷢ��Խ��Խ���ã�ҲԽ��Խ�򵥡�
	//˫��ѭ������ʹֻ��һ���ڵ㣬��Ȼ�ʻ�״��Ҳ����˵��ͷ��������ַ��Ա��¼�Լ��ĵ�ַ

	//�����⣺�����ж��������Ƿ��л�������ָ��
	//�����⣺���������Ŀռ����������������������������ڵ�ֻ��������Ա��һ������λint���͡�һ����ַλ����������ֻ��50%���������飬�����������λ���࣬�����ʾ͸�һЩ
		//����Ŀռ���һ������õģ����ûװ�����������ʾͲ���100%��������9��int���Ϳռ䣬ֻװ��6�����������ʾ���2/3.

	//pEnd��Ϊ��ʹ��������ࡢЧ�ʸ��ߣ�β�ڵ�ĸ��涼Ҫ�л�pEndָ��
	//��ͷ��Ϊ��ʹ��д�����߼�����࣬��Ӱ��Ч��
	}
}

struct Node
{
	int iData;
	struct Node* pNext;
	struct Node* pPre;
};

//����β���
void AddToEnd(struct Node* STHead, int* ICount, int IData);
//����ͷ���
void AddToHead(struct Node* STHead, int* ICount, int IData);
//����ָ���±�λ����ӽڵ�
void InsertByIndex(struct Node* STHead, int* ICount, int IIndex, int IData);
//����ָ���±�λ����ӽڵ�(N��)
void InsertSomeByIndex(struct Node* STHead, int* ICount, int IIndex, int iNodeCount, int IData);
//����ָ������λ����ӽڵ�
void InsertByData(struct Node* STHead, int* ICount, int IValue, int IData);
//ɾ��ɾ��ָ���±�ڵ�
void DeleteByIndex(struct Node* STHead, int* ICount, int IIndex);
//ɾ��ɾ��һ�νڵ㣨�±�ָ����
void DeleteSomeByIndex(struct Node* STHead, int* ICount, int IIndex1, int IIndex2);
//ɾ��ɾ��ָ�����ݣ�N����
void DeleteAllByData(struct Node* STHead, int* ICount, int IValue);
//�飺����ָ���ڵ㣨�����±꣩
struct Node* GetNodeByIndex(struct Node* STHead, int ICount, int iIndex);
//�飺����ָ���ڵ㣨�������ݣ�
struct Node* GetNodeByData(struct Node* STHead, int iValue);
//ѭ������
void AllShow(struct Node* STHead, int ICount);
//�ͷ�
void FreeList(struct Node* STHead, int* ICount);

int main(void)
{
	//������ͷ����ʼ��
	struct Node stHead;
	stHead.iData = 0;
	//˫��ѭ������ʹֻ��һ���ڵ㣬��Ȼ�ʻ�״��Ҳ����˵��ͷ��������ַ��ԱҪ��¼�Լ��ĵ�ַ
	stHead.pNext = &stHead;
	stHead.pPre  = &stHead;
	//������ʼ��
	int iCount = 0;

//β��ӡ�ͷ��ӡ�ѭ������
{
	AddToEnd(&stHead, &iCount, 0);
	AddToEnd(&stHead, &iCount, 1);
	AddToEnd(&stHead, &iCount, 2);
	AddToEnd(&stHead, &iCount, 3);
	AddToEnd(&stHead, &iCount, 4);

	AllShow(&stHead, iCount);

	AddToHead(&stHead, &iCount, -1);
	AddToHead(&stHead, &iCount, -2);
	AllShow(&stHead, iCount);

	AddToEnd(&stHead, &iCount, 5);
	AddToEnd(&stHead, &iCount, 6);
	AllShow(&stHead, iCount);

	FreeList(&stHead, &iCount);
	AllShow(&stHead, iCount);
}
//����ָ���ڵ�:�����±ꡢ���ݡ��޸Ľڵ�
{

	AddToEnd(&stHead, &iCount, 2);
	AddToEnd(&stHead, &iCount, 3);
	AddToEnd(&stHead, &iCount, 4);	
	AddToHead(&stHead, &iCount, 1);

	AllShow(&stHead, iCount);
	//�±����
	struct Node* p = GetNodeByIndex(&stHead, iCount, 3);
	if (p == NULL)
		printf("\n�±겻����/����ΪNULL\n");
	else
		printf("\n�鵽�±�����: %3d\n", p->iData);
	//���ݲ���
	p = GetNodeByData(&stHead, 2);
	if (p == NULL)
		printf("\n���ݲ�����/����ΪNULL\n");
	else
		printf("\n�鵽��Ӧ����: %3d\n", p->iData);
	//�޸�����:ֱ���÷���ֵ�޸�	���ĳ�C++����ò����ˣ���Ϊ��Ա���˽�е���
	if (p == NULL)
		printf("\n���ݲ�����/����ΪNULL\n");
	else
		p->iData = 23;
	AllShow(&stHead, iCount);

	AddToHead(&stHead, &iCount, 0);
	AddToEnd(&stHead, &iCount, 5);
	AllShow(&stHead, iCount);


	FreeList(&stHead, &iCount);
	AllShow(&stHead, iCount);
}
//ָ���±�λ����ӽڵ�
{
	AddToEnd(&stHead, &iCount, 2);
	AddToEnd(&stHead, &iCount, 3);
	AddToEnd(&stHead, &iCount, 4);
	AddToHead(&stHead, &iCount, 1);

	AllShow(&stHead, iCount);

	InsertByIndex(&stHead, &iCount, 0, 26);
	AllShow(&stHead, iCount);

	AddToEnd(&stHead, &iCount, 5);
	AddToHead(&stHead, &iCount, -1);
	AllShow(&stHead, iCount);

	FreeList(&stHead, &iCount);
	AllShow(&stHead, iCount);
}
//ָ���±�λ����ӽڵ�(N��)
{
	AddToEnd(&stHead, &iCount, 4);
	AddToHead(&stHead, &iCount, 1);
	AllShow(&stHead, iCount);

	InsertSomeByIndex(&stHead, &iCount, 1, 3, 28);
	AllShow(&stHead, iCount);

	AddToEnd(&stHead, &iCount, 00);
	AddToHead(&stHead, &iCount, 00);
	AllShow(&stHead, iCount);

	FreeList(&stHead, &iCount);
	AllShow(&stHead, iCount);
}
//ָ������λ����ӽڵ�
{
	AddToEnd(&stHead, &iCount, 4);
	AddToHead(&stHead, &iCount, 1);
	AllShow(&stHead, iCount);

	InsertByData(&stHead, &iCount, 1, 13);
	AllShow(&stHead, iCount);

	AddToEnd(&stHead, &iCount,0);
	AddToHead(&stHead, &iCount, 0);
	InsertByData(&stHead, &iCount, 4, 27);
	AllShow(&stHead, iCount);

	FreeList(&stHead, &iCount);
	AllShow(&stHead, iCount);
}
//ɾ��ָ���±�ڵ�(һ����һ��)
{
	AddToEnd(&stHead, &iCount, 2);
	AddToEnd(&stHead, &iCount, 3);
	AddToEnd(&stHead, &iCount, 4);
	AddToHead(&stHead, &iCount, 1);
	AddToEnd(&stHead, &iCount, 5);
	AddToEnd(&stHead, &iCount, 6);
	AddToEnd(&stHead, &iCount, 7);
	AddToEnd(&stHead, &iCount, 8);

	AllShow(&stHead, iCount);
	//ɾ��1��
	DeleteByIndex(&stHead, &iCount, 7);
	AllShow(&stHead, iCount);
	AddToEnd(&stHead, &iCount, 8);
	AllShow(&stHead, iCount);
	//ɾ��һ��
	DeleteSomeByIndex(&stHead, &iCount, 2, 6);
	AllShow(&stHead, iCount);
	AddToEnd(&stHead, &iCount, 9);
	AllShow(&stHead, iCount);

	FreeList(&stHead, &iCount);
	AllShow(&stHead, iCount);
}
//ɾ��ָ�����ݣ�N����
{
	AddToEnd(&stHead, &iCount, 2);
	AddToEnd(&stHead, &iCount, 2);
	AddToEnd(&stHead, &iCount, 4);
	AddToHead(&stHead, &iCount, 1);
	AddToEnd(&stHead, &iCount, 8);
	AddToEnd(&stHead, &iCount, 4);
	AddToEnd(&stHead, &iCount, 7);
	AddToEnd(&stHead, &iCount, 8);

	AllShow(&stHead, iCount);

	DeleteAllByData(&stHead, &iCount, 8);
	AllShow(&stHead, iCount);

	AddToHead(&stHead, &iCount, 1);
	AddToEnd(&stHead, &iCount, 7);
	AllShow(&stHead, iCount);

	DeleteAllByData(&stHead, &iCount, 4);
	DeleteAllByData(&stHead, &iCount, 2);
	DeleteAllByData(&stHead, &iCount, 1);
	AllShow(&stHead, iCount);

	FreeList(&stHead, &iCount);
	AllShow(&stHead, iCount);
}

	system("pause>0");
	return 0;
}


//����β���
void AddToEnd(struct Node* STHead, int* ICount, int IData)
{
	//�����Ϸ��Լ��
	if (&STHead == NULL || STHead == NULL || (*ICount) < 0)
		return;
	//�����½ڵ�
	struct Node* pTemp = (struct Node*)malloc(sizeof(struct Node));
	if (pTemp == NULL)
		return;
	//�ڵ㸳ֵ
	pTemp->pNext = NULL;
	pTemp->pPre = NULL;
	pTemp->iData = IData;
	//�½ڵ���β�ڵ����ӣ�����ͷ��ǰһλ��
	pTemp->pPre = STHead->pPre;
	STHead->pPre->pNext = pTemp;
	//�½ڵ����ͷ����	//ע��˳��Ҫ����β�ڵ����ӣ�Ϊ�˱���ָ�붪ʧ�����ɻ�ͼ�������
	pTemp->pNext = STHead;
	STHead->pPre = pTemp;
	//����+1
	(*ICount)++;
}
//����ͷ���
void AddToHead(struct Node* STHead, int* ICount, int IData)
{
	//�����Ϸ��Լ��
	if (&STHead == NULL || STHead == NULL || *ICount < 0)
		return;
	//�����½ڵ�
	struct Node* pTemp = (struct Node*)malloc(sizeof(struct Node));
	if (pTemp == NULL)
		return;
	//�ڵ㸳ֵ
	pTemp->pNext = NULL;
	pTemp->pPre = NULL;
	pTemp->iData = IData;
	//�½ڵ������ͷ����2�ڵ�����(��ʦ��˼·��Ҳ������)
	pTemp->pNext = STHead->pNext;
	pTemp->pPre = STHead;
	//�Ͽ���ͷ���2�ڵ�֮�����ϵ
	STHead->pNext->pPre = pTemp;
	STHead->pNext = pTemp;
	//����+1
	*ICount += 1;
}
//����ָ���±�λ����ӽڵ�
void InsertByIndex(struct Node* STHead, int* ICount, int IIndex, int IData)
{
	//�����Ϸ��Լ��
	if (&STHead == NULL || STHead == NULL || *ICount < 0 || IIndex < 0 || IIndex > *ICount)
		return;//IIndex < *ICount�����±��ܴﵽβ�ڵ���һλ���������ܽ���β���
	//����±���β�ڵ���һλ
	if(IIndex == (*ICount))
		AddToEnd(STHead, ICount, IData);
	else
	{
		//����λ��
		struct Node* pTemp = GetNodeByIndex(STHead, *ICount, IIndex);
		//�����ڵ�
		struct Node* pT = (struct Node*)malloc(sizeof(struct Node));
		if (pT == NULL)
			return;
		//�ڵ㸳ֵ
		pT->pNext = NULL;
		pT->pPre  = NULL;
		pT->iData = IData;
		//�½ڵ����λ�õ�ǰһλ�ڵ㡢�ýڵ�����
		pT->pNext = pTemp;
		pT->pPre = pTemp->pPre;
		//��λ�õ�ǰһλ�ڵ���ýڵ�Ͽ�
		if (pT->pPre == NULL)
			return;
		pTemp->pPre->pNext = pT;
		pTemp->pPre = pTemp;
		//����+1
		*ICount += 1;
	}
}
//����ָ���±�λ����ӽڵ�(N��)
void InsertSomeByIndex(struct Node* STHead, int* ICount, int IIndex, int iNodeCount, int IData)
{
	//�����Ϸ��Լ��
	if (&STHead == NULL || STHead == NULL || *ICount < 0 || IIndex < 0 || IIndex > *ICount || iNodeCount < 0)
		return;
	//ѭ�����
	for (int i = 0; i < iNodeCount; i++)
		InsertByIndex(STHead, ICount, IIndex, IData);	
}
//����ָ������λ����ӽڵ�
void InsertByData(struct Node* STHead, int* ICount, int IValue, int IData)
{
	//�����Ϸ��Լ��
	if (&STHead == NULL || STHead == NULL || *ICount <= 0)
		return;
	//���Ҷ�Ӧλ��
	struct Node* pTemp = GetNodeByData(STHead, IValue);
	//�����½ڵ�
	struct Node* pT = (struct Node*)malloc(sizeof(struct Node));
	if (pT == NULL)
		return;
	//�ڵ㸳ֵ
	pT->pNext = NULL;
	pT->pPre  = NULL;
	pT->iData = IData;
	//�½ڵ���뵽��λ��ǰ
	//��λ�ýڵ㡢ǰһ���ڵ����½ڵ�����
	pT->pNext = pTemp;
	pT->pPre = pTemp->pPre;
	//��λ�ýڵ㡢ǰһ���ڵ�֮��Ͽ�
	pTemp->pPre->pNext = pT;
	pTemp->pPre = pT;
	//����-1
	(*ICount)++;
}
//ɾ��ɾ��ָ���±�ڵ�
void DeleteByIndex(struct Node* STHead, int* ICount, int IIndex)
{
	//�����Ϸ��Լ��
	if (&STHead == NULL || STHead == NULL || *ICount <= 0 || IIndex < 0 || IIndex >= *ICount)
		return;
	//���Ҹýڵ�
	struct Node* pTemp = GetNodeByIndex(STHead, *ICount, IIndex);
	//���ýڵ��ǰ���������ڵ�����
	pTemp->pPre->pNext = pTemp->pNext;
	pTemp->pNext->pPre = pTemp->pPre;
	//�ͷŸýڵ�
	free(pTemp);
	//����-1
	(*ICount)--;
}
//ɾ��ɾ��һ�νڵ㣨�±�ָ����
void DeleteSomeByIndex(struct Node* STHead, int* ICount, int IIndex1, int IIndex2)
{
	//�����Ϸ��Լ��
	if (IIndex1 > IIndex2 || IIndex1 < 0 || IIndex2 < 0)
		return;//�˴�Ҫ����DeleteByIndex����������������Ѿ�����һЩ��������ˣ��ʲ������ֻдû��⵽��
	//ѭ��ɾ��
	for (int i = IIndex1; i <= IIndex2; i++)
		DeleteByIndex(STHead, ICount, IIndex1);
	//ע������˴�����ɾ�����������ܴ�����i����Ϊi�����ӣ�
	//�����Ӧλ���Ѿ���ɾ��������Ľڵ�������ǰ�ƶ�����i�Ļ��͵�������ɾ������©��һЩ�ڵ�
	//�˴�ֱ�Ӵ�IIndex1���ɣ���Ϊɾ������һ���ڵ���滻����±�λ�ã���������ɾ������
}
//ɾ��ɾ��ָ�����ݣ�N����
void DeleteAllByData(struct Node* STHead, int* ICount, int IValue)
{
	//�����Ϸ��Լ��
	if (&STHead == NULL || STHead == NULL || *ICount <= 0)
		return;
	//ѭ��ɾ��
	while (1)
	{
		//����λ��
		struct Node* pTemp = GetNodeByData(STHead, IValue);
		//û�ҵ�������������û����������ˣ�����ѭ��
		if (pTemp == NULL)
			return;
		//����λ��ǰ����Ľڵ�����
		pTemp->pPre->pNext = pTemp->pNext;
		pTemp->pNext->pPre = pTemp->pPre;
		//�ͷŸýڵ�
		free(pTemp);
		//����-1
		*ICount -= 1;
	}
}
//�飺����ָ���ڵ㣨�����±꣩
struct Node* GetNodeByIndex(struct Node* STHead, int ICount, int iIndex)
{
	//�����Ϸ��Լ��
	if (&STHead == NULL || STHead == NULL || ICount < 0 || iIndex < 0 || iIndex >= ICount)
		return NULL;
	//�ӵ�2�ڵ㿪ʼ����
	struct Node* pTemp = STHead->pNext;
	//ѭ������
	for (int i = 0; i < iIndex; i++)
		pTemp = pTemp->pNext;
	return pTemp;
}
//�飺����ָ���ڵ㣨�������ݣ�
struct Node* GetNodeByData(struct Node* STHead, int iValue)
{
	//�����Ϸ��Լ��
	if (&STHead == NULL || STHead == NULL)
		return NULL;
	//�ӵ�2�ڵ㿪ʼ
	struct Node* pTemp = STHead->pNext;
	//ѭ������
	while (pTemp != STHead)
	{
		if (pTemp->iData == iValue)
			return pTemp;
		pTemp = pTemp->pNext;
	}
	//û�ҵ�
	return NULL;
}
//ѭ������
void AllShow(struct Node* STHead, int ICount)
{
	//�����Ϸ��Լ��
	if (&STHead == NULL || STHead == NULL || ICount < 0)
		return;
	//�ӿ�ͷ��һλ��ʼ����2���ڵ㿪ʼ
	struct Node* pTemp = STHead->pNext;
	printf("\n���ݸ�����%2d  ����Ϊ��", ICount);
	//��ʽһ��whileѭ��������ӡ
	while (pTemp != STHead)
	{
		printf(" %3d", pTemp->iData);
		pTemp = pTemp->pNext;
	}
	////��ʽ����forѭ��������ӡ
	//for (int i = 0; i < (*ICount); i++)
	//{
	//	printf(" %3d", pTemp->iData);
	//	pTemp = pTemp->pNext;
	//}
	putchar('\n');
}
//�ͷ�
void FreeList(struct Node* STHead, int* ICount)
{
	//�����Ϸ��Լ��
	if (&STHead == NULL || STHead == NULL || *ICount < 0 || STHead->pNext == STHead)
		return;
	//��¼��2���ڵ�
	struct Node* pTemp = STHead->pNext;
	while (pTemp != STHead)
	{
		//��¼��ǰ�Ľڵ��ַ
		struct Node* pT = pTemp;
		//�����������
		pTemp = pTemp->pNext;
		//�ͷŽڵ�
		free(pT);
	}
	//��ʼ����ͷָ��
	STHead->pNext = STHead;
	STHead->pPre = STHead;
	//������0
	*ICount = 0;
}