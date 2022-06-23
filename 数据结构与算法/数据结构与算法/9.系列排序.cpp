#include <iostream>
#include <stdlib.h>
#include <stack>		//STL 栈的容器
#include <queue>		//STL 队列的容器

using namespace std;

//冒泡排序：看C3老师的图方便理解
void MaoPao(int arr[], int a)
{	//传数组参数的方式就是这样，第二个是数组元素个数
	//a有多少个，就经过几遍循环
	for (int i = 1; i <= a; i++)
	{
		//j < a-i是优化后的结论，本来是j < a-1即可，但是会发现，每次循环，第一次将最小的数交换到最后面了
		//这样下一次最后一个数就不用再交换，所以交换次数随被排到最后面的数的增加而减少，
		//就像冒泡泡，总的泡泡固定，冒出来确定的泡泡越多，剩下的泡泡越少，需要交换的次数每次都-1
		for (int j = 0; j < a-i; j++)
		{	//第一次循环交换的次数为a-1，自己画图就知道为什么交换这些次数了
			if (arr[j] < arr[j + 1])//此处是从大到小排序，切换<>就改变排序顺序了
			{
				//交换
				int swap = (arr[j]);
				(arr[j]) = (arr[j + 1]);
				(arr[j + 1]) = swap;
			}
		}
	}
	
}

//选择排序：看C3老师的图方便理解
void XuanZe(int arr[], int o)
{
	//（本函数现在是从大到小排序，最小的数与最右侧比较交换）
	//我们可以从剩下数中选择最 大/小 的与最 左/右 的进行交换，四种交换方式，看自己需求选择哪种
	//比如有100个数，那循环99次即可

	//int InGin = o;		//用来记录，未排序的元素个数
	//此处用i来代替了InGin的功能，并且还控制了循环次数
	for (int i = o-1; i > 0; i--)
	{
		int Min = arr[0];	//记录最小的数
		int Index = 0;		//记录对应数的下标
		//1.找到数组中 还未排序的数中最小的那个数
		for (int n = 0; n < i; n++)
		{
			if (Min > arr[n])
			{
				Min = arr[n];
				Index = n;
			}
		}
		//2.用这个最小的数与 剩下未排序的数中最右侧的数比较
		if (Min < arr[i])
		{
			int swap = arr[Index];
			arr[Index] = arr[i];
			arr[i] = swap;
		}
		//InGin -= 1;
	}
	
}

//插入排序：自己画图，有点抽象，要好好思考，代码简单，但是不好理解
void ChaRu(int arr[], int n)
{	//插入排序将数组分成了有序部分+无序部分，最开始只有第1个元素是有序的
	//外层循环，是遍历未排序的部分，i从第2个元素开始往后遍历，第1个元素默认一开始就是有序的部分
	for (int i = 1; i < n; i++)
	{	//这里i就是当前指向无序部分 需要与有序部分比较的元素的指针


		//因为比较然后插入时，有序部分在比较后，不满足插入条件的元素向后移动了一格，就将无序部分原本i所在的位置顶掉了
		//所以要单独记录i位置的元素
		int Temp = arr[i];
		//内层循环就是有序部分，用外层i指向的元素，依次（由j向0方向）与有序部分的元素进行比较
		for (int j = i-1; j >= 0; j--)
		{
			//如果j指向的元素与Temp比较，满足条件，则将Temp插入到当前j + 1的位置。
			//不必担心j+1往后的元素，因为j+1往后的元素都整体向后移动了一格，有序部分最靠后的元素顶掉了原本i的位置
			//也就是说：当前的j+1位置是空出来的，满足则将Temp插入，不满足则将j的元素插入，然后继续向前比较
			if (arr[j] <= Temp)
			{	//判断条件决定着从小到大、从大到小的顺序
				//满足条件则将Temp插入，然后跳出循环，不跳出的话，当前j的位置继续向后移动一格，会把Temp覆盖掉，这样Temp就丢失了
				arr[j + 1] = Temp;
				break;
			}
			//不满足条件，则将当前j位置元素向后移动一格
			arr[j + 1] = arr[j];
			//如果j为0，则证明有序部分没有元素能满足比较，此时就把Temp插入到下标0的位置，
			//此时的有序部分整体向后移动了一格，顶掉了原本i的位置，下标0则是空出来的位置，将Temp插入
			if (0 == j)
				arr[0] = Temp;
		}
	}
}

