#pragma once
#include <iostream>
using namespace std;


struct Node
{	//�����淶��m_p g_p m��My��д�������Ա��g����ȫ�ֱ�����p����ָ������
	int m_iData;			//��¼����
	struct Node* m_pNext;	//��¼��һ�ڵ��ַ
	struct Node* m_pPre;	//��¼��һ�ڵ��ַ
};

class SX
{
private:
public:
	struct Node* g_pHead;	//��¼ͷ�ڵ��ָ��
	struct Node* g_pEnd;	//��¼β�ڵ��ָ��
	int	g_iNodeCount;		//�ڵ����

private:
	//�����ͷ�
	void FreeList();

public:
	SX();
	~SX();

public:
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
	//������ӡ(����)
	void ShowZheng();
	//������ӡ(����)
	void ShowFan();

};