#include <stdio.h>
#include <stdlib.h>		//system的头文件
#include <string.h>		

//1.有空头链表（课前说明）
void AAA()
{
	//有空头链表操作逻辑更简便一些
	//链表的头节点不装数据，只装着第2个节点的地址，且永远都是链表头不变
	//头添加/删除，则是在第2节点前添加/删除，空头节点再指向新的第2节点
	//算法这东西不是一成不变的，我们学这些是前辈的经验，如果有需要，我们可以按照思考来修改
	
	//网上和学校教的链表大多数没有pEnd（记录尾节点），所以这个有空头的就演示没有pEnd的写法，逻辑都一样，只是要从头遍历寻找尾节点
	//本课演示：有空头单向链表、不加pEnd、加计数器（辅助使逻辑更简便）
	//自己可以尝试加上尾空头，学完就能看懂大部分的代码了，然后看自己缺什么
	//这一课我就不加多余的注释了，以后要是看不懂代码，没加注释的，可翻看有空头单向链表的注释

	//学完本课时了：老师讲了一下，有无空头，有无pEnd的区别
	//有空头：代码增、删逻辑上更简单，且空头一直存在，链表没有节点时，空头也不需要要赋值NULL
	//无空头：一些增删代码要繁琐一点、因为有pHead存在，链表没节点时，pHead要赋值NULL，
	//有pEnd：尾添加时效率大大增加（节点数越多越明显）、因为无需遍历查找尾节点，尾节点发生更替变化时，需要单独判断处理pEnd的指向
	//无pEnd：简化了代码逻辑，尾添加效率低
	//如何选择：有空头、无pEnd写代码要更轻松，但是实际应用中，尾添加需求是比较高的，还是用有空头、有pEnd要好
	//其实链表相较于图、二叉树、红黑树要简单很多很多了，用哪个也繁琐不了哪去。以求效率为准。
	//本课时没有写翻转函数，但整体逻辑与无空头的一样，
	//网上的代码，我们查看时要注意：可能因为链表结构有所不同，故函数代码就有变化，但整体逻辑差不多。所以看网上代码要注意它的链表结构是怎样的
}

struct Node
{
	int iData;
	struct Node* iNext;
};

//增：尾添加
void AddToTail		(struct Node* stHead, int pData);
//增：头添加
void AddToHead		(struct Node* stHead, int pData);
//增：指定数据后添加（按数据查找、1次加1个）
void AddBeHandData	(struct Node* stHead, int iPosData, int pData);
//增：指定下标位置添加节点(1个)
void AddByIndex		(struct Node* stHead, int iPosIndex, int pData);
//增：指定下标位置添加节点(N个)
void AddByIndex		(struct Node* stHead, int iPosIndex, int pCount, int pData);
//删：删除指定下标节点
void DeleteByIndex	(struct Node* stHead, int pIndex);
//删：删除指定数据节点（N个）
void DeleteAllByData(struct Node* stHead, int pValue);
//删：删除重复的数据（去重）
void DeleteSame		(struct Node* stHead);
//查找结点（根据数据）（找到第一个出现的）
struct Node* FindNodeByData	(struct Node* stHead, int pData);
//查找结点（根据下标）
struct Node* FindNodeByIndex(struct Node* stHead, int pIndex);
//修改节点数据（根据下标）
void ChangeByIndex	(struct Node stHead, int pIndex, int pValue);
//修改节点数据（根据数据）
void ChangeByData	(struct Node stHead, int pData, int pValue);
//遍历打印
void AllShow		(struct Node stHead);
//释放空间
void FreeList		(struct Node* stHead);

