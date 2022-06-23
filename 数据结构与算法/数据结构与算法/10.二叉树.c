//#define _CRT_SECURE_NO_WARNINGS 1	//消除scanf的警告，因为新版本要用scanf_s才安全
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

//数据结构两大难点：KMP算法、线索二叉树

//二叉树介绍
void AAA()
{
	if (1)
	{
		//二叉树的节点有1个前驱节点，N个后驱节点，一个节点后有俩节点，有多个节点的叫多叉树
		//每个节点记录着后驱节点的地址（书上说不能记录前驱节点地址，但C3说不是绝对的）
		//二叉树就像小分类一样，字典，生物谱，族谱都很契合二叉树的使用
		//二叉树就像链表一样，有很多分类，链表有：单向链表、双向链表、循环链表等
		//二叉树也有：二叉排序树、二叉搜索树、平衡二叉树、红黑树、哈夫曼树、B树、多叉树等等，
		//但是就和链表一样，改一点功能，就成了别的树，本质的结构是一样的，所以一通百通
		//二叉树的一些节点的分类这里就不做介绍了，关注微信公众号 C3程序猿，就有文本文档可以看他整理好的介绍

		//我们是学二叉树的 创建、增、删、改、查操作，熟悉了之后就越学越简单

		//树深度：即根节点到叶子节点的层数，根节点是第一层
		//非终端节点：非叶子节点
		//度：子节点的个数称为度，度为0的节点就是叶子节点，比如二叉树的根节点root的度最大为2，因为它最大只能有两个子节点，多叉树的一个节点的度就可能很高
		//树的分类：一般树、二叉树（应用最多）、森林
		//一般树：任意节点的子节点个数不受限制
		//二叉树：最多两个子节点、且节点位置不可更改
		//森林：N个不交互的树的集合
		//二叉树分类：一般二叉树、满二叉树、完全二叉树
		//满二叉树：专业说法：在层数不增加的情况下、无法再添加节点。即根节点到叶子节点，除叶子节点外，没有其它节点能再添加分支，即中间节点都满了，不能再有分支
		//完全二叉树：在满二叉树的情况下，最底层的叶子节点，从右向左连续删除N个节点形成的树叫二叉树，满二叉树是完全二叉树的特例，即一个节点都没删除
		//完全二叉树最底层的节点一定是连续删除，从右向左，不能间断，目的是方便存储（数组形式的存储）

		//二叉树的连续存储：
		//讲一下完全二叉树的好处：比如我们有一个二叉树，不是满二叉树，也不是完全二叉树，中间有一些节点没有分支
		///这时候我们用前序遍历、中序遍历、后序遍历把这个树遍历出来存到数组中，会发现，无法通过数组来推导出二叉树本来的样子
		//但如果满二叉树或者完全二叉树呢，这些数存到数组中，会发现是能够推导出原本的二叉树的样子的，因为中间节点没有分支
		//并且满二叉树，每一层最大的节点数是固定的，也就是说光凭元素个数就能反向推导二叉树的样子
		//这样的话就知道完全二叉树的重要性了，但问题是，实际中的树很大可能不是完全二叉树，所以我们要把没有分支的节点给补上，让树补上一些无意义的节点形成完全二叉树
		//然后就能通过线性的数组推导完全二叉树，然后再去掉无意义的节点，就能知道树原本的样子，还能通过父子节点有固定的线性排序的序号知道父子节点的位置
		//缺点：因为要填补节点，所以会浪费很多空间
		//这样的数组存储就是二叉树的连续存储

		//二叉树的链式存储：就是C3老师的那种存储方式，用指针就能在内存中不必线性存储。
		//也会浪费空间，即没有子节点的节点的地址位为NULL

		//树的存储方式：双亲表示法：		可以通过下表推导出树原本的样子，记录的数字就代表这个节点对应的父节点、子节点等。这就是双亲表示法，-1是root节点的父节点，是不存在的
		//	data parent child1 child2	//还可以改成记录堂兄弟的节点的表，也很方便
		//0  A	   -1	  1		  6
		//1  B		0	  2		  -1
		//2  C		1	  3		  4
		//3  D		2	  -1	  -1
		//4  E		2	  -1	  -1
		//5  F		2	  -1	  -1
		//6  G		0	  -1	  -1
		//7  H		0	  8		  9
		//8  I		7	  -1	  -1
		//9  J		7	  10	  -1
		//10 K		9	  -1	  -1

		//二叉树的左分支与右分支是严格区分的，当节点只有一个分支时，一定要清楚是左还是右
	}
}

