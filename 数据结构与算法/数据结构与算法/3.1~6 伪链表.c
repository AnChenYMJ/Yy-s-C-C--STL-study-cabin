#include <stdio.h>
#include <stdlib.h>				//system 的头文件
#include <string.h>				//memset 的头文件

//我们封装函数尽可能让函数功能单一，用的时候再调用，不要跟学习的时候一样随便在函数内随意处理打印数据

//伪链表讲解
void WLB()
{
	//伪链表是最简单形式的链表表现，实际应用中不可能会用，这里学习是为了接下来学习链表做铺垫
	//算法根据需求一直在变化，我们要培养的是思维。
	
	//数组的特点：元素空间地址连续，一次性申请好的固定大小空间，若是数据量不确定，则申请时多申请一些，防止越界（导致空间浪费）
	//空间不够时，会重新申请更大空间，且复制原数据到新空间
	//数组访问元素：访问速度很快，得益于地址连续，能进行下标运算（即：地址偏移，首地址做加减）

	//链表节点空间相对独立，增加空间无需进行数组的复制，直接添加节点空间，故节点空间地址不连续

	//链表如何访问元素呢？
	//由于链表的空间在不同时间点申请，地址不可能连续，无法进行下标运算来访问
	//所以就需要每个节点记录下一节点的地址（单向链表），有的也记录上一节点地址（双向链表）
	//故链表节点基本需要两个成员，一个记录数据，一个记录下一节点的地址。所以链表节点是一个结构体类型.
	
}

//链表的创建
struct WeiLianBiao
{
	int iValue;					//存数据
	struct WeiLianBiao* pNext;	//存下一节点的地址
};
//重命名结构体：工作中常会用到，但学习就暂时不用，避免名字一杂乱影响思路
//typedef struct WeiLianBiao
//{
//	int iValue;					//存数据
//	struct WeiLianBiao* pNext;	//存下一节点的地址
//}_WeiLianBiao;

//处理查找返回地址封装函数
void FindShow(struct WeiLianBiao* pJiLu);

//查：1.遍历链表
void BianLiShow(struct WeiLianBiao* pJiLu);	

//查：2.1查找指定：根据数据
struct WeiLianBiao* FindByData(struct WeiLianBiao* pJiLu, int ShuJu);

//查：2.2查找指定：根据下标查找(第几个或者下标都行，下标的话就是个数-1)
struct WeiLianBiao* FindByIndex(struct WeiLianBiao* pJiLu, int Index);

//查：2.3.1查找指定：根据个数（统计重复出现的数量）
int Count(struct WeiLianBiao* pJiLu, int ShuJu);		//count：计数

//查：2.3.2查找指定：根据个数（记录数据）（自己改：与2.3.1结合）
int GetNode(struct WeiLianBiao* pJiLu, struct WeiLianBiao* arr[5], int Data);

//改：3.1根据数据修改		修改==查找 + 改，所以也分为根据数据修改，根据下标修改
void ChangeByData(struct WeiLianBiao* pJiLu, int iValue1, int iData);

//改：3.2根据下标（第几个）修改	
void ChangeByIndex(struct WeiLianBiao* pJiLu, int iIndex, int iData);


