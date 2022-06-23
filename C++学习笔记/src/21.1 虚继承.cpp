#include <iostream>
using namespace std;

class CA	//这种虚继承的父类叫做：虚基类
{
public:
	int o;
	CA() : o(5)
	{}
};

class CB : virtual public CA	//CB虚继承CA
{
public:
};

class CC : virtual public CA	//CC虚继承CA
{
public:
};

class CD : public CB , public CC//CD继承CB与CC
{
public:
};


class B : public CA	//实继承示例
{
public:
};

class C : public CA
{
public:
};

class D : public B, public C
{
public:
};
int main()//虚继承是为了解决多继承中访问不明确的问题
{			//一般不建议用，结构复杂，内存开销大
			//虚继承是多重继承中特有的概念，虚拟基类是为了解决多重继承而出现的

			//多重继承可以很复杂，像连线图一样，想连哪就连哪

	CD d;	//CB CC 虚继承CA
	cout << d.o << endl;//因为虚继承就相当于有一个使用权限，而不是复刻下来，这样的话就只有CA里有一个o
	//虚继承就不会出现下面的情况，o也不属于CD，更不属于CB CC 只属于CA


	D n;	//B C 实继承CA
	cout << n.o << endl;//error C2385: 对“o”的访问不明确
	//因为B C 实继承CA ， 这样的B C 都有自己的o，n调用o时就不知道用哪个了
	//B C 都是把父类复刻下来到自己身上

	system("pause");
	return 0;
}