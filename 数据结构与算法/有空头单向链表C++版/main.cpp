#include "YK.h"

int main()
{
	int iNodeCount = 0;	//����,������Ϊ�˷��㣬�ѿ�ͷ������λ��������
	//���԰ѿ�ͷ�����д��ȫ�����У�����ʹ�ø����㣬����ѧϰΪ����⣬���Ƿŵ���������

	//��ͷ(ָ�����ͶԱ�)
	{
		
		//�ԱȻᷢ�֣�ָ�����͵Ĵ�������Ҫmalloc�ռ䡢��ֵ����ʹ����Ҫ�ֶ��ͷ�
		//����鷳һЩ
		struct Node* pHead = (struct Node*)malloc(sizeof(struct Node));
		if (pHead != NULL)
		{
			pHead->iData = 0;
			pHead->iNext = NULL;
		}
		free(pHead);
	}
	//β��ӣ�AddToTail����
	{
		YK yk;

		yk.AddToTail(2);
		yk.AddToTail(5);
		yk.AddToTail(1);
		yk.AddToTail(3);

		yk.AllShow();
	}
	//�ͷ�����ռ�
	{
		YK yk;
		yk.AllShow();

		yk.AddToTail(5);
		yk.AddToTail(1);
		yk.AllShow();

	}
	//ͷ���
	{
		YK yk;
		yk.AddToHead(3);
		yk.AddToHead(1);
		yk.AddToHead(2);
		yk.AddToHead(5);

		yk.AllShow();

		yk.AddToTail(7);

		yk.AllShow();
	}
	//ָ�����ݺ���ӣ������ݲ��ҡ�1�μ�1����
	{
		YK yk;

		yk.AddToHead(3);
		yk.AddToHead(1);
		yk.AddBeHandData(1, 7);
		yk.AllShow();
		yk.AddBeHandData(3, 9);
		yk.AllShow();
		yk.AddBeHandData(9, 23);
		yk.AllShow();
		yk.AddToTail(2);
		yk.AllShow();

		yk.AddBeHandData(11, 22);
		yk.AllShow();
	}
	//ָ���±�λ����ӽڵ�(һ����N��)
	{
		YK yk;

		yk.AddToHead(3);
		yk.AddToHead(1);
		yk.AddBeHandData(1, 7);
		yk.AllShow();
		yk.AddBeHandData(3, 9);
		yk.AllShow();
		//����һ���ڵ�
		yk.AddByIndex(4, 2);
		yk.AllShow();
		yk.AddToHead(33);
		yk.AddBeHandData(33, 66);
		yk.AddToTail(22);
		yk.AllShow();
		yk.AddByIndex(0, 26);
		yk.AllShow();
		//����N���ڵ�
		yk.AddByIndex(9, 3, 996);
		yk.AddByIndex(0, 1, 996);
		yk.AllShow();
		yk.AddToTail(22);
		yk.AddToHead(33);
		yk.AllShow();
	}
	//���ҽ��
	{
		YK yk;
		yk.AddToHead(3);
		yk.AddToHead(1);
		yk.AddBeHandData(1, 7);
		yk.AllShow();
		//�������ݲ���
		struct Node* pt = yk.FindNodeByData(3);
		if (pt == NULL)
			cout << "\n�����ݲ�����\n";
		else
			cout << "\n�ҵ����ݣ� " << pt->iData << "\n";

		yk.AddByIndex(0, 26);
		yk.AddByIndex(4, 27);
		yk.AllShow();
		//�����±����
		pt = yk.FindNodeByIndex(4);
		if (pt == NULL)
			cout << "\n���±����/ָ��ΪNULL\n";
		else
			cout << "\n�ҵ����ݣ� " << pt->iData << "\n";
		//
		pt = yk.FindNodeByIndex(0);
		if (pt == NULL)
			cout << "\n���±����/ָ��ΪNULL\n";
		else
			cout << "\n�ҵ����ݣ� " << pt->iData << "\n";
		//�����±곬��
		pt = yk.FindNodeByIndex(5);
		if (pt == NULL)
			cout << "\n���±����/ָ��ΪNULL\n";
		else
			cout << "\n�ҵ����ݣ� " << pt->iData << "\n";
		//�����±��С
		pt = yk.FindNodeByIndex(-1);
		if (pt == NULL)
			cout << "\n���±����/ָ��ΪNULL\n";
		else
			cout << "\n�ҵ����ݣ� " << pt->iData << "\n";

		yk.AddByIndex(0, 45);
		yk.AddByIndex(4, 35);
		yk.AllShow();
	}
	//�޸Ľڵ����ݣ������±꣩
	{
		YK yk;
		yk.AddToHead(3);
		yk.AddToHead(1);
		yk.AddBeHandData(1, 7);
		yk.AddBeHandData(3, 7);
		yk.AddByIndex(4, 2);
		yk.AddToHead(33);
		yk.AddBeHandData(33, 66);
		yk.AddToTail(66);
		yk.AllShow();

		//�����±��޸�
		yk.ChangeByIndex(0, 5);
		yk.ChangeByIndex(7, 5);
		yk.AllShow();

		//���������޸ģ�N����
		yk.ChangeByData(66, 11);
		yk.AllShow();
		yk.ChangeByData(5, 996);
		yk.AllShow();
		yk.ChangeByData(996, 27);
		yk.AllShow();
	}
	//ɾ��ָ���±�ڵ�
	{
		YK yk;
		yk.AddToTail(1);
		yk.AddToTail(5);
		yk.AddToHead(3);
		yk.AllShow();

		yk.DeleteByIndex(0);
		yk.AllShow();

		yk.AddToTail(9);
		yk.AllShow();
		yk.DeleteByIndex(2);
		yk.AllShow();
		yk.AddToTail(4);
		yk.AllShow();
	}
	//ɾ��ָ�����ݽڵ㣨N����
	{
		YK yk;
		yk.AddToTail(1);
		yk.AddToTail(5);
		yk.AddToHead(3);
		yk.AddToTail(5);
		yk.AddToTail(5);
		yk.AddToHead(1);
		yk.AddToHead(1);
		yk.AllShow();

		yk.DeleteAllByData(1);
		yk.AllShow();

		yk.AddToHead(3);
		yk.DeleteAllByData(5);
		yk.AllShow();

		yk.AddToTail(2);
		yk.DeleteAllByData(3);
		yk.AllShow();

		yk.DeleteAllByData(2);
		yk.AllShow();
	}
	//ɾ���ظ������ݣ�ȥ�أ�
	{
		YK yk;
		yk.AddToTail(1);
		yk.AddToTail(5);
		yk.AddToHead(3);
		yk.AddToTail(5);
		yk.AddToTail(5);
		yk.AddToHead(1);
		yk.AddToHead(1);
		yk.AddToHead(3);
		yk.AddToHead(2);
		yk.AllShow();
		yk.DeleteSame();
		yk.AllShow();
		yk.AddToTail(5);
		yk.AddToHead(1);
		yk.AllShow();
		yk.DeleteSame();
		yk.AllShow();
	}

	//��Ҫ�ص�����̨�ģ��밴�������������ʾ������࣬��Ŀ����������ϵͳ����ϵͳ������̨ ����Ϊ��δ����
	system("pause>0");
	return 0;
}