int main()
{

//创建链表
	struct WeiLianBiao	a = {5, NULL},		//设定节点
						b = {8, NULL},		
						c = {6, NULL}, 
						d = {5, NULL}, 
						e = {3, NULL};		//将pNext初始化成NULL，会方便很多操作，请看下面的 增删查改 内容

	a.pNext = &b;		//将后一节点的地址存到当前节点的成员中
	b.pNext = &c;		//即：记录下一节点的地址
	c.pNext = &d;		//每增加节点都这么写，会很麻烦，可以用循环来完成
	d.pNext = &e;		//最后一个节点因为没有再下一个节点地址覆盖掉它的pNext，所以它的pNext将会是NULL，直到下一个节点来覆盖

//查 链表
// 
	//1.遍历链表
	{

	struct WeiLianBiao* pJiLu;				//用一个指针记录链表头的地址，方便调用
	pJiLu = &a;

	printf("以下为第一次手写遍历：\n");
	printf("%d  ", a.iValue);								//a	变量调用成员 用 .   指针或地址调用成员用 ->
	printf("%d  ", (&a)->pNext->iValue);					//b	(&a)与 a 与 pJiLu 都是代表一个地址
	printf("%d  ", pJiLu->pNext->pNext->iValue);			//c
	printf("%d  ", a.pNext->pNext->pNext->iValue);			//d
	printf("%d  ", a.pNext->pNext->pNext->pNext->iValue);	//e
	printf("\n\n");
	//会发现，这样写，当节点一多，就越来越麻烦，所以要用规律来写成循环

	//规律如下：
	printf("以下为查找规律的简写遍历：\n");
	printf("%d  ", pJiLu->iValue);		//a

	pJiLu = pJiLu->pNext;				//下一个节点的地址覆盖掉当前的指针
	printf("%d  ", pJiLu->iValue);		//b

	pJiLu = pJiLu->pNext;				//发现每次pJiLu被下一节点地址覆盖即可实现遍历
	printf("%d  ", pJiLu->iValue);		//c

	pJiLu = pJiLu->pNext;
	printf("%d  ", pJiLu->iValue);		//d

	pJiLu = pJiLu->pNext;
	printf("%d  ", pJiLu->iValue);		//e

	printf("\n\n");

	//循环遍历
	printf("以下为循环遍历：\n");			//成功打印
	BianLiShow(&a);						//循环很简洁，注意末端节点的pNext是NULL，这点不会变
	printf("\n\n");


	}

	//2.查找指定
	{
		//查找指定有：1.根据数据、2.查看第几个、3.根据个数

		//1.根据数据
		{
			//1.1根据数据，查找已有
			printf("以下为查找指定数据：\n");
			FindByData(&a, 6);
			if (FindByData(&a, 6) == NULL)				//1.对数据处理有两种方式，这种如果要对数据进行操作，则慢了一点，如果只是判断，速度则快了一些
			{											//可写个封装函数
				printf("未查到该数据。\n");
			}
			else
			{
				printf("查到指定数据，数据为： %d \n", FindByData(&a, 6)->iValue);
			}											//数据处理慢一些的原因是这if else调用了两次函数
			printf("\n");

			//1.2根据数据，查找没有的
			printf("以下为查找没有的数据：\n");
			FindByData(&a, 11);
			struct WeiLianBiao* pHead = FindByData(&a, 11);//2.这是第二种方式，对数据进行操作，快了一些，但要单独进行指针赋值
			if(pHead != NULL)
				printf("查到指定数据，数据为： %d \n", pHead->iValue);
			else											//if else不加{}则自动执行靠近它们最近的一个语句
				printf("未查到该数据。\n");						
			printf("\n");
		
		}
		
		//2.查看第几个
		{
			//2.1 查看第几个，查找已有的
			printf("以下为查找对应个数的数据：\n");
			FindShow(FindByIndex(&a, 5));					//此处用到俩封装的函数（自写）FindShow（）与FindByIndex（），请查看函数声明
			printf("\n");

			//2.2查看第几个，查找没有的
			printf("以下为查找对应个数没有的数据：\n");
			struct WeiLianBiao* pHead1 = FindByIndex(&a, 8);//与上面一样的，不过多了个步骤，麻烦了点，上面更灵活
			FindShow(pHead1);
			printf("\n");
		}

		//3.根据个数
		{
			//3.1统计重复出现的次数
			printf("数据重复的次数：%d \n", Count(&a, 5));	
			printf("\n");

			printf("数据重复的次数：%d \n", Count(&a, 23));
			printf("\n");

			//3.2记录重复出现的数据
			struct WeiLianBiao* arr[5] = { NULL };			//这里我们不确定数量的话，可以按照动态数组的思维，需要多少就扩充，5是因为我们上面链表节点最大为5
			GetNode(&a, arr, 5);
			for (int i = 0; i < 5 && arr[i] != NULL; i++)	//这里老师有个经验：i < 4放到前面，就避免了arr[4]的越界，因为它下标最大是3
			{												//arr[i] != NULL放到前面会越界取数据比较，这样不好，工作的时候注意
				printf("重复的数据为：%d \n",arr[i]->iValue);
			}
			if(GetNode(&a, arr, 5) == 0)
				printf("没有重复的数据。\n");
			else
				printf("出现的次数为：%d\n", GetNode(&a, arr,5));//我把函数的返回值设为重复的次数，就把3.1的结合了
			printf("\n");

			//测试没有的数据
			memset(arr, NULL, 5);							//给数组arr初始化,因为上面的操作给它赋值了
			GetNode(&a, arr, 11);
			for (int i = 0; i < 5 && arr[i] != NULL; i++)	//这里老师有个经验：i < 4放到前面，就避免了arr[4]的越界，因为它下标最大是3
			{												//arr[i] != NULL放到前面会越界取数据比较，这样不好，工作的时候注意
				printf("重复的数据为：%d \n", arr[i]->iValue);
			}
			if (GetNode(&a, arr, 11) == 0)
				printf("没有重复的数据。\n");
			else
				printf("出现的次数为：%d\n", GetNode(&a, arr, 11));//我把函数的返回值设为重复的次数，就把3.1的结合了
			printf("\n");
		}
		
	}

//增、删
{
//增：添加						对于一些抽象的概念，尽可能画图去辅助思考，方便很多
	//头添加						创建一个节点记录原头节点的地址，就替代了头节点
	struct WeiLianBiao	a1 = { 55, NULL };
	a1.pNext = &a;
	printf("以下为头添加：\n");
	BianLiShow(&a1);
	printf("\n\n");

	//尾添加						创建一个节点，原尾节点记录这个节点的地址，就替代了尾节点（注意，任何尾节点的pNext都必须是NULL，详情看我们封装的函数定义就知道了）
	struct WeiLianBiao	f = { 26, NULL };
	e.pNext = &f;
	printf("以下为尾添加：\n");
	BianLiShow(&a1);
	printf("\n\n");

	//中间添加					创建一个节点，比如用a,c中间插入b来说，b记录c的地址，a记录的地址修改为记录b，就实现了中间插入（画图好理解）
	struct WeiLianBiao	c1 = { 48, NULL };
	c.pNext = &c1;
	c1.pNext = &d;
	printf("以下为中间添加：\n");
	BianLiShow(&a1);
	printf("\n\n");


//删：删除
	//头删除
	a1.pNext = NULL;			//将链表头记录的地址改为NULL，然后再释放掉这个节点空间即可
	//free(&a1);				//现在是伪链表演示，不是真正的链表，没有malloc，故无需释放，这是局部变量
	printf("以下为头删除：\n");
	BianLiShow(&a);
	printf("\n\n");

	//尾删除
	e.pNext = NULL;				//倒数第2的节点记录地址清除为NULL，然后再释放掉原尾节点空间即可
	//free(&f);					
	printf("以下为尾删除：\n");
	BianLiShow(&a);
	printf("\n\n");

	//中间删除
	c.pNext = &d;				//用 a->b->c 删b为例，a改为记录c的地址，然后再释放b节点空间即可
	//free(&c1);					
	printf("以下为中间删除：\n");
	BianLiShow(&a);
	printf("\n\n");
	
}

//改：修改	改 == 查找+修改
{
	//指定数据修改
	printf("以下为指定数据修改：\n");
	ChangeByData(&a, 5, 99);
	BianLiShow(&a);
	printf("\n\n");

	printf("以下为找不到指定数据：\n");
	ChangeByData(&a, 56, 99);

	//指定第几个修改
	printf("以下为指定第几个修改：\n");
	ChangeByIndex(&a, 1, 88);
	BianLiShow(&a);
	printf("\n\n");

	printf("以下为参数超出元素个数：\n");
	ChangeByIndex(&a, 18, 666);
}


	system ("pause>0");			//正常这里控制台会提示“请按任意键继续……”，但是在加上>0后，就不提示这句话啦，但是功效还在，按任意键继续
	return 0;
}



