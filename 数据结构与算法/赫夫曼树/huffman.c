#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "queue.h"
#include "huffman.h"

//递归对二叉树的节点数据进行编码，根节点到对应的数据节点的路径用0 1 来记录，记录好的数据就是编好的码
void traverseTree(htNode* treeNode, hlTable** table, int k, char code[256])
{
	//如果当前节点没有分支了，即到达了叶子节点，赫夫曼树的叶子节点就是存放对应数据的节点
	if (treeNode->left == NULL && treeNode->right == NULL)
	{
		code[k] = '\0';		//给记录路径的字符串加结尾 \0 \0是字符串结束的标志
		//创建链表节点
		hlNode *aux = (hlNode*)malloc(sizeof(hlNode));
		if (aux == NULL)
			return;
		//链表节点成员aux->code申请字符数组空间，
		aux->code = (char*)malloc(sizeof(char) * (strlen(code) + 1));	//strlen返回字符串长度，不包括结束字符NULL，所以strlen(code) + 1
		//将记录好的当前节点的路径,即编码存入该链表节点成员中
		strcpy_s(aux->code, (strlen(code) + 1), code);
		//将当前树节点的数据存入当前链表节点
		aux->symbol = treeNode->symbol;
		//链表记录下一节点成员初始化
		aux->next = NULL;

		//如果此链表还没有节点，则头添加
		if ((*table)->first == NULL)
		{
			(*table)->first = aux;
			(*table)->last = aux;
		}
		//此链表已经有了节点，则尾添加
		else
		{
			//当前节点接到链表尾
			(*table)->last->next = aux;
			//(*table)->last是尾指针，尾指针记录新的尾节点
			(*table)->last = aux;
		}
	}

	//当前节点向左走
	if (treeNode->left != NULL)
	{
		code[k] = '0';	//记录一个0
		traverseTree(treeNode->left, table, k + 1, code);	//k + 1代表层数+1
	}

	//当前节点向右走
	if (treeNode->right != NULL)
	{
		code[k] = '1';
		traverseTree(treeNode->right, table, k + 1, code);
	}
}

//对树进行编码，且用链表方式存储
hlTable* buildTable(htTree* huffmantree)
{
	//可看成创建链表并初始化
	hlTable* table = (hlTable*)malloc(sizeof(hlTable));
	if (table == NULL)
		return NULL;
	table->first = NULL;
	table->last = NULL;

	char code[256];		//记录二叉树到节点的路径，向左走0，向右走1，这样记录路径，记录好的数据就是我们的编码
	int k = 0;			//记录二叉树当前节点层数，二叉树向下走一级就+1

	//对二叉树的数据节点进行链表化，且编码
	traverseTree(huffmantree->root, &table, k, code);
	return table;
}

