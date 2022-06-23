#include <stdio.h>
#include <stdlib.h>		//system��ͷ�ļ�
#include <string.h>		

//1.�п�ͷ������ǰ˵����
void AAA()
{
	//�п�ͷ��������߼������һЩ
	//�����ͷ�ڵ㲻װ���ݣ�ֻװ�ŵ�2���ڵ�ĵ�ַ������Զ��������ͷ����
	//ͷ���/ɾ���������ڵ�2�ڵ�ǰ���/ɾ������ͷ�ڵ���ָ���µĵ�2�ڵ�
	//�㷨�ⶫ������һ�ɲ���ģ�����ѧ��Щ��ǰ���ľ��飬�������Ҫ�����ǿ��԰���˼�����޸�
	
	//���Ϻ�ѧУ�̵���������û��pEnd����¼β�ڵ㣩����������п�ͷ�ľ���ʾû��pEnd��д�����߼���һ����ֻ��Ҫ��ͷ����Ѱ��β�ڵ�
	//������ʾ���п�ͷ������������pEnd���Ӽ�����������ʹ�߼�����㣩
	//�Լ����Գ��Լ���β��ͷ��ѧ����ܿ����󲿷ֵĴ����ˣ�Ȼ���Լ�ȱʲô
	//��һ���ҾͲ��Ӷ����ע���ˣ��Ժ�Ҫ�ǿ��������룬û��ע�͵ģ��ɷ����п�ͷ���������ע��

	//ѧ�걾��ʱ�ˣ���ʦ����һ�£����޿�ͷ������pEnd������
	//�п�ͷ����������ɾ�߼��ϸ��򵥣��ҿ�ͷһֱ���ڣ�����û�нڵ�ʱ����ͷҲ����ҪҪ��ֵNULL
	//�޿�ͷ��һЩ��ɾ����Ҫ����һ�㡢��Ϊ��pHead���ڣ�����û�ڵ�ʱ��pHeadҪ��ֵNULL��
	//��pEnd��β���ʱЧ�ʴ�����ӣ��ڵ���Խ��Խ���ԣ�����Ϊ�����������β�ڵ㣬β�ڵ㷢������仯ʱ����Ҫ�����жϴ���pEnd��ָ��
	//��pEnd�����˴����߼���β���Ч�ʵ�
	//���ѡ���п�ͷ����pEndд����Ҫ�����ɣ�����ʵ��Ӧ���У�β��������ǱȽϸߵģ��������п�ͷ����pEndҪ��
	//��ʵ���������ͼ���������������Ҫ�򵥺ܶ�ܶ��ˣ����ĸ�Ҳ����������ȥ������Ч��Ϊ׼��
	//����ʱû��д��ת�������������߼����޿�ͷ��һ����
	//���ϵĴ��룬���ǲ鿴ʱҪע�⣺������Ϊ����ṹ������ͬ���ʺ���������б仯���������߼���ࡣ���Կ����ϴ���Ҫע����������ṹ��������
}

struct Node
{
	int iData;
	struct Node* iNext;
};

//����β���
void AddToTail		(struct Node* stHead, int pData);
//����ͷ���
void AddToHead		(struct Node* stHead, int pData);
//����ָ�����ݺ���ӣ������ݲ��ҡ�1�μ�1����
void AddBeHandData	(struct Node* stHead, int iPosData, int pData);
//����ָ���±�λ����ӽڵ�(1��)
void AddByIndex		(struct Node* stHead, int iPosIndex, int pData);
//����ָ���±�λ����ӽڵ�(N��)
void AddByIndex		(struct Node* stHead, int iPosIndex, int pCount, int pData);
//ɾ��ɾ��ָ���±�ڵ�
void DeleteByIndex	(struct Node* stHead, int pIndex);
//ɾ��ɾ��ָ�����ݽڵ㣨N����
void DeleteAllByData(struct Node* stHead, int pValue);
//ɾ��ɾ���ظ������ݣ�ȥ�أ�
void DeleteSame		(struct Node* stHead);
//���ҽ�㣨�������ݣ����ҵ���һ�����ֵģ�
struct Node* FindNodeByData	(struct Node* stHead, int pData);
//���ҽ�㣨�����±꣩
struct Node* FindNodeByIndex(struct Node* stHead, int pIndex);
//�޸Ľڵ����ݣ������±꣩
void ChangeByIndex	(struct Node stHead, int pIndex, int pValue);
//�޸Ľڵ����ݣ��������ݣ�
void ChangeByData	(struct Node stHead, int pData, int pValue);
//������ӡ
void AllShow		(struct Node stHead);
//�ͷſռ�
void FreeList		(struct Node* stHead);

