#include <stdio.h>
#include <stdlib.h>
#include <string.h>		//memcpy的头文件

//链表的很多思路都能在伪链表的比记录找到

struct Node
{	//此结构体字节排布方式：
	//以此结构体空间最大的成员的字节数为一个分段，此结构体为double（8字节），然后按成员顺序填装，不够的装入下一个分段，分段中按两端对齐排列
	//[i][i][i][i][ ][ ][ ][ ]	//此分段前4位装int类型的数据，后4位不装，因为塞不下double类型
	//[b][b][b][b][b][b][b][b]	//double类型独占一分段，8位，8字节
	//[c][c][ ][ ][N][N][N][N]	//此分段前2位装short类型数据，最后的成员Node*占据后4位（分段中按两端对齐排列）
	int iData;		//4字节
	double b;		//8字节		//在交换函数中有详细说明
	short c;		//2字节
	struct Node* iNext;			//x86是4字节，64位是8字节
};

//函数命名规范：每个单词首字母大写，或者单词间用 _ 隔开然后小写

//*增：尾添加
void AddToEnd(struct Node** pHead, struct Node** pEnd, int pData);

//（不必要）对照 尾添加的二级指针使用解惑
void ceshi(int b);

//（不必要）pEND的作用(此函数演示没有pEnd的情况)
void AddToEndNopEnd(struct Node** pHead, int pData);

//*增：头添加
void AddToHead(struct Node** pHead, struct Node** pEnd, int pData);

//*增：指定位置接入节点
void InsertNodeByIndex(struct Node** pHead, struct Node** pEnd, int pIndex, int pData);

//*增：一次增加数据为x的N个节点
void AddSomeNode(struct Node** pHead, struct Node** pEnd, int pCount, int pData);

//*删：头删除
void DeleteHead(struct Node** pHead, struct Node** pEnd);

//*删：尾删除
void DeleteEnd(struct Node** pHead, struct Node** pEnd);

//*删：删除指定数据节点	 (一次删一个)
struct Node* DeleteOneByData(struct Node** pHead, struct Node** pEnd, int iData);

//*删：删除指定数据节点	（一次删除多个重复的）
void DeleteAllByData(struct Node** pHead, struct Node** pEnd, int iData);

//*删：根据下标删除节点	 (一次删一个)
void DeleteDataByIndex(struct Node** pHead, struct Node** pEnd, int pIndex);

//*改：修改指定节点数据	（一次修改1个）
void ChangeData(struct Node* pHead, int iEesData, int pDesData);

//*改：修改相同数据的节点	（一次修改多个）方式1：（推荐）
void ChangeSomeData(struct Node* pHead, int iEesData, int pDesData);

//改：修改相同数据的节点	（一次修改多个）方式2：（麻烦了些）
void ChangeSomeData2(struct Node* pHead, int iEesData, int pDesData);

//遍历释放
void FreeList(struct Node* pHead);

//遍历释放 + 记录头尾的指针赋值NULL
void FreeListNULL(struct Node** pHead, struct Node** pEnd);

//*查：根据下标查找指定节点
struct Node* FindIndex(struct Node* pHead, int pIndex);

//*查：根据数据查找指定节点
struct Node* FindByData(struct Node* pHead, int pData);

//*交换两节点数据（根据数据查找）两种方式
void SwapByData(struct Node* pHead, struct Node* pEnd, int pData1, int pData2);

//*交换两节点数据（根据下标查找）两种方式
void SwapByIndex(struct Node* pHead, struct Node* pEnd, int pIndex1, int pIndex2);

//*交换指针指向（麻烦形式的交换节点）
void SwapByChangePoint(struct Node** pHead, struct Node** pEnd, int pIndex1, int pIndex2);

//*反转链表（数据翻转）
void ReverseByData(struct Node* pHead, struct Node* pEnd);

//*反转链表（节点翻转）
void ReverseByPoint(struct Node** pHead, struct Node** pEnd);

//*翻转链表（辅助空间）
void ReverseByHelpSpace(struct Node** pHead, struct Node** pEnd);

//链表节点数计数
int GetListNodeCount(struct Node* pHead);

//遍历打印
void AllShow(struct Node* pHead);


