#include "YK.h"

YK::YK()
{
	stHead.iData = 0;
	stHead.iNext = NULL;
}
YK::~YK()
{
	FreeList();
}

//增：尾添加
void YK::AddToTail( int pData)
{	//对比无空头单向链表，加深映像
	//参数合法性检测	
	if (stHead.iData < 0)
		return;	//注意顺序：iNodeCount == NULL在前，避免为NULL时进行了大小判断，导致程序崩溃

	//创建新节点
	struct Node* pTemp = new Node;
	//节点赋值
	if (pTemp == NULL)			//此处避免NULL可以有另一种方式，请查看无空头单向链表内容
		return;
	pTemp->iData = pData;
	pTemp->iNext = NULL;
	//找到尾节点地址
	struct Node* pt = &stHead;	//使用临时变量pt避免头指针丢失
	while (pt->iNext != NULL)
		pt = pt->iNext;
	//新节点接到尾节点上
	pt->iNext = pTemp;
	//计数变量++
	stHead.iData++;
}
//增：头添加
void YK::AddToHead(int pData)
{
	//创建新节点
	struct Node* pTemp = new Node;
	if (pTemp == NULL)
		return;
	//节点赋值
	pTemp->iData = pData;
	pTemp->iNext = NULL;			//因为接下来会对pTemp->iNext进行操作，但是这一步还是有必要的，为了保证严谨性
	//节点连接到空头后面，原第2节点前面
	struct Node* pt = stHead.iNext;//这个临时变量方便操作，否则下面指针的切换需要考虑顺序
	pTemp->iNext = pt;
	stHead.iNext = pTemp;			//画图理解，一目了然
	//计数增加
	stHead.iData += 1;
}
//增：指定数据后添加（按数据查找、1次加1个）
void YK::AddBeHandData(int iPosData, int pData)
{
	//参数合法性检测
	if (stHead.iData <= 0)
		return;//过滤空指针、链表没有节点（除空头）

	//从第2节点开始查找对应节点
	struct Node* pTemp = stHead.iNext;

	while (pTemp != NULL)
	{
		if (pTemp->iData == iPosData)	//*注意：我经常搞忘判断语句中：== 写成了 = 
			break;
		pTemp = pTemp->iNext;
	}
	//判断是否找到
	if (pTemp == NULL)	//未找到
	{
		cout << "\n未找到对应数据的节点\n";
		return;
	}
	else				//找到
	{
		//创建新节点
		struct Node* pT = new Node;
		if (pT == NULL)
			return;
		//节点赋值
		pT->iData = pData;
		pT->iNext = NULL;
		//新节点连接到查到的节点后面
		struct Node* pA = pTemp->iNext;
		pT->iNext = pA;
		pTemp->iNext = pT;
		//计数+1
		stHead.iData += 1;
	}
}
//增：指定下标位置添加节点(1个)
void YK::AddByIndex(int iPosIndex, int pData)
{
	//参数合法性检测
	if (iPosIndex > stHead.iData || iPosIndex < 0)
		return;//第1个判断：下标为总节点数-1，而数据个数也是总节点数-1（因为要除掉空头）故二者数值相等，所以这是下标不能越界的条件判断

	//寻找下标位置
	struct Node* pTemp = &stHead;
	for (int i = 0; i < iPosIndex; i++)
		pTemp = pTemp->iNext;
	//找到后，在该下标后添加节点	//在包括空头的下标看来，是在输入的下标节点后添加节点
	//创建新节点
	struct Node* pT = new Node;
	if (pT == NULL)
		return;
	//节点赋值
	pT->iData = pData;
	pT->iNext = NULL;		
	//新节点连接到查到的节点后面
	struct Node* pt = pTemp->iNext;
	pT->iNext = pt;
	pTemp->iNext = pT;			
	//计数+1
	stHead.iData += 1;
}
//增：指定下标位置添加节点(N个)
void YK::AddByIndex(int iPosIndex, int pCount, int pData)
{
	//参数合法性检测
	if (iPosIndex > stHead.iData || iPosIndex < 0)
		return;
	//查找节点
	struct Node* pTemp = &stHead;
	for (int i = 0; i < iPosIndex; i++)
		pTemp = pTemp->iNext;
	//利用循环在该位置添加N个节点
	for (int j = 0; j < pCount; j++)	//假设这几个边界值判断不清楚，等脑子清晰的时候，在纸上画图写数字来理解，不必每次都想清楚
	{									//清楚一次，然后使用就好了。主要要是测试与整体逻辑。
		//添加节点
		//创建新节点
		struct Node* pT = new Node;
		if (pT == NULL)
			return;
		//节点赋值
		pT->iData = pData;
		pT->iNext = NULL;			
		//新节点连接到查到的节点后面
		struct Node* pt = pTemp->iNext;
		pT->iNext = pt;
		pTemp->iNext = pT;			
		//计数增加
		stHead.iData += 1;
	}
}
//删：删除指定下标节点
void YK::DeleteByIndex(int pIndex)
{
	//参数合法性检测
	if (pIndex < 0 || pIndex > stHead.iData - 1)
		return;

	//因为需要下标的前一位，可能要用到空头，所以从空头开始
	struct Node* pTemp = &stHead;
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
	delete(pt);
	//计数-1
	stHead.iData -= 1;
}
//删：删除指定数据节点（N个）
void YK::DeleteAllByData(int pValue)
{
	//参数合法性检测
	if (stHead.iData <= 0)
		return;

	//从空头开始找（可能需要用空头这个节点）
	struct Node* pTemp = &stHead;
	//找到对应节点前一位
	while (pTemp->iNext != NULL)	//第一次这里的判断写成了pTemp != NULL是错的，我们要确保要操作的节点存在，而不是前一位存在就行
	{
		if (pTemp->iNext->iData == pValue)
		{
			//记录对应节点
			struct Node* pt = pTemp->iNext;
			//如A-B-C删B A->C 然后释放B
			pTemp->iNext = pt->iNext;
			delete(pt);
			//计数-1
			stHead.iData--;
			//跳回循环起始点继续循环
			continue;		//continue语句的作用是跳过本次循环体中余下尚未执行的语句，立即进行下一次的循环条件判定，可以理解为仅结束本次循环。
		}
		pTemp = pTemp->iNext;
	}

}
//删：删除重复的数据（去重）
void YK::DeleteSame()
{
	//原理是：从第一个结点开始（除空头）依次与后面的节点数据进行比较，重复的删除，故需要双层循环
	//参数合法性检测
	if (stHead.iData <= 0)
		return;

	//从第二个节点开始（除空头的第一个）
	struct Node* pWai = stHead.iNext;
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
				delete(pTemp);
				//计数-1
				stHead.iData -= 1;
				//跳到循环开始，重新循环比较 很重要，可以画图理解，作用是避免跳过1个节点比对，造成遗漏
				continue;
			}
			pNei = pNei->iNext;

		}
		pWai = pWai->iNext;
	}
}
//查找结点（根据数据）（找到第一个出现的）
struct Node* YK::FindNodeByData(int pData)
{
	//参数合法性检测
	if (stHead.iData <= 0)
		return NULL;
	//遍历查找
	struct Node* pTemp = &stHead;
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
struct Node* YK::FindNodeByIndex(int pIndex)
{
	//参数合法性检测
	if (stHead.iData <= 0 || pIndex > stHead.iData - 1 || pIndex < 0)
		return NULL;//此处的pIndex是从第2结点开始的下标（即：除空头的下标）
	//从第2节点开始
	struct Node* pTemp = stHead.iNext;
	if (pTemp == NULL)
		return NULL;
	//查找该下标
	for (int i = 0; i < pIndex; i++)
		pTemp = pTemp->iNext;
	return pTemp;
}
//修改节点数据（根据下标）
void YK::ChangeByIndex(int pIndex, int pValue)
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
void YK::ChangeByData(int pData, int pValue)
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
void YK::AllShow()
{	//因为不修改任何数据，所以可以以不传指针，这就相当于变量间赋值了，且注意变量调用成员用 . 指针调用成员用 ->
	//参数合法性检测	
	if (stHead.iData < 0)
		return;

	cout << "\n链表节点数为:" << stHead.iData << "  数据为 : ";
	//从第2个节点开始
	struct Node* pTemp = stHead.iNext;
	//循环打印
	while (pTemp != NULL)
	{
		cout << pTemp->iData << ' ';
		pTemp = pTemp->iNext;
	}
	cout << endl;
}
//释放空间
void YK::FreeList()
{
	//参数合法性检测
	if (stHead.iData == 0 || stHead.iData < 0)
		return;

	//记录第2个节点地址
	struct Node* pTemp = stHead.iNext;
	//从第2个节点开始释放
	if (pTemp != NULL)
	{
		while (pTemp != NULL)
		{
			struct Node* pt = pTemp;
			pTemp = pTemp->iNext;
			delete(pt);
		}
		//将空头设为唯一节点	（注意，如果空头是指针malloc的空间，则需要释放空间）
		stHead.iNext = NULL;
		stHead.iData = 0;
	}

}