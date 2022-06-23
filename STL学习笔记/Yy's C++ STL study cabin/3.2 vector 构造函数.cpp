#include <iostream>
#include <vector>
using namespace std;

void STLConstructors()
{
//容器初始化
	vector<int> vec1;								//无参数

	vector<int> vec2(7);							//7个元素给容器初始化，7个元素默认初始化为0

	vector<int> vec3(6, 'y');						//6个 'y'给容器初始化，容器元素int类型

	vector<char> vecc(6, 'y');						//6个 'y'给容器初始化，容器元素char类型

	vector<int> vec4(vec3);							//用一个对象给本对象初始化

	vector<int> vec5(vec3.begin() + 2, vec3.end());	//用迭代器给本对象初始化

	vector<char>::iterator ite1 = vecc.begin()+1;
	vector<char>::iterator ite2 = vecc.end();
	vector<char> vec6(ite1, ite2);					//用迭代器给本对象初始化

//容器内容输出，讲解
{
	//cout << vec1[0] << endl;					//崩溃了，无参数就没有内容，当然无法输出

	for (int i = 0; i < vec2.size(); i++)
	{
		cout << vec2[i] << ' ';						//发现7个元素默认初始化为0
	}
	cout << endl;

	for (int i = 0; i < vec3.size(); i++)
	{
		cout << vec3[i] << ' ';						//6个元素都是121，对应y的ASC码序号
	}												//因为此对象vector的容器数据类型是int
	cout << endl;

	for (int i = 0; i < vecc.size(); i++)
	{
		cout << vecc[i] << ' ';						//6个元素打印了字符y
	}												//因为此对象vector的容器数据类型是char
	cout << endl;

	for (int i = 0; i < vec4.size(); i++)
	{
		cout << vec4[i] << ' ';						//6个元素打印了字符y
	}												//因为此对象是拷贝构造了vec3
	cout << endl;

	for (int i = 0; i < vec5.size(); i++)
	{
		cout << vec5[i] << ' ';						//4个元素打印了121，对应y的ASC码序号
	}												//利用迭代器截取了vec3的一段类给本对象初始化
	cout << endl;									//vec3.begin() + 2 ~ vec3.end()
		
	for (int i = 0; i < vec6.size(); i++)
	{
		cout << vec6[i] << ' ';						//5个元素打印了y
	}												//利用迭代器截取了vecc的一段类给本对象初始化
	cout << endl;									//vecc.begin()+1~vecc.end();
}

//容器初始化的注意点
{
	//对象为参数时，两对象的容器数据类型必须要一致
	vector<char> vec7(6, 'o');

	vector<int> vec8(vec7.begin() + 2, vec7.end());	//在老师的演示里，vec7与vec8的容器数据类型必须一致
													//否则会报错
	for (int i = 0; i < vec8.size(); i++)
	{
		cout << vec8[i] << ' ';						//4个元素打印了111,'o'的ASC码
	}												
	cout << endl;


	//不要越界操作
	//cout << vec7[6] << endl;						//越界读取，程序崩溃了


	//string没有容器数据类型参数列表，比较特殊，以后我们学的其它容器都有这个参数列表。
	//string有很多下标运算符的函数，也是特殊的，其它容器大多数都是用迭代器，下标很少。
	//所有的容器像begin（）， end（）这些迭代器是通用的
	//还有capacity()， reserve这些成员函数也是通用的

}

}

int main()
{
	STLConstructors();



	system("pause");
	return 0;
}