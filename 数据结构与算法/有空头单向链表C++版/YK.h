#pragma once
#include <iostream>
#include <cstdio>

using namespace std;

struct Node
{
	int iData;
	struct Node* iNext;
};


class YK
{
private:
	Node stHead;
	void FreeList();//�ͷſռ�

public:
	YK();	//���캯��
	~YK();	//��������
public:
	
	//����β���
	void AddToTail(int pData);
	//����ͷ���
	void AddToHead(int pData);
	//����ָ�����ݺ���ӣ������ݲ��ҡ�1�μ�1����
	void AddBeHandData(int iPosData, int pData);
	//����ָ���±�λ����ӽڵ�(1��)
	void AddByIndex(int iPosIndex, int pData);
	//����ָ���±�λ����ӽڵ�(N��)
	void AddByIndex(int iPosIndex, int pCount, int pData);
	//ɾ��ɾ��ָ���±�ڵ�
	void DeleteByIndex(int pIndex);
	//ɾ��ɾ��ָ�����ݽڵ㣨N����
	void DeleteAllByData(int pValue);
	//ɾ��ɾ���ظ������ݣ�ȥ�أ�
	void DeleteSame();
	//���ҽ�㣨�������ݣ����ҵ���һ�����ֵģ�
	struct Node* FindNodeByData(int pData);
	//���ҽ�㣨�����±꣩
	struct Node* FindNodeByIndex(int pIndex);
	//�޸Ľڵ����ݣ������±꣩
	void ChangeByIndex(int pIndex, int pValue);
	//�޸Ľڵ����ݣ��������ݣ�
	void ChangeByData(int pData, int pValue);
	//������ӡ
	void AllShow();
	

};
