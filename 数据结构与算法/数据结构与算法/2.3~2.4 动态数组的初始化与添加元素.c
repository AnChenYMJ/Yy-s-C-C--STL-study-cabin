#include <stdio.h>		//标准输入输出函数的头文件
#include <malloc.h>		//malloc的头文件


//讲解
void jiangjie()	
{
//尾巴上添加一个节点的讲解思路
// 
	//我们要创建一个动态数组，主要有下面三个问题（主要）

	//1.动态数组的首地址 首地址记录的问题	
	//2.可存放的数据总量 总体容量记录的问题
	//3.已存储的数据容量 已经存放的数据的容量记录问题
	//回答：用一个结构体将三个变量统一管理，方便使用

//其他问题：（次要）		增加灵活性
	//1.动态指针			除了首地址外，，有一个能变化的指针在数组中来回指，用它来访问
	//2.元素大小			比如元素的数据类型是double的，那我们可能要记录double是 8 字节，这样
}

//结构体来方便管理三个变量
struct DongTaiShuZu							//结构体来方便管理三个变量
{
	int* ShouDiZhi;							//首地址		记录空间首地址
	unsigned int ZongCunLiang;				//总存量		空间总体能存放的容量
	unsigned int YiCunLiang;				//已存量		已占用的容量
};		

//初始化函数
void ChuShiHua(struct DongTaiShuZu* pDSZ)	//初始化函数
{
	//NULL指针提示	//以后写代码，这个很重要，只要参数有指针，都要加上
	if (pDSZ == NULL)
	{
		printf("初始化函数参数异常\n");
		return;
	}
	if (pDSZ)		//防止NULL指针
	{
		pDSZ->ZongCunLiang = 5;					//初始容量设为5	//根据需求来设置初始容量
		pDSZ->YiCunLiang = 0;					//初始化为空
		pDSZ->ShouDiZhi = (int*)malloc(sizeof(int) * pDSZ->ZongCunLiang);	//malloc申请空间，并且将空间首地址返回给ShouDiZhi
												//注意这里申请的空间大小是总存量大小，且要将malloc返回值强转成指针
	}
}	

//添加元素		//重要
void TianJia(struct DongTaiShuZu* pDSZ, int iShuJu)
{
	//NULL指针提示	
	if (pDSZ == NULL)
	{
		printf("增加元素函数参数异常\n");
		return;
	}
	//防止传入NULL指针
	if (pDSZ)			//参数检测比较重要，记得写
	{
		//判断容量是否满了
		if (pDSZ->ZongCunLiang == pDSZ->YiCunLiang)
		{
			//1.容量变大
			pDSZ->ZongCunLiang += 10;
			//2.申请新空间
			int* newShou = (int*)malloc(sizeof(int) * pDSZ->ZongCunLiang);

			//3..复制数据
			for (unsigned int i = 0; i < (pDSZ->YiCunLiang-1); i++)			//减一不会有警告
			{	
				if (newShou)						//防止NULL指针
				{
					newShou[i] = pDSZ->ShouDiZhi[i];//将原数据复制到新空间
				}
				
			}
			//4.释放原空间
			free(pDSZ->ShouDiZhi);
			if (newShou)							//防止NULL指针否则会有警告
			{
			//5.将数组头指针指向新地址
				pDSZ->ShouDiZhi = newShou;
			}
		}

		//写入数据
		pDSZ->ShouDiZhi[pDSZ->YiCunLiang] = iShuJu;
		//已存量变化
		pDSZ->YiCunLiang++;	
	}
	
}

//打印函数
void show(struct DongTaiShuZu* pDSZ)	//可以不传指针，那样的话就相当于创建一个临时结构体变量，然后把数据复制到临时变量再处理，效率低下
{
					//NULL指针提示	
	if (pDSZ == NULL)
	{
		printf("打印函数参数异常");
		return;		//退出函数
	}

	if (pDSZ)		//防止NULL指针
	{
		printf("总存量：%u, 已存量：%u \n", pDSZ->ZongCunLiang, pDSZ->YiCunLiang);
		printf("数据内容：");
		for (unsigned int i = 0; i < pDSZ->YiCunLiang; i++)
		{
			printf("%d ", pDSZ->ShouDiZhi[i]);
		}
	}	

}

int main(void)
{
	struct DongTaiShuZu DSZ;				//声明结构体变量

	ChuShiHua(&DSZ);						//初始化变量

	TianJia(&DSZ, 6);						//写入数据
	TianJia(&DSZ, 3);
	/*TianJia(&DSZ, 4);
	TianJia(&DSZ, 6);
	TianJia(&DSZ, 9);
	TianJia(&DSZ, 8);*/
	TianJia(NULL,5);						//传入NULL检测异常处理
	TianJia(&DSZ, 6);
	TianJia(&DSZ, 9);

	show(&DSZ);								//打印
	show(NULL);								//传入NULL检测异常处理

	free(DSZ.ShouDiZhi);					//释放空间	一定要释放，否则申请的空间将永远占用
	//free(&DSZ);							//这样也可以，上面的更合逻辑，因为是ShouDiZhi申请的空间
	return 0;
}