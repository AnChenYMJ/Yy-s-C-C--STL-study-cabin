#include "SX.h"


int main()
{
	//尾添加、正反向遍历、释放
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
	//头添加、中间添加（N个）
	{
		SX s;
		//头添加
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
		//中间添加(头)
		s.InsertNodeByIndex(0, 1, 996);
		s.ShowZheng();
		s.AddToEnd(5);
		//中间添加(尾)
		s.InsertNodeByIndex(11, 2, 996);
		s.ShowZheng();
		s.AddToHead(-5);
		s.AddToEnd(6);
		//中间添加(中间)
		s.InsertNodeByIndex(6, 3, 996);
		s.ShowZheng();
		s.AddToHead(-6);
		s.AddToEnd(7);
		s.ShowZheng();
		//测试不存在的下标
		s.InsertNodeByIndex(31, 3, 996);
		s.ShowZheng();
	}
	//指定数据位置添加节点
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
		//测试不存在的数据
		s.InsertNodeByData(13, 996);
		s.ShowZheng();
	}
	//查找数据（根据下标、数据）、修改指定节点（根据数据（N个）、根据下标）
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
		//查：根据数据查找
		struct Node* p = s.GetByData(0);
		if (p != NULL)
			printf("\n找到数据： %3d\n", p->m_iData);
		else
			printf("\n未找到该数据\n");

		s.AddToHead(-5);
		s.AddToEnd(5);
		s.ShowZheng();
		p = s.GetByData(11);
		if (p != NULL)
			printf("\n找到数据： %3d\n", p->m_iData);
		else
			printf("\n未找到该数据\n");
		//查：根据下标
		p = s.GetByIndex(10);
		if (p != NULL)
			printf("\n找到下标数据： %3d\n", p->m_iData);
		else
			printf("\n未找到该数据\n");

		s.AddToHead(-6);
		s.AddToEnd(6);
		s.ShowZheng();
		p = s.GetByIndex(13);
		if (p != NULL)
			printf("\n找到下标数据： %3d\n", p->m_iData);
		else
			printf("\n未找到该数据\n");
		//改：根据下标
		s.ChangeByIndex(0, 14);
		s.ShowZheng();
		s.AddToHead(0);
		s.AddToEnd(0);
		s.ShowZheng();
		s.ChangeByIndex(14, 14);
		s.ShowZheng();
		s.ChangeByIndex(16, 16);
		s.ShowZheng();
		//改：根据数据
		s.ChangeByData(0, 26);
		s.ShowZheng();

		s.AddToHead(0);
		s.AddToEnd(0);
		s.ChangeByData(22, 27);
		s.ShowZheng();
	}
	//删除指定下标节点（根据下标）
	{
		SX s;
		s.AddToEnd(0);
		s.AddToHead(-1);
		s.AddToEnd(1);
		s.AddToHead(-2);
		s.AddToEnd(2);
		s.ShowZheng();
		//头删除
		s.DeleteByIndex(0);
		s.ShowZheng();
		//尾删除
		s.AddToHead(-2);
		s.AddToEnd(3);
		s.ShowZheng();
		s.DeleteByIndex(5);
		s.ShowZheng();
		//中间删除
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
	//删除指定下标节点（根据数据）（N个）
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
