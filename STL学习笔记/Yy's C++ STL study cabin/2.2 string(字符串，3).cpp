#include <iostream>
using namespace std;


int main()
{
	string stc("abcdefgijklmn", 6);//用字符串前6个字符给对象初始化
	cout << stc.c_str()+19 << endl;


	system("pause");
	return 0;
}