#include <stdio.h>
#include <malloc.h>
#include <string.h>			//函数memset()的头文件

//实际应用会要求添加多个元素
//原理是一样的，用一个循环，挨个添加即可，（可将该功能封装成函数）


//2.5 动态数组中间插入元素	
//2.6 下标太大了怎么处理
//2.7.1代码整改：将溢满增大函数封装，增加重用性、
//2.7.2将函数放到主函数下面，上面放声明，就不必考虑逻辑问题了（谁上谁下）
//相互调用函数用一级指针或二级指针或者三、四级指针都是可以的

//2.8~9 删		上面的属于增
//删有三种形式：1.删除尾	2.删除中间	3.删除全部


//中间插入元素要点
//下标以后的数据整体向后挪一位
//然后在下标处添加数据
//当下标大于已存量时，有两种方式，1.异常处理，2.添加到尾部
//对于一些边界条件，不要浪费时间在上面，等写出出整体程序后，再调试
//调试了很久很久我才把边界条件弄好
//VS2019的警告很精细，我们没有必要全部清除，浪费时间，但是要确保我们程序逻辑上无误
//*工作中常用的不是单个元素增加，而是多个，我们可以按单个元素思路，写个循环，将循环封装成函数，就实现了多个元素插入。


//动态数组三个重要变量		//结构体不能放到下面然后再声明
struct DongShuZu
{
	int* ShuuZuTou;				//数组头（数组首地址）
	unsigned int ZongCunLiang;	//总存量
	unsigned int YiCunLiang;	//已存量
};	   


//数组变量初始化函数
void ChuShiHua(struct DongShuZu* idsz);

//容量溢满增大封装函数
void BianHua(struct DongShuZu* idsz);		//变量指针、数据、下标

//尾部添加函数
void TianJia(struct DongShuZu* idsz, int ShuJu);

//中间插入函数
void ChaRu(struct DongShuZu* idsz, int ShuJu, unsigned int XiaBiao);

//打印输出函数
void show(struct DongShuZu* idsz);

//删除尾
void ShanChuWei(struct DongShuZu* idsz);

//删除全部
void ShanChuQuanBu(struct DongShuZu* idsz);

//删除中间
void ShanChuZhongJian(struct DongShuZu* idsz, unsigned int DiJiGe);



//主函数
int main(void)
{
	struct DongShuZu CeShi;
	ChuShiHua(&CeShi);			//初始化

	TianJia(&CeShi, 3);
	TianJia(&CeShi, 8);
	TianJia(&CeShi, 4);
	TianJia(&CeShi, 2);
	TianJia(&CeShi, 7);
	TianJia(&CeShi, 1);
	show(&CeShi);				//打印

	//测试中间插入
	ChaRu(&CeShi, 9, 1);		
	printf("中间插入后： \n");
	show(&CeShi);

	//测试下标大于已存量时
	ChaRu(&CeShi, 56, 11);		
	printf("插入下标大于已存量时： \n");
	show(&CeShi);

	//测试删除尾					//经测试：3种方式都成功完成
	ShanChuWei(&CeShi);
	printf("删除尾时： \n");
	show(&CeShi);

	//测试删除尾然后再添加
	TianJia(&CeShi, 77);
	printf("删除尾再添加后： \n");
	show(&CeShi);

	//测试删除全部				//经测试，3种方式都成功完成
	ShanChuQuanBu(&CeShi);
	printf("删除全部时： \n");
	show(&CeShi);

	//测试删除全部然后再添加		///严格意义这里测试删除全部的第3种方法：释放后，这里应该初始化，但没初始化也可以，不知道为什么
	TianJia(&CeShi, 88);
	printf("删除全部再添加后： \n");
	show(&CeShi);

	//删除中间测试
	TianJia(&CeShi, 8);
	TianJia(&CeShi, 4);
	TianJia(&CeShi, 2);
	TianJia(&CeShi, 7);
	TianJia(&CeShi, 1);
	printf("删除中间前： \n");
	show(&CeShi);

	printf("删除中间后： \n");	//测试成功
	ShanChuZhongJian(&CeShi, 2);
	show(&CeShi);

	//测试删除中间，参数过大
	ShanChuZhongJian(&CeShi, 9);//测试成功
	show(&CeShi);



	free(CeShi.ShuuZuTou);		//之前写成free(&CeShi.ShuuZuTou),调试了很久，不要这样写，会中断崩溃

	return 0;
}


