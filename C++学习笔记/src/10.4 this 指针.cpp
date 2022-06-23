#include <iostream>
using namespace std;

class CST
{
public:
	int a;

	//CST(int a)
	//{
	//	a = a;	//这样打印a的值，得到-858993460，不是我们想要的值
	//}			//原因是这样，在局部变量与外部变量重名时，局部中以局部变量为准，这样两个a就都是传递进来的参数了
				//对外部的a不起作用，没有对外部的a进行初始化

	CST(int a)		//this是对象创建的时候才有的
	{				//这样打印a的值，就能得到我们传递进来的15了
		this->a = a;//原因是this是当前对象的指针，所以能指出对象的成员，就把成员a与参数a给区分开了
	}

	void show()
	{
		cout << a << endl;
	}

	CST* getdx()//this是指向当前对象的指针，即是说，this装着当前对象的地址
	{		//this是类中所有函数的隐藏参数，即只能在函数中使用，因为是函数的参数，this不是成员
		return this;//返回当前对象的地址
	}
};

int main()
{
	CST st(15);
	st.show();
	CST* o = st.getdx();
	cout << o << endl;//打印对象地址

	CST st1(18);
	CST* p = st1.getdx();//把对象的地址装到p里
	p->show();//p就能当对象来访问成员
	cout << p << endl;

	return 0;
}