//处理查找返回地址封装函数
void FindShow(struct WeiLianBiao* pJiLu)
{
	if (pJiLu == NULL)
		printf("未查到该数据。\n");
	else
		printf("查到指定数据，数据为： %d \n", pJiLu->iValue);
}

//查：1.遍历链表
void BianLiShow(struct WeiLianBiao* pJiLu)	//以下为前辈总结的规律与经验，很简洁，注意思考
{											//只要传入链表头地址即可
	while (pJiLu != NULL)					//pJiLu == NULL时 则代表已经到了节点的末端//最后一个节点的pNext因为没有其它节点地址覆盖，所以一直是NULL
	{
		printf("%d  ", pJiLu->iValue);		//从第一个开始遍历
		pJiLu = pJiLu->pNext;
	}
}

//查：2.1查找指定：根据数据
struct WeiLianBiao* FindByData(struct WeiLianBiao* pJiLu, int ShuJu)		//找到返回该节点地址，没找到返回NULL
{																			//struct WeiLianBiao*为返回的地址的类型，（结构体指针类型）
	while (pJiLu != NULL)
	{
		if (pJiLu->iValue == ShuJu)
		{
			return pJiLu;													//找到返回了地址且退出函数
		}
		pJiLu = pJiLu->pNext;
	}
	return NULL;															//没找到返回NULL
}

