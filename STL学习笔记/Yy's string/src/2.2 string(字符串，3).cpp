#include "2.2 Mystream.h"


//string(const char* str, size_t length)//字符串前length个字符给对象赋值
Mystring::Mystring(const char* str, size_t length)
{
	//if (length < 0 || str == NULL)
	//{
	//			//注意，一般来说，会有类似这样的一个不合法检测，当传递的参数超出我们的范围时，
	//			//给一个错误处理方式
	//}
	//申请空间
	m_str = new char[length + 1];//多一个来装\0

	//遍历赋值
	for (size_t i = 0; i < length; i++)//下标运算从0开始，length-1 就是刚好length的个数
	{
		m_str[i] = str[i];
	}

	//添加结尾\0
	m_str[length] = '\0';		//length在下标运算里就是最后一个字符空间

	nlength = length + 1;
}