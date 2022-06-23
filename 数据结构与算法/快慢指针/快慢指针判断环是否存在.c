#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>	//bool的头文件，老师说C++、C识别大布尔与小布尔有区别

//环的概念以及判断方法
void AAA()
{
	if (1 == 1)
	{
		//环：用A-B-C-D-E-F-G-H-I代替链表来解释
		//I原本下一位是NULL（单向）或者A（双向）
		//结果因为一些原因，I指向了链表中其它节点，比如D
		//链表（正向）就成了A-B-C-D-E-F-G-H-I -D-E-F-G-H-I -D-E....
		//画图来看，就像一个6字

		//面试题：怎么判断一个链表中是否有环
		//判断方式：使用快慢指针来判断链表是否有环
		//快慢指针：两个指针，一个一次走好几个节点（快），另一个一次1个节点（慢）
		//这样当它们相遇时，像操场一般，快的围圈跑追上慢的了，则证明有环的存在
	}

}

struct Node
{
	int iData;
	struct Node* pNext;
	struct Node* pPre;
};

//尾添加
void AddToEnd(struct Node* stHead, int* ICount, int IData)
{
	//参数合法性检测
	if (&stHead == NULL || stHead == NULL || *ICount < 0)
		return;
	//创建新节点
	struct Node* pTemp = (struct Node*)malloc(sizeof(struct Node));
	if (pTemp == NULL)
		return;
	//节点赋值
	pTemp->iData = IData;
	pTemp->pNext = NULL;
	pTemp->pPre = NULL;
	//新节点与原尾节点相连
	pTemp->pPre = stHead->pPre;
	stHead->pPre->pNext = pTemp;
	//新节点与空头相连
	pTemp->pNext = stHead;
	stHead->pPre = pTemp;
	//计数+1
	*ICount += 1;
}
//释放
void FreeList(struct Node* stHead, int* ICount)
{
	//参数合法性检测
	if (&stHead == NULL || stHead == NULL || *ICount <= 0)
		return;
	//从第2节点开始
	struct Node* pTemp = stHead->pNext;
	//循环释放
	while (pTemp != stHead)
	{
		//记录当前节点
		struct Node* pT = pTemp;
		//向后遍历
		pTemp = pTemp->pNext;
		//释放
		free(pT);
	}
	//初始化链表
	stHead->pNext = stHead;
	stHead->pPre = stHead;
	//计数归0
	*ICount = 0;
}
//遍历打印
void AllShow(struct Node* stHead, int ICount)
{
	//参数合法性检测
	if (&stHead == NULL || stHead == NULL || ICount < 0)
		return;

	//从第2结点开始
	struct Node* pTemp = stHead->pNext;
	printf("\n节点数: %3d  数据为:", ICount);
	//循环遍历
	while (pTemp != stHead)
	{
		printf(" %2d", pTemp->iData);
		pTemp = pTemp->pNext;
	}
	putchar('\n');
}
//快慢指针判断是否成环
bool QuikSlow(struct Node* stHead)
{
	//参数合法性检测
	if (&stHead == NULL || stHead == NULL)
		return false;
	//声明快慢指针
	struct Node* Quik = stHead->pNext;		//快指针
	struct Node* Slow = stHead->pNext;		//慢指针
	//循环，让两指针遍历链表
	while (Quik != NULL && Quik->pNext != NULL)
	{//注意第2个判断条件，是防止Quik越界操作、也注意判断的顺序
		//两指针遍历
		Quik = Quik->pNext->pNext;
		Slow = Slow->pNext;
		//当两指针相遇，证实环的存在
		if (Quik == Slow)
			return true;
	}
	return false;
}

int main(void)
{
	//空头
	struct Node stHead;
	stHead.pNext = &stHead;
	stHead.pPre = &stHead;
	stHead.iData = 0;
	//计数
	int iCount = 0;

	AddToEnd(&stHead, &iCount, 1);
	AddToEnd(&stHead, &iCount, 2);
	AddToEnd(&stHead, &iCount, 3);
	AddToEnd(&stHead, &iCount, 4);
	AddToEnd(&stHead, &iCount, 5);
	AddToEnd(&stHead, &iCount, 6);

	AllShow(&stHead, iCount);

	/*FreeList(&stHead, &iCount);
	AllShow(&stHead, iCount);*/

	//使双向循环链表断开成不循环的，为下面快慢指针判断做准备(因为循环就是一个大环)
	struct Node* pEnd = stHead.pPre;
	pEnd->pNext = NULL;
	stHead.pPre = NULL;

	//手动形成环（正向的环）
	//pEnd->pNext = stHead.pNext->pNext->pNext;

	//快慢指针判断是否成环（可以修改或添加函数成反向遍历检测）
	bool b = QuikSlow(&stHead);

	//判断完之后再让链表变成循环的
	pEnd->pNext = &stHead;
	stHead.pPre = pEnd;
	pEnd = NULL;

	AllShow(&stHead, iCount);


	system("pause>0");
	return 0;
}