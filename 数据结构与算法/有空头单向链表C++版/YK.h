#pragma once
#include <iostream>
#include <cstdio>

using namespace std;

struct Node
{
	int iData;
	struct Node* iNext;
};


class YK
{
private:
	Node stHead;
	void FreeList();//释放空间

public:
	YK();	//构造函数
	~YK();	//析构函数
public:
	
	//增：尾添加
	void AddToTail(int pData);
	//增：头添加
	void AddToHead(int pData);
	//增：指定数据后添加（按数据查找、1次加1个）
	void AddBeHandData(int iPosData, int pData);
	//增：指定下标位置添加节点(1个)
	void AddByIndex(int iPosIndex, int pData);
	//增：指定下标位置添加节点(N个)
	void AddByIndex(int iPosIndex, int pCount, int pData);
	//删：删除指定下标节点
	void DeleteByIndex(int pIndex);
	//删：删除指定数据节点（N个）
	void DeleteAllByData(int pValue);
	//删：删除重复的数据（去重）
	void DeleteSame();
	//查找结点（根据数据）（找到第一个出现的）
	struct Node* FindNodeByData(int pData);
	//查找结点（根据下标）
	struct Node* FindNodeByIndex(int pIndex);
	//修改节点数据（根据下标）
	void ChangeByIndex(int pIndex, int pValue);
	//修改节点数据（根据数据）
	void ChangeByData(int pData, int pValue);
	//遍历打印
	void AllShow();
	

};
