#include <iostream>
using namespace std;

class Cst
{
private:
	int ange;
	double high;
public:
	Cst():ange(16)
	{
		high = 165.22;
	}

	void show()
	{
		cout << ange << endl << high << endl;
	}
			//一般数据成员是受保护的，所以用友元
	friend istream& operator >> (istream& ist, Cst& sa);
};

istream& operator >> (istream& ist, Cst& sa)
{		//输入类型要和变量的类型对应上
	ist >> sa.ange >> sa.high; //可连续输入，输入时用空格或回车来间隔（C++自动的），注意输入顺序

				//输入的格式与变量格式不匹配时，错误的那一个会被修改成0
				//比如double我们输入字符串qew，就会变成0

	if (ist.fail())//这个函数当输入的格式与变量原本格式不匹配时，返回1，输入正确时返回0。
	{				//利用这个函数，只要错误输入1个，就全部恢复默认值（或者需要的变量和值）//书上的建议
		cout << "输入错误：fail！ 已恢复初始值。" << endl;

		sa.ange = 0;		//因为如果只是输入错误一个，只会把错误的一个变成0，那剩下输入正确的没修改，
							//在实际应用中可能导致运行错误
		sa.high = 0.00;		//所以利用fail函数来把所有值都恢复默认，这样就容易判断是否输入错误，且安全
	}

	return ist;
}


int main()
{
	Cst su;
	cin >> su;
	su.show();

	return 0;
}