//快速排序，整体逻辑文字不好描述，看C3的文档容易一些（微信公众号：C3程序猿），原理是数学问题
void KuaiSu(int* arr, int left, int right)
{	//快速排序本质是冒泡排序，但是效率比冒泡排序高，查找交换的循环次数比冒泡少，详情看C3文档
	if (left >= right)//递归的结束条件，递归执行到这里，发现不能再递归了
		return;
	else
	{
		//q是从左向右与基数比较、h是从右向左与基数比较，基数是left所在的数
		int q = left, h = right;
		while (q < h)
		{
			//先让h从右向左遍历查找比基数小的数
			//右侧h指向的元素，比基数arr[left]大或相等，则继续向左遍历（此处是希望从小到大排序，可修改）
			while (q < h && arr[h] >= arr[left])
			{
				h--;
			}
			//再让q从左向右遍历查找比基数大的数
			//左侧q指向的元素，比基数arr[left]小或相等，则继续向右遍历
			while (q < h && arr[q] <= arr[left])
			{
				q++;
			}
			//如果q h 相遇了，则不再查找，跳出循环
			if (q == h)
				break;
			//如果q h没相遇，证明q h 分别找到各自那边对应的数，把这两个数进行交换
			int swap = arr[h];
			arr[h] = arr[q];
			arr[q] = swap;
		}
		//基数归位
		//q 与 h 相遇了，如果这个位置不是基数的位置，则交换基数到这个位置
		if (left != q)	//基数归位：数学原理，我不清楚，但是确定的是，当进行了基数归位后，q == h的这个位置，就是基数排序后应该在的位置，不会变了
		{
			int swap = arr[q];
			arr[q] = arr[left];
			arr[left] = swap;
		}
		//递归：第一次找完，数组被分割成两段，还要再分别对这两段进行查找交换，然后再分割成更多小段，然后再查。直到不能分割，每一小段都查完，排序就完成了
		KuaiSu(arr, left, q - 1);	//分割后的左边，分割后q == h 且进行了基数归位，那个位置的数已经是排序后基数的位置，无需再参加剩下查找交换
		KuaiSu(arr, h+1, right);	//分割后的右边
	}
}
//快速排序（非递归写法，栈）
void KuaiSu1(stack<int> st, int* arr, int left, int right)
{
	st.push(left);		//入栈
	st.push(right);		//注意栈是先进后出

	//循环实现递归一样的功能
	while (!st.empty())	//栈里有元素则继续，为NULL则不进入循环
	{
		right = st.top();//从栈顶取元素
		st.pop();		//删除栈顶
		left = st.top();//注意出栈顺序，先入栈的后出
		st.pop();

		int q = left, h = right;
		while (q < h)
		{
			//h向前遍历
			while (q < h && arr[h] <= arr[left])
				h--;
			//q向后遍历
			while (q < h && arr[q] >= arr[left])
				q++;
			//q与h相遇
			if (q == h)
				break;
			int swap = arr[q];
			arr[q] = arr[h];
			arr[h] = swap;
		}
		//基数归位
		if (q != left)
		{
			int swap = arr[q];
			arr[q] = arr[left];
			arr[left] = swap;
		}
		//q h 判断切割的小块是否能继续
		//能继续则入栈 以两个为一组进行查找交换，
		//所有的小段都这样分成两个一组存到栈中进行一样的操作
		//等全部操作完、数组就排好序了
		if (q-1 > left)
		{
			st.push(left);
			st.push(q - 1);
		}
		if (h+1 < right)
		{
			st.push(h + 1);
			st.push(right);
		}		
	}
}
//快速排序（非递归写法，栈）
void KuaiSu2(queue<int> qu, int* arr, int left, int right)
{
	qu.push(left);		//入队
	qu.push(right);		//注意队列是先进先出

	//循环实现递归一样的功能
	while (!qu.empty())	//栈里有元素则继续，为NULL则不进入循环
	{
		left = qu.front();//从队尾取元素
		qu.pop();		//删除队尾
		right = qu.front();//出队顺序：先入栈的先出，所以队尾就是先存的数，先出
		qu.pop();

		int q = left, h = right;
		while (q < h)
		{
			//h向前遍历
			while (q < h && arr[h] >= arr[left])
				h--;
			//q向后遍历
			while (q < h && arr[q] <= arr[left])
				q++;
			//q与h相遇
			if (q == h)
				break;
			int swap = arr[q];
			arr[q] = arr[h];
			arr[h] = swap;
		}
		//基数归位
		if (q != left)
		{
			int swap = arr[q];
			arr[q] = arr[left];
			arr[left] = swap;
		}
		//q h 判断切割的小块是否能继续
		//等全部操作完、数组就排好序了
		if (q - 1 > left)
		{
			qu.push(left);
			qu.push(q - 1);
		}
		if (h + 1 < right)
		{
			qu.push(h + 1);
			qu.push(right);
		}
	}
}