//将传进来的字符串变成赫夫曼二叉树存储
htTree* buildTree(char* inputString)
{
	//申请数指针，用于统计传进来的字符出现的次数
	int* probability = (int*)malloc(sizeof(int) * 256);
	//至于为什么是256？因为ASCII码每个字符有8位，每位字符有0或1，那八位的总变化数为2^7 == 256,即每个字符最多有256种不一样的二进制码
	if (probability == NULL)
		return NULL;

	//使统计数组初始化为0
	for (int i = 0; i < 256; i++)
		probability[i] = 0;

	//统计字符串里对应字符出现的次数
	for (int j = 0; inputString[j] != '\0'; j++)
		probability[(unsigned char)inputString[j]]++;
	//统计过程：inputString[j]即字符串的对应位置的字符，直到字符为\0，'\0'是字符串的结尾（系统默认）
	//probability[]是int数组的对应下标的元素，一开始在上面每个元素都初始化成0，而这个数组下标也对应着ASCII码的字符对应的十进制数字
	//比如第1个字符是I，I的ASCII码十进制为73，那此时就为probability[73]++，即int数组的下标为73的元素+1，
	//那此时0+1 == 1，也就起到了统计该字符出现的次数，原理是用数组个元素来对应ASCII码的十进制编码。
	//这是C语言的书上的统计的例子，(unsigned char)可加可不加，是正数限定


	//创建队列
	pQueue* huffmanQueue;
	//队列初始化
	initpQueue(&huffmanQueue);

	//填充队列
	for (int k = 0; k < 256; k++)
	{
		//将统计中出现过的字符，插入到队列中，
		if (probability[k] != 0)
		{	//probability[k] == 0的话证明对应下标转换成的ASCII码字符没有出现过
			//创建二叉树节点
			htNode* aux = (htNode*)malloc(sizeof(htNode));
			//节点赋值
			aux->left = NULL;
			aux->right = NULL;
			aux->symbol = (char)k;	//将此时遍历到的k值转换成字符存入到symbol中，此时的k值是int数组的下标，数字上也对应着ASCII码的字符

			//当前节点aux及字符优先级整合成元素，然后添加到队列huffmanQueue中
			addpQueue(&huffmanQueue, aux, probability[k]);
			//上面有提过，probability[k]是对应字符出现的次数，那这里出现的次数就当作优先级使用
		}
	}

	//释放统计数组，因为经过上面循环，已经将字符串及字符出现次数存入到队列中了
	free(probability);

	//通过循环，将队列中的元素取出、整合成新元素，放入再取出整合，直到最后一个元素
	//（详情看赫夫曼二叉树的理论形成，这一步是赫夫曼二叉树的形成过程，从队列转换成赫夫曼二叉树）
	while (huffmanQueue->size != 1)
	{
		//记录队顶元素优先级（权值）
		int priority = huffmanQueue->first->priority;
		//将第1、第2元素的权值相加
		priority += huffmanQueue->first->next->priority;

		//获得队顶元素的二叉树节点，并删除队顶
		//将最外侧的两个节点（权最低的）取出来
		htNode* left = getpQueue(&huffmanQueue);
		htNode* right = getpQueue(&huffmanQueue);

		//创建新节点，并且让刚取出来的两低权值节挂到此节点下，此节点为那俩的根节点
		htNode* newNode = (htNode*)malloc(sizeof(htNode));
		newNode->left = left;
		newNode->right = right;

		//将刚创建的根节点、相加后的权值整合传入队列中，形成新的元素根据优先级（权值）插入到相应位置
		addpQueue(&huffmanQueue, newNode, priority);
	}

	//创建树（创建根节点）
	htTree* tree = (htTree*)malloc(sizeof(htTree));
	//将整合后的队列剩下的唯一元素的树节点取出，作为赫夫曼二叉树的根节点，因为经过循环，此时队列只有一个元素了
	tree->root = getpQueue(&huffmanQueue);
	//返回赫夫曼二叉树的root地址
	return tree;
}

//链表还原字符串并打印该字符串的编码
void encode(hlTable* table, char* stringToEncode)
{
	//创建临时链表节点
	hlNode* traversal;

	//打印编码前的字符串与相关提示，其实也不一定，我们输入什么他就打印什么
	printf("Encoding......\n\nInput string:\n%s\n\nEncoded string:\n", stringToEncode);

	//循环还原成字符串打印
	for (int i = 0; stringToEncode[i] != '\0'; i++)
	{
		//从链表第1个节点开始
		traversal = table->first;
		//循环找到对应字符的位置
		while (traversal->symbol != stringToEncode[i])
			traversal = traversal->next;
		//打印该字符对应的编码
		printf("%s", traversal->code);
	}
	printf("\n");
}

//根据输入的编码来输出赫夫曼树的字符
void decode(htTree* tree, char* stringToDecode)
{
	//创建临时树节点，且从根节点开始查找
	htNode* traversal = tree->root;

	//打印相关提示、输入的编码
	printf("\n\nDecoding......\n\nInput string:\n%s\n\nDEcoded string:\n", stringToDecode);

	//循环遍历，根据编码找到对应字符
	for (int i = 0; stringToDecode[i] != '\0'; i++)
	{
		//如果为叶子节点、则打印输出该节点字符，并回到根节点查找下一个字符
		if (traversal->left == NULL && traversal->right == NULL)
		{
			printf("%c", traversal->symbol);
			traversal = tree->root;
		}
		//如果编码数字是 0 向左走
		if (stringToDecode[i] == '0')
			traversal = traversal->left;
		//如果编码数字是 1 向右走
		if (stringToDecode[i] == '1')
			traversal = traversal->right;
		//如果编码数字非0 非1 则提示输入的编码不正确
		if (stringToDecode[i] != '0' && stringToDecode[i] != '1')
		{
			printf("The input string is not coded correctly!\n");
			return;
		}
	}

	//不清楚这一步的必要性、可能是确保没有打印遗漏
	if (traversal->left == NULL && traversal->right == NULL)
	{
		printf("%c", traversal->symbol);
		traversal = tree->root;
	}

	printf("\n");
}