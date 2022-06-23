#include "dl.h"


//这里说一下老师的修改顺序：
//1.结构体改成类、函数放进类中、给函数定义添加类名作用域
//2.添加访问修饰符
//3.删除当前类中函数的形参（因为变量已经是类内成员了）
//4.主函数中修改成对象调用
//5.malloc free 修改成：new申请空间、delete释放空间
//6.printf 修改成 cout

int main()
{
	List ls;

	//尾添加
	ls.AddToEnd( 5);
	ls.AddToEnd( 1);
	ls.AddToEnd( 3);
	ls.AddToEnd( 2);

	ls.AllShow();

	//对照 尾添加的二级指针使用解惑
	{
		int a = 0;
		ls.ceshi(a);
		printf("%d \n", a);
	}

	//对照 没有pEnd的尾添加演示
	{
		List ls1;		//出了{}就自动释放了，因为是局部变量

		ls1.AddToEndNopEnd(	51);
		ls1.AddToEndNopEnd( 52);
		ls1.AddToEndNopEnd( 53);
		ls1.AddToEndNopEnd( 54);
		ls1.AddToEndNopEnd( 55);

		ls1.AllShow();
	}

	//遍历释放	+	记录头尾的指针赋值NULL
	{
		List ls1;

		//ls.FreeList();	//释放时，这三个要在一起，释放完必须给头尾赋值NULL，否则之前测试没有赋值NULL的话，再遍历输出此链表，就运行异常了
		//ls.pHead = NULL;	//将这三个写在一个函数内即可
		//ls.pEnd = NULL;	//因为改成C++，这三个是私密成员无法调用，但已经确保无误了

		ls1.AddToEnd( 45);
		ls1.AddToEnd( 12);
		ls1.AddToEnd( 23);
		ls1.AddToEnd( 52);

		ls1.AllShow();

		//ls1.FreeListNULL();	//已经是私密成员，但已经确保有效了
	}

	//头添加
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

		ls1.AllShow();					//添加成功
	}

	//根据下标查找数据
	{
		List ls1;

		ls1.AddToHead( -5);
		ls1.AddToEnd( 61);
		ls1.AddToEnd( 11);
		ls1.AddToHead( -34);
		ls1.AddToEnd( 71);
		ls1.AllShow();

		//测试正常查找
		struct Node* pTemp = ls1.FindIndex(2);
		if (pTemp)
			printf("\n对应下标的数据：%d\n", pTemp->iData);
		else
			printf("\n输入下标错误\n");

		//测试下标过大
		pTemp = ls1.FindIndex( 5);
		if (pTemp)
			printf("\n对应下标的数据：%d\n", pTemp->iData);
		else
			printf("\n输入下标下标错误\n");

		//测试下标过小
		pTemp = ls1.FindIndex( -5);
		if (pTemp)
			printf("\n对应下标的数据：%d\n", pTemp->iData);
		else
			printf("\n输入下标下标错误\n");

	}

	//指定位置接入节点
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

		//测试输入过大下标
		ls1.InsertNodeByIndex( 11, 000);
		ls1.AllShow();

	}

	//一次增加数据为x的N个节点
	{
		List ls1;

		//可以根据需要改成头添加、尾添加、指定位置添加
		ls1.AddToHead( -34);
		ls1.AddToEnd( 1);
		ls1.AddToHead( 556);
		ls1.AddToEnd( 3);
		ls1.AddSomeNode( 3, 996);	//此处为尾添加
		ls1.AddToHead( 2);

		ls1.AllShow();

	}

	//修改指定节点数据（一次改一个）
	{
		List ls1;

		ls1.AddToHead( -34);
		ls1.AddToEnd( 1);
		ls1.AddToHead( 556);
		ls1.AddToEnd( 3);
		ls1.AddSomeNode( 3, 996);
		ls1.AddToHead( 2);
		ls1.AllShow();

		ls1.ChangeData( 996, 955);	//只修改第一个被查到的节点数据
		ls1.AllShow();

		//测试没有的节点
		ls1.ChangeData( 888, 666);	//成功提示：查无此节点
		ls1.AllShow();
	}

	//修改相同数据的节点（一次改N个）
	{
		List ls1;

		//有两种形式的函数写法
		ls1.AddToHead( -34);
		ls1.AddToEnd( 1);
		ls1.AddToHead( 556);
		ls1.AddToEnd( 3);
		ls1.AddSomeNode( 3, 996);
		ls1.AddToHead( 2);
		ls1.AllShow();

		//*方式1：	（推荐）
		ls1.ChangeSomeData( 996, 955);
		ls1.AllShow();
		//测试输入没有的数据
		ls1.ChangeSomeData( 22, 33);
		ls1.AllShow();

		//*方式2：	（麻烦了些）
		ls1.ChangeSomeData2( 955, 996);
		ls1.AllShow();
		//测试输入没有的数据
		ls1.ChangeSomeData2( 22, 33);
		ls1.AllShow();
	}

	//头删除
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

		//测试没有节点时头删除
		List ls2;
		ls2.AllShow();
		ls2.DeleteHead();
		ls2.AllShow();

		//测试只有一个节点时头删除
		cout << "\n以下为1节点头删除：\n";
		ls2.InsertNodeByIndex( 0, 3);
		ls2.AllShow();
		ls2.DeleteHead();
		ls2.AllShow();
	}

	//尾删除
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
		//测试只有有一个节点时
		ls1.DeleteEnd();
		ls1.AllShow();
		//测试链表没有节点时
		ls1.DeleteEnd();
		ls1.AllShow();
	}

	//删除指定数据节点（一次删一个）
	{
		List ls2;

		ls2.AddToHead( 4);
		ls2.AddToEnd( 2);
		ls2.AddToHead( 5);
		ls2.AddToEnd( 3);
		ls2.AllShow();

		if (ls2.DeleteOneByData(2) == NULL)
			printf("\n查无此节点\n");
		ls2.AllShow();

		//测试头删除
		if (ls2.DeleteOneByData(5) == NULL)
			printf("\n查无此节点\n");
		ls2.AllShow();

		//测试尾删除
		if (ls2.DeleteOneByData(3) == NULL)
			printf("\n查无此节点\n");
		ls2.AllShow();

		//测试删除不存在的节点
		if (ls2.DeleteOneByData(3) == NULL)
			printf("\n查无此节点\n");
		ls2.AllShow();
	}

	//删除指定数据节点（一次删除多个重复的）
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
		//删除不存在的
		ls1.DeleteAllByData(6);
		ls1.AllShow();
	}

	//删除对应下标节点（一次删一个）
	{
		List ls1;

		ls1.AddToHead( 4);
		ls1.AddToHead( 5);
		ls1.AddToEnd( 2);
		ls1.AddToEnd( 2);
		ls1.AddToHead( 5);
		ls1.AddToEnd( 3);
		ls1.AllShow();
		printf("\n测试删除对应下标节点\n");
		//测试头删除
		ls1.DeleteDataByIndex( 0);
		ls1.AllShow();
		//测试删除不存在的下标
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

		//*（特殊）测试只有一个节点时，输入下标为1，老师的视频里没有这个边界值的考量
		ls1.DeleteDataByIndex( 1);
	}

	//交换两节点数据（根据数据查找）
	{
		List ls1;

		ls1.AddToHead( 4);
		ls1.AddToHead( 5);
		ls1.AddToEnd( 2);
		ls1.AddToEnd( 2);
		ls1.AddToHead( 5);
		ls1.AddToEnd( 3);
		ls1.AllShow();

		ls1.SwapByData( 5, 3);	//经测试，两种方式都成功，
		ls1.AllShow();			//有重复数据的化，交换的是第一个被查到的数据
	}

	//交换两节点数据（根据下标查找）
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
		//测试下标超出节点数
		ls1.SwapByIndex( 6, 9);
		ls1.AllShow();
	}

	//交换两节点指针指向
	{	//测试时，尽量考虑到特殊情况（经验积累）
		List ls1;

		ls1.AddToHead( 4);
		ls1.AddToHead( 5);
		ls1.AllShow();
		//头尾交换：两个节点时
		ls1.SwapByChangePoint( 0, 1);
		ls1.AllShow();

		ls1.AddToHead( 3);
		ls1.AddToHead( 8);
		ls1.AllShow();
		//头尾交换：多个节点时
		ls1.SwapByChangePoint( 0, 3);
		ls1.AllShow();

		ls1.AddToEnd( 1);
		ls1.AddToEnd( 9);
		ls1.AllShow();
		//头-中间交换：相邻时
		ls1.SwapByChangePoint( 0, 1);
		ls1.AllShow();
		//头-中间交换：不相邻时
		ls1.SwapByChangePoint( 0, 4);
		ls1.AllShow();

		ls1.AddToEnd( 18);
		ls1.AddToHead( 32);
		ls1.AllShow();
		//尾-中间交换:相邻时
		ls1.SwapByChangePoint( 6, 7);
		ls1.AllShow();
		ls1.AddToEnd( 77);
		ls1.AddToHead( 45);
		ls1.AllShow();
		//尾-中间交换:不相邻时
		ls1.SwapByChangePoint( 1, 9);
		ls1.AllShow();

		ls1.AddToEnd( 25);
		ls1.AllShow();
		//中间-中间交换：相邻
		ls1.SwapByChangePoint( 4, 5);
		ls1.AllShow();
		ls1.AddToEnd( 27);
		ls1.AddToHead( 35);
		ls1.AllShow();
		//中间-中间交换：不相邻
		ls1.SwapByChangePoint( 1, 9);
		ls1.AllShow();
	}

	//翻转链表（2种方式）（原地翻转）
	{
		List ls1;

		ls1.AddToHead( 2);
		ls1.AddToHead( 1);
		ls1.AddToEnd( 3);
		ls1.AddToEnd( 4);
		ls1.AddToHead( 0);
		ls1.AddToEnd( 5);
		ls1.AllShow();
		//数据翻转
		ls1.ReverseByData();
		ls1.AllShow();

		ls1.AddToEnd( -1);
		ls1.AddToHead( 6);
		ls1.AllShow();
		//节点翻转
		ls1.ReverseByPoint();
		ls1.AllShow();

		ls1.AddToEnd( 7);
		ls1.AddToHead( -2);
		ls1.AllShow();
	}

	//翻转链表（辅助空间）（逻辑更清晰，代码更简洁）
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
		//翻转
		ls1.ReverseByHelpSpace();
		ls1.AllShow();

		ls1.AddToEnd( -1);
		ls1.AddToHead( 9);
		ls1.AllShow();
		//添加后再翻转
		ls1.ReverseByHelpSpace();
		ls1.AllShow();
	}


	system("pause>0");
	return 0;
}