int main(void)
{
	struct Node* pHead = { NULL };	//初始化记录头尾节点的指针
	struct Node* pEnd  = { NULL };

	//尾添加
	AddToEnd(&pHead, &pEnd, 5);
	AddToEnd(&pHead, &pEnd, 1);
	AddToEnd(&pHead, &pEnd, 3);
	AddToEnd(&pHead, &pEnd, 2);

	AllShow(pHead);

//对照 尾添加的二级指针使用解惑
{
	int a = 0;
	ceshi(a);
	printf("%d \n",a);
}
	
//对照 没有pEnd的尾添加演示
{
	struct Node* pH1 = { NULL };	//初始化头节点的指针

	AddToEndNopEnd(&pH1, 51);
	AddToEndNopEnd(&pH1, 52);
	AddToEndNopEnd(&pH1, 53);
	AddToEndNopEnd(&pH1, 54);
	AddToEndNopEnd(&pH1, 55);

	AllShow(pH1);

	FreeList(pH1);
}

//遍历释放	+	记录头尾的指针赋值NULL
{
	FreeList(pHead);		//释放时，这三个要在一起，释放完必须给头尾赋值NULL，否则之前测试没有赋值NULL的话，再遍历输出此链表，就运行异常了
	pHead	= NULL;
	pEnd	= NULL;			//将这三个写在一个函数内即可

	AllShow(pHead);

	AddToEnd(&pHead, &pEnd, 45);
	AddToEnd(&pHead, &pEnd, 12);
	AddToEnd(&pHead, &pEnd, 23);
	AddToEnd(&pHead, &pEnd, 52);

	AllShow(pHead);

	FreeListNULL(&pHead, &pEnd);//将上述三个操作合成的新释放函数

	AllShow(pHead);
}

//头添加
{
	AddToHead(&pHead, &pEnd, -5);
	AddToEnd(&pHead, &pEnd, 61);
	AddToEnd(&pHead, &pEnd, 11);
	AddToHead(&pHead, &pEnd, -34);
	AddToEnd(&pHead, &pEnd, 71);
	AddToHead(&pHead, &pEnd, -8);
	AddToHead(&pHead, &pEnd, -72);
	AddToEnd(&pHead, &pEnd, 99);

	AllShow(pHead);					//添加成功

	FreeListNULL(&pHead, &pEnd);

	AllShow(pHead);
}

//根据下标查找数据
{
	AddToHead(&pHead, &pEnd, -5);
	AddToEnd(&pHead, &pEnd, 61);
	AddToEnd(&pHead, &pEnd, 11);
	AddToHead(&pHead, &pEnd, -34);
	AddToEnd(&pHead, &pEnd, 71);
	AllShow(pHead);

	//测试正常查找
	struct Node* pTemp = FindIndex(pHead, 2);
	if (pTemp)
		printf("\n对应下标的数据：%d\n", pTemp->iData);
	else
		printf("\n输入下标错误\n");
	
	//测试下标过大
	pTemp = FindIndex(pHead, 5);
	if (pTemp)
		printf("\n对应下标的数据：%d\n", pTemp->iData);
	else
		printf("\n输入下标下标错误\n");

	//测试下标过小
	pTemp = FindIndex(pHead, -5);
	if (pTemp)
		printf("\n对应下标的数据：%d\n", pTemp->iData);
	else
		printf("\n输入下标下标错误\n");


	FreeListNULL(&pHead, &pEnd);		//释放空间
}

//指定位置接入节点
{
	AddToHead(&pHead, &pEnd, -5);
	AddToEnd(&pHead, &pEnd, 61);
	AddToEnd(&pHead, &pEnd, 11);
	AllShow(pHead);

	InsertNodeByIndex(&pHead, &pEnd, 0, 996);
	AllShow(pHead);

	InsertNodeByIndex(&pHead, &pEnd, 2, 955);
	AllShow(pHead);

	//测试输入过大下标
	InsertNodeByIndex(&pHead, &pEnd, 11, 000);
	AllShow(pHead);

	FreeListNULL(&pHead, &pEnd);
}

//一次增加数据为x的N个节点
{
	//可以根据需要改成头添加、尾添加、指定位置添加
	AddToHead(&pHead, &pEnd, -34);
	AddToEnd(&pHead, &pEnd, 1);
	AddToHead(&pHead, &pEnd, 556);
	AddToEnd(&pHead, &pEnd, 3);
	AddSomeNode(&pHead, &pEnd, 3, 996);
	AddToHead(&pHead, &pEnd, 2);

	AllShow(pHead);

	FreeListNULL(&pHead, &pEnd);
}
	
//修改指定节点数据（一次改一个）
{
	AddToHead(&pHead, &pEnd, -34);
	AddToEnd(&pHead, &pEnd, 1);
	AddToHead(&pHead, &pEnd, 556);
	AddToEnd(&pHead, &pEnd, 3);
	AddSomeNode(&pHead, &pEnd, 3, 996);
	AddToHead(&pHead, &pEnd, 2);
	AllShow(pHead);

	ChangeData(pHead, 996, 955);	//只修改第一个被查到的节点数据
	AllShow(pHead);

	//测试没有的节点
	ChangeData(pHead, 888, 666);	//成功提示：查无此节点
	AllShow(pHead);

	FreeListNULL(&pHead, &pEnd);
}

//修改相同数据的节点（一次改N个）
{
	//有两种形式的函数写法
	AddToHead(&pHead, &pEnd, -34);
	AddToEnd(&pHead, &pEnd, 1);
	AddToHead(&pHead, &pEnd, 556);
	AddToEnd(&pHead, &pEnd, 3);
	AddSomeNode(&pHead, &pEnd, 3, 996);
	AddToHead(&pHead, &pEnd, 2);
	AllShow(pHead);

	//*方式1：	（推荐）
	ChangeSomeData(pHead, 996, 955);
	AllShow(pHead);
	//测试输入没有的数据
	ChangeSomeData(pHead, 22, 33);
	AllShow(pHead);

	//*方式2：	（麻烦了些）
	ChangeSomeData(pHead, 955, 996);
	AllShow(pHead);
	//测试输入没有的数据
	ChangeSomeData(pHead, 22, 33);
	AllShow(pHead);

	FreeListNULL(&pHead, &pEnd);
}

//头删除
{
	AddToHead(&pHead, &pEnd, -34);
	AddToEnd(&pHead, &pEnd, 1);
	AddToHead(&pHead, &pEnd, 556);
	AddToEnd(&pHead, &pEnd, 3);
	AddSomeNode(&pHead, &pEnd, 3, 996);
	AddToHead(&pHead, &pEnd, 2);
	AllShow(pHead);

	DeleteHead(&pHead, &pEnd);
	AllShow(pHead);

	//测试没有节点时头删除
	struct Node* pH1 = { NULL };	
	struct Node* pE1 = { NULL };
	AllShow(pH1);
	DeleteHead(&pH1, &pE1);
	AllShow(pH1);

	//测试只有一个节点时头删除
	printf("\n以下为1节点头删除：\n");
	InsertNodeByIndex(&pH1, &pE1, 0, 3);
	AllShow(pH1);
	DeleteHead(&pH1, &pE1);
	AllShow(pH1);

	FreeListNULL(&pH1, &pE1);
	FreeListNULL(&pHead, &pEnd);
}

//尾删除
{
	AddToHead(&pHead, &pEnd, 4);
	AddToEnd(&pHead, &pEnd, 2);
	AddToHead(&pHead, &pEnd, 5);
	AddToEnd(&pHead, &pEnd, 3);
	AllShow(pHead);

	DeleteEnd(&pHead, &pEnd);
	AllShow(pHead);

	DeleteEnd(&pHead, &pEnd);
	DeleteHead(&pHead, &pEnd);
	AllShow(pHead);
	//测试只有有一个节点时
	DeleteEnd(&pHead, &pEnd);
	AllShow(pHead);
	//测试链表没有节点时
	DeleteEnd(&pHead, &pEnd);
	AllShow(pHead);

	FreeListNULL(&pHead, &pEnd);
}

//删除指定数据节点（一次删一个）
{
	AddToHead(&pHead, &pEnd, 4);
	AddToEnd(&pHead, &pEnd, 2);
	AddToHead(&pHead, &pEnd, 5);
	AddToEnd(&pHead, &pEnd, 3);
	AllShow(pHead);

	if (DeleteOneByData(&pHead, &pEnd, 2) == NULL)
		printf("\n查无此节点\n");
	AllShow(pHead);

	//测试头删除
	if (DeleteOneByData(&pHead, &pEnd, 5) == NULL)
		printf("\n查无此节点\n");
	AllShow(pHead);

	//测试尾删除
	if (DeleteOneByData(&pHead, &pEnd, 3) == NULL)
		printf("\n查无此节点\n");
	AllShow(pHead);

	//测试删除不存在的节点
	if (DeleteOneByData(&pHead, &pEnd, 3) == NULL)
		printf("\n查无此节点\n");
	AllShow(pHead);
	
	FreeListNULL(&pHead, &pEnd);
}

//删除指定数据节点（一次删除多个重复的）
{
	AddToHead(&pHead, &pEnd, 4);
	AddToHead(&pHead, &pEnd, 5);
	AddToEnd(&pHead, &pEnd, 2);
	AddToEnd(&pHead, &pEnd, 2);
	AddToHead(&pHead, &pEnd, 5);
	AddToEnd(&pHead, &pEnd, 3);
	AllShow(pHead);

	DeleteAllByData(&pHead, &pEnd, 2);
	AllShow(pHead);

	DeleteAllByData(&pHead, &pEnd, 5);		//执行这句就运行异常报错了，找到原因了，详情看注释
	AllShow(pHead);

	FreeListNULL(&pHead, &pEnd);
}

//删除对应下标节点（一次删一个）
{
	AddToHead(&pHead, &pEnd, 4);
	AddToHead(&pHead, &pEnd, 5);
	AddToEnd(&pHead, &pEnd, 2);
	AddToEnd(&pHead, &pEnd, 2);
	AddToHead(&pHead, &pEnd, 5);
	AddToEnd(&pHead, &pEnd, 3);
	AllShow(pHead);

	//测试头删除
	DeleteDataByIndex(&pHead, &pEnd, 0);
	AllShow(pHead);
	//测试删除不存在的下标
	DeleteDataByIndex(&pHead, &pEnd, 10);
	AllShow(pHead);

	DeleteDataByIndex(&pHead, &pEnd, 1);
	DeleteDataByIndex(&pHead, &pEnd, 1);
	DeleteDataByIndex(&pHead, &pEnd, 1);
	DeleteDataByIndex(&pHead, &pEnd, 1);
	AllShow(pHead);

	//*（特殊）测试只有一个节点时，输入下标为1，老师的视频里没有这个边界值的考量
	DeleteDataByIndex(&pHead, &pEnd, 1);
	
	FreeListNULL(&pHead, &pEnd);
}

//交换两节点数据（根据数据查找）
{
	AddToHead(&pHead, &pEnd, 4);
	AddToHead(&pHead, &pEnd, 5);
	AddToEnd(&pHead, &pEnd, 2);
	AddToEnd(&pHead, &pEnd, 2);
	AddToHead(&pHead, &pEnd, 5);
	AddToEnd(&pHead, &pEnd, 3);
	AllShow(pHead);

	SwapByData(pHead, pEnd, 5, 3);	//经测试，两种方式都成功，
	AllShow(pHead);				//有重复数据的化，交换的是第一个被查到的数据

	FreeListNULL(&pHead, &pEnd);
}

//交换两节点数据（根据下标查找）
{
	AddToHead(&pHead, &pEnd, 4);
	AddToHead(&pHead, &pEnd, 5);
	AddToEnd(&pHead, &pEnd, 2);
	AddToEnd(&pHead, &pEnd, 2);
	AddToHead(&pHead, &pEnd, 5);
	AddToEnd(&pHead, &pEnd, 3);
	AllShow(pHead);

	SwapByIndex(pHead, pEnd, 0, 3);
	AllShow(pHead);

	SwapByIndex(pHead, pEnd, 0, 5);
	AllShow(pHead);
	//测试下标超出节点数
	SwapByIndex(pHead, pEnd, 6, 9);
	AllShow(pHead);

	FreeListNULL(&pHead, &pEnd);
}

//交换两节点指针指向
{	//测试时，尽量考虑到特殊情况（经验积累）
	AddToHead(&pHead, &pEnd, 4);
	AddToHead(&pHead, &pEnd, 5);
	AllShow(pHead);
	//头尾交换：两个节点时
	SwapByChangePoint(&pHead, &pEnd, 0, 1);
	AllShow(pHead);
	
	AddToHead(&pHead, &pEnd, 3);
	AddToHead(&pHead, &pEnd, 8);
	AllShow(pHead);
	//头尾交换：多个节点时
	SwapByChangePoint(&pHead, &pEnd, 0, 3);
	AllShow(pHead);

	AddToEnd(&pHead, &pEnd, 1);
	AddToEnd(&pHead, &pEnd, 9);
	AllShow(pHead);
	//头-中间交换：相邻时
	SwapByChangePoint(&pHead, &pEnd, 0, 1);
	AllShow(pHead);
	//头-中间交换：不相邻时
	SwapByChangePoint(&pHead, &pEnd, 0, 4);
	AllShow(pHead);

	AddToEnd(&pHead, &pEnd, 18);
	AddToHead(&pHead, &pEnd, 32);
	AllShow(pHead);
	//尾-中间交换:相邻时
	SwapByChangePoint(&pHead, &pEnd, 6, 7);
	AllShow(pHead);
	AddToEnd(&pHead, &pEnd, 77);
	AddToHead(&pHead, &pEnd, 45);
	//尾-中间交换:不相邻时
	SwapByChangePoint(&pHead, &pEnd, 1, 9);
	AllShow(pHead);
	
	AddToEnd(&pHead, &pEnd, 25);
	AllShow(pHead);
	//中间-中间交换：相邻
	SwapByChangePoint(&pHead, &pEnd, 4, 5);
	AllShow(pHead);
	AddToEnd(&pHead, &pEnd, 27);
	AddToHead(&pHead, &pEnd, 35);
	AllShow(pHead);
	//中间-中间交换：不相邻
	SwapByChangePoint(&pHead, &pEnd, 1, 9);
	AllShow(pHead);
	
	FreeListNULL(&pHead, &pEnd);
}

//翻转链表（2种方式）（原地翻转）
{
	AddToHead(&pHead, &pEnd, 2);
	AddToHead(&pHead, &pEnd, 1);
	AddToEnd(&pHead, &pEnd, 3);
	AddToEnd(&pHead, &pEnd, 4);
	AddToHead(&pHead, &pEnd, 0);
	AddToEnd(&pHead, &pEnd, 5);
	AllShow(pHead);
	//数据翻转
	ReverseByData(pHead, pEnd);
	AllShow(pHead);

	AddToEnd(&pHead, &pEnd, -1);
	AddToHead(&pHead, &pEnd, 6);
	AllShow(pHead);
	//节点翻转
	ReverseByPoint(&pHead, &pEnd);
	AllShow(pHead);

	AddToEnd(&pHead, &pEnd, 7);
	AddToHead(&pHead, &pEnd, -2);
	AllShow(pHead);

	FreeListNULL(&pHead, &pEnd);
}

//翻转链表（辅助空间）（逻辑更清晰，代码更简洁）
{
	AddToHead(&pHead, &pEnd, 2);
	AddToHead(&pHead, &pEnd, 1);
	AddToEnd(&pHead, &pEnd, 3);
	AddToEnd(&pHead, &pEnd, 4);
	AddToHead(&pHead, &pEnd, 0);
	AddToEnd(&pHead, &pEnd, 5);
	AddToEnd(&pHead, &pEnd, 6);
	AddToEnd(&pHead, &pEnd, 7);
	AddToEnd(&pHead, &pEnd, 8);
	AllShow(pHead);
	//翻转
	ReverseByHelpSpace(&pHead, &pEnd);
	AllShow(pHead);

	AddToEnd(&pHead, &pEnd, -1);
	AddToHead(&pHead, &pEnd, 9);
	AllShow(pHead);
	//添加后再翻转
	ReverseByHelpSpace(&pHead, &pEnd);
	AllShow(pHead);

	FreeListNULL(&pHead, &pEnd);
}


	system("pause>0");
	return 0;
}



