#include <iostream>
#include <string.h>			//函数memset()的头文件

using namespace std;


//特点
void TeDian()
{
//1.空间连续
	//每个元素都是相邻的，地址也是相邻排序的

//2.优点：
	//*能随机访问，且访问速度快。下标访问
	//下标访问本质其实就是地址的增减，所以快

//3.缺点：
	//*增、删、效率慢
	//原因是增删涉及到新空间的申请与数据的复制
	//还有中间插入与删除时，涉及到数据的前、后移

//选取：
 	//链表则是增删快，访问慢
	//当实际需求中，数据访问次数占主要时，选数组更好
	//当对数据修改，增删占主要时，选择链表作为数据结构更好
	//当数据量不大，或者两者需求相近时，选哪个都可以
	//也有折中的选择，就是红黑树基础改进的数据结构，
	//如STL里的map，访问速度比链表快很多，但比数组慢一点；增删效率比数组快很多，但比链表慢一点。

//忠告：
	//算法都是人想出来的，但不要一昧的去抄别人（厉害的人）的写法，或者直接搜哪个函数
	//我们到带着自己的思考，自己想怎么做了，再去做，或者再参靠学习别人的做法，才能成长技能
}

//以下为上一源文件改成C++版的，请对照上一文件的注释与内容，修改如下：
//1.结构体改成类，函数放进去，函数实现加类名作用域 DongShuZu::
//2.访问修饰符分类
//3.删除当前类内函数的参数
//4.修改对象调用（将结构体变为对象，与对象调用函数）
//5.new delete 代替 malloc free		(new int[] : int为元素类型，[]内是元素个数，返回值是空间首地址，无需强转)（delete[] 空间地址 : 对象数组释放在delete后加[]，普通数组可不加，为了规范还是加上）
//6.编写构造函数 与 析构函数	（构造函数：构建对象时执行，一般用来初始化，析构函数，程序结束时自动执行，用来释放空间）
//7.cout 替代 printf			(cout 的换行也可以用 "\n" '\n' 或者 endl ，运行效率'\n' > "\n" > endl)因为endl涉及到传冲区更新


//类
class DongShuZu					//改为类
{
private:						//私有
	int* ShuuZuTou;				//数组头（数组首地址）
	unsigned int ZongCunLiang;	//总存量
	unsigned int YiCunLiang;	//已存量
	void BianHua();				//容量溢满增大封装函数	(将这个变为私有的，仅类内或友元能调用)
	
public:							//此处用来分类
	DongShuZu();				//构造函数	：构建对象时执行，一般用来初始化
	~DongShuZu();				//析构函数	：程序结束时自动执行，一般用来释放空间


public:							//共有的
	//数组变量初始化函数
	void ChuShiHua();			

	//尾部添加函数
	void TianJia(int ShuJu);	//void TianJia(struct DongShuZu* idsz, int ShuJu);以此为例，因为在类内，所以不存在传对象（结构体）指针来调用了，故删掉第一个结构体指针参数

	//中间插入函数
	void ChaRu(int ShuJu, unsigned int XiaBiao);

	//打印输出函数
	void show();

	//删除尾
	void ShanChuWei();

	//删除全部
	void ShanChuQuanBu();

	//删除中间
	void ShanChuZhongJian(unsigned int DiJiGe);

};

//主函数
int main()
{
	class DongShuZu CeShi;

	CeShi.TianJia(3);
	CeShi.TianJia(8);
	CeShi.TianJia(4);
	CeShi.TianJia(2);
	CeShi.TianJia(7);
	CeShi.TianJia(1);
	CeShi.show();				//打印

	//测试中间插入
	CeShi.ChaRu(9, 1);
	cout << "中间插入后： \n";
	CeShi.show();

	//测试下标大于已存量时
	CeShi.ChaRu(56, 11);
	cout << "插入下标大于已存量时： \n";
	CeShi.show();

	//测试删除尾					
	CeShi.ShanChuWei();
	cout << "删除尾时： \n";
	CeShi.show();

	//测试删除尾然后再添加
	CeShi.TianJia(77);
	cout << "删除尾再添加后： \n";
	CeShi.show();

	//测试删除全部				//改成C++版之后，删除全部按照方法3，ShuuZuTou变成NULL，导致出错
	CeShi.ShanChuQuanBu();		//因为ShuuZuTou只有一个还变成了NULL，要重新给ShuuZuTou申请空间才行
	cout << "删除全部时： \n";
	CeShi.show();

	//测试删除全部然后再添加		
	CeShi.ChuShiHua();			//因为删除全部释放了指针，所以初始化，重新申请空间
	CeShi.TianJia(88);
	cout << "删除全部再添加后： \n";
	CeShi.show();

	//删除中间测试
	CeShi.TianJia(8);
	CeShi.TianJia(4);
	CeShi.TianJia(2);
	CeShi.TianJia(7);
	CeShi.TianJia(1);
	cout << "删除中间前： \n";
	CeShi.show();

	cout << "删除中间后： \n";
	CeShi.ShanChuZhongJian(2);
	CeShi.show();

	//测试删除中间，参数过大
	CeShi.ShanChuZhongJian(9);
	CeShi.show();


	//free(CeShi.ShuuZuTou);	//C++将释放空间放到了析构函数中，且改成了delete

	return 0;
}

