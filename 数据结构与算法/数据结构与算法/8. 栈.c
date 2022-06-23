#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>	//C����ʹ��bool������Ҫͷ�ļ�

//ջ����
void AAA()
{
	//ջ��ݹ�
	if (1)
	{
		//ջ����һ�ֶ����Ա�Ĳ����޶�������˵һ�ֲ�����ʽ�����㷨��
		//ֻ�ܶ�ͬһ�˽��в�������ɾ�ȵȣ���������ֻ��ͷλ�ý��в���������ͷβһ�������ֻ��ͬʱ��ͬ�˲���
		//����������������顢����ջ��ݹ��
		//һ��Ĺ��ܣ�����ջ���ж�ջ�Ƿ�Ϊ�ա�����ջ����ɾ��ջ���������ؽڵ㣨��ջ��������Ԫ�أ���ջ��ѹջ�����ͷ�ջ
		//�������Ļ�����������󣬿������һ���������ܣ�����ʦ˵һ�㲻���飩
		//ջ����һ��������װ���Ķ����ŵ����ף�����ֻ�ܴӾ��ڽ����������Ƚ��Ķ���������ܳ�����������һ���ԽУ��Ƚ����
		//ջ�����ã�����ʵ�ֵݹ���߼�
		//�ݹ��ʵ�֣����ǽ�ջ��ջ�Ĺ��̣����ǵݹ�Ĳ�������̫�ࡣ��ͨ��ջʵ�ֵĵݹ��߼������ٲ㶼����
		
		
		//�������Գ������������ı�������ȱ�������ȱ����ȣ����ǿ�ջ��ʵ�ֵ�
	
	}

}

struct Node
{
	int a;
	struct Node* pNext;
	struct Node* pPre;
};

//ջ�Ĵ���������һ����ͷ������ʱ����˫��ѭ������
struct Node* Stack();
//ѹջ��β��ӣ�(�ɸĳ�ͷ���ͷɾ������֮Ҫ��ͬһ��������в���)
void Push(struct Node* StHead, int iData);
//�ж�ջ����û��Ԫ��
bool IsEmpty(struct Node* StHead);
//�ͷ�ջ
void FreeStack(struct Node** StHead);
//��ȡջ����ɾ��
struct Node* Top(struct Node* StHead);
//ջ����ɾ��
void Pop(struct Node* StHead);

int main(void)
{
	//��ͷ
	struct Node* stHead = Stack();
	//�ж�ջ����û��Ԫ��
	bool b = IsEmpty(stHead);
	//ѹջ(��ջ)
	Push(stHead, 1);
	Push(stHead, 2);
	Push(stHead, 3);
	Push(stHead, 4);
	Push(stHead, 5);
	//�ж�ջ����û��Ԫ��
	b = IsEmpty(stHead);
	//�ͷ�ջ
	FreeStack(&stHead);


	//��ͷ
	struct Node* Head = Stack();
	//�ж�ջ����û��Ԫ��
	bool a = IsEmpty(Head);
	//ѹջ(��ջ)//������ʱΪ��12345
	int arr[5] = { 1, 2, 3, 4, 5 };
	Push(Head, arr[0]);
	Push(Head, arr[1]);
	Push(Head, arr[2]);
	Push(Head, arr[3]);
	Push(Head, arr[4]);
	//�ж�ջ����û��Ԫ��
	a = IsEmpty(Head);

	//��ջ(��ջ��ȡԪ��)//ȡ����ʱ��54321����ѭ�Ƚ������ԭ����ֻ����ͬһ�����
	arr[0] = Top(Head)->a;
	Pop(Head);
	arr[1] = Top(Head)->a;
	Pop(Head);
	arr[2] = Top(Head)->a;
	Pop(Head);
	arr[3] = Top(Head)->a;
	Pop(Head);
	arr[4] = Top(Head)->a;
	Pop(Head);
	//�ж�ջ����û��Ԫ��
	a = IsEmpty(Head);
	//�ͷ�ջ
	FreeStack(&Head);
	


	system("pause>0");
	return 0;
}


struct Node* Stack()
{
	//����ڵ�
	struct Node* pTemp = (struct Node*)malloc(sizeof(struct Node));
	if (pTemp == NULL)
		return NULL;
	//�ڵ��ʼ����ע������˫��ѭ�������ͷ�ĳ�ʼ����
	pTemp->a = 0;
	pTemp->pNext = pTemp;
	pTemp->pPre = pTemp;
	//���ظÿ�ͷ��ַ
	return pTemp;
}
void Push(struct Node* StHead, int iData)
{
	//�����Ϸ��Լ��
	if (&StHead == NULL || StHead == NULL)
		return;
	//�����½ڵ�
	struct Node* pTemp = (struct Node*)malloc(sizeof(struct Node));
	if (pTemp == NULL)
		return;
	//�ڵ㸳ֵ
	pTemp->a = iData;
	pTemp->pNext = NULL;
	pTemp->pPre = NULL;
	//���ڵ���뵽β�ڵ��
	//�½ڵ�����β�ڵ㡢ͷ�ڵ�����
	pTemp->pNext = StHead;
	pTemp->pPre = StHead->pPre;
	//ԭβ�ڵ���ͷ�ڵ�֮��Ͽ�
	StHead->pPre->pNext = pTemp;
	StHead->pPre = pTemp;
}
bool IsEmpty(struct Node* StHead)
{
	//�����Ϸ��Լ��
	if (&StHead == NULL || StHead == NULL)
		return false;
	//�ж��Ƿ���Ԫ�أ�����ͷ�⣩
	if (StHead->pNext == StHead)
		return false;
	else
		return true;
}
void FreeStack(struct Node** StHead)
{
	//�����Ϸ��Լ��
	if (StHead == NULL || *StHead == NULL)
		return;
	//�ӿ�ͷ��ʼ�ͷ�
	struct Node* pTemp = *StHead;
	//��ΪҪ��ͷ�ͷţ�������do while ��ִ��һ�����жϣ������һ�ξ�ֱ������ѭ����
	do
	{
		//��¼��ǰ�ڵ��ַ
		struct Node* pT = pTemp;
		//ָ�����±���
		pTemp = pTemp->pNext;
		//�ͷż�¼�Ľڵ�
		free(pT);
	} while (pTemp != *StHead);

	//�ͷ��꣬��ͷ��ַ����
	*StHead = NULL;
}
struct Node* Top(struct Node* StHead)
{
	//�����Ϸ��Լ��
	if (&StHead == NULL || StHead == NULL)
		return NULL;
	//���������û��Ԫ��
	if (IsEmpty(StHead) == 0)
		return NULL;
	//��Ԫ�أ�����β�ڵ�
	else
		return StHead->pPre;
}
void Pop(struct Node* StHead)
{
	//�����Ϸ��Լ��
	if (&StHead == NULL || StHead == NULL)
		return;
	//������û��Ԫ��
	if (IsEmpty(StHead) == 0)
		return;
	//��Ԫ��
	else
	{
		//��¼β�ڵ�
		struct Node* pTemp = StHead->pPre;
		//���ýڵ�������϶�����
		pTemp->pPre->pNext = StHead;
		StHead->pPre = pTemp->pPre;
		//�ͷŸýڵ�
		free(pTemp);
	}
}
