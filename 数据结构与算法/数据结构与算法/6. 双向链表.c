#include <stdio.h>
#include <stdlib.h>

//要点注意
void AAA()
{
	//双向链表对应STL里的List容器
	//双向链表基本三变量，分别为：数据、下一节点地址、上一节点地址
	//头尾因为三变量边界原因，要特殊处理
	//双向链表对比单向链表更灵活了，但是代码就繁琐一点
	//全局变量尽量不要用大空间变量，因为全局变量与程序共存亡，无法释放，空间太大就浪费了
	//工作中用双向链表更多，除非特殊或简单的项目使用单向链表，否则双向链表优势更大（灵活，可以任意向遍历，可以定点清除）
	//本课时使用无空头来展示，我们可以自己改代码加上

}	

struct Node
{	//命名规范：m_p g_p m是My缩写，代表成员，g代表全局变量，p代表指针类型
	int m_iData;			//记录数据
	struct Node* m_pNext;	//记录下一节点地址
	struct Node* m_pPre;	//记录上一节点地址
};

//全局变量
struct Node* g_pHead = NULL;	//记录头节点的指针
struct Node* g_pEnd = NULL;	//记录尾节点的指针
int	g_iNodeCount = 0;		//节点计数

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
//遍历释放
void FreeList();
//遍历打印(正向)
void ShowZheng();
//遍历打印(反向)
void ShowFan();


int main(void)
{
//尾添加、正反向遍历、释放
{
	AddToEnd(1);
	AddToEnd(2);
	AddToEnd(3);
	AddToEnd(4);
	AddToEnd(5);

	ShowZheng();
	AddToEnd(6);
	ShowFan();

	FreeList();
	ShowZheng();
}
//头添加、中间添加（N个）
{
	//头添加
	AddToEnd(0);
	AddToHead(-1);
	AddToEnd(1);
	AddToHead(-2);
	AddToEnd(2);
	AddToHead(-3);
	AddToEnd(3);
	AddToHead(-4);
	AddToEnd(4);

	ShowZheng();
	ShowFan();
	//中间添加(头)
	InsertNodeByIndex(0, 1, 996);
	ShowZheng();
	AddToEnd(5);
	//中间添加(尾)
	InsertNodeByIndex(11, 2, 996);
	ShowZheng();
	AddToHead(-5);
	AddToEnd(6);
	//中间添加(中间)
	InsertNodeByIndex(6, 3, 996);
	ShowZheng();
	AddToHead(-6);
	AddToEnd(7);
	ShowZheng();
	//测试不存在的下标
	InsertNodeByIndex(31, 3, 996);
	ShowZheng();

	FreeList();
	ShowZheng();
}
//指定数据位置添加节点
{
	AddToEnd(0);
	AddToHead(-1);
	AddToEnd(1);
	AddToHead(-2);
	AddToEnd(2);
	AddToHead(-3);
	AddToEnd(3);
	AddToHead(-4);
	AddToEnd(4);

	ShowZheng();

	InsertNodeByData(0, 996);
	ShowZheng();

	AddToHead(-5);
	AddToEnd(5);
	InsertNodeByData(1, 996);
	ShowZheng();
	//测试不存在的数据
	InsertNodeByData(13, 996);
	ShowZheng();

	FreeList();
	ShowZheng();
}
//查找数据（根据下标、数据）、修改指定节点（根据数据（N个）、根据下标）
{
	AddToEnd(0);
	AddToHead(-1);
	AddToEnd(1);
	AddToHead(-2);
	AddToEnd(2);
	AddToHead(-3);
	AddToEnd(3);
	AddToHead(-4);
	AddToEnd(4);

	ShowZheng();
	//查：根据数据查找
	struct Node* p = GetByData(0);
	if (p != NULL)
		printf("\n找到数据： %3d\n", p->m_iData);
	else
		printf("\n未找到该数据\n");

	AddToHead(-5);
	AddToEnd(5);
	ShowZheng();
	p = GetByData(11);
	if (p != NULL)
		printf("\n找到数据： %3d\n", p->m_iData);
	else
		printf("\n未找到该数据\n");
	//查：根据下标
	p = GetByIndex(10);
	if (p != NULL)
		printf("\n找到下标数据： %3d\n", p->m_iData);
	else
		printf("\n未找到该数据\n");

	AddToHead(-6);
	AddToEnd(6);
	ShowZheng();
	p = GetByIndex(13);
	if (p != NULL)
		printf("\n找到下标数据： %3d\n", p->m_iData);
	else
		printf("\n未找到该数据\n");
	//改：根据下标
	ChangeByIndex(0, 14);
	ShowZheng();
	AddToHead(0);
	AddToEnd(0);
	ShowZheng();
	ChangeByIndex(14, 14);
	ShowZheng();
	ChangeByIndex(16, 16);
	ShowZheng();
	//改：根据数据
	ChangeByData(0, 26);
	ShowZheng();

	AddToHead(0);
	AddToEnd(0);
	ChangeByData(22, 27);
	ShowZheng();

	FreeList();
	ShowZheng();
} 
//删除指定下标节点（根据下标）
{
	AddToEnd(0);
	AddToHead(-1);
	AddToEnd(1);
	AddToHead(-2);
	AddToEnd(2);
	ShowZheng();
	//头删除
	DeleteByIndex(0);
	ShowZheng();
	//尾删除
	AddToHead(-2);
	AddToEnd(3);
	ShowZheng();
	DeleteByIndex(5);
	ShowZheng();
	//中间删除
	AddToHead(-3);
	AddToEnd(3);
	ShowZheng();
	DeleteByIndex(3);
	ShowZheng();
	AddToHead(-4);
	AddToEnd(4);
	ShowZheng();
	ShowFan();

	FreeList();
	ShowZheng();
}
//删除指定下标节点（根据数据）（N个）
{
	AddToEnd(2);
	AddToHead(2);
	AddToEnd(1);
	AddToHead(2);
	AddToEnd(2);
	ShowZheng();

	DeleteByData(2);
	ShowZheng();

	AddToHead(5);
	AddToEnd(1);
	ShowZheng();
	ShowFan();

	DeleteByData(1);
	ShowZheng();

	FreeList();
	ShowZheng();
}



	system("pause>0");
	return 0;
}