//数组变量初始化函数
void ChuShiHua(struct DongShuZu* idsz)
{
	if (idsz == NULL)
	{
		printf("初始化函数：参数错误\n");
		return;
	}

	if (idsz)
	{
		idsz->ZongCunLiang = 4;
		idsz->ShuuZuTou = (int*)malloc(sizeof(int) * idsz->ZongCunLiang);
		idsz->YiCunLiang = 0;
	}
}

//容量溢满增大封装函数
void BianHua(struct DongShuZu* idsz)		//变量指针、数据、下标
{

	//异常报告
	if (idsz == NULL)
	{
		printf("元素变化函数：传入参数错误\n");
		return;
	}

	if (idsz)	//防止NULL指针参数
	{
		//检查总存量是否满了
		if (idsz->ZongCunLiang == idsz->YiCunLiang)
		{
			//1.总存量变大
			idsz->ZongCunLiang += 5;

			//2.申请新空间
			int* newTou = (int*)malloc(sizeof(int) * idsz->ZongCunLiang);
			//memset(newTou, 0, sizeof(int) * idsz->ZongCunLiang);		//老师的视频用memset给newTou赋值初始化了，写不写都行
		//3.将原空间数据复制到新空间
			for (unsigned int i = 0; i < idsz->YiCunLiang; i++)			//i < (idsz->YiCunLiang-1)之前这么写，打印结果错了,
			{															//我分析了一下刚好是第4个数据出错，因为i=3时按之前的写法就不执行语句了，
				if (newTou)	//防止NULL指针参数							//实际上只执行了3次，所以第4个数据没有复制过去（终于弄清楚了！！）
				{
					newTou[i] = idsz->ShuuZuTou[i];
				}
			}

			//4.释放原空间
			free(idsz->ShuuZuTou);

			//5.指定新空间数组头
			idsz->ShuuZuTou = newTou;
		}

	}

}

//尾部添加函数
void TianJia(struct DongShuZu* idsz, int ShuJu)
{
	BianHua(idsz);		//这里用一级指针或二级指针都是可以的，一级指针两个都指向外部的动态数组，地址是一样的
						//二级指针的话，被调用的用的是动态数组的地址的地址，效果是一样的
	//尾部添加数据
	idsz->ShuuZuTou[idsz->YiCunLiang] = ShuJu;

	//已存量大小变化
	idsz->YiCunLiang++;
}

//中间插入函数
void ChaRu(struct DongShuZu* idsz, int ShuJu, unsigned int XiaBiao)
{

	////下标大于已存量，添加到尾部（自写）
	//if (XiaBiao >= idsz->YiCunLiang)
	//{	
	//	TianJia(idsz, ShuJu);
	//	return;			//退出不执行下面
	//}

	//下标过大，老师的方法更简便
	if (XiaBiao > idsz->YiCunLiang)		//当下标等于已存量时，向后移的步骤因为i > XiaBiao不执行
	{									//直接就添加到结尾了
		XiaBiao = idsz->YiCunLiang;
	}

	//下标的后面数据向后移一位
	for (unsigned int i = idsz->YiCunLiang; i > XiaBiao; i--)
	{
		idsz->ShuuZuTou[i] = idsz->ShuuZuTou[i - 1];
	}

	//下标位置插入指定的数据
	idsz->ShuuZuTou[XiaBiao] = ShuJu;

	//已存量大小变化
	idsz->YiCunLiang++;

}

