#pragma once
#ifndef _HUFFMAN_H
#define _HUFFMAN_H

#include "queue.h"
#include "huffman.h"


//二叉树节点结构
typedef struct _htNode
{
	char symbol;
	struct _htNode* left, * right;
}htNode;

//创建树
typedef struct _htTree
{
	htNode* root;
}htTree;

//可看成链表节点，用于记录
typedef struct _hlNode
{
	char symbol;			//记录二叉树的数据位，即字符数据
	char* code;				//赫夫曼二叉树从根节点开始，到达此链表节点对应的二叉树节点走过的路径，比如向左走为0，向右走为1，那这个成员则记录类似 ‘0001’的路径过程的地址
	struct _hlNode* next;	//指向下一链表节点
}hlNode;

//可看成链表创建
typedef struct _hlTable
{
	hlNode* first;			//头指针
	hlNode* last;			//尾指针
}hlTable;

htTree* buildTree(char* inputString);
hlTable* buildTable(htTree* huffmanTree);
void encode(hlTable* table, char* StringToEncode);
void decode(htTree* tree, char* stringToDecode);


#endif