int main(void)
{
	//��ͷ���ṹ��������ͣ���Ķ������ͣ���
	struct Node stHead = { 0, NULL };	//����д�������㣬ջ�������������ֶ��ͷ�
	//int iNodeCount = 0;					//����,������Ϊ�˷��㣬�ѿ�ͷ������λ��������
	//���԰ѿ�ͷ�����д��ȫ�����У�����ʹ�ø����㣬����ѧϰΪ����⣬���Ƿŵ���������

	//��ͷ(ָ�����ͶԱ�)
	{
		//�ԱȻᷢ�֣�ָ�����͵Ĵ�������Ҫmalloc�ռ䡢��ֵ����ʹ����Ҫ�ֶ��ͷ�
		//����鷳һЩ
		struct Node* pHead = (struct Node*)malloc(sizeof(struct Node));
		if (pHead != NULL)
		{
			pHead->iData = 0;		
			pHead->iNext = NULL;
		}
		free(pHead);
}	
	//β��ӣ�AddToTail����
	{
		AddToTail(&stHead, 2);
		AddToTail(&stHead, 5);
		AddToTail(&stHead, 1);
		AddToTail(&stHead, 3);

		AllShow(stHead);
	}
	//�ͷ�����ռ�
	{
		AllShow(stHead);

		FreeList(&stHead);
		AllShow(stHead);

		AddToTail(&stHead, 5);
		AddToTail(&stHead, 1);
		AllShow(stHead);

		FreeList(&stHead);
	}
	//ͷ���
	{
		AddToHead(&stHead, 3);
		AddToHead(&stHead, 1);
		AddToHead(&stHead, 2);
		AddToHead(&stHead, 5);

		AllShow(stHead);

		AddToTail(&stHead, 7);

		AllShow(stHead);

		FreeList(&stHead);
		AllShow(stHead);
	}
	//ָ�����ݺ���ӣ������ݲ��ҡ�1�μ�1����
	{
		AddToHead		(&stHead, 3);
		AddToHead		(&stHead, 1);
		AddBeHandData	(&stHead, 1, 7);
		AllShow(stHead);
		AddBeHandData	(&stHead, 3, 9);
		AllShow(stHead);
		AddBeHandData	(&stHead, 9, 23);
		AllShow(stHead);
		AddToTail		(&stHead, 2);
		AllShow(stHead);

		AddBeHandData(&stHead, 11, 22);
		AllShow(stHead);

		FreeList(&stHead);
		AllShow(stHead);
	}
	//ָ���±�λ����ӽڵ�(һ����N��)
	{
		AddToHead(&stHead, 3);
		AddToHead(&stHead, 1);
		AddBeHandData(&stHead, 1, 7);
		AllShow(stHead);
		AddBeHandData(&stHead, 3, 9);
		AllShow(stHead);
		//����һ���ڵ�
		AddByIndex(&stHead, 4, 2);
		AllShow(stHead);
		AddToHead(&stHead, 33);
		AddBeHandData(&stHead, 33, 66);
		AddToTail(&stHead, 22);
		AllShow(stHead);
		AddByIndex(&stHead, 0, 26);
		AllShow(stHead);
		//����N���ڵ�
		AddByIndex(&stHead, 9, 3, 996);
		AddByIndex(&stHead, 0, 1, 996);
		AllShow(stHead);
		AddToTail(&stHead, 22);
		AddToHead(&stHead, 33);
		AllShow(stHead);

		FreeList(&stHead);
		AllShow(stHead);
	}
	//���ҽ��
	{
		AddToHead(&stHead, 3);
		AddToHead(&stHead, 1);
		AddBeHandData(&stHead, 1, 7);
		AllShow(stHead);
		//�������ݲ���
		struct Node* pt = FindNodeByData(&stHead, 3);
		if (pt == NULL)
			printf("\n�����ݲ�����\n");
		else
			printf("\n�ҵ����ݣ� %2d\n", pt->iData);

		AddByIndex(&stHead, 0, 26);
		AddByIndex(&stHead, 4, 27);
		AllShow(stHead);
		//�����±����
		pt = FindNodeByIndex(&stHead, 4);
		if (pt == NULL)
			printf("\n���±����/ָ��ΪNULL\n");
		else
			printf("\n�ҵ����ݣ� %2d\n", pt->iData);
		//
		pt = FindNodeByIndex(&stHead, 0);
		if (pt == NULL)
			printf("\n���±����/ָ��ΪNULL\n");
		else
			printf("\n�ҵ����ݣ� %2d\n", pt->iData);
		//�����±곬��
		pt = FindNodeByIndex(&stHead, 5);
		if (pt == NULL)
			printf("\n���±����/ָ��ΪNULL\n");
		else
			printf("\n�ҵ����ݣ� %2d\n", pt->iData);
		//�����±��С
		pt = FindNodeByIndex(&stHead, -1);
		if (pt == NULL)
			printf("\n���±����/ָ��ΪNULL\n");
		else
			printf("\n�ҵ����ݣ� %2d\n", pt->iData);

		AddByIndex(&stHead, 0, 45);
		AddByIndex(&stHead, 4, 35);
		AllShow(stHead);

		FreeList(&stHead);
		AllShow(stHead);
	}
	//�޸Ľڵ����ݣ������±꣩
	{
		AddToHead(&stHead, 3);
		AddToHead(&stHead, 1);
		AddBeHandData(&stHead, 1, 7);
		AddBeHandData(&stHead, 3, 7);
		AddByIndex(&stHead, 4, 2);
		AddToHead(&stHead, 33);
		AddBeHandData(&stHead, 33, 66);
		AddToTail(&stHead, 66);
		AllShow(stHead);

		//�����±��޸�
		ChangeByIndex(stHead, 0, 5);
		ChangeByIndex(stHead, 7, 5);
		AllShow(stHead);

		//���������޸ģ�N����
		ChangeByData(stHead, 66, 11);
		AllShow(stHead);
		ChangeByData(stHead, 5, 996);
		AllShow(stHead);
		ChangeByData(stHead, 996, 27);
		AllShow(stHead);

		FreeList(&stHead);
		AllShow(stHead);
	}
	//ɾ��ָ���±�ڵ�
	{
		AddToTail(&stHead, 1);
		AddToTail(&stHead, 5);
		AddToHead(&stHead, 3);
		AllShow(stHead);

		DeleteByIndex(&stHead, 0);
		AllShow(stHead);

		AddToTail(&stHead, 9);
		AllShow(stHead);
		DeleteByIndex(&stHead, 2);
		AllShow(stHead);
		AddToTail(&stHead, 4);
		AllShow(stHead);

		FreeList(&stHead);
		AllShow(stHead);
	}
	//ɾ��ָ�����ݽڵ㣨N����
	{
		AddToTail(&stHead, 1);
		AddToTail(&stHead, 5);
		AddToHead(&stHead, 3);
		AddToTail(&stHead, 5);
		AddToTail(&stHead, 5);
		AddToHead(&stHead, 1);
		AddToHead(&stHead, 1);
		AllShow(stHead);

		DeleteAllByData(&stHead, 1);
		AllShow(stHead);

		AddToHead(&stHead, 3);
		DeleteAllByData(&stHead, 5);
		AllShow(stHead);

		AddToTail(&stHead, 2);
		DeleteAllByData(&stHead, 3);
		AllShow(stHead);

		DeleteAllByData(&stHead, 2);
		AllShow(stHead);

		FreeList(&stHead);
		AllShow(stHead);
	}
	//ɾ���ظ������ݣ�ȥ�أ�
	{
		AddToTail(&stHead, 1);
		AddToTail(&stHead, 5);
		AddToHead(&stHead, 3);
		AddToTail(&stHead, 5);
		AddToTail(&stHead, 5);
		AddToHead(&stHead, 1);
		AddToHead(&stHead, 1);
		AddToHead(&stHead, 3);
		AddToHead(&stHead, 2);
		AllShow(stHead);
		DeleteSame(&stHead);
		AllShow(stHead);
		AddToTail(&stHead, 5);
		AddToHead(&stHead, 1);
		AllShow(stHead);
		DeleteSame(&stHead);
		AllShow(stHead);

		FreeList(&stHead);
		AllShow(stHead);
	}

	//��Ҫ�ص�����̨�ģ��밴�������������ʾ������࣬��Ŀ����������ϵͳ����ϵͳ������̨ ����Ϊ��δ����
	system("pause>0");
	return 0;
}