void AddToEnd(int ipData)
{
	//参数合法性检测
	if (&g_pHead == NULL || &g_pEnd == NULL || g_iNodeCount < 0)
		return;//老师说全局变量稳当，就不用检测指针地址了（但我还是加上）

	//创建节点
	struct Node* pTemp = (struct Node*)malloc(sizeof(struct Node));
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
void AddToHead(int ipData)
{
	//参数合法性检测
	if (&g_pHead == NULL || &g_pEnd == NULL || g_iNodeCount < 0)
		return;
	//创建节点
	struct Node* pTemp = (struct Node*)malloc(sizeof(struct Node));
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
void InsertNodeByIndex(int Index, int iCount, int ipData)
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
			struct Node* pNew = (struct Node*)malloc(sizeof(struct Node));
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
void InsertNodeByData(int iValue, int ipData)
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
			struct Node* pNew = (struct Node*)malloc(sizeof(struct Node));
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
		printf("\n未找到该数据\n");
		return;
	}
}
struct Node* GetByData(int iValue)
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
struct Node* GetByIndex(int Index)
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
void DeleteNode(struct Node* pTemp)
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
			free(pTemp);
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
			free(PT);
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
		free(PT);
	}
	//中间删除
	else
	{
		//改变该位置前一位节点指向
		pTemp->m_pPre->m_pNext = pTemp->m_pNext;
		//改变该位置后一位节点指向
		pTemp->m_pNext->m_pPre = pTemp->m_pPre;
		//释放该节点
		free(pTemp);

		////计数-1
		//g_iNodeCount--;	//由于这三种判断都进行了这步操作，我们放到下面一起执行
	}
	//计数-1
	g_iNodeCount--;
}
void DeleteByIndex(int Index)
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
void DeleteByData(int iValue)
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
void ChangeByData(int iValue, int ipData)
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
void ChangeByIndex(int Index, int ipData)
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
void FreeList()
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
		free(pT);
	}
	g_pHead = NULL;
	g_pEnd = NULL;
	g_iNodeCount = 0;
}
void ShowZheng()
{
	//参数合法性检测
	if (&g_pHead == NULL || &g_pEnd == NULL || g_iNodeCount < 0)
		return;

	//打印提示
	printf("\n节点数:%2d  数据为: ", g_iNodeCount);
	//循环遍历
	struct Node* pTemp = g_pHead;
	while (pTemp != NULL)
	{
		printf(" %3d", pTemp->m_iData);
		pTemp = pTemp->m_pNext;
	}
	putchar('\n');
}
void ShowFan()
{
	//参数合法性检测
	if (&g_pHead == NULL || &g_pEnd == NULL || g_iNodeCount < 0)
		return;

	//打印提示
	printf("\n节点数:%2d  数据为: ", g_iNodeCount);
	//循环遍历
	struct Node* pTemp = g_pEnd;
	while (pTemp != NULL)
	{
		printf(" %3d", pTemp->m_iData);
		pTemp = pTemp->m_pPre;
	}
	putchar('\n');
}
