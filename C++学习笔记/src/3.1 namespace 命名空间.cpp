#include <iostream>
using namespace std;//这是打开std得命名空间，我们常用得cout cin对象都在std里，所以这里我们要打开
//命名空间

//using std::cout;//指定开放空间某一成员，不常用，注意是开放不是调用

//using namespace不能放在被调用的命名空间之前

namespace stu //命名空间里能放多个函数，成员函数与别的命名空间的函数名可以一样
			//但命名空间的名字不能相同 
{
	void stop()
	{
		cout << "Keep going! yy." << endl;
	}
}

;;;;//这样是不会出错的，分号是语句的结束，这样写就是一堆空语句，是符合逻辑的

namespace stu1
{
	void stop()
	{			//  :: 作用域运算符
		std::cout << "Don't waver,you're strong." << std::endl;
	}	//这样的写法没问题，很符合逻辑，cout与endl是std空间里的对象

}

using namespace stu;//命名空间的调用能在全局区调用，但注意不能在命名空间定义之前调用

int main()
{
	//using namespace stu;//先调用命名空间，//第一种调用方式
	stop(); //再调用空间里的函数 

	//using namespace stu1;
	//stop();//当两个命名空间内的函数同名，且两个空间都调用时，就不能以这种方式调用函数了

	stu1::stop();//这就是第二种调用方式，就能随意调用命名空间里的成员了
	stu ::stop();

	using stu::stop;//指定开放空间里的某一成员，注意不是调用，是开放，就是开放后就能调用这个成员了
					//这个不常用

	std::cout << "Keep going~" << std::endl;
	system("pause");
	return 0;
}