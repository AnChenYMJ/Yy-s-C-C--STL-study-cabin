#include "YK.h"

YK::YK()
{
	stHead.iData = 0;
	stHead.iNext = NULL;
}
YK::~YK()
{
	FreeList();
}

//����β���
void YK::AddToTail( int pData)
{	//�Ա��޿�ͷ������������ӳ��
	//�����Ϸ��Լ��	
	if (stHead.iData < 0)
		return;	//ע��˳��iNodeCount == NULL��ǰ������ΪNULLʱ�����˴�С�жϣ����³������

	//�����½ڵ�
	struct Node* pTemp = new Node;
	//�ڵ㸳ֵ
	if (pTemp == NULL)			//�˴�����NULL��������һ�ַ�ʽ����鿴�޿�ͷ������������
		return;
	pTemp->iData = pData;
	pTemp->iNext = NULL;
	//�ҵ�β�ڵ��ַ
	struct Node* pt = &stHead;	//ʹ����ʱ����pt����ͷָ�붪ʧ
	while (pt->iNext != NULL)
		pt = pt->iNext;
	//�½ڵ�ӵ�β�ڵ���
	pt->iNext = pTemp;
	//��������++
	stHead.iData++;
}
//����ͷ���
void YK::AddToHead(int pData)
{
	//�����½ڵ�
	struct Node* pTemp = new Node;
	if (pTemp == NULL)
		return;
	//�ڵ㸳ֵ
	pTemp->iData = pData;
	pTemp->iNext = NULL;			//��Ϊ���������pTemp->iNext���в�����������һ�������б�Ҫ�ģ�Ϊ�˱�֤�Ͻ���
	//�ڵ����ӵ���ͷ���棬ԭ��2�ڵ�ǰ��
	struct Node* pt = stHead.iNext;//�����ʱ���������������������ָ����л���Ҫ����˳��
	pTemp->iNext = pt;
	stHead.iNext = pTemp;			//��ͼ��⣬һĿ��Ȼ
	//��������
	stHead.iData += 1;
}
//����ָ�����ݺ���ӣ������ݲ��ҡ�1�μ�1����
void YK::AddBeHandData(int iPosData, int pData)
{
	//�����Ϸ��Լ��
	if (stHead.iData <= 0)
		return;//���˿�ָ�롢����û�нڵ㣨����ͷ��

	//�ӵ�2�ڵ㿪ʼ���Ҷ�Ӧ�ڵ�
	struct Node* pTemp = stHead.iNext;

	while (pTemp != NULL)
	{
		if (pTemp->iData == iPosData)	//*ע�⣺�Ҿ��������ж�����У�== д���� = 
			break;
		pTemp = pTemp->iNext;
	}
	//�ж��Ƿ��ҵ�
	if (pTemp == NULL)	//δ�ҵ�
	{
		cout << "\nδ�ҵ���Ӧ���ݵĽڵ�\n";
		return;
	}
	else				//�ҵ�
	{
		//�����½ڵ�
		struct Node* pT = new Node;
		if (pT == NULL)
			return;
		//�ڵ㸳ֵ
		pT->iData = pData;
		pT->iNext = NULL;
		//�½ڵ����ӵ��鵽�Ľڵ����
		struct Node* pA = pTemp->iNext;
		pT->iNext = pA;
		pTemp->iNext = pT;
		//����+1
		stHead.iData += 1;
	}
}
//����ָ���±�λ����ӽڵ�(1��)
void YK::AddByIndex(int iPosIndex, int pData)
{
	//�����Ϸ��Լ��
	if (iPosIndex > stHead.iData || iPosIndex < 0)
		return;//��1���жϣ��±�Ϊ�ܽڵ���-1�������ݸ���Ҳ���ܽڵ���-1����ΪҪ������ͷ���ʶ�����ֵ��ȣ����������±겻��Խ��������ж�

	//Ѱ���±�λ��
	struct Node* pTemp = &stHead;
	for (int i = 0; i < iPosIndex; i++)
		pTemp = pTemp->iNext;
	//�ҵ����ڸ��±����ӽڵ�	//�ڰ�����ͷ���±꿴��������������±�ڵ����ӽڵ�
	//�����½ڵ�
	struct Node* pT = new Node;
	if (pT == NULL)
		return;
	//�ڵ㸳ֵ
	pT->iData = pData;
	pT->iNext = NULL;		
	//�½ڵ����ӵ��鵽�Ľڵ����
	struct Node* pt = pTemp->iNext;
	pT->iNext = pt;
	pTemp->iNext = pT;			
	//����+1
	stHead.iData += 1;
}
//����ָ���±�λ����ӽڵ�(N��)
void YK::AddByIndex(int iPosIndex, int pCount, int pData)
{
	//�����Ϸ��Լ��
	if (iPosIndex > stHead.iData || iPosIndex < 0)
		return;
	//���ҽڵ�
	struct Node* pTemp = &stHead;
	for (int i = 0; i < iPosIndex; i++)
		pTemp = pTemp->iNext;
	//����ѭ���ڸ�λ�����N���ڵ�
	for (int j = 0; j < pCount; j++)	//�����⼸���߽�ֵ�жϲ������������������ʱ����ֽ�ϻ�ͼд��������⣬����ÿ�ζ������
	{									//���һ�Σ�Ȼ��ʹ�þͺ��ˡ���ҪҪ�ǲ����������߼���
		//��ӽڵ�
		//�����½ڵ�
		struct Node* pT = new Node;
		if (pT == NULL)
			return;
		//�ڵ㸳ֵ
		pT->iData = pData;
		pT->iNext = NULL;			
		//�½ڵ����ӵ��鵽�Ľڵ����
		struct Node* pt = pTemp->iNext;
		pT->iNext = pt;
		pTemp->iNext = pT;			
		//��������
		stHead.iData += 1;
	}
}
//ɾ��ɾ��ָ���±�ڵ�
void YK::DeleteByIndex(int pIndex)
{
	//�����Ϸ��Լ��
	if (pIndex < 0 || pIndex > stHead.iData - 1)
		return;

	//��Ϊ��Ҫ�±��ǰһλ������Ҫ�õ���ͷ�����Դӿ�ͷ��ʼ
	struct Node* pTemp = &stHead;
	if (pTemp == NULL)
		return;
	//���Ҷ�Ӧ�±��ǰһ�ڵ�
	for (int i = 0; i < pIndex; i++)
		pTemp = pTemp->iNext;

	//��ʱ pTemp �Ƕ�Ӧ�±��ǰһ�ڵ�
	//��¼��Ӧ�±�
	struct Node* pt = pTemp->iNext;	//pt������Ҫ�ͷŵĽڵ�
	//A-B-CɾB����Aָ��C
	pTemp->iNext = pt->iNext;
	//�ͷŸýڵ�
	delete(pt);
	//����-1
	stHead.iData -= 1;
}
//ɾ��ɾ��ָ�����ݽڵ㣨N����
void YK::DeleteAllByData(int pValue)
{
	//�����Ϸ��Լ��
	if (stHead.iData <= 0)
		return;

	//�ӿ�ͷ��ʼ�ң�������Ҫ�ÿ�ͷ����ڵ㣩
	struct Node* pTemp = &stHead;
	//�ҵ���Ӧ�ڵ�ǰһλ
	while (pTemp->iNext != NULL)	//��һ��������ж�д����pTemp != NULL�Ǵ�ģ�����Ҫȷ��Ҫ�����Ľڵ���ڣ�������ǰһλ���ھ���
	{
		if (pTemp->iNext->iData == pValue)
		{
			//��¼��Ӧ�ڵ�
			struct Node* pt = pTemp->iNext;
			//��A-B-CɾB A->C Ȼ���ͷ�B
			pTemp->iNext = pt->iNext;
			delete(pt);
			//����-1
			stHead.iData--;
			//����ѭ����ʼ�����ѭ��
			continue;		//continue������������������ѭ������������δִ�е���䣬����������һ�ε�ѭ�������ж����������Ϊ����������ѭ����
		}
		pTemp = pTemp->iNext;
	}

}
//ɾ��ɾ���ظ������ݣ�ȥ�أ�
void YK::DeleteSame()
{
	//ԭ���ǣ��ӵ�һ����㿪ʼ������ͷ�����������Ľڵ����ݽ��бȽϣ��ظ���ɾ��������Ҫ˫��ѭ��
	//�����Ϸ��Լ��
	if (stHead.iData <= 0)
		return;

	//�ӵڶ����ڵ㿪ʼ������ͷ�ĵ�һ����
	struct Node* pWai = stHead.iNext;
	//��һ��ѭ������������
	while (pWai != NULL)
	{
		//��¼��ǰ�ڵ�
		struct Node* pNei = pWai;
		//�ڶ���ѭ��������pWai->iData��ʣ�µĽڵ�ԱȲ���ɾ��,pNei��������ѭ��
		while (pNei->iNext != NULL)
		{	//ע��˴�pNei->iNext������Ҫ�����Աȣ�ɾ�����Ľڵ㣬�ʲ�ҪpNei != NULL ��������pNei->iNext->iData���������ΪpNei->iNextΪNULL�����û���ж�
			if (pWai->iData == pNei->iNext->iData)
			{
				//��¼��ǰ���鵽�ظ��Ľڵ�
				struct Node* pTemp = pNei->iNext;
				//��A-B-CɾB A->C Aָ��C��Ȼ���ͷ�B
				pNei->iNext = pTemp->iNext;
				//�ͷŽڵ�
				delete(pTemp);
				//����-1
				stHead.iData -= 1;
				//����ѭ����ʼ������ѭ���Ƚ� ����Ҫ�����Ի�ͼ��⣬�����Ǳ�������1���ڵ�ȶԣ������©
				continue;
			}
			pNei = pNei->iNext;

		}
		pWai = pWai->iNext;
	}
}
//���ҽ�㣨�������ݣ����ҵ���һ�����ֵģ�
struct Node* YK::FindNodeByData(int pData)
{
	//�����Ϸ��Լ��
	if (stHead.iData <= 0)
		return NULL;
	//��������
	struct Node* pTemp = &stHead;
	if (pTemp == NULL)
		return NULL;
	while (pTemp != NULL)
	{
		if (pTemp->iData == pData)
			break;		//�ҵ����˳����ص�ַ
		pTemp = pTemp->iNext;
	}
	return pTemp;		//�ҵ����򷵻ص�ַ��û�ҵ��Ļ�pTemp == NULL���򷵻���NULL
}
//���ҽ�㣨�����±꣩
struct Node* YK::FindNodeByIndex(int pIndex)
{
	//�����Ϸ��Լ��
	if (stHead.iData <= 0 || pIndex > stHead.iData - 1 || pIndex < 0)
		return NULL;//�˴���pIndex�Ǵӵ�2��㿪ʼ���±꣨��������ͷ���±꣩
	//�ӵ�2�ڵ㿪ʼ
	struct Node* pTemp = stHead.iNext;
	if (pTemp == NULL)
		return NULL;
	//���Ҹ��±�
	for (int i = 0; i < pIndex; i++)
		pTemp = pTemp->iNext;
	return pTemp;
}
//�޸Ľڵ����ݣ������±꣩
void YK::ChangeByIndex(int pIndex, int pValue)
{	//�˴�û��ָ�룬�൱�ڴ����˸���ʱ����Ȼ��ֵ����
	//�����Ϸ��Լ��
	if (stHead.iData <= 0 || pIndex > stHead.iData - 1 || pIndex < 0)
		return;
	//�ӵ�2�ڵ㿪ʼ����1�ڵ��ǿ�ͷ��
	struct Node* pTemp = stHead.iNext;
	if (pTemp == NULL)
		return;
	//ѭ�����Ӧ����ýڵ�
	for (int i = 0; i < pIndex; i++)
		pTemp = pTemp->iNext;
	//�޸Ľڵ�����
	pTemp->iData = pValue;
}
//�޸Ľڵ����ݣ��������ݣ�
void YK::ChangeByData(int pData, int pValue)
{
	//�����Ϸ��Լ��
	if (stHead.iData <= 0)
		return;
	//�ӵ�2��㿪ʼ����
	struct Node* pTemp = stHead.iNext;
	if (pTemp == NULL)
		return;
	//ѭ�����������޸�
	while (pTemp != NULL)
	{
		if (pTemp->iData == pData)
			pTemp->iData = pValue;
		pTemp = pTemp->iNext;
	}
}
//������ӡ
void YK::AllShow()
{	//��Ϊ���޸��κ����ݣ����Կ����Բ���ָ�룬����൱�ڱ����丳ֵ�ˣ���ע��������ó�Ա�� . ָ����ó�Ա�� ->
	//�����Ϸ��Լ��	
	if (stHead.iData < 0)
		return;

	cout << "\n����ڵ���Ϊ:" << stHead.iData << "  ����Ϊ : ";
	//�ӵ�2���ڵ㿪ʼ
	struct Node* pTemp = stHead.iNext;
	//ѭ����ӡ
	while (pTemp != NULL)
	{
		cout << pTemp->iData << ' ';
		pTemp = pTemp->iNext;
	}
	cout << endl;
}
//�ͷſռ�
void YK::FreeList()
{
	//�����Ϸ��Լ��
	if (stHead.iData == 0 || stHead.iData < 0)
		return;

	//��¼��2���ڵ��ַ
	struct Node* pTemp = stHead.iNext;
	//�ӵ�2���ڵ㿪ʼ�ͷ�
	if (pTemp != NULL)
	{
		while (pTemp != NULL)
		{
			struct Node* pt = pTemp;
			pTemp = pTemp->iNext;
			delete(pt);
		}
		//����ͷ��ΪΨһ�ڵ�	��ע�⣬�����ͷ��ָ��malloc�Ŀռ䣬����Ҫ�ͷſռ䣩
		stHead.iNext = NULL;
		stHead.iData = 0;
	}

}