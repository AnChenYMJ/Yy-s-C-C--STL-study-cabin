#include <iostream>
using namespace std;

int main()				
{								//C语言中两个for循环不能定义同一个变量（VC++），VS编辑器好像可以	
	//int i = 5;				//C语言中for循环判断定义的变量作用域是循环所在的花括号里（如函数，主函数，更大的循环）
	for (int i = 5; i >= 0; i--)//C++中能把变量定义写在for循环判断中
	{							//且在判断中定义的变量是局部变量，作用域在这个循环中
		cout << i << endl;
	}

	cout << i << endl;//error： “i”: 未声明的标识符//证明了C++中for循环判断里定义的变量是局部变量

	for (int i = 5; i >= 0; i--)//就是说上面的循环中的变量i与这个循环中的变量i没有关系
	{							//是两个不同的局部变量
		cout << i << endl;
	}


	return 0;
}