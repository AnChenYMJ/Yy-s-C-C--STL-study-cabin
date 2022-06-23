#pragma once
#include <iostream>
using namespace std;


struct Node
{	//命名规范：m_p g_p m是My缩写，代表成员，g代表全局变量，p代表指针类型
	int m_iData;			//记录数据
	struct Node* m_pNext;	//记录下一节点地址
	struct Node* m_pPre;	//记录上一节点地址
};

class SX
{
private:
public:
	struct Node* g_pHead;	//记录头节点的指针
	struct Node* g_pEnd;	//记录尾节点的指针
	int	g_iNodeCount;		//节点计数

private:
	//遍历释放
	void FreeList();

public:
	SX();
	~SX();

public:
	//增：尾添加
	void AddToEnd(int ipData);
	//增：头添加
	void AddToHead(int ipData);
	//增：指定下标添加节点（N个）
	void InsertNodeByIndex(int Index, int iCount, int ipData);
	//增：指定数据前添加节点（1个）
	void InsertNodeByData(int iValue, int ipData);
	//查：根据数据查找
	struct Node* GetByData(int iValue);
	//查：根据下标查找
	struct Node* GetByIndex(int Index);
	//删：删除节点（给其它函数调用的）
	void DeleteNode(struct Node* pTemp);
	//删：根据下标删除指定节点
	void DeleteByIndex(int Index);
	//删：根据数据删除指定节点（N个）
	void DeleteByData(int iValue);
	//改：修改指定数据（根据数据）（N个）
	void ChangeByData(int iValue, int ipData);
	//改：修改指定数据（根据下标）
	void ChangeByIndex(int Index, int ipData);
	//遍历打印(正向)
	void ShowZheng();
	//遍历打印(反向)
	void ShowFan();

};