#include<iostream>
using namespace std;

class Cfather
{
public:
	double a;
};

class Cson:public Cfather
{
public:
	char b;
};

class Cother
{
public:
	int c;
};

int main()
{
	Cfather* p;
	Cson* s;
	Cother* o;

	//p = (Cson*)s;	//旧的强制类型转换，有两种，第一种C和C++通用，第二种C++特有
					//一种是上面的形式（type）value，第二种种是type（value）

		//类型转换运算符		//static_cast<type>(expression)
	p = static_cast<Cfather*>(s);//这是新式的类型转换，需要满足以下要求：
							//yepe和expression必须存在能相互隐式转换的关系，这才是合法的

	//o = static_cast<Cother*>(s);//Cother与Cson的类没有任何关系，无法隐式转换，所以会报错
						//error: 无法从“Cson *”转换为“Cother *”//不允许不相干转换

	o = (Cother*)s;//但是旧的强制类型转换就没有限制，强行转换
				//这样会存在一些问题，比如Cson继承了Cfather，它的空间有两个，自己的和父类的
				//两个空间的成员类型也不尽相同，强行合并转化成Cother，就会存在安全隐患，危险
				//所以新式的转换更安全，当然如果我们对内存排布什么的特别熟悉，用强制转换也没问题

	system("pause");
	return 0;
}