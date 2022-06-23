#include <iostream>
#include <map>
#include <algorithm>		//算法的头文件
using namespace std;

//error：无法将参数 1 从“std::pair<const int,char>”转换为“std::pair<int,char> &”
void show(pair<int, char> pa)		//这里的参数不可以是引用，否则会有上述报错
{
	cout << pa.first << ' ' << pa.second << endl;	//键值是该结构体的first，实值是该结构体的second
}

void STLmap()
{
//构造函数
{
//无参构造					//无参的话什么都没有
	map<int, char> mp;		//因为<Ky | 实> 键值对有两个数据，所以我们要写两个类型
							//容器是用键值来进行比较排序查找的，所以键值一般写成int或char类型
							//实值就可以是任意类型，如容器，结构体，对象，元素啥的

//一个参数 用另一个对象给本对象初始化

	map<int, char> mp3;							//可以利用typedef重命名
	typedef pair<int, char> in_pair;			//pair是编译器定义好的类型模板即map元素的类型
												//使用pair这个形式来插入
	mp3.insert(pair<int, char>(5, 'e'));
	mp3.insert(pair<int, char>(9, 'g'));		//会自动给键值排序，默认从小到大
	mp3.insert(pair<int, char>(7, 'f'));		//键值不能重复，键值冲突的话
	mp3.insert(pair<int, char>(3, 'e'));

	map<int, char> mp4(mp3);
	
	for_each(mp4.begin(), mp4.end(), show);		//for_each来遍历show函数输出
	cout << "以上是另一对象给本对象初始化" << '\n';

	//用MSDN找map，list这些，注意要带class的才是c++，点进去看最上面的是否是c++的

//两个参数 用另一个对象的一段给本对象初始化
	map<int, char>::iterator ite = mp4.begin();
	ite++;

	map<int, char> mp5(ite, --mp4.end());

	for_each(mp5.begin(), mp5.end(), show);
	cout << "以上是另一对象的一段给本对象初始化" << '\n';

}

//插入元素					//第1种用的最多，第23种用的少
{
	map<int, char> mp1;
	pair<map<int, char>::iterator, bool> pr;		//这是插入的返回值的类型，用来接住容器元素返回的true或false
													//MSDN第一个参数只给了iterator，所以我们要根据知识推导迭代器类型
	typedef pair<int, char> in_pair;				//重命名的话，就方便我们下面的书写了

	//插入一个元素			有返回值					//插入哪里返回哪里的迭代器
		mp1.insert(pair<int, char> (5, 'e'));		//因为map一个元素包含了两个元素：键值与实值，所以数据类型应该是一个结构体类型
													//C++给这种结构体定义了，叫做pair<> 注意：这个结构体的参数类型要与容器的参数类型一致
		mp1.insert(pair<int, char> (9, 'g'));		//会自动给键值排序，默认从小到大
		pr = mp1.insert(pair<int, char> (7, 'f'));	//用pr来接住返回值
		cout << pr.second << endl;					//1（true）//输出返回值
		pr = mp1.insert(pair<int, char> (7, 'l'));	//键值不可以重复，重复的无法打印，且second会返回一个false
		cout << pr.second << endl;					//0（false）
		pr = mp1.insert(pair<int, char>(3, 'e'));
		cout << pr.second << endl;					//1（true）实值可以重复

		for_each(mp1.begin(), mp1.end(), show);
		cout << '\n';
	

	//指定位置插入一个元素（pair）	有返回值
		map<int, char>::iterator mit = mp1.begin();	//map的迭代器与链表list的一样，不可以+1  +5这样地址偏移，只能++ --
		mit++; mit++; mit++; mit++;					//二叉树或其他树，本质就是链表，但是结构组成不一样
													//二叉树一个节点指向两个节点，多叉树则指向更多节点
		mp1.insert(mit, in_pair(1, 'j'));
		mp1.insert(--mit, in_pair(11, 'u'));		//可以观测到，尽管我们利用自加自减偏移了迭代器插入
			
		for_each(mp1.begin(), mp1.end(), show);		//但是插入后，还是按照键值大小自动排序了		
		cout << endl;								//不过注意不要越界，否则崩溃


	//插入另一个对象的一段	无返回值
		map<int, char> mp2;
		mp2.insert(in_pair(2, 'y'));
		mp2.insert(in_pair(4, 'Y'));
		mp2.insert(in_pair(6, 't'));
		mp2.insert(in_pair(0, 'Z'));

		mp1.insert(++mp2.begin(), --mp2.end());		//插入了mp2键值排序后的 2 4 ， 第2 3个pair
													//即mp2先排序，然后再按顺序插入进mp1
		for_each(mp1.begin(), mp1.end(), show);		
		cout << endl;

}

}

int main()
{
	STLmap();		//经验：MSDN查找容器或函数时，点开一定要看最上方是否是C++的
					//因为有可能是java 或者 FMC其它的库



	system("pause");
	return 0;
}