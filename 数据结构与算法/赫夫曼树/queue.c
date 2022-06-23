#include "queue.h"
#include "huffman.h"
#include <stdio.h>
#include <stdlib.h>

//队列初始化
void initpQueue(pQueue** queue)		//传入队列
{	//传2级指针是为了方便申请空间及调用成员
	(*queue) = (pQueue*)malloc(sizeof(pQueue));
	if ((*queue) == NULL)
		return;
	(*queue)->first = NULL;			//队列队顶元素为NULL
	(*queue)->size = 0;				//队列长度为0
}

//传入的二叉树节点val、优先级整合成元素，然后添加到传入的队列queue中
void addpQueue(pQueue** queue, TYPE val, unsigned int priority)
{
	//如果队列长度到了256，则提示队列满了
	if ((*queue)->size == MAX_SZ)
	{
		printf("\nQueue is full.\n");
		return;
	}

	//将传入的节点val、优先级priority整合成元素
	pQueueNode* aux = (pQueueNode*)malloc(sizeof(pQueueNode));
	if (aux == NULL)
		return;
	aux->priority = priority;	//aux->priority是此节点的一个成员，用于记录优先级，而priority是对应字符出现的次数
	aux->val = val;				//同理：aux->val是一个节点成员，用于记录二叉树的节点地址，val是创建好的树结点

	//元素添加到队列中
	//如果传入的队列还没有元素时.则将元素aux装到队列中第一个
	if ((*queue)->size == 0 || (*queue)->first == NULL)
	{
		aux->next = NULL;		
		(*queue)->first = aux;	
		(*queue)->size = 1;		//长度+1
		return;
	}
	//如果队列已经有了元素
	else
	{
		//如果当前元素优先级低于队顶元素，头添加
		if (priority <= (*queue)->first->priority)
		{
			aux->next = (*queue)->first;
			(*queue)->first = aux;
			(*queue)->size++;
			return;
		}
		//当前元素优先级高于队顶元素
		else
		{
			//从队顶元素开始向后遍历
			pQueueNode* iterator = (*queue)->first;
			//遍历插入元素
			while (iterator->next != NULL)
			{
				//找到优先级比本元素高的位置，元素插到该位置前
				if (priority <= iterator->next->priority)
				{
					//该位置元素与当前元素连接
					aux->next = iterator->next;
					//该位置的前一位与元素连接
					iterator->next = aux;
					(*queue)->size++;
					return;
				}
				//向下遍历
				iterator = iterator->next;
			}
			//此时iterator经过循环正好是尾元素的位置
			//遍历完了，没有比当前元素优先级高的，尾添加（队列：头进尾出，先进先出）
			if (iterator->next == NULL)
			{
				aux->next = NULL;
				iterator->next = aux;
				(*queue)->size++;
				return;
			}
		}
	}	
}

//获得队顶元素的二叉树节点，并删除队顶
TYPE getpQueue(pQueue** queue)
{
	//创建二叉树节点并初始化
	TYPE returnValue;
	returnValue = NULL;

	//如果队列长度大于0
	if ((*queue)->size > 0)
	{
		//记录队顶元素的二叉树节点
		returnValue = (*queue)->first->val;
		//去掉队顶
		(*queue)->first = (*queue)->first->next;
		//队列长度-1
		(*queue)->size--;
	}
	//如果队列没有元素，提示队列空了
	else
		printf("\nQueue is empty.\n");
	//返回取到的队顶元素的二叉树节点
	return returnValue;
}