//构造函数
DongShuZu::DongShuZu()
{
	ChuShiHua();		//初始化
}

//析构函数
DongShuZu::~DongShuZu()
{
	delete[] ShuuZuTou;	//释放空间
}

//数组变量初始化函数		//加上类名作用域 DongShuZu::
void DongShuZu::ChuShiHua()					//以此为例：将其与类关联则需要添加DongShuZu::类名作用域
{
	//if (ShuuZuTou == NULL)				//因为删除全部的方法3要释放掉ShuuZuTou，变为NULL，导致程序卡住
	//{										//这里为了继续下面的测试，取消参数合法性检测，让初始化直接重新申请空间
	//	cout << "初始化函数：参数错误\n";
	//	return;
	//}

	/*if (ShuuZuTou)
	{*/
		ZongCunLiang = 4;					//idsz->ZongCunLiang = 4;以此为例，直接调用类内成员ZongCunLiang即可，无需指针调用
		ShuuZuTou = new int[sizeof(int) * ZongCunLiang];	
		YiCunLiang = 0;						//(new int[] : int为元素类型，[]内是元素个数，返回值是空间首地址，无需强转)
	//}
}

//容量溢满增大封装函数
void DongShuZu::BianHua()		//变量指针、数据、下标
{

	//异常报告
	if (ShuuZuTou == NULL)
	{
		cout << "元素变化函数：传入参数错误\n";
		return;
	}

	if (ShuuZuTou)	//防止NULL指针参数
	{
		//检查总存量是否满了
		if (ZongCunLiang == YiCunLiang)
		{
			//1.总存量变大
			ZongCunLiang += 5;

			//2.申请新空间
			int* newTou = new int[sizeof(int) * ZongCunLiang];
			//memset(newTou, 0, sizeof(int) * idsz->ZongCunLiang);		//老师的视频用memset给newTou赋值初始化了，写不写都行
		//3.将原空间数据复制到新空间
			for (unsigned int i = 0; i < YiCunLiang; i++)			//i < (YiCunLiang-1)之前这么写，打印结果错了,
			{															//我分析了一下刚好是第4个数据出错，因为i=3时按之前的写法就不执行语句了，
				if (newTou)	//防止NULL指针参数							//实际上只执行了3次，所以第4个数据没有复制过去（终于弄清楚了！！）
				{
					newTou[i] = ShuuZuTou[i];
				}
			}

			//4.释放原空间
			delete[] ShuuZuTou;

			//5.指定新空间数组头
			ShuuZuTou = newTou;
		}

	}

}

//尾部添加函数
void DongShuZu::TianJia(int ShuJu)
{
	BianHua();		//因为是类内，无需指针调用
						
	//尾部添加数据
	ShuuZuTou[YiCunLiang] = ShuJu;

	//已存量大小变化
	YiCunLiang++;
}

//中间插入函数
void DongShuZu::ChaRu(int ShuJu, unsigned int XiaBiao)
{

	////下标大于已存量，添加到尾部（自写）
	//if (XiaBiao >= idsz->YiCunLiang)
	//{	
	//	TianJia(idsz, ShuJu);
	//	return;			//退出不执行下面
	//}

	//下标过大，老师的方法更简便
	if (XiaBiao > YiCunLiang)		//当下标等于已存量时，向后移的步骤因为i > XiaBiao不执行
	{									//直接就添加到结尾了
		XiaBiao = YiCunLiang;
	}

	//下标的后面数据向后移一位
	for (unsigned int i = YiCunLiang; i > XiaBiao; i--)
	{
		ShuuZuTou[i] = ShuuZuTou[i - 1];
	}

	//下标位置插入指定的数据
	ShuuZuTou[XiaBiao] = ShuJu;

	//已存量大小变化
	YiCunLiang++;

}

