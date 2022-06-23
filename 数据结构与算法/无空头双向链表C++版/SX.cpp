#include "SX.h"

SX::SX()
{
	g_pHead = NULL;
	g_pEnd = NULL;
	g_iNodeCount = 0;
}
SX::~SX()
{
	FreeList();
}

void SX::AddToEnd(int ipData)
{
	//参数合法性检测
	if (&g_pHead == NULL || &g_pEnd == NULL || g_iNodeCount < 0)
		return;//老师说全局变量稳当，就不用检测指针地址了（但我还是加上）

	//创建节点
	struct Node* pTemp = new struct Node;
	if (pTemp == NULL)
		return;
	//节点赋值
	pTemp->m_iData = ipData;
	pTemp->m_pNext = NULL;
	pTemp->m_pPre = NULL;
	//节点连接到链表（需进行情况判断）
	//链表还没有节点：
	if (g_iNodeCount == 0 && g_pHead == NULL)
		//记录头尾的指针记录这个节点
		g_pHead = pTemp;
	//链表已存在节点
	else
	{
		//原尾节点与该节点互相记录地址（双向链表）
		g_pEnd->m_pNext = pTemp;
		pTemp->m_pPre = g_pEnd;
	}
	//两个情况重复的操作放到外面(简化代码)
	g_pEnd = pTemp;		//记录尾节点指针记录新尾节点
	g_iNodeCount += 1;	//计数+1
}
void SX::AddToHead(int ipData)
{
	//参数合法性检测
	if (&g_pHead == NULL || &g_pEnd == NULL || g_iNodeCount < 0)
		return;
	//创建节点
	struct Node* pTemp = new struct Node;
	if (pTemp == NULL)
		return;
	//节点赋值
	pTemp->m_pNext = NULL;
	pTemp->m_pPre = NULL;
	pTemp->m_iData = ipData;
	//节点添加到链表（2种情况）
	//1.链表没有节点时
	if (g_pHead == NULL)
		g_pEnd = pTemp;
	//2.链表有节点时
	else
	{
		//节点连到头节点之前
		pTemp->m_pNext = g_pHead;
		g_pHead->m_pPre = pTemp;
	}
	//记录头节点指针记录新头节点
	g_pHead = pTemp;
	//计数+1
	g_iNodeCount++;
}
void SX::InsertNodeByIndex(int Index, int iCount, int ipData)
{
	//参数合法性检测
	if (&g_pHead == NULL || &g_pEnd == NULL || g_iNodeCount < 0 || Index < 0 || iCount <= 0 || Index > g_iNodeCount)
		return; //Index = g_iNodeCount时，就刚好在尾节点的下一位，就能进行尾添加了
	//添加节点（3种情况）
	//1.下表为0，头添加
	if (Index == 0)
	{
		for (int i = 0; i < iCount; i++)
			AddToHead(ipData);
	}
	//2.下标为尾节点下一位，尾添加
	else if (Index == g_iNodeCount)
	{
		for (int i = 0; i < iCount; i++)
			AddToEnd(ipData);
	}
	//3.中间位置添加
	else
	{
		for (int i = 0; i < iCount; i++)
		{
			//创建节点
			struct Node* pNew = new struct Node;
			if (pNew == NULL)
				return;
			//节点赋值
			pNew->m_pNext = NULL;
			pNew->m_pPre = NULL;
			pNew->m_iData = ipData;
			//查找下标位置
			struct Node* pTemp = g_pHead;
			for (int i = 0; i < Index; i++)
			{
				pTemp = pTemp->m_pNext;
			}
			//该位置的前一位节点与新节点相连
			pTemp->m_pPre->m_pNext = pNew;	//画图能方便理解，pTemp->m_pPre 是该位置的前一个结点
			pNew->m_pPre = pTemp->m_pPre;
			//新节点与原该位置的节点相连
			pNew->m_pNext = pTemp;
			pTemp->m_pPre = pNew;
			//计数+1
			g_iNodeCount++;
		}
	}
}
void SX::InsertNodeByData(int iValue, int ipData)
{
	//参数合法性检测
	if (&g_pHead == NULL || &g_pEnd == NULL || g_iNodeCount < 0 || g_pHead == NULL)
		return;//过滤掉没有节点的情况
	//查找对应节点
	struct Node* pTemp = g_pHead;
	while (pTemp != NULL)
	{
		if (pTemp->m_iData == iValue)
			break;
		pTemp = pTemp->m_pNext;
	}
	//判断是否找到该节点
	//找到
	if (pTemp != NULL)
	{
		//如果该位置是头节点,头添加
		if (pTemp == g_pHead)
			AddToHead(ipData);
		//该位置不是头节点
		else
		{
			//创建新节点
			struct Node* pNew = new struct Node;
			if (pNew == NULL)
				return;
			//节点赋值
			pNew->m_pNext = NULL;
			pNew->m_pPre = NULL;
			pNew->m_iData = ipData;
			//该位置的前一位节点与新结点连接
			pTemp->m_pPre->m_pNext = pNew;
			pNew->m_pPre = pTemp->m_pPre;
			//新节点与该位置节点相连
			pNew->m_pNext = pTemp;
			pTemp->m_pPre = pNew;
			//计数+1
			g_iNodeCount += 1;
		}
	}
	//没找到
	else
	{
		cout << "\n未找到该数据\n";
		return;
	}
}
struct Node* SX::GetByData(int iValue)
{
	//参数合法性检测
	if (&g_pHead == NULL || &g_pEnd == NULL || g_iNodeCount <= 0 || g_pHead == NULL)
		return NULL;
	//从第一个节点开始查找
	struct Node* pTemp = g_pHead;
	while (pTemp != NULL)
	{
		if (pTemp->m_iData == iValue)
			break;	//找到则跳出循环
		pTemp = pTemp->m_pNext;
	}
	//如果找到，返回的是地址，如果没找到返回的是NULL
	return pTemp;
}
struct Node* SX::GetByIndex(int Index)
{
	//参数合法性检测
	if (&g_pHead == NULL || &g_pEnd == NULL || g_iNodeCount <= 0 || g_pHead == NULL || Index < 0 || Index >= g_iNodeCount)
		return NULL;//Index >= g_iNodeCount是确保不会超出下标上限越界
	//从第一个结点开始查找
	struct Node* pTemp = g_pHead;
	if (pTemp == NULL)
		return NULL;
	//查找
	for (int i = 0; i < Index; i++)
		pTemp = pTemp->m_pNext;
	return pTemp;
}
void SX::DeleteNode(struct Node* pTemp)
{
	//参数合法性检测
	if (&pTemp == NULL || pTemp == NULL || g_pHead == NULL)
		return;
	//判断头、尾、中间中的哪种情况、分开处理
	//头删除
	if (pTemp == g_pHead)
	{
		//判断是否只有一个节点
		if (g_pHead == g_pEnd)
		{
			//释放
			delete pTemp;
			//头尾记录指针赋空
			g_pHead = NULL;
			g_pEnd = NULL;
		}
		else
		{
			//记录当前节点
			struct Node* PT = g_pHead;
			//改变新头节点的指向（原头节点的下一位）
			g_pHead->m_pNext->m_pPre = NULL;
			//头记录指针记录新头节点
			g_pHead = g_pHead->m_pNext;
			//释放原头节点
			delete PT;
		}
	}
	//尾删除
	else if (pTemp == g_pEnd)
	{
		//判断是否只有一个节点：头删除判断的时候这种情况判断过了，无需再操作，因为一个节点，既是头删除也是尾删除

		//记录当前节点
		struct Node* PT = g_pEnd;
		//改变新尾节点指向
		g_pEnd->m_pPre->m_pNext = NULL;
		//尾记录指针记录新尾节点
		g_pEnd = g_pEnd->m_pPre;
		//释放原尾节点
		delete PT;
	}
	//中间删除
	else
	{
		//改变该位置前一位节点指向
		pTemp->m_pPre->m_pNext = pTemp->m_pNext;
		//改变该位置后一位节点指向
		pTemp->m_pNext->m_pPre = pTemp->m_pPre;
		//释放该节点
		delete pTemp;

		////计数-1
		//g_iNodeCount--;	//由于这三种判断都进行了这步操作，我们放到下面一起执行
	}
	//计数-1
	g_iNodeCount--;
}
void SX::DeleteByIndex(int Index)
{
	//参数合法性检测	//由于FindByIndex查找函数有了参数检测，这里我们可以不写
	if (&g_pHead == NULL || &g_pEnd == NULL || g_pHead == NULL || g_iNodeCount <= 0 || Index < 0 || Index >= g_iNodeCount)
		return;
	//查找下标对应位置
	struct Node* pTemp = GetByIndex(Index);
	//找到则进行节点删除
	if (pTemp != NULL)
		DeleteNode(pTemp);
	else
		return;
}
void SX::DeleteByData(int iValue)
{
	//参数合法性检测
	if (&g_pHead == NULL || &g_pEnd == NULL || g_iNodeCount <= 0 || g_pHead == NULL)
		return;

	//循环来查找删除
	struct Node* pTemp;
	//注意判断语句里的符号优先级	//这种循环写法更简洁，但是初学者不好理解
	while (NULL != (pTemp = GetByData(iValue)))
		DeleteNode(pTemp);
}
void SX::ChangeByData(int iValue, int ipData)
{
	//参数合法性检测
	if (&g_pHead == NULL || &g_pEnd == NULL || g_iNodeCount <= 0 || g_pHead == NULL)
		return;
	//查找到对应节点，并修改该节点数据
	struct Node* pTemp = g_pHead;
	while (pTemp != NULL)
	{
		if (pTemp->m_iData == iValue)
			pTemp->m_iData = ipData;
		pTemp = pTemp->m_pNext;
	}
}
void SX::ChangeByIndex(int Index, int ipData)
{
	//参数合法性检测
	if (&g_pHead == NULL || &g_pEnd == NULL || g_iNodeCount <= 0 || g_pHead == NULL || Index < 0 || Index >= g_iNodeCount)
		return;
	//查找该位置
	struct Node* pTemp = GetByIndex(Index);
	//找到后进行该节点的修改
	if (pTemp != NULL)
		pTemp->m_iData = ipData;
	//没找到
	else
		return;
}
void SX::FreeList()
{	//全局区的变量，有可能陷入循环重复申请，导致内存占用过高崩溃，不过全局区的变量我们是能手动释放的
	//参数合法性检测
	if (&g_pHead == NULL || &g_pEnd == NULL || g_pEnd == NULL)
		return;
	//循环遍历释放
	struct Node* pTemp = g_pHead;
	while (pTemp != NULL)
	{
		//记录要被释放的节点
		struct Node* pT = pTemp;
		//pTemp继续遍历
		pTemp = pTemp->m_pNext;
		//释放节点
		delete pT;
	}
	g_pHead = NULL;
	g_pEnd = NULL;
	g_iNodeCount = 0;
}
void SX::ShowZheng()
{
	//参数合法性检测
	if (&g_pHead == NULL || &g_pEnd == NULL || g_iNodeCount < 0)
		return;

	//打印提示
	cout << "\n节点数:" <<  g_iNodeCount << "  数据为: ";
	//循环遍历
	struct Node* pTemp = g_pHead;
	while (pTemp != NULL)
	{
		cout << " " << pTemp->m_iData;
		pTemp = pTemp->m_pNext;
	}
	cout << '\n';
}
void SX::ShowFan()
{
	//参数合法性检测
	if (&g_pHead == NULL || &g_pEnd == NULL || g_iNodeCount < 0)
		return;

	//打印提示
	cout << "\n节点数:" << g_iNodeCount << "  数据为: ";
	//循环遍历
	struct Node* pTemp = g_pEnd;
	while (pTemp != NULL)
	{
		cout << " " << pTemp->m_iData;
		pTemp = pTemp->m_pPre;
	}
	putchar('\n');
}
