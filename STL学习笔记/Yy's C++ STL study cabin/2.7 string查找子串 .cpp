#include <iostream>
using namespace std;


//查找子串 、交换
void FindSwap()				//find:查找   swap：交换
{
	string str1("Keep going! Don't be afraid. Yy~ Go the distance!");
	string str2("Yy~");

//查找子字符串				//find()
{
	//全字符串内查找
		cout << "全字符串：" << endl;

	cout << str1.find(str2) << endl;		//在本对象中查找对象，如果找到，则返回对应的起始下标

	cout << str2.find(str1) << endl;		//如果没有找到，则返回4294967295，因为返回值是无符号ing
	cout << (int)str2.find(str1) << endl;	//强转返回值为int，就能看到是-1，说明找不到则返回-1

	cout << str1.find("Keep") << endl;		//在本对象中查找字符串。

	cout << str1.find('o') << endl;			//在本对象中查找字符，返回第一个出现字符的下标


	//指定位置查找
		cout << "指定位置查找：" << endl;

	cout << str1.find(str2, 12) << endl;		//在本对象第12字符以后查找对象
		
	cout << str2.find(str1, 3) << endl;			//在本对象第3字符以后查找对象
	cout << (int)str2.find(str1, 3) << endl;	//得到4294967295的原因是负数的存储形式与读取形式的原因

	cout << str1.find("Keep", 2) << endl;		//在本对象第2字符以后中查找字符串。

	cout << str1.find('o', 7) << endl;			//在本对象第7字符以后中查找字符
}

//返回子字符串				//substr()		substr:子字符串
{
	cout << str1.substr(1, 20) << endl;//下标为1的字符开始，返回20个字符。
}

//交换两对象内容				//swap()
{
	cout << "交换前：" << endl;
	cout << "str1:" << str1 << endl;
	cout << "str2:" << str2 << endl;

	str1.swap(str2);

	cout << "交换后" << endl;
	cout << "str1:" << str1 << endl;
	cout << "str2:" << str2 << endl;
}
	
//运算符重载  +号				//此前的课程里有讲过别的运算符
{
	cout << "相加后：" << (str1 + ' ' + str2) << endl;			//对象 + 字符 +对象
							//就是拼接起来	//但没有改变哪个的值，因为没有赋值符号出现
	cout << "相加后：" << (str1 + " you're strong!") << endl;	//对象 + 字符串
}

}

int main()
{
	FindSwap();


	system ("pause");
	return 0;
}