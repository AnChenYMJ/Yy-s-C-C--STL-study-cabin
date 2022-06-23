#include <stdio.h>
#include <stdlib.h>
#include <string.h>		//memcpy��ͷ�ļ�

//����ĺܶ�˼·������α����ıȼ�¼�ҵ�

struct Node
{	//�˽ṹ���ֽ��Ų���ʽ��
	//�Դ˽ṹ��ռ����ĳ�Ա���ֽ���Ϊһ���ֶΣ��˽ṹ��Ϊdouble��8�ֽڣ���Ȼ�󰴳�Ա˳����װ��������װ����һ���ֶΣ��ֶ��а����˶�������
	//[i][i][i][i][ ][ ][ ][ ]	//�˷ֶ�ǰ4λװint���͵����ݣ���4λ��װ����Ϊ������double����
	//[b][b][b][b][b][b][b][b]	//double���Ͷ�ռһ�ֶΣ�8λ��8�ֽ�
	//[c][c][ ][ ][N][N][N][N]	//�˷ֶ�ǰ2λװshort�������ݣ����ĳ�ԱNode*ռ�ݺ�4λ���ֶ��а����˶������У�
	int iData;		//4�ֽ�
	double b;		//8�ֽ�		//�ڽ�������������ϸ˵��
	short c;		//2�ֽ�
	struct Node* iNext;			//x86��4�ֽڣ�64λ��8�ֽ�
};

//���������淶��ÿ����������ĸ��д�����ߵ��ʼ��� _ ����Ȼ��Сд

//*����β���
void AddToEnd(struct Node** pHead, struct Node** pEnd, int pData);

//������Ҫ������ β��ӵĶ���ָ��ʹ�ý��
void ceshi(int b);

//������Ҫ��pEND������(�˺�����ʾû��pEnd�����)
void AddToEndNopEnd(struct Node** pHead, int pData);

//*����ͷ���
void AddToHead(struct Node** pHead, struct Node** pEnd, int pData);

//*����ָ��λ�ý���ڵ�
void InsertNodeByIndex(struct Node** pHead, struct Node** pEnd, int pIndex, int pData);

//*����һ����������Ϊx��N���ڵ�
void AddSomeNode(struct Node** pHead, struct Node** pEnd, int pCount, int pData);

//*ɾ��ͷɾ��
void DeleteHead(struct Node** pHead, struct Node** pEnd);

//*ɾ��βɾ��
void DeleteEnd(struct Node** pHead, struct Node** pEnd);

//*ɾ��ɾ��ָ�����ݽڵ�	 (һ��ɾһ��)
struct Node* DeleteOneByData(struct Node** pHead, struct Node** pEnd, int iData);

//*ɾ��ɾ��ָ�����ݽڵ�	��һ��ɾ������ظ��ģ�
void DeleteAllByData(struct Node** pHead, struct Node** pEnd, int iData);

//*ɾ�������±�ɾ���ڵ�	 (һ��ɾһ��)
void DeleteDataByIndex(struct Node** pHead, struct Node** pEnd, int pIndex);

//*�ģ��޸�ָ���ڵ�����	��һ���޸�1����
void ChangeData(struct Node* pHead, int iEesData, int pDesData);

//*�ģ��޸���ͬ���ݵĽڵ�	��һ���޸Ķ������ʽ1�����Ƽ���
void ChangeSomeData(struct Node* pHead, int iEesData, int pDesData);

//�ģ��޸���ͬ���ݵĽڵ�	��һ���޸Ķ������ʽ2�����鷳��Щ��
void ChangeSomeData2(struct Node* pHead, int iEesData, int pDesData);

//�����ͷ�
void FreeList(struct Node* pHead);

//�����ͷ� + ��¼ͷβ��ָ�븳ֵNULL
void FreeListNULL(struct Node** pHead, struct Node** pEnd);

//*�飺�����±����ָ���ڵ�
struct Node* FindIndex(struct Node* pHead, int pIndex);

//*�飺�������ݲ���ָ���ڵ�
struct Node* FindByData(struct Node* pHead, int pData);

//*�������ڵ����ݣ��������ݲ��ң����ַ�ʽ
void SwapByData(struct Node* pHead, struct Node* pEnd, int pData1, int pData2);

//*�������ڵ����ݣ������±���ң����ַ�ʽ
void SwapByIndex(struct Node* pHead, struct Node* pEnd, int pIndex1, int pIndex2);

//*����ָ��ָ���鷳��ʽ�Ľ����ڵ㣩
void SwapByChangePoint(struct Node** pHead, struct Node** pEnd, int pIndex1, int pIndex2);

//*��ת�������ݷ�ת��
void ReverseByData(struct Node* pHead, struct Node* pEnd);

//*��ת�����ڵ㷭ת��
void ReverseByPoint(struct Node** pHead, struct Node** pEnd);

//*��ת���������ռ䣩
void ReverseByHelpSpace(struct Node** pHead, struct Node** pEnd);

//����ڵ�������
int GetListNodeCount(struct Node* pHead);

//������ӡ
void AllShow(struct Node* pHead);


