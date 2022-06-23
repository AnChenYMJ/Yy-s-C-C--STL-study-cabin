#include <iostream>
using namespace std;

class CStu
{
public:
	CStu()
	{
		cout << "构造函数" << endl;
	}

	~CStu()
	{
		cout << "析构函数" << endl;
	}

};

int main()
{
	//CStu st;//构造函数与析构函数都能自动调用

	//CStu* ft = new CStu;
	//delete ft;//new的对象空间只有delete释放时才会调用析构函数
	//free (ft);//free释放空间不会调用析构函数

	//CStu* rt = malloc (sizeof(CStu));//: 无法从“void *”转换为“CStu *”,因为malloc返回的地址是通用的地址
	CStu* rt = (CStu *)malloc(sizeof(CStu));//所以需要强转指针类型
	//delete rt;//可以发现，malloc的对象空间构建是不会触发构造函数的
				//用delete释放空间是可以触发析构函数的
	free (rt);	//用free释放空间不会触发析构函数

	system("pause");
	return 0;
}