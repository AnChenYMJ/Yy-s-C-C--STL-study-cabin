#include <stdio.h>
#include <stdlib.h>

struct Node
{	//命名规范：m_p g_p m是My缩写，代表成员，g代表全局变量，p代表指针类型
	int m_iData;			//记录数据
	struct Node* m_pNext;	//记录下一节点地址
	struct Node* m_pPre;	//记录上一节点地址
};

	

//函数有参数可以增加复用性（多条链表可以调用同一条函数、增加灵活性）

//增：尾添加
void AddToEnd(struct Node** pHead, struct Node** pEnd, int* iCount, int ipData);
//增：头添加
void AddToHead(struct Node** pHead, struct Node** pEnd, int* iCount, int ipData);
//合并链表：摘头
struct Node* GetHead(struct Node** pHead, struct Node** pEnd, int* iCount);
//合并链表：接入
void HeBing(struct Node** pHA, struct Node** pEA, int* iCA, struct Node** pHB, struct Node** pEB, int* iCB);
//遍历释放
void FreeList(struct Node** pHead, struct Node** pEnd, int* iCount);
//遍历打印(正向)
void ShowZheng(struct Node** pHead, struct Node** pEnd, int* iCount);
//遍历打印(反向)
void ShowFan(struct Node** pHead, struct Node** pEnd, int* iCount);


int main(void)
{
	//A链表
	struct Node* g_pHA = NULL;
	struct Node* g_pEA = NULL;
	int	g_iACount = 0;

	//B链表
	struct Node* g_pHB = NULL;
	struct Node* g_pEB = NULL;
	int	g_iBCount = 0;

	AddToEnd(&g_pHA, &g_pEA, &g_iACount, 1);
	AddToHead(&g_pHA, &g_pEA, &g_iACount, 3);
	AddToEnd(&g_pHA, &g_pEA, &g_iACount, 5);
	AddToHead(&g_pHA, &g_pEA, &g_iACount, 8);
	AddToEnd(&g_pHA, &g_pEA, &g_iACount, 14);

	ShowZheng(&g_pHA, &g_pEA, &g_iACount);
	ShowFan(&g_pHA, &g_pEA, &g_iACount);

	ShowZheng(&g_pHB, &g_pEB, &g_iBCount);
	//B无节点接入测试
	HeBing(&g_pHA, &g_pEA, &g_iACount, &g_pHB, &g_pEB, &g_iBCount);
	ShowZheng(&g_pHB, &g_pEB, &g_iBCount);
	//测试再添加是否成功
	AddToEnd(&g_pHB, &g_pEB, &g_iBCount, 11);
	AddToHead(&g_pHB, &g_pEB, &g_iBCount, 7);
	ShowZheng(&g_pHB, &g_pEB, &g_iBCount);
	//测试接入后的头添加
	HeBing(&g_pHA, &g_pEA, &g_iACount, &g_pHB, &g_pEB, &g_iBCount);
	HeBing(&g_pHA, &g_pEA, &g_iACount, &g_pHB, &g_pEB, &g_iBCount);
	ShowZheng(&g_pHB, &g_pEB, &g_iBCount);
	//测试接入后的中间添加
	HeBing(&g_pHA, &g_pEA, &g_iACount, &g_pHB, &g_pEB, &g_iBCount);
	ShowZheng(&g_pHB, &g_pEB, &g_iBCount);
	//测试接入后的尾添加
	HeBing(&g_pHA, &g_pEA, &g_iACount, &g_pHB, &g_pEB, &g_iBCount);
	ShowZheng(&g_pHB, &g_pEB, &g_iBCount);
	//测试再添加是否成功
	AddToEnd(&g_pHB, &g_pEB, &g_iBCount, 0);
	AddToHead(&g_pHB, &g_pEB, &g_iBCount, 0);
	ShowZheng(&g_pHB, &g_pEB, &g_iBCount);
	ShowFan(&g_pHB, &g_pEB, &g_iBCount);
	//测试打印被掏光的链表A
	ShowZheng(&g_pHA, &g_pEA, &g_iACount);


	system("pause>0");
	return 0;
}


