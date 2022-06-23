#include <stdio.h>
#include <stdlib.h>		//system��ͷ�ļ�
#include <stdbool.h>
#include <malloc.h>

//��
#define Num 10

struct Node
{
	int arr[Num];		//����װ����
	int iCount;			//������ջװ�˶���Ԫ��
};

//����ջ�����飩
struct Node* Stack();
//ѹջ�����Ԫ�أ�
void Push(struct Node* pStack, int IData);
//�ж�ջ�Ƿ���Ԫ��
bool IsEmpty(struct Node* pStack);
//�ͷ�ջ
void FreeStack(struct Node** pStack);
//��ȡջ������ɾ��
int Top(struct Node* pStack);
//ɾ��ջ��
void Pop(struct Node* pStack);


int main(void)
{
	//����ջ
	struct Node* ST = Stack();
	//�ж�ջ�Ƿ���Ԫ��
	bool b = IsEmpty(ST);
	//ѹջ
	int arr[5] = { 5, 6, 8, 3, 1 };
	Push(ST, arr[0]);
	Push(ST, arr[1]);
	Push(ST, arr[2]);
	Push(ST, arr[3]);
	Push(ST, arr[4]);

	//�ж�ջ�Ƿ���Ԫ��
	b = IsEmpty(ST);
	//��ջ
	arr[0] = Top(ST);
	Pop(ST);
	arr[1] = Top(ST);
	Pop(ST);
	arr[2] = Top(ST);
	Pop(ST);
	arr[3] = Top(ST);
	Pop(ST);
	arr[4] = Top(ST);
	Pop(ST);

	//�ж�ջ�Ƿ���Ԫ��
	b = IsEmpty(ST);
	//�ͷ�ջ
	FreeStack(&ST);


	system("pause>0");
	return 0;
}


struct Node* Stack()
{
	//����ջ�ռ�
	struct Node* pTemp = (struct Node*)malloc(sizeof(struct Node));
	if (pTemp == NULL)
		return NULL;
	//������0��ʼ������Ͳ��ó�ʼ���ˣ�
	pTemp->iCount = 0;
	//����ջ�ռ��ַ
	return pTemp;
}
void Push(struct Node* pStack, int IData)
{
	//�����Ϸ��Լ��
	if (&pStack == NULL || pStack == NULL)
		return;
	//���Ԫ��,��ʱ�������±���
	pStack->arr[pStack->iCount] = IData;
	//����+1
	pStack->iCount += 1;
}
bool IsEmpty(struct Node* pStack)
{
	//�����Ϸ��Լ��
	if (&pStack == NULL || pStack == NULL)
		return false;
	//�ж��Ƿ���Ԫ��
	if (pStack->iCount == 0 || pStack == NULL)
		return false;
	else
		return true;
}
void FreeStack(struct Node** pStack)
{
	//�����Ϸ��Լ��
	if (pStack == NULL)
		return;
	//ֱ���ͷ�ջ//����*pStackΪNULLҲ���ͷ�
	free(*pStack);
	//��ֵNULL
	*pStack = NULL;
}
int Top(struct Node* pStack)
{
	//�����Ϸ��Լ��
	if (&pStack == NULL || pStack == NULL || pStack->iCount == 0)
		return 0;
	//��������//iCount�Ǽ������±�ȼ�����1
	return pStack->arr[pStack->iCount - 1];
}
void Pop(struct Node* pStack)
{
	//�����Ϸ��Լ��
	if (&pStack == NULL || pStack == NULL || pStack->iCount == 0)
		return;
	//ջ����Ϊ�����飬�ʲ��øı����ݣ����������ɣ����þ͸��ǵ�����
	//���û��Ԫ��
	if (IsEmpty(pStack) == 0)
		return;
	//�����Ԫ�أ�����-1
	pStack->iCount -= 1;
}

