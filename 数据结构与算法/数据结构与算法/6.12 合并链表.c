#include <stdio.h>
#include <stdlib.h>

struct Node
{	//�����淶��m_p g_p m��My��д�������Ա��g����ȫ�ֱ�����p����ָ������
	int m_iData;			//��¼����
	struct Node* m_pNext;	//��¼��һ�ڵ��ַ
	struct Node* m_pPre;	//��¼��һ�ڵ��ַ
};

	

//�����в����������Ӹ����ԣ�����������Ե���ͬһ����������������ԣ�

//����β���
void AddToEnd(struct Node** pHead, struct Node** pEnd, int* iCount, int ipData);
//����ͷ���
void AddToHead(struct Node** pHead, struct Node** pEnd, int* iCount, int ipData);
//�ϲ�����ժͷ
struct Node* GetHead(struct Node** pHead, struct Node** pEnd, int* iCount);
//�ϲ���������
void HeBing(struct Node** pHA, struct Node** pEA, int* iCA, struct Node** pHB, struct Node** pEB, int* iCB);
//�����ͷ�
void FreeList(struct Node** pHead, struct Node** pEnd, int* iCount);
//������ӡ(����)
void ShowZheng(struct Node** pHead, struct Node** pEnd, int* iCount);
//������ӡ(����)
void ShowFan(struct Node** pHead, struct Node** pEnd, int* iCount);


int main(void)
{
	//A����
	struct Node* g_pHA = NULL;
	struct Node* g_pEA = NULL;
	int	g_iACount = 0;

	//B����
	struct Node* g_pHB = NULL;
	struct Node* g_pEB = NULL;
	int	g_iBCount = 0;

	AddToEnd(&g_pHA, &g_pEA, &g_iACount, 1);
	AddToHead(&g_pHA, &g_pEA, &g_iACount, 3);
	AddToEnd(&g_pHA, &g_pEA, &g_iACount, 5);
	AddToHead(&g_pHA, &g_pEA, &g_iACount, 8);
	AddToEnd(&g_pHA, &g_pEA, &g_iACount, 14);

	ShowZheng(&g_pHA, &g_pEA, &g_iACount);
	ShowFan(&g_pHA, &g_pEA, &g_iACount);

	ShowZheng(&g_pHB, &g_pEB, &g_iBCount);
	//B�޽ڵ�������
	HeBing(&g_pHA, &g_pEA, &g_iACount, &g_pHB, &g_pEB, &g_iBCount);
	ShowZheng(&g_pHB, &g_pEB, &g_iBCount);
	//����������Ƿ�ɹ�
	AddToEnd(&g_pHB, &g_pEB, &g_iBCount, 11);
	AddToHead(&g_pHB, &g_pEB, &g_iBCount, 7);
	ShowZheng(&g_pHB, &g_pEB, &g_iBCount);
	//���Խ�����ͷ���
	HeBing(&g_pHA, &g_pEA, &g_iACount, &g_pHB, &g_pEB, &g_iBCount);
	HeBing(&g_pHA, &g_pEA, &g_iACount, &g_pHB, &g_pEB, &g_iBCount);
	ShowZheng(&g_pHB, &g_pEB, &g_iBCount);
	//���Խ������м����
	HeBing(&g_pHA, &g_pEA, &g_iACount, &g_pHB, &g_pEB, &g_iBCount);
	ShowZheng(&g_pHB, &g_pEB, &g_iBCount);
	//���Խ�����β���
	HeBing(&g_pHA, &g_pEA, &g_iACount, &g_pHB, &g_pEB, &g_iBCount);
	ShowZheng(&g_pHB, &g_pEB, &g_iBCount);
	//����������Ƿ�ɹ�
	AddToEnd(&g_pHB, &g_pEB, &g_iBCount, 0);
	AddToHead(&g_pHB, &g_pEB, &g_iBCount, 0);
	ShowZheng(&g_pHB, &g_pEB, &g_iBCount);
	ShowFan(&g_pHB, &g_pEB, &g_iBCount);
	//���Դ�ӡ���͹������A
	ShowZheng(&g_pHA, &g_pEA, &g_iACount);


	system("pause>0");
	return 0;
}