//老师就使用了记录父节点的指针
struct TreeNode
{
	int iData;					//数据成员
	struct TreeNode* pFther;	//父节点地址
	struct TreeNode* pLeft;		//左 子成员
	struct TreeNode* pRight;	//右 子成员
};
//前序遍历（递归写法）（C3）
void Look(struct TreeNode* root)
{
	if (root != NULL)
	{
		printf(" %2d", root->iData);
		Look(root->pLeft);
		Look(root->pRight);
	}
}


//二叉树节点的内容（小甲鱼）
typedef struct BitNode
{
	char data;
	struct BitNode* left, * right;
}BiTNode, *BiTree;
//创建一颗二叉树（scanf输入的方式，小甲鱼）递归写法：提前约定好，需要以前序遍历的排序来输入
void CreateBiTree(BiTNode** P)
{	//BiTree已经是指针类型的了，形参再加*就变成了二级指针，所以下面递归要传二级指针
	
	char c;
	scanf_s("%c", &c, 10);	//第三个参数是限制输入的字符数，10即最多9个字符
	//如果输入为空格，则对应节点为NULL，即对应节点不存在
	if (' ' == c)
		*P = NULL;
	//如果输入不为空格
	else
	{
		//给当前有输入数据的指针创建节点,也巧妙地相当于给节点地址初始化
		*P = (BiTNode*)malloc(sizeof(BiTNode));
		if ((*P) == NULL)
			return;
		//切换下面三个输入的顺序，可以做到中序遍历、后序遍历的节点输入，现在是先序遍历的方式：根-左-右
		(*P)->data = c;				//根节点赋值		当前指针所在的节点
		CreateBiTree(&(*P)->left);	//左节点赋值
		CreateBiTree(&(*P)->right);	//右节点赋值
	}
	
}
//对遍历到的节点进行输出
void visit(char data, int level)
{
	printf("节点数据：%c 层数：%d\n", data, level);
}
//遍历二叉树（小甲鱼）
void PreOrderTraverse(BiTNode* P, int level)
{	//此处的BiTree是一级指针，因为重命名时就定义为一级指针了
	//level是记录层数的变量
	if (P)	//变相的进行参数合法性检测
	{
		//visit是对当前遍历到的节点要做什么的函数
		visit(P->data, level);				//这里的level就是当前节点的层数
		PreOrderTraverse(P->left, level+1);	//进入子节点，level就+1
		PreOrderTraverse(P->right, level+1);//此处不能用后置++，否则叶子节点少了一层
	}
}