//*增：尾添加
void AddToEnd(struct Node** pHead, struct Node** pEnd, int pData)
{	//此处用二级指针的原因还在探究，似乎是为了用*（）来操控原空间，用一级指针就不能操控，而是局部变量，无法改变原空间内容
	//二级指针，是为了要对pHead本身进行操作，也能操作pHead指向的空间
	//申请空间
	struct Node* pTemp = (struct Node*)malloc(sizeof(struct Node));

	//申请空间可能会失败，要进行空指针判断
	if (pTemp)
	{
		//空间赋值
		pTemp->iData = pData;
		pTemp->iNext = NULL;		//一定要是NULL，因为链表尾节点的iNext必须是NULL，原因请看伪链表的课件笔记

		//连接节点
		if (*pHead == NULL)			//当pHead与pEnd（外部的）都是NULL时，说明还没有任何节点，当一个不为NULL时两个都不为NULL，
		{							//所以pHead与pEnd有一个判断即可，不必写成（*pHead == NULL || *pEnd == NULL）
			*pHead = pTemp;			//节点赋值
			//*pEnd  = pTemp;
		}
		else
		{
			(*pEnd)->iNext = pTemp;	//原尾节点记录新节点地址
			//*pEnd = pTemp;
		}
		*pEnd = pTemp;				//pEnd记录新加节点的指针，而不是空间覆盖，（pEnd指针的作用是记录尾节点的地址，提高效率）pEnd是结构体指针，pTemp也是结构体指针，
	}							//结构体想要覆盖，必须要用=的运算符重载才行，所以不必担心覆盖问题。这点很高明，简单又复杂，此前还以为是数值覆盖。
}

