#include <iostream>
using namespace std;

int main()		//注意：新建主函数时，旧主函数体与函数都要注释掉，否则会报错
					报错时可能不是那个文件的错误，而是别的文件，我们双击报错能跳到错误位置
{
	char a;
	int b ;
	double c;

	//cout、cin是对象，不是关键字，也不是函数
	cout << "请输入：姓名缩写、年龄、身高" << endl;
	cin >> a >> b >> c;		//可以连续输入，比scanf更智能，会自动识别数据类型（scanf要手动输入类型%f）
	cout << a << ' ' << b << ' ' << c << endl;

	system("pause");
	return 0;
}