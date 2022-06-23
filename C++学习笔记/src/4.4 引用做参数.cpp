#include <iostream>
using namespace std;

void can1(int& a)//引用做参数
{
	a = 27;
	cout << a << endl;
}

void can2(int a)//变量做参数
{
	a = 28;
	cout << a << endl;
}

void can3(int* a)//指针做参数
{
	*a = 29;
	cout << *a << endl;
}

int main()
{
	int b = 26;
	can1(b);		//因为引用是将装数值的空间加了个入口，所以在函数里通过引用能改变控件的值
	cout << "can1后 b = " << b << endl;//函数内改变了变量b的值

	can2(b);		//函数2只是将b的值赋给函数2中的变量，所以不会改变b原来的值
	cout << "can2后 b = " << b << endl;//b的值在函数2内未改变

	can3(&b);		//函数3通过指针来传递参数，所以函数3内的指针指向b，因而能通过内存操作符修改b的空间
	cout << "can3后 b = " << b << endl;//b的值在函数3内被修改

	return 0;
}