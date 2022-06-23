#include "dl.h"

//���캯��
List::List()
{
	pHead = NULL;
	pEnd = NULL;
	iCount = 0;
}

//��������
List::~List()
{
	FreeListNULL();
}	 

//*����β���
void List::AddToEnd( int pData)
{	//�˴��ö���ָ���ԭ����̽�����ƺ���Ϊ����*�������ٿ�ԭ�ռ䣬��һ��ָ��Ͳ��ܲٿأ����Ǿֲ��������޷��ı�ԭ�ռ�����
	//����ָ�룬��Ϊ��Ҫ��pHead������в�����Ҳ�ܲ���pHeadָ��Ŀռ�
	//����ռ�
	struct Node* pTemp = new Node;

	//����ռ���ܻ�ʧ�ܣ�Ҫ���п�ָ���ж�
	if (pTemp)
	{
		//�ռ丳ֵ
		pTemp->iData = pData;
		pTemp->iNext = NULL;		//һ��Ҫ��NULL����Ϊ����β�ڵ��iNext������NULL��ԭ���뿴α����Ŀμ��ʼ�

		//���ӽڵ�
		if (pHead == NULL)			//��pHead��pEnd���ⲿ�ģ�����NULLʱ��˵����û���κνڵ㣬��һ����ΪNULLʱ��������ΪNULL��
		{							//����pHead��pEnd��һ���жϼ��ɣ�����д�ɣ�*pHead == NULL || *pEnd == NULL��
			pHead = pTemp;			//�ڵ㸳ֵ
			//*pEnd  = pTemp;
		}
		else
		{
			pEnd->iNext = pTemp;	//ԭβ�ڵ��¼�½ڵ��ַ
			//*pEnd = pTemp;
		}
		pEnd = pTemp;				//pEnd��¼�¼ӽڵ��ָ�룬�����ǿռ串�ǣ���pEndָ��������Ǽ�¼β�ڵ�ĵ�ַ�����Ч�ʣ�pEnd�ǽṹ��ָ�룬pTempҲ�ǽṹ��ָ�룬
	}							//�ṹ����Ҫ���ǣ�����Ҫ��=����������ز��У����Բ��ص��ĸ������⡣���ܸ��������ָ��ӣ���ǰ����Ϊ����ֵ���ǡ�
}

//������Ҫ������ β��ӵĶ���ָ��ʹ�ý��
void  List::ceshi(int b)
{	//ע�⺯�����β��Ǿֲ����������ⲿ�Ĳ���ͬ1��
	//����β��ӶԶ���ָ���ʹ�ã���Ϊ����* �������ٿش����������ݱ���һ��ָ��Ͳ��ܶԴ������ı�����в���
	b = 13;
}

//������Ҫ��pEND������(�˺�����ʾû��pEnd�����)
void  List::AddToEndNopEnd(int pData)
{
	//�����ڵ�
	struct Node* pTemp = new Node;

	//��ָ����
	if (pTemp != NULL)
	{
		//�ڵ㸳ֵ
		pTemp->iData = pData;
		pTemp->iNext = NULL;

		//�ڵ���������
		if (pHead == NULL)			//û�нڵ�ʱ��*pHead == NULL
			pHead = pTemp;
		else
		{
			struct Node* pt = pHead;//����ʱ��������¼�ڵ�ͷָ�룬ԭ��������ֱ���ýڵ�ͷ�Ļ��������*pHead��¼�ĵ�ַ�ͻز���ԭ��λ�ã��Ͷ�ʧ�ˣ����ٴ���ڵ�ͷ

			while (pt->iNext != NULL)//�����ַ�ʽ��Ѱ�ҵ�β�ڵ��λ�ã�������ڵ���һ�࣬ѭ������Ҳ��Խ��Խ�࣬ÿ����ӽڵ㶼Ҫѭ��һ��
				pt = pt->iNext;		//һ�Աȣ���pEnd�ĺô����Ǳ�����ѭ��Ѱ��β�ڵ�λ�ã�ֱ����ָ��pEnd��¼��ǰβ�ڵ��ַ���Ͳ���Ѱ�ң�ֱ��֪��λ�ã������Ч��

			pt->iNext = pTemp;		//�����¼ӽڵ�
		}
	}


}