//（不必要）对照 尾添加的二级指针使用解惑
void ceshi(int b)
{	//注意函数的形参是局部变量，与外部的不是同1个
	//对照尾添加对二级指针的使用，是为了用* （）来操控传进来的数据本身，一级指针就不能对传进来的本身进行操作
	b = 13;
}

//（不必要）pEND的作用(此函数演示没有pEnd的情况)
void AddToEndNopEnd(struct Node** pHead, int pData)
{
	//创建节点
	struct Node* pTemp = (struct Node*)malloc(sizeof(struct Node));

	//空指针检测
	if (pTemp != NULL)
	{
		//节点赋值
		pTemp->iData = pData;
		pTemp->iNext = NULL;

		//节点连上链表
		if (*pHead == NULL)			//没有节点时，*pHead == NULL
			*pHead = pTemp;
		else
		{
			struct Node* pt = *pHead;//用临时变量来记录节点头指针，原因是下面直接用节点头的话，到最后*pHead记录的地址就回不到原先位置，就丢失了，不再代表节点头

			while (pt->iNext != NULL)//用这种方式来寻找到尾节点的位置，当链表节点数一多，循环次数也就越来越多，每次添加节点都要循环一次
				pt = pt->iNext;		//一对比，用pEnd的好处就是避免了循环寻找尾节点位置，直接用指针pEnd记录当前尾节点地址，就不用寻找，直接知道位置，提高了效率

			pt->iNext = pTemp;		//连接新加节点
		}
	}


}

//*增：头添加
void AddToHead(struct Node** pHead, struct Node** pEnd, int pData)
{	//与尾添加对比发现，基本原理一样
	//创建节点
	struct Node* pTemp = (struct Node*)malloc(sizeof(struct Node));

	if (pTemp)
	{
		//节点赋值
		pTemp->iData = pData;
		pTemp->iNext = NULL;

		//节点连接到链表
		if (*pHead == NULL)			//链表还没有节点时
		{
			//*pHead	= pTemp;	//发现两种情况都要将记录头节点地址的指针pHead记录新节点地址，所以可以写在{}外面，节省代码
			*pEnd = pTemp;
		}
		else						//链表有节点时
		{
			pTemp->iNext = *pHead;	//新节点的iNext记录原头节点地址
			//*pHead	= pTemp;
		}
		*pHead = pTemp;				//指针pHead记录新的头节点的地址
	}
}

//*增：指定位置接入节点
void InsertNodeByIndex(struct Node** pHead, struct Node** pEnd, int pIndex, int pData)
{
	//参数合法性检测
	if (pIndex < 0)		//没有判断pHead是否为NULL的原因是：就算为NULL还没有节点，这是个添加节点函数，没有节点也要	添加上去
	{
		printf("\n输入下标参数无效，请重新输入\n");
		return;
	}

	//如果下标为0，则头添加
	if (pIndex == 0)		
	{
		AddToHead(pHead, pEnd, pData);
	}						//此前链表没有节点，则会将该节点添加进去（写在AddToHead函数里）
	else
	{
		//找位置
		struct Node* pt = FindIndex(*pHead, pIndex - 1);
		if (pt != NULL)						//比如a c节点，b要取代c的位置（下标），那需要操作a的位置，故pIndex - 1
		{
			//创建节点
			struct Node* pTemp = (struct Node*)malloc(sizeof(struct Node));
			if (pTemp)
			{
				//节点赋值
				pTemp->iData = pData;
				pTemp->iNext = NULL;

				//连接节点，先连后断
				pTemp->iNext = pt->iNext;		//用a c 节点，b要插入到c的位置，b节点先记录c的地址
				pt->iNext = pTemp;				//然后a再将记录的地址修改为记录b，这样b就取代了c原本的位置
			}
			
		}
		else
			printf("\n查无此节点\n");
	}

}

//*增：一次增加数据为x的N个节点	//可以根据需要改成头添加、尾添加、指定位置添加
void AddSomeNode(struct Node** pHead, struct Node** pEnd, int pCount, int pData)
{
	//用循环调用添加函数即可
	for (int i = 0; i < pCount; i++)	//添加的函数我们不必再写一遍，浪费时间，调用其它添加函数就好了
	{
		AddToEnd(pHead, pEnd, pData);	//写的函数功能单一，这样通用性高，其他函数调用方便，写的太冗杂就不好调用了
	}
}

