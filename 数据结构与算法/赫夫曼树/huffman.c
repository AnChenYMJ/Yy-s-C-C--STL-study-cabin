#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "queue.h"
#include "huffman.h"

//�ݹ�Զ������Ľڵ����ݽ��б��룬���ڵ㵽��Ӧ�����ݽڵ��·����0 1 ����¼����¼�õ����ݾ��Ǳ�õ���
void traverseTree(htNode* treeNode, hlTable** table, int k, char code[256])
{
	//�����ǰ�ڵ�û�з�֧�ˣ���������Ҷ�ӽڵ㣬�շ�������Ҷ�ӽڵ���Ǵ�Ŷ�Ӧ���ݵĽڵ�
	if (treeNode->left == NULL && treeNode->right == NULL)
	{
		code[k] = '\0';		//����¼·�����ַ����ӽ�β \0 \0���ַ��������ı�־
		//��������ڵ�
		hlNode *aux = (hlNode*)malloc(sizeof(hlNode));
		if (aux == NULL)
			return;
		//����ڵ��Աaux->code�����ַ�����ռ䣬
		aux->code = (char*)malloc(sizeof(char) * (strlen(code) + 1));	//strlen�����ַ������ȣ������������ַ�NULL������strlen(code) + 1
		//����¼�õĵ�ǰ�ڵ��·��,��������������ڵ��Ա��
		strcpy_s(aux->code, (strlen(code) + 1), code);
		//����ǰ���ڵ�����ݴ��뵱ǰ����ڵ�
		aux->symbol = treeNode->symbol;
		//�����¼��һ�ڵ��Ա��ʼ��
		aux->next = NULL;

		//���������û�нڵ㣬��ͷ���
		if ((*table)->first == NULL)
		{
			(*table)->first = aux;
			(*table)->last = aux;
		}
		//�������Ѿ����˽ڵ㣬��β���
		else
		{
			//��ǰ�ڵ�ӵ�����β
			(*table)->last->next = aux;
			//(*table)->last��βָ�룬βָ���¼�µ�β�ڵ�
			(*table)->last = aux;
		}
	}

	//��ǰ�ڵ�������
	if (treeNode->left != NULL)
	{
		code[k] = '0';	//��¼һ��0
		traverseTree(treeNode->left, table, k + 1, code);	//k + 1�������+1
	}

	//��ǰ�ڵ�������
	if (treeNode->right != NULL)
	{
		code[k] = '1';
		traverseTree(treeNode->right, table, k + 1, code);
	}
}

//�������б��룬��������ʽ�洢
hlTable* buildTable(htTree* huffmantree)
{
	//�ɿ��ɴ���������ʼ��
	hlTable* table = (hlTable*)malloc(sizeof(hlTable));
	if (table == NULL)
		return NULL;
	table->first = NULL;
	table->last = NULL;

	char code[256];		//��¼���������ڵ��·����������0��������1��������¼·������¼�õ����ݾ������ǵı���
	int k = 0;			//��¼��������ǰ�ڵ������������������һ����+1

	//�Զ����������ݽڵ�����������ұ���
	traverseTree(huffmantree->root, &table, k, code);
	return table;
}