void AddToEnd(struct Node** pHead, struct Node** pEnd, int* iCount, int ipData)
{
	//参数合法性检测
	if (pHead == NULL || pEnd == NULL || iCount < 0)
		return;

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
	if (*iCount == 0 && *pHead == NULL)
		//记录头尾的指针记录这个节点
		*pHead = pTemp;
	//链表已存在节点
	else
	{
		//原尾节点与该节点互相记录地址（双向链表）
		(*pEnd)->m_pNext = pTemp;
		pTemp->m_pPre = *pEnd;
	}
	//两个情况重复的操作放到外面(简化代码)
	*pEnd = pTemp;		//记录尾节点指针记录新尾节点
	*iCount += 1;	//计数+1
}
void AddToHead(struct Node** pHead, struct Node** pEnd, int* iCount, int ipData)
{
	//参数合法性检测
	if (pHead == NULL || pEnd == NULL || iCount < 0)
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
	if (*pHead == NULL)
		*pEnd = pTemp;
	//2.链表有节点时
	else
	{
		//节点连到头节点之前
		pTemp->m_pNext = *pHead;
		(*pHead)->m_pPre = pTemp;
	}
	//记录头节点指针记录新头节点
	*pHead = pTemp;
	//计数+1
	(*iCount)++;	//++ 运算符比 * 优先级高
}
struct Node* GetHead(struct Node** pHead, struct Node** pEnd, int* iCount)
{
	//参数合法性检测
	if (pHead == NULL || pEnd == NULL || *pHead == NULL || *iCount < 0)
		return NULL;
	//记录头节点
	struct Node* pTemp = *pHead;
	//判断是否只有一个节点
	if (*pHead == *pEnd)
	{
		//头尾记录指针赋空
		*pHead = NULL;
		*pEnd = NULL;
	}
	else
	{
		//使头记录指针记录下一个节点
		*pHead = (*pHead)->m_pNext;
		//断开被独立的节点与链表的联系
		(*pHead)->m_pPre = NULL;
	}
	//断开被独立的节点与链表的联系
	pTemp->m_pNext = NULL;
	//计数-1
	*iCount -= 1;
	//返回这个被隔开的节点地址
	return pTemp;


}
void HeBing(struct Node** pHA, struct Node** pEA, int* iCA, struct Node** pHB, struct Node** pEB, int* iCB)
{
	//参数合法性检测
	if (pHA == NULL || pEA == NULL || pHB == NULL || pEB == NULL || *pHA == NULL || *iCA <= 0 || *iCB < 0)
		return;
	//记录链表A被独立开的节点
	struct Node* pTemp = GetHead(pHA, pEA, iCA);
	if (pTemp == NULL)
		return;
	//B还没有节点
	if (*pHB == NULL)
	{
		//将新节点添加到链表B
		*pHB = pTemp;		//pTemp在摘头函数中，它的两个地址记录已经被赋空了
		*pEB = pTemp;
		//计数+1
		*iCB += 1;
	}
	//B已经有了节点
	else
	{
		//链表B只有一个节点
		if (*pHB == *pEB)
		{
			//新节点比B的节点小	头添加
			if (pTemp->m_iData <= (*pHB)->m_iData)
			{
				//新节点连接到B原头节点前
				pTemp->m_pNext = *pHB;
				(*pHB)->m_pPre = pTemp;
				//B头记录指针记录新头节点
				*pHB = pTemp;
				//计数+1
				*iCB += 1;
			}
			//新节点比B的节点大	尾添加
			else
			{
				//新节点连接到B原头节点后
				(*pEB)->m_pNext = pTemp;
				pTemp->m_pPre = *pEB;		//pTemp在摘头函数中，它的两个地址记录已经被赋空了
				//B头记录指针记录新尾节点
				*pEB = pTemp;
				//计数+1
				*iCB += 1;
			}
		}
		//链表B有多个节点
		else
		{
			//新节点比B的头节点小	头添加
			if (pTemp->m_iData <= (*pHB)->m_iData)
			{
				//新节点连接到B原头节点前
				pTemp->m_pNext = *pHB;
				(*pHB)->m_pPre = pTemp;
				//B头记录指针记录新头节点
				*pHB = pTemp;
				//计数+1
				*iCB += 1;
			}
			//新节点比B的尾节点大	尾添加
			else if (pTemp->m_iData > (*pEB)->m_iData)
			{
				//新节点连接到B原尾节点后
				(*pEB)->m_pNext = pTemp;
				pTemp->m_pPre = *pEB;		//pTemp在摘头函数中，它的两个地址记录已经被赋空了
				//B头记录指针记录新尾节点
				*pEB = pTemp;
				//计数+1
				*iCB += 1;
			}
			//新节点比B的头节点大、比B的尾节点小	中间添加
			else
			{
				struct Node* PT = *pHB;
				if (PT == NULL)
					return;

				//循环查找合适的插入位置
				while (PT->m_pNext != NULL)
				{	//位置条件是：新节点数据位比该节点大于等于，同时比该节点的下一位小于等于
					if (pTemp->m_iData >= PT->m_iData && pTemp->m_iData <= PT->m_pNext->m_iData)
						break;
					PT = PT->m_pNext;
				}
				//消除警告：对NULL指针PT->m_pNext的使用
				if (PT->m_pNext == NULL)
					return;
				//找到合适位置
				//新节点与该位置后一位节点连接

				pTemp->m_pNext = PT->m_pNext;
				PT->m_pNext->m_pPre = pTemp;
				//新节点与该位置节点连接
				PT->m_pNext = pTemp;
				pTemp->m_pPre = PT;
				//计数+1
				*iCB += 1;
			}
		}
	}

}
void FreeList(struct Node** pHead, struct Node** pEnd, int* iCount)
{	//全局区的变量，有可能陷入循环重复申请，导致内存占用过高崩溃，不过全局区的变量我们是能手动释放的
	//参数合法性检测
	if (pHead == NULL || pEnd == NULL || *pHead == NULL)
		return;
	//循环遍历释放
	struct Node* pTemp = *pHead;
	while (pTemp != NULL)
	{
		//记录要被释放的节点
		struct Node* pT = pTemp;
		//pTemp继续遍历
		pTemp = pTemp->m_pNext;
		//释放节点
		free(pT);
	}
	*pHead = NULL;
	*pEnd = NULL;
	*iCount = 0;
}
void ShowZheng(struct Node** pHead, struct Node** pEnd, int* iCount)
{
	//参数合法性检测
	if (pHead == NULL || pEnd == NULL || iCount < 0)
		return;

	//打印提示
	printf("\n节点数:%2d  数据为: ", *iCount);
	//循环遍历
	struct Node* pTemp = *pHead;
	while (pTemp != NULL)
	{
		printf(" %3d", pTemp->m_iData);
		pTemp = pTemp->m_pNext;
	}
	putchar('\n');
}
void ShowFan(struct Node** pHead, struct Node** pEnd, int* iCount)
{
	//参数合法性检测
	if (pHead == NULL || pEnd == NULL || iCount < 0)
		return;

	//打印提示
	printf("\n节点数:%2d  数据为: ", *iCount);
	//循环遍历
	struct Node* pTemp = *pEnd;
	while (pTemp != NULL)
	{
		printf(" %3d", pTemp->m_iData);
		pTemp = pTemp->m_pPre;
	}
	putchar('\n');
}
