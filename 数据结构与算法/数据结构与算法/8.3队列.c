#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <stdbool.h>	//boolͷ�ļ�s

//���н���
void AAA()
{
	//����
	if (1)
	{
		//������ջһ�������Ƕ����Ա��һ���޶�����
		//ջ�������ɾ������ջ���ջ����������ͬһ�����
		//���У������ɾ������ջ���ջ����������������

		//�Ƚ��ȳ���������װ�������ݣ��ȳ�����
		//Ӧ�ã�����windows����Ϣ���ƣ����̵�����ȣ��Ƚ�����Ϣ�ȳ�ȥ
		//��ջһ��������������ʵ�֣�����û�б�Ҫ����Ϊ������˲����е��鷳��β��ӣ���Ҫͷɾ������������ǰ�����ռ䲻���ã���ʵ������Ҳ���Բ��鷳����һ��������
		// ���ǵ�������ʵ�ֵĻ���Ч�ʾ͵��ˣ���ΪҪ������β��Ȼ���ٱ������µ�β��
		//���ܣ�Queue���������п�ͷ��IsEmpty���ж��Ƿ�ΪNULL��Push����ӡ�Pop�����ӡ�Front����ͷ�ڵ㡢Back����β�ڵ�
	}
}

//������ʹ��˫��ѭ������ͷ��ӡ�βɾ����
struct Node
{
	int iData;
	struct Node* pNext;
	struct Node* pPre;
};

//�������п�ͷ
struct Node* Queue()
{
	//�����ڵ�
	struct Node* pTemp = (struct Node*)malloc(sizeof(struct Node));
	if (pTemp == NULL)
		return NULL;
	//��ͷ�ڵ��ʼ��
	pTemp->iData = 0;
	pTemp->pNext = pTemp;
	pTemp->pPre = pTemp;
	//���ؿ�ͷ��ַ
	return pTemp;
}
//�ж϶����Ƿ��нڵ�
bool IsEmpty(struct Node* pQueue)
{
	//�����Ϸ��Լ��
	//û�ж���ڵ�
	if (&pQueue == NULL || pQueue == NULL || pQueue->pNext == pQueue)
		return false;
	//�нڵ㣨����ͷ��
	else
		return true;
}
//��ͷ�ڵ㣨�����ȳ��Ľڵ㣬��β�ڵ㣬��Ϊ�Ƚ��ȳ����������ͷ��ӣ���β�͵Ľڵ��ȳ���
struct Node* Front(struct Node* pQueue)
{
	//�����Ϸ��Լ��
	if (IsEmpty(pQueue) == false)
		return NULL;
	else
		return pQueue->pPre;
}
//��β�ڵ㣨���غ���Ľڵ㣬��ͷ�ڵ㣩
struct Node* Back(struct Node* pQueue)
{
	//�����Ϸ��Լ��
	if (IsEmpty(pQueue) == false)
		return NULL;
	else
		return pQueue->pNext;
}
//��ӣ�ͷ��ӣ�
void Push(struct Node* pQueue, int IData)
{
	//�����Ϸ��Լ��
	if (pQueue == NULL || &pQueue == NULL)
		return;
	else
	{
		//�����½ڵ�
		struct Node* pTemp = (struct Node*)malloc(sizeof(struct Node));
		if (pTemp == NULL)
			return;
		//�ڵ㸳ֵ
		pTemp->iData = IData;
		pTemp->pNext = NULL;
		pTemp->pPre = NULL;
		//�½ڵ����ͷ��ͷ�ڵ�����
		pTemp->pPre = pQueue;
		pTemp->pNext = pQueue->pNext;
		//ԭͷ�ڵ����ͷ�Ͽ�
		pQueue->pNext->pPre = pTemp;
		pQueue->pNext = pTemp;
	}
}
//���ӣ�βɾ����
void Pop(struct Node* pQueue)
{
	//�����Ϸ��Լ��
	if (IsEmpty(pQueue) == false)
		return;
	else
	{
		//��¼β�ڵ�
		struct Node* pTemp = pQueue->pPre;
		//��β�ڵ�����������
		pTemp->pPre->pNext = pQueue;
		pQueue->pPre = pTemp->pPre;
		//�ͷ�����������Ľڵ�
		free(pTemp);
	}
}
//�ͷ�
void Free(struct Node** pQueue)
{
	//�����Ϸ��Լ��
	if (IsEmpty(*pQueue) == false)
	{
		free(*pQueue);
		*pQueue = NULL;
		return;
	}
		
	else
	{
		//�ӿ�ͷ��ʼ�ͷ�
		struct Node* pTemp = *pQueue;
		do {
			//��¼��ǰ�ڵ�
			struct Node* pT = pTemp;
			//ָ��������
			pTemp = pTemp->pNext;
			//�ͷŽڵ�
			free(pT);
		} while (pTemp != NULL);
	}
}

int main(void)
{
	//������ͷ
	struct Node* pQueue = Queue();
	//�ж϶����Ƿ��нڵ�
	bool b = IsEmpty(pQueue);
	//��ӣ�ͷ��ӣ�
	int arr[5] = { 9, 7, 5, 3, 1 };
	Push(pQueue, arr[0]);
	Push(pQueue, arr[1]);
	Push(pQueue, arr[2]);
	Push(pQueue, arr[3]);
	Push(pQueue, arr[4]);

	//�ж϶����Ƿ��нڵ�
	b = IsEmpty(pQueue);

	//����
	Pop(pQueue);
	Pop(pQueue);
	Pop(pQueue);
	Pop(pQueue);
	Pop(pQueue);

	//�ͷ�
	Free(&pQueue);

	system("pause>0");
	return 0;
}