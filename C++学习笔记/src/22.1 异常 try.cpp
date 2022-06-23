#include <iostream>
#include <cstdlib>	//cstdlib 是C++的标准头文件写法，对应C语言的stdlib.h
#include <stdio.h>	//C++也可以用C语言的.h头文件 ，C++的标准是cstdio
using namespace std;

void fun(int a)
{
	while (a < 10)
	{
		if (a == 8)		//怎么算异常，也是由人为来定义
		{
			throw a;	//遇到我们定义的异常时，抛出一个值给try的catch接住
		}
		if (a == 5)
		{
			throw 'a';
		}
		if (a == 6)		
		{
			throw 123.689;	
		}
		a++;
	}
}


class Cfather
{
public:
	int fj;
	Cfather():fj(2)
	{}
};

void fun1(Cfather& a)	//记住用引用或者指针，避免拷贝构造，重复释放
{
	while (a.fj < 10)
	{
		if (a.fj == 8)		
		{
			throw a;	//抛出对象
		}
		if (a.fj == 5)		
		{
			throw &a;	//抛出指针
		}
		a.fj++;
	}
}


int main()
{
	//int b;
	//cin >> b;
	//if (b == 1)	//这个异常中止，是人为定义的一种情况提示
	//{			
	//	abort();//当执行这个函数时，程序执行时就会异常报错，就像以前的程序崩溃的报错一样
	//}
		

	//try是一个异常处理的功能，对比abort，abort只是一个提示，没有处理
	try  //只写try的化；会有错误：上开始的“try”块没有 catch 处理程序
	{
		fun(1);		//异常抛出与异常处理，会在try内调用的函数上生效
	}
	catch(int c)	//异常处理	//throw的值传递到这里，进行异常处理
	{
		cout << c << endl;//怎么处理也是由人为来定义
	}
	catch (char b)	//异常处理	//throw的值传递到这里，进行异常处理
	{
		cout << b << endl;//怎么处理也是由人为来定义
		try		//try就和全局 局部变量一样有作用域，这个try只在这个catch内有效
		{
			fun(5 + 1);//异常处理中利用try再跳过那个异常值
		}
		catch (int c)
		{
			cout << c << endl;
		}
		catch(...)	//当返回值不确定时，就用三个点来接住
		{
			cout << "default" << endl;
		}
	}
	

	Cfather fa;

	try
	{
		fun1(fa);
	}
	catch (Cfather& c)	//使用引用或者指针，避免拷贝构造
	{
		cout << "引用" << endl;
	}
	catch (Cfather* c)
	{
		c->fj++;		//指针调用
		cout << "指针" << endl;
	}


	system("pause");
	return 0;
}