#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>	//C语言使用bool类型需要头文件

//栈介绍
void AAA()
{
	//栈与递归
	if (1)
	{
		//栈：是一种对线性表的操作限定，或者说一种操作方式法（算法）
		//只能对同一端进行操作，增删等等，比如链表只从头位置进行操作，不能头尾一起操作，只能同时在同端操作
		//操作对象可以是数组、链表、栈与递归等
		//一般的功能：创建栈、判断栈是否为空、返回栈顶、删除栈顶，并返回节点（出栈）、增加元素（入栈、压栈）、释放栈
		//在上述的基础功能满足后，可以添加一点其它功能，（老师说一般不建议）
		//栈就像一个井，先装进的东西放到井底，由于只能从井口进出，所以先进的东西后面才能出来，所以这一特性叫：先进后出
		//栈的作用：用来实现递归的逻辑
		//递归的实现，就是进栈出栈的过程，但是递归的层数不能太多。而通过栈实现的递归逻辑，多少层都可以
		
		
		//笔试面试常考：二叉树的遍历，广度遍历、深度遍历等，都是靠栈来实现的
	
	}

}

struct Node
{
	int a;
	struct Node* pNext;
	struct Node* pPre;
};

//栈的创建：创建一个空头（本课时采用双向循环链表）
struct Node* Stack();
//压栈（尾添加）(可改成头添加头删除，总之要在同一端完成所有操作)
void Push(struct Node* StHead, int iData);
//判断栈里有没有元素
bool IsEmpty(struct Node* StHead);
//释放栈
void FreeStack(struct Node** StHead);
//获取栈顶不删除
struct Node* Top(struct Node* StHead);
//栈顶并删除
void Pop(struct Node* StHead);

int main(void)
{
	//空头
	struct Node* stHead = Stack();
	//判断栈里有没有元素
	bool b = IsEmpty(stHead);
	//压栈(入栈)
	Push(stHead, 1);
	Push(stHead, 2);
	Push(stHead, 3);
	Push(stHead, 4);
	Push(stHead, 5);
	//判断栈里有没有元素
	b = IsEmpty(stHead);
	//释放栈
	FreeStack(&stHead);


	//空头
	struct Node* Head = Stack();
	//判断栈里有没有元素
	bool a = IsEmpty(Head);
	//压栈(入栈)//进数据时为：12345
	int arr[5] = { 1, 2, 3, 4, 5 };
	Push(Head, arr[0]);
	Push(Head, arr[1]);
	Push(Head, arr[2]);
	Push(Head, arr[3]);
	Push(Head, arr[4]);
	//判断栈里有没有元素
	a = IsEmpty(Head);

	//出栈(从栈里取元素)//取数据时：54321，遵循先进后出，原因是只能在同一侧操作
	arr[0] = Top(Head)->a;
	Pop(Head);
	arr[1] = Top(Head)->a;
	Pop(Head);
	arr[2] = Top(Head)->a;
	Pop(Head);
	arr[3] = Top(Head)->a;
	Pop(Head);
	arr[4] = Top(Head)->a;
	Pop(Head);
	//判断栈里有没有元素
	a = IsEmpty(Head);
	//释放栈
	FreeStack(&Head);
	


	system("pause>0");
	return 0;
}


struct Node* Stack()
{
	//申请节点
	struct Node* pTemp = (struct Node*)malloc(sizeof(struct Node));
	if (pTemp == NULL)
		return NULL;
	//节点初始化（注意这是双向循环链表空头的初始化）
	pTemp->a = 0;
	pTemp->pNext = pTemp;
	pTemp->pPre = pTemp;
	//返回该空头地址
	return pTemp;
}
void Push(struct Node* StHead, int iData)
{
	//参数合法性检测
	if (&StHead == NULL || StHead == NULL)
		return;
	//创建新节点
	struct Node* pTemp = (struct Node*)malloc(sizeof(struct Node));
	if (pTemp == NULL)
		return;
	//节点赋值
	pTemp->a = iData;
	pTemp->pNext = NULL;
	pTemp->pPre = NULL;
	//将节点插入到尾节点后
	//新节点先与尾节点、头节点相连
	pTemp->pNext = StHead;
	pTemp->pPre = StHead->pPre;
	//原尾节点与头节点之间断开
	StHead->pPre->pNext = pTemp;
	StHead->pPre = pTemp;
}
bool IsEmpty(struct Node* StHead)
{
	//参数合法性检测
	if (&StHead == NULL || StHead == NULL)
		return false;
	//判断是否有元素（除空头外）
	if (StHead->pNext == StHead)
		return false;
	else
		return true;
}
void FreeStack(struct Node** StHead)
{
	//参数合法性检测
	if (StHead == NULL || *StHead == NULL)
		return;
	//从空头开始释放
	struct Node* pTemp = *StHead;
	//因为要从头释放，所以用do while 先执行一次再判断，否则第一次就直接跳过循环了
	do
	{
		//记录当前节点地址
		struct Node* pT = pTemp;
		//指针向下遍历
		pTemp = pTemp->pNext;
		//释放记录的节点
		free(pT);
	} while (pTemp != *StHead);

	//释放完，空头地址赋空
	*StHead = NULL;
}
struct Node* Top(struct Node* StHead)
{
	//参数合法性检测
	if (&StHead == NULL || StHead == NULL)
		return NULL;
	//如果该链表没有元素
	if (IsEmpty(StHead) == 0)
		return NULL;
	//有元素，返回尾节点
	else
		return StHead->pPre;
}
void Pop(struct Node* StHead)
{
	//参数合法性检测
	if (&StHead == NULL || StHead == NULL)
		return;
	//该链表没有元素
	if (IsEmpty(StHead) == 0)
		return;
	//有元素
	else
	{
		//记录尾节点
		struct Node* pTemp = StHead->pPre;
		//将该节点从链表上独立开
		pTemp->pPre->pNext = StHead;
		StHead->pPre = pTemp->pPre;
		//释放该节点
		free(pTemp);
	}
}
