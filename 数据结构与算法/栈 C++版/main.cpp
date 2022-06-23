#include <iostream>
//#include <stdbool.h>	//C����ʹ��bool������Ҫͷ�ļ�

using namespace std;

struct Node
{
	int a;
	struct Node* pNext;
	struct Node* pPre;
};

class ST
{
private:
	struct Node* StHead;

	//ջ�Ĵ���������һ����ͷ������ʱ����˫��ѭ������
	struct Node* Stack();
	//�ͷ�ջ
	void FreeStack();
public:
	ST()
	{
		StHead = Stack();
	}
	~ST()
	{
		FreeStack();
	}
public:
	
	//ѹջ��β��ӣ�
	void Push(int iData);
	//�ж�ջ����û��Ԫ��
	bool IsEmpty();
	//��ȡջ����ɾ��
	struct Node* Top();
	//ջ����ɾ��
	void Pop();
};


int main(void)
{
	ST st;
	//�ж�ջ����û��Ԫ��
	bool a = st.IsEmpty();
	//ѹջ(��ջ)//������ʱΪ��12345
	int arr[5] = { 1, 2, 3, 4, 5 };
	st.Push(arr[0]);
	st.Push(arr[1]);
	st.Push(arr[2]);
	st.Push(arr[3]);
	st.Push(arr[4]);
	//�ж�ջ����û��Ԫ��
	a = st.IsEmpty();

	//��ջ(��ջ��ȡԪ��)//ȡ����ʱ��54321����ѭ�Ƚ������ԭ����ֻ����ͬһ�����
	arr[0] = st.Top()->a;
	st.Pop();
	arr[1] = st.Top()->a;
	st.Pop();
	arr[2] = st.Top()->a;
	st.Pop();
	arr[3] = st.Top()->a;
	st.Pop();
	arr[4] = st.Top()->a;
	st.Pop();
	//�ж�ջ����û��Ԫ��
	a = st.IsEmpty();



	system("pause>0");
	return 0;
}


struct Node* ST::Stack()
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
void ST::Push(int iData)
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
bool ST::IsEmpty()
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
void ST::FreeStack()
{
	//�����Ϸ��Լ��
	if (StHead == NULL || &StHead == NULL)
		return;
	//�ӿ�ͷ��ʼ�ͷ�
	struct Node* pTemp = StHead;
	//��ΪҪ��ͷ�ͷţ�������do while ��ִ��һ�����жϣ������һ�ξ�ֱ������ѭ����
	do
	{
		//��¼��ǰ�ڵ��ַ
		struct Node* pT = pTemp;
		//ָ�����±���
		pTemp = pTemp->pNext;
		//�ͷż�¼�Ľڵ�
		free(pT);
	} while (pTemp != StHead);

	//�ͷ��꣬��ͷ��ַ����
	StHead = NULL;
}
struct Node* ST::Top()
{
	//�����Ϸ��Լ��
	if (&StHead == NULL || StHead == NULL)
		return NULL;
	//���������û��Ԫ��
	if (IsEmpty() == 0)
		return NULL;
	//��Ԫ�أ�����β�ڵ�
	else
		return StHead->pPre;
}
void ST::Pop()
{
	//�����Ϸ��Լ��
	if (&StHead == NULL || StHead == NULL)
		return;
	//������û��Ԫ��
	if (IsEmpty() == 0)
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