//*����ͷ���
void  List::AddToHead( int pData)
{	//��β��ӶԱȷ��֣�����ԭ��һ��
	//�����ڵ�
	struct Node* pTemp = new Node;
	
	if (pTemp != NULL)
	{
		//�ڵ㸳ֵ
		pTemp->iData = pData;
		pTemp->iNext = NULL;

		//�ڵ����ӵ�����
		if (pHead == NULL)			//����û�нڵ�ʱ
		{
			//pHead	= pTemp;	//�������������Ҫ����¼ͷ�ڵ��ַ��ָ��pHead��¼�½ڵ��ַ�����Կ���д��{}���棬��ʡ����
			pEnd = pTemp;
		}
		else						//�����нڵ�ʱ
		{
			pTemp->iNext = pHead;	//�½ڵ��iNext��¼ԭͷ�ڵ��ַ
			//pHead	= pTemp;
		}
		pHead = pTemp;				//ָ��pHead��¼�µ�ͷ�ڵ�ĵ�ַ
	}
}

//*����ָ��λ�ý���ڵ�
void  List::InsertNodeByIndex( int pIndex, int pData)
{
	//�����Ϸ��Լ��
	if (pIndex < 0)		//û���ж�pHead�Ƿ�ΪNULL��ԭ���ǣ�����ΪNULL��û�нڵ㣬���Ǹ���ӽڵ㺯����û�нڵ�ҲҪ	�����ȥ
	{
		cout << "\n�����±������Ч������������\n";
		return;
	}

	//����±�Ϊ0����ͷ���
	if (pIndex == 0)
	{
		AddToHead( pData);
	}						//��ǰ����û�нڵ㣬��Ὣ�ýڵ���ӽ�ȥ��д��AddToHead�����
	else
	{
		//��λ��
		struct Node* pt = FindIndex( pIndex - 1);
		if (pt != NULL)						//����a c�ڵ㣬bҪȡ��c��λ�ã��±꣩������Ҫ����a��λ�ã���pIndex - 1
		{
			//�����ڵ�
			struct Node* pTemp = new Node;
			if (pTemp)
			{
				//�ڵ㸳ֵ
				pTemp->iData = pData;
				pTemp->iNext = NULL;

				//���ӽڵ㣬�������
				pTemp->iNext = pt->iNext;		//��a c �ڵ㣬bҪ���뵽c��λ�ã�b�ڵ��ȼ�¼c�ĵ�ַ
				pt->iNext = pTemp;				//Ȼ��a�ٽ���¼�ĵ�ַ�޸�Ϊ��¼b������b��ȡ����cԭ����λ��
			}

		}
		else
			cout << "\n���޴˽ڵ�\n";
	}

}

//*����һ����������Ϊx��N���ڵ�	//���Ը�����Ҫ�ĳ�ͷ��ӡ�β��ӡ�ָ��λ�����
void  List::AddSomeNode( int pCount, int pData)
{
	//��ѭ��������Ӻ�������
	for (int i = 0; i < pCount; i++)	//��ӵĺ������ǲ�����дһ�飬�˷�ʱ�䣬����������Ӻ����ͺ���
	{
		AddToEnd( pData);	//д�ĺ������ܵ�һ������ͨ���Ըߣ������������÷��㣬д��̫���ӾͲ��õ�����
	}
}

//*ɾ��ͷɾ��
void  List::DeleteHead()
{	//���������淶��ÿ����������ĸ��д�����ߵ��ʼ��� _ ����Ȼ��Сд
	//�����Ϸ��Լ��
	if (pHead == NULL)			//������Ϊ��ʱ��û�нڵ㣬��������
		return;
	if (pHead == pEnd)			//������ֻ��һ���ڵ�ʱ
	{							//(*pHead)->iNext == NULL���ж���(*pHead == *pEnd)��һ���ģ�����ʾ����ֻ��һ���ڵ�ʱ
		delete(pHead);
		pHead = NULL;			//������ֻ��һ���ڵ�ʱ�����ռ��ͷţ����ҽ���¼ͷβ��ָ�븳ֵNULL
		pEnd = NULL;			//���򲻸�ֵNULL�Ļ�����¼����ͷβ��ָ�벻֪������ʲô�ˣ�����Ͳ������ˣ���������ӽڵ�ͻ����
	}
	else						//���ж���ڵ�ʱ
	{
		struct Node* pt = pHead;//��¼ԭͷ�ڵ��ַ
		pHead = pt->iNext;		//��ͷָ���¼�µ�ͷ�ڵ�
		delete(pt);				//�ͷ�ԭͷ�ڵ�ռ�
	}

}

