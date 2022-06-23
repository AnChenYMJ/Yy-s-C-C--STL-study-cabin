#include "dl.h"

//构造函数
List::List()
{
	pHead = NULL;
	pEnd = NULL;
	iCount = 0;
}

//析构函数
List::~List()
{
	FreeListNULL();
}	 

//*增：尾添加
void List::AddToEnd( int pData)
{	//此处用二级指针的原因还在探究，似乎是为了用*（）来操控原空间，用一级指针就不能操控，而是局部变量，无法改变原空间内容
	//二级指针，是为了要对pHead本身进行操作，也能操作pHead指向的空间
	//申请空间
	struct Node* pTemp = new Node;

	//申请空间可能会失败，要进行空指针判断
	if (pTemp)
	{
		//空间赋值
		pTemp->iData = pData;
		pTemp->iNext = NULL;		//一定要是NULL，因为链表尾节点的iNext必须是NULL，原因请看伪链表的课件笔记

		//连接节点
		if (pHead == NULL)			//当pHead与pEnd（外部的）都是NULL时，说明还没有任何节点，当一个不为NULL时两个都不为NULL，
		{							//所以pHead与pEnd有一个判断即可，不必写成（*pHead == NULL || *pEnd == NULL）
			pHead = pTemp;			//节点赋值
			//*pEnd  = pTemp;
		}
		else
		{
			pEnd->iNext = pTemp;	//原尾节点记录新节点地址
			//*pEnd = pTemp;
		}
		pEnd = pTemp;				//pEnd记录新加节点的指针，而不是空间覆盖，（pEnd指针的作用是记录尾节点的地址，提高效率）pEnd是结构体指针，pTemp也是结构体指针，
	}							//结构体想要覆盖，必须要用=的运算符重载才行，所以不必担心覆盖问题。这点很高明，简单又复杂，此前还以为是数值覆盖。
}

//（不必要）对照 尾添加的二级指针使用解惑
void  List::ceshi(int b)
{	//注意函数的形参是局部变量，与外部的不是同1个
	//对照尾添加对二级指针的使用，是为了用* （）来操控传进来的数据本身，一级指针就不能对传进来的本身进行操作
	b = 13;
}

//（不必要）pEND的作用(此函数演示没有pEnd的情况)
void  List::AddToEndNopEnd(int pData)
{
	//创建节点
	struct Node* pTemp = new Node;

	//空指针检测
	if (pTemp != NULL)
	{
		//节点赋值
		pTemp->iData = pData;
		pTemp->iNext = NULL;

		//节点连上链表
		if (pHead == NULL)			//没有节点时，*pHead == NULL
			pHead = pTemp;
		else
		{
			struct Node* pt = pHead;//用临时变量来记录节点头指针，原因是下面直接用节点头的话，到最后*pHead记录的地址就回不到原先位置，就丢失了，不再代表节点头

			while (pt->iNext != NULL)//用这种方式来寻找到尾节点的位置，当链表节点数一多，循环次数也就越来越多，每次添加节点都要循环一次
				pt = pt->iNext;		//一对比，用pEnd的好处就是避免了循环寻找尾节点位置，直接用指针pEnd记录当前尾节点地址，就不用寻找，直接知道位置，提高了效率

			pt->iNext = pTemp;		//连接新加节点
		}
	}


}

//*增：头添加
void  List::AddToHead( int pData)
{	//与尾添加对比发现，基本原理一样
	//创建节点
	struct Node* pTemp = new Node;
	
	if (pTemp != NULL)
	{
		//节点赋值
		pTemp->iData = pData;
		pTemp->iNext = NULL;

		//节点连接到链表
		if (pHead == NULL)			//链表还没有节点时
		{
			//pHead	= pTemp;	//发现两种情况都要将记录头节点地址的指针pHead记录新节点地址，所以可以写在{}外面，节省代码
			pEnd = pTemp;
		}
		else						//链表有节点时
		{
			pTemp->iNext = pHead;	//新节点的iNext记录原头节点地址
			//pHead	= pTemp;
		}
		pHead = pTemp;				//指针pHead记录新的头节点的地址
	}
}

