#pragma once
#ifndef _HUFFMAN_H
#define _HUFFMAN_H

#include "queue.h"
#include "huffman.h"


//�������ڵ�ṹ
typedef struct _htNode
{
	char symbol;
	struct _htNode* left, * right;
}htNode;

//������
typedef struct _htTree
{
	htNode* root;
}htTree;

//�ɿ�������ڵ㣬���ڼ�¼
typedef struct _hlNode
{
	char symbol;			//��¼������������λ�����ַ�����
	char* code;				//�շ����������Ӹ��ڵ㿪ʼ�����������ڵ��Ӧ�Ķ������ڵ��߹���·��������������Ϊ0��������Ϊ1���������Ա���¼���� ��0001����·�����̵ĵ�ַ
	struct _hlNode* next;	//ָ����һ����ڵ�
}hlNode;

//�ɿ���������
typedef struct _hlTable
{
	hlNode* first;			//ͷָ��
	hlNode* last;			//βָ��
}hlTable;

htTree* buildTree(char* inputString);
hlTable* buildTable(htTree* huffmanTree);
void encode(hlTable* table, char* StringToEncode);
void decode(htTree* tree, char* stringToDecode);


#endif
