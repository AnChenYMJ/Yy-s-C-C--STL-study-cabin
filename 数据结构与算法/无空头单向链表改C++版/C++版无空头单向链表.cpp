#include "dl.h"


//����˵һ����ʦ���޸�˳��
//1.�ṹ��ĳ��ࡢ�����Ž����С������������������������
//2.��ӷ������η�
//3.ɾ����ǰ���к������βΣ���Ϊ�����Ѿ������ڳ�Ա�ˣ�
//4.���������޸ĳɶ������
//5.malloc free �޸ĳɣ�new����ռ䡢delete�ͷſռ�
//6.printf �޸ĳ� cout

int main()
{
	List ls;

	//β���
	ls.AddToEnd( 5);
	ls.AddToEnd( 1);
	ls.AddToEnd( 3);
	ls.AddToEnd( 2);

	ls.AllShow();

	//���� β��ӵĶ���ָ��ʹ�ý��
	{
		int a = 0;
		ls.ceshi(a);
		printf("%d \n", a);
	}

	//���� û��pEnd��β�����ʾ
	{
		List ls1;		//����{}���Զ��ͷ��ˣ���Ϊ�Ǿֲ�����

		ls1.AddToEndNopEnd(	51);
		ls1.AddToEndNopEnd( 52);
		ls1.AddToEndNopEnd( 53);
		ls1.AddToEndNopEnd( 54);
		ls1.AddToEndNopEnd( 55);

		ls1.AllShow();
	}

	//�����ͷ�	+	��¼ͷβ��ָ�븳ֵNULL
	{
		List ls1;

		//ls.FreeList();	//�ͷ�ʱ��������Ҫ��һ���ͷ�������ͷβ��ֵNULL������֮ǰ����û�и�ֵNULL�Ļ����ٱ�������������������쳣��
		//ls.pHead = NULL;	//��������д��һ�������ڼ���
		//ls.pEnd = NULL;	//��Ϊ�ĳ�C++����������˽�ܳ�Ա�޷����ã����Ѿ�ȷ��������

		ls1.AddToEnd( 45);
		ls1.AddToEnd( 12);
		ls1.AddToEnd( 23);
		ls1.AddToEnd( 52);

		ls1.AllShow();

		//ls1.FreeListNULL();	//�Ѿ���˽�ܳ�Ա�����Ѿ�ȷ����Ч��
	}

	//ͷ���
	{
		List ls1;

		ls1.AddToHead( -5);
		ls1.AddToEnd( 61);
		ls1.AddToEnd( 11);
		ls1.AddToHead( -34);
		ls1.AddToEnd( 71);
		ls1.AddToHead( -8);
		ls1.AddToHead( -72);
		ls1.AddToEnd( 99);

		ls1.AllShow();					//��ӳɹ�
	}

	//�����±��������
	{
		List ls1;

		ls1.AddToHead( -5);
		ls1.AddToEnd( 61);
		ls1.AddToEnd( 11);
		ls1.AddToHead( -34);
		ls1.AddToEnd( 71);
		ls1.AllShow();

		//������������
		struct Node* pTemp = ls1.FindIndex(2);
		if (pTemp)
			printf("\n��Ӧ�±�����ݣ�%d\n", pTemp->iData);
		else
			printf("\n�����±����\n");

		//�����±����
		pTemp = ls1.FindIndex( 5);
		if (pTemp)
			printf("\n��Ӧ�±�����ݣ�%d\n", pTemp->iData);
		else
			printf("\n�����±��±����\n");

		//�����±��С
		pTemp = ls1.FindIndex( -5);
		if (pTemp)
			printf("\n��Ӧ�±�����ݣ�%d\n", pTemp->iData);
		else
			printf("\n�����±��±����\n");

	}

	//ָ��λ�ý���ڵ�
	{
		List ls1;

		ls1.AddToHead( -5);
		ls1.AddToEnd( 61);
		ls1.AddToEnd( 11);
		ls1.AllShow();

		ls1.InsertNodeByIndex( 0, 996);
		ls1.AllShow();

		ls1.InsertNodeByIndex( 2, 955);
		ls1.AllShow();

		//������������±�
		ls1.InsertNodeByIndex( 11, 000);
		ls1.AllShow();

	}

	//һ����������Ϊx��N���ڵ�
	{
		List ls1;

		//���Ը�����Ҫ�ĳ�ͷ��ӡ�β��ӡ�ָ��λ�����
		ls1.AddToHead( -34);
		ls1.AddToEnd( 1);
		ls1.AddToHead( 556);
		ls1.AddToEnd( 3);
		ls1.AddSomeNode( 3, 996);	//�˴�Ϊβ���
		ls1.AddToHead( 2);

		ls1.AllShow();

	}

	//�޸�ָ���ڵ����ݣ�һ�θ�һ����
	{
		List ls1;

		ls1.AddToHead( -34);
		ls1.AddToEnd( 1);
		ls1.AddToHead( 556);
		ls1.AddToEnd( 3);
		ls1.AddSomeNode( 3, 996);
		ls1.AddToHead( 2);
		ls1.AllShow();

		ls1.ChangeData( 996, 955);	//ֻ�޸ĵ�һ�����鵽�Ľڵ�����
		ls1.AllShow();

		//����û�еĽڵ�
		ls1.ChangeData( 888, 666);	//�ɹ���ʾ�����޴˽ڵ�
		ls1.AllShow();
	}

	//�޸���ͬ���ݵĽڵ㣨һ�θ�N����
	{
		List ls1;

		//��������ʽ�ĺ���д��
		ls1.AddToHead( -34);
		ls1.AddToEnd( 1);
		ls1.AddToHead( 556);
		ls1.AddToEnd( 3);
		ls1.AddSomeNode( 3, 996);
		ls1.AddToHead( 2);
		ls1.AllShow();

		//*��ʽ1��	���Ƽ���
		ls1.ChangeSomeData( 996, 955);
		ls1.AllShow();
		//��������û�е�����
		ls1.ChangeSomeData( 22, 33);
		ls1.AllShow();

		//*��ʽ2��	���鷳��Щ��
		ls1.ChangeSomeData2( 955, 996);
		ls1.AllShow();
		//��������û�е�����
		ls1.ChangeSomeData2( 22, 33);
		ls1.AllShow();
	}

	//ͷɾ��
	{
		List ls1;

		ls1.AddToHead( -34);
		ls1.AddToEnd( 1);
		ls1.AddToHead( 556);
		ls1.AddToEnd( 3);
		ls1.AddSomeNode( 3, 996);
		ls1.AddToHead( 2);
		ls1.AllShow();

		ls1.DeleteHead();
		ls1.AllShow();

		//����û�нڵ�ʱͷɾ��
		List ls2;
		ls2.AllShow();
		ls2.DeleteHead();
		ls2.AllShow();

		//����ֻ��һ���ڵ�ʱͷɾ��
		cout << "\n����Ϊ1�ڵ�ͷɾ����\n";
		ls2.InsertNodeByIndex( 0, 3);
		ls2.AllShow();
		ls2.DeleteHead();
		ls2.AllShow();
	}

	//βɾ��
	{
		List ls1;

		ls1.AddToHead( 4);
		ls1.AddToEnd( 2);
		ls1.AddToHead( 5);
		ls1.AddToEnd( 3);
		ls1.AllShow();

		ls1.DeleteEnd();
		ls1.AllShow();

		ls1.DeleteEnd();
		ls1.DeleteHead();
		ls1.AllShow();
		//����ֻ����һ���ڵ�ʱ
		ls1.DeleteEnd();
		ls1.AllShow();
		//��������û�нڵ�ʱ
		ls1.DeleteEnd();
		ls1.AllShow();
	}

	//ɾ��ָ�����ݽڵ㣨һ��ɾһ����
	{
		List ls2;

		ls2.AddToHead( 4);
		ls2.AddToEnd( 2);
		ls2.AddToHead( 5);
		ls2.AddToEnd( 3);
		ls2.AllShow();

		if (ls2.DeleteOneByData(2) == NULL)
			printf("\n���޴˽ڵ�\n");
		ls2.AllShow();

		//����ͷɾ��
		if (ls2.DeleteOneByData(5) == NULL)
			printf("\n���޴˽ڵ�\n");
		ls2.AllShow();

		//����βɾ��
		if (ls2.DeleteOneByData(3) == NULL)
			printf("\n���޴˽ڵ�\n");
		ls2.AllShow();

		//����ɾ�������ڵĽڵ�
		if (ls2.DeleteOneByData(3) == NULL)
			printf("\n���޴˽ڵ�\n");
		ls2.AllShow();
	}

	//ɾ��ָ�����ݽڵ㣨һ��ɾ������ظ��ģ�
	{
		List ls1;

		ls1.AddToHead( 4);
		ls1.AddToHead( 5);
		ls1.AddToEnd( 2);
		ls1.AddToEnd( 2);
		ls1.AddToHead( 5);
		ls1.AddToEnd( 3);
		ls1.AllShow();

		ls1.DeleteAllByData( 2);
		ls1.AllShow();

		ls1.DeleteAllByData( 5);		
		ls1.AllShow();
		//ɾ�������ڵ�
		ls1.DeleteAllByData(6);
		ls1.AllShow();
	}

	//ɾ����Ӧ�±�ڵ㣨һ��ɾһ����
	{
		List ls1;

		ls1.AddToHead( 4);
		ls1.AddToHead( 5);
		ls1.AddToEnd( 2);
		ls1.AddToEnd( 2);
		ls1.AddToHead( 5);
		ls1.AddToEnd( 3);
		ls1.AllShow();
		printf("\n����ɾ����Ӧ�±�ڵ�\n");
		//����ͷɾ��
		ls1.DeleteDataByIndex( 0);
		ls1.AllShow();
		//����ɾ�������ڵ��±�
		ls1.DeleteDataByIndex( 10);
		ls1.AllShow();
		
		ls1.DeleteDataByIndex( 4);
		ls1.AddToEnd(7);
		ls1.AllShow();
		ls1.DeleteDataByIndex( 1);
		ls1.DeleteDataByIndex( 1);
		ls1.DeleteDataByIndex( 1);
		ls1.DeleteDataByIndex(1);
		ls1.AllShow();

		//*�����⣩����ֻ��һ���ڵ�ʱ�������±�Ϊ1����ʦ����Ƶ��û������߽�ֵ�Ŀ���
		ls1.DeleteDataByIndex( 1);
	}

	//�������ڵ����ݣ��������ݲ��ң�
	{
		List ls1;

		ls1.AddToHead( 4);
		ls1.AddToHead( 5);
		ls1.AddToEnd( 2);
		ls1.AddToEnd( 2);
		ls1.AddToHead( 5);
		ls1.AddToEnd( 3);
		ls1.AllShow();

		ls1.SwapByData( 5, 3);	//�����ԣ����ַ�ʽ���ɹ���
		ls1.AllShow();			//���ظ����ݵĻ����������ǵ�һ�����鵽������
	}

	//�������ڵ����ݣ������±���ң�
	{
		List ls1;

		ls1.AddToHead( 4);
		ls1.AddToHead( 5);
		ls1.AddToEnd( 2);
		ls1.AddToEnd( 2);
		ls1.AddToHead( 5);
		ls1.AddToEnd( 3);
		ls1.AllShow();

		ls1.SwapByIndex( 0, 3);
		ls1.AllShow();

		ls1.SwapByIndex( 0, 5);
		ls1.AllShow();
		//�����±곬���ڵ���
		ls1.SwapByIndex( 6, 9);
		ls1.AllShow();
	}

	//�������ڵ�ָ��ָ��
	{	//����ʱ���������ǵ����������������ۣ�
		List ls1;

		ls1.AddToHead( 4);
		ls1.AddToHead( 5);
		ls1.AllShow();
		//ͷβ�����������ڵ�ʱ
		ls1.SwapByChangePoint( 0, 1);
		ls1.AllShow();

		ls1.AddToHead( 3);
		ls1.AddToHead( 8);
		ls1.AllShow();
		//ͷβ����������ڵ�ʱ
		ls1.SwapByChangePoint( 0, 3);
		ls1.AllShow();

		ls1.AddToEnd( 1);
		ls1.AddToEnd( 9);
		ls1.AllShow();
		//ͷ-�м佻��������ʱ
		ls1.SwapByChangePoint( 0, 1);
		ls1.AllShow();
		//ͷ-�м佻����������ʱ
		ls1.SwapByChangePoint( 0, 4);
		ls1.AllShow();

		ls1.AddToEnd( 18);
		ls1.AddToHead( 32);
		ls1.AllShow();
		//β-�м佻��:����ʱ
		ls1.SwapByChangePoint( 6, 7);
		ls1.AllShow();
		ls1.AddToEnd( 77);
		ls1.AddToHead( 45);
		ls1.AllShow();
		//β-�м佻��:������ʱ
		ls1.SwapByChangePoint( 1, 9);
		ls1.AllShow();

		ls1.AddToEnd( 25);
		ls1.AllShow();
		//�м�-�м佻��������
		ls1.SwapByChangePoint( 4, 5);
		ls1.AllShow();
		ls1.AddToEnd( 27);
		ls1.AddToHead( 35);
		ls1.AllShow();
		//�м�-�м佻����������
		ls1.SwapByChangePoint( 1, 9);
		ls1.AllShow();
	}

	//��ת����2�ַ�ʽ����ԭ�ط�ת��
	{
		List ls1;

		ls1.AddToHead( 2);
		ls1.AddToHead( 1);
		ls1.AddToEnd( 3);
		ls1.AddToEnd( 4);
		ls1.AddToHead( 0);
		ls1.AddToEnd( 5);
		ls1.AllShow();
		//���ݷ�ת
		ls1.ReverseByData();
		ls1.AllShow();

		ls1.AddToEnd( -1);
		ls1.AddToHead( 6);
		ls1.AllShow();
		//�ڵ㷭ת
		ls1.ReverseByPoint();
		ls1.AllShow();

		ls1.AddToEnd( 7);
		ls1.AddToHead( -2);
		ls1.AllShow();
	}

	//��ת���������ռ䣩���߼����������������ࣩ
	{
		List ls1;

		ls1.AddToHead( 2);
		ls1.AddToHead( 1);
		ls1.AddToEnd( 3);
		ls1.AddToEnd( 4);
		ls1.AddToHead( 0);
		ls1.AddToEnd( 5);
		ls1.AddToEnd( 6);
		ls1.AddToEnd( 7);
		ls1.AddToEnd( 8);
		ls1.AllShow();
		//��ת
		ls1.ReverseByHelpSpace();
		ls1.AllShow();

		ls1.AddToEnd( -1);
		ls1.AddToHead( 9);
		ls1.AllShow();
		//��Ӻ��ٷ�ת
		ls1.ReverseByHelpSpace();
		ls1.AllShow();
	}


	system("pause>0");
	return 0;
}