int main(void)
{
	//空头（结构体变量类型（类的对象类型））
	struct Node stHead = { 0, NULL };	//这种写法更方便，栈区变量，无需手动释放
	//int iNodeCount = 0;					//计数,本程序为了方便，把空头的数据位用来计数
	//可以把空头与计数写到全局区中，这样使用更方便，但是学习为了理解，还是放到主函数里

	//空头(指针类型对比)
	{
		//对比会发现，指针类型的创建，需要malloc空间、赋值、不使用了要手动释放
		//相对麻烦一些
		struct Node* pHead = (struct Node*)malloc(sizeof(struct Node));
		if (pHead != NULL)
		{
			pHead->iData = 0;		
			pHead->iNext = NULL;
		}
		free(pHead);
}	
	//尾添加：AddToTail（）
	{
		AddToTail(&stHead, 2);
		AddToTail(&stHead, 5);
		AddToTail(&stHead, 1);
		AddToTail(&stHead, 3);

		AllShow(stHead);
	}
	//释放链表空间
	{
		AllShow(stHead);

		FreeList(&stHead);
		AllShow(stHead);

		AddToTail(&stHead, 5);
		AddToTail(&stHead, 1);
		AllShow(stHead);

		FreeList(&stHead);
	}
	//头添加
	{
		AddToHead(&stHead, 3);
		AddToHead(&stHead, 1);
		AddToHead(&stHead, 2);
		AddToHead(&stHead, 5);

		AllShow(stHead);

		AddToTail(&stHead, 7);

		AllShow(stHead);

		FreeList(&stHead);
		AllShow(stHead);
	}
	//指定数据后添加（按数据查找、1次加1个）
	{
		AddToHead		(&stHead, 3);
		AddToHead		(&stHead, 1);
		AddBeHandData	(&stHead, 1, 7);
		AllShow(stHead);
		AddBeHandData	(&stHead, 3, 9);
		AllShow(stHead);
		AddBeHandData	(&stHead, 9, 23);
		AllShow(stHead);
		AddToTail		(&stHead, 2);
		AllShow(stHead);

		AddBeHandData(&stHead, 11, 22);
		AllShow(stHead);

		FreeList(&stHead);
		AllShow(stHead);
	}
	//指定下标位置添加节点(一个与N个)
	{
		AddToHead(&stHead, 3);
		AddToHead(&stHead, 1);
		AddBeHandData(&stHead, 1, 7);
		AllShow(stHead);
		AddBeHandData(&stHead, 3, 9);
		AllShow(stHead);
		//插入一个节点
		AddByIndex(&stHead, 4, 2);
		AllShow(stHead);
		AddToHead(&stHead, 33);
		AddBeHandData(&stHead, 33, 66);
		AddToTail(&stHead, 22);
		AllShow(stHead);
		AddByIndex(&stHead, 0, 26);
		AllShow(stHead);
		//插入N个节点
		AddByIndex(&stHead, 9, 3, 996);
		AddByIndex(&stHead, 0, 1, 996);
		AllShow(stHead);
		AddToTail(&stHead, 22);
		AddToHead(&stHead, 33);
		AllShow(stHead);

		FreeList(&stHead);
		AllShow(stHead);
	}
	//查找结点
	{
		AddToHead(&stHead, 3);
		AddToHead(&stHead, 1);
		AddBeHandData(&stHead, 1, 7);
		AllShow(stHead);
		//根据数据查找
		struct Node* pt = FindNodeByData(&stHead, 3);
		if (pt == NULL)
			printf("\n该数据不存在\n");
		else
			printf("\n找到数据： %2d\n", pt->iData);

		AddByIndex(&stHead, 0, 26);
		AddByIndex(&stHead, 4, 27);
		AllShow(stHead);
		//根据下标查找
		pt = FindNodeByIndex(&stHead, 4);
		if (pt == NULL)
			printf("\n该下标错误/指针为NULL\n");
		else
			printf("\n找到数据： %2d\n", pt->iData);
		//
		pt = FindNodeByIndex(&stHead, 0);
		if (pt == NULL)
			printf("\n该下标错误/指针为NULL\n");
		else
			printf("\n找到数据： %2d\n", pt->iData);
		//测试下标超界
		pt = FindNodeByIndex(&stHead, 5);
		if (pt == NULL)
			printf("\n该下标错误/指针为NULL\n");
		else
			printf("\n找到数据： %2d\n", pt->iData);
		//测试下标过小
		pt = FindNodeByIndex(&stHead, -1);
		if (pt == NULL)
			printf("\n该下标错误/指针为NULL\n");
		else
			printf("\n找到数据： %2d\n", pt->iData);

		AddByIndex(&stHead, 0, 45);
		AddByIndex(&stHead, 4, 35);
		AllShow(stHead);

		FreeList(&stHead);
		AllShow(stHead);
	}
	//修改节点数据（根据下标）
	{
		AddToHead(&stHead, 3);
		AddToHead(&stHead, 1);
		AddBeHandData(&stHead, 1, 7);
		AddBeHandData(&stHead, 3, 7);
		AddByIndex(&stHead, 4, 2);
		AddToHead(&stHead, 33);
		AddBeHandData(&stHead, 33, 66);
		AddToTail(&stHead, 66);
		AllShow(stHead);

		//根据下标修改
		ChangeByIndex(stHead, 0, 5);
		ChangeByIndex(stHead, 7, 5);
		AllShow(stHead);

		//根据数据修改（N个）
		ChangeByData(stHead, 66, 11);
		AllShow(stHead);
		ChangeByData(stHead, 5, 996);
		AllShow(stHead);
		ChangeByData(stHead, 996, 27);
		AllShow(stHead);

		FreeList(&stHead);
		AllShow(stHead);
	}
	//删除指定下标节点
	{
		AddToTail(&stHead, 1);
		AddToTail(&stHead, 5);
		AddToHead(&stHead, 3);
		AllShow(stHead);

		DeleteByIndex(&stHead, 0);
		AllShow(stHead);

		AddToTail(&stHead, 9);
		AllShow(stHead);
		DeleteByIndex(&stHead, 2);
		AllShow(stHead);
		AddToTail(&stHead, 4);
		AllShow(stHead);

		FreeList(&stHead);
		AllShow(stHead);
	}
	//删除指定数据节点（N个）
	{
		AddToTail(&stHead, 1);
		AddToTail(&stHead, 5);
		AddToHead(&stHead, 3);
		AddToTail(&stHead, 5);
		AddToTail(&stHead, 5);
		AddToHead(&stHead, 1);
		AddToHead(&stHead, 1);
		AllShow(stHead);

		DeleteAllByData(&stHead, 1);
		AllShow(stHead);

		AddToHead(&stHead, 3);
		DeleteAllByData(&stHead, 5);
		AllShow(stHead);

		AddToTail(&stHead, 2);
		DeleteAllByData(&stHead, 3);
		AllShow(stHead);

		DeleteAllByData(&stHead, 2);
		AllShow(stHead);

		FreeList(&stHead);
		AllShow(stHead);
	}
	//删除重复的数据（去重）
	{
		AddToTail(&stHead, 1);
		AddToTail(&stHead, 5);
		AddToHead(&stHead, 3);
		AddToTail(&stHead, 5);
		AddToTail(&stHead, 5);
		AddToHead(&stHead, 1);
		AddToHead(&stHead, 1);
		AddToHead(&stHead, 3);
		AddToHead(&stHead, 2);
		AllShow(stHead);
		DeleteSame(&stHead);
		AllShow(stHead);
		AddToTail(&stHead, 5);
		AddToHead(&stHead, 1);
		AllShow(stHead);
		DeleteSame(&stHead);
		AllShow(stHead);

		FreeList(&stHead);
		AllShow(stHead);
	}

	//想要关掉控制台的，请按任意键继续的提示，在左侧，项目》链接器》系统》子系统》控制台 设置为：未设置
	system("pause>0");
	return 0;
}