//线索二叉树（小甲鱼）
void BB()
{
	//普通二叉树如果是完全二叉树，用中序遍历的方式就能发现，一些只有一个分支的节点，一些没有分支的节点，排序出来，有两分支的节点与没分支的节点按间隔分开
	//这样没有分支的节点的地址域就能有作用了，没有分支的节点的两个地址成员可以用来记录前驱节点和后继节点（注意不是左节点与右节点，是排好序后在它前面的节点和排在后面的节点）
	//如果不是完全二叉树呢，不管怎样方式的遍历，都不是按规律排布的，那些没有分支的节点的地址域就无法利用，或者只有一个分支的节点空出来的地址成员也无法利用
	//这些原本为NULL的地址域如果能想办法利用上，记录前驱后驱节点，会极大提高我们查找节点的速率
	//方法就是使用线索二叉树的特点：使节点成员增加，ltag、rtag来区分left、right记录的是左节点/右节点 还是前驱/后继，这样就解决了
	//比如对应节点地址成员left记录的是左节点，此时ltag==0，如果left记录的不是左节点，而是排序后的前驱节点，此时ltag==1
	//这样就完美区分了地址成员left的记录问题，提高了利用率，且增加了灵活性（哪种遍历方式都可用），查找效率，尽管ltag、rtag需要占用少量空间
	//空的地址域记录前驱/后继 节点，也叫记录线索
}
//枚举，Link（0），地址成员记录左右节点
//Thread（1），地址成员记录前驱/后继节点
typedef enum{Link, Thread} PointerTag;
//线索二叉树节点的结构
typedef struct BiThrNode
{
	char data;					//数据位
	struct BiThrNode* left;		//左地址成员
	struct BiThrNode* right;	//右
	PointerTag ltag;			//左地址成员判断标识
	PointerTag rtag;			//右
}BiThrNode, *BiThrTree;
//用于记录上一节点的变量，最开始是从空头开始
BiThrNode* Pre;
//对遍历到的节点进行输出
void visit1(char data)
{
	printf("%c ", data);
}
//创建一个线索二叉树,scanf输入的方式,约定以前序遍历的排序（递归）
void CreaterBiThrTree(BiThrNode** PHead)
{
	if (PHead)
	{	//输入节点的数据
		char c;
		scanf_s("%c", &c, 10);
		//输入 空格 则不生成节点
		if (c == ' ')
			*PHead = NULL;
		else
		{
			//创建节点，并且起地址初始化作用
			*PHead = (BiThrNode*)malloc(sizeof(BiThrNode));
			if (*PHead == NULL)
				return;
			//节点赋值
			(*PHead)->data = c;
			//节点线索标识初始化成0（即表示记录左右节点，在遍历时再判断修改）
			(*PHead)->ltag = Link;	
			(*PHead)->rtag = Link;
			//递归对其它分支节点进行创建
			CreaterBiThrTree(&(*PHead)->left);
			CreaterBiThrTree(&(*PHead)->right);
		}
	}
}
//中序遍历，并且线索化(递归写法)
void InThreading(BiThrNode* PHead)
{	//参数检测
	if (PHead)	//中序遍历：左-根-右
	{
		InThreading(PHead->left);		//左遍历

		//此节点的左地址位的线索化
		if (PHead->left == NULL)		//如果此节点左孩子为NULL
		{
			PHead->ltag = Thread;		//此节点左地址位线索化
			PHead->left = Pre;			//Pre为前驱节点，即遍历到这个节点前的一位节点
		}

		//前一个节点的右地址位的线索化		Pre是前一个结点的地址		Pre不进到这个节点前，无法知道它的后继节点的地址，也就无法线索化，所以需要Pre来记住上一节点
		if (Pre->right == NULL)			//如果前节点右孩子为NULL
		{
			Pre->rtag = Thread;			//前节点右地址位的线索化
			Pre->right = PHead;			//此时对于Pre来说，此时的节点是Pre的后继节点
		}

		//输出
		visit1(PHead->data);

		Pre = PHead;					//使Pre记录当前的地址，然后进行右遍历

		InThreading(PHead->right);		//右遍历
	}
}
//中序遍历的迭代写法（屁的非递归，还是用了递归遍历的线索化结果)
void InOrderTraverse(BiThrNode* PP)
{
	//定义一个指针
	BiThrNode* PTemp;
	//指针从空头开始
	PTemp = PP->left;

	//因为上面我们使其成环，所以PTemp == PP时，刚好一圈
	while (PTemp != PP)
	{
		//一直指到最左侧的叶子节点
		while (PTemp->ltag == Link)
		{
			PTemp = PTemp->left;
		}

		//输出当前节点
		visit1(PTemp->data);

		//让PTemp继续向右遍历，其实还是用了递归中序遍历的线索化结果，屁的非递归遍历
		while (PTemp->rtag == Thread && PTemp->right != PP)
		{
			PTemp = PTemp->right;
			visit1(PTemp->data);
		}

		PTemp = PTemp->right;

	}
}
//自写非递归遍历
void InOrderTraverse1(BiThrNode* PHead)
{
	//想不出来，上网搜吧
}
//创建头节点（类似空头，在根节点的前面）
void InOrderThreading(BiThrNode** P, BiThrNode* PHead)
{
	//创建空头节点
	*P = (BiThrNode*)malloc(sizeof(BiThrNode));
	if (*P == NULL)
		return;
	//空头结点初始化
	(*P)->ltag = Link;
	(*P)->rtag = Thread;
	(*P)->left = *P;
	//如果根节点不存在
	if (PHead == NULL)
		(*P)->right = *P;
	//根节点存在
	else
	{
		//空头左分支设为根节点
		(*P)->left = PHead;
		//Pre从空头开始记录，它代表遍历到的位置的父节点地址
		Pre = *P;
		//从根节点开始遍历
		InThreading(PHead);
		//遍历完了,此时Pre为树中最后一个被遍历的节点
		//使这个最后的节点连上空头，就像循环链表的循环一样
		Pre->right = *P;
		Pre->rtag = Thread;	//线索化
		//使空头连上最后的节点
		(*P)->right = Pre;
	}


}



