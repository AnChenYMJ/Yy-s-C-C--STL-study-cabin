#include <iostream>
using namespace std;


int main()//C++中也能使用malloc 和 free//但不能用于对象空间，能用于基本数据类型，所以一般不用
		//new delete能触发构造和析构，所以还是用
{	
	//申请单个空间：

	//int * 是申请空间返回的地址类型默认为int，现强转为int *再赋值给指针p
	//int* p = (int *)malloc(sizeof(int));//这是C语言的申请堆区空间

			//new如果失败会返回NULL就和malloc一样
	int* p = new int;//C++申请堆区空间的标准形式
	int* p1 = new int(996); //还能够给申请的控件初始化，这里初始化为996
	//会发现比起C语言，更加方便了，少了很多手动的东西

	*p = 26;	//写
	cout << *p << ' ' << *p1 << endl;//读

	delete p, p1;//C++的堆区空间释放 delete：删除
				//注意，申请的空间类型，与释放时的类型一定要对应上


	//申请数组空间：
	//int* o = malloc(sizeof(int) * 5);//C语言的申请数组空间

	int* o1 = new int[5];//C++没有给我们直接初始化申请的数组的方法
	memset(o1, 0, 5 * 4);//这个函数的三个参数：参数1：申请空间地址，参数2：需要初始化成的值
	//这个函数很重要		//参数3： 数组的字节大小
	//memset  memory:存储、记忆  set：设置，规定

	o1[0] = 26;
	o1[1] = 27;

	cout << o1[0] << ' ' << o1[1] << ' ' << o1[2] << ' ' << o1[3] << endl;

	delete[] o1; //注意，申请的空间类型，与释放时的类型一定要对应上
			//比如这里少了 [] 编译没有问题，但实际上空间未释放，会出现问题，所以我们要注意
	system("pause");
	return 0;
}