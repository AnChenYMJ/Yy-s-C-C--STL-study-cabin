#include "SX.h"


int main()
{
	//β��ӡ�������������ͷ�
	{
		SX s;
		s.AddToEnd(1);
		s.AddToEnd(2);
		s.AddToEnd(3);
		s.AddToEnd(4);
		s.AddToEnd(5);

		s.ShowZheng();
		s.AddToEnd(6);
		s.ShowFan();
	}
	//ͷ��ӡ��м���ӣ�N����
	{
		SX s;
		//ͷ���
		s.AddToEnd(0);
		s.AddToHead(-1);
		s.AddToEnd(1);
		s.AddToHead(-2);
		s.AddToEnd(2);
		s.AddToHead(-3);
		s.AddToEnd(3);
		s.AddToHead(-4);
		s.AddToEnd(4);

		s.ShowZheng();
		s.ShowFan();
		//�м����(ͷ)
		s.InsertNodeByIndex(0, 1, 996);
		s.ShowZheng();
		s.AddToEnd(5);
		//�м����(β)
		s.InsertNodeByIndex(11, 2, 996);
		s.ShowZheng();
		s.AddToHead(-5);
		s.AddToEnd(6);
		//�м����(�м�)
		s.InsertNodeByIndex(6, 3, 996);
		s.ShowZheng();
		s.AddToHead(-6);
		s.AddToEnd(7);
		s.ShowZheng();
		//���Բ����ڵ��±�
		s.InsertNodeByIndex(31, 3, 996);
		s.ShowZheng();
	}
	//ָ������λ����ӽڵ�
	{
		SX s;
		s.AddToEnd(0);
		s.AddToHead(-1);
		s.AddToEnd(1);
		s.AddToHead(-2);
		s.AddToEnd(2);
		s.AddToHead(-3);
		s.AddToEnd(3);
		s.AddToHead(-4);
		s.AddToEnd(4);

		s.ShowZheng();

		s.InsertNodeByData(0, 996);
		s.ShowZheng();

		s.AddToHead(-5);
		s.AddToEnd(5);
		s.InsertNodeByData(1, 996);
		s.ShowZheng();
		//���Բ����ڵ�����
		s.InsertNodeByData(13, 996);
		s.ShowZheng();
	}
	//�������ݣ������±ꡢ���ݣ����޸�ָ���ڵ㣨�������ݣ�N�����������±꣩
	{
		SX s;
		s.AddToEnd(0);
		s.AddToHead(-1);
		s.AddToEnd(1);
		s.AddToHead(-2);
		s.AddToEnd(2);
		s.AddToHead(-3);
		s.AddToEnd(3);
		s.AddToHead(-4);
		s.AddToEnd(4);

		s.ShowZheng();
		//�飺�������ݲ���
		struct Node* p = s.GetByData(0);
		if (p != NULL)
			printf("\n�ҵ����ݣ� %3d\n", p->m_iData);
		else
			printf("\nδ�ҵ�������\n");

		s.AddToHead(-5);
		s.AddToEnd(5);
		s.ShowZheng();
		p = s.GetByData(11);
		if (p != NULL)
			printf("\n�ҵ����ݣ� %3d\n", p->m_iData);
		else
			printf("\nδ�ҵ�������\n");
		//�飺�����±�
		p = s.GetByIndex(10);
		if (p != NULL)
			printf("\n�ҵ��±����ݣ� %3d\n", p->m_iData);
		else
			printf("\nδ�ҵ�������\n");

		s.AddToHead(-6);
		s.AddToEnd(6);
		s.ShowZheng();
		p = s.GetByIndex(13);
		if (p != NULL)
			printf("\n�ҵ��±����ݣ� %3d\n", p->m_iData);
		else
			printf("\nδ�ҵ�������\n");
		//�ģ������±�
		s.ChangeByIndex(0, 14);
		s.ShowZheng();
		s.AddToHead(0);
		s.AddToEnd(0);
		s.ShowZheng();
		s.ChangeByIndex(14, 14);
		s.ShowZheng();
		s.ChangeByIndex(16, 16);
		s.ShowZheng();
		//�ģ���������
		s.ChangeByData(0, 26);
		s.ShowZheng();

		s.AddToHead(0);
		s.AddToEnd(0);
		s.ChangeByData(22, 27);
		s.ShowZheng();
	}
	//ɾ��ָ���±�ڵ㣨�����±꣩
	{
		SX s;
		s.AddToEnd(0);
		s.AddToHead(-1);
		s.AddToEnd(1);
		s.AddToHead(-2);
		s.AddToEnd(2);
		s.ShowZheng();
		//ͷɾ��
		s.DeleteByIndex(0);
		s.ShowZheng();
		//βɾ��
		s.AddToHead(-2);
		s.AddToEnd(3);
		s.ShowZheng();
		s.DeleteByIndex(5);
		s.ShowZheng();
		//�м�ɾ��
		s.AddToHead(-3);
		s.AddToEnd(3);
		s.ShowZheng();
		s.DeleteByIndex(3);
		s.ShowZheng();
		s.AddToHead(-4);
		s.AddToEnd(4);
		s.ShowZheng();
		s.ShowFan();
	}
	//ɾ��ָ���±�ڵ㣨�������ݣ���N����
	{
		SX s;
		s.AddToEnd(2);
		s.AddToHead(2);
		s.AddToEnd(1);
		s.AddToHead(2);
		s.AddToEnd(2);
		s.ShowZheng();

		s.DeleteByData(2);
		s.ShowZheng();

		s.AddToHead(5);
		s.AddToEnd(1);
		s.ShowZheng();
		s.ShowFan();

		s.DeleteByData(1);
		s.ShowZheng();
	}

	system("pause>0");
	return 0;
}
