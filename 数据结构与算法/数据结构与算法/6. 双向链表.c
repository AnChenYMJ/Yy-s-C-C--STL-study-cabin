#include <stdio.h>
#include <stdlib.h>

//Ҫ��ע��
void AAA()
{
	//˫�������ӦSTL���List����
	//˫������������������ֱ�Ϊ�����ݡ���һ�ڵ��ַ����һ�ڵ��ַ
	//ͷβ��Ϊ�������߽�ԭ��Ҫ���⴦��
	//˫������Աȵ������������ˣ����Ǵ���ͷ���һ��
	//ȫ�ֱ���������Ҫ�ô�ռ��������Ϊȫ�ֱ�������򹲴������޷��ͷţ��ռ�̫����˷���
	//��������˫��������࣬���������򵥵���Ŀʹ�õ�����������˫���������Ƹ�����������������������Զ��������
	//����ʱʹ���޿�ͷ��չʾ�����ǿ����Լ��Ĵ������

}	

struct Node
{	//�����淶��m_p g_p m��My��д�������Ա��g����ȫ�ֱ�����p����ָ������
	int m_iData;			//��¼����
	struct Node* m_pNext;	//��¼��һ�ڵ��ַ
	struct Node* m_pPre;	//��¼��һ�ڵ��ַ
};

//ȫ�ֱ���
struct Node* g_pHead = NULL;	//��¼ͷ�ڵ��ָ��
struct Node* g_pEnd = NULL;	//��¼β�ڵ��ָ��
int	g_iNodeCount = 0;		//�ڵ����

//����β���
void AddToEnd(int ipData);
//����ͷ���
void AddToHead(int ipData);
//����ָ���±���ӽڵ㣨N����
void InsertNodeByIndex(int Index, int iCount, int ipData);
//����ָ������ǰ��ӽڵ㣨1����
void InsertNodeByData(int iValue, int ipData);
//�飺�������ݲ���
struct Node* GetByData(int iValue);
//�飺�����±����
struct Node* GetByIndex(int Index);
//ɾ��ɾ���ڵ㣨�������������õģ�
void DeleteNode(struct Node* pTemp);
//ɾ�������±�ɾ��ָ���ڵ�
void DeleteByIndex(int Index);
//ɾ����������ɾ��ָ���ڵ㣨N����
void DeleteByData(int iValue);
//�ģ��޸�ָ�����ݣ��������ݣ���N����
void ChangeByData(int iValue, int ipData);
//�ģ��޸�ָ�����ݣ������±꣩
void ChangeByIndex(int Index, int ipData);
//�����ͷ�
void FreeList();
//������ӡ(����)
void ShowZheng();
//������ӡ(����)
void ShowFan();


int main(void)
{
//β��ӡ�������������ͷ�
{
	AddToEnd(1);
	AddToEnd(2);
	AddToEnd(3);
	AddToEnd(4);
	AddToEnd(5);

	ShowZheng();
	AddToEnd(6);
	ShowFan();

	FreeList();
	ShowZheng();
}
//ͷ��ӡ��м���ӣ�N����
{
	//ͷ���
	AddToEnd(0);
	AddToHead(-1);
	AddToEnd(1);
	AddToHead(-2);
	AddToEnd(2);
	AddToHead(-3);
	AddToEnd(3);
	AddToHead(-4);
	AddToEnd(4);

	ShowZheng();
	ShowFan();
	//�м����(ͷ)
	InsertNodeByIndex(0, 1, 996);
	ShowZheng();
	AddToEnd(5);
	//�м����(β)
	InsertNodeByIndex(11, 2, 996);
	ShowZheng();
	AddToHead(-5);
	AddToEnd(6);
	//�м����(�м�)
	InsertNodeByIndex(6, 3, 996);
	ShowZheng();
	AddToHead(-6);
	AddToEnd(7);
	ShowZheng();
	//���Բ����ڵ��±�
	InsertNodeByIndex(31, 3, 996);
	ShowZheng();

	FreeList();
	ShowZheng();
}
//ָ������λ����ӽڵ�
{
	AddToEnd(0);
	AddToHead(-1);
	AddToEnd(1);
	AddToHead(-2);
	AddToEnd(2);
	AddToHead(-3);
	AddToEnd(3);
	AddToHead(-4);
	AddToEnd(4);

	ShowZheng();

	InsertNodeByData(0, 996);
	ShowZheng();

	AddToHead(-5);
	AddToEnd(5);
	InsertNodeByData(1, 996);
	ShowZheng();
	//���Բ����ڵ�����
	InsertNodeByData(13, 996);
	ShowZheng();

	FreeList();
	ShowZheng();
}
//�������ݣ������±ꡢ���ݣ����޸�ָ���ڵ㣨�������ݣ�N�����������±꣩
{
	AddToEnd(0);
	AddToHead(-1);
	AddToEnd(1);
	AddToHead(-2);
	AddToEnd(2);
	AddToHead(-3);
	AddToEnd(3);
	AddToHead(-4);
	AddToEnd(4);

	ShowZheng();
	//�飺�������ݲ���
	struct Node* p = GetByData(0);
	if (p != NULL)
		printf("\n�ҵ����ݣ� %3d\n", p->m_iData);
	else
		printf("\nδ�ҵ�������\n");

	AddToHead(-5);
	AddToEnd(5);
	ShowZheng();
	p = GetByData(11);
	if (p != NULL)
		printf("\n�ҵ����ݣ� %3d\n", p->m_iData);
	else
		printf("\nδ�ҵ�������\n");
	//�飺�����±�
	p = GetByIndex(10);
	if (p != NULL)
		printf("\n�ҵ��±����ݣ� %3d\n", p->m_iData);
	else
		printf("\nδ�ҵ�������\n");

	AddToHead(-6);
	AddToEnd(6);
	ShowZheng();
	p = GetByIndex(13);
	if (p != NULL)
		printf("\n�ҵ��±����ݣ� %3d\n", p->m_iData);
	else
		printf("\nδ�ҵ�������\n");
	//�ģ������±�
	ChangeByIndex(0, 14);
	ShowZheng();
	AddToHead(0);
	AddToEnd(0);
	ShowZheng();
	ChangeByIndex(14, 14);
	ShowZheng();
	ChangeByIndex(16, 16);
	ShowZheng();
	//�ģ���������
	ChangeByData(0, 26);
	ShowZheng();

	AddToHead(0);
	AddToEnd(0);
	ChangeByData(22, 27);
	ShowZheng();

	FreeList();
	ShowZheng();
} 
//ɾ��ָ���±�ڵ㣨�����±꣩
{
	AddToEnd(0);
	AddToHead(-1);
	AddToEnd(1);
	AddToHead(-2);
	AddToEnd(2);
	ShowZheng();
	//ͷɾ��
	DeleteByIndex(0);
	ShowZheng();
	//βɾ��
	AddToHead(-2);
	AddToEnd(3);
	ShowZheng();
	DeleteByIndex(5);
	ShowZheng();
	//�м�ɾ��
	AddToHead(-3);
	AddToEnd(3);
	ShowZheng();
	DeleteByIndex(3);
	ShowZheng();
	AddToHead(-4);
	AddToEnd(4);
	ShowZheng();
	ShowFan();

	FreeList();
	ShowZheng();
}
//ɾ��ָ���±�ڵ㣨�������ݣ���N����
{
	AddToEnd(2);
	AddToHead(2);
	AddToEnd(1);
	AddToHead(2);
	AddToEnd(2);
	ShowZheng();

	DeleteByData(2);
	ShowZheng();

	AddToHead(5);
	AddToEnd(1);
	ShowZheng();
	ShowFan();

	DeleteByData(1);
	ShowZheng();

	FreeList();
	ShowZheng();
}



	system("pause>0");
	return 0;
}


