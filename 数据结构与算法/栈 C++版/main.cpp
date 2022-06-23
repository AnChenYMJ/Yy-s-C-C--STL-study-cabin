#include <iostream>
//#include <stdbool.h>	//C语言使用bool类型需要头文件

using namespace std;

struct Node
{
	int a;
	struct Node* pNext;
	struct Node* pPre;
};

class ST
{
private:
	struct Node* StHead;

	//栈的创建：创建一个空头（本课时采用双向循环链表）
	struct Node* Stack();
	//释放栈
	void FreeStack();
public:
	ST()
	{
		StHead = Stack();
	}
	~ST()
	{
		FreeStack();
	}
public:
	
	//压栈（尾添加）
	void Push(int iData);
	//判断栈里有没有元素
	bool IsEmpty();
	//获取栈顶不删除
	struct Node* Top();
	//栈顶并删除
	void Pop();
};


int main(void)
{
	ST st;
	//判断栈里有没有元素
	bool a = st.IsEmpty();
	//压栈(入栈)//进数据时为：12345
	int arr[5] = { 1, 2, 3, 4, 5 };
	st.Push(arr[0]);
	st.Push(arr[1]);
	st.Push(arr[2]);
	st.Push(arr[3]);
	st.Push(arr[4]);
	//判断栈里有没有元素
	a = st.IsEmpty();

	//出栈(从栈里取元素)//取数据时：54321，遵循先进后出，原因是只能在同一侧操作
	arr[0] = st.Top()->a;
	st.Pop();
	arr[1] = st.Top()->a;
	st.Pop();
	arr[2] = st.Top()->a;
	st.Pop();
	arr[3] = st.Top()->a;
	st.Pop();
	arr[4] = st.Top()->a;
	st.Pop();
	//判断栈里有没有元素
	a = st.IsEmpty();



	system("pause>0");
	return 0;
}


struct Node* ST::Stack()
{
	//申请节点
	struct Node* pTemp = (struct Node*)malloc(sizeof(struct Node));
	if (pTemp == NULL)
		return NULL;
	//节点初始化（注意这是双向循环链表空头的初始化）
	pTemp->a = 0;
	pTemp->pNext = pTemp;
	pTemp->pPre = pTemp;
	//返回该空头地址
	return pTemp;
}
void ST::Push(int iData)
{
	//参数合法性检测
	if (&StHead == NULL || StHead == NULL)
		return;
	//创建新节点
	struct Node* pTemp = (struct Node*)malloc(sizeof(struct Node));
	if (pTemp == NULL)
		return;
	//节点赋值
	pTemp->a = iData;
	pTemp->pNext = NULL;
	pTemp->pPre = NULL;
	//将节点插入到尾节点后
	//新节点先与尾节点、头节点相连
	pTemp->pNext = StHead;
	pTemp->pPre = StHead->pPre;
	//原尾节点与头节点之间断开
	StHead->pPre->pNext = pTemp;
	StHead->pPre = pTemp;
}
bool ST::IsEmpty()
{
	//参数合法性检测
	if (&StHead == NULL || StHead == NULL)
		return false;
	//判断是否有元素（除空头外）
	if (StHead->pNext == StHead)
		return false;
	else
		return true;
}
void ST::FreeStack()
{
	//参数合法性检测
	if (StHead == NULL || &StHead == NULL)
		return;
	//从空头开始释放
	struct Node* pTemp = StHead;
	//因为要从头释放，所以用do while 先执行一次再判断，否则第一次就直接跳过循环了
	do
	{
		//记录当前节点地址
		struct Node* pT = pTemp;
		//指针向下遍历
		pTemp = pTemp->pNext;
		//释放记录的节点
		free(pT);
	} while (pTemp != StHead);

	//释放完，空头地址赋空
	StHead = NULL;
}
struct Node* ST::Top()
{
	//参数合法性检测
	if (&StHead == NULL || StHead == NULL)
		return NULL;
	//如果该链表没有元素
	if (IsEmpty() == 0)
		return NULL;
	//有元素，返回尾节点
	else
		return StHead->pPre;
}
void ST::Pop()
{
	//参数合法性检测
	if (&StHead == NULL || StHead == NULL)
		return;
	//该链表没有元素
	if (IsEmpty() == 0)
		return;
	//有元素
	else
	{
		//记录尾节点
		struct Node* pTemp = StHead->pPre;
		//将该节点从链表上独立开
		pTemp->pPre->pNext = StHead;
		StHead->pPre = pTemp->pPre;
		//释放该节点
		free(pTemp);
	}
}