//打印输出函数
void show(struct DongShuZu* idsz)
{
	if (idsz == NULL)
	{
		printf("打印函数：输入参数错误\n");
		return;
	}

	if (idsz)	//防止NULL指针参数
	{
		printf("总存量为：%u, 已存量为：%u \n", idsz->ZongCunLiang, idsz->YiCunLiang);
		printf("数据为：");
		for (unsigned int i = 0; i < idsz->YiCunLiang; i++)
		{
			printf("%u ", idsz->ShuuZuTou[i]);
		}
		printf("\n\n");
	}
}

//删除尾
void ShanChuWei(struct DongShuZu* idsz)
{
	//参数合法性检测（工作中必用到的）
	if (idsz == NULL)
	{
		printf("删除尾函数：传入参数错误\n");
		return;
	}

	//方式1	仅将已存量减少	不改变容量，也不将末尾元素归0
		idsz->YiCunLiang--;

	//方式2	将末尾元素重置为0，不改变容量，减少已存量
		/*idsz->ShuuZuTou[idsz->YiCunLiang - 1] = 0;
		idsz->YiCunLiang--;*/

	//方式3	根据情况改变容量，且将末尾元素归0或剔除		写法参考尾添加
		//if (idsz->ZongCunLiang >= idsz->YiCunLiang - 1)
		//{

		//	idsz->ZongCunLiang = idsz->YiCunLiang-1;

		//	int* newTou = (int*)malloc(sizeof(int) * idsz->ZongCunLiang);

		//	idsz->YiCunLiang--;						//将已存量减少写在这里，能使下面少复制

		//	for (unsigned int i = 0; i < idsz->YiCunLiang; i++)				
		//	{																
		//		if (newTou)	//防止NULL指针参数							
		//		{
		//			newTou[i] = idsz->ShuuZuTou[i];
		//		}
		//	}
		//	free(idsz->ShuuZuTou);
		//	idsz->ShuuZuTou = newTou;
		//}

	//三种方式，方式1最合适，因为2和3操作多余了，实际情况我们不可能不再修改这个数组，不大可能不再添加，
	//等再添加时，也是直接覆盖掉末尾元素的值，0和别的数没区别，所以归0没必要，修改容量后，可能添加元素时又要再增加容量，影响效率
	//所以直接已存量-1是一般而言最合适最高效的做法的方法
}

//删除全部
void ShanChuQuanBu(struct DongShuZu* idsz)
{
	//参数合法性检测（工作中必用到的）
	if (idsz == NULL)
	{
		printf("删除全部：传入参数错误\n");
		return;
	}

//方式1：将已存量减为0即可	不改变容量，也不将数据归0
	/*idsz->YiCunLiang = 0;*/

//方式2：全部数据归0，已存量减为0，不改变容量
	/*memset(idsz->ShuuZuTou, 0, sizeof(int)*idsz->YiCunLiang);
	idsz->YiCunLiang = 0;*/

//方式3：释放掉这个变量，全部清空，使指针为NULL
	idsz->YiCunLiang = 0;
	idsz->ZongCunLiang = 0;
	free(idsz->ShuuZuTou);
	idsz->ShuuZuTou = NULL;

//用那种都可以，第1种更高效，第三种也是有意义的，根据需求是否释放
}

//删除中间
void ShanChuZhongJian(struct DongShuZu* idsz, unsigned int DiJiGe)
{
	//输入参数合法性检测
	if (idsz->ShuuZuTou == NULL || DiJiGe > idsz->YiCunLiang)		//参数过大，与参数为NULL的检测
	{																//这是删除，不是添加不能随意删除数据
		printf("删除中间输入参数无效\n");								//所以参数过大一定不要随意处理，
		return;
	}

	//将需要删除的位置后面的数据向前移
	for (unsigned int i = DiJiGe - 1; i < idsz->YiCunLiang - 1; i++)
	{
		idsz->ShuuZuTou[i] = idsz->ShuuZuTou[i + 1];				//边界条件等程序写好以后再来调试，别浪费时间
	}																//i是下标，最右只能移动到下标为i+1的数，而下标为i+1的数是已存量的位置
																	//i+1 = Y-1 两个代表的下标相同，所以i < Y-1没问题，刚好到边界，注意边界不要超
	//已存量-1
	idsz->YiCunLiang--;

}