//打印输出函数
void DongShuZu::show()
{
	if (ShuuZuTou == NULL)
	{
		cout << "打印函数：输入参数错误\n";
		return;
	}

	if (ShuuZuTou)	//防止NULL指针参数
	{
		cout << "总存量为：" << ZongCunLiang << ' ' << "已存量为：" << YiCunLiang << '\n';
		cout << "数据为：";
		for (unsigned int i = 0; i < YiCunLiang; i++)
		{
			cout << ShuuZuTou[i] << ' ';
		}
		cout << "\n\n";
	}
}

//删除尾
void DongShuZu::ShanChuWei()
{
	//参数合法性检测（工作中必用到的）
	if (ShuuZuTou == NULL)
	{
		cout << "删除尾函数：传入参数错误\n";
		return;
	}

	//方式1	仅将已存量减少	不改变容量，也不将末尾元素归0
	//YiCunLiang--;

	//方式2	将末尾元素重置为0，不改变容量，减少已存量
		ShuuZuTou[YiCunLiang - 1] = 0;
		YiCunLiang--;

		//方式3	根据情况改变容量，且将末尾元素归0或剔除		写法参考尾添加
			//if (ZongCunLiang >= YiCunLiang - 1)
			//{

			//	ZongCunLiang = YiCunLiang-1;

			//	int* newTou = new int[sizeof(int) * ZongCunLiang];

			//	YiCunLiang--;						//将已存量减少写在这里，能使下面少复制

			//	for (unsigned int i = 0; i < YiCunLiang; i++)				
			//	{																
			//		if (newTou)	//防止NULL指针参数							
			//		{
			//			newTou[i] = ShuuZuTou[i];
			//		}
			//	}
			//	delete[] ShuuZuTou;
			//	ShuuZuTou = newTou;
			//}

		//三种方式，方式1最合适，因为2和3操作多余了，实际情况我们不可能不再修改这个数组，不大可能不再添加，
		//等再添加时，也是直接覆盖掉末尾元素的值，0和别的数没区别，所以归0没必要，修改容量后，可能添加元素时又要再增加容量，影响效率
		//所以直接已存量-1是一般而言最合适最高效的做法的方法
}

//删除全部
void DongShuZu::ShanChuQuanBu()
{
	//参数合法性检测（工作中必用到的）
	if (ShuuZuTou == NULL)
	{
		cout << "删除全部：传入参数错误\n";
		return;
	}

	//方式1：将已存量减为0即可	不改变容量，也不将数据归0
		/*YiCunLiang = 0;*/

	//方式2：全部数据归0，已存量减为0，不改变容量
		/*memset(ShuuZuTou, 0, sizeof(int)*YiCunLiang);
		YiCunLiang = 0;*/

	//方式3：释放掉这个变量，全部清空，使指针为NULL
	YiCunLiang = 0;
	ZongCunLiang = 0;
	delete[] ShuuZuTou;
	ShuuZuTou = NULL;		//改成C++版之后，NULL指针就导致无法继续了，因为ShuuZuTou只有一个还变成了NULL，要重新申请空间才行

	//用那种都可以，第1种更高效，第三种也是有意义的，根据需求是否释放
}

//删除中间
void DongShuZu::ShanChuZhongJian(unsigned int DiJiGe)
{
	//输入参数合法性检测
	if (ShuuZuTou == NULL || DiJiGe > YiCunLiang)		//参数过大，与参数为NULL的检测
	{																//这是删除，不是添加不能随意删除数据
		cout << "删除中间输入参数无效\n";								//所以参数过大一定不要随意处理，
		return;
	}

	//将需要删除的位置后面的数据向前移
	for (unsigned int i = DiJiGe - 1; i < YiCunLiang - 1; i++)
	{
		ShuuZuTou[i] = ShuuZuTou[i + 1];				//边界条件等程序写好以后再来调试，别浪费时间
	}																//i是下标，最右只能移动到下标为i+1的数，而下标为i+1的数是已存量的位置
																	//i+1 = Y-1 两个代表的下标相同，所以i < Y-1没问题，刚好到边界，注意边界不要超
	//已存量-1
	YiCunLiang--;

}