#include <stdio.h>
#include <stdlib.h>		//system的头文件
#include <stdbool.h>
#include <malloc.h>

//宏
#define Num 10

struct Node
{
	int arr[Num];		//数组装数据
	int iCount;			//计数，栈装了多少元素
};

//创建栈（数组）
struct Node* Stack();
//压栈（添加元素）
void Push(struct Node* pStack, int IData);
//判断栈是否有元素
bool IsEmpty(struct Node* pStack);
//释放栈
void FreeStack(struct Node** pStack);
//获取栈顶，不删除
int Top(struct Node* pStack);
//删除栈顶
void Pop(struct Node* pStack);


int main(void)
{
	//创建栈
	struct Node* ST = Stack();
	//判断栈是否有元素
	bool b = IsEmpty(ST);
	//压栈
	int arr[5] = { 5, 6, 8, 3, 1 };
	Push(ST, arr[0]);
	Push(ST, arr[1]);
	Push(ST, arr[2]);
	Push(ST, arr[3]);
	Push(ST, arr[4]);

	//判断栈是否有元素
	b = IsEmpty(ST);
	//出栈
	arr[0] = Top(ST);
	Pop(ST);
	arr[1] = Top(ST);
	Pop(ST);
	arr[2] = Top(ST);
	Pop(ST);
	arr[3] = Top(ST);
	Pop(ST);
	arr[4] = Top(ST);
	Pop(ST);

	//判断栈是否有元素
	b = IsEmpty(ST);
	//释放栈
	FreeStack(&ST);


	system("pause>0");
	return 0;
}


struct Node* Stack()
{
	//创建栈空间
	struct Node* pTemp = (struct Node*)malloc(sizeof(struct Node));
	if (pTemp == NULL)
		return NULL;
	//计数从0开始（数组就不用初始化了）
	pTemp->iCount = 0;
	//返回栈空间地址
	return pTemp;
}
void Push(struct Node* pStack, int IData)
{
	//参数合法性检测
	if (&pStack == NULL || pStack == NULL)
		return;
	//添加元素,此时计数当下标用
	pStack->arr[pStack->iCount] = IData;
	//计数+1
	pStack->iCount += 1;
}
bool IsEmpty(struct Node* pStack)
{
	//参数合法性检测
	if (&pStack == NULL || pStack == NULL)
		return false;
	//判断是否有元素
	if (pStack->iCount == 0 || pStack == NULL)
		return false;
	else
		return true;
}
void FreeStack(struct Node** pStack)
{
	//参数合法性检测
	if (pStack == NULL)
		return;
	//直接释放栈//哪怕*pStack为NULL也能释放
	free(*pStack);
	//赋值NULL
	*pStack = NULL;
}
int Top(struct Node* pStack)
{
	//参数合法性检测
	if (&pStack == NULL || pStack == NULL || pStack->iCount == 0)
		return 0;
	//返回数据//iCount是计数，下标比计数少1
	return pStack->arr[pStack->iCount - 1];
}
void Pop(struct Node* pStack)
{
	//参数合法性检测
	if (&pStack == NULL || pStack == NULL || pStack->iCount == 0)
		return;
	//栈顶因为是数组，故不用改变数据，不用它即可，再用就覆盖掉就行
	//如果没有元素
	if (IsEmpty(pStack) == 0)
		return;
	//如果有元素，计数-1
	pStack->iCount -= 1;
}