//*ɾ��βɾ��
void  List::DeleteEnd()
{
	//�����Ϸ��Լ��
	if (pHead == NULL)
		return;
	//��ֻ��һ���ڵ�ʱ
	if (pHead == pEnd)
	{
		delete(pHead);
		pHead = NULL;
		pEnd = NULL;
	}
	else//���ж���ڵ�ʱ
	{
		struct Node* pt = pHead;	//ʹ����ʱ�������洢��ַ����Ҫֱ����pHead�����ı�pHead�����ݣ��������Ҳ���ͷ�ڵ���
		//Ѱ��β�ڵ��ǰһ��
		while (pt->iNext != pEnd)	//��β�ڵ�ǰһ��ԭ����A C ɾC�����ӣ�Ҫ��pt��¼A��Ȼ���ͷ�C���ٽ�A�ļ�¼��ַ��ֵNULL��pEnd��¼�µ�β�ڵ�A
		{
			pt = pt->iNext;			//����pt = (*pHead)->iNext;	֮ǰ����д���ˣ���Ϊ*pHeadû�䣬��pt��Զ��ѭ����==һ���̶�ֵ����ȥ
		}
		//��ʱpt�ͼ�¼��β�ڵ��ǰһ��
		delete(pEnd);
		pEnd = pt;			//*pEnd��¼��β�ڵ�ĵ�ַ
		pt->iNext = NULL;	//**ע�⣬�µ�β�ڵ�һ��Ҫ��iNext��ֵΪNULL
	}
}

//*ɾ��ɾ��ָ�����ݽڵ�	 (һ��ɾһ��)
struct Node* List::DeleteOneByData( int iData)
{
	//�����Ϸ��Լ��
	if (pHead == NULL)
		return NULL;

	if (pHead->iData == iData)		//�������ݵĽڵ���ͷ�ڵ�ʱ��ͷɾ��
	{
		DeleteHead();				
		return pHead;				//����ֵ��Ϊ�˸�ɾ������ظ��ĺ���ʹ�õ�
	}
	else if (pEnd->iData == iData)	//�������ݵĽڵ���β�ڵ�ʱ��βɾ��
	{
		DeleteEnd();
		return pHead;				//����Ҳ����ͷָ�룬����Ϊ����������Ҫ��ͷ�����ģ���β�ͱ���������
	}
	else							//���������м�ڵ�ʱ
	{
		struct Node* pTemp = pHead;
		//ѭ�����Ҹýڵ��ǰһλ
		while (pTemp->iNext != NULL)
		{
			if (pTemp->iNext->iData == iData)
				break;				//�ҵ���������ǰѭ��
			pTemp = pTemp->iNext;
		}
		if (pTemp->iNext != NULL)
		{								//��ABCDɾB������A��¼��ָ���Ϊ��¼C�ĵ�ַ��Ȼ���ͷ�B������
			struct Node* pt = pTemp->iNext;//��һ����ʱ�����洢�ýڵ㣨B���ĵ�ַ
			pTemp->iNext = pt->iNext;	//Bָ��C�ĵ�ַ���Aָ��C
			delete(pt);					//�ͷ�B�Ŀռ�
			return pTemp;				
										
		}
		else							//pTemp->iNext == NULL ˵������������û�ҵ�
		{
			//cout << "\n���޴˽ڵ�\n";	//һ��ɾ�����DeleteAllByData�����е��ô˺������ض���ִ�д˴�ӡ����ע�͵������������д���
			return NULL;
		}
	}
}

//*ɾ��ɾ��ָ�����ݽڵ�	��һ��ɾ������ظ��ģ�
void  List::DeleteAllByData( int iData)
{
	//�����Ϸ��Լ��
	if (pHead == NULL)
		return;

	//��¼ɾ��ָ���ڵ�DeleteOneByData��������ֵ
	struct Node* pT = DeleteOneByData( iData);
	if(pT == NULL)
		cout << "\n���޴˽ڵ�\n";
						
	//ѭ������ɾ��
	while (pT != NULL)	
	{					
		pT = DeleteOneByData( iData);	
	}					//����ȷ����������pHead�������Ǵ�ͷ��ʼ����ɾ�����˷���Ч��
	
}