//*增：指定位置接入节点
void  List::InsertNodeByIndex( int pIndex, int pData)
{
	//参数合法性检测
	if (pIndex < 0)		//没有判断pHead是否为NULL的原因是：就算为NULL还没有节点，这是个添加节点函数，没有节点也要	添加上去
	{
		cout << "\n输入下标参数无效，请重新输入\n";
		return;
	}

	//如果下标为0，则头添加
	if (pIndex == 0)
	{
		AddToHead( pData);
	}						//此前链表没有节点，则会将该节点添加进去（写在AddToHead函数里）
	else
	{
		//找位置
		struct Node* pt = FindIndex( pIndex - 1);
		if (pt != NULL)						//比如a c节点，b要取代c的位置（下标），那需要操作a的位置，故pIndex - 1
		{
			//创建节点
			struct Node* pTemp = new Node;
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
			cout << "\n查无此节点\n";
	}

}

//*增：一次增加数据为x的N个节点	//可以根据需要改成头添加、尾添加、指定位置添加
void  List::AddSomeNode( int pCount, int pData)
{
	//用循环调用添加函数即可
	for (int i = 0; i < pCount; i++)	//添加的函数我们不必再写一遍，浪费时间，调用其它添加函数就好了
	{
		AddToEnd( pData);	//写的函数功能单一，这样通用性高，其他函数调用方便，写的太冗杂就不好调用了
	}
}

//*删：头删除
void  List::DeleteHead()
{	//函数命名规范：每个单词首字母大写，或者单词间用 _ 隔开然后小写
	//参数合法性检测
	if (pHead == NULL)			//当链表为空时，没有节点，跳出函数
		return;
	if (pHead == pEnd)			//当链表只有一个节点时
	{							//(*pHead)->iNext == NULL的判断与(*pHead == *pEnd)是一样的，都表示链表只有一个节点时
		delete(pHead);
		pHead = NULL;			//当链表只有一个节点时，将空间释放，并且将记录头尾的指针赋值NULL
		pEnd = NULL;			//否则不赋值NULL的话，记录链表头尾的指针不知道记着什么了，链表就不存在了，再往链表加节点就会出错
	}
	else						//当有多个节点时
	{
		struct Node* pt = pHead;//记录原头节点地址
		pHead = pt->iNext;		//将头指针记录新的头节点
		delete(pt);				//释放原头节点空间
	}

}

//*删：尾删除
void  List::DeleteEnd()
{
	//参数合法性检测
	if (pHead == NULL)
		return;
	//当只有一个节点时
	if (pHead == pEnd)
	{
		delete(pHead);
		pHead = NULL;
		pEnd = NULL;
	}
	else//当有多个节点时
	{
		struct Node* pt = pHead;	//使用临时变量来存储地址，不要直接用pHead，这会改变pHead的内容，这样就找不到头节点了
		//寻找尾节点的前一个
		while (pt->iNext != pEnd)	//找尾节点前一个原因：用A C 删C做例子，要用pt记录A，然后释放C，再将A的记录地址赋值NULL，pEnd记录新的尾节点A
		{
			pt = pt->iNext;			//纠错：pt = (*pHead)->iNext;	之前这样写错了，因为*pHead没变，那pt永远在循环里==一个固定值出不去
		}
		//此时pt就记录着尾节点的前一个
		delete(pEnd);
		pEnd = pt;			//*pEnd记录新尾节点的地址
		pt->iNext = NULL;	//**注意，新的尾节点一定要把iNext赋值为NULL
	}
}

//*删：删除指定数据节点	 (一次删一个)
struct Node* List::DeleteOneByData( int iData)
{
	//参数合法性检测
	if (pHead == NULL)
		return NULL;

	if (pHead->iData == iData)		//当该数据的节点是头节点时，头删除
	{
		DeleteHead();				
		return pHead;				//返回值是为了给删除多个重复的函数使用的
	}
	else if (pEnd->iData == iData)	//当该数据的节点是尾节点时，尾删除
	{
		DeleteEnd();
		return pHead;				//这里也返回头指针，是因为单向链表是要从头遍历的，传尾就遍历不了了
	}
	else							//该数据是中间节点时
	{
		struct Node* pTemp = pHead;
		//循环查找该节点的前一位
		while (pTemp->iNext != NULL)
		{
			if (pTemp->iNext->iData == iData)
				break;				//找到，跳出当前循环
			pTemp = pTemp->iNext;
		}
		if (pTemp->iNext != NULL)
		{								//用ABCD删B举例，A记录的指针变为记录C的地址，然后释放B的内容
			struct Node* pt = pTemp->iNext;//用一个临时变量存储该节点（B）的地址
			pTemp->iNext = pt->iNext;	//B指向C的地址变成A指向C
			delete(pt);					//释放B的空间
			return pTemp;				
										
		}
		else							//pTemp->iNext == NULL 说明遍历后依旧没找到
		{
			//cout << "\n查无此节点\n";	//一次删除多个DeleteAllByData函数中调用此函数，必定会执行此打印，故注释掉，在主函数中处理
			return NULL;
		}
	}
}

//*删：删除指定数据节点	（一次删除多个重复的）
void  List::DeleteAllByData( int iData)
{
	//参数合法性检测
	if (pHead == NULL)
		return;

	//记录删除指定节点DeleteOneByData函数返回值
	struct Node* pT = DeleteOneByData( iData);
	if(pT == NULL)
		cout << "\n查无此节点\n";
						
	//循环查找删除
	while (pT != NULL)	
	{					
		pT = DeleteOneByData( iData);	
	}					//（正确参数！）用pHead，但就是从头开始查找删除，浪费了效率
	
}

//*删：根据下标删除节点	 (一次删一个)
void  List::DeleteDataByIndex( int pIndex)
{
	//参数合法性检测
	if (pHead == NULL)
		return;

	//下标为0时，头删除
	if (pIndex == 0)
		DeleteHead();
	else//下标不为0
	{

		//查找对应下标的前一个节点
		struct Node* pt = FindIndex(pIndex - 1);
		if(pt != NULL)
		{
			//如果对应下标是尾节点，则需要尾删除
			if (pt->iNext == pEnd)		//这些临界条件要积累经验，出错了判断怎么回事
			{
				DeleteEnd();			//因为不经过尾删除的话，记录尾节点的指针就会丢失（那块空间释放掉了）
				return;
			}
			struct Node* pT = pt->iNext;//ABC删B，让A变成记录C地址（B原先记录的内容），然后释放B
			if (pT != NULL)
			{
				pt->iNext = pT->iNext;
				delete(pT);
			}
			else//当只有1个节点且输入下标为1时才会触发，因为上面是查找pIndex - 1，所以一定会触发这里
				cout << "\n此提示仅会在只有一个节点，而下标为1时存在：下标错误！只剩1个节点，下标为0\n";
		}
		else
			cout << "查无此节点\n";	//FindIndex函数中就有下标判断了,但那里是查找下标-1的节点，不是查对应下标
	}
}

//*改：修改指定节点数据	（一次修改1个）
void  List::ChangeData( int iEesData, int pDesData)
{	//因为是修改数据，而不是指针本身，所以传一级指针
	struct Node* pes = FindByData( iEesData);	//用一个临时变量记录FindByData的返回值，以免下面调用两次影响效率

	if (pes == NULL)				//没找到对应数据
		cout << "\n查无此数据.\n";
	else							//找到了
	{
		pes->iData = pDesData;
	}
}

//*改：修改相同数据的节点	（一次修改多个）方式1：（推荐，更简洁高效）
void  List::ChangeSomeData( int iEesData, int pDesData)
{
	//参数合法性检测
	if (FindByData(iEesData) == NULL)
		cout << "\n查无此节点\n";

	struct Node* pTemp = pHead;
	while (pTemp != NULL)
	{
		if (pTemp->iData == iEesData)
			pTemp->iData = pDesData;
		pTemp = pTemp->iNext;
	}
}

//*改：修改相同数据的节点	（一次修改多个）方式2：（麻烦了些，效率低了一点）
void  List::ChangeSomeData2( int iEesData, int pDesData)
{
	////第一次查找
	struct Node* pea = FindByData( iEesData);//FindByData会对pHead进行参数合法性检测
	//参数合法性检测
	if (pea == NULL)
	{
		cout << "\n查无此节点" << endl;
		return;					//没找到跳出函数
	}
	else//第一次修改
		pea->iData = pDesData;

	//再次查找
	while (pea != NULL)
	{
		pea = FindByData( iEesData);
		if (pea != NULL)		//因为全部找完后pea == NULL，所以加上这个判断防止进行NULL->iData的操作
			pea->iData = pDesData;
	}
}

//遍历释放
void  List::FreeList()
{	//使用一级指针的原因，这里传递的是外部的pHead的内容，我们是对这个内容进行操作，而不是对pHead本身进行操作
	struct Node* pTemp = pHead;		//加中间变量可处理这个警告：//警告	C6001	使用未初始化的内存“* pHead”。
									//不清楚原因，明明外部pHead都进行了合法赋值
	while (pTemp != NULL)
	{
		struct Node* pt = pTemp;	//使用临时变量来存储pHead变化前装的地址，否则直接释放pHead的话，就不能找到下一个节点的位置了
		pTemp = pTemp->iNext;
		delete(pt);					//释放记录的地址指向的空间
	}
}

//*遍历释放 + 记录头尾的指针赋值NULL
void  List::FreeListNULL()
{	//因为要对外部的pHead本身进行操作，所以需要二级指针（参考尾添加与遍历释放）
	struct Node* pTempH = pHead;	//为了处理警告，否则感觉多此一举，不清楚为什么有警告，逻辑都是对的
	//循环释放节点
	while (pTempH != NULL)
	{
		struct Node* pt = pTempH;
		pTempH = pTempH->iNext;
		delete(pt);
	}
	//头尾记录指针赋值NULL
	pHead = NULL;
	pEnd = NULL;
}

//*查：根据下标查找指定节点
struct Node* List::FindIndex( int pIndex)
{
	int Num = 0;			//用一个数来计数比较输入下标

	//参数合法性检测
	if (pHead == NULL || pIndex < 0)
	{
		cout << "\n输入为NULL/参数无效\n";
		return NULL;		//返回NULL，跳出函数
	}

	//改成C++就不能直接使用pHead了，会改变类内成员pHead的，设定一个临时变量来记录就好了
	struct Node* pTemp = pHead;
	//查找过程
	while (pTemp != NULL)
	{
		if (Num == pIndex)
			return pTemp;
		Num++;
		pTemp = pTemp->iNext;
	}
	//没找到才执行下面
	cout << "\n输入下标超出链表元素个数\n";	//没在上面循环中找到，说明下标过大，我们提示并返回NULL
	return NULL;
}

//*查：根据数据查找指定节点
struct Node* List::FindByData( int pData)
{
	//参数合法性检测
	if (pHead == NULL)
		return NULL;

	struct Node* pTemp = pHead;
	//开始查找
	while (pTemp != NULL)
	{
		if (pTemp->iData == pData)
			return pTemp;			//找到返回地址，跳出函数
		pTemp = pTemp->iNext;
	}
	//没找到
	return NULL;
}

//*交换两节点数据（根据数据查找）两种方式
void  List::SwapByData( int pData1, int pData2)
{
	//参数合法性检测
	if (pHead == NULL || pHead->iNext == NULL)
		return;//分别为：链表没有节点、链表只有一个节点 都不能进行交换

	//查找
	struct Node* pT1 = FindByData( pData1);
	struct Node* pT2 = FindByData( pData2);
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
		cout << "\n第1个数据未找到\n";
	if (pT2 == NULL)
		cout << "\n第2个数据未找到\n";
	if (pT1 == pT2)
		cout << "\n一样的数据，只有一个节点，无法交换\n";
}

//*交换两节点数据（根据下标查找）
void  List::SwapByIndex( int pIndex1, int pIndex2)
{
	//参数合法性检测
	if (pHead == NULL || pHead->iNext == NULL || pIndex1 == pIndex2 || pIndex1 < 0 || pIndex2 < 0)
		return;//分别为：链表没有节点、链表只有一个节点、两下标相同、下标小于0

	//查找
	struct Node* pt1 = FindIndex( pIndex1);
	struct Node* pt2 = FindIndex( pIndex2);

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
		cout << "\n第1个数据未找到\n";
	if (pt2 == NULL)
		cout << "\n第2个数据未找到\n";
}

//*交换指针指向（麻烦形式的交换节点）
void  List::SwapByChangePoint( int pIndex1, int pIndex2)
{
	//我们在学习时，将代码存起来，这些实现链表的方式都是算法，存起来，然后改进，然后使用。

	//参数合法性检测	（尽量考虑到漏洞与特殊情况，避免BUG，积累经验）
	if (pHead == NULL || pHead->iNext == NULL || pIndex1 == pIndex2 || pIndex1 < 0 || pIndex2 < 0)
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
	struct Node* pMix = FindIndex( Mix);
	struct Node* pMax = FindIndex( Max);
	//找不到对应节点就终止函数
	if (pMix == NULL || pMax == NULL)
		return;

	//确保找到后，进行头-尾、头-中间、尾-中间三种情况判断	

	//头-尾交换	（2种情况）
	if (pMix == pHead && pMax == pEnd)		//头-尾、头-中间、尾-中间，三种情况是不一样的，所以要单独找出来
	{
		//1.链表只有2个节点情况
		if (pHead->iNext == pEnd)
		{																	//用AB交换来举例：
			//头尾指向转换						
			pEnd->iNext = pHead;										//1.从A->B变成B->A
			//给新的尾节点地址成员赋值NULL
			pHead->iNext = NULL;											//2.给A的地址位赋值NULL
			//记录头尾地址的指针交换
			pHead = pEnd;				//此时一个节点同时被头尾记录指针记录	//3.然后pHead从记录A变成记B，此时B被pHead与pEnd同时记录
			pEnd = pEnd->iNext;		//此时完成头尾记录指针的交换			//4.再让pEnd变为记录A
		}
		//2.链表有多个节点情况
		else
		{
			//查找尾节点的前一个	//上面参数已经筛选过，这里肯定3个节点以上，肯定能找到pMaxpre
			struct Node* pMaxpre = FindIndex( Max - 1);
			//头尾节点位置互换					//依旧用A-B-C-D来举例
			pEnd->iNext = pHead->iNext;	//变成D->B
			pMaxpre->iNext = pHead;			//C->D变成C->A
			//给新的尾节点地址成员赋值NULL
			pHead->iNext = NULL;				//A的地址成员赋值NULL
			//记录头尾地址的指针交换
			pHead = pEnd;						//pHead从记录A变成记录D，此时pEnd与pHead都记录D
			pEnd = pMaxpre->iNext;			//pEnd从记录D，变成记录A，至此完成头尾交换，链表变成D-B-C-A
			//这里不能用两节点时的方式了，一定要用pMaxpre->iNext，
			//可以画图方便理解，(*pEnd)->iNext与(*pHead)->iNext都表示D的下一位（即节点B）
		}
	}
	//头-中间交换（2种情况）
	else if (pMix == pHead && pMax != pEnd)
	{
		//1.两个节点相邻
		if (pMix->iNext == pMax)
		{
			//改变两节点现指向			//用A-B-C举例：
			pMix->iNext = pMax->iNext;	//A->C,A改为指向C
			pMax->iNext = pMix;			//B->A,B改为指向A	变成了B-A-C
			//改变头记录指针
			pHead = pMax;				//pHead记录新头节点B
		}
		//2.两节点不相邻
		else
		{
			//寻找pMax的前一位节点
			struct Node* Maxpre = FindIndex( Max - 1);
			//记录第2个节点地址			//辅助变量影响不大，使用方便，记得使用理清思路，减少费脑
			struct Node* second = pHead->iNext;
			//改变节点的指向				//用A-B-C-D-E举例：AD交换
			pMix->iNext = pMax->iNext;	//A->E
			pMax->iNext = second;		//D->B
			Maxpre->iNext = pMix;		//C->A		链表现在为D-B-C-A-E
			//改变头记录指针
			pHead = pMax;
		}
	}
	//尾-中间交换（2种情况）
	else if (pMix != pHead && pMax == pEnd)
	{
		//1.相邻
		if (pMix->iNext == pMax)
		{
			//找到pMix的前一位节点		//用A-B-C交换BC举例：
			struct Node* p = FindIndex( Mix - 1);
			//改变节点间的指向		
			p->iNext = pMax;			//A->C
			pMax->iNext = pMix;			//C->B	此时链表变成A-C-B
			//给新的尾节点iNext赋值NULL
			pMix->iNext = NULL;
			//改变尾节点记录指针
			pEnd = pMix;
		}
		else
		{
			//分别找到pMix与pMax的前一位节点
			struct Node* pMixpre = FindIndex( Mix - 1);
			struct Node* pMaxpre = FindIndex( Max - 1);
			//改变节点间的指向			//用A-B-C-D-E换BE举例：
			pMixpre->iNext = pMax;		//A->E
			pMax->iNext = pMix->iNext;	//E->C
			pMaxpre->iNext = pMix;		//D->B		现在的链表顺序为：A-E-C-D-B
			//给新的尾节点iNext赋值NULL
			pMix->iNext = NULL;
			//改变尾节点记录指针
			pEnd = pMix;
		}
	}
	//中间-中间交换（2种情况）
	else if (pMix != pHead && pMax != pEnd)
	{
		//相邻
		if (pMix->iNext == pMax)
		{
			//分别找到pMix的前一位、pMax的下一位节点
			struct Node* pMixPre = FindIndex( Mix - 1);
			struct Node* pMaxNext = FindIndex( Max + 1);

			//改变节点的指向			//用A-B-C-D交换BC举例：
			pMixPre->iNext = pMax;	//A->C
			pMax->iNext = pMix;		//C->B
			pMix->iNext = pMaxNext;	//B->D		交换后顺序：A-C-B-D
		}
		//不相邻
		else
		{
			//找到pMix前后两个节点	//找这些节点，是为了使交换的逻辑简单，不必把脑袋搞混，找一下不费什么事
			struct Node* pMixPre = FindIndex( Mix - 1);
			struct Node* pMixNext = FindIndex( Mix + 1);
			//找到pMax前后两个节点
			struct Node* pMaxPre = FindIndex( Max - 1);
			struct Node* pMaxNext = FindIndex( Max + 1);

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
void  List::ReverseByData()
{
	//参数合法性检测	//pHead == NULL的判断一定要写在前面，因为如果为NULL的话，读取iNext属于越界操作
	if (pHead == NULL || pHead->iNext == NULL)
		return;//过滤没有节点、只有一个节点

	//交换节点数据
	int i = 0; int j = GetListNodeCount() - 1;	//让i j向中间靠拢
	for (; i < j; i++, j--)		//用A-B-C-D-E举例
	{							//A-E交换 B-D交换 C不交换，就实现了链表翻转
		SwapByIndex( i, j);
	}
}

//*翻转链表（节点翻转）（原地翻转）
void  List::ReverseByPoint()
{	//使用二级指针的原因是要交换指针指向，需要改变pHead本身的内容
	//参数合法性检测
	if (pHead == NULL || pHead->iNext == NULL)
		return;//过滤没有节点、只有一个节点

	int i = 0; int j = GetListNodeCount() - 1;	//这里的J是当下标使用，所以要个数-1
	for (; i < j; i++, j--)
	{
		SwapByChangePoint( i, j);
	}
}

//*翻转链表（辅助空间）（逻辑更清晰，代码更简洁）
void  List::ReverseByHelpSpace()
{	//二级指针：要对pHead本身进行操作
	//参数合法性检测
	if (pHead == NULL || pHead->iNext == NULL)
		return;//过滤：没有节点、只有一个节点

	//记录头指针，避免头指针丢失			//逻辑过程：
	struct Node* pTemp = pHead;			//1.创建新链表
	//创建新链表							//2.原链表按顺序，将节点数据头添加到新链表	（实现了翻转）
	struct Node* pNewpHead = NULL;		//3.释放原空间
	struct Node* pNewpEnd = NULL;		//4.头尾记录指针记录新链表头尾，至此完成翻转
	//头添加所需临时变量
	
	//将旧链表的节点数据，按顺序头添加到新链表，在新链表就实现了翻转
	while (pTemp != NULL)
	{
		//AddToHead( pTemp->iData);		//由于改成C++类内函数，没有了指针参数，所以直接把头添加的实现代码搬过来
		//头添加过程：
		//创建节点
		struct Node* pT = new Node;
		if (pT)
		{
			
			//节点赋值
			pT->iData = pTemp->iData;
			pT->iNext = NULL;

			//节点连接到链表
			if (pNewpHead == NULL)
				pNewpEnd = pT;
			else						
				pT->iNext = pNewpHead;
			pNewpHead = pT;
		}
		//原链表遍历
		pTemp = pTemp->iNext;
	}

	//释放原空间
	FreeListNULL();

	//记录头尾的指针，记录新链表的头尾
	pHead = pNewpHead;
	pEnd = pNewpEnd;
}

//链表节点数计数
int  List::GetListNodeCount()
{
	//参数合法性检测
	if (pHead == NULL)
		return 0;

	struct Node* pTemp = pHead;
	int Num = 0;
	while (pTemp != NULL)
	{
		Num++;
		pTemp = pTemp->iNext;
	}
	return Num;
}

//遍历打印
void  List::AllShow()
{
	struct Node* pTemp = pHead;		//为了不让类内成员pHead改变，用临时变量记录使用

	cout << "\n节点的元素数据为：";
	if (pTemp)
	{
		while (pTemp != NULL)
		{
			cout << ' ' << pTemp->iData;
			pTemp = pTemp->iNext;
		}
	}
	else
		cout << " 打印函数参数错误";

	cout << '\n';			
}
