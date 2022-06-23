#include <iostream>
#include <algorithm>		//algorithm: 算法		for_each 、sort  的头文件
#include <functional>		//function:	 功能		伪函数greater	 的头文件
using namespace std;

int show(char ch)			//默认传递进来的参数类型是char
{							//有无返回值都可以
	cout << ch;
	return 1;
}

void testforeach()
{
	string str1("Don't be afraid. Keep going! Go the distance. Yy.");
	string str2("Don't waver.");			//waver: 动摇

//算法一：for_each 遍历	头文件是<algorithm>
{
	//参数1：开始下标		参数2：结尾下标	参数3：函数（这个函数是我们自定义的，就像for循环里的执行语句一样）
	for_each (str1.begin()+9, str1.end()-3, show);		//for_each就像是我们自己写的遍历打印for循环一样 
														//默认参数三的函数原型的参数类型是当前容器的元素类型
}

cout << endl;			//换行

//算法二：sort 排序		头文件是<algorithm>
{
	//两参数：头	与 尾		此时默认从小到大排序
	sort(str1.begin(), str1.end());		//根据容器元素类型，不同的类型都能排序，现在是按字符来排序
	cout << str1 << endl;

	//三参数：头 尾 伪函数	能从大到小排序				//<>中是参数类型，附：我换成了double也没问题居然
	sort(str1.begin(), str1.end(), greater<char>());	//greater的头文件是<functional>
	cout << str1 << endl;								//greater：更大
														//仿函数在普通函数中用不到，一般在STL中才用得到
}
}


int main()
{
	testforeach();



	system("pause");
	return 0;
}