//*ɾ�������±�ɾ���ڵ�	 (һ��ɾһ��)
void  List::DeleteDataByIndex( int pIndex)
{
	//�����Ϸ��Լ��
	if (pHead == NULL)
		return;

	//�±�Ϊ0ʱ��ͷɾ��
	if (pIndex == 0)
		DeleteHead();
	else//�±겻Ϊ0
	{

		//���Ҷ�Ӧ�±��ǰһ���ڵ�
		struct Node* pt = FindIndex(pIndex - 1);
		if(pt != NULL)
		{
			//�����Ӧ�±���β�ڵ㣬����Ҫβɾ��
			if (pt->iNext == pEnd)		//��Щ�ٽ�����Ҫ���۾��飬�������ж���ô����
			{
				DeleteEnd();			//��Ϊ������βɾ���Ļ�����¼β�ڵ��ָ��ͻᶪʧ���ǿ�ռ��ͷŵ��ˣ�
				return;
			}
			struct Node* pT = pt->iNext;//ABCɾB����A��ɼ�¼C��ַ��Bԭ�ȼ�¼�����ݣ���Ȼ���ͷ�B
			if (pT != NULL)
			{
				pt->iNext = pT->iNext;
				delete(pT);
			}
			else//��ֻ��1���ڵ��������±�Ϊ1ʱ�Żᴥ������Ϊ�����ǲ���pIndex - 1������һ���ᴥ������
				cout << "\n����ʾ������ֻ��һ���ڵ㣬���±�Ϊ1ʱ���ڣ��±����ֻʣ1���ڵ㣬�±�Ϊ0\n";
		}
		else
			cout << "���޴˽ڵ�\n";	//FindIndex�����о����±��ж���,�������ǲ����±�-1�Ľڵ㣬���ǲ��Ӧ�±�
	}
}

//*�ģ��޸�ָ���ڵ�����	��һ���޸�1����
void  List::ChangeData( int iEesData, int pDesData)
{	//��Ϊ���޸����ݣ�������ָ�뱾�����Դ�һ��ָ��
	struct Node* pes = FindByData( iEesData);	//��һ����ʱ������¼FindByData�ķ���ֵ�����������������Ӱ��Ч��

	if (pes == NULL)				//û�ҵ���Ӧ����
		cout << "\n���޴�����.\n";
	else							//�ҵ���
	{
		pes->iData = pDesData;
	}
}

//*�ģ��޸���ͬ���ݵĽڵ�	��һ���޸Ķ������ʽ1�����Ƽ���������Ч��
void  List::ChangeSomeData( int iEesData, int pDesData)
{
	//�����Ϸ��Լ��
	if (FindByData(iEesData) == NULL)
		cout << "\n���޴˽ڵ�\n";

	struct Node* pTemp = pHead;
	while (pTemp != NULL)
	{
		if (pTemp->iData == iEesData)
			pTemp->iData = pDesData;
		pTemp = pTemp->iNext;
	}
}

//*�ģ��޸���ͬ���ݵĽڵ�	��һ���޸Ķ������ʽ2�����鷳��Щ��Ч�ʵ���һ�㣩
void  List::ChangeSomeData2( int iEesData, int pDesData)
{
	////��һ�β���
	struct Node* pea = FindByData( iEesData);//FindByData���pHead���в����Ϸ��Լ��
	//�����Ϸ��Լ��
	if (pea == NULL)
	{
		cout << "\n���޴˽ڵ�" << endl;
		return;					//û�ҵ���������
	}
	else//��һ���޸�
		pea->iData = pDesData;

	//�ٴβ���
	while (pea != NULL)
	{
		pea = FindByData( iEesData);
		if (pea != NULL)		//��Ϊȫ�������pea == NULL�����Լ�������жϷ�ֹ����NULL->iData�Ĳ���
			pea->iData = pDesData;
	}
}

//�����ͷ�
void  List::FreeList()
{	//ʹ��һ��ָ���ԭ�����ﴫ�ݵ����ⲿ��pHead�����ݣ������Ƕ�������ݽ��в����������Ƕ�pHead������в���
	struct Node* pTemp = pHead;		//���м�����ɴ���������棺//����	C6001	ʹ��δ��ʼ�����ڴ桰* pHead����
									//�����ԭ�������ⲿpHead�������˺Ϸ���ֵ
	while (pTemp != NULL)
	{
		struct Node* pt = pTemp;	//ʹ����ʱ�������洢pHead�仯ǰװ�ĵ�ַ������ֱ���ͷ�pHead�Ļ����Ͳ����ҵ���һ���ڵ��λ����
		pTemp = pTemp->iNext;
		delete(pt);					//�ͷż�¼�ĵ�ַָ��Ŀռ�
	}
}

//*�����ͷ� + ��¼ͷβ��ָ�븳ֵNULL
void  List::FreeListNULL()
{	//��ΪҪ���ⲿ��pHead������в�����������Ҫ����ָ�루�ο�β���������ͷţ�
	struct Node* pTempH = pHead;	//Ϊ�˴����棬����о����һ�٣������Ϊʲô�о��棬�߼����ǶԵ�
	//ѭ���ͷŽڵ�
	while (pTempH != NULL)
	{
		struct Node* pt = pTempH;
		pTempH = pTempH->iNext;
		delete(pt);
	}
	//ͷβ��¼ָ�븳ֵNULL
	pHead = NULL;
	pEnd = NULL;
}

