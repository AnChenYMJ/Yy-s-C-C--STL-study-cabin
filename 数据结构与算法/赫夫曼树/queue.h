#pragma once
#ifndef _PQUEUE_H
#define _PQUEUE_H

#include "queue.h"
#include "huffman.h"

//TYPEΪ�ڵ��ָ������
#define TYPE htNode *	//�������Ľ��ָ��
#define MAX_SZ 256

//����Ԫ�ؽṹ
typedef struct _pQueueNode
{
	TYPE val;					//���ڵ�ָ�룬ָ�����ڵ�
	unsigned int priority;		//���ȼ������ȼ�����Ϊ0������Ҫ��unsigned�������Ժ�д�ĳ�������������û����������ʹ���Ϊ�����������ɸ��˵���
	struct _pQueueNode* next;	//ָ����һ����Ԫ�أ��ɿ��ɼ�¼�������һ�ڵ�
}pQueueNode;

//���еĽṹ
typedef struct _pQueue
{
	unsigned int size;			//���ȣ����еĳ��ȣ������ж�������ʱ���Ƿ������һ��Ԫ�ص�
	pQueueNode* first;			//ָ��ǰ���жӶ�Ԫ��
}pQueue;

//���г�ʼ��
void initpQueue(pQueue** queue);
//����Ķ������ڵ�val�����ȼ����ϳ�Ԫ�أ�Ȼ����ӵ�����Ķ���queue��
void addpQueue(pQueue** queue, TYPE val, unsigned int priority);
//��öӶ�Ԫ�صĶ������ڵ㣬��ɾ���Ӷ�
TYPE getpQueue(pQueue** queue);

#endif