void AddToEnd(int ipData)
{
	//�����Ϸ��Լ��
	if (&g_pHead == NULL || &g_pEnd == NULL || g_iNodeCount < 0)
		return;//��ʦ˵ȫ�ֱ����ȵ����Ͳ��ü��ָ���ַ�ˣ����һ��Ǽ��ϣ�

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
void AddToHead(int ipData)
{
	//�����Ϸ��Լ��
	if (&g_pHead == NULL || &g_pEnd == NULL || g_iNodeCount < 0)
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
void InsertNodeByIndex(int Index, int iCount, int ipData)
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
			struct Node* pNew = (struct Node*)malloc(sizeof(struct Node));
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
void InsertNodeByData(int iValue, int ipData)
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
			struct Node* pNew = (struct Node*)malloc(sizeof(struct Node));
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
		printf("\nδ�ҵ�������\n");
		return;
	}
}
struct Node* GetByData(int iValue)
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
struct Node* GetByIndex(int Index)
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
void DeleteNode(struct Node* pTemp)
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
			free(pTemp);
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
			free(PT);
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
		free(PT);
	}
	//�м�ɾ��
	else
	{
		//�ı��λ��ǰһλ�ڵ�ָ��
		pTemp->m_pPre->m_pNext = pTemp->m_pNext;
		//�ı��λ�ú�һλ�ڵ�ָ��
		pTemp->m_pNext->m_pPre = pTemp->m_pPre;
		//�ͷŸýڵ�
		free(pTemp);

		////����-1
		//g_iNodeCount--;	//�����������ж϶��������ⲽ���������Ƿŵ�����һ��ִ��
	}
	//����-1
	g_iNodeCount--;
}
void DeleteByIndex(int Index)
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
void DeleteByData(int iValue)
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
void ChangeByData(int iValue, int ipData)
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
void ChangeByIndex(int Index, int ipData)
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
void FreeList()
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
		free(pT);
	}
	g_pHead = NULL;
	g_pEnd = NULL;
	g_iNodeCount = 0;
}
void ShowZheng()
{
	//�����Ϸ��Լ��
	if (&g_pHead == NULL || &g_pEnd == NULL || g_iNodeCount < 0)
		return;

	//��ӡ��ʾ
	printf("\n�ڵ���:%2d  ����Ϊ: ", g_iNodeCount);
	//ѭ������
	struct Node* pTemp = g_pHead;
	while (pTemp != NULL)
	{
		printf(" %3d", pTemp->m_iData);
		pTemp = pTemp->m_pNext;
	}
	putchar('\n');
}
void ShowFan()
{
	//�����Ϸ��Լ��
	if (&g_pHead == NULL || &g_pEnd == NULL || g_iNodeCount < 0)
		return;

	//��ӡ��ʾ
	printf("\n�ڵ���:%2d  ����Ϊ: ", g_iNodeCount);
	//ѭ������
	struct Node* pTemp = g_pEnd;
	while (pTemp != NULL)
	{
		printf(" %3d", pTemp->m_iData);
		pTemp = pTemp->m_pPre;
	}
	putchar('\n');
}