//赫夫曼树介绍
void CCC()
{
	if (1)
	{
		//赫夫曼树是根据赫夫曼编码来实现的，赫夫曼编码是为了使压缩效率更高（电文总长最短），且不影响二义性
		//相关的名词：
		//权：可直接理解为重量，比如实际应用中一个节点被访问的次数相当多，那它的权值就重，或者比如一段字符串，按字母出现次数来讲，某些字幕出现次数高，那它的权值就重
		//节点的路径长度：从根节点到该节点路径上的连接数，就是二叉树画出图来，节点之间的连线，根节点到该节点出现的连线次数
		//树的路径长度：树中每个叶子节点的路径长度之和，
		//节点带权路径长度：节点的路径长度与节点权值的乘积
		//树的带权路径长度：WPL：是树中所有叶子结点的节点带权路径长度之和

		//赫夫曼树就是，权值重的节点靠近上层，即靠近根节点，权值低的就靠近叶子节点
		//目的是使WPL更低，这样效率就高

		//名词：
		//定长编码：像ASCII码，每个字符固定8字节大小，不会变
		//变长编码：单个编码的长度不一致，可以根据整体出现频率来实现
		//前缀码：没有任何码字是其他码字的前缀，例如：有一个字符编码为010，那其它字符的二进制码不可能出现010开头的编码，比如01011这就是不可能出现的，因为不能出现010的前缀
		//赫夫曼编码就属于前缀码
		
		//赫夫曼树的实现：
		//用一个有顺序的队列来存放节点，从权值最低的两个节点开始取出来，将这两个节点形成一个二叉树，根节点是这两节点的权值之和
		//然后用这个整合过的根节点与队列的队顶元素权值比较（因为两节点取出来，队顶是剩下的元素），大于则放到队顶后面，小于则放到队顶前面，
		//然后再取两个元素进行整合，再插入，不断地重复，直到队列的最后一个元素。这就是赫夫曼树的实现过程，根据赫夫曼编码的特性写的。
	}
}