//查：2.2查找指定：根据下标查找(第几个或者下标都行，下标的话就是个数-1)
struct WeiLianBiao* FindByIndex(struct WeiLianBiao* pJiLu, int Index)
{
	int Num = 1;			//用一个数来记录对比，如果是下标查找，则Num=0即可，第几个的话Num=1
	while (pJiLu != NULL)
	{
		if (Num == Index)	//当Num与我们要的个数相等时，返回当前的地址
			return pJiLu;
		Num++;
		pJiLu = pJiLu->pNext;
	}
	return NULL;
}

//查：2.3.1查找指定：根据个数（统计重复出现的数量）
int Count(struct WeiLianBiao* pJiLu, int ShuJu)		//count:计数
{
	int Num = 0;
	while (pJiLu != NULL)
	{
		if (pJiLu->iValue == ShuJu)
			Num++;
		pJiLu = pJiLu->pNext;
	}
	return Num;
}

//查：2.3.2查找指定：根据个数（记录数据）（自己改：与2.3.1结合）
int GetNode(struct WeiLianBiao* pJiLu, struct WeiLianBiao* arr[5], int Data)
{										//函数的参数都是局部变量，与外界的不是同一个，名字不同也不要紧的，这点要注意
	int i = 0;
	while (pJiLu != NULL)
	{
		if (pJiLu->iValue == Data)
		{
			arr[i++] = pJiLu;			//i++先取值再+1，放到这里节省了代码
		}
		pJiLu = pJiLu->pNext;
	}
	return i;							//我把它与统计重复数量结合了，返回值就是重复的次数
}

//改：3.1根据数据修改		修改==查找 + 改，所以也分为根据数据修改，根据下标修改
void ChangeByData(struct WeiLianBiao* pJiLu, int iValue1, int iData)
{
	int count = 0;
	while (pJiLu != NULL)				//自写版本，能修改重复部分,但复杂，且一开始忘了当找不到时怎么处理
	{
		if (pJiLu->iValue == iValue1)	//根据数据修改
		{
			pJiLu->iValue = iData;		//如果查到某节点与我们想找的值一样，则将该节点改为iData
			count++;
		}
		pJiLu = pJiLu->pNext;
	}
	if (count == 0)
		printf("未找到该数据 \n\n");

	//struct WeiLianBiao* pTemp = FindByData(pJiLu, iValue1);
	//if (pTemp == NULL)					//老师的版本，更简练，调用了此前写的函数，找不到数据返回NULL
	//	printf("未找到该数据 \n\n");
	//if (pTemp != NULL)					//注意是if不是while
	//	pTemp->iValue = iData;			//无法修改重复部分的内容，只能修改，第一个查到的数据（详情查看FindByData（）函数定义）

}

//改：3.2根据下标（第几个）修改	
void ChangeByIndex(struct WeiLianBiao* pJiLu, int iIndex, int iData)
{
	//int Num = 1;						//自写版本，不够简单
	//while (pJiLu != NULL)
	//{
	//	if (Num == iIndex)
	//		pJiLu->iValue = iData;
	//	Num++;
	//	pJiLu = pJiLu->pNext;
	//}
	//if (pJiLu == NULL)
	//	printf("参数超出元素个数上限 \n\n");


	struct WeiLianBiao* pTemp = FindByIndex(pJiLu, iIndex);
	if (pTemp != NULL)				//老师版本，够简练
		pTemp->iValue = iData;
	if (pTemp == NULL)
		printf("参数超出元素个数上限 \n\n");
}