int main(void)
{
	struct Node* pHead = { NULL };	//��ʼ����¼ͷβ�ڵ��ָ��
	struct Node* pEnd  = { NULL };

	//β���
	AddToEnd(&pHead, &pEnd, 5);
	AddToEnd(&pHead, &pEnd, 1);
	AddToEnd(&pHead, &pEnd, 3);
	AddToEnd(&pHead, &pEnd, 2);

	AllShow(pHead);

//���� β��ӵĶ���ָ��ʹ�ý��
{
	int a = 0;
	ceshi(a);
	printf("%d \n",a);
}
	
//���� û��pEnd��β�����ʾ
{
	struct Node* pH1 = { NULL };	//��ʼ��ͷ�ڵ��ָ��

	AddToEndNopEnd(&pH1, 51);
	AddToEndNopEnd(&pH1, 52);
	AddToEndNopEnd(&pH1, 53);
	AddToEndNopEnd(&pH1, 54);
	AddToEndNopEnd(&pH1, 55);

	AllShow(pH1);

	FreeList(pH1);
}

//�����ͷ�	+	��¼ͷβ��ָ�븳ֵNULL
{
	FreeList(pHead);		//�ͷ�ʱ��������Ҫ��һ���ͷ�������ͷβ��ֵNULL������֮ǰ����û�и�ֵNULL�Ļ����ٱ�������������������쳣��
	pHead	= NULL;
	pEnd	= NULL;			//��������д��һ�������ڼ���

	AllShow(pHead);

	AddToEnd(&pHead, &pEnd, 45);
	AddToEnd(&pHead, &pEnd, 12);
	AddToEnd(&pHead, &pEnd, 23);
	AddToEnd(&pHead, &pEnd, 52);

	AllShow(pHead);

	FreeListNULL(&pHead, &pEnd);//���������������ϳɵ����ͷź���

	AllShow(pHead);
}

//ͷ���
{
	AddToHead(&pHead, &pEnd, -5);
	AddToEnd(&pHead, &pEnd, 61);
	AddToEnd(&pHead, &pEnd, 11);
	AddToHead(&pHead, &pEnd, -34);
	AddToEnd(&pHead, &pEnd, 71);
	AddToHead(&pHead, &pEnd, -8);
	AddToHead(&pHead, &pEnd, -72);
	AddToEnd(&pHead, &pEnd, 99);

	AllShow(pHead);					//��ӳɹ�

	FreeListNULL(&pHead, &pEnd);

	AllShow(pHead);
}

//�����±��������
{
	AddToHead(&pHead, &pEnd, -5);
	AddToEnd(&pHead, &pEnd, 61);
	AddToEnd(&pHead, &pEnd, 11);
	AddToHead(&pHead, &pEnd, -34);
	AddToEnd(&pHead, &pEnd, 71);
	AllShow(pHead);

	//������������
	struct Node* pTemp = FindIndex(pHead, 2);
	if (pTemp)
		printf("\n��Ӧ�±�����ݣ�%d\n", pTemp->iData);
	else
		printf("\n�����±����\n");
	
	//�����±����
	pTemp = FindIndex(pHead, 5);
	if (pTemp)
		printf("\n��Ӧ�±�����ݣ�%d\n", pTemp->iData);
	else
		printf("\n�����±��±����\n");

	//�����±��С
	pTemp = FindIndex(pHead, -5);
	if (pTemp)
		printf("\n��Ӧ�±�����ݣ�%d\n", pTemp->iData);
	else
		printf("\n�����±��±����\n");


	FreeListNULL(&pHead, &pEnd);		//�ͷſռ�
}

//ָ��λ�ý���ڵ�
{
	AddToHead(&pHead, &pEnd, -5);
	AddToEnd(&pHead, &pEnd, 61);
	AddToEnd(&pHead, &pEnd, 11);
	AllShow(pHead);

	InsertNodeByIndex(&pHead, &pEnd, 0, 996);
	AllShow(pHead);

	InsertNodeByIndex(&pHead, &pEnd, 2, 955);
	AllShow(pHead);

	//������������±�
	InsertNodeByIndex(&pHead, &pEnd, 11, 000);
	AllShow(pHead);

	FreeListNULL(&pHead, &pEnd);
}

//һ����������Ϊx��N���ڵ�
{
	//���Ը�����Ҫ�ĳ�ͷ��ӡ�β��ӡ�ָ��λ�����
	AddToHead(&pHead, &pEnd, -34);
	AddToEnd(&pHead, &pEnd, 1);
	AddToHead(&pHead, &pEnd, 556);
	AddToEnd(&pHead, &pEnd, 3);
	AddSomeNode(&pHead, &pEnd, 3, 996);
	AddToHead(&pHead, &pEnd, 2);

	AllShow(pHead);

	FreeListNULL(&pHead, &pEnd);
}
	
//�޸�ָ���ڵ����ݣ�һ�θ�һ����
{
	AddToHead(&pHead, &pEnd, -34);
	AddToEnd(&pHead, &pEnd, 1);
	AddToHead(&pHead, &pEnd, 556);
	AddToEnd(&pHead, &pEnd, 3);
	AddSomeNode(&pHead, &pEnd, 3, 996);
	AddToHead(&pHead, &pEnd, 2);
	AllShow(pHead);

	ChangeData(pHead, 996, 955);	//ֻ�޸ĵ�һ�����鵽�Ľڵ�����
	AllShow(pHead);

	//����û�еĽڵ�
	ChangeData(pHead, 888, 666);	//�ɹ���ʾ�����޴˽ڵ�
	AllShow(pHead);

	FreeListNULL(&pHead, &pEnd);
}

//�޸���ͬ���ݵĽڵ㣨һ�θ�N����
{
	//��������ʽ�ĺ���д��
	AddToHead(&pHead, &pEnd, -34);
	AddToEnd(&pHead, &pEnd, 1);
	AddToHead(&pHead, &pEnd, 556);
	AddToEnd(&pHead, &pEnd, 3);
	AddSomeNode(&pHead, &pEnd, 3, 996);
	AddToHead(&pHead, &pEnd, 2);
	AllShow(pHead);

	//*��ʽ1��	���Ƽ���
	ChangeSomeData(pHead, 996, 955);
	AllShow(pHead);
	//��������û�е�����
	ChangeSomeData(pHead, 22, 33);
	AllShow(pHead);

	//*��ʽ2��	���鷳��Щ��
	ChangeSomeData(pHead, 955, 996);
	AllShow(pHead);
	//��������û�е�����
	ChangeSomeData(pHead, 22, 33);
	AllShow(pHead);

	FreeListNULL(&pHead, &pEnd);
}

//ͷɾ��
{
	AddToHead(&pHead, &pEnd, -34);
	AddToEnd(&pHead, &pEnd, 1);
	AddToHead(&pHead, &pEnd, 556);
	AddToEnd(&pHead, &pEnd, 3);
	AddSomeNode(&pHead, &pEnd, 3, 996);
	AddToHead(&pHead, &pEnd, 2);
	AllShow(pHead);

	DeleteHead(&pHead, &pEnd);
	AllShow(pHead);

	//����û�нڵ�ʱͷɾ��
	struct Node* pH1 = { NULL };	
	struct Node* pE1 = { NULL };
	AllShow(pH1);
	DeleteHead(&pH1, &pE1);
	AllShow(pH1);

	//����ֻ��һ���ڵ�ʱͷɾ��
	printf("\n����Ϊ1�ڵ�ͷɾ����\n");
	InsertNodeByIndex(&pH1, &pE1, 0, 3);
	AllShow(pH1);
	DeleteHead(&pH1, &pE1);
	AllShow(pH1);

	FreeListNULL(&pH1, &pE1);
	FreeListNULL(&pHead, &pEnd);
}

//βɾ��
{
	AddToHead(&pHead, &pEnd, 4);
	AddToEnd(&pHead, &pEnd, 2);
	AddToHead(&pHead, &pEnd, 5);
	AddToEnd(&pHead, &pEnd, 3);
	AllShow(pHead);

	DeleteEnd(&pHead, &pEnd);
	AllShow(pHead);

	DeleteEnd(&pHead, &pEnd);
	DeleteHead(&pHead, &pEnd);
	AllShow(pHead);
	//����ֻ����һ���ڵ�ʱ
	DeleteEnd(&pHead, &pEnd);
	AllShow(pHead);
	//��������û�нڵ�ʱ
	DeleteEnd(&pHead, &pEnd);
	AllShow(pHead);

	FreeListNULL(&pHead, &pEnd);
}

//ɾ��ָ�����ݽڵ㣨һ��ɾһ����
{
	AddToHead(&pHead, &pEnd, 4);
	AddToEnd(&pHead, &pEnd, 2);
	AddToHead(&pHead, &pEnd, 5);
	AddToEnd(&pHead, &pEnd, 3);
	AllShow(pHead);

	if (DeleteOneByData(&pHead, &pEnd, 2) == NULL)
		printf("\n���޴˽ڵ�\n");
	AllShow(pHead);

	//����ͷɾ��
	if (DeleteOneByData(&pHead, &pEnd, 5) == NULL)
		printf("\n���޴˽ڵ�\n");
	AllShow(pHead);

	//����βɾ��
	if (DeleteOneByData(&pHead, &pEnd, 3) == NULL)
		printf("\n���޴˽ڵ�\n");
	AllShow(pHead);

	//����ɾ�������ڵĽڵ�
	if (DeleteOneByData(&pHead, &pEnd, 3) == NULL)
		printf("\n���޴˽ڵ�\n");
	AllShow(pHead);
	
	FreeListNULL(&pHead, &pEnd);
}

//ɾ��ָ�����ݽڵ㣨һ��ɾ������ظ��ģ�
{
	AddToHead(&pHead, &pEnd, 4);
	AddToHead(&pHead, &pEnd, 5);
	AddToEnd(&pHead, &pEnd, 2);
	AddToEnd(&pHead, &pEnd, 2);
	AddToHead(&pHead, &pEnd, 5);
	AddToEnd(&pHead, &pEnd, 3);
	AllShow(pHead);

	DeleteAllByData(&pHead, &pEnd, 2);
	AllShow(pHead);

	DeleteAllByData(&pHead, &pEnd, 5);		//ִ�����������쳣�����ˣ��ҵ�ԭ���ˣ����鿴ע��
	AllShow(pHead);

	FreeListNULL(&pHead, &pEnd);
}

//ɾ����Ӧ�±�ڵ㣨һ��ɾһ����
{
	AddToHead(&pHead, &pEnd, 4);
	AddToHead(&pHead, &pEnd, 5);
	AddToEnd(&pHead, &pEnd, 2);
	AddToEnd(&pHead, &pEnd, 2);
	AddToHead(&pHead, &pEnd, 5);
	AddToEnd(&pHead, &pEnd, 3);
	AllShow(pHead);

	//����ͷɾ��
	DeleteDataByIndex(&pHead, &pEnd, 0);
	AllShow(pHead);
	//����ɾ�������ڵ��±�
	DeleteDataByIndex(&pHead, &pEnd, 10);
	AllShow(pHead);

	DeleteDataByIndex(&pHead, &pEnd, 1);
	DeleteDataByIndex(&pHead, &pEnd, 1);
	DeleteDataByIndex(&pHead, &pEnd, 1);
	DeleteDataByIndex(&pHead, &pEnd, 1);
	AllShow(pHead);

	//*�����⣩����ֻ��һ���ڵ�ʱ�������±�Ϊ1����ʦ����Ƶ��û������߽�ֵ�Ŀ���
	DeleteDataByIndex(&pHead, &pEnd, 1);
	
	FreeListNULL(&pHead, &pEnd);
}

//�������ڵ����ݣ��������ݲ��ң�
{
	AddToHead(&pHead, &pEnd, 4);
	AddToHead(&pHead, &pEnd, 5);
	AddToEnd(&pHead, &pEnd, 2);
	AddToEnd(&pHead, &pEnd, 2);
	AddToHead(&pHead, &pEnd, 5);
	AddToEnd(&pHead, &pEnd, 3);
	AllShow(pHead);

	SwapByData(pHead, pEnd, 5, 3);	//�����ԣ����ַ�ʽ���ɹ���
	AllShow(pHead);				//���ظ����ݵĻ����������ǵ�һ�����鵽������

	FreeListNULL(&pHead, &pEnd);
}

//�������ڵ����ݣ������±���ң�
{
	AddToHead(&pHead, &pEnd, 4);
	AddToHead(&pHead, &pEnd, 5);
	AddToEnd(&pHead, &pEnd, 2);
	AddToEnd(&pHead, &pEnd, 2);
	AddToHead(&pHead, &pEnd, 5);
	AddToEnd(&pHead, &pEnd, 3);
	AllShow(pHead);

	SwapByIndex(pHead, pEnd, 0, 3);
	AllShow(pHead);

	SwapByIndex(pHead, pEnd, 0, 5);
	AllShow(pHead);
	//�����±곬���ڵ���
	SwapByIndex(pHead, pEnd, 6, 9);
	AllShow(pHead);

	FreeListNULL(&pHead, &pEnd);
}

//�������ڵ�ָ��ָ��
{	//����ʱ���������ǵ����������������ۣ�
	AddToHead(&pHead, &pEnd, 4);
	AddToHead(&pHead, &pEnd, 5);
	AllShow(pHead);
	//ͷβ�����������ڵ�ʱ
	SwapByChangePoint(&pHead, &pEnd, 0, 1);
	AllShow(pHead);
	
	AddToHead(&pHead, &pEnd, 3);
	AddToHead(&pHead, &pEnd, 8);
	AllShow(pHead);
	//ͷβ����������ڵ�ʱ
	SwapByChangePoint(&pHead, &pEnd, 0, 3);
	AllShow(pHead);

	AddToEnd(&pHead, &pEnd, 1);
	AddToEnd(&pHead, &pEnd, 9);
	AllShow(pHead);
	//ͷ-�м佻��������ʱ
	SwapByChangePoint(&pHead, &pEnd, 0, 1);
	AllShow(pHead);
	//ͷ-�м佻����������ʱ
	SwapByChangePoint(&pHead, &pEnd, 0, 4);
	AllShow(pHead);

	AddToEnd(&pHead, &pEnd, 18);
	AddToHead(&pHead, &pEnd, 32);
	AllShow(pHead);
	//β-�м佻��:����ʱ
	SwapByChangePoint(&pHead, &pEnd, 6, 7);
	AllShow(pHead);
	AddToEnd(&pHead, &pEnd, 77);
	AddToHead(&pHead, &pEnd, 45);
	//β-�м佻��:������ʱ
	SwapByChangePoint(&pHead, &pEnd, 1, 9);
	AllShow(pHead);
	
	AddToEnd(&pHead, &pEnd, 25);
	AllShow(pHead);
	//�м�-�м佻��������
	SwapByChangePoint(&pHead, &pEnd, 4, 5);
	AllShow(pHead);
	AddToEnd(&pHead, &pEnd, 27);
	AddToHead(&pHead, &pEnd, 35);
	AllShow(pHead);
	//�м�-�м佻����������
	SwapByChangePoint(&pHead, &pEnd, 1, 9);
	AllShow(pHead);
	
	FreeListNULL(&pHead, &pEnd);
}

//��ת����2�ַ�ʽ����ԭ�ط�ת��
{
	AddToHead(&pHead, &pEnd, 2);
	AddToHead(&pHead, &pEnd, 1);
	AddToEnd(&pHead, &pEnd, 3);
	AddToEnd(&pHead, &pEnd, 4);
	AddToHead(&pHead, &pEnd, 0);
	AddToEnd(&pHead, &pEnd, 5);
	AllShow(pHead);
	//���ݷ�ת
	ReverseByData(pHead, pEnd);
	AllShow(pHead);

	AddToEnd(&pHead, &pEnd, -1);
	AddToHead(&pHead, &pEnd, 6);
	AllShow(pHead);
	//�ڵ㷭ת
	ReverseByPoint(&pHead, &pEnd);
	AllShow(pHead);

	AddToEnd(&pHead, &pEnd, 7);
	AddToHead(&pHead, &pEnd, -2);
	AllShow(pHead);

	FreeListNULL(&pHead, &pEnd);
}

//��ת���������ռ䣩���߼����������������ࣩ
{
	AddToHead(&pHead, &pEnd, 2);
	AddToHead(&pHead, &pEnd, 1);
	AddToEnd(&pHead, &pEnd, 3);
	AddToEnd(&pHead, &pEnd, 4);
	AddToHead(&pHead, &pEnd, 0);
	AddToEnd(&pHead, &pEnd, 5);
	AddToEnd(&pHead, &pEnd, 6);
	AddToEnd(&pHead, &pEnd, 7);
	AddToEnd(&pHead, &pEnd, 8);
	AllShow(pHead);
	//��ת
	ReverseByHelpSpace(&pHead, &pEnd);
	AllShow(pHead);

	AddToEnd(&pHead, &pEnd, -1);
	AddToHead(&pHead, &pEnd, 9);
	AllShow(pHead);
	//��Ӻ��ٷ�ת
	ReverseByHelpSpace(&pHead, &pEnd);
	AllShow(pHead);

	FreeListNULL(&pHead, &pEnd);
}


	system("pause>0");
	return 0;
}