int main(void)
{

//二叉树的创建（C3的演示、也是小甲鱼说的链式存储、国际惯用的存储方式）
{
	//节点的创建、初始化
	struct TreeNode T1 = { 1, NULL, NULL, NULL };
	struct TreeNode T2 = { 2, NULL, NULL, NULL };
	struct TreeNode T3 = { 3, NULL, NULL, NULL };
	struct TreeNode T4 = { 4, NULL, NULL, NULL };
	struct TreeNode T5 = { 5, NULL, NULL, NULL };
	struct TreeNode T6 = { 6, NULL, NULL, NULL };
	struct TreeNode T7 = { 7, NULL, NULL, NULL };
	struct TreeNode T8 = { 8, NULL, NULL, NULL };
	struct TreeNode T9 = { 9, NULL, NULL, NULL };
	struct TreeNode T10 = { 10, NULL, NULL, NULL };
	struct TreeNode T11 = { 11, NULL, NULL, NULL };
	struct TreeNode T12 = { 12, NULL, NULL, NULL };
	struct TreeNode T13 = { 13, NULL, NULL, NULL };
	struct TreeNode T14 = { 14, NULL, NULL, NULL };
	struct TreeNode T15 = { 15, NULL, NULL, NULL };
	struct TreeNode T16 = { 16, NULL, NULL, NULL };

	//好像记录父节点代码量有点大啊，呃呃呃

	//父节点：T1
	T1.pLeft = &T2;
	T1.pRight = &T3;
	T2.pFther = &T1;
	T3.pFther = &T1;

	//父节点：T2
	T2.pLeft = &T4;
	T2.pRight = &T5;
	T4.pFther = &T2;
	T5.pFther = &T2;

	//父节点：T4
	T4.pLeft = &T11;
	T4.pRight = &T12;
	T11.pFther = &T4;
	T12.pFther = &T4;

	//父节点：T12
	T12.pLeft = &T13;
	T13.pFther = &T12;

	//父节点T5
	T5.pLeft = &T7;
	T5.pRight = &T8;
	T7.pFther = &T5;
	T8.pFther = &T5;

	//父节点：T7
	T7.pRight = &T14;
	T14.pFther = &T7;

	//父节点：T3
	T3.pLeft = &T15;
	T3.pRight = &T6;
	T6.pFther = &T3;
	T15.pFther = &T3;

	//父节点：T5
	T5.pLeft = &T7;
	T5.pRight = &T8;
	T7.pFther = &T5;
	T8.pFther = &T5;

	//父节点：T6
	T6.pLeft = &T9;
	T6.pRight = &T10;
	T9.pFther = &T6;
	T10.pFther = &T6;

	//父节点T10
	T10.pLeft = &T16;
	T16.pFther = &T10;

	//前序遍历
	{
		//前序遍历介绍：
			//前序遍历：从整个树的root节点开始，遍历顺序为：根-左-右
			//比如从1开始，到了它的左节点2，然后又以2为根节点进行根-左-右遍历，一直到叶子节点
			//到了叶子节点，下面没有节点了，然后回到它的父节点判断有无右节点，进入那个右节点又开始根-左-右的遍历

			//整体的遍历顺序，是从左往右
			//可以看C3老师画的那张箭头图，容易理解，递归的写法很简洁，但是完全契合前序遍历
			//也可以自己画箭头图加深印象，很容易知道遍历顺序
			//注意前序遍历一定是从左向右，不要写成从右向左了，那不是前序遍历
		Look(&T1);
	}
}
	
//小甲鱼：双亲孩子表示法（详情看小甲鱼的图片，P43课）
{
#define MAX_TREE_SIZE 100

	typedef char ElemType;

	//孩子节点
	typedef struct CTNode
	{
		int Child;				//孩子节点的下标
		struct CTNode* next;	//指向下一孩子节点的指针
	}*Childptr;					//这是指针形式的重命名，

	//表头结构
	typedef struct TOU
	{
		ElemType data;			//存放在树中节点的数据
		int parent;				//存放双亲（父节点）的下标
		Childptr firstchild;	//指向第一个孩子的下标
	}CTbox;

	//树结构
	typedef struct SHU
	{
		CTbox nodes[MAX_TREE_SIZE];	//一个数组，每个元素都是一个表头结构，这个表头可能有指向它第一个子节点的下标，没有子节点则为NULL，为了节省空间的做法
		int r, n;					//r：记录根节点的下标，n：节点的数
	}SHU;
}
//小甲鱼：遍历二叉树
//{
//	printf("\n");
//	//创建根节点
//	int level = 1;		//根节点层数
//	BiTNode* P = NULL;
//
//	//对二叉树进行输入，提前约定好的以前序遍历的排序方式输入
//	CreateBiTree(&P);
//
//	//遍历二叉树
//	PreOrderTraverse(P, level);
//
//}
//小甲鱼：线索二叉树
{
	printf("\n");
	printf("\n");
	//空头
	BiThrNode* PP;
	//根节点 root
	BiThrNode* PHead;
	//输入节点
	printf("请输入线索二叉树节点： ");
	CreaterBiThrTree(&PHead);
	//创建空头，并且进行中序遍历
	printf("中序遍历后节点： ");
	InOrderThreading(&PP, PHead);
	printf("\n");

}

	system("pause>0");
	return 0;
}