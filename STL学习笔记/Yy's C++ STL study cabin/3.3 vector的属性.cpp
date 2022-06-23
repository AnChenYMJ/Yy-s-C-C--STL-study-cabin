#include <iostream>
#include <vector>
using namespace std;

void STLCapacity()
{
	//定义容器对象
	vector<int> vec1;
	vector<int> vec2(7);
	vector<int> vec3(3);

//测试初始容量，与容量变化规律
{
	//打印初始容量大小
	cout << vec1.capacity() << endl;		//0		//没有参数就没有元素也没有空间
	cout << vec2.capacity() << endl;		//7
	cout << vec3.capacity() << endl;		//3
	//发现初始容量根据初始化的参数决定，初始化多少元素，就有多少空间，没有参数就没有空间。
	//与string的初始容量不一样。string初始容量至少15.


	//用下标操作容器元素
	{
		//cout << vec1[0] << endl;				//崩溃了，下标运算只针对存在的元素，不存在的元素操作会崩溃。

		vec2[3] = 88;
		cout << vec2[3] << endl;				//成功操作

		//cout << vec3[3] << endl;				//越界访问操作导致崩溃了
	}
	
	//push_back()在尾巴添加一个元素，增大容量，查看容量变化规律
	{
		vec1.push_back(1);						//push_back()添加值为val的元素到当前vector末尾，即只添加一个元素

		cout << vec1.capacity() << endl;		//1		//从0增加1个

		vec1.push_back(1);
		cout << vec1.capacity() << endl;		//2		//从1增加1个

		vec1.push_back(1);
		cout << vec1.capacity() << endl;		//3		//从2增加 2/2 == 1个

		vec1.push_back(1);
		cout << vec1.capacity() << endl;		//4		//从3增加 3/2 == 1个 

		vec1.push_back(1);
		cout << vec1.capacity() << endl;		//6		从4增加	  4/2 == 2个

		vec1.push_back(1);
		vec1.push_back(1);
		cout << vec1.capacity() << endl;		//9		//从6增加 6/2 == 3个

		vec1.push_back(1);
		vec1.push_back(100);//push_back（）在尾部添加一个值为100的元素
		vec1.push_back(1);
		cout << vec1.capacity() << endl;		//13	从9增加  9/2 == 4个

		//vector没有固定的初始空间，初始化多少，就多大空间。
		//由此可见，在VS2019与2005（老师视频）中，vector溢出容量时，增加的空间是当前容量值的一半
		//VC6.0中 容量溢出，增加值为当前值的2倍，5 -> 10 -> 20 - >40
		//VC在win8与win10里不太兼容，不能直接运行，必须先编译，否则会出现问题。在win7中倒是运行得很好

	}

	//reserve修改容量大小
	{
		vec2.reserve(6);
		cout << vec2.size()		<< endl;		//7
		cout << vec2.capacity() << endl;		//7

		vec2.reserve(8);
		cout << vec2.size()		<< endl;		//7
		cout << vec2.capacity() << endl;		//8		//vector的reserve（）的变化规律与string不一样

		vec2.reserve(15);
		cout << vec2.size()		<< endl;		//7
		cout << vec2.capacity() << endl;		//15	//vector的reserve是变成多少就是多少

		//由上测试可见，reserve（）只能将容量变大，不能变小。
		//且不会改变元素的个数。
		//vector的reserve是变成多少就是多少，不会有预留空间。
		//string是会有预留空间，溢出预留空间之后，按一定空间单位增加（VS为16）。

		//注意点：不同容器的变化规律是不一样的。
		//而且这些变化规律还是经常的考点。

	}

	//迭代器失效
	{
		vector<int>::iterator ite = vec3.begin();
		ite[1] = 99;
		cout << vec3[1] << endl;
		cout << vec3.capacity() << endl;	//3

		vec3.insert(ite+1, 56);				//此时插入了值为56的元素，重新申请了空间
		cout << vec3.capacity() << endl;	//4
		//cout << ite[1] << endl;			//迭代器失效引发异常（异常的话，我们可以处理也可以过滤掉）

		//重新申请空间时，指向原空间的迭代器就会失效
	}

	//resize改变元素个数
	{
		vec3.resize(2);
		cout << vec3.size() << ' ' << vec3.capacity() << endl;	//2 4

		vec3.resize(4);
		cout << vec3.size() << ' ' << vec3.capacity() << endl;	//4 4

		vec3.resize(7);
		cout << vec3.size() << ' ' << vec3.capacity() << endl;	//7 7	//参见5条说明

		vec3.resize(8); 
		cout << vec3.size() << ' ' << vec3.capacity() << endl;	//8 10

		vec3.resize(11);
		cout << vec3.size() << ' ' << vec3.capacity() << endl;	//11 15

		vec3.resize(25);
		cout << vec3.size() << ' ' << vec3.capacity() << endl;	//25 25	//参见5条说明

		//1.经过上面测试可观测到
		//2.改变元素大小不是改变容量大小，
		//3.在容量范围内，修改元素个数不会修改容量大小，
		//4.当元素个数溢出容量时，会按照vector的容量变化规律来变化，即增加当前容量值的一半.
		//5.但是溢出量超过一次的变化规律时，元素改变成多少，容量就变为多少，不会按照规律变化。
	}

	//empty（）查看是否有元素	//有元素返回0	无元素返回1
	{
		vector<int> vec4;				//无元素对象

		cout << vec3.empty() << endl;	//有元素返回0

		cout << vec4.empty() << endl;	//无元素返回1
	}
}
}

int main()
{
	STLCapacity();


	system("pause");
	return 0;
}