//*�飺�����±����ָ���ڵ�
struct Node* List::FindIndex( int pIndex)
{
	int Num = 0;			//��һ�����������Ƚ������±�

	//�����Ϸ��Լ��
	if (pHead == NULL || pIndex < 0)
	{
		cout << "\n����ΪNULL/������Ч\n";
		return NULL;		//����NULL����������
	}

	//�ĳ�C++�Ͳ���ֱ��ʹ��pHead�ˣ���ı����ڳ�ԱpHead�ģ��趨һ����ʱ��������¼�ͺ���
	struct Node* pTemp = pHead;
	//���ҹ���
	while (pTemp != NULL)
	{
		if (Num == pIndex)
			return pTemp;
		Num++;
		pTemp = pTemp->iNext;
	}
	//û�ҵ���ִ������
	cout << "\n�����±곬������Ԫ�ظ���\n";	//û������ѭ�����ҵ���˵���±����������ʾ������NULL
	return NULL;
}

//*�飺�������ݲ���ָ���ڵ�
struct Node* List::FindByData( int pData)
{
	//�����Ϸ��Լ��
	if (pHead == NULL)
		return NULL;

	struct Node* pTemp = pHead;
	//��ʼ����
	while (pTemp != NULL)
	{
		if (pTemp->iData == pData)
			return pTemp;			//�ҵ����ص�ַ����������
		pTemp = pTemp->iNext;
	}
	//û�ҵ�
	return NULL;
}

//*�������ڵ����ݣ��������ݲ��ң����ַ�ʽ
void  List::SwapByData( int pData1, int pData2)
{
	//�����Ϸ��Լ��
	if (pHead == NULL || pHead->iNext == NULL)
		return;//�ֱ�Ϊ������û�нڵ㡢����ֻ��һ���ڵ� �����ܽ��н���

	//����
	struct Node* pT1 = FindByData( pData1);
	struct Node* pT2 = FindByData( pData2);
	//���ظ����ݵĻ����������ǵ�һ�����鵽������

	//�����ڵ㶼�ҵ�ʱ����
	if (pT1 != NULL && pT2 != NULL && pT1 != pT2)//�ų�����ͬ����ֻ�ҵ�һ���ڵ�����
	{
		////����ʽ
		//struct Node p = *pT1;		//���ַ�ʽ���������ڵ��������ݣ�����ָ��
		//*pT1 = *pT2;				//�ͻᵼ�������˳�򱻸��ң��һᶪʧһ��pT1��pT2�Ľڵ�
		//*pT2 = p;					//��ABCDEFG����CE�����������˷���������˳������ABCFG��DE��ʧ���ˣ���Ϊԭ��Dָ��E���޸ĺ�E��ָ��D


		////��ʽ1��
		//int p1 = pT1->iData;		//�������ڵ����ݣ�ע�⣬�����Ա�࣬��Ҫ©����Ӧ��Ա��������ʽ��һ��
		//pT1->iData = pT2->iData;
		//pT2->iData = p1;

		//��ʽ2��
		struct Node p2 = *pT1;		//ע�������Ա�ֽ�����������1�����ԱҲһ����ע��Ҫ�ų���¼��һ�ڵ�ĵ�ַ��Ա
		memcpy(pT1, pT2, 20);		//string.h���������������ͷ�ļ�,���ֽ�����������������ָ��Ļ����͵���������ݳ�Ա���ֽڴ�С
		memcpy(pT2, &p2, 20);		//�ṹ���ֽ��Ų���ʽ�����鿴�ṹ��������
		//�Դ˽ṹ��Ϊ����int��double��shortռ��18���ֽڿռ䣨int����4�ֽڿգ�������short��2�ֽڵĿգ���ָ�����ܹ�20�ֽڵ����ݿռ�
	}
	else if (pT1 == NULL)
		cout << "\n��1������δ�ҵ�\n";
	if (pT2 == NULL)
		cout << "\n��2������δ�ҵ�\n";
	if (pT1 == pT2)
		cout << "\nһ�������ݣ�ֻ��һ���ڵ㣬�޷�����\n";
}