//����β���
void AddToTail(struct Node* stHead, int pData)
{	//�Ա��޿�ͷ������������ӳ��
	//�����Ϸ��Լ��	
	if (stHead == NULL || stHead->iData < 0)
		return;	//ע��˳��iNodeCount == NULL��ǰ������ΪNULLʱ�����˴�С�жϣ����³������

	//�����½ڵ�
	struct Node* pTemp = (struct Node*)malloc(sizeof(struct Node));
	//�ڵ㸳ֵ
	if (pTemp == NULL)			//�˴�����NULL��������һ�ַ�ʽ����鿴�޿�ͷ������������
		return;
	pTemp->iData = pData;
	pTemp->iNext = NULL;
	//�ҵ�β�ڵ��ַ
	struct Node* pt = stHead;	//ʹ����ʱ����pt����ͷָ�붪ʧ
	while (pt->iNext != NULL)
		pt = pt->iNext;
	//�½ڵ�ӵ�β�ڵ���
	pt->iNext = pTemp;
	//��������++
	stHead->iData++;
}
//����ͷ���
void AddToHead(struct Node* stHead, int pData)
{
	//�����Ϸ��Լ��
	if (stHead == NULL)
		return;

	//�����½ڵ�
	struct Node* pTemp = (struct Node*)malloc(sizeof(struct Node));
	if (pTemp == NULL)
		return;
	//�ڵ㸳ֵ
	pTemp->iData = pData;
	pTemp->iNext = NULL;			//��Ϊ���������pTemp->iNext���в�����������һ�������б�Ҫ�ģ�Ϊ�˱�֤�Ͻ���
	//�ڵ����ӵ���ͷ���棬ԭ��2�ڵ�ǰ��
	struct Node* pt = stHead->iNext;//�����ʱ���������������������ָ����л���Ҫ����˳��
	pTemp->iNext = pt;
	stHead->iNext = pTemp;			//��ͼ��⣬һĿ��Ȼ
	//��������
	stHead->iData += 1;
}
//����ָ�����ݺ���ӣ������ݲ��ҡ�1�μ�1����
void AddBeHandData(struct Node* stHead, int iPosData, int pData)
{
	//�����Ϸ��Լ��
	if (stHead == NULL || stHead->iData <= 0)
		return;//���˿�ָ�롢����û�нڵ㣨����ͷ��

	//�ӵ�2�ڵ㿪ʼ���Ҷ�Ӧ�ڵ�
	struct Node* pTemp = stHead->iNext;

	while (pTemp != NULL)
	{
		if (pTemp->iData == iPosData)	//*ע�⣺�Ҿ��������ж�����У�== д���� = 
			break;
		pTemp = pTemp->iNext;
	}
	//�ж��Ƿ��ҵ�
	if (pTemp == NULL)	//δ�ҵ�
	{
		printf("\nδ�ҵ���Ӧ���ݵĽڵ�\n");
		return;
	}
	else				//�ҵ�
	{
		//AddToHead(pTemp, pData);	//C3��ʦһ��ʼд�ķ�ʽ��������ֲ��ԣ���Ϊִ����pTemp->iData += 1;��ԭ���Ǽ���+1�����������ڵ�+1
		//���Բ�Ҫ�����ַ�ʽ����Ȼ��������Ǽ�������ʹ��һ������������һ��ʼ��iNodeCount�����������ı�ڵ����ݣ�����������ֽ�ʡ�������ķ�ʽ
		//��ʦ���뵽��������ˣ�

		//�鵽��λ�ú�����ӽڵ�
		AddToHead(pTemp, pData);
		pTemp->iData -= 1;		//��ΪAddToHead��ִ����pTemp->iData += 1;�������������
		//����+1
		stHead->iData += 1;


		//���µĴ��������������е����н�����߼�����һ����

		////�����½ڵ�
		//struct Node* pT = (struct Node*)malloc(sizeof(struct Node));
		//if (pT == NULL)
		//	return;
		////�ڵ㸳ֵ
		//pT->iData = pData;
		//pT->iNext = NULL;
		////�½ڵ����ӵ��鵽�Ľڵ����
		//struct Node* pA = pTemp->iNext;
		//pT->iNext = pA;
		//pTemp->iNext = pT;
		////����+1
		//stHead->iData += 1;
	}
}
//����ָ���±�λ����ӽڵ�(1��)
void AddByIndex(struct Node* stHead, int iPosIndex, int pData)
{
	//�����Ϸ��Լ��
	if (stHead == NULL || iPosIndex > stHead->iData || iPosIndex < 0)
		return;//�ڶ����жϣ��±�Ϊ�ܽڵ���-1�������ݸ���Ҳ���ܽڵ���-1����ΪҪ������ͷ���ʶ�����ֵ��ȣ����������±겻��Խ��������ж�

	//Ѱ���±�λ��
	struct Node* pTemp = stHead;
	for (int i = 0; i < iPosIndex; i++)
		pTemp = pTemp->iNext;
	//�ҵ����ڸ��±����ӽڵ�	//�ڰ�����ͷ���±꿴��������������±�ڵ����ӽڵ�
	AddToHead(pTemp, pData);	//�ڳ�����ͷ���±꿴�������滻��������±�ڵ��λ��
	pTemp->iData -= 1;
	stHead->iData += 1;
}
//����ָ���±�λ����ӽڵ�(N��)
void AddByIndex(struct Node* stHead, int iPosIndex, int pCount, int pData)
{
	//�����Ϸ��Լ��
	if (stHead == NULL || iPosIndex > stHead->iData || iPosIndex < 0)
		return;
	//���ҽڵ�
	struct Node* pTemp = stHead;
	for (int i = 0; i < iPosIndex; i++)
		pTemp = pTemp->iNext;
	//����ѭ���ڸ�λ�����N���ڵ�
	for (int j = 0; j < pCount; j++)	//�����⼸���߽�ֵ�жϲ������������������ʱ����ֽ�ϻ�ͼд��������⣬����ÿ�ζ������
	{									//���һ�Σ�Ȼ��ʹ�þͺ��ˡ���ҪҪ�ǲ����������߼���
		AddToHead(pTemp, pData);
		pTemp->iData -= 1;
		stHead->iData += 1;
	}
}
//ɾ��ɾ��ָ���±�ڵ�
void DeleteByIndex(struct Node* stHead, int pIndex)
{
	//�����Ϸ��Լ��
	if (stHead == NULL || pIndex < 0 || pIndex > stHead->iData - 1)
		return;

	//��Ϊ��Ҫ�±��ǰһλ������Ҫ�õ���ͷ�����Դӿ�ͷ��ʼ
	struct Node* pTemp = stHead;
	if (pTemp == NULL)
		return;
	//���Ҷ�Ӧ�±��ǰһ�ڵ�
	for (int i = 0; i < pIndex; i++)
		pTemp = pTemp->iNext;

	//��ʱ pTemp �Ƕ�Ӧ�±��ǰһ�ڵ�
	//��¼��Ӧ�±�
	struct Node* pt = pTemp->iNext;	//pt������Ҫ�ͷŵĽڵ�
	//A-B-CɾB����Aָ��C
	pTemp->iNext = pt->iNext;
	//�ͷŸýڵ�
	free(pt);
	//����-1
	stHead->iData -= 1;
}
//ɾ��ɾ��ָ�����ݽڵ㣨N����
void DeleteAllByData(struct Node* stHead, int pValue)
{
	//�����Ϸ��Լ��
	if (stHead == NULL || stHead->iData <= 0)
		return;

	//�ӿ�ͷ��ʼ�ң�������Ҫ�ÿ�ͷ����ڵ㣩
	struct Node* pTemp = stHead;
	//�ҵ���Ӧ�ڵ�ǰһλ
	while (pTemp->iNext != NULL)	//��һ��������ж�д����pTemp != NULL�Ǵ�ģ�����Ҫȷ��Ҫ�����Ľڵ���ڣ�������ǰһλ���ھ���
	{
		if (pTemp->iNext->iData == pValue)
		{
			//��¼��Ӧ�ڵ�
			struct Node* pt = pTemp->iNext;
			//��A-B-CɾB A->C Ȼ���ͷ�B
			pTemp->iNext = pt->iNext;
			free(pt);
			//����-1
			stHead->iData--;
			//����ѭ����ʼ�����ѭ��
			continue;		//continue������������������ѭ������������δִ�е���䣬����������һ�ε�ѭ�������ж����������Ϊ����������ѭ����
		}
		pTemp = pTemp->iNext;
	}

}
//ɾ��ɾ���ظ������ݣ�ȥ�أ�
void DeleteSame(struct Node* stHead)
{
	//ԭ���ǣ��ӵ�һ����㿪ʼ������ͷ�����������Ľڵ����ݽ��бȽϣ��ظ���ɾ��������Ҫ˫��ѭ��
	//�����Ϸ��Լ��
	if (stHead == NULL || stHead->iData <= 0)
		return;

	//�ӵڶ����ڵ㿪ʼ������ͷ�ĵ�һ����
	struct Node* pWai = stHead->iNext;
	//��һ��ѭ������������
	while (pWai != NULL)
	{
		//��¼��ǰ�ڵ�
		struct Node* pNei = pWai;
		//�ڶ���ѭ��������pWai->iData��ʣ�µĽڵ�ԱȲ���ɾ��,pNei��������ѭ��
		while (pNei->iNext != NULL)
		{	//ע��˴�pNei->iNext������Ҫ�����Աȣ�ɾ�����Ľڵ㣬�ʲ�ҪpNei != NULL ��������pNei->iNext->iData���������ΪpNei->iNextΪNULL�����û���ж�
			if (pWai->iData == pNei->iNext->iData)
			{
				//��¼��ǰ���鵽�ظ��Ľڵ�
				struct Node* pTemp = pNei->iNext;
				//��A-B-CɾB A->C Aָ��C��Ȼ���ͷ�B
				pNei->iNext = pTemp->iNext;
				//�ͷŽڵ�
				free(pTemp);
				//����-1
				stHead->iData -= 1;
				//����ѭ����ʼ������ѭ���Ƚ� ����Ҫ�����Ի�ͼ��⣬�����Ǳ�������1���ڵ�ȶԣ������©
				continue;
			}
			pNei = pNei->iNext;

		}
		pWai = pWai->iNext;
	}
}
//���ҽ�㣨�������ݣ����ҵ���һ�����ֵģ�
struct Node* FindNodeByData(struct Node* stHead, int pData)
{
	//�����Ϸ��Լ��
	if (stHead == NULL || stHead->iData <= 0)
		return NULL;
	//��������
	struct Node* pTemp = stHead;
	if (pTemp == NULL)
		return NULL;
	while (pTemp != NULL)
	{
		if (pTemp->iData == pData)
			break;		//�ҵ����˳����ص�ַ
		pTemp = pTemp->iNext;
	}
	return pTemp;		//�ҵ����򷵻ص�ַ��û�ҵ��Ļ�pTemp == NULL���򷵻���NULL
}
//���ҽ�㣨�����±꣩
struct Node* FindNodeByIndex(struct Node* stHead, int pIndex)
{
	//�����Ϸ��Լ��
	if (stHead == NULL || stHead->iData <= 0 || pIndex > stHead->iData - 1 || pIndex < 0)
		return NULL;//�˴���pIndex�Ǵӵ�2��㿪ʼ���±꣨��������ͷ���±꣩
	//�ӵ�2�ڵ㿪ʼ
	struct Node* pTemp = stHead->iNext;
	if (pTemp == NULL)
		return NULL;
	//���Ҹ��±�
	for (int i = 0; i < pIndex; i++)
		pTemp = pTemp->iNext;
	return pTemp;
}
//�޸Ľڵ����ݣ������±꣩
void ChangeByIndex(struct Node stHead, int pIndex, int pValue)
{	//�˴�û��ָ�룬�൱�ڴ����˸���ʱ����Ȼ��ֵ����
	//�����Ϸ��Լ��
	if (stHead.iData <= 0 || pIndex > stHead.iData - 1 || pIndex < 0)
		return;
	//�ӵ�2�ڵ㿪ʼ����1�ڵ��ǿ�ͷ��
	struct Node* pTemp = stHead.iNext;
	if (pTemp == NULL)
		return;
	//ѭ�����Ӧ����ýڵ�
	for (int i = 0; i < pIndex; i++)
		pTemp = pTemp->iNext;
	//�޸Ľڵ�����
	pTemp->iData = pValue;
}
//�޸Ľڵ����ݣ��������ݣ�
void ChangeByData(struct Node stHead, int pData, int pValue)
{
	//�����Ϸ��Լ��
	if (stHead.iData <= 0)
		return;
	//�ӵ�2��㿪ʼ����
	struct Node* pTemp = stHead.iNext;
	if (pTemp == NULL)
		return;
	//ѭ�����������޸�
	while (pTemp != NULL)
	{
		if (pTemp->iData == pData)
			pTemp->iData = pValue;
		pTemp = pTemp->iNext;
	}
}
//������ӡ
void AllShow(struct Node stHead)
{	//��Ϊ���޸��κ����ݣ����Կ����Բ���ָ�룬����൱�ڱ����丳ֵ�ˣ���ע��������ó�Ա�� . ָ����ó�Ա�� ->
	//�����Ϸ��Լ��	
	if (&stHead == NULL || stHead.iData < 0)
		return;

	printf("\n����ڵ���Ϊ:%2d  ����Ϊ:", stHead.iData);
	//�ӵ�2���ڵ㿪ʼ
	struct Node* pTemp = stHead.iNext;
	//ѭ����ӡ
	while (pTemp != NULL)
	{
		printf(" %2d", pTemp->iData);
		pTemp = pTemp->iNext;
	}
	putchar('\n');
}
//�ͷſռ�
void FreeList(struct Node* stHead)
{
	//�����Ϸ��Լ��
	if (stHead == NULL || stHead->iData == 0 || stHead->iData < 0)
		return;

	//��¼��2���ڵ��ַ
	struct Node* pTemp = stHead->iNext;
	//�ӵ�2���ڵ㿪ʼ�ͷ�
	if (pTemp != NULL)
	{
		while (pTemp != NULL)
		{
			struct Node* pt = pTemp;
			pTemp = pTemp->iNext;
			free(pt);
		}
		//����ͷ��ΪΨһ�ڵ�	��ע�⣬�����ͷ��ָ��malloc�Ŀռ䣬����Ҫ�ͷſռ䣩
		stHead->iNext = NULL;
		stHead->iData = 0;
	}

}