//*删：头删除
void DeleteHead(struct Node** pHead, struct Node** pEnd)
{	//函数命名规范：每个单词首字母大写，或者单词间用 _ 隔开然后小写
	//参数合法性检测
	if (*pHead == NULL)			//当链表为空时，没有节点，跳出函数
		return;
	if (*pHead == *pEnd)		//当链表只有一个节点时
	{							//(*pHead)->iNext == NULL的判断与(*pHead == *pEnd)是一样的，都表示链表只有一个节点时
		free(*pHead);
		*pHead	= NULL;			//当链表只有一个节点时，将空间释放，并且将记录头尾的指针赋值NULL
		*pEnd	= NULL;			//否则不赋值NULL的话，记录链表头尾的指针不知道记着什么了，链表就不存在了，再往链表加节点就会出错
	}
	else						//当有多个节点时
	{
		struct Node* pt = *pHead;//记录原头节点地址
		*pHead = pt->iNext;//将头指针记录新的头节点
		free(pt);				//释放原头节点空间
	}

}

//*删：尾删除
void DeleteEnd(struct Node** pHead, struct Node** pEnd)
{
	//参数合法性检测
	if (*pHead == NULL)
		return;
	//当只有一个节点时
	if (*pHead == *pEnd)
	{
		free(*pHead);
		*pHead	= NULL;
		*pEnd	= NULL;
	}
	else//当有多个节点时
	{
		struct Node* pt = *pHead;	//使用临时变量来存储地址，不要直接用pHead，这会改变pHead的内容，这样就找不到头节点了
		//寻找尾节点的前一个
		while (pt->iNext != *pEnd)	//找尾节点前一个原因：用A C 删C做例子，要用pt记录A，然后释放C，再将A的记录地址赋值NULL，pEnd记录新的尾节点A
		{							
			pt = pt->iNext;			//纠错：pt = (*pHead)->iNext;	之前这样写错了，因为*pHead没变，那pt永远在循环里==一个固定值出不去
		}				
		//此时pt就记录着尾节点的前一个
		free(*pEnd);
		*pEnd = pt;			//*pEnd记录新尾节点的地址
		pt->iNext = NULL;	//**注意，新的尾节点一定要把iNext赋值为NULL
	}
}

//*删：删除指定数据节点	 (一次删一个)
struct Node* DeleteOneByData(struct Node** pHead, struct Node** pEnd, int iData)
{
	//参数合法性检测
	if (*pHead == NULL)
		return NULL;

	if ((*pHead)->iData == iData)		//当该数据的节点是头节点时，头删除
	{
		DeleteHead(pHead, pEnd);		//*这里的参数pHead即外部传递进来的&pHead，因为函数参数是二级指针，故函数内的pHead也是二级指针，就是外部的&pHead
		return *pHead;					//返回值是为了给删除多个重复的函数使用的
	}
	else if ((*pEnd)->iData == iData)	//当该数据的节点是尾节点时，尾删除
	{
		DeleteEnd(pHead, pEnd);	
		return *pHead;					//这里也返回头指针，是因为单向链表是要从头遍历的，传尾就遍历不了了
	}
	else								//该数据是中间节点时
	{
		struct Node* pTemp = *pHead;
		//循环查找该节点的前一位
		while (pTemp->iNext != NULL)
		{
			if (pTemp->iNext->iData == iData)
				break;					//找到，跳出当前循环
			pTemp = pTemp->iNext;
		}
		if (pTemp->iNext != NULL)
		{								//用ABCD删B举例，A记录的指针变为记录C的地址，然后释放B的内容
			struct Node* pt = pTemp->iNext;//用一个临时变量存储该节点（B）的地址
			pTemp->iNext = pt->iNext;	//B指向C的地址变成A指向C
			free(pt);					//释放B的空间
			return pTemp;				//返回A的地址，让删除多个的函数从A开始继续查找删除（此前已经查找过了），避免掉从头开始查找，提高效率
										//老师一开始返回了C的地址，结果出错了，因为从C开始遍历，可能导致头删除，删掉C，这样ACD就断开了，链表断开就出错了
		}
		else							//pTemp->iNext == NULL 说明遍历后依旧没找到
		{
			//printf("\n查无此节点\n");	//一次删除多个DeleteAllByData函数中调用此函数，必定会执行此打印，故注释掉，在主函数中处理
			return NULL;
		}	
	}
}

//*删：删除指定数据节点	（一次删除多个重复的）
void DeleteAllByData(struct Node** pHead, struct Node** pEnd, int iData)
{
	//参数合法性检测
	if (*pHead == NULL)
		return;

	//记录删除指定节点DeleteOneByData函数返回值
	struct Node* pT = DeleteOneByData(pHead, pEnd, iData);//DeleteOneByData函数中自带头节点、尾节点的判断处理，我们就不用再写了
						//其实可以把函数调用直接写进函数判断中，但是用临时变量方便理解，且不会有什么影响
	//循环查找删除
	while (pT != NULL)	//返回不为NULL，则继续用DeleteOneByData函数循环查找删除
	{					// （记得加取地址符 & 
		pT = DeleteOneByData(pHead, pEnd, iData);	//**（错误参数！！）注意使用&pT的原因，请查看DeleteOneByData函数返回值注释
	}					//（正确参数！）也可以用pHead，但就是从头开始查找删除，浪费了效率，故从返回值开始继续查找
	//注意：我虽然用了pT，但连续删除两个5（头删除）后就异常报错了，不清楚原因,换成pHead就可以了
	//似乎找到原因了，因为这里传递了&pT，进行完头删除后，pT即代表了新的链表头指针，而此时主函数里的pHead还是被删除前的链表头指针，导致链表头指针丢失，不知道指向哪里（越界了）
	//找原因时断点查看数据因为各个函数里的*pHead名字一样，我以为与主函里的pHead是一样的，但其实不一样，这个循环里如果传递了&pT,那操作的对象是临时变量pT，而非主函数里的pHead
	//这样虽然pT记录了新的链表头，但它不是起到改变值的作用，而是记录返回值来判断的作用，导致主函数里的pHead记录的空间（原链表头）被释放，链表头丢失，起判断作用的pT记录了新的地址，
	//而后因为循环返回值成NULL退出循环的原因，pT变成了NULL，所以这里应该严谨的传递主函数里的pHead，不要按老师的方法，我卡这个问题卡了4小时，脑袋都晕了！
}	

