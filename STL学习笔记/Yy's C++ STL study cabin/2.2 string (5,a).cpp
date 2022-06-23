#include <iostream>
using namespace std;


int main()
{
						//size_type转定义用MSDN能看到是size_t(unsignet int)类型的重命名
					   //string(size_type length, char ch);
	string stc(6, 'a');//第一个参数：字符的个数，第二个参数：字符（注意加字符符号：单引号）
	cout << stc << endl;//用6个a给对象初始化


	system("pause");
	return 0;
}