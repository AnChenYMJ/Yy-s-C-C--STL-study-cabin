#include <iostream>
#include <deque>
using namespace std;

void STLdeque()
{
//空间内存对比 deque vector list
{
	//vector空间结构：[                   ]		//连续的空间
	//特点：当内容溢出空间时，会重新申请空间，把内容复制到新空间。

	//list空间结构  ：[]-[]-[]-[]-[]-[]-[]-[]	//节点形式，不连续空间
	//特点：每个节点有指向下一个节点指针和上一节点指针，溢出时在尾部或头部添加新节点即可

	//deque空间结构： [     ]-[     ]-[     ]	//段连续空间
	//特点，把定量的一段连续空间像节点一样链接起来，就既有连续空间的特性，又有链表特性。溢出时在尾部添加新的一段定量连续空间。
	//C3说他查资料，每一段的空间数据量是512字节
}

//功能比较
{
	//vector
	//随机访问：效率高			//下标运算，连续的空间
	//随机插入/删除：效率低		//删除一个元素，位置后的所有元素都要向前移动一个单位，如果元素够多，那效率就很低
	//头添加：不支持；	尾添加：支持

	//list
	//随机访问：不支持
	//随机插入/删除：效率高		
	//头添加：支持；		尾添加：支持

	//deque
	//随机访问：效率不如vector	//下标运算与at（）需要进行堆跳转，因为定量空间之间不连续；迭代器结构复杂，因为也要进行跳转
	//随机插入/删除：效率不如list，比vector高	//删除一个元素，需要前移的那些元素，只限于所在的那段定量空间，所以
	//头添加：支持；		尾添加：支持
}

//选取使用
{
	//对随机访问要求高，选用vector。	访问量大的

	//对插入/删除频率高的，选用list。	

	//随机访问+头添加。选用deque。

	//如果又要随机访问，又要插入/删除效率高，这是不可能的
	//就看实际应用中，随机访问和插入/删除，哪个对自己更重要，做选取，都差不多不太重要就用deque
}

//函数对比	deque vector
{
	//对比vector
	//没有了capacity 和 reserve	（查看容量大小，和设置容量大小）
	//多了push_front 和 pop_front	(头添加 和 头删除)
	//其它函数一样
}

//函数演示
{
	deque<int> de;
	de.push_front(26);
	de.push_front(27);
	de.push_front(28);
	de.push_front(29);

	cout << *de.begin() << endl;
	cout << de[1] << endl;
	cout << de.at(2) << endl;

	deque<int>::iterator ite = de.begin();
	cout << *(ite + 3) << endl;
}
}

int main()
{
	STLdeque();


	system("pause");
	return 0;
}