//*删：根据下标删除节点	 (一次删一个)
void DeleteDataByIndex(struct Node** pHead, struct Node** pEnd, int pIndex)
{
	//参数合法性检测
	if (*pHead == NULL)
		return;

	//下标为0时，头删除
	if (pIndex == 0)
		DeleteHead(pHead, pEnd);
	else//下标不为0
	{
		//查找对应下标的前一个节点
		struct Node *pt = FindIndex(*pHead, pIndex - 1);
		if (pt != NULL)
		{
			//如果对应下标是尾节点，则需要尾删除
			if (pt->iNext == pEnd)		//这些临界条件要积累经验，出错了判断怎么回事
			{
				DeleteEnd(pHead, pEnd);			//因为不经过尾删除的话，记录尾节点的指针就会丢失（那块空间释放掉了）
				return;
			}
			//如果该节点不是尾节点，则继续
			struct Node* pT = pt->iNext;//ABC删B，让A变成记录C地址（B原先记录的内容），然后释放B
			if (pT != NULL)
			{
				pt->iNext = pT->iNext;
				free(pT);
			}
			else//当只有1个节点且输入下标为1时才会触发，因为上面是查找pIndex - 1，所以一定会触发这里
				printf("\n此提示仅会在只有一个节点，而下标为1时存在：下标错误！只剩1个节点，下标为0\n");
		}
		else
			printf("查无此节点\n");	//FindIndex函数中就有下标判断了,但那里是查找下标-1的节点，不是查对应下标
	}
}

//*改：修改指定节点数据	（一次修改1个）
void ChangeData(struct Node* pHead, int iEesData, int pDesData)
{	//因为是修改数据，而不是指针本身，所以传一级指针
	struct Node* pes = FindByData(pHead, iEesData);	//用一个临时变量记录FindByData的返回值，以免下面调用两次影响效率

	if (pes == NULL)				//没找到对应数据
		printf("\n查无此数据.\n");
	else							//找到了
	{
		pes->iData = pDesData;
	}
}

//*改：修改相同数据的节点	（一次修改多个）方式1：（推荐，更简洁高效）
void ChangeSomeData(struct Node* pHead, int iEesData, int pDesData)
{
	//参数合法性检测
	if (FindByData(pHead, iEesData) == NULL)
		printf("\n查无此节点\n");
	while (pHead != NULL)
	{
		if (pHead->iData == iEesData)
			pHead->iData = pDesData;
		pHead = pHead->iNext;
	}
}

//*改：修改相同数据的节点	（一次修改多个）方式2：（麻烦了些，效率低了一点）
void ChangeSomeData2(struct Node* pHead, int iEesData, int pDesData)
{
	////第一次查找
	struct Node* pea = FindByData(pHead, iEesData);//FindByData会对pHead进行参数合法性检测
	//参数合法性检测
	if (pea == NULL)
	{
		printf("\n查无此节点\n");
		return;					//没找到跳出函数
	}
	else//第一次修改
		pea->iData = pDesData;

	//再次查找
	while (pea != NULL)
	{
		pea = FindByData(pHead, iEesData);
		if (pea != NULL)		//因为全部找完后pea == NULL，所以加上这个判断防止进行NULL->iData的操作
			pea->iData = pDesData;
	}
}

//遍历释放
void FreeList(struct Node* pHead)
{	//使用一级指针的原因，这里传递的是外部的pHead的内容，我们是对这个内容进行操作，而不是对pHead本身进行操作
	struct Node* pTemp = pHead;		//加中间变量可处理这个警告：//警告	C6001	使用未初始化的内存“* pHead”。
									//不清楚原因，明明外部pHead都进行了合法赋值
	while (pTemp != NULL)
	{
		struct Node* pt = pTemp;	//使用临时变量来存储pHead变化前装的地址，否则直接释放pHead的话，就不能找到下一个节点的位置了
		pTemp = pTemp->iNext;
		free(pt);					//释放记录的地址指向的空间
	}
}

//*遍历释放 + 记录头尾的指针赋值NULL
void FreeListNULL(struct Node** pHead, struct Node** pEnd)
{	//因为要对外部的pHead本身进行操作，所以需要二级指针（参考尾添加与遍历释放）
	struct Node* pTempH = *pHead;	//为了处理警告，否则感觉多此一举，不清楚为什么有警告，逻辑都是对的

	while (pTempH != NULL)
	{
		struct Node* pt = pTempH;
		pTempH = pTempH->iNext;
		free(pt);
	}
	*pHead = NULL;
	*pEnd = NULL;
}

//*查：根据下标查找指定节点
struct Node* FindIndex(struct Node* pHead, int pIndex)
{
	int Num = 0;			//用一个数来计数比较输入下标

	//参数合法性检测
	if (pHead == NULL || pIndex < 0)
	{
		printf("\n输入为NULL/参数无效\n");
		return NULL;		//返回NULL，跳出函数
	}

	//查找过程
	while (pHead != NULL)	//书上说将判断写全，更规范，只写pHead按规范来的话，说明这个是boole类型的数
	{
		if (Num == pIndex)
			return pHead;	//找到返回当前节点地址，跳出函数
		Num++;
		pHead = pHead->iNext;
	}

	//没找到才执行下面
	printf("\n输入下标超出链表元素个数\n");	//没在上面循环中找到，说明下标过大，我们提示并返回NULL
	return NULL;
}

//*查：根据数据查找指定节点
struct Node* FindByData(struct Node* pHead, int pData)
{
	//参数合法性检测
	if (pHead == NULL)
		return NULL;
	//开始查找
	while (pHead != NULL)
	{
		if (pHead->iData == pData)
			return pHead;			//找到返回地址，跳出函数
		pHead = pHead->iNext;
	}
	//没找到
	return NULL;
}

