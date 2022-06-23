#include <iostream>
using namespace std;

void change1(int& a1, int& b1)//利用引用做参数互换
{						//因为ab的入口关联了a1与b1，所以修改a1与b1就是修改了ab的空间
	int Temp = a1;
	a1 = b1;
	b1 = Temp;
}

void change2(int a1, int b1)
{
	int Temp = a1;
	a1 = b1;
	b1 = Temp;
}

void change3(int* a1, int* b1)//利用指针做参数互换
{							//因为指针能直接修改指向的空间，所以ab被修改了
	int Temp = *a1;
	*a1 = *b1;
	*b1 = Temp;
}

int main()
{
	int a = 27;
	int b = 26;
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << endl;

	change1(a, b);//发现值已经互换
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << endl;

	change2(a, b);//发现值并没有互换
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << endl;

	change3(&a, &b);//发现值已经互换
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << endl;

	return 0;
}