//增：尾添加
void AddToTail(struct Node* stHead, int pData)
{	//对比无空头单向链表，加深映像
	//参数合法性检测	
	if (stHead == NULL || stHead->iData < 0)
		return;	//注意顺序：iNodeCount == NULL在前，避免为NULL时进行了大小判断，导致程序崩溃

	//创建新节点
	struct Node* pTemp = (struct Node*)malloc(sizeof(struct Node));
	//节点赋值
	if (pTemp == NULL)			//此处避免NULL可以有另一种方式，请查看无空头单向链表内容
		return;
	pTemp->iData = pData;
	pTemp->iNext = NULL;
	//找到尾节点地址
	struct Node* pt = stHead;	//使用临时变量pt避免头指针丢失
	while (pt->iNext != NULL)
		pt = pt->iNext;
	//新节点接到尾节点上
	pt->iNext = pTemp;
	//计数变量++
	stHead->iData++;
}
//增：头添加
void AddToHead(struct Node* stHead, int pData)
{
	//参数合法性检测
	if (stHead == NULL)
		return;

	//创建新节点
	struct Node* pTemp = (struct Node*)malloc(sizeof(struct Node));
	if (pTemp == NULL)
		return;
	//节点赋值
	pTemp->iData = pData;
	pTemp->iNext = NULL;			//因为接下来会对pTemp->iNext进行操作，但是这一步还是有必要的，为了保证严谨性
	//节点连接到空头后面，原第2节点前面
	struct Node* pt = stHead->iNext;//这个临时变量方便操作，否则下面指针的切换需要考虑顺序
	pTemp->iNext = pt;
	stHead->iNext = pTemp;			//画图理解，一目了然
	//计数增加
	stHead->iData += 1;
}
//增：指定数据后添加（按数据查找、1次加1个）
void AddBeHandData(struct Node* stHead, int iPosData, int pData)
{
	//参数合法性检测
	if (stHead == NULL || stHead->iData <= 0)
		return;//过滤空指针、链表没有节点（除空头）

	//从第2节点开始查找对应节点
	struct Node* pTemp = stHead->iNext;

	while (pTemp != NULL)
	{
		if (pTemp->iData == iPosData)	//*注意：我经常搞忘判断语句中：== 写成了 = 
			break;
		pTemp = pTemp->iNext;
	}
	//判断是否找到
	if (pTemp == NULL)	//未找到
	{
		printf("\n未找到对应数据的节点\n");
		return;
	}
	else				//找到
	{
		//AddToHead(pTemp, pData);	//C3老师一开始写的方式，结果发现不对，因为执行了pTemp->iData += 1;（原本是计数+1）变成了这个节点+1
		//所以不要用这种方式，当然，如果我们计数单独使用一个变量，比如一开始的iNodeCount来计数，不改变节点数据，则可以用这种节省代码量的方式
		//老师又想到方法解决了：

		//查到的位置后面添加节点
		AddToHead(pTemp, pData);
		pTemp->iData -= 1;		//因为AddToHead中执行了pTemp->iData += 1;这里减回来即可
		//计数+1
		stHead->iData += 1;


		//以下的代码与上面这三行的运行结果、逻辑上是一样的

		////创建新节点
		//struct Node* pT = (struct Node*)malloc(sizeof(struct Node));
		//if (pT == NULL)
		//	return;
		////节点赋值
		//pT->iData = pData;
		//pT->iNext = NULL;
		////新节点连接到查到的节点后面
		//struct Node* pA = pTemp->iNext;
		//pT->iNext = pA;
		//pTemp->iNext = pT;
		////计数+1
		//stHead->iData += 1;
	}
}
//增：指定下标位置添加节点(1个)
void AddByIndex(struct Node* stHead, int iPosIndex, int pData)
{
	//参数合法性检测
	if (stHead == NULL || iPosIndex > stHead->iData || iPosIndex < 0)
		return;//第二个判断：下标为总节点数-1，而数据个数也是总节点数-1（因为要除掉空头）故二者数值相等，所以这是下标不能越界的条件判断

	//寻找下标位置
	struct Node* pTemp = stHead;
	for (int i = 0; i < iPosIndex; i++)
		pTemp = pTemp->iNext;
	//找到后，在该下标后添加节点	//在包括空头的下标看来，是在输入的下标节点后添加节点
	AddToHead(pTemp, pData);	//在除掉空头的下标看来，是替换掉输入的下标节点的位置
	pTemp->iData -= 1;
	stHead->iData += 1;
}
//增：指定下标位置添加节点(N个)
void AddByIndex(struct Node* stHead, int iPosIndex, int pCount, int pData)
{
	//参数合法性检测
	if (stHead == NULL || iPosIndex > stHead->iData || iPosIndex < 0)
		return;
	//查找节点
	struct Node* pTemp = stHead;
	for (int i = 0; i < iPosIndex; i++)
		pTemp = pTemp->iNext;
	//利用循环在该位置添加N个节点
	for (int j = 0; j < pCount; j++)	//假设这几个边界值判断不清楚，等脑子清晰的时候，在纸上画图写数字来理解，不必每次都想清楚
	{									//清楚一次，然后使用就好了。主要要是测试与整体逻辑。
		AddToHead(pTemp, pData);
		pTemp->iData -= 1;
		stHead->iData += 1;
	}
}
//删：删除指定下标节点
void DeleteByIndex(struct Node* stHead, int pIndex)
{
	//参数合法性检测
	if (stHead == NULL || pIndex < 0 || pIndex > stHead->iData - 1)
		return;

	//因为需要下标的前一位，可能要用到空头，所以从空头开始
	struct Node* pTemp = stHead;
	if (pTemp == NULL)
		return;
	//查找对应下标的前一节点
	for (int i = 0; i < pIndex; i++)
		pTemp = pTemp->iNext;

	//此时 pTemp 是对应下标的前一节点
	//记录对应下标
	struct Node* pt = pTemp->iNext;	//pt是我们要释放的节点
	//A-B-C删B，将A指向C
	pTemp->iNext = pt->iNext;
	//释放该节点
	free(pt);
	//计数-1
	stHead->iData -= 1;
}
//删：删除指定数据节点（N个）
void DeleteAllByData(struct Node* stHead, int pValue)
{
	//参数合法性检测
	if (stHead == NULL || stHead->iData <= 0)
		return;

	//从空头开始找（可能需要用空头这个节点）
	struct Node* pTemp = stHead;
	//找到对应节点前一位
	while (pTemp->iNext != NULL)	//第一次这里的判断写成了pTemp != NULL是错的，我们要确保要操作的节点存在，而不是前一位存在就行
	{
		if (pTemp->iNext->iData == pValue)
		{
			//记录对应节点
			struct Node* pt = pTemp->iNext;
			//如A-B-C删B A->C 然后释放B
			pTemp->iNext = pt->iNext;
			free(pt);
			//计数-1
			stHead->iData--;
			//跳回循环起始点继续循环
			continue;		//continue语句的作用是跳过本次循环体中余下尚未执行的语句，立即进行下一次的循环条件判定，可以理解为仅结束本次循环。
		}
		pTemp = pTemp->iNext;
	}

}
//删：删除重复的数据（去重）
void DeleteSame(struct Node* stHead)
{
	//原理是：从第一个结点开始（除空头）依次与后面的节点数据进行比较，重复的删除，故需要双层循环
	//参数合法性检测
	if (stHead == NULL || stHead->iData <= 0)
		return;

	//从第二个节点开始（除空头的第一个）
	struct Node* pWai = stHead->iNext;
	//第一层循环，遍历链表
	while (pWai != NULL)
	{
		//记录当前节点
		struct Node* pNei = pWai;
		//第二层循环，利用pWai->iData与剩下的节点对比查重删除,pNei用来控制循环
		while (pNei->iNext != NULL)
		{	//注意此处pNei->iNext是我们要操作对比（删除）的节点，故不要pNei != NULL 否则下面pNei->iNext->iData会崩溃，因为pNei->iNext为NULL的情况没有判断
			if (pWai->iData == pNei->iNext->iData)
			{
				//记录当前被查到重复的节点
				struct Node* pTemp = pNei->iNext;
				//如A-B-C删B A->C A指向C，然后释放B
				pNei->iNext = pTemp->iNext;
				//释放节点
				free(pTemp);
				//计数-1
				stHead->iData -= 1;
				//跳到循环开始，重新循环比较 很重要，可以画图理解，作用是避免跳过1个节点比对，造成遗漏
				continue;
			}
			pNei = pNei->iNext;

		}
		pWai = pWai->iNext;
	}
}
//查找结点（根据数据）（找到第一个出现的）
struct Node* FindNodeByData(struct Node* stHead, int pData)
{
	//参数合法性检测
	if (stHead == NULL || stHead->iData <= 0)
		return NULL;
	//遍历查找
	struct Node* pTemp = stHead;
	if (pTemp == NULL)
		return NULL;
	while (pTemp != NULL)
	{
		if (pTemp->iData == pData)
			break;		//找到，退出返回地址
		pTemp = pTemp->iNext;
	}
	return pTemp;		//找到了则返回地址，没找到的话pTemp == NULL，则返回了NULL
}
//查找结点（根据下标）
struct Node* FindNodeByIndex(struct Node* stHead, int pIndex)
{
	//参数合法性检测
	if (stHead == NULL || stHead->iData <= 0 || pIndex > stHead->iData - 1 || pIndex < 0)
		return NULL;//此处的pIndex是从第2结点开始的下标（即：除空头的下标）
	//从第2节点开始
	struct Node* pTemp = stHead->iNext;
	if (pTemp == NULL)
		return NULL;
	//查找该下标
	for (int i = 0; i < pIndex; i++)
		pTemp = pTemp->iNext;
	return pTemp;
}
//修改节点数据（根据下标）
void ChangeByIndex(struct Node stHead, int pIndex, int pValue)
{	//此处没传指针，相当于创建了个临时对象，然后赋值操作
	//参数合法性检测
	if (stHead.iData <= 0 || pIndex > stHead.iData - 1 || pIndex < 0)
		return;
	//从第2节点开始（第1节点是空头）
	struct Node* pTemp = stHead.iNext;
	if (pTemp == NULL)
		return;
	//循环查对应坐标该节点
	for (int i = 0; i < pIndex; i++)
		pTemp = pTemp->iNext;
	//修改节点数据
	pTemp->iData = pValue;
}
//修改节点数据（根据数据）
void ChangeByData(struct Node stHead, int pData, int pValue)
{
	//参数合法性检测
	if (stHead.iData <= 0)
		return;
	//从第2结点开始查找
	struct Node* pTemp = stHead.iNext;
	if (pTemp == NULL)
		return;
	//循环查找数据修改
	while (pTemp != NULL)
	{
		if (pTemp->iData == pData)
			pTemp->iData = pValue;
		pTemp = pTemp->iNext;
	}
}
//遍历打印
void AllShow(struct Node stHead)
{	//因为不修改任何数据，所以可以以不传指针，这就相当于变量间赋值了，且注意变量调用成员用 . 指针调用成员用 ->
	//参数合法性检测	
	if (&stHead == NULL || stHead.iData < 0)
		return;

	printf("\n链表节点数为:%2d  数据为:", stHead.iData);
	//从第2个节点开始
	struct Node* pTemp = stHead.iNext;
	//循环打印
	while (pTemp != NULL)
	{
		printf(" %2d", pTemp->iData);
		pTemp = pTemp->iNext;
	}
	putchar('\n');
}
//释放空间
void FreeList(struct Node* stHead)
{
	//参数合法性检测
	if (stHead == NULL || stHead->iData == 0 || stHead->iData < 0)
		return;

	//记录第2个节点地址
	struct Node* pTemp = stHead->iNext;
	//从第2个节点开始释放
	if (pTemp != NULL)
	{
		while (pTemp != NULL)
		{
			struct Node* pt = pTemp;
			pTemp = pTemp->iNext;
			free(pt);
		}
		//将空头设为唯一节点	（注意，如果空头是指针malloc的空间，则需要释放空间）
		stHead->iNext = NULL;
		stHead->iData = 0;
	}

}