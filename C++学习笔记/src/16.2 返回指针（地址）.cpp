#include <iostream>
using namespace std;

class Cst
{
private:
	int a,
		b,
		c;
	double d;
	float e;
	int Nerror;
public:
	Cst() :a(1), b(2)
	{
		c = 56;
		d = 165.556;
		e = 156.887f;
		Nerror = -1;
	}

	//void*是通用类型指针，可以装任何类型的地址
	void* operator [] (int n)//但返回引用更符合下标运算符的本质，指针还需要强转类型，加东西
	{							//所以老师不推荐写
		switch (n)
		{
		case 0:
			return &a;	//返回地址
		case 1:
			return &b;
		case 2:
			return &c;//现在的成员类型 》void*类型指针 》强转后的类型
		case 3:			//前后一定要对应上，否则数值就变化了
			return &d;
		case 4:
			return &e;
		}
		return &Nerror;//超限提示
	}

};

int main()
{
	Cst su;
	cout << su[1] << endl;//这样的话，返回的是一个地址
	cout << su[3] << endl;

	//cout << *su[1] << endl;// error C2100: 非法的间接寻址//无法直接用地址操作符来操作
	//系统不知道这个地址的数据类型是多少，现在是void* 的通用类型指针，

	//int l = sizeof(void);//无法输出void的大小，证明void没有确定的大小，
	int l = sizeof(void*);//void*是4字节大小
	cout << l << endl;

	cout << *(int*)su[1]	<< endl;//上面提到指针类型是void*，不知道具体类型无法对空间操作
	cout << *(double*)su[3] << endl;//我们通过强转指针类型就可以了

	*(int*)su[1] = 88;				//能进行读写操作
	cout << *(int*)su[1]	<< endl;	//但是比起引用的返回值，我们要写的东西就多了

	cout << *(double*)su[1] << endl;//注意：在对象内的类型要与类外调用强转后的类型对应上
					//否则就出错了，比如上面这条的值就变得不认识了

	return 0;
}