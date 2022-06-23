#include <iostream>
#include <set>
#include <string>
#include <algorithm>

using namespace std;

//注意：有时候光标会变成一个方块，那是替换，想要换回光标则按INS键，笔记本则按ctrl+F12

void show(string pt)
{
	cout << pt << endl;
}

void STLset()
{
//简介：
	//通过实值来排序，与map和multimap不同（键值）
	//键值与实值合二为一了，键值就是实值，只有一个数
	//特点：高效访问
	//底层结构：平衡 排序二叉树（红黑树）：x = log2^N  ( N是数据总量，x是查找次数）

	set<string> st;

	st.insert(string("abc"));
	st.insert(string("aba"));
	st.insert(string("abb"));
	st.insert(string("abg"));
	st.insert(string("abd"));

	set<string>::iterator ite = st.begin();

	for (ite; ite != st.end(); ite++)		//打印出来自动排序了，这就必需涉及到比较运算符重载了（比如大于>小于<的重载）
	{
		cout << *ite << endl;				//课上老师演示的直接这样写出错了，要添加一个头文件<string>
	}										//一般说符号什么没找到就是头文件未添加(注意积累问题，长查看MSDN)
	cout << "以上是遍历输出" << endl << endl;

//属性
	//没有容量									与map相同
	//得到元素个数	size（）						与map相同
	//得到元素数量，或者说判断元素是否存在	count()	与map相同
	//判断是否为空	empty（）空返1，非空返0		与map相同
	//头尾迭代器		begin（）	end（）			与map相同

//输出
	//1.迭代器遍历输出
	//2.算法函数for__each()实现遍历输出

//操作
	//增、删、改、查								除了改，其它与map相同
	//演示删		erase（）						还有clear（）清空所有元素
	st.erase(string("abg"));					//这是标准写法
	st.erase("abb");							//这则利用了运算符重载（封装在set容器中了），也是可行的

	ite = st.begin();
	for_each(ite, st.end(), show);
	cout << "以上是：删除指定元素后利用for_each输出" << endl << endl;

	st.clear();
	for_each(st.begin(), st.end(), show);
	cout << "clear()清空所有元素后输出" << endl << endl;

	//改			
	//因为set的键值与实值是一样的，二者不分你我，所以修改了键值（实值），会因为键值修改而改变整体结构
	//所以不要修改，想要修改实值还是用map吧
}


int main()
{
	STLset();


	return 0;
}