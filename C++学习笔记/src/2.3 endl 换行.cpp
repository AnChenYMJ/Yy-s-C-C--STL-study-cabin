#include <iostream>
using namespace std;

int main()
{
	cout << "Don't waver, you're strong! yy" << endl;//换行，并且清空 刷新缓冲区

	cout << "Keep going! Don't stop!\n";//C语言中的\n（换行）在C++中也是能够使用的，\n 算作一个字符

	/*
		二者的区别：	
		endl会多一步操作，就是在内存中显示到提示符时，会把缓冲区刷新，这样就能立马显示出来
		\n就没有这步操作，比如执行完这一句，就执行下一句了，在某些系统中，就会慢半拍显示
		但二者宏观上看作用是一样的换行
		不过endl多了一步操作，整体上效率会慢一些
	*/
	system("pause");
	return 0;
}