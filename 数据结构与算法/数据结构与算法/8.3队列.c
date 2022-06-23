#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <stdbool.h>	//bool头文件s

//队列介绍
void AAA()
{
	//队列
	if (1)
	{
		//队列与栈一样，都是对线性表的一种限定操作
		//栈：添加与删除，入栈与出栈，都必须在同一端完成
		//队列：添加与删除，入栈与出栈，都必须在异端完成

		//先进先出，就是先装进的数据，先出队列
		//应用：比如windows的消息机制，键盘的输入等，先进的信息先出去
		//与栈一样，可以用数组实现，但是没有必要，因为数组异端操作有点麻烦（尾添加，就要头删除，就是数组前几个空间不能用，其实这样做也可以不麻烦），一般用链表
		// 但是单向链表实现的话，效率就低了，因为要遍历找尾，然后再遍历找新的尾。
		//功能：Queue：创建队列空头、IsEmpty：判断是否为NULL、Push：入队、Pop：出队、Front：队头节点、Back：队尾节点
	}
}

//本队列使用双向循环链表（头添加、尾删除）
struct Node
{
	int iData;
	struct Node* pNext;
	struct Node* pPre;
};

//创建队列空头
struct Node* Queue()
{
	//创建节点
	struct Node* pTemp = (struct Node*)malloc(sizeof(struct Node));
	if (pTemp == NULL)
		return NULL;
	//空头节点初始化
	pTemp->iData = 0;
	pTemp->pNext = pTemp;
	pTemp->pPre = pTemp;
	//返回空头地址
	return pTemp;
}
//判断队列是否有节点
bool IsEmpty(struct Node* pQueue)
{
	//参数合法性检测
	//没有额外节点
	if (&pQueue == NULL || pQueue == NULL || pQueue->pNext == pQueue)
		return false;
	//有节点（除空头）
	else
		return true;
}
//队头节点（返回先出的节点，即尾节点，因为先进先出，这里采用头添加，那尾巴的节点先出）
struct Node* Front(struct Node* pQueue)
{
	//参数合法性检测
	if (IsEmpty(pQueue) == false)
		return NULL;
	else
		return pQueue->pPre;
}
//队尾节点（返回后出的节点，即头节点）
struct Node* Back(struct Node* pQueue)
{
	//参数合法性检测
	if (IsEmpty(pQueue) == false)
		return NULL;
	else
		return pQueue->pNext;
}
//入队（头添加）
void Push(struct Node* pQueue, int IData)
{
	//参数合法性检测
	if (pQueue == NULL || &pQueue == NULL)
		return;
	else
	{
		//创建新节点
		struct Node* pTemp = (struct Node*)malloc(sizeof(struct Node));
		if (pTemp == NULL)
			return;
		//节点赋值
		pTemp->iData = IData;
		pTemp->pNext = NULL;
		pTemp->pPre = NULL;
		//新节点与空头、头节点相连
		pTemp->pPre = pQueue;
		pTemp->pNext = pQueue->pNext;
		//原头节点与空头断开
		pQueue->pNext->pPre = pTemp;
		pQueue->pNext = pTemp;
	}
}
//出队（尾删除）
void Pop(struct Node* pQueue)
{
	//参数合法性检测
	if (IsEmpty(pQueue) == false)
		return;
	else
	{
		//记录尾节点
		struct Node* pTemp = pQueue->pPre;
		//将尾节点从链表独立开
		pTemp->pPre->pNext = pQueue;
		pQueue->pPre = pTemp->pPre;
		//释放这个独立开的节点
		free(pTemp);
	}
}
//释放
void Free(struct Node** pQueue)
{
	//参数合法性检测
	if (IsEmpty(*pQueue) == false)
	{
		free(*pQueue);
		*pQueue = NULL;
		return;
	}
		
	else
	{
		//从空头开始释放
		struct Node* pTemp = *pQueue;
		do {
			//记录当前节点
			struct Node* pT = pTemp;
			//指针向后遍历
			pTemp = pTemp->pNext;
			//释放节点
			free(pT);
		} while (pTemp != NULL);
	}
}

int main(void)
{
	//创建空头
	struct Node* pQueue = Queue();
	//判断队列是否有节点
	bool b = IsEmpty(pQueue);
	//入队（头添加）
	int arr[5] = { 9, 7, 5, 3, 1 };
	Push(pQueue, arr[0]);
	Push(pQueue, arr[1]);
	Push(pQueue, arr[2]);
	Push(pQueue, arr[3]);
	Push(pQueue, arr[4]);

	//判断队列是否有节点
	b = IsEmpty(pQueue);

	//出队
	Pop(pQueue);
	Pop(pQueue);
	Pop(pQueue);
	Pop(pQueue);
	Pop(pQueue);

	//释放
	Free(&pQueue);

	system("pause>0");
	return 0;
}