//shell排序（希尔排序）
void shell(int* arr, int n)
{	//是插入排序的变种，效率比插入排序高，（为什么高是数学问题，我暂时不做探究），分段的大小可以自己看着办，定义一个变量记录指向查找的次数就能观测到效率变化
	//整体的运行逻辑是先进行几次大排序，最后一次进行细致排序（标准的插入排序）
	int I = 0;			//执行循环次数记录
	int x = 5;			//x是要分段的大小，x == 4 则说明4个元素为一段，每一段每次循环选出一个元素与其它段选出的元素比较
	for (; x >= 1; x--)	//每次x-1 再插入排序一次
	{					//i < n-x的原因：k是当作遍历下标使用的，所以k < n，而k == i+x，所以i+x < n ,所以 i<n-x
		for (int i = 0; i < n - x; i += x)	//这里的i是指向有序部分的元素，第一次外层循环i就是每段的第一个元素，第2次外层循环就是每段的第2个元素
		{
			int k = i + x;				//k指向的是无序部分要比较的数
			int Temp = arr[k];

			while (k >= 0 && Temp < arr[k - x])//此处是从小到大排序
			{
				arr[k] = arr[k - x];	//将有序部分不满足插入条件的向后挪
				k -= x;					//k继续向前查找合适插入的位置
				I++;					// 执行循环次数记录
			}

			arr[k] = Temp;				//将Temp插入到查到的合适的位置
			
		}
	}

}

int main(void)
{
//冒泡排序
{
	int arr[7] = { 6, 1, 1, 2, 8, 3, 7 };
	int* p = arr; 
		printf("\n冒泡排序前：");
	for (int i = 0; i < 7; i++)
		printf(" %d", p[i]);
	//冒泡排序
	MaoPao(p, 7);
	printf("\n冒泡排序后：");
	for(int i = 0; i < 7; i++)
		printf(" %d", p[i]);

	printf("\n");
}
//选择排序
{
	int arr[8] = { 6, 6, 8, 1, 3, 1, 2, 5 };
	int* p = arr;	//记录数组的地址

	printf("\n选择排序前：");
	for (int i = 0; i < 8; i++)
		printf(" %d", p[i]);

	//选择排序
	XuanZe(p, 8);

	printf("\n选择排序后：");
	for (int i = 0; i < 8; i++)
		printf(" %d", p[i]);
	
	printf("\n");
}
//插入排序
{
	int arr[5] = { 3, 1, 4, 2, 7 };
	int* p = arr;

	printf("\n插入排序前：");
	for (int i = 0; i < 5; i++)
		printf(" %d", p[i]);

	//插入排序
	ChaRu(p, 5);

	printf("\n插入排序后：");
	for (int i = 0; i < 5; i++)
		printf(" %d", p[i]);

	printf("\n");
}
//快速排序
{
	int arr[10] = { 4,3,6,1,8,0,3,2,5,7 };

	printf("\n快速排序前：");
	for (int i = 0; i < 10; i++)
		printf(" %d", arr[i]);
	printf("\n");
	//递归写法
	//插入排序(此处2、3参数是最小下标、最大下标)
	KuaiSu(arr, 0, 9);

	printf("\n递归：快速排序后：");
	for (int i = 0; i < 10; i++)
		printf(" %d", arr[i]);
	printf("\n");

	//栈的写法（方便对比理解）
	stack<int> st;			//stack 容器的对象声明（栈）
	KuaiSu1(st, arr, 0, 9);

	printf("\n栈：快速排序后：");
	for (int i = 0; i < 10; i++)
		printf(" %d", arr[i]);
	printf("\n");

	//队列的写法（对比理解）
	queue<int> qu;			//stack 容器的对象声明（栈）
	KuaiSu2(qu, arr, 0, 9);

	printf("\n队列：快速排序后：");
	for (int i = 0; i < 10; i++)
		printf(" %d", arr[i]);
	printf("\n");
}
//shell排序（希尔排序）
{
	int arr[10] = { 3,4,8,6,9,5,2,6,1,7 };

	printf("\n希尔排序前：");
	for (int i = 0; i < 10; i++)
		printf(" %d", arr[i]);
	printf("\n");
	//shell排序
	shell(arr, 10);

	printf("\n希尔排序后：");
	for (int i = 0; i < 10; i++)
		printf(" %d", arr[i]);
	printf("\n");
}


	system("pause>0");
	return 0;
}