void AddToEnd(struct Node** pHead, struct Node** pEnd, int* iCount, int ipData)
{
	//�����Ϸ��Լ��
	if (pHead == NULL || pEnd == NULL || iCount < 0)
		return;

	//�����ڵ�
	struct Node* pTemp = (struct Node*)malloc(sizeof(struct Node));
	if (pTemp == NULL)
		return;
	//�ڵ㸳ֵ
	pTemp->m_iData = ipData;
	pTemp->m_pNext = NULL;
	pTemp->m_pPre = NULL;
	//�ڵ����ӵ��������������жϣ�
	//����û�нڵ㣺
	if (*iCount == 0 && *pHead == NULL)
		//��¼ͷβ��ָ���¼����ڵ�
		*pHead = pTemp;
	//�����Ѵ��ڽڵ�
	else
	{
		//ԭβ�ڵ���ýڵ㻥���¼��ַ��˫������
		(*pEnd)->m_pNext = pTemp;
		pTemp->m_pPre = *pEnd;
	}
	//��������ظ��Ĳ����ŵ�����(�򻯴���)
	*pEnd = pTemp;		//��¼β�ڵ�ָ���¼��β�ڵ�
	*iCount += 1;	//����+1
}
void AddToHead(struct Node** pHead, struct Node** pEnd, int* iCount, int ipData)
{
	//�����Ϸ��Լ��
	if (pHead == NULL || pEnd == NULL || iCount < 0)
		return;
	//�����ڵ�
	struct Node* pTemp = (struct Node*)malloc(sizeof(struct Node));
	if (pTemp == NULL)
		return;
	//�ڵ㸳ֵ
	pTemp->m_pNext = NULL;
	pTemp->m_pPre = NULL;
	pTemp->m_iData = ipData;
	//�ڵ���ӵ�����2�������
	//1.����û�нڵ�ʱ
	if (*pHead == NULL)
		*pEnd = pTemp;
	//2.�����нڵ�ʱ
	else
	{
		//�ڵ�����ͷ�ڵ�֮ǰ
		pTemp->m_pNext = *pHead;
		(*pHead)->m_pPre = pTemp;
	}
	//��¼ͷ�ڵ�ָ���¼��ͷ�ڵ�
	*pHead = pTemp;
	//����+1
	(*iCount)++;	//++ ������� * ���ȼ���
}
struct Node* GetHead(struct Node** pHead, struct Node** pEnd, int* iCount)
{
	//�����Ϸ��Լ��
	if (pHead == NULL || pEnd == NULL || *pHead == NULL || *iCount < 0)
		return NULL;
	//��¼ͷ�ڵ�
	struct Node* pTemp = *pHead;
	//�ж��Ƿ�ֻ��һ���ڵ�
	if (*pHead == *pEnd)
	{
		//ͷβ��¼ָ�븳��
		*pHead = NULL;
		*pEnd = NULL;
	}
	else
	{
		//ʹͷ��¼ָ���¼��һ���ڵ�
		*pHead = (*pHead)->m_pNext;
		//�Ͽ��������Ľڵ����������ϵ
		(*pHead)->m_pPre = NULL;
	}
	//�Ͽ��������Ľڵ����������ϵ
	pTemp->m_pNext = NULL;
	//����-1
	*iCount -= 1;
	//��������������Ľڵ��ַ
	return pTemp;


}
void HeBing(struct Node** pHA, struct Node** pEA, int* iCA, struct Node** pHB, struct Node** pEB, int* iCB)
{
	//�����Ϸ��Լ��
	if (pHA == NULL || pEA == NULL || pHB == NULL || pEB == NULL || *pHA == NULL || *iCA <= 0 || *iCB < 0)
		return;
	//��¼����A���������Ľڵ�
	struct Node* pTemp = GetHead(pHA, pEA, iCA);
	if (pTemp == NULL)
		return;
	//B��û�нڵ�
	if (*pHB == NULL)
	{
		//���½ڵ���ӵ�����B
		*pHB = pTemp;		//pTemp��ժͷ�����У�����������ַ��¼�Ѿ���������
		*pEB = pTemp;
		//����+1
		*iCB += 1;
	}
	//B�Ѿ����˽ڵ�
	else
	{
		//����Bֻ��һ���ڵ�
		if (*pHB == *pEB)
		{
			//�½ڵ��B�Ľڵ�С	ͷ���
			if (pTemp->m_iData <= (*pHB)->m_iData)
			{
				//�½ڵ����ӵ�Bԭͷ�ڵ�ǰ
				pTemp->m_pNext = *pHB;
				(*pHB)->m_pPre = pTemp;
				//Bͷ��¼ָ���¼��ͷ�ڵ�
				*pHB = pTemp;
				//����+1
				*iCB += 1;
			}
			//�½ڵ��B�Ľڵ��	β���
			else
			{
				//�½ڵ����ӵ�Bԭͷ�ڵ��
				(*pEB)->m_pNext = pTemp;
				pTemp->m_pPre = *pEB;		//pTemp��ժͷ�����У�����������ַ��¼�Ѿ���������
				//Bͷ��¼ָ���¼��β�ڵ�
				*pEB = pTemp;
				//����+1
				*iCB += 1;
			}
		}
		//����B�ж���ڵ�
		else
		{
			//�½ڵ��B��ͷ�ڵ�С	ͷ���
			if (pTemp->m_iData <= (*pHB)->m_iData)
			{
				//�½ڵ����ӵ�Bԭͷ�ڵ�ǰ
				pTemp->m_pNext = *pHB;
				(*pHB)->m_pPre = pTemp;
				//Bͷ��¼ָ���¼��ͷ�ڵ�
				*pHB = pTemp;
				//����+1
				*iCB += 1;
			}
			//�½ڵ��B��β�ڵ��	β���
			else if (pTemp->m_iData > (*pEB)->m_iData)
			{
				//�½ڵ����ӵ�Bԭβ�ڵ��
				(*pEB)->m_pNext = pTemp;
				pTemp->m_pPre = *pEB;		//pTemp��ժͷ�����У�����������ַ��¼�Ѿ���������
				//Bͷ��¼ָ���¼��β�ڵ�
				*pEB = pTemp;
				//����+1
				*iCB += 1;
			}
			//�½ڵ��B��ͷ�ڵ�󡢱�B��β�ڵ�С	�м����
			else
			{
				struct Node* PT = *pHB;
				if (PT == NULL)
					return;

				//ѭ�����Һ��ʵĲ���λ��
				while (PT->m_pNext != NULL)
				{	//λ�������ǣ��½ڵ�����λ�ȸýڵ���ڵ��ڣ�ͬʱ�ȸýڵ����һλС�ڵ���
					if (pTemp->m_iData >= PT->m_iData && pTemp->m_iData <= PT->m_pNext->m_iData)
						break;
					PT = PT->m_pNext;
				}
				//�������棺��NULLָ��PT->m_pNext��ʹ��
				if (PT->m_pNext == NULL)
					return;
				//�ҵ�����λ��
				//�½ڵ����λ�ú�һλ�ڵ�����

				pTemp->m_pNext = PT->m_pNext;
				PT->m_pNext->m_pPre = pTemp;
				//�½ڵ����λ�ýڵ�����
				PT->m_pNext = pTemp;
				pTemp->m_pPre = PT;
				//����+1
				*iCB += 1;
			}
		}
	}

}
void FreeList(struct Node** pHead, struct Node** pEnd, int* iCount)
{	//ȫ�����ı������п�������ѭ���ظ����룬�����ڴ�ռ�ù��߱���������ȫ�����ı������������ֶ��ͷŵ�
	//�����Ϸ��Լ��
	if (pHead == NULL || pEnd == NULL || *pHead == NULL)
		return;
	//ѭ�������ͷ�
	struct Node* pTemp = *pHead;
	while (pTemp != NULL)
	{
		//��¼Ҫ���ͷŵĽڵ�
		struct Node* pT = pTemp;
		//pTemp��������
		pTemp = pTemp->m_pNext;
		//�ͷŽڵ�
		free(pT);
	}
	*pHead = NULL;
	*pEnd = NULL;
	*iCount = 0;
}
void ShowZheng(struct Node** pHead, struct Node** pEnd, int* iCount)
{
	//�����Ϸ��Լ��
	if (pHead == NULL || pEnd == NULL || iCount < 0)
		return;

	//��ӡ��ʾ
	printf("\n�ڵ���:%2d  ����Ϊ: ", *iCount);
	//ѭ������
	struct Node* pTemp = *pHead;
	while (pTemp != NULL)
	{
		printf(" %3d", pTemp->m_iData);
		pTemp = pTemp->m_pNext;
	}
	putchar('\n');
}
void ShowFan(struct Node** pHead, struct Node** pEnd, int* iCount)
{
	//�����Ϸ��Լ��
	if (pHead == NULL || pEnd == NULL || iCount < 0)
		return;

	//��ӡ��ʾ
	printf("\n�ڵ���:%2d  ����Ϊ: ", *iCount);
	//ѭ������
	struct Node* pTemp = *pEnd;
	while (pTemp != NULL)
	{
		printf(" %3d", pTemp->m_iData);
		pTemp = pTemp->m_pPre;
	}
	putchar('\n');
}
