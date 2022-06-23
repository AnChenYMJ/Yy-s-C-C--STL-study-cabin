#include <iostream>
using namespace std;

struct STU
	{
		int i;
		float f;
	};

class Cstu
{
public:
	int a[6];
	STU sr;
	
	//Cstu() :a()//数组在类中初始化的方式一：不同的编译器可能会给数组不同的值
	//{
	//}

	/*Cstu()
	{			//数组在类中初始化的方式二：利用循环打印
		for (int i = 0; i < 6; i++)
		{
			a[i] = 0;
		}
	}*/

	Cstu()
	{			//数组在类中连续初始化的方式三：利用memset函数，
		memset(&a[0], 0, 24);//参数1：要修改的连续空间的首地址。参数2：要给每个空间赋的值
	}					 //参数3：这块连续空间的总大小（注意不要越界，否则会有很难找的问题）
	//注意：空间是连续申请的，当memset申请过多时，多出的部分可能就是结构体的空间，
	//结构体赋值显示，结构体被越界操作的部分就可能被memset赋值为其它数，所以申请内存时要十分小心

	

	/*Cstu(STU en) :sr(en)//结构体传递参数初始化
	{
		cout << sr.i << " " << sr.f << endl;
	}*/

	Cstu(STU& en) :sr(en)//引用结构体参数初始化
	{
		cout << sr.i << " " << sr.f << endl;
	}
	void show()
	{
		for (int i = 0; i < 6; i++)
		{
			cout << a[i] << endl;
		}
	}


};

int main()
{
	//Cstu st;
	//st.show();

	STU fg = {26, 165.22f};//结构体相互赋值
	STU yu = fg;
	cout << yu.i << " " << yu.f << endl;

	Cstu bo(fg);
	cout << bo.sr.i << " " << bo.sr.f << endl;

	//初始化的方式选择哪种都可以，不要被局限住
	system("pause");
	return 0;
}