//*����β���
void AddToEnd(struct Node** pHead, struct Node** pEnd, int pData)
{	//�˴��ö���ָ���ԭ����̽�����ƺ���Ϊ����*�������ٿ�ԭ�ռ䣬��һ��ָ��Ͳ��ܲٿأ����Ǿֲ��������޷��ı�ԭ�ռ�����
	//����ָ�룬��Ϊ��Ҫ��pHead������в�����Ҳ�ܲ���pHeadָ��Ŀռ�
	//����ռ�
	struct Node* pTemp = (struct Node*)malloc(sizeof(struct Node));

	//����ռ���ܻ�ʧ�ܣ�Ҫ���п�ָ���ж�
	if (pTemp)
	{
		//�ռ丳ֵ
		pTemp->iData = pData;
		pTemp->iNext = NULL;		//һ��Ҫ��NULL����Ϊ����β�ڵ��iNext������NULL��ԭ���뿴α����Ŀμ��ʼ�

		//���ӽڵ�
		if (*pHead == NULL)			//��pHead��pEnd���ⲿ�ģ�����NULLʱ��˵����û���κνڵ㣬��һ����ΪNULLʱ��������ΪNULL��
		{							//����pHead��pEnd��һ���жϼ��ɣ�����д�ɣ�*pHead == NULL || *pEnd == NULL��
			*pHead = pTemp;			//�ڵ㸳ֵ
			//*pEnd  = pTemp;
		}
		else
		{
			(*pEnd)->iNext = pTemp;	//ԭβ�ڵ��¼�½ڵ��ַ
			//*pEnd = pTemp;
		}
		*pEnd = pTemp;				//pEnd��¼�¼ӽڵ��ָ�룬�����ǿռ串�ǣ���pEndָ��������Ǽ�¼β�ڵ�ĵ�ַ�����Ч�ʣ�pEnd�ǽṹ��ָ�룬pTempҲ�ǽṹ��ָ�룬
	}							//�ṹ����Ҫ���ǣ�����Ҫ��=����������ز��У����Բ��ص��ĸ������⡣���ܸ��������ָ��ӣ���ǰ����Ϊ����ֵ���ǡ�
}

