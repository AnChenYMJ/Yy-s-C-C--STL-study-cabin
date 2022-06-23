#include <iostream>
#include <string>
#include <list>
#include <vector>
using namespace std;

void STLfalse()
{
	string st;
	st.resize(3);		//resize() 重新设置字符大小，如果在当前容量范围内，则不改变容量大小，
						//如果溢出，则会按照对应容器的容量增加规律变化，string初始容量至少15，此后按照16为单位增加
	cout << st.capacity() << endl;		//15
	st.resize(16);
	cout << st.capacity() << endl;		//31
	st.resize(32);
	cout << st.capacity() << endl;		//47
	st.resize(77);
	cout << st.capacity() << endl;		//79


	vector<int> ve;
	ve.resize(3);		//vector重新设置字符大小在当前容量内，则不改变容量大小，溢出则会按照1.5倍增加容量
						//注意，我的VS2019，当溢出的值超过变化一次后的容量，就不按规律了，设置字符多少，就多大容量
	cout << ve.capacity() << endl;		//3
	ve.resize(16);
	cout << ve.capacity() << endl;		//16		
	ve.resize(32);
	cout << ve.capacity() << endl;		//32		//16增加一次是24，但设置的超过了增加一次的结果，所以设置成32容量就是32
	ve.resize(77);
	cout << ve.capacity() << endl;		//77		//同理，超过了32增加一次的结果48，设置成77，容量就变为77
	ve.resize(80);
	cout << ve.capacity() << endl;		//115		//没有超出77变化一次的结果，所以按照1.5倍增加，变成77+77/2 ==115


	list<int> li;
	li.resize(4);								//设置成多少字符就多大字符空间
	cout << li.size() << endl;		//4			//list没有capacity，也看不了容量，只能用size来代替
	li.resize(16);
	cout << li.size() << endl;		//16		
	li.resize(32);
	cout << li.size() << endl;		//32	
	li.resize(77);
	cout << li.size() << endl;		//77	
	li.resize(80);
	cout << li.size() << endl;		//80
	
	for (list<int>::iterator ite = li.begin(); ite !=li.end(); ite++)
	{
		cout << *ite << endl;		//可以看见，没有初始化时，默认初始化成0
	}
}

int main()
{
	STLfalse();


	system("pause");
	return 0;
}