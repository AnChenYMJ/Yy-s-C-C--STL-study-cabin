#include <iostream>
using namespace std;

void StrOut()
{
//对象的输出
	string stc("Don't be afraid! GO the distance!");
	cout << stc << endl;			//string类内有输出重载

//c_str()函数的原理					//有的编译器没有<<重载，所以用c_str要更通用一些
	cout << stc.c_str() << endl;	//c_str()是将字符串复制到另一个空间中，然后返回新空间的地址，所以这并不是原本的字符串空间

//string对象的下标运算				//指定输出字符串的一个字符
	cout << stc[12] << endl;		//对象是不能用下标运算符的，除非类内重载了下标运算符[]
									//当越界操作时，运行会崩溃报错，（人家写的好啊）

//at()函数	//at()函数返回一个引用，指向在index位置的字符
	cout << stc.at(12) << endl;

	//cout << stc.at(36) << endl;		//当index超出范围，即越界输出时，会有异常提示"out of range"错误
									//并抛出out_of_range异常
	try								//便可以放到try中处理异常
	{
		cout << stc.at(36) << endl;
	}
	//catch (...)					//不知道抛出的异常类型时，用...来代替
	//{
	//	cout << "at（）函数越界操作了！" << endl;
	//}
	catch(out_of_range& v)			//查手册知道异常的类型是out_of_range//用不用引用都可以，可以直接写out_of_range
	{
		cout << "at（）函数越界操作了！" << endl;
	}
}

int main()
{
	StrOut();						//指定输出的两种方式：str[]对象下标运算、at()返回指定字符的引用


	system("pause");
	return 0;
}