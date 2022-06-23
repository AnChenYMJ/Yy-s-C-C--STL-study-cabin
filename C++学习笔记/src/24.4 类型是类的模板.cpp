#include <iostream>
using namespace std;

class SCC
{
public:
	int pou;
};

template <typename T, typename Y>
class Ctea
{
public:
	Ctea(SCC& v)		//传递参数为对象的引用
	{

	}
};


template <typename T, typename U>
class SXX
{
public:
	int pou;
};

template <typename T, typename Y>
class Cstu
{
public:
	Cstu(SXX<char, const char*>& v)		//传递参数为对象的引用
	{

	}
};

int main()
{
	SCC sc;		//这个类无模板
	Ctea<char, SCC> ta(sc);//传递参数为对象的引用

	SXX<char, const char*> sx;	//这个类有模板
	Cstu<const char*, SXX<char, const char*>> tsx(sx);
			//有模板时，只要出现类名SXX，就必须加上模板参数列表

			//<char, const char*>这种是真实的类型，而typename T这种不是真实的类型

	system("pause");
	return 0;
}