//*交换两节点数据（根据数据查找）两种方式
void SwapByData(struct Node* pHead, struct Node* pEnd, int pData1, int pData2)
{
	//参数合法性检测
	if (pHead == NULL || pHead->iNext == NULL)
		return;//分别为：链表没有节点、链表只有一个节点 都不能进行交换

	//查找
	struct Node* pT1 = FindByData(pHead, pData1);
	struct Node* pT2 = FindByData(pHead, pData2);
	//有重复数据的化，交换的是第一个被查到的数据

	//两个节点都找到时继续
	if (pT1 != NULL && pT2 != NULL && pT1 != pT2)//排除有相同数据只找到一个节点的情况
	{
		////错误方式
		//struct Node p = *pT1;		//此种方式交换了两节点所有内容，包括指针
		//*pT1 = *pT2;				//就会导致链表的顺序被搞乱，且会丢失一段pT1到pT2的节点
		//*pT2 = p;					//用ABCDEFG交换CE来举例：按此方法交换后，顺序变成了ABCFG，DE丢失掉了，因为原先D指向E，修改后E又指向D


		////方式1：
		//int p1 = pT1->iData;		//交换两节点数据，注意，如果成员多，则不要漏掉对应成员，交换方式都一样
		//pT1->iData = pT2->iData;
		//pT2->iData = p1;

		//方式2：
		struct Node p2 = *pT1;		//注意算清成员字节数，就算有1万个成员也一样，注意要排除记录下一节点的地址成员
		memcpy(pT1, pT2, 20);		//string.h是这个交换函数的头文件,按字节数来交换，不交换指针的话，就得算清楚数据成员的字节大小
		memcpy(pT2, &p2, 20);		//结构体字节排布方式：详情看结构体声明。
		//以此结构体为例，int，double，short占了18个字节空间（int后有4字节空），还有short后2字节的空，除指针外总共20字节的数据空间
	}
	else if (pT1 == NULL)
		printf("\n第1个数据未找到\n");
	if (pT2 == NULL)
		printf("\n第2个数据未找到\n");
	if(pT1 == pT2)
		printf("\n一样的数据，只有一个节点，无法交换\n");
}

//*交换两节点数据（根据下标查找）
void SwapByIndex(struct Node* pHead, struct Node* pEnd, int pIndex1, int pIndex2)
{
	//参数合法性检测
	if (pHead == NULL || pHead->iNext == NULL || pIndex1 == pIndex2 || pIndex1 < 0 || pIndex2 < 0)
		return;//分别为：链表没有节点、链表只有一个节点、两下标相同、下标小于0

	//查找
	struct Node* pt1 = FindIndex(pHead, pIndex1);
	struct Node* pt2 = FindIndex(pHead, pIndex2);

	if (pt1 != NULL && pt2 != NULL)
	{
		//方式1：
		int p1 = pt1->iData;
		pt1->iData = pt2->iData;
		pt2->iData = p1;

		////方式2：
		//struct Node p2 = *pt1;
		//memcpy(pt1, pt2, 20);
		//memcpy(pt2, &p2, 20);
	}
	else if (pt1 == NULL)
		printf("\n第1个数据未找到\n");
	if (pt2 == NULL)
		printf("\n第2个数据未找到\n");
}

//*交换指针指向（麻烦形式的交换节点）
void SwapByChangePoint(struct Node** pHead, struct Node** pEnd, int pIndex1, int pIndex2)
{
	//我们在学习时，将代码存起来，这些实现链表的方式都是算法，存起来，然后改进，然后使用。

	//参数合法性检测	（尽量考虑到漏洞与特殊情况，避免BUG，积累经验）
	if (*pHead == NULL || (*pHead)->iNext == NULL || pIndex1 == pIndex2 || pIndex1 < 0 || pIndex2 < 0)
		return;//分别为：链表没有节点、链表只有一个节点、两下标相同、下标小于0

	//要确定下标的大小关系（因为链表节点有先后关系，我们要操作指针）
	int Mix = pIndex1;
	int Max = pIndex2;
	if (pIndex2 < pIndex1)		//这样就确保Max > Mix了，参数检测时过滤掉了二者相等的情况
	{
		Mix = pIndex2;
		Max = pIndex1;
	}
	//确定节点先后的好处还有：
	//因为 头\尾 节点与别的节点交换是特殊的，找 头\尾 节点，因为确定了先后的关系，只要用pMix来判断是否为 头\尾 节点即可
	//否则要用else if再判断Max

	//根据下标查找节点			//因为确保了下标大小关系，这里也确定了链表上pMix在pMax的前面
	struct Node* pMix = FindIndex(*pHead, Mix);
	struct Node* pMax = FindIndex(*pHead, Max);
	//找不到对应节点就终止函数
	if (pMix == NULL || pMax == NULL)
		return;

	//确保找到后，进行头-尾、头-中间、尾-中间三种情况判断	
	
	//头-尾交换	（2种情况）
	if (pMix == *pHead && pMax == *pEnd)		//头-尾、头-中间、尾-中间，三种情况是不一样的，所以要单独找出来
	{
		//1.链表只有2个节点情况
		if ((*pHead)->iNext == *pEnd)
		{																	//用AB交换来举例：
			//头尾指向转换						
			(*pEnd)->iNext = *pHead;										//1.从A->B变成B->A
			//给新的尾节点地址成员赋值NULL
			(*pHead)->iNext = NULL;											//2.给A的地址位赋值NULL
			//记录头尾地址的指针交换
			*pHead = *pEnd;				//此时一个节点同时被头尾记录指针记录	//3.然后pHead从记录A变成记B，此时B被pHead与pEnd同时记录
			*pEnd = (*pEnd)->iNext;		//此时完成头尾记录指针的交换			//4.再让pEnd变为记录A
		}
		//2.链表有多个节点情况
		else 
		{
			//查找尾节点的前一个	//上面参数已经筛选过，这里肯定3个节点以上，肯定能找到pMaxpre
			struct Node* pMaxpre = FindIndex(*pHead, Max-1);
			//头尾节点位置互换					//依旧用A-B-C-D来举例
			(*pEnd)->iNext = (*pHead)->iNext;	//变成D->B
			pMaxpre->iNext = *pHead;			//C->D变成C->A
			//给新的尾节点地址成员赋值NULL
			(*pHead)->iNext = NULL;				//A的地址成员赋值NULL
			//记录头尾地址的指针交换
			*pHead = *pEnd;						//pHead从记录A变成记录D，此时pEnd与pHead都记录D
			*pEnd = pMaxpre->iNext;			//pEnd从记录D，变成记录A，至此完成头尾交换，链表变成D-B-C-A
			//这里不能用两节点时的方式了，一定要用pMaxpre->iNext，
			//可以画图方便理解，(*pEnd)->iNext与(*pHead)->iNext都表示D的下一位（即节点B）
		}
	}
	//头-中间交换（2种情况）
	else if (pMix == *pHead && pMax != *pEnd)
	{
		//1.两个节点相邻
		if (pMix->iNext == pMax)
		{
			//改变两节点现指向			//用A-B-C举例：
			pMix->iNext = pMax->iNext;	//A->C,A改为指向C
			pMax->iNext = pMix;			//B->A,B改为指向A	变成了B-A-C
			//改变头记录指针
			*pHead = pMax;				//pHead记录新头节点B
		}
		//2.两节点不相邻
		else
		{
			//寻找pMax的前一位节点
			struct Node* Maxpre = FindIndex(*pHead, Max - 1);
			//记录第2个节点地址			//辅助变量影响不大，使用方便，记得使用理清思路，减少费脑
			struct Node* second = (*pHead)->iNext;
			//改变节点的指向				//用A-B-C-D-E举例：AD交换
			pMix->iNext = pMax->iNext;	//A->E
			pMax->iNext = second;		//D->B
			Maxpre->iNext = pMix;		//C->A		链表现在为D-B-C-A-E
			//改变头记录指针
			*pHead = pMax;
		}
	}
	//尾-中间交换（2种情况）
	else if (pMix != *pHead && pMax == *pEnd)
	{
		//1.相邻
		if (pMix->iNext == pMax)
		{
			//找到pMix的前一位节点		//用A-B-C交换BC举例：
			struct Node* p = FindIndex(*pHead, Mix - 1);
			//改变节点间的指向		
			p->iNext = pMax;			//A->C
			pMax->iNext = pMix;			//C->B	此时链表变成A-C-B
			//给新的尾节点iNext赋值NULL
			pMix->iNext = NULL;
			//改变尾节点记录指针
			*pEnd = pMix;
		}
		else
		{
			//分别找到pMix与pMax的前一位节点
			struct Node* pMixpre = FindIndex(*pHead, Mix - 1);
			struct Node* pMaxpre = FindIndex(*pHead, Max - 1);
			//改变节点间的指向			//用A-B-C-D-E换BE举例：
			pMixpre->iNext = pMax;		//A->E
			pMax->iNext = pMix->iNext;	//E->C
			pMaxpre->iNext = pMix;		//D->B		现在的链表顺序为：A-E-C-D-B
			//给新的尾节点iNext赋值NULL
			pMix->iNext = NULL;
			//改变尾节点记录指针
			*pEnd = pMix;
		}
	}
	//中间-中间交换（2种情况）
	else if (pMix != *pHead && pMax != *pEnd)
	{
		//相邻
		if (pMix->iNext == pMax)
		{
			//分别找到pMix的前一位、pMax的下一位节点
			struct Node* pMixPre = FindIndex(*pHead, Mix - 1);
			struct Node* pMaxNext = FindIndex(*pHead, Max + 1);

			//改变节点的指向			//用A-B-C-D交换BC举例：
			pMixPre->iNext = pMax;	//A->C
			pMax->iNext = pMix;		//C->B
			pMix->iNext = pMaxNext;	//B->D		交换后顺序：A-C-B-D
		}
		//不相邻
		else
		{
			//找到pMix前后两个节点	//找这些节点，是为了使交换的逻辑简单，不必把脑袋搞混，找一下不费什么事
			struct Node* pMixPre = FindIndex(*pHead, Mix - 1);
			struct Node* pMixNext = FindIndex(*pHead, Mix + 1);
			//找到pMax前后两个节点
			struct Node* pMaxPre = FindIndex(*pHead, Max - 1);
			struct Node* pMaxNext = FindIndex(*pHead, Max + 1);

			//改变结点指向			//用A-B-C-D-E-F交换BE举例：
			pMixPre->iNext = pMax;	//A->E
			pMax->iNext = pMixNext;	//E->C
			pMaxPre->iNext = pMix;	//D->B
			pMix->iNext = pMaxNext;	//B->F		交换后顺序：A-E-C-D-B-F
		}
	}
	//若是觉得指向改变难想，那么在纸上画出来就方便理解了，原理简单，只是写成代码有点复杂
}