//*�������ڵ����ݣ������±���ң�
void  List::SwapByIndex( int pIndex1, int pIndex2)
{
	//�����Ϸ��Լ��
	if (pHead == NULL || pHead->iNext == NULL || pIndex1 == pIndex2 || pIndex1 < 0 || pIndex2 < 0)
		return;//�ֱ�Ϊ������û�нڵ㡢����ֻ��һ���ڵ㡢���±���ͬ���±�С��0

	//����
	struct Node* pt1 = FindIndex( pIndex1);
	struct Node* pt2 = FindIndex( pIndex2);

	if (pt1 != NULL && pt2 != NULL)
	{
		//��ʽ1��
		int p1 = pt1->iData;
		pt1->iData = pt2->iData;
		pt2->iData = p1;

		////��ʽ2��
		//struct Node p2 = *pt1;
		//memcpy(pt1, pt2, 20);
		//memcpy(pt2, &p2, 20);
	}
	else if (pt1 == NULL)
		cout << "\n��1������δ�ҵ�\n";
	if (pt2 == NULL)
		cout << "\n��2������δ�ҵ�\n";
}

//*����ָ��ָ���鷳��ʽ�Ľ����ڵ㣩
void  List::SwapByChangePoint( int pIndex1, int pIndex2)
{
	//������ѧϰʱ�����������������Щʵ������ķ�ʽ�����㷨����������Ȼ��Ľ���Ȼ��ʹ�á�

	//�����Ϸ��Լ��	���������ǵ�©�����������������BUG�����۾��飩
	if (pHead == NULL || pHead->iNext == NULL || pIndex1 == pIndex2 || pIndex1 < 0 || pIndex2 < 0)
		return;//�ֱ�Ϊ������û�нڵ㡢����ֻ��һ���ڵ㡢���±���ͬ���±�С��0

	//Ҫȷ���±�Ĵ�С��ϵ����Ϊ����ڵ����Ⱥ��ϵ������Ҫ����ָ�룩
	int Mix = pIndex1;
	int Max = pIndex2;
	if (pIndex2 < pIndex1)		//������ȷ��Max > Mix�ˣ��������ʱ���˵��˶�����ȵ����
	{
		Mix = pIndex2;
		Max = pIndex1;
	}
	//ȷ���ڵ��Ⱥ�ĺô����У�
	//��Ϊ ͷ\β �ڵ����Ľڵ㽻��������ģ��� ͷ\β �ڵ㣬��Ϊȷ�����Ⱥ�Ĺ�ϵ��ֻҪ��pMix���ж��Ƿ�Ϊ ͷ\β �ڵ㼴��
	//����Ҫ��else if���ж�Max

	//�����±���ҽڵ�			//��Ϊȷ�����±��С��ϵ������Ҳȷ����������pMix��pMax��ǰ��
	struct Node* pMix = FindIndex( Mix);
	struct Node* pMax = FindIndex( Max);
	//�Ҳ�����Ӧ�ڵ����ֹ����
	if (pMix == NULL || pMax == NULL)
		return;

	//ȷ���ҵ��󣬽���ͷ-β��ͷ-�м䡢β-�м���������ж�	

	//ͷ-β����	��2�������
	if (pMix == pHead && pMax == pEnd)		//ͷ-β��ͷ-�м䡢β-�м䣬��������ǲ�һ���ģ�����Ҫ�����ҳ���
	{
		//1.����ֻ��2���ڵ����
		if (pHead->iNext == pEnd)
		{																	//��AB������������
			//ͷβָ��ת��						
			pEnd->iNext = pHead;										//1.��A->B���B->A
			//���µ�β�ڵ��ַ��Ա��ֵNULL
			pHead->iNext = NULL;											//2.��A�ĵ�ַλ��ֵNULL
			//��¼ͷβ��ַ��ָ�뽻��
			pHead = pEnd;				//��ʱһ���ڵ�ͬʱ��ͷβ��¼ָ���¼	//3.Ȼ��pHead�Ӽ�¼A��ɼ�B����ʱB��pHead��pEndͬʱ��¼
			pEnd = pEnd->iNext;		//��ʱ���ͷβ��¼ָ��Ľ���			//4.����pEnd��Ϊ��¼A
		}
		//2.�����ж���ڵ����
		else
		{
			//����β�ڵ��ǰһ��	//��������Ѿ�ɸѡ��������϶�3���ڵ����ϣ��϶����ҵ�pMaxpre
			struct Node* pMaxpre = FindIndex( Max - 1);
			//ͷβ�ڵ�λ�û���					//������A-B-C-D������
			pEnd->iNext = pHead->iNext;	//���D->B
			pMaxpre->iNext = pHead;			//C->D���C->A
			//���µ�β�ڵ��ַ��Ա��ֵNULL
			pHead->iNext = NULL;				//A�ĵ�ַ��Ա��ֵNULL
			//��¼ͷβ��ַ��ָ�뽻��
			pHead = pEnd;						//pHead�Ӽ�¼A��ɼ�¼D����ʱpEnd��pHead����¼D
			pEnd = pMaxpre->iNext;			//pEnd�Ӽ�¼D����ɼ�¼A���������ͷβ������������D-B-C-A
			//���ﲻ�������ڵ�ʱ�ķ�ʽ�ˣ�һ��Ҫ��pMaxpre->iNext��
			//���Ի�ͼ������⣬(*pEnd)->iNext��(*pHead)->iNext����ʾD����һλ�����ڵ�B��
		}
	}
	//ͷ-�м佻����2�������
	else if (pMix == pHead && pMax != pEnd)
	{
		//1.�����ڵ�����
		if (pMix->iNext == pMax)
		{
			//�ı����ڵ���ָ��			//��A-B-C������
			pMix->iNext = pMax->iNext;	//A->C,A��Ϊָ��C
			pMax->iNext = pMix;			//B->A,B��Ϊָ��A	�����B-A-C
			//�ı�ͷ��¼ָ��
			pHead = pMax;				//pHead��¼��ͷ�ڵ�B
		}
		//2.���ڵ㲻����
		else
		{
			//Ѱ��pMax��ǰһλ�ڵ�
			struct Node* Maxpre = FindIndex( Max - 1);
			//��¼��2���ڵ��ַ			//��������Ӱ�첻��ʹ�÷��㣬�ǵ�ʹ������˼·�����ٷ���
			struct Node* second = pHead->iNext;
			//�ı�ڵ��ָ��				//��A-B-C-D-E������AD����
			pMix->iNext = pMax->iNext;	//A->E
			pMax->iNext = second;		//D->B
			Maxpre->iNext = pMix;		//C->A		��������ΪD-B-C-A-E
			//�ı�ͷ��¼ָ��
			pHead = pMax;
		}
	}
	//β-�м佻����2�������
	else if (pMix != pHead && pMax == pEnd)
	{
		//1.����
		if (pMix->iNext == pMax)
		{
			//�ҵ�pMix��ǰһλ�ڵ�		//��A-B-C����BC������
			struct Node* p = FindIndex( Mix - 1);
			//�ı�ڵ���ָ��		
			p->iNext = pMax;			//A->C
			pMax->iNext = pMix;			//C->B	��ʱ������A-C-B
			//���µ�β�ڵ�iNext��ֵNULL
			pMix->iNext = NULL;
			//�ı�β�ڵ��¼ָ��
			pEnd = pMix;
		}
		else
		{
			//�ֱ��ҵ�pMix��pMax��ǰһλ�ڵ�
			struct Node* pMixpre = FindIndex( Mix - 1);
			struct Node* pMaxpre = FindIndex( Max - 1);
			//�ı�ڵ���ָ��			//��A-B-C-D-E��BE������
			pMixpre->iNext = pMax;		//A->E
			pMax->iNext = pMix->iNext;	//E->C
			pMaxpre->iNext = pMix;		//D->B		���ڵ�����˳��Ϊ��A-E-C-D-B
			//���µ�β�ڵ�iNext��ֵNULL
			pMix->iNext = NULL;
			//�ı�β�ڵ��¼ָ��
			pEnd = pMix;
		}
	}
	//�м�-�м佻����2�������
	else if (pMix != pHead && pMax != pEnd)
	{
		//����
		if (pMix->iNext == pMax)
		{
			//�ֱ��ҵ�pMix��ǰһλ��pMax����һλ�ڵ�
			struct Node* pMixPre = FindIndex( Mix - 1);
			struct Node* pMaxNext = FindIndex( Max + 1);

			//�ı�ڵ��ָ��			//��A-B-C-D����BC������
			pMixPre->iNext = pMax;	//A->C
			pMax->iNext = pMix;		//C->B
			pMix->iNext = pMaxNext;	//B->D		������˳��A-C-B-D
		}
		//������
		else
		{
			//�ҵ�pMixǰ�������ڵ�	//����Щ�ڵ㣬��Ϊ��ʹ�������߼��򵥣����ذ��Դ���죬��һ�²���ʲô��
			struct Node* pMixPre = FindIndex( Mix - 1);
			struct Node* pMixNext = FindIndex( Mix + 1);
			//�ҵ�pMaxǰ�������ڵ�
			struct Node* pMaxPre = FindIndex( Max - 1);
			struct Node* pMaxNext = FindIndex( Max + 1);

			//�ı���ָ��			//��A-B-C-D-E-F����BE������
			pMixPre->iNext = pMax;	//A->E
			pMax->iNext = pMixNext;	//E->C
			pMaxPre->iNext = pMix;	//D->B
			pMix->iNext = pMaxNext;	//B->F		������˳��A-E-C-D-B-F
		}
	}
	//���Ǿ���ָ��ı����룬��ô��ֽ�ϻ������ͷ�������ˣ�ԭ��򵥣�ֻ��д�ɴ����е㸴��
}

