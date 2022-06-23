#include <iostream>
using namespace std;


int main()
{
	string stc("Keep going! Yy, Don't stop");
	cout << stc.c_str() << endl;

	string stc1(stc);
	cout << stc1.c_str() << endl;


	system("pause");
	return 0;
}