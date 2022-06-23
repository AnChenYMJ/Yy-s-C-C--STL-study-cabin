#include <iostream>
using namespace std;

int main()//C语言中（）有void，C++是没有的
{
	//输出     //单行注释是C++的标准注释，但是多行注释/* */也是很支持的
	cout << "Keep going !~ yy!" << endl;//输出文字。endl是换行
#if 0	//#if 0		#endif 成对使用，就像if语句一样 为0时进入语句，不为0就不进入，就能当作注释用了
		//所以C和C++的代码语句是很灵活的，不要被局限住
	/*
	cout << "Keep going !~ yy!" << endl;
	cout << "Keep going !~ yy!" << endl;
	/*
	cout << "Keep going !~ yy!" << endl;//一个编程经验：当你写了很多行算法，发现其中一些能够进行优化
	cout << "Keep going !~ yy!" << endl;//此时就可以用多行注释包起来，不删掉，在下面再写优化的代码
	*/
	cout << "Keep going !~ yy!" << endl;
	*/   当多个多行注释包含时，会发现从第一个/* 开始  直到遇见第一个 */  多行注释就结束，后面的*/就没用了
#endif
	cout << "Keep going !~ yy!" << endl;
	system("pause");//这个函数的作用是卡住方便观察结果
	return 0;
}