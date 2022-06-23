#include <iostream>
using namespace std;

//string 属性				//属性笔试、面试常考，尤其是容量。//而具体的操作函数是不考的
void attribute()			//attribute: 属性
{
//申请对象空间
	string str;											//空字符 初始化对象

	string str1("Keep going! Go the distance. Yy.");	//字符串 初始化对象

	string str2(6, 'o');								//6 个 o 初始化对象

	string str3("Don't waver.", 4);						//字符串前 4个 字符初始化对象

	string str4("you are strong! just go.", 7, 17);		//字符串下标 7 开始往后 17个 字符给对象初始化

	string str5(str1);									//对象给本对象初始化


//capakity() 查看容量大小			//capakity：容量
{
	//打印容量大小
	cout << str.capacity()	<< endl;		//15	
	cout << str1.capacity() << endl;		//47
	cout << str2.capacity() << endl;		//15
	cout << str3.capacity() << endl;		//15
	cout << str4.capacity() << endl;		//31
	cout << str5.capacity() << endl;		//47
}

//容量相关概念：
{
	//容量就是对象的字符串空间大小。
	//不同的容器容量也是不同的。
	//容量根据编译器的不同，容量的变化规律也会不一样。
	//VS2005 VS2019 string容器至少15容量，溢出则按16大小为单位增加。
	//VC6.0 至少31空间，溢出则每次增加32个字符空间。
	//上诉是为了能预留一些空间，避免小改动而重新申请空间。
	//这样做提高了很多效率
}

//容量规律变化的意义
{
	//假设没有规律：
	//对象如果出现拼接，插入等操作，字符数改变，空间大小变化。
	//这时原本空间不够装，就会重新申请空间，再把变化后的内容赋值到新空间里。
	//这样的话，只要比原来空间哪怕溢出一个字符，都要重新申请空间。
	//这会极大的影响效率。

	//有了规律：
	//如str，尽管没有字符数，但依然有15的初始容量。
	//此时str的字符数就能在15字符数的范围内随意改变，而不会重新申请空间。
	//只有当溢出初始容量时，按照一定容量大小固定增加空间。
	//这样的话，就极大的提高了运行效率，避免很多修改字符引起的重新申请空间。
	//这种容量预留空间是一种编程思想。

	//注意点：
	//VS2005 与 VS2019 string 初始容量为15，溢出按16大小为单位增加：15 -> 31 -> 47 -> 63 ->...
	//VC6.0 初始容量为31，溢出按32大小为单位增加：31 -> 63 -> 95 ->...
	//VS中因为与win10 不太兼容，必须先编译，再运行，否则容易出错。
	//VS编译器中刚好15个字符是不会溢出的，到了16就会溢出。
	//面试时，尽量表达自己动手能力强，有测试过，面试官喜欢动手能力强的。
	
}

//reserve() 改变容量大小			//只能变大，不能变小。
{
	str.reserve(5);						//变小，不成功
	cout << str.capacity() << endl;

	str.reserve(16);					//变大，成功
	cout << str.capacity() << endl;		//溢出初始的15容量后，按规律增加16，容量变成了31
}

//longth() 字符串长度	size()字符数		//二者在数值上相等
{
	//longth	字符串长度
	cout << str1.length() << endl;		

	//size		字符数
	cout << str1.size()	  << endl;

	//二者的存在 可能是为了实现细分的功能而存在，为了使逻辑、结构更完整严谨。
}

//resize()	重新设置字符个数		//容量不变
{
	//使字符数变大溢出原容量
	str2.resize(16);

	cout << str2.size()	    << endl;		//16
	cout << str2.length()   << endl;		//16
	cout << str2.capacity() << endl;		//31
	//发现字符数变高后，容量变大了，看来溢出后会使容量增大。

	//使字符数变小
	str2.resize(4);

	cout << str2.size()		<< endl;		//4
	cout << str2.length()	<< endl;		//4
	cout << str2.capacity() << endl;		//31
	//发现字符数变小以后，容量并没有变小，看来在容量范围内不会改变容量大小。

	cout << str2 << endl;					//打印了4个o（原本6个），说明字符数真的被修改了
}

}

int main()
{
	attribute();


	system("pause");
	return 0;
}