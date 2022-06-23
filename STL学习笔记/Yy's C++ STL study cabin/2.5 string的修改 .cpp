#include <iostream>
using namespace std;

//输出
void StrOut()
{
//对象的输出：<< 重载
	string stc("Don't be afraid! GO the distance!");
	cout << stc << endl;			//string类内有输出重载

//对象的输出：c_str()函数的原理					//有的编译器没有<<重载，所以用c_str要更通用一些
	cout << stc.c_str() << endl;	//c_str()是将字符串复制到另一个空间中，然后返回新空间的地址，所以这并不是原本的字符串空间


//string对象的下标运算				//指定输出字符串的一个字符
	cout << stc[12] << endl;		//对象是不能用下标运算符的，除非类内重载了下标运算符[]
									//当越界操作时，运行会崩溃报错，（人家写的好啊）

//at()函数	//at()函数返回一个引用，指向在index位置的字符
	cout << stc.at(12) << endl;
									
	try								//当index超出范围，即越界输出时，会有异常提示"out of range"错误
	{
		cout << stc.at(36) << endl;	// 并抛出out_of_range异常
	}
	catch (out_of_range)			//查手册知道异常的类型是out_of_range//用不用引用都可以，可以直接写out_of_range
	{
		cout << "at（）函数越界操作了！" << endl;
	}
	
}

//修改
void Strchange()
{
	string go("Don't be afraid! Yy. Go the distance.");
	string yes("You are strong!");

//修改指定元素
{
	//[]下标运算修改
	go[18] = 'Y';
	cout << go << endl;

	//at()修改					//at():返回指定位置的引用
	go.at(18) = 'y';
	cout << go.c_str() << endl;	//c_str()是将原字符串空间复制到一个新空间中，再返回新空间的地址
}

//insert中间插入字符				//（从0开始计数）			//insert: 插		（哇哦）
{
	//中间插入对象
	go.insert(20, yes);			//在第20个字符（index）的前面开始插入（从0开始计数）
	cout << go << endl;

	//index位置前面插入一个字符串
	go.insert(20, "is't be OK. ");
	cout << go << endl;			//在第20个字符的前面插入一个字符串（从0开始计数）

	//index1位置前面插入另一个对象的某一段字符串
	go.insert(47, yes, 8, 15);	//在第47个字符前面，插入另一个对象的第8个字符~14字符（第15字符的前面）（从0开始计数）
	cout << go << endl;

	//index位置前面插入字符串的前几个字符		
	go.insert(55, "Don't be afraid! ", 17);
	cout << go << endl;			//第55个字符前（从0开始计数）插入字符串的前17个字符

	//index位置前面插入num个ch
	go.insert(55, 6, 'a');
	cout << go << endl;

	//insert实现尾部插入			//类推能实现头部插入，拼接等
	go.insert(go.length(), 6, 'a');//length()返回字符串长度
	cout << go << endl;			//在尾部插入了6个a
}

//尾巴插入 +=拼接  与  append拼接
{
	string go("Don't be afraid! Yy. Go the distance.");
	string yes("You are strong!");

	//+= 拼接
	go += yes;			//拼接对象
	go += "keep going.";//拼接字符串
	cout << go << endl;


	//append拼接
		//尾巴拼接一个对象
	go.append(yes);
	cout << go << endl;

	//尾巴拼接一个字符串
	go.append(" Don't be worry.");
	cout << go << endl;

	//尾巴拼接一个对象的某一段
	go.append(yes, 8, 15);
	cout << go << endl;

	//尾巴拼接字符串前几个
	go.append("keep going! Yy.", 11);
	cout << go << endl;

	//尾巴拼接num个ch
	yes.append(5, 'h');
	cout << yes << endl;
}


//重新赋值 =赋值  与  >>输入赋值  与  assign赋值
{
	string go("Don't be afraid! Yy. Go the distance.");
	string yes("You are strong!");

// = 赋值
	go = yes;				//对象赋值
	cout << go << endl;
	go = "Don't be worry.";	//字符串赋值
	cout << go << endl;

//>>输入赋值
	/*cin >> go;
	cout << go << endl;*/

//assign赋值
	//对象赋值
	go.assign(yes);
	cout << go << endl;

	//字符串赋值
	go.assign("lie.");
	cout << go << endl;

	//对象某一段赋值
	go.assign(yes, 8, 15);
	cout << go << endl;

	//字符串前几个字符赋值
	go.assign("your are lie.", 12);
	cout << go << endl;

	//num个ch赋值
	go.assign(6, 'o');
	cout << go << endl;
}

//删除指定位置字符
{
	string go("Don't be afraid! Yy. Go the distance.");
	string yes("You are strong!");

	//删除指定位置，指定个数
	go.erase(17, 4);		//第17个字符后删除4个字符（从1开始）
	cout << go << endl;

	//删除所有内容
	go.erase(0, go.length());//第0个字符后，删除字符串长度的内容，相当于清空
	cout << go << endl;
}

}

int main()		//注：不同编译器之间只有源文件与头文件相通，若要移植，就挨个把头文件与源文件移植过去
{
	Strchange();//通过对比发现
				//insert 插入  或  append拼接  或  assign赋值
				//套路基本相同，即内容差不多如下：
				//1.对象之间
				//2.字符串
				//3.对象某一段
				//4.字符串前几个
				//5.num个ch



	system("pause");
	return 0;
}