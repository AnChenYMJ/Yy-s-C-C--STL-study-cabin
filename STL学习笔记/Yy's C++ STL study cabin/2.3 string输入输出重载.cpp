#include <iostream>
using namespace std;


int main()					//string自带输入输出重载
{
	string stc("abcdefghijk");
	string stc1;

	cout << stc << endl;	//输出（重载）

	cout << stc1 << endl;
	cin >> stc1;			//输入（重载）
	cout << stc1 << endl;

	size_t i;
	for (i = 0; i < 8; i++);
	cout << i << endl;	//i 输出 8


	system("pause");
	return 0;
}