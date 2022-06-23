#include "queue.h"
#include "huffman.h"
#include <stdio.h>
#include <stdlib.h>

//���г�ʼ��
void initpQueue(pQueue** queue)		//�������
{	//��2��ָ����Ϊ�˷�������ռ估���ó�Ա
	(*queue) = (pQueue*)malloc(sizeof(pQueue));
	if ((*queue) == NULL)
		return;
	(*queue)->first = NULL;			//���жӶ�Ԫ��ΪNULL
	(*queue)->size = 0;				//���г���Ϊ0
}

//����Ķ������ڵ�val�����ȼ����ϳ�Ԫ�أ�Ȼ����ӵ�����Ķ���queue��
void addpQueue(pQueue** queue, TYPE val, unsigned int priority)
{
	//������г��ȵ���256������ʾ��������
	if ((*queue)->size == MAX_SZ)
	{
		printf("\nQueue is full.\n");
		return;
	}

	//������Ľڵ�val�����ȼ�priority���ϳ�Ԫ��
	pQueueNode* aux = (pQueueNode*)malloc(sizeof(pQueueNode));
	if (aux == NULL)
		return;
	aux->priority = priority;	//aux->priority�Ǵ˽ڵ��һ����Ա�����ڼ�¼���ȼ�����priority�Ƕ�Ӧ�ַ����ֵĴ���
	aux->val = val;				//ͬ��aux->val��һ���ڵ��Ա�����ڼ�¼�������Ľڵ��ַ��val�Ǵ����õ������

	//Ԫ����ӵ�������
	//�������Ķ��л�û��Ԫ��ʱ.��Ԫ��auxװ�������е�һ��
	if ((*queue)->size == 0 || (*queue)->first == NULL)
	{
		aux->next = NULL;		
		(*queue)->first = aux;	
		(*queue)->size = 1;		//����+1
		return;
	}
	//��������Ѿ�����Ԫ��
	else
	{
		//�����ǰԪ�����ȼ����ڶӶ�Ԫ�أ�ͷ���
		if (priority <= (*queue)->first->priority)
		{
			aux->next = (*queue)->first;
			(*queue)->first = aux;
			(*queue)->size++;
			return;
		}
		//��ǰԪ�����ȼ����ڶӶ�Ԫ��
		else
		{
			//�ӶӶ�Ԫ�ؿ�ʼ������
			pQueueNode* iterator = (*queue)->first;
			//��������Ԫ��
			while (iterator->next != NULL)
			{
				//�ҵ����ȼ��ȱ�Ԫ�ظߵ�λ�ã�Ԫ�ز嵽��λ��ǰ
				if (priority <= iterator->next->priority)
				{
					//��λ��Ԫ���뵱ǰԪ������
					aux->next = iterator->next;
					//��λ�õ�ǰһλ��Ԫ������
					iterator->next = aux;
					(*queue)->size++;
					return;
				}
				//���±���
				iterator = iterator->next;
			}
			//��ʱiterator����ѭ��������βԪ�ص�λ��
			//�������ˣ�û�бȵ�ǰԪ�����ȼ��ߵģ�β��ӣ����У�ͷ��β�����Ƚ��ȳ���
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

//��öӶ�Ԫ�صĶ������ڵ㣬��ɾ���Ӷ�
TYPE getpQueue(pQueue** queue)
{
	//�����������ڵ㲢��ʼ��
	TYPE returnValue;
	returnValue = NULL;

	//������г��ȴ���0
	if ((*queue)->size > 0)
	{
		//��¼�Ӷ�Ԫ�صĶ������ڵ�
		returnValue = (*queue)->first->val;
		//ȥ���Ӷ�
		(*queue)->first = (*queue)->first->next;
		//���г���-1
		(*queue)->size--;
	}
	//�������û��Ԫ�أ���ʾ���п���
	else
		printf("\nQueue is empty.\n");
	//����ȡ���ĶӶ�Ԫ�صĶ������ڵ�
	return returnValue;
}