#include <iostream>
using namespace std;
				
				//C语言中函数名是不可以一样的
void test(int a)//C++中，函数名相同，参数不同的函数叫做重载函数，这些函数是不同的
{
	cout << a << endl;
}

//void test(int a, int b = 27)//error C2668: “test”: 对重载函数的调用不明确
void test(int a, int b)//如果给参数默认值，就可能会导致上面的情况，调用不明确
{							
	cout << a << ' ' << b << endl;
}

void test(char c)
{
	cout << c << endl;
}



void show(int a)//函数重载使函数更灵活了，比如这里我们用show函数，输入什么类型数据都能打印
{
	cout << a << endl;
}

void show(char a)
{
	cout << a << endl;
}

void show(float a)
{
	cout << a << endl;
}


int main()
{
	test(26);//可以看到三个同名函数（函数重载）成功调用了
	test(26, 27);//重载函数会根据传递的参数，自动去找对应的函数
	test('Y');


	show(27);//可以见到，用同一个名字的函数，输入不同数据类型，都能打印，因为使用了函数重载
	show('h');//而在C语言中，就必须写三个不同名称的函数来实现了，所以说提高了函数灵活性
	show(165.45f);

	return 0;
}