//*翻转链表（数据翻转）（原地翻转）
void ReverseByData(struct Node* pHead, struct Node* pEnd)
{
	//参数合法性检测	//pHead == NULL的判断一定要写在前面，因为如果为NULL的话，读取iNext属于越界操作
	if (pHead == NULL || pHead->iNext == NULL)
		return;//过滤没有节点、只有一个节点

	//交换节点数据
	int i = 0; int j = GetListNodeCount(pHead)-1;	//让i j向中间靠拢
	for (; i < j; i++, j--)		//用A-B-C-D-E举例
	{							//A-E交换 B-D交换 C不交换，就实现了链表翻转
		SwapByIndex(pHead, pEnd, i, j);
	}
}

//*翻转链表（节点翻转）（原地翻转）
void ReverseByPoint(struct Node** pHead, struct Node** pEnd)
{	//使用二级指针的原因是要交换指针指向，需要改变pHead本身的内容
	//参数合法性检测
	if (*pHead == NULL || (*pHead)->iNext == NULL)
		return;//过滤没有节点、只有一个节点

	int i = 0; int j = GetListNodeCount(*pHead)-1;	//这里的J是当下标使用，所以要个数-1
	for (; i < j; i++, j--)
	{
		SwapByChangePoint(pHead, pEnd, i, j);
	}
}

//*翻转链表（辅助空间）（逻辑更清晰，代码更简洁）
void ReverseByHelpSpace(struct Node** pHead, struct Node** pEnd)
{	//二级指针：要对pHead本身进行操作
	//参数合法性检测
	if (*pHead == NULL || (*pHead)->iNext == NULL)
		return;//过滤：没有节点、只有一个节点

	//记录头指针，避免头指针丢失			//逻辑过程：
	struct Node* pTemp = *pHead;		//1.创建新链表
	//创建新链表							//2.原链表按顺序，将节点数据头添加到新链表	（实现了翻转）
	struct Node* pNewpHead = NULL;		//3.释放原空间
	struct Node* pNewpEnd = NULL;		//4.头尾记录指针记录新链表头尾，至此完成翻转

	//将旧链表的节点数据，按顺序头添加到新链表，在新链表就实现了翻转
	while (pTemp != NULL)
	{
		AddToHead(&pNewpHead, &pNewpEnd, pTemp->iData);
		pTemp = pTemp->iNext;
	}

	//释放原空间
	FreeListNULL(pHead, pEnd);

	//记录头尾的指针，记录新链表的头尾
	*pHead = pNewpHead;
	*pEnd = pNewpEnd;
}

//链表节点数计数
int GetListNodeCount(struct Node* pHead)
{
	//参数合法性检测
	if (pHead == NULL)
		return 0;

	int Num = 0;
	while (pHead != NULL)
	{
		Num++;
		pHead = pHead->iNext;
	}
	return Num;
}

//遍历打印
void AllShow(struct Node* pHead)
{
	printf("\n节点的元素数据为：");
	if (pHead)
	{
		while (pHead != NULL)
		{
			printf("%2d  ", pHead->iData);
			pHead = pHead->iNext;
		}
	}
	else
		printf(" 打印函数参数错误");

	putchar('\n');				//老师的演示，可能与printf一样的作用，但我输出"\n\n"变成了输出P，可能是输出字符，而不是字符串的
}
