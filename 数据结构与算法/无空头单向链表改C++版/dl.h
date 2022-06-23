#pragma once	//��ֹͷ�ļ��ظ�������Ҳ������endif���ַ�ʽ��
#include <iostream>
using namespace std;

//һ����������п����ж����Ŀ �һ��������->�����Ŀ
//�Ը���Ŀ�һ� �ܹ�����-����-��Ϊ������

//��Ϊ��C��C++�棬�����ע���Ҿ�ɾ���ˣ����鿴C���ע��

struct Node
{
public:
	int iData;
	double b;
	short c;
	struct Node* iNext;
};

class List
{
//private:
public:
	int iCount;
	struct Node* pHead;
	struct Node* pEnd;

private:
	void FreeList();				//�����ͷ�
	void FreeListNULL();			//�����ͷ� + ��¼ͷβ��ָ�븳ֵNULL

public:
	List();
	~List();

public:
	void AddToEnd(int pData);		//*����β���
	void ceshi(int b);				//������Ҫ������ β��ӵĶ���ָ��ʹ�ý��
	void AddToEndNopEnd( int pData);//������Ҫ��pEND������(�˺�����ʾû��pEnd�����)
	void AddToHead( int pData);		//*����ͷ���
	void InsertNodeByIndex( int pIndex, int pData);	//*����ָ��λ�ý���ڵ�
	void AddSomeNode( int pCount, int pData);		//*����һ����������Ϊx��N���ڵ�
	void DeleteHead();				//*ɾ��ͷɾ��
	void DeleteEnd();				//*ɾ��βɾ��
	struct Node* DeleteOneByData( int iData);		//*ɾ��ɾ��ָ�����ݽڵ�	 (һ��ɾһ��)
	void DeleteAllByData( int iData);				//*ɾ��ɾ��ָ�����ݽڵ�	��һ��ɾ������ظ��ģ�
	void DeleteDataByIndex( int pIndex);			//*ɾ�������±�ɾ���ڵ�	 (һ��ɾһ��)
	void ChangeData(int iEesData, int pDesData);	//*�ģ��޸�ָ���ڵ�����	��һ���޸�1����
	void ChangeSomeData( int iEesData, int pDesData);//*�ģ��޸���ͬ���ݵĽڵ�	��һ���޸Ķ������ʽ1�����Ƽ���
	void ChangeSomeData2( int iEesData, int pDesData);//�ģ��޸���ͬ���ݵĽڵ�	��һ���޸Ķ������ʽ2�����鷳��Щ��
	struct Node* FindIndex( int pIndex);			//*�飺�����±����ָ���ڵ�
	struct Node* FindByData( int pData);			//*�飺�������ݲ���ָ���ڵ�
	void SwapByData( int pData1, int pData2);		//*�������ڵ����ݣ��������ݲ��ң����ַ�ʽ
	void SwapByIndex( int pIndex1, int pIndex2);	//*�������ڵ����ݣ������±���ң����ַ�ʽ
	void SwapByChangePoint( int pIndex1, int pIndex2);//*����ָ��ָ���鷳��ʽ�Ľ����ڵ㣩
	void ReverseByData();			//*��ת�������ݷ�ת��
	void ReverseByPoint();			//*��ת�����ڵ㷭ת��
	void ReverseByHelpSpace();		//*��ת���������ռ䣩
	int GetListNodeCount();			//����ڵ�������
	void AllShow();					//������ӡ
};