//������Ҫ������ β��ӵĶ���ָ��ʹ�ý��
void ceshi(int b)
{	//ע�⺯�����β��Ǿֲ����������ⲿ�Ĳ���ͬ1��
	//����β��ӶԶ���ָ���ʹ�ã���Ϊ����* �������ٿش����������ݱ���һ��ָ��Ͳ��ܶԴ������ı�����в���
	b = 13;
}

//������Ҫ��pEND������(�˺�����ʾû��pEnd�����)
void AddToEndNopEnd(struct Node** pHead, int pData)
{
	//�����ڵ�
	struct Node* pTemp = (struct Node*)malloc(sizeof(struct Node));

	//��ָ����
	if (pTemp != NULL)
	{
		//�ڵ㸳ֵ
		pTemp->iData = pData;
		pTemp->iNext = NULL;

		//�ڵ���������
		if (*pHead == NULL)			//û�нڵ�ʱ��*pHead == NULL
			*pHead = pTemp;
		else
		{
			struct Node* pt = *pHead;//����ʱ��������¼�ڵ�ͷָ�룬ԭ��������ֱ���ýڵ�ͷ�Ļ��������*pHead��¼�ĵ�ַ�ͻز���ԭ��λ�ã��Ͷ�ʧ�ˣ����ٴ���ڵ�ͷ

			while (pt->iNext != NULL)//�����ַ�ʽ��Ѱ�ҵ�β�ڵ��λ�ã�������ڵ���һ�࣬ѭ������Ҳ��Խ��Խ�࣬ÿ����ӽڵ㶼Ҫѭ��һ��
				pt = pt->iNext;		//һ�Աȣ���pEnd�ĺô����Ǳ�����ѭ��Ѱ��β�ڵ�λ�ã�ֱ����ָ��pEnd��¼��ǰβ�ڵ��ַ���Ͳ���Ѱ�ң�ֱ��֪��λ�ã������Ч��

			pt->iNext = pTemp;		//�����¼ӽڵ�
		}
	}


}

//*����ͷ���
void AddToHead(struct Node** pHead, struct Node** pEnd, int pData)
{	//��β��ӶԱȷ��֣�����ԭ��һ��
	//�����ڵ�
	struct Node* pTemp = (struct Node*)malloc(sizeof(struct Node));

	if (pTemp)
	{
		//�ڵ㸳ֵ
		pTemp->iData = pData;
		pTemp->iNext = NULL;

		//�ڵ����ӵ�����
		if (*pHead == NULL)			//����û�нڵ�ʱ
		{
			//*pHead	= pTemp;	//�������������Ҫ����¼ͷ�ڵ��ַ��ָ��pHead��¼�½ڵ��ַ�����Կ���д��{}���棬��ʡ����
			*pEnd = pTemp;
		}
		else						//�����нڵ�ʱ
		{
			pTemp->iNext = *pHead;	//�½ڵ��iNext��¼ԭͷ�ڵ��ַ
			//*pHead	= pTemp;
		}
		*pHead = pTemp;				//ָ��pHead��¼�µ�ͷ�ڵ�ĵ�ַ
	}
}