//*��ת�������ݷ�ת����ԭ�ط�ת��
void  List::ReverseByData()
{
	//�����Ϸ��Լ��	//pHead == NULL���ж�һ��Ҫд��ǰ�棬��Ϊ���ΪNULL�Ļ�����ȡiNext����Խ�����
	if (pHead == NULL || pHead->iNext == NULL)
		return;//����û�нڵ㡢ֻ��һ���ڵ�

	//�����ڵ�����
	int i = 0; int j = GetListNodeCount() - 1;	//��i j���м俿£
	for (; i < j; i++, j--)		//��A-B-C-D-E����
	{							//A-E���� B-D���� C����������ʵ��������ת
		SwapByIndex( i, j);
	}
}

//*��ת�����ڵ㷭ת����ԭ�ط�ת��
void  List::ReverseByPoint()
{	//ʹ�ö���ָ���ԭ����Ҫ����ָ��ָ����Ҫ�ı�pHead���������
	//�����Ϸ��Լ��
	if (pHead == NULL || pHead->iNext == NULL)
		return;//����û�нڵ㡢ֻ��һ���ڵ�

	int i = 0; int j = GetListNodeCount() - 1;	//�����J�ǵ��±�ʹ�ã�����Ҫ����-1
	for (; i < j; i++, j--)
	{
		SwapByChangePoint( i, j);
	}
}

