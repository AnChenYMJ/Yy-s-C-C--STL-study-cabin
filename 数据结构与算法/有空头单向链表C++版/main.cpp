#include "YK.h"

int main()
{
	int iNodeCount = 0;	//计数,本程序为了方便，把空头的数据位用来计数
	//可以把空头与计数写到全局区中，这样使用更方便，但是学习为了理解，还是放到主函数里

	//空头(指针类型对比)
	{
		
		//对比会发现，指针类型的创建，需要malloc空间、赋值、不使用了要手动释放
		//相对麻烦一些
		struct Node* pHead = (struct Node*)malloc(sizeof(struct Node));
		if (pHead != NULL)
		{
			pHead->iData = 0;
			pHead->iNext = NULL;
		}
		free(pHead);
	}
	//尾添加：AddToTail（）
	{
		YK yk;

		yk.AddToTail(2);
		yk.AddToTail(5);
		yk.AddToTail(1);
		yk.AddToTail(3);

		yk.AllShow();
	}
	//释放链表空间
	{
		YK yk;
		yk.AllShow();

		yk.AddToTail(5);
		yk.AddToTail(1);
		yk.AllShow();

	}
	//头添加
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
	//指定数据后添加（按数据查找、1次加1个）
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
	//指定下标位置添加节点(一个与N个)
	{
		YK yk;

		yk.AddToHead(3);
		yk.AddToHead(1);
		yk.AddBeHandData(1, 7);
		yk.AllShow();
		yk.AddBeHandData(3, 9);
		yk.AllShow();
		//插入一个节点
		yk.AddByIndex(4, 2);
		yk.AllShow();
		yk.AddToHead(33);
		yk.AddBeHandData(33, 66);
		yk.AddToTail(22);
		yk.AllShow();
		yk.AddByIndex(0, 26);
		yk.AllShow();
		//插入N个节点
		yk.AddByIndex(9, 3, 996);
		yk.AddByIndex(0, 1, 996);
		yk.AllShow();
		yk.AddToTail(22);
		yk.AddToHead(33);
		yk.AllShow();
	}
	//查找结点
	{
		YK yk;
		yk.AddToHead(3);
		yk.AddToHead(1);
		yk.AddBeHandData(1, 7);
		yk.AllShow();
		//根据数据查找
		struct Node* pt = yk.FindNodeByData(3);
		if (pt == NULL)
			cout << "\n该数据不存在\n";
		else
			cout << "\n找到数据： " << pt->iData << "\n";

		yk.AddByIndex(0, 26);
		yk.AddByIndex(4, 27);
		yk.AllShow();
		//根据下标查找
		pt = yk.FindNodeByIndex(4);
		if (pt == NULL)
			cout << "\n该下标错误/指针为NULL\n";
		else
			cout << "\n找到数据： " << pt->iData << "\n";
		//
		pt = yk.FindNodeByIndex(0);
		if (pt == NULL)
			cout << "\n该下标错误/指针为NULL\n";
		else
			cout << "\n找到数据： " << pt->iData << "\n";
		//测试下标超界
		pt = yk.FindNodeByIndex(5);
		if (pt == NULL)
			cout << "\n该下标错误/指针为NULL\n";
		else
			cout << "\n找到数据： " << pt->iData << "\n";
		//测试下标过小
		pt = yk.FindNodeByIndex(-1);
		if (pt == NULL)
			cout << "\n该下标错误/指针为NULL\n";
		else
			cout << "\n找到数据： " << pt->iData << "\n";

		yk.AddByIndex(0, 45);
		yk.AddByIndex(4, 35);
		yk.AllShow();
	}
	//修改节点数据（根据下标）
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

		//根据下标修改
		yk.ChangeByIndex(0, 5);
		yk.ChangeByIndex(7, 5);
		yk.AllShow();

		//根据数据修改（N个）
		yk.ChangeByData(66, 11);
		yk.AllShow();
		yk.ChangeByData(5, 996);
		yk.AllShow();
		yk.ChangeByData(996, 27);
		yk.AllShow();
	}
	//删除指定下标节点
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
	//删除指定数据节点（N个）
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
	//删除重复的数据（去重）
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

	//想要关掉控制台的，请按任意键继续的提示，在左侧，项目》链接器》系统》子系统》控制台 设置为：未设置
	system("pause>0");
	return 0;
}