//*����ָ��λ�ý���ڵ�
void InsertNodeByIndex(struct Node** pHead, struct Node** pEnd, int pIndex, int pData)
{
	//�����Ϸ��Լ��
	if (pIndex < 0)		//û���ж�pHead�Ƿ�ΪNULL��ԭ���ǣ�����ΪNULL��û�нڵ㣬���Ǹ���ӽڵ㺯����û�нڵ�ҲҪ	�����ȥ
	{
		printf("\n�����±������Ч������������\n");
		return;
	}

	//����±�Ϊ0����ͷ���
	if (pIndex == 0)		
	{
		AddToHead(pHead, pEnd, pData);
	}						//��ǰ����û�нڵ㣬��Ὣ�ýڵ���ӽ�ȥ��д��AddToHead�����
	else
	{
		//��λ��
		struct Node* pt = FindIndex(*pHead, pIndex - 1);
		if (pt != NULL)						//����a c�ڵ㣬bҪȡ��c��λ�ã��±꣩������Ҫ����a��λ�ã���pIndex - 1
		{
			//�����ڵ�
			struct Node* pTemp = (struct Node*)malloc(sizeof(struct Node));
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
			printf("\n���޴˽ڵ�\n");
	}

}

//*����һ����������Ϊx��N���ڵ�	//���Ը�����Ҫ�ĳ�ͷ��ӡ�β��ӡ�ָ��λ�����
void AddSomeNode(struct Node** pHead, struct Node** pEnd, int pCount, int pData)
{
	//��ѭ��������Ӻ�������
	for (int i = 0; i < pCount; i++)	//��ӵĺ������ǲ�����дһ�飬�˷�ʱ�䣬����������Ӻ����ͺ���
	{
		AddToEnd(pHead, pEnd, pData);	//д�ĺ������ܵ�һ������ͨ���Ըߣ������������÷��㣬д��̫���ӾͲ��õ�����
	}
}

//*ɾ��ͷɾ��
void DeleteHead(struct Node** pHead, struct Node** pEnd)
{	//���������淶��ÿ����������ĸ��д�����ߵ��ʼ��� _ ����Ȼ��Сд
	//�����Ϸ��Լ��
	if (*pHead == NULL)			//������Ϊ��ʱ��û�нڵ㣬��������
		return;
	if (*pHead == *pEnd)		//������ֻ��һ���ڵ�ʱ
	{							//(*pHead)->iNext == NULL���ж���(*pHead == *pEnd)��һ���ģ�����ʾ����ֻ��һ���ڵ�ʱ
		free(*pHead);
		*pHead	= NULL;			//������ֻ��һ���ڵ�ʱ�����ռ��ͷţ����ҽ���¼ͷβ��ָ�븳ֵNULL
		*pEnd	= NULL;			//���򲻸�ֵNULL�Ļ�����¼����ͷβ��ָ�벻֪������ʲô�ˣ�����Ͳ������ˣ���������ӽڵ�ͻ����
	}
	else						//���ж���ڵ�ʱ
	{
		struct Node* pt = *pHead;//��¼ԭͷ�ڵ��ַ
		*pHead = pt->iNext;//��ͷָ���¼�µ�ͷ�ڵ�
		free(pt);				//�ͷ�ԭͷ�ڵ�ռ�
	}

}

//*ɾ��βɾ��
void DeleteEnd(struct Node** pHead, struct Node** pEnd)
{
	//�����Ϸ��Լ��
	if (*pHead == NULL)
		return;
	//��ֻ��һ���ڵ�ʱ
	if (*pHead == *pEnd)
	{
		free(*pHead);
		*pHead	= NULL;
		*pEnd	= NULL;
	}
	else//���ж���ڵ�ʱ
	{
		struct Node* pt = *pHead;	//ʹ����ʱ�������洢��ַ����Ҫֱ����pHead�����ı�pHead�����ݣ��������Ҳ���ͷ�ڵ���
		//Ѱ��β�ڵ��ǰһ��
		while (pt->iNext != *pEnd)	//��β�ڵ�ǰһ��ԭ����A C ɾC�����ӣ�Ҫ��pt��¼A��Ȼ���ͷ�C���ٽ�A�ļ�¼��ַ��ֵNULL��pEnd��¼�µ�β�ڵ�A
		{							
			pt = pt->iNext;			//����pt = (*pHead)->iNext;	֮ǰ����д���ˣ���Ϊ*pHeadû�䣬��pt��Զ��ѭ����==һ���̶�ֵ����ȥ
		}				
		//��ʱpt�ͼ�¼��β�ڵ��ǰһ��
		free(*pEnd);
		*pEnd = pt;			//*pEnd��¼��β�ڵ�ĵ�ַ
		pt->iNext = NULL;	//**ע�⣬�µ�β�ڵ�һ��Ҫ��iNext��ֵΪNULL
	}
}

//*ɾ��ɾ��ָ�����ݽڵ�	 (һ��ɾһ��)
struct Node* DeleteOneByData(struct Node** pHead, struct Node** pEnd, int iData)
{
	//�����Ϸ��Լ��
	if (*pHead == NULL)
		return NULL;

	if ((*pHead)->iData == iData)		//�������ݵĽڵ���ͷ�ڵ�ʱ��ͷɾ��
	{
		DeleteHead(pHead, pEnd);		//*����Ĳ���pHead���ⲿ���ݽ�����&pHead����Ϊ���������Ƕ���ָ�룬�ʺ����ڵ�pHeadҲ�Ƕ���ָ�룬�����ⲿ��&pHead
		return *pHead;					//����ֵ��Ϊ�˸�ɾ������ظ��ĺ���ʹ�õ�
	}
	else if ((*pEnd)->iData == iData)	//�������ݵĽڵ���β�ڵ�ʱ��βɾ��
	{
		DeleteEnd(pHead, pEnd);	
		return *pHead;					//����Ҳ����ͷָ�룬����Ϊ����������Ҫ��ͷ�����ģ���β�ͱ���������
	}
	else								//���������м�ڵ�ʱ
	{
		struct Node* pTemp = *pHead;
		//ѭ�����Ҹýڵ��ǰһλ
		while (pTemp->iNext != NULL)
		{
			if (pTemp->iNext->iData == iData)
				break;					//�ҵ���������ǰѭ��
			pTemp = pTemp->iNext;
		}
		if (pTemp->iNext != NULL)
		{								//��ABCDɾB������A��¼��ָ���Ϊ��¼C�ĵ�ַ��Ȼ���ͷ�B������
			struct Node* pt = pTemp->iNext;//��һ����ʱ�����洢�ýڵ㣨B���ĵ�ַ
			pTemp->iNext = pt->iNext;	//Bָ��C�ĵ�ַ���Aָ��C
			free(pt);					//�ͷ�B�Ŀռ�
			return pTemp;				//����A�ĵ�ַ����ɾ������ĺ�����A��ʼ��������ɾ������ǰ�Ѿ����ҹ��ˣ����������ͷ��ʼ���ң����Ч��
										//��ʦһ��ʼ������C�ĵ�ַ����������ˣ���Ϊ��C��ʼ���������ܵ���ͷɾ����ɾ��C������ACD�ͶϿ��ˣ�����Ͽ��ͳ�����
		}
		else							//pTemp->iNext == NULL ˵������������û�ҵ�
		{
			//printf("\n���޴˽ڵ�\n");	//һ��ɾ�����DeleteAllByData�����е��ô˺������ض���ִ�д˴�ӡ����ע�͵������������д���
			return NULL;
		}	
	}
}

//*ɾ��ɾ��ָ�����ݽڵ�	��һ��ɾ������ظ��ģ�
void DeleteAllByData(struct Node** pHead, struct Node** pEnd, int iData)
{
	//�����Ϸ��Լ��
	if (*pHead == NULL)
		return;

	//��¼ɾ��ָ���ڵ�DeleteOneByData��������ֵ
	struct Node* pT = DeleteOneByData(pHead, pEnd, iData);//DeleteOneByData�������Դ�ͷ�ڵ㡢β�ڵ���жϴ������ǾͲ�����д��
						//��ʵ���԰Ѻ�������ֱ��д�������ж��У���������ʱ����������⣬�Ҳ�����ʲôӰ��
	//ѭ������ɾ��
	while (pT != NULL)	//���ز�ΪNULL���������DeleteOneByData����ѭ������ɾ��
	{					// ���ǵü�ȡ��ַ�� & 
		pT = DeleteOneByData(pHead, pEnd, iData);	//**���������������ע��ʹ��&pT��ԭ����鿴DeleteOneByData��������ֵע��
	}					//����ȷ��������Ҳ������pHead�������Ǵ�ͷ��ʼ����ɾ�����˷���Ч�ʣ��ʴӷ���ֵ��ʼ��������
	//ע�⣺����Ȼ����pT��������ɾ������5��ͷɾ��������쳣�����ˣ������ԭ��,����pHead�Ϳ�����
	//�ƺ��ҵ�ԭ���ˣ���Ϊ���ﴫ����&pT��������ͷɾ����pT���������µ�����ͷָ�룬����ʱ���������pHead���Ǳ�ɾ��ǰ������ͷָ�룬��������ͷָ�붪ʧ����֪��ָ�����Խ���ˣ�
	//��ԭ��ʱ�ϵ�鿴������Ϊ�����������*pHead����һ��������Ϊ���������pHead��һ���ģ�����ʵ��һ�������ѭ�������������&pT,�ǲ����Ķ�������ʱ����pT���������������pHead
	//������ȻpT��¼���µ�����ͷ�����������𵽸ı�ֵ�����ã����Ǽ�¼����ֵ���жϵ����ã��������������pHead��¼�Ŀռ䣨ԭ����ͷ�����ͷţ�����ͷ��ʧ�����ж����õ�pT��¼���µĵ�ַ��
	//������Ϊѭ������ֵ��NULL�˳�ѭ����ԭ��pT�����NULL����������Ӧ���Ͻ��Ĵ������������pHead����Ҫ����ʦ�ķ������ҿ�������⿨��4Сʱ���Դ������ˣ�
}	

//*ɾ�������±�ɾ���ڵ�	 (һ��ɾһ��)
void DeleteDataByIndex(struct Node** pHead, struct Node** pEnd, int pIndex)
{
	//�����Ϸ��Լ��
	if (*pHead == NULL)
		return;

	//�±�Ϊ0ʱ��ͷɾ��
	if (pIndex == 0)
		DeleteHead(pHead, pEnd);
	else//�±겻Ϊ0
	{
		//���Ҷ�Ӧ�±��ǰһ���ڵ�
		struct Node *pt = FindIndex(*pHead, pIndex - 1);
		if (pt != NULL)
		{
			//�����Ӧ�±���β�ڵ㣬����Ҫβɾ��
			if (pt->iNext == pEnd)		//��Щ�ٽ�����Ҫ���۾��飬�������ж���ô����
			{
				DeleteEnd(pHead, pEnd);			//��Ϊ������βɾ���Ļ�����¼β�ڵ��ָ��ͻᶪʧ���ǿ�ռ��ͷŵ��ˣ�
				return;
			}
			//����ýڵ㲻��β�ڵ㣬�����
			struct Node* pT = pt->iNext;//ABCɾB����A��ɼ�¼C��ַ��Bԭ�ȼ�¼�����ݣ���Ȼ���ͷ�B
			if (pT != NULL)
			{
				pt->iNext = pT->iNext;
				free(pT);
			}
			else//��ֻ��1���ڵ��������±�Ϊ1ʱ�Żᴥ������Ϊ�����ǲ���pIndex - 1������һ���ᴥ������
				printf("\n����ʾ������ֻ��һ���ڵ㣬���±�Ϊ1ʱ���ڣ��±����ֻʣ1���ڵ㣬�±�Ϊ0\n");
		}
		else
			printf("���޴˽ڵ�\n");	//FindIndex�����о����±��ж���,�������ǲ����±�-1�Ľڵ㣬���ǲ��Ӧ�±�
	}
}

//*�ģ��޸�ָ���ڵ�����	��һ���޸�1����
void ChangeData(struct Node* pHead, int iEesData, int pDesData)
{	//��Ϊ���޸����ݣ�������ָ�뱾�����Դ�һ��ָ��
	struct Node* pes = FindByData(pHead, iEesData);	//��һ����ʱ������¼FindByData�ķ���ֵ�����������������Ӱ��Ч��

	if (pes == NULL)				//û�ҵ���Ӧ����
		printf("\n���޴�����.\n");
	else							//�ҵ���
	{
		pes->iData = pDesData;
	}
}

//*�ģ��޸���ͬ���ݵĽڵ�	��һ���޸Ķ������ʽ1�����Ƽ���������Ч��
void ChangeSomeData(struct Node* pHead, int iEesData, int pDesData)
{
	//�����Ϸ��Լ��
	if (FindByData(pHead, iEesData) == NULL)
		printf("\n���޴˽ڵ�\n");
	while (pHead != NULL)
	{
		if (pHead->iData == iEesData)
			pHead->iData = pDesData;
		pHead = pHead->iNext;
	}
}

//*�ģ��޸���ͬ���ݵĽڵ�	��һ���޸Ķ������ʽ2�����鷳��Щ��Ч�ʵ���һ�㣩
void ChangeSomeData2(struct Node* pHead, int iEesData, int pDesData)
{
	////��һ�β���
	struct Node* pea = FindByData(pHead, iEesData);//FindByData���pHead���в����Ϸ��Լ��
	//�����Ϸ��Լ��
	if (pea == NULL)
	{
		printf("\n���޴˽ڵ�\n");
		return;					//û�ҵ���������
	}
	else//��һ���޸�
		pea->iData = pDesData;

	//�ٴβ���
	while (pea != NULL)
	{
		pea = FindByData(pHead, iEesData);
		if (pea != NULL)		//��Ϊȫ�������pea == NULL�����Լ�������жϷ�ֹ����NULL->iData�Ĳ���
			pea->iData = pDesData;
	}
}

//�����ͷ�
void FreeList(struct Node* pHead)
{	//ʹ��һ��ָ���ԭ�����ﴫ�ݵ����ⲿ��pHead�����ݣ������Ƕ�������ݽ��в����������Ƕ�pHead������в���
	struct Node* pTemp = pHead;		//���м�����ɴ���������棺//����	C6001	ʹ��δ��ʼ�����ڴ桰* pHead����
									//�����ԭ�������ⲿpHead�������˺Ϸ���ֵ
	while (pTemp != NULL)
	{
		struct Node* pt = pTemp;	//ʹ����ʱ�������洢pHead�仯ǰװ�ĵ�ַ������ֱ���ͷ�pHead�Ļ����Ͳ����ҵ���һ���ڵ��λ����
		pTemp = pTemp->iNext;
		free(pt);					//�ͷż�¼�ĵ�ַָ��Ŀռ�
	}
}

//*�����ͷ� + ��¼ͷβ��ָ�븳ֵNULL
void FreeListNULL(struct Node** pHead, struct Node** pEnd)
{	//��ΪҪ���ⲿ��pHead������в�����������Ҫ����ָ�루�ο�β���������ͷţ�
	struct Node* pTempH = *pHead;	//Ϊ�˴����棬����о����һ�٣������Ϊʲô�о��棬�߼����ǶԵ�

	while (pTempH != NULL)
	{
		struct Node* pt = pTempH;
		pTempH = pTempH->iNext;
		free(pt);
	}
	*pHead = NULL;
	*pEnd = NULL;
}

//*�飺�����±����ָ���ڵ�
struct Node* FindIndex(struct Node* pHead, int pIndex)
{
	int Num = 0;			//��һ�����������Ƚ������±�

	//�����Ϸ��Լ��
	if (pHead == NULL || pIndex < 0)
	{
		printf("\n����ΪNULL/������Ч\n");
		return NULL;		//����NULL����������
	}

	//���ҹ���
	while (pHead != NULL)	//����˵���ж�дȫ�����淶��ֻдpHead���淶���Ļ���˵�������boole���͵���
	{
		if (Num == pIndex)
			return pHead;	//�ҵ����ص�ǰ�ڵ��ַ����������
		Num++;
		pHead = pHead->iNext;
	}

	//û�ҵ���ִ������
	printf("\n�����±곬������Ԫ�ظ���\n");	//û������ѭ�����ҵ���˵���±����������ʾ������NULL
	return NULL;
}

//*�飺�������ݲ���ָ���ڵ�
struct Node* FindByData(struct Node* pHead, int pData)
{
	//�����Ϸ��Լ��
	if (pHead == NULL)
		return NULL;
	//��ʼ����
	while (pHead != NULL)
	{
		if (pHead->iData == pData)
			return pHead;			//�ҵ����ص�ַ����������
		pHead = pHead->iNext;
	}
	//û�ҵ�
	return NULL;
}

//*�������ڵ����ݣ��������ݲ��ң����ַ�ʽ
void SwapByData(struct Node* pHead, struct Node* pEnd, int pData1, int pData2)
{
	//�����Ϸ��Լ��
	if (pHead == NULL || pHead->iNext == NULL)
		return;//�ֱ�Ϊ������û�нڵ㡢����ֻ��һ���ڵ� �����ܽ��н���

	//����
	struct Node* pT1 = FindByData(pHead, pData1);
	struct Node* pT2 = FindByData(pHead, pData2);
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
		printf("\n��1������δ�ҵ�\n");
	if (pT2 == NULL)
		printf("\n��2������δ�ҵ�\n");
	if(pT1 == pT2)
		printf("\nһ�������ݣ�ֻ��һ���ڵ㣬�޷�����\n");
}

//*�������ڵ����ݣ������±���ң�
void SwapByIndex(struct Node* pHead, struct Node* pEnd, int pIndex1, int pIndex2)
{
	//�����Ϸ��Լ��
	if (pHead == NULL || pHead->iNext == NULL || pIndex1 == pIndex2 || pIndex1 < 0 || pIndex2 < 0)
		return;//�ֱ�Ϊ������û�нڵ㡢����ֻ��һ���ڵ㡢���±���ͬ���±�С��0

	//����
	struct Node* pt1 = FindIndex(pHead, pIndex1);
	struct Node* pt2 = FindIndex(pHead, pIndex2);

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
		printf("\n��1������δ�ҵ�\n");
	if (pt2 == NULL)
		printf("\n��2������δ�ҵ�\n");
}

//*����ָ��ָ���鷳��ʽ�Ľ����ڵ㣩
void SwapByChangePoint(struct Node** pHead, struct Node** pEnd, int pIndex1, int pIndex2)
{
	//������ѧϰʱ�����������������Щʵ������ķ�ʽ�����㷨����������Ȼ��Ľ���Ȼ��ʹ�á�

	//�����Ϸ��Լ��	���������ǵ�©�����������������BUG�����۾��飩
	if (*pHead == NULL || (*pHead)->iNext == NULL || pIndex1 == pIndex2 || pIndex1 < 0 || pIndex2 < 0)
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
	struct Node* pMix = FindIndex(*pHead, Mix);
	struct Node* pMax = FindIndex(*pHead, Max);
	//�Ҳ�����Ӧ�ڵ����ֹ����
	if (pMix == NULL || pMax == NULL)
		return;

	//ȷ���ҵ��󣬽���ͷ-β��ͷ-�м䡢β-�м���������ж�	
	
	//ͷ-β����	��2�������
	if (pMix == *pHead && pMax == *pEnd)		//ͷ-β��ͷ-�м䡢β-�м䣬��������ǲ�һ���ģ�����Ҫ�����ҳ���
	{
		//1.����ֻ��2���ڵ����
		if ((*pHead)->iNext == *pEnd)
		{																	//��AB������������
			//ͷβָ��ת��						
			(*pEnd)->iNext = *pHead;										//1.��A->B���B->A
			//���µ�β�ڵ��ַ��Ա��ֵNULL
			(*pHead)->iNext = NULL;											//2.��A�ĵ�ַλ��ֵNULL
			//��¼ͷβ��ַ��ָ�뽻��
			*pHead = *pEnd;				//��ʱһ���ڵ�ͬʱ��ͷβ��¼ָ���¼	//3.Ȼ��pHead�Ӽ�¼A��ɼ�B����ʱB��pHead��pEndͬʱ��¼
			*pEnd = (*pEnd)->iNext;		//��ʱ���ͷβ��¼ָ��Ľ���			//4.����pEnd��Ϊ��¼A
		}
		//2.�����ж���ڵ����
		else 
		{
			//����β�ڵ��ǰһ��	//��������Ѿ�ɸѡ��������϶�3���ڵ����ϣ��϶����ҵ�pMaxpre
			struct Node* pMaxpre = FindIndex(*pHead, Max-1);
			//ͷβ�ڵ�λ�û���					//������A-B-C-D������
			(*pEnd)->iNext = (*pHead)->iNext;	//���D->B
			pMaxpre->iNext = *pHead;			//C->D���C->A
			//���µ�β�ڵ��ַ��Ա��ֵNULL
			(*pHead)->iNext = NULL;				//A�ĵ�ַ��Ա��ֵNULL
			//��¼ͷβ��ַ��ָ�뽻��
			*pHead = *pEnd;						//pHead�Ӽ�¼A��ɼ�¼D����ʱpEnd��pHead����¼D
			*pEnd = pMaxpre->iNext;			//pEnd�Ӽ�¼D����ɼ�¼A���������ͷβ������������D-B-C-A
			//���ﲻ�������ڵ�ʱ�ķ�ʽ�ˣ�һ��Ҫ��pMaxpre->iNext��
			//���Ի�ͼ������⣬(*pEnd)->iNext��(*pHead)->iNext����ʾD����һλ�����ڵ�B��
		}
	}
	//ͷ-�м佻����2�������
	else if (pMix == *pHead && pMax != *pEnd)
	{
		//1.�����ڵ�����
		if (pMix->iNext == pMax)
		{
			//�ı����ڵ���ָ��			//��A-B-C������
			pMix->iNext = pMax->iNext;	//A->C,A��Ϊָ��C
			pMax->iNext = pMix;			//B->A,B��Ϊָ��A	�����B-A-C
			//�ı�ͷ��¼ָ��
			*pHead = pMax;				//pHead��¼��ͷ�ڵ�B
		}
		//2.���ڵ㲻����
		else
		{
			//Ѱ��pMax��ǰһλ�ڵ�
			struct Node* Maxpre = FindIndex(*pHead, Max - 1);
			//��¼��2���ڵ��ַ			//��������Ӱ�첻��ʹ�÷��㣬�ǵ�ʹ������˼·�����ٷ���
			struct Node* second = (*pHead)->iNext;
			//�ı�ڵ��ָ��				//��A-B-C-D-E������AD����
			pMix->iNext = pMax->iNext;	//A->E
			pMax->iNext = second;		//D->B
			Maxpre->iNext = pMix;		//C->A		��������ΪD-B-C-A-E
			//�ı�ͷ��¼ָ��
			*pHead = pMax;
		}
	}
	//β-�м佻����2�������
	else if (pMix != *pHead && pMax == *pEnd)
	{
		//1.����
		if (pMix->iNext == pMax)
		{
			//�ҵ�pMix��ǰһλ�ڵ�		//��A-B-C����BC������
			struct Node* p = FindIndex(*pHead, Mix - 1);
			//�ı�ڵ���ָ��		
			p->iNext = pMax;			//A->C
			pMax->iNext = pMix;			//C->B	��ʱ������A-C-B
			//���µ�β�ڵ�iNext��ֵNULL
			pMix->iNext = NULL;
			//�ı�β�ڵ��¼ָ��
			*pEnd = pMix;
		}
		else
		{
			//�ֱ��ҵ�pMix��pMax��ǰһλ�ڵ�
			struct Node* pMixpre = FindIndex(*pHead, Mix - 1);
			struct Node* pMaxpre = FindIndex(*pHead, Max - 1);
			//�ı�ڵ���ָ��			//��A-B-C-D-E��BE������
			pMixpre->iNext = pMax;		//A->E
			pMax->iNext = pMix->iNext;	//E->C
			pMaxpre->iNext = pMix;		//D->B		���ڵ�����˳��Ϊ��A-E-C-D-B
			//���µ�β�ڵ�iNext��ֵNULL
			pMix->iNext = NULL;
			//�ı�β�ڵ��¼ָ��
			*pEnd = pMix;
		}
	}
	//�м�-�м佻����2�������
	else if (pMix != *pHead && pMax != *pEnd)
	{
		//����
		if (pMix->iNext == pMax)
		{
			//�ֱ��ҵ�pMix��ǰһλ��pMax����һλ�ڵ�
			struct Node* pMixPre = FindIndex(*pHead, Mix - 1);
			struct Node* pMaxNext = FindIndex(*pHead, Max + 1);

			//�ı�ڵ��ָ��			//��A-B-C-D����BC������
			pMixPre->iNext = pMax;	//A->C
			pMax->iNext = pMix;		//C->B
			pMix->iNext = pMaxNext;	//B->D		������˳��A-C-B-D
		}
		//������
		else
		{
			//�ҵ�pMixǰ�������ڵ�	//����Щ�ڵ㣬��Ϊ��ʹ�������߼��򵥣����ذ��Դ���죬��һ�²���ʲô��
			struct Node* pMixPre = FindIndex(*pHead, Mix - 1);
			struct Node* pMixNext = FindIndex(*pHead, Mix + 1);
			//�ҵ�pMaxǰ�������ڵ�
			struct Node* pMaxPre = FindIndex(*pHead, Max - 1);
			struct Node* pMaxNext = FindIndex(*pHead, Max + 1);

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
void ReverseByData(struct Node* pHead, struct Node* pEnd)
{
	//�����Ϸ��Լ��	//pHead == NULL���ж�һ��Ҫд��ǰ�棬��Ϊ���ΪNULL�Ļ�����ȡiNext����Խ�����
	if (pHead == NULL || pHead->iNext == NULL)
		return;//����û�нڵ㡢ֻ��һ���ڵ�

	//�����ڵ�����
	int i = 0; int j = GetListNodeCount(pHead)-1;	//��i j���м俿£
	for (; i < j; i++, j--)		//��A-B-C-D-E����
	{							//A-E���� B-D���� C����������ʵ��������ת
		SwapByIndex(pHead, pEnd, i, j);
	}
}

//*��ת�����ڵ㷭ת����ԭ�ط�ת��
void ReverseByPoint(struct Node** pHead, struct Node** pEnd)
{	//ʹ�ö���ָ���ԭ����Ҫ����ָ��ָ����Ҫ�ı�pHead���������
	//�����Ϸ��Լ��
	if (*pHead == NULL || (*pHead)->iNext == NULL)
		return;//����û�нڵ㡢ֻ��һ���ڵ�

	int i = 0; int j = GetListNodeCount(*pHead)-1;	//�����J�ǵ��±�ʹ�ã�����Ҫ����-1
	for (; i < j; i++, j--)
	{
		SwapByChangePoint(pHead, pEnd, i, j);
	}
}

//*��ת���������ռ䣩���߼����������������ࣩ
void ReverseByHelpSpace(struct Node** pHead, struct Node** pEnd)
{	//����ָ�룺Ҫ��pHead������в���
	//�����Ϸ��Լ��
	if (*pHead == NULL || (*pHead)->iNext == NULL)
		return;//���ˣ�û�нڵ㡢ֻ��һ���ڵ�

	//��¼ͷָ�룬����ͷָ�붪ʧ			//�߼����̣�
	struct Node* pTemp = *pHead;		//1.����������
	//����������							//2.ԭ����˳�򣬽��ڵ�����ͷ��ӵ�������	��ʵ���˷�ת��
	struct Node* pNewpHead = NULL;		//3.�ͷ�ԭ�ռ�
	struct Node* pNewpEnd = NULL;		//4.ͷβ��¼ָ���¼������ͷβ��������ɷ�ת

	//��������Ľڵ����ݣ���˳��ͷ��ӵ����������������ʵ���˷�ת
	while (pTemp != NULL)
	{
		AddToHead(&pNewpHead, &pNewpEnd, pTemp->iData);
		pTemp = pTemp->iNext;
	}

	//�ͷ�ԭ�ռ�
	FreeListNULL(pHead, pEnd);

	//��¼ͷβ��ָ�룬��¼�������ͷβ
	*pHead = pNewpHead;
	*pEnd = pNewpEnd;
}

//����ڵ�������
int GetListNodeCount(struct Node* pHead)
{
	//�����Ϸ��Լ��
	if (pHead == NULL)
		return 0;

	int Num = 0;
	while (pHead != NULL)
	{
		Num++;
		pHead = pHead->iNext;
	}
	return Num;
}

//������ӡ
void AllShow(struct Node* pHead)
{
	printf("\n�ڵ��Ԫ������Ϊ��");
	if (pHead)
	{
		while (pHead != NULL)
		{
			printf("%2d  ", pHead->iData);
			pHead = pHead->iNext;
		}
	}
	else
		printf(" ��ӡ������������");

	putchar('\n');				//��ʦ����ʾ��������printfһ�������ã��������"\n\n"��������P������������ַ����������ַ�����
}
