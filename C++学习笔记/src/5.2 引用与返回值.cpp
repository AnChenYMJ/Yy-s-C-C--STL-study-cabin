#include <iostream>
using namespace std;

int& fun()//引用是C++非常重要的知识点
{
	int b = 27;
	return b;//返回局部变量或临时变量的地址: b
}			//因为局部变量出了他的作用域就算作是非法空间了，不代表原来的b的空间
			//所以不要用局部变量的引用作为返回值
int main()
{
	int& c = fun();//现在在操作非法空间
	cout << c << endl;//尽管能打印27，但实际上是非法操作
					//一个有问题的操作，在多个编译器下运行，如果结果都一样，就可能有相关标准规定

	//引用需要初始化，指针不用
	//引用初始化后就不能再关联其它空间了，而指针可以
	//引用是关联空间，给空间多一个入口，所以引用不占空间，而指针占空间
	//引用直接操作对应空间，效率更高。
	//引用更安全一些，指针能偏移，越界等操作
	//指针更加灵活

	//&的三种作用
	//1. 在声明引用时，表示这是个引用变量
	//2. 变量前加&，表示取地址
	//3. 按位操作中，&表示位与运算
	return 0;
}