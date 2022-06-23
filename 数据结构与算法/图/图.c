#include <stdio.h>
#include <stdlib.h>

//图
void AAA()
{
	if (1)
	{
		//图的专业术语
		//无向边：顶点之间连线没有方向，叫做边  有向边：顶点之间连线有方向，连线叫做弧
		//简单图：在图结构中，若不存在顶点到其自身的边，且同一条边不重复出现，则称这样的图为简单图
		//无向完全图：在无向图中，如果任意两个顶点之间都存在边，则称该图为无向完全图
		//有向完全图：在有向图中，如果任意两个顶点之间都存在方向互为相反的两条弧，则称该图为有向完全图
		//稀疏图和稠密图：这里的稀疏和稠密是模糊的概念，都是相对而言的，通常认为边或弧数小于n*logn（n是顶点的个数）的图称为稀疏图，反之称为稠密图，可理解为毛多毛少的问题
		//在无向图G中，如果从顶点V1到顶点V2有路径，则称V1和V2是连通的，如果对于图中任意两个顶点Vi和Vj都是连通的，则称G是连通图
		//度：即当前节点有多少条连线
		//有向图还有出度、入度的说法：出度：从当前节点指向别处的有向连线，入度：与出度方向相反
		//权：与树类似，连线上也可以有权，比如北京到上海，北京到深圳的地图连线，北京离这两点的距离是不一样的，距离就可以当作这两根连线的权值
		//网：图的每根连线都带有权值，则可当作网


		//图的存储方式：邻接矩阵
		//无向图：两个数组实现，第1个数组，一维数组；装图里的顶点信息。第2个数组：二维数组；装顶点间的连线信息
		//（二维数组看成矩阵，纵坐标是各顶点，横坐标也是各顶点，顶点相交的位置用0或1表示这两顶点见是否连线）
		
		//有向图：与无向图一样，1个一维数组，1个二维数组。区别是二维数组的矩阵中，先从纵坐标代表的节点，比如v0看，v0->v1 == 8（权值）有正向连线。
		//先从横坐标看v0->v1 == 正无穷，证明v1->v0没有连线，注意怎么看矩阵与连线方向取决于我们

		//图的存储方式：邻接表
		//有点类似树存储的双亲表示法，或者双亲孩子表示法那样，详情看小甲鱼课件
		//优点是不必像邻接矩阵那样浪费空间

		//图的存储方式：十字链表
	}
}

// 时间复杂度为O(n+n^2+e)

#define MAXVEX 100			// 最大顶点数
#define INFINITY 65535		// 用65535来代表无穷大

typedef struct
{
	char vexs[MAXVEX];				// 顶点表	(1维数组)
	int arc[MAXVEX][MAXVEX];		// 邻接矩阵	（2维数组）
	int numVertexes, numEdges;		// 图中当前的顶点数和边数
} MGraph;
// 建立无向网图的邻接矩阵
void CreateMGraph(MGraph* G)
{
	int i, j, k, w;

	printf("请输入顶点数和边数：\n");
	scanf_s("%d %d", &G->numVertexes, &G->numEdges);

	for (i = 0; i < G->numVertexes; i++)
	{
		scanf_s("%c", &G->vexs[i], 9);
	}

	for (i = 0; i < G->numVertexes; i++)
	{
		for (j = 0; j < G->numVertexes; j++)
		{
			G->arc[i][j] = INFINITY;			// 邻接矩阵初始化//INFINITY表示无穷大
		}
	}

	for (k = 0; k < G->numEdges; k++)
	{
		printf("请输入边(Vi,Vj)上的下标i,下标j和对应的权w:\n");		// 这只是例子，提高用户体验需要进行改善
		scanf_s("%d %d %d", &i, &j, &w);
		G->arc[i][j] = w;
		G->arc[j][i] = G->arc[i][j];			// 是无向网图，对称矩阵
	}
}


//邻接表，小甲鱼的垃圾代码，VS不好用，网上重新找了看吧
//邻接表的边节点
struct EdgeNode
{
	int adjvex;					//存储该顶点对应的下标
	int weight;					//用于存储权值，对于非网图可以不需要
	struct EdgeNode* next;	//链域，指向下一个邻接点
};
//邻接表的顶点节点
struct VertexNode
{
	char* data;				//装顶点相关信息
	struct EdgeNode* firstEdge;	//与之有连线的边节点指针
}AdjList[MAXVEX];
//创建邻接表
struct GraphAdjList
{
	struct VertexNode adjList;	//创建链表
	int numVertexes, numEdges;	// 图中当前顶点数和边数
};

//图的遍历：深度优先遍历（小甲鱼的不好用的话，现在他这学理论的，然后再上网找别人的代码）
//先从一个结点开始，一开始按照一个固定规则像后走，比如只选右侧的节点走，走的过程中，把遍历过的节点做个标记
// 走到无法再前进时，退到上一个节点，根据标记判断有无没遍历过的节点，有则继续，到了尽头再一步步退回来判断
//这样最后退到最开始的根节点时，就全部遍历完了，这就是图的深度优先遍历

int main(void)
{
	//邻接矩阵
	/*MGraph* G = (MGraph*)malloc(sizeof(MGraph));
	if (G == NULL)
		return;
	CreateMGraph(G);*/

	//查找算法
	struct XueSheng XS[4] = { {2012, "小甲鱼", 88},
							  {2013, "Yy", 30},
							  {2014, "dream", 90}
							};
	int a = ShuChu(XS, 4, 2013);
	printf("%d\n%s\n%d", XS[a].XH, XS[a].XM, XS[a].CJ);

	system("pause>0");
	return 0;
}