//*��ת���������ռ䣩���߼����������������ࣩ
void  List::ReverseByHelpSpace()
{	//����ָ�룺Ҫ��pHead������в���
	//�����Ϸ��Լ��
	if (pHead == NULL || pHead->iNext == NULL)
		return;//���ˣ�û�нڵ㡢ֻ��һ���ڵ�

	//��¼ͷָ�룬����ͷָ�붪ʧ			//�߼����̣�
	struct Node* pTemp = pHead;			//1.����������
	//����������							//2.ԭ����˳�򣬽��ڵ�����ͷ��ӵ�������	��ʵ���˷�ת��
	struct Node* pNewpHead = NULL;		//3.�ͷ�ԭ�ռ�
	struct Node* pNewpEnd = NULL;		//4.ͷβ��¼ָ���¼������ͷβ��������ɷ�ת
	//ͷ���������ʱ����
	
	//��������Ľڵ����ݣ���˳��ͷ��ӵ����������������ʵ���˷�ת
	while (pTemp != NULL)
	{
		//AddToHead( pTemp->iData);		//���ڸĳ�C++���ں�����û����ָ�����������ֱ�Ӱ�ͷ��ӵ�ʵ�ִ�������
		//ͷ��ӹ��̣�
		//�����ڵ�
		struct Node* pT = new Node;
		if (pT)
		{
			
			//�ڵ㸳ֵ
			pT->iData = pTemp->iData;
			pT->iNext = NULL;

			//�ڵ����ӵ�����
			if (pNewpHead == NULL)
				pNewpEnd = pT;
			else						
				pT->iNext = pNewpHead;
			pNewpHead = pT;
		}
		//ԭ�������
		pTemp = pTemp->iNext;
	}

	//�ͷ�ԭ�ռ�
	FreeListNULL();

	//��¼ͷβ��ָ�룬��¼�������ͷβ
	pHead = pNewpHead;
	pEnd = pNewpEnd;
}

//����ڵ�������
int  List::GetListNodeCount()
{
	//�����Ϸ��Լ��
	if (pHead == NULL)
		return 0;

	struct Node* pTemp = pHead;
	int Num = 0;
	while (pTemp != NULL)
	{
		Num++;
		pTemp = pTemp->iNext;
	}
	return Num;
}

//������ӡ
void  List::AllShow()
{
	struct Node* pTemp = pHead;		//Ϊ�˲������ڳ�ԱpHead�ı䣬����ʱ������¼ʹ��

	cout << "\n�ڵ��Ԫ������Ϊ��";
	if (pTemp)
	{
		while (pTemp != NULL)
		{
			cout << ' ' << pTemp->iData;
			pTemp = pTemp->iNext;
		}
	}
	else
		cout << " ��ӡ������������";

	cout << '\n';			
}
