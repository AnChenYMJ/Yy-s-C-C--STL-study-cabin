#include "SX.h"

SX::SX()
{
	g_pHead = NULL;
	g_pEnd = NULL;
	g_iNodeCount = 0;
}
SX::~SX()
{
	FreeList();
}

void SX::AddToEnd(int ipData)
{
	//�����Ϸ��Լ��
	if (&g_pHead == NULL || &g_pEnd == NULL || g_iNodeCount < 0)
		return;//��ʦ˵ȫ�ֱ����ȵ����Ͳ��ü��ָ���ַ�ˣ����һ��Ǽ��ϣ�

	//�����ڵ�
	struct Node* pTemp = new struct Node;
	if (pTemp == NULL)
		return;
	//�ڵ㸳ֵ
	pTemp->m_iData = ipData;
	pTemp->m_pNext = NULL;
	pTemp->m_pPre = NULL;
	//�ڵ����ӵ��������������жϣ�
	//����û�нڵ㣺
	if (g_iNodeCount == 0 && g_pHead == NULL)
		//��¼ͷβ��ָ���¼����ڵ�
		g_pHead = pTemp;
	//�����Ѵ��ڽڵ�
	else
	{
		//ԭβ�ڵ���ýڵ㻥���¼��ַ��˫������
		g_pEnd->m_pNext = pTemp;
		pTemp->m_pPre = g_pEnd;
	}
	//��������ظ��Ĳ����ŵ�����(�򻯴���)
	g_pEnd = pTemp;		//��¼β�ڵ�ָ���¼��β�ڵ�
	g_iNodeCount += 1;	//����+1
}
void SX::AddToHead(int ipData)
{
	//�����Ϸ��Լ��
	if (&g_pHead == NULL || &g_pEnd == NULL || g_iNodeCount < 0)
		return;
	//�����ڵ�
	struct Node* pTemp = new struct Node;
	if (pTemp == NULL)
		return;
	//�ڵ㸳ֵ
	pTemp->m_pNext = NULL;
	pTemp->m_pPre = NULL;
	pTemp->m_iData = ipData;
	//�ڵ���ӵ�����2�������
	//1.����û�нڵ�ʱ
	if (g_pHead == NULL)
		g_pEnd = pTemp;
	//2.�����нڵ�ʱ
	else
	{
		//�ڵ�����ͷ�ڵ�֮ǰ
		pTemp->m_pNext = g_pHead;
		g_pHead->m_pPre = pTemp;
	}
	//��¼ͷ�ڵ�ָ���¼��ͷ�ڵ�
	g_pHead = pTemp;
	//����+1
	g_iNodeCount++;
}
void SX::InsertNodeByIndex(int Index, int iCount, int ipData)
{
	//�����Ϸ��Լ��
	if (&g_pHead == NULL || &g_pEnd == NULL || g_iNodeCount < 0 || Index < 0 || iCount <= 0 || Index > g_iNodeCount)
		return; //Index = g_iNodeCountʱ���͸պ���β�ڵ����һλ�����ܽ���β�����
	//��ӽڵ㣨3�������
	//1.�±�Ϊ0��ͷ���
	if (Index == 0)
	{
		for (int i = 0; i < iCount; i++)
			AddToHead(ipData);
	}
	//2.�±�Ϊβ�ڵ���һλ��β���
	else if (Index == g_iNodeCount)
	{
		for (int i = 0; i < iCount; i++)
			AddToEnd(ipData);
	}
	//3.�м�λ�����
	else
	{
		for (int i = 0; i < iCount; i++)
		{
			//�����ڵ�
			struct Node* pNew = new struct Node;
			if (pNew == NULL)
				return;
			//�ڵ㸳ֵ
			pNew->m_pNext = NULL;
			pNew->m_pPre = NULL;
			pNew->m_iData = ipData;
			//�����±�λ��
			struct Node* pTemp = g_pHead;
			for (int i = 0; i < Index; i++)
			{
				pTemp = pTemp->m_pNext;
			}
			//��λ�õ�ǰһλ�ڵ����½ڵ�����
			pTemp->m_pPre->m_pNext = pNew;	//��ͼ�ܷ�����⣬pTemp->m_pPre �Ǹ�λ�õ�ǰһ�����
			pNew->m_pPre = pTemp->m_pPre;
			//�½ڵ���ԭ��λ�õĽڵ�����
			pNew->m_pNext = pTemp;
			pTemp->m_pPre = pNew;
			//����+1
			g_iNodeCount++;
		}
	}
}
void SX::InsertNodeByData(int iValue, int ipData)
{
	//�����Ϸ��Լ��
	if (&g_pHead == NULL || &g_pEnd == NULL || g_iNodeCount < 0 || g_pHead == NULL)
		return;//���˵�û�нڵ�����
	//���Ҷ�Ӧ�ڵ�
	struct Node* pTemp = g_pHead;
	while (pTemp != NULL)
	{
		if (pTemp->m_iData == iValue)
			break;
		pTemp = pTemp->m_pNext;
	}
	//�ж��Ƿ��ҵ��ýڵ�
	//�ҵ�
	if (pTemp != NULL)
	{
		//�����λ����ͷ�ڵ�,ͷ���
		if (pTemp == g_pHead)
			AddToHead(ipData);
		//��λ�ò���ͷ�ڵ�
		else
		{
			//�����½ڵ�
			struct Node* pNew = new struct Node;
			if (pNew == NULL)
				return;
			//�ڵ㸳ֵ
			pNew->m_pNext = NULL;
			pNew->m_pPre = NULL;
			pNew->m_iData = ipData;
			//��λ�õ�ǰһλ�ڵ����½������
			pTemp->m_pPre->m_pNext = pNew;
			pNew->m_pPre = pTemp->m_pPre;
			//�½ڵ����λ�ýڵ�����
			pNew->m_pNext = pTemp;
			pTemp->m_pPre = pNew;
			//����+1
			g_iNodeCount += 1;
		}
	}
	//û�ҵ�
	else
	{
		cout << "\nδ�ҵ�������\n";
		return;
	}
}
struct Node* SX::GetByData(int iValue)
{
	//�����Ϸ��Լ��
	if (&g_pHead == NULL || &g_pEnd == NULL || g_iNodeCount <= 0 || g_pHead == NULL)
		return NULL;
	//�ӵ�һ���ڵ㿪ʼ����
	struct Node* pTemp = g_pHead;
	while (pTemp != NULL)
	{
		if (pTemp->m_iData == iValue)
			break;	//�ҵ�������ѭ��
		pTemp = pTemp->m_pNext;
	}
	//����ҵ������ص��ǵ�ַ�����û�ҵ����ص���NULL
	return pTemp;
}
struct Node* SX::GetByIndex(int Index)
{
	//�����Ϸ��Լ��
	if (&g_pHead == NULL || &g_pEnd == NULL || g_iNodeCount <= 0 || g_pHead == NULL || Index < 0 || Index >= g_iNodeCount)
		return NULL;//Index >= g_iNodeCount��ȷ�����ᳬ���±�����Խ��
	//�ӵ�һ����㿪ʼ����
	struct Node* pTemp = g_pHead;
	if (pTemp == NULL)
		return NULL;
	//����
	for (int i = 0; i < Index; i++)
		pTemp = pTemp->m_pNext;
	return pTemp;
}
void SX::DeleteNode(struct Node* pTemp)
{
	//�����Ϸ��Լ��
	if (&pTemp == NULL || pTemp == NULL || g_pHead == NULL)
		return;
	//�ж�ͷ��β���м��е�����������ֿ�����
	//ͷɾ��
	if (pTemp == g_pHead)
	{
		//�ж��Ƿ�ֻ��һ���ڵ�
		if (g_pHead == g_pEnd)
		{
			//�ͷ�
			delete pTemp;
			//ͷβ��¼ָ�븳��
			g_pHead = NULL;
			g_pEnd = NULL;
		}
		else
		{
			//��¼��ǰ�ڵ�
			struct Node* PT = g_pHead;
			//�ı���ͷ�ڵ��ָ��ԭͷ�ڵ����һλ��
			g_pHead->m_pNext->m_pPre = NULL;
			//ͷ��¼ָ���¼��ͷ�ڵ�
			g_pHead = g_pHead->m_pNext;
			//�ͷ�ԭͷ�ڵ�
			delete PT;
		}
	}
	//βɾ��
	else if (pTemp == g_pEnd)
	{
		//�ж��Ƿ�ֻ��һ���ڵ㣺ͷɾ���жϵ�ʱ����������жϹ��ˣ������ٲ�������Ϊһ���ڵ㣬����ͷɾ��Ҳ��βɾ��

		//��¼��ǰ�ڵ�
		struct Node* PT = g_pEnd;
		//�ı���β�ڵ�ָ��
		g_pEnd->m_pPre->m_pNext = NULL;
		//β��¼ָ���¼��β�ڵ�
		g_pEnd = g_pEnd->m_pPre;
		//�ͷ�ԭβ�ڵ�
		delete PT;
	}
	//�м�ɾ��
	else
	{
		//�ı��λ��ǰһλ�ڵ�ָ��
		pTemp->m_pPre->m_pNext = pTemp->m_pNext;
		//�ı��λ�ú�һλ�ڵ�ָ��
		pTemp->m_pNext->m_pPre = pTemp->m_pPre;
		//�ͷŸýڵ�
		delete pTemp;

		////����-1
		//g_iNodeCount--;	//�����������ж϶��������ⲽ���������Ƿŵ�����һ��ִ��
	}
	//����-1
	g_iNodeCount--;
}
void SX::DeleteByIndex(int Index)
{
	//�����Ϸ��Լ��	//����FindByIndex���Һ������˲�����⣬�������ǿ��Բ�д
	if (&g_pHead == NULL || &g_pEnd == NULL || g_pHead == NULL || g_iNodeCount <= 0 || Index < 0 || Index >= g_iNodeCount)
		return;
	//�����±��Ӧλ��
	struct Node* pTemp = GetByIndex(Index);
	//�ҵ�����нڵ�ɾ��
	if (pTemp != NULL)
		DeleteNode(pTemp);
	else
		return;
}
void SX::DeleteByData(int iValue)
{
	//�����Ϸ��Լ��
	if (&g_pHead == NULL || &g_pEnd == NULL || g_iNodeCount <= 0 || g_pHead == NULL)
		return;

	//ѭ��������ɾ��
	struct Node* pTemp;
	//ע���ж������ķ������ȼ�	//����ѭ��д������࣬���ǳ�ѧ�߲������
	while (NULL != (pTemp = GetByData(iValue)))
		DeleteNode(pTemp);
}
void SX::ChangeByData(int iValue, int ipData)
{
	//�����Ϸ��Լ��
	if (&g_pHead == NULL || &g_pEnd == NULL || g_iNodeCount <= 0 || g_pHead == NULL)
		return;
	//���ҵ���Ӧ�ڵ㣬���޸ĸýڵ�����
	struct Node* pTemp = g_pHead;
	while (pTemp != NULL)
	{
		if (pTemp->m_iData == iValue)
			pTemp->m_iData = ipData;
		pTemp = pTemp->m_pNext;
	}
}
void SX::ChangeByIndex(int Index, int ipData)
{
	//�����Ϸ��Լ��
	if (&g_pHead == NULL || &g_pEnd == NULL || g_iNodeCount <= 0 || g_pHead == NULL || Index < 0 || Index >= g_iNodeCount)
		return;
	//���Ҹ�λ��
	struct Node* pTemp = GetByIndex(Index);
	//�ҵ�����иýڵ���޸�
	if (pTemp != NULL)
		pTemp->m_iData = ipData;
	//û�ҵ�
	else
		return;
}
void SX::FreeList()
{	//ȫ�����ı������п�������ѭ���ظ����룬�����ڴ�ռ�ù��߱���������ȫ�����ı������������ֶ��ͷŵ�
	//�����Ϸ��Լ��
	if (&g_pHead == NULL || &g_pEnd == NULL || g_pEnd == NULL)
		return;
	//ѭ�������ͷ�
	struct Node* pTemp = g_pHead;
	while (pTemp != NULL)
	{
		//��¼Ҫ���ͷŵĽڵ�
		struct Node* pT = pTemp;
		//pTemp��������
		pTemp = pTemp->m_pNext;
		//�ͷŽڵ�
		delete pT;
	}
	g_pHead = NULL;
	g_pEnd = NULL;
	g_iNodeCount = 0;
}
void SX::ShowZheng()
{
	//�����Ϸ��Լ��
	if (&g_pHead == NULL || &g_pEnd == NULL || g_iNodeCount < 0)
		return;

	//��ӡ��ʾ
	cout << "\n�ڵ���:" <<  g_iNodeCount << "  ����Ϊ: ";
	//ѭ������
	struct Node* pTemp = g_pHead;
	while (pTemp != NULL)
	{
		cout << " " << pTemp->m_iData;
		pTemp = pTemp->m_pNext;
	}
	cout << '\n';
}
void SX::ShowFan()
{
	//�����Ϸ��Լ��
	if (&g_pHead == NULL || &g_pEnd == NULL || g_iNodeCount < 0)
		return;

	//��ӡ��ʾ
	cout << "\n�ڵ���:" << g_iNodeCount << "  ����Ϊ: ";
	//ѭ������
	struct Node* pTemp = g_pEnd;
	while (pTemp != NULL)
	{
		cout << " " << pTemp->m_iData;
		pTemp = pTemp->m_pPre;
	}
	putchar('\n');
}
