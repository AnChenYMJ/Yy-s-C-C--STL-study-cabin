#include <iostream>
using namespace std;

int main()
{
	cout << "Don't waver,you are strong!" << ' ' << 25;//cout可以连续输出
	cout << 'y' << 56.54 << endl;	//cout对比C语言的printf，能自动识别数据再打印
	//cout不是关键字是个对象（后续会讲解）//比如printf要用%d 等来手动确认输出类型
									//但C++的cout就直接输出了
	int a = 26;
	char c = 'Y';
	float f = 256.23F;//“初始化”: 从“double”到“float”截断
					//因为浮点型默认为double，要想数据是float必须加上F的后缀

	cout << a		//cout能够换行写代码
		<< ' '
		<< c
		<< ' '
		<< f
		<< endl;

	system("pause");
	return 0;
}