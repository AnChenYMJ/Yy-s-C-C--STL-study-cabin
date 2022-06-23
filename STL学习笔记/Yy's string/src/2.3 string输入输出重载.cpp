#include "2.2 Mystream.h"


//输出重载
ostream& operator << (ostream& os, Mystring& str)		//因为声明在类外，所以不用加类名作用域
{
	os << str.c_str();
	return os;
}

//输入重载				//可以试一下写在类内能简写到什么程度
istream& operator >> (istream& is, Mystring& str)
{

//记录输入字符串
	char* n_str = new char[60];		//申请记录的空间
												//.gcount()是istream类中记录输入字符数的函数
	is >> n_str;

//确定字符数
	size_t num ;		//变量声明在循环内的话，就是局部变量了，除了循环就释放掉，就无法记录num的值
	for (num = 0; n_str[num] != '\0'; num++);

//释放对象空间
	delete[] str.m_str;

//申请空间
	str.m_str = new char[num + 1];		//确定字符数的步骤得到的是下标（从0开始），实际字符数要+1

//遍历赋值（实现覆盖对象原内容）
	size_t i;							//避免局部变量，方便下面字符个数改变时使用
	for ( i = 0; i <= num; i++)
	{
		str.m_str[i] = n_str[i];
	}

//TODO:字符个数改变
	str.nlength = i;					//此处不可使用.size（）,因为被const修饰的
										//如果没有nlength能用，就改变zise或用类似的取代（写一个设置字符数函数）

//返回is
	return is;
}