#pragma once
#ifndef _PQUEUE_H
#define _PQUEUE_H

#include "queue.h"
#include "huffman.h"

//TYPE为节点的指针类型
#define TYPE htNode *	//二叉树的结点指针
#define MAX_SZ 256

//队列元素结构
typedef struct _pQueueNode
{
	TYPE val;					//树节点指针，指向树节点
	unsigned int priority;		//优先级，优先级不能为0，所以要加unsigned，否则以后写的程序可能有人利用缓冲区溢出，使其变为负数，做不可告人的事
	struct _pQueueNode* next;	//指向下一队列元素，可看成记录链表的下一节点
}pQueueNode;

//队列的结构
typedef struct _pQueue
{
	unsigned int size;			//长度：队列的长度，用来判断生成树时，是否到了最后一个元素等
	pQueueNode* first;			//指向当前队列队顶元素
}pQueue;

//队列初始化
void initpQueue(pQueue** queue);
//传入的二叉树节点val、优先级整合成元素，然后添加到传入的队列queue中
void addpQueue(pQueue** queue, TYPE val, unsigned int priority);
//获得队顶元素的二叉树节点，并删除队顶
TYPE getpQueue(pQueue** queue);

#endif