//�����������ַ�����ɺշ����������洢
htTree* buildTree(char* inputString)
{
	//������ָ�룬����ͳ�ƴ��������ַ����ֵĴ���
	int* probability = (int*)malloc(sizeof(int) * 256);
	//����Ϊʲô��256����ΪASCII��ÿ���ַ���8λ��ÿλ�ַ���0��1���ǰ�λ���ܱ仯��Ϊ2^7 == 256,��ÿ���ַ������256�ֲ�һ���Ķ�������
	if (probability == NULL)
		return NULL;

	//ʹͳ�������ʼ��Ϊ0
	for (int i = 0; i < 256; i++)
		probability[i] = 0;

	//ͳ���ַ������Ӧ�ַ����ֵĴ���
	for (int j = 0; inputString[j] != '\0'; j++)
		probability[(unsigned char)inputString[j]]++;
	//ͳ�ƹ��̣�inputString[j]���ַ����Ķ�Ӧλ�õ��ַ���ֱ���ַ�Ϊ\0��'\0'���ַ����Ľ�β��ϵͳĬ�ϣ�
	//probability[]��int����Ķ�Ӧ�±��Ԫ�أ�һ��ʼ������ÿ��Ԫ�ض���ʼ����0������������±�Ҳ��Ӧ��ASCII����ַ���Ӧ��ʮ��������
	//�����1���ַ���I��I��ASCII��ʮ����Ϊ73���Ǵ�ʱ��Ϊprobability[73]++����int������±�Ϊ73��Ԫ��+1��
	//�Ǵ�ʱ0+1 == 1��Ҳ������ͳ�Ƹ��ַ����ֵĴ�����ԭ�����������Ԫ������ӦASCII���ʮ���Ʊ��롣
	//����C���Ե����ϵ�ͳ�Ƶ����ӣ�(unsigned char)�ɼӿɲ��ӣ��������޶�


	//��������
	pQueue* huffmanQueue;
	//���г�ʼ��
	initpQueue(&huffmanQueue);

	//������
	for (int k = 0; k < 256; k++)
	{
		//��ͳ���г��ֹ����ַ������뵽�����У�
		if (probability[k] != 0)
		{	//probability[k] == 0�Ļ�֤����Ӧ�±�ת���ɵ�ASCII���ַ�û�г��ֹ�
			//�����������ڵ�
			htNode* aux = (htNode*)malloc(sizeof(htNode));
			//�ڵ㸳ֵ
			aux->left = NULL;
			aux->right = NULL;
			aux->symbol = (char)k;	//����ʱ��������kֵת�����ַ����뵽symbol�У���ʱ��kֵ��int������±꣬������Ҳ��Ӧ��ASCII����ַ�

			//��ǰ�ڵ�aux���ַ����ȼ����ϳ�Ԫ�أ�Ȼ����ӵ�����huffmanQueue��
			addpQueue(&huffmanQueue, aux, probability[k]);
			//�����������probability[k]�Ƕ�Ӧ�ַ����ֵĴ�������������ֵĴ����͵������ȼ�ʹ��
		}
	}

	//�ͷ�ͳ�����飬��Ϊ��������ѭ�����Ѿ����ַ������ַ����ִ������뵽��������
	free(probability);

	//ͨ��ѭ�����������е�Ԫ��ȡ�������ϳ���Ԫ�أ�������ȡ�����ϣ�ֱ�����һ��Ԫ��
	//�����鿴�շ����������������γɣ���һ���Ǻշ������������γɹ��̣��Ӷ���ת���ɺշ�����������
	while (huffmanQueue->size != 1)
	{
		//��¼�Ӷ�Ԫ�����ȼ���Ȩֵ��
		int priority = huffmanQueue->first->priority;
		//����1����2Ԫ�ص�Ȩֵ���
		priority += huffmanQueue->first->next->priority;

		//��öӶ�Ԫ�صĶ������ڵ㣬��ɾ���Ӷ�
		//�������������ڵ㣨Ȩ��͵ģ�ȡ����
		htNode* left = getpQueue(&huffmanQueue);
		htNode* right = getpQueue(&huffmanQueue);

		//�����½ڵ㣬�����ø�ȡ����������Ȩֵ�ڹҵ��˽ڵ��£��˽ڵ�Ϊ�����ĸ��ڵ�
		htNode* newNode = (htNode*)malloc(sizeof(htNode));
		newNode->left = left;
		newNode->right = right;

		//���մ����ĸ��ڵ㡢��Ӻ��Ȩֵ���ϴ�������У��γ��µ�Ԫ�ظ������ȼ���Ȩֵ�����뵽��Ӧλ��
		addpQueue(&huffmanQueue, newNode, priority);
	}

	//���������������ڵ㣩
	htTree* tree = (htTree*)malloc(sizeof(htTree));
	//�����Ϻ�Ķ���ʣ�µ�ΨһԪ�ص����ڵ�ȡ������Ϊ�շ����������ĸ��ڵ㣬��Ϊ����ѭ������ʱ����ֻ��һ��Ԫ����
	tree->root = getpQueue(&huffmanQueue);
	//���غշ�����������root��ַ
	return tree;
}

//����ԭ�ַ�������ӡ���ַ����ı���
void encode(hlTable* table, char* stringToEncode)
{
	//������ʱ����ڵ�
	hlNode* traversal;

	//��ӡ����ǰ���ַ����������ʾ����ʵҲ��һ������������ʲô���ʹ�ӡʲô
	printf("Encoding......\n\nInput string:\n%s\n\nEncoded string:\n", stringToEncode);

	//ѭ����ԭ���ַ�����ӡ
	for (int i = 0; stringToEncode[i] != '\0'; i++)
	{
		//�������1���ڵ㿪ʼ
		traversal = table->first;
		//ѭ���ҵ���Ӧ�ַ���λ��
		while (traversal->symbol != stringToEncode[i])
			traversal = traversal->next;
		//��ӡ���ַ���Ӧ�ı���
		printf("%s", traversal->code);
	}
	printf("\n");
}

//��������ı���������շ��������ַ�
void decode(htTree* tree, char* stringToDecode)
{
	//������ʱ���ڵ㣬�ҴӸ��ڵ㿪ʼ����
	htNode* traversal = tree->root;

	//��ӡ�����ʾ������ı���
	printf("\n\nDecoding......\n\nInput string:\n%s\n\nDEcoded string:\n", stringToDecode);

	//ѭ�����������ݱ����ҵ���Ӧ�ַ�
	for (int i = 0; stringToDecode[i] != '\0'; i++)
	{
		//���ΪҶ�ӽڵ㡢���ӡ����ýڵ��ַ������ص����ڵ������һ���ַ�
		if (traversal->left == NULL && traversal->right == NULL)
		{
			printf("%c", traversal->symbol);
			traversal = tree->root;
		}
		//������������� 0 ������
		if (stringToDecode[i] == '0')
			traversal = traversal->left;
		//������������� 1 ������
		if (stringToDecode[i] == '1')
			traversal = traversal->right;
		//����������ַ�0 ��1 ����ʾ����ı��벻��ȷ
		if (stringToDecode[i] != '0' && stringToDecode[i] != '1')
		{
			printf("The input string is not coded correctly!\n");
			return;
		}
	}

	//�������һ���ı�Ҫ�ԡ�������ȷ��û�д�ӡ��©
	if (traversal->left == NULL && traversal->right == NULL)
	{
		printf("%c", traversal->symbol);
		traversal = tree->root;
	}

	printf("\n");
}