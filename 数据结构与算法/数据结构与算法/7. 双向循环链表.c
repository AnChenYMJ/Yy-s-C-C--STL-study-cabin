#include <stdio.h>
#include <stdlib.h>

//双向循环链表简介、总结
void AAA()
{
	if (1)
	{
	//本课时双向循环链采用有空头链表
	//双向循环链表则是头节点的前一位就是链表的尾节点，即尾节点与头节点相连，形成环状
	//双向循环链表是所有基础链表里的巅峰，最灵活、最好用的结构
	//单向链表也能修改成循环链表
	//此前学的链表结构，会发现越来越好用，也越来越简单。
	//双向循环链表即使只有一个节点，依然呈环状，也就是说空头的两个地址成员记录自己的地址

	//面试题：怎样判断链表中是否有环：快慢指针
	//面试题：链表和数组的空间利用率怎样？看情况，比如链表节点只有两个成员，一个数据位int类型、一个地址位。那利用率只有50%，不如数组，但是如果数据位够多，利用率就高一些
		//数组的空间是一次申请好的，如果没装满，那利用率就不足100%。比如有9个int类型空间，只装了6个，那利用率就是2/3.

	//pEnd是为了使链表代码简洁、效率更高，尾节点的更替都要切换pEnd指向
	//空头是为了使书写代码逻辑更简洁，不影响效率
	}
}

struct Node
{
	int iData;
	struct Node* pNext;
	struct Node* pPre;
};

//增：尾添加
void AddToEnd(struct Node* STHead, int* ICount, int IData);
//增：头添加
void AddToHead(struct Node* STHead, int* ICount, int IData);
//增：指定下标位置添加节点
void InsertByIndex(struct Node* STHead, int* ICount, int IIndex, int IData);
//增：指定下标位置添加节点(N个)
void InsertSomeByIndex(struct Node* STHead, int* ICount, int IIndex, int iNodeCount, int IData);
//增：指定数据位置添加节点
void InsertByData(struct Node* STHead, int* ICount, int IValue, int IData);
//删：删除指定下标节点
void DeleteByIndex(struct Node* STHead, int* ICount, int IIndex);
//删：删除一段节点（下标指定）
void DeleteSomeByIndex(struct Node* STHead, int* ICount, int IIndex1, int IIndex2);
//删：删除指定数据（N个）
void DeleteAllByData(struct Node* STHead, int* ICount, int IValue);
//查：查找指定节点（根据下标）
struct Node* GetNodeByIndex(struct Node* STHead, int ICount, int iIndex);
//查：查找指定节点（根据数据）
struct Node* GetNodeByData(struct Node* STHead, int iValue);
//循环遍历
void AllShow(struct Node* STHead, int ICount);
//释放
void FreeList(struct Node* STHead, int* ICount);

int main(void)
{
	//创建空头、初始化
	struct Node stHead;
	stHead.iData = 0;
	//双向循环链表即使只有一个节点，依然呈环状，也就是说空头的两个地址成员要记录自己的地址
	stHead.pNext = &stHead;
	stHead.pPre  = &stHead;
	//计数初始化
	int iCount = 0;

//尾添加、头添加、循环遍历
{
	AddToEnd(&stHead, &iCount, 0);
	AddToEnd(&stHead, &iCount, 1);
	AddToEnd(&stHead, &iCount, 2);
	AddToEnd(&stHead, &iCount, 3);
	AddToEnd(&stHead, &iCount, 4);

	AllShow(&stHead, iCount);

	AddToHead(&stHead, &iCount, -1);
	AddToHead(&stHead, &iCount, -2);
	AllShow(&stHead, iCount);

	AddToEnd(&stHead, &iCount, 5);
	AddToEnd(&stHead, &iCount, 6);
	AllShow(&stHead, iCount);

	FreeList(&stHead, &iCount);
	AllShow(&stHead, iCount);
}
//查找指定节点:根据下标、数据。修改节点
{

	AddToEnd(&stHead, &iCount, 2);
	AddToEnd(&stHead, &iCount, 3);
	AddToEnd(&stHead, &iCount, 4);	
	AddToHead(&stHead, &iCount, 1);

	AllShow(&stHead, iCount);
	//下标查找
	struct Node* p = GetNodeByIndex(&stHead, iCount, 3);
	if (p == NULL)
		printf("\n下标不存在/参数为NULL\n");
	else
		printf("\n查到下标数据: %3d\n", p->iData);
	//数据查找
	p = GetNodeByData(&stHead, 2);
	if (p == NULL)
		printf("\n数据不存在/参数为NULL\n");
	else
		printf("\n查到对应数据: %3d\n", p->iData);
	//修改数据:直接用返回值修改	但改成C++后就用不了了，因为成员变成私有的了
	if (p == NULL)
		printf("\n数据不存在/参数为NULL\n");
	else
		p->iData = 23;
	AllShow(&stHead, iCount);

	AddToHead(&stHead, &iCount, 0);
	AddToEnd(&stHead, &iCount, 5);
	AllShow(&stHead, iCount);


	FreeList(&stHead, &iCount);
	AllShow(&stHead, iCount);
}
//指定下标位置添加节点
{
	AddToEnd(&stHead, &iCount, 2);
	AddToEnd(&stHead, &iCount, 3);
	AddToEnd(&stHead, &iCount, 4);
	AddToHead(&stHead, &iCount, 1);

	AllShow(&stHead, iCount);

	InsertByIndex(&stHead, &iCount, 0, 26);
	AllShow(&stHead, iCount);

	AddToEnd(&stHead, &iCount, 5);
	AddToHead(&stHead, &iCount, -1);
	AllShow(&stHead, iCount);

	FreeList(&stHead, &iCount);
	AllShow(&stHead, iCount);
}
//指定下标位置添加节点(N个)
{
	AddToEnd(&stHead, &iCount, 4);
	AddToHead(&stHead, &iCount, 1);
	AllShow(&stHead, iCount);

	InsertSomeByIndex(&stHead, &iCount, 1, 3, 28);
	AllShow(&stHead, iCount);

	AddToEnd(&stHead, &iCount, 00);
	AddToHead(&stHead, &iCount, 00);
	AllShow(&stHead, iCount);

	FreeList(&stHead, &iCount);
	AllShow(&stHead, iCount);
}
//指定数据位置添加节点
{
	AddToEnd(&stHead, &iCount, 4);
	AddToHead(&stHead, &iCount, 1);
	AllShow(&stHead, iCount);

	InsertByData(&stHead, &iCount, 1, 13);
	AllShow(&stHead, iCount);

	AddToEnd(&stHead, &iCount,0);
	AddToHead(&stHead, &iCount, 0);
	InsertByData(&stHead, &iCount, 4, 27);
	AllShow(&stHead, iCount);

	FreeList(&stHead, &iCount);
	AllShow(&stHead, iCount);
}
//删除指定下标节点(一个、一段)
{
	AddToEnd(&stHead, &iCount, 2);
	AddToEnd(&stHead, &iCount, 3);
	AddToEnd(&stHead, &iCount, 4);
	AddToHead(&stHead, &iCount, 1);
	AddToEnd(&stHead, &iCount, 5);
	AddToEnd(&stHead, &iCount, 6);
	AddToEnd(&stHead, &iCount, 7);
	AddToEnd(&stHead, &iCount, 8);

	AllShow(&stHead, iCount);
	//删除1个
	DeleteByIndex(&stHead, &iCount, 7);
	AllShow(&stHead, iCount);
	AddToEnd(&stHead, &iCount, 8);
	AllShow(&stHead, iCount);
	//删除一段
	DeleteSomeByIndex(&stHead, &iCount, 2, 6);
	AllShow(&stHead, iCount);
	AddToEnd(&stHead, &iCount, 9);
	AllShow(&stHead, iCount);

	FreeList(&stHead, &iCount);
	AllShow(&stHead, iCount);
}
//删除指定数据（N个）
{
	AddToEnd(&stHead, &iCount, 2);
	AddToEnd(&stHead, &iCount, 2);
	AddToEnd(&stHead, &iCount, 4);
	AddToHead(&stHead, &iCount, 1);
	AddToEnd(&stHead, &iCount, 8);
	AddToEnd(&stHead, &iCount, 4);
	AddToEnd(&stHead, &iCount, 7);
	AddToEnd(&stHead, &iCount, 8);

	AllShow(&stHead, iCount);

	DeleteAllByData(&stHead, &iCount, 8);
	AllShow(&stHead, iCount);

	AddToHead(&stHead, &iCount, 1);
	AddToEnd(&stHead, &iCount, 7);
	AllShow(&stHead, iCount);

	DeleteAllByData(&stHead, &iCount, 4);
	DeleteAllByData(&stHead, &iCount, 2);
	DeleteAllByData(&stHead, &iCount, 1);
	AllShow(&stHead, iCount);

	FreeList(&stHead, &iCount);
	AllShow(&stHead, iCount);
}

	system("pause>0");
	return 0;
}


//增：尾添加
void AddToEnd(struct Node* STHead, int* ICount, int IData)
{
	//参数合法性检测
	if (&STHead == NULL || STHead == NULL || (*ICount) < 0)
		return;
	//创建新节点
	struct Node* pTemp = (struct Node*)malloc(sizeof(struct Node));
	if (pTemp == NULL)
		return;
	//节点赋值
	pTemp->pNext = NULL;
	pTemp->pPre = NULL;
	pTemp->iData = IData;
	//新节点与尾节点连接（即空头的前一位）
	pTemp->pPre = STHead->pPre;
	STHead->pPre->pNext = pTemp;
	//新节点与空头连接	//注意顺序，要先与尾节点连接（为了避免指针丢失），可画图方便理解
	pTemp->pNext = STHead;
	STHead->pPre = pTemp;
	//计数+1
	(*ICount)++;
}
//增：头添加
void AddToHead(struct Node* STHead, int* ICount, int IData)
{
	//参数合法性检测
	if (&STHead == NULL || STHead == NULL || *ICount < 0)
		return;
	//创建新节点
	struct Node* pTemp = (struct Node*)malloc(sizeof(struct Node));
	if (pTemp == NULL)
		return;
	//节点赋值
	pTemp->pNext = NULL;
	pTemp->pPre = NULL;
	pTemp->iData = IData;
	//新节点先与空头、第2节点相连(老师的思路，也很清晰)
	pTemp->pNext = STHead->pNext;
	pTemp->pPre = STHead;
	//断开空头与第2节点之间的联系
	STHead->pNext->pPre = pTemp;
	STHead->pNext = pTemp;
	//计数+1
	*ICount += 1;
}
//增：指定下标位置添加节点
void InsertByIndex(struct Node* STHead, int* ICount, int IIndex, int IData)
{
	//参数合法性检测
	if (&STHead == NULL || STHead == NULL || *ICount < 0 || IIndex < 0 || IIndex > *ICount)
		return;//IIndex < *ICount是让下标能达到尾节点下一位，这样就能进行尾添加
	//如果下标是尾节点下一位
	if(IIndex == (*ICount))
		AddToEnd(STHead, ICount, IData);
	else
	{
		//查找位置
		struct Node* pTemp = GetNodeByIndex(STHead, *ICount, IIndex);
		//创建节点
		struct Node* pT = (struct Node*)malloc(sizeof(struct Node));
		if (pT == NULL)
			return;
		//节点赋值
		pT->pNext = NULL;
		pT->pPre  = NULL;
		pT->iData = IData;
		//新节点与该位置的前一位节点、该节点连接
		pT->pNext = pTemp;
		pT->pPre = pTemp->pPre;
		//该位置的前一位节点与该节点断开
		if (pT->pPre == NULL)
			return;
		pTemp->pPre->pNext = pT;
		pTemp->pPre = pTemp;
		//计数+1
		*ICount += 1;
	}
}
//增：指定下标位置添加节点(N个)
void InsertSomeByIndex(struct Node* STHead, int* ICount, int IIndex, int iNodeCount, int IData)
{
	//参数合法性检测
	if (&STHead == NULL || STHead == NULL || *ICount < 0 || IIndex < 0 || IIndex > *ICount || iNodeCount < 0)
		return;
	//循环添加
	for (int i = 0; i < iNodeCount; i++)
		InsertByIndex(STHead, ICount, IIndex, IData);	
}
//增：指定数据位置添加节点
void InsertByData(struct Node* STHead, int* ICount, int IValue, int IData)
{
	//参数合法性检测
	if (&STHead == NULL || STHead == NULL || *ICount <= 0)
		return;
	//查找对应位置
	struct Node* pTemp = GetNodeByData(STHead, IValue);
	//创建新节点
	struct Node* pT = (struct Node*)malloc(sizeof(struct Node));
	if (pT == NULL)
		return;
	//节点赋值
	pT->pNext = NULL;
	pT->pPre  = NULL;
	pT->iData = IData;
	//新节点插入到该位置前
	//该位置节点、前一个节点与新节点相连
	pT->pNext = pTemp;
	pT->pPre = pTemp->pPre;
	//该位置节点、前一个节点之间断开
	pTemp->pPre->pNext = pT;
	pTemp->pPre = pT;
	//计数-1
	(*ICount)++;
}
//删：删除指定下标节点
void DeleteByIndex(struct Node* STHead, int* ICount, int IIndex)
{
	//参数合法性检测
	if (&STHead == NULL || STHead == NULL || *ICount <= 0 || IIndex < 0 || IIndex >= *ICount)
		return;
	//查找该节点
	struct Node* pTemp = GetNodeByIndex(STHead, *ICount, IIndex);
	//将该节点的前、后两个节点相连
	pTemp->pPre->pNext = pTemp->pNext;
	pTemp->pNext->pPre = pTemp->pPre;
	//释放该节点
	free(pTemp);
	//计数-1
	(*ICount)--;
}
//删：删除一段节点（下标指定）
void DeleteSomeByIndex(struct Node* STHead, int* ICount, int IIndex1, int IIndex2)
{
	//参数合法性检测
	if (IIndex1 > IIndex2 || IIndex1 < 0 || IIndex2 < 0)
		return;//此处要调用DeleteByIndex函数，这个函数内已经有有一些参数检测了，故参数检测只写没检测到的
	//循环删除
	for (int i = IIndex1; i <= IIndex2; i++)
		DeleteByIndex(STHead, ICount, IIndex1);
	//注意事项，此处调用删除函数，不能传参数i，因为i在增加，
	//链表对应位置已经被删除，后面的节点整体向前移动，传i的话就导致跳着删除，会漏掉一些节点
	//此处直接传IIndex1即可，因为删除后，下一个节点会替换这个下标位置，这样继续删除即可
}
//删：删除指定数据（N个）
void DeleteAllByData(struct Node* STHead, int* ICount, int IValue)
{
	//参数合法性检测
	if (&STHead == NULL || STHead == NULL || *ICount <= 0)
		return;
	//循环删除
	while (1)
	{
		//查找位置
		struct Node* pTemp = GetNodeByData(STHead, IValue);
		//没找到、或者链表中没有这个数据了，跳出循环
		if (pTemp == NULL)
			return;
		//将该位置前、后的节点相连
		pTemp->pPre->pNext = pTemp->pNext;
		pTemp->pNext->pPre = pTemp->pPre;
		//释放该节点
		free(pTemp);
		//计数-1
		*ICount -= 1;
	}
}
//查：查找指定节点（根据下标）
struct Node* GetNodeByIndex(struct Node* STHead, int ICount, int iIndex)
{
	//参数合法性检测
	if (&STHead == NULL || STHead == NULL || ICount < 0 || iIndex < 0 || iIndex >= ICount)
		return NULL;
	//从第2节点开始查找
	struct Node* pTemp = STHead->pNext;
	//循环查找
	for (int i = 0; i < iIndex; i++)
		pTemp = pTemp->pNext;
	return pTemp;
}
//查：查找指定节点（根据数据）
struct Node* GetNodeByData(struct Node* STHead, int iValue)
{
	//参数合法性检测
	if (&STHead == NULL || STHead == NULL)
		return NULL;
	//从第2节点开始
	struct Node* pTemp = STHead->pNext;
	//循环查找
	while (pTemp != STHead)
	{
		if (pTemp->iData == iValue)
			return pTemp;
		pTemp = pTemp->pNext;
	}
	//没找到
	return NULL;
}
//循环遍历
void AllShow(struct Node* STHead, int ICount)
{
	//参数合法性检测
	if (&STHead == NULL || STHead == NULL || ICount < 0)
		return;
	//从空头后一位开始，第2个节点开始
	struct Node* pTemp = STHead->pNext;
	printf("\n数据个数：%2d  数据为：", ICount);
	//方式一：while循环遍历打印
	while (pTemp != STHead)
	{
		printf(" %3d", pTemp->iData);
		pTemp = pTemp->pNext;
	}
	////方式二：for循环遍历打印
	//for (int i = 0; i < (*ICount); i++)
	//{
	//	printf(" %3d", pTemp->iData);
	//	pTemp = pTemp->pNext;
	//}
	putchar('\n');
}
//释放
void FreeList(struct Node* STHead, int* ICount)
{
	//参数合法性检测
	if (&STHead == NULL || STHead == NULL || *ICount < 0 || STHead->pNext == STHead)
		return;
	//记录第2个节点
	struct Node* pTemp = STHead->pNext;
	while (pTemp != STHead)
	{
		//记录当前的节点地址
		struct Node* pT = pTemp;
		//继续往后遍历
		pTemp = pTemp->pNext;
		//释放节点
		free(pT);
	}
	//初始化空头指向
	STHead->pNext = STHead;
	STHead->pPre = STHead;
	//计数归0
	*ICount = 0;
}