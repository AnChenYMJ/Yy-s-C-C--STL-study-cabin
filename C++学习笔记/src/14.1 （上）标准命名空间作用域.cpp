#include <iostream>

void fun();


int main()
{			
	{				//error C2065: “cout”: 未声明的标识符
		using namespace std;//若把标准命名空间写在局部，那么局部之外就不能使用它了
	}

	std::cout << "作用域不在这" << std::endl;//不能使用cout 和 endl 只能通过std：：来调用


	fun();

	system("pause");
	return 0;
}

void fun()
{		
	std::cout << "作用域" << std::endl; //只能通过std：：来实现调用
}