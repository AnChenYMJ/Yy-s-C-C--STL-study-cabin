#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>	//bool��ͷ�ļ�����ʦ˵C++��Cʶ��󲼶���С����������

//���ĸ����Լ��жϷ���
void AAA()
{
	if (1 == 1)
	{
		//������A-B-C-D-E-F-G-H-I��������������
		//Iԭ����һλ��NULL�����򣩻���A��˫��
		//�����ΪһЩԭ��Iָ���������������ڵ㣬����D
		//�������򣩾ͳ���A-B-C-D-E-F-G-H-I -D-E-F-G-H-I -D-E....
		//��ͼ����������һ��6��

		//�����⣺��ô�ж�һ���������Ƿ��л�
		//�жϷ�ʽ��ʹ�ÿ���ָ�����ж������Ƿ��л�
		//����ָ�룺����ָ�룬һ��һ���ߺü����ڵ㣨�죩����һ��һ��1���ڵ㣨����
		//��������������ʱ����ٳ�һ�㣬���ΧȦ��׷�������ˣ���֤���л��Ĵ���
	}

}

struct Node
{
	int iData;
	struct Node* pNext;
	struct Node* pPre;
};

//β���
void AddToEnd(struct Node* stHead, int* ICount, int IData)
{
	//�����Ϸ��Լ��
	if (&stHead == NULL || stHead == NULL || *ICount < 0)
		return;
	//�����½ڵ�
	struct Node* pTemp = (struct Node*)malloc(sizeof(struct Node));
	if (pTemp == NULL)
		return;
	//�ڵ㸳ֵ
	pTemp->iData = IData;
	pTemp->pNext = NULL;
	pTemp->pPre = NULL;
	//�½ڵ���ԭβ�ڵ�����
	pTemp->pPre = stHead->pPre;
	stHead->pPre->pNext = pTemp;
	//�½ڵ����ͷ����
	pTemp->pNext = stHead;
	stHead->pPre = pTemp;
	//����+1
	*ICount += 1;
}
//�ͷ�
void FreeList(struct Node* stHead, int* ICount)
{
	//�����Ϸ��Լ��
	if (&stHead == NULL || stHead == NULL || *ICount <= 0)
		return;
	//�ӵ�2�ڵ㿪ʼ
	struct Node* pTemp = stHead->pNext;
	//ѭ���ͷ�
	while (pTemp != stHead)
	{
		//��¼��ǰ�ڵ�
		struct Node* pT = pTemp;
		//������
		pTemp = pTemp->pNext;
		//�ͷ�
		free(pT);
	}
	//��ʼ������
	stHead->pNext = stHead;
	stHead->pPre = stHead;
	//������0
	*ICount = 0;
}
//������ӡ
void AllShow(struct Node* stHead, int ICount)
{
	//�����Ϸ��Լ��
	if (&stHead == NULL || stHead == NULL || ICount < 0)
		return;

	//�ӵ�2��㿪ʼ
	struct Node* pTemp = stHead->pNext;
	printf("\n�ڵ���: %3d  ����Ϊ:", ICount);
	//ѭ������
	while (pTemp != stHead)
	{
		printf(" %2d", pTemp->iData);
		pTemp = pTemp->pNext;
	}
	putchar('\n');
}
//����ָ���ж��Ƿ�ɻ�
bool QuikSlow(struct Node* stHead)
{
	//�����Ϸ��Լ��
	if (&stHead == NULL || stHead == NULL)
		return false;
	//��������ָ��
	struct Node* Quik = stHead->pNext;		//��ָ��
	struct Node* Slow = stHead->pNext;		//��ָ��
	//ѭ��������ָ���������
	while (Quik != NULL && Quik->pNext != NULL)
	{//ע���2���ж��������Ƿ�ֹQuikԽ�������Ҳע���жϵ�˳��
		//��ָ�����
		Quik = Quik->pNext->pNext;
		Slow = Slow->pNext;
		//����ָ��������֤ʵ���Ĵ���
		if (Quik == Slow)
			return true;
	}
	return false;
}

int main(void)
{
	//��ͷ
	struct Node stHead;
	stHead.pNext = &stHead;
	stHead.pPre = &stHead;
	stHead.iData = 0;
	//����
	int iCount = 0;

	AddToEnd(&stHead, &iCount, 1);
	AddToEnd(&stHead, &iCount, 2);
	AddToEnd(&stHead, &iCount, 3);
	AddToEnd(&stHead, &iCount, 4);
	AddToEnd(&stHead, &iCount, 5);
	AddToEnd(&stHead, &iCount, 6);

	AllShow(&stHead, iCount);

	/*FreeList(&stHead, &iCount);
	AllShow(&stHead, iCount);*/

	//ʹ˫��ѭ������Ͽ��ɲ�ѭ���ģ�Ϊ�������ָ���ж���׼��(��Ϊѭ������һ����)
	struct Node* pEnd = stHead.pPre;
	pEnd->pNext = NULL;
	stHead.pPre = NULL;

	//�ֶ��γɻ�������Ļ���
	//pEnd->pNext = stHead.pNext->pNext->pNext;

	//����ָ���ж��Ƿ�ɻ��������޸Ļ���Ӻ����ɷ��������⣩
	bool b = QuikSlow(&stHead);

	//�ж���֮������������ѭ����
	pEnd->pNext = &stHead;
	stHead.pPre = pEnd;
	pEnd = NULL;

	AllShow(&stHead, iCount);


	system("pause>0");
	return 0;
}