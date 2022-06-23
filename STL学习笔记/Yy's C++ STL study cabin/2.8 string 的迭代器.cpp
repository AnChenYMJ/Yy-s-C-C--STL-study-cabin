#include <iostream>
using namespace std;

void Itrator()
{
	string str1("Keep going Yy! Don't be afraid. you're strong. Go the distance."+5);	//+5多申请了5个字符空间
	string str2("null");																//为下面测试迭代器失效准备

//迭代器的声明
{
	string::iterator ite;			//迭代器的声明
	int				 a	;			//类比普通变量，其实string::iterator是迭代器的类型而已，lie是变量名

	char*			 ch ;			//迭代器的作用(本质)就相当于指针，二者不过是形式上的不同，

	//vector::iterator lie;			//迭代器比起变量或指针就很容易切换对应的容器
									//而且迭代器就相当于通用类型的指针

	string::iterator lei;			//迭代器是连接容器与算法的器件（通道）
									//operator是运算符重载的关键字，iterator是迭代器的关键字
}
		
//迭代器的使用
{
	string::iterator ite;

	ite = str1.begin();								//begin()返回一个迭代器，指向字符串第一个元素

	const char* ca = str2.c_str();					//ca的作用与迭代器一样，都是指针，这一句的效果与上面的一样的，获取首元素地址

//通过迭代器ite遍历对象元素
{
	//for (size_t i = 0; i < str1.length(); i++)		//length()函数返回字符串的长度. 这个数字应该和size()返回的数字相同.
	//{
	//	cout << ite[i] ;
	//}

	//for (ite = str1.begin(); ite != str1.end(); ite++)//end()函数返回一个迭代器，指向字符串的末尾(最后一个字符的下一个位置).
	//{
	//	cout << *ite;
	//}

	//for (size_t i = 0; i < str1.length(); i++)	
	//{
	//	cout << *ite;
	//	ite++;
	//}
}
	
//通过迭代器进行指定元素的赋值
{
	//定向替换指定元素
	ite[12] = 'Y';					//下标为12的元素修改为 Y	

	cout << str1 << endl;


	//循环替换赋值
	/*for (ite = str1.begin(); ite != str1.end(); ite++)
	{
		*ite = 'o';
	}*/

	for (size_t i = 0; i < str1.size(); i++)
	{
		ite[i] = 'i';
	}

	cout << str1 << endl;
}

//迭代器的理解
{
	//迭代器：定义了一个指向string对象的元素指针
	//迭代器是要与算法进行链接的，适用于所有容器，即一个通用的指针类型，或者智能指针。
	//切换容器时就很方便，string::iterator ite; 切换string的类型就好了
}
}

//迭代器的失效	//容器申请新空间，导致迭代器失效	//笔试面试经常问
{
	string::iterator ite;
	ite = str1.begin();				//.begin()返回一个迭代器，指向字符串首元素

	//迭代器失效的情况
	//str1.append(" just go.");		//append 拼接，这里拼接了9个字符，超出了原本的空间大小，所以需要重新申请空间
	cout << str1 << endl;

									//迭代器失效：
	//ite[12] = 'Y';				//会发现运行结束时崩溃了，原因如下
	//cout << str1 << endl;			//迭代器相当于指针，指向字符串首元素，如果对象重新申请空间重建，首元素地址就会改变；
									//而此时迭代器指向的地址还是原来的地址没有更新，就会导致它是一个野指针，指向一个非法空间，
									//对非法空间越界操作了就会崩溃。


	//迭代器未失效的情况
	str1.append(5, 'o');			//原因是声明定义对象时多申请了5个空间，我们拼接5个字符时空间足够，不必重新申请空间
	cout << str1 << endl;			//没有重新申请空间，迭代器指向的地址没有变化，就不会失效

	ite[12] = 'Y';					
	cout << str1 << endl;

}

}

int main()
{
	Itrator();



	system("pause");
	return 0;
}