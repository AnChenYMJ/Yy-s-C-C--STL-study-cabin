#pragma once	//防止头文件重复包含（也可以用endif那种方式）
#include <iostream>
using namespace std;

//一个解决方案中可以有多个项目 右击解决方案->添加项目
//对该项目右击 能够生成-调试-设为启动项

//因为是C改C++版，多余的注释我就删掉了，详情看C版的注释

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
	void FreeList();				//遍历释放
	void FreeListNULL();			//遍历释放 + 记录头尾的指针赋值NULL

public:
	List();
	~List();

public:
	void AddToEnd(int pData);		//*增：尾添加
	void ceshi(int b);				//（不必要）对照 尾添加的二级指针使用解惑
	void AddToEndNopEnd( int pData);//（不必要）pEND的作用(此函数演示没有pEnd的情况)
	void AddToHead( int pData);		//*增：头添加
	void InsertNodeByIndex( int pIndex, int pData);	//*增：指定位置接入节点
	void AddSomeNode( int pCount, int pData);		//*增：一次增加数据为x的N个节点
	void DeleteHead();				//*删：头删除
	void DeleteEnd();				//*删：尾删除
	struct Node* DeleteOneByData( int iData);		//*删：删除指定数据节点	 (一次删一个)
	void DeleteAllByData( int iData);				//*删：删除指定数据节点	（一次删除多个重复的）
	void DeleteDataByIndex( int pIndex);			//*删：根据下标删除节点	 (一次删一个)
	void ChangeData(int iEesData, int pDesData);	//*改：修改指定节点数据	（一次修改1个）
	void ChangeSomeData( int iEesData, int pDesData);//*改：修改相同数据的节点	（一次修改多个）方式1：（推荐）
	void ChangeSomeData2( int iEesData, int pDesData);//改：修改相同数据的节点	（一次修改多个）方式2：（麻烦了些）
	struct Node* FindIndex( int pIndex);			//*查：根据下标查找指定节点
	struct Node* FindByData( int pData);			//*查：根据数据查找指定节点
	void SwapByData( int pData1, int pData2);		//*交换两节点数据（根据数据查找）两种方式
	void SwapByIndex( int pIndex1, int pIndex2);	//*交换两节点数据（根据下标查找）两种方式
	void SwapByChangePoint( int pIndex1, int pIndex2);//*交换指针指向（麻烦形式的交换节点）
	void ReverseByData();			//*反转链表（数据翻转）
	void ReverseByPoint();			//*反转链表（节点翻转）
	void ReverseByHelpSpace();		//*翻转链表（辅助空间）
	int GetListNodeCount();			//链表节点数计数
	void AllShow();					//遍历打印
};

