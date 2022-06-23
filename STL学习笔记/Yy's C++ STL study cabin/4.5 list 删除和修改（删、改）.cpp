#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

struct ok
{
	int	 a;
	char c;

	ok(int i, char r)
	{
		a = i;
		c = r;
	}

	//第一次没有给运算符重载函数后面加上const，报错了，报错提示如下，加上const后就正常了
	//，error C2678: 二进制“==”: 没有找到接受“const _Ty”类型的左操作数的运算符(或没有可接受的转换)
	bool operator== (const ok& o) const			//== 的运算符重载，返回值是bool类型的
	{											//类内重载，第一个参数是当前对象的this指针
		if (o.a == this->a && o.c == this->c)
			return true;
		else
			return false;
	}
};

void show(ok o)
{
	cout << o.a << ' ' << o.c << endl;
}

//删、改
void STLdeletechange()
{
	list<ok> li1;
	li1.push_front(ok(30, 'a'));
	li1.push_front(ok(29, 'f'));
	li1.push_front(ok(28, 'e'));
	li1.push_front(ok(27, 'g'));
	li1.push_front(ok(26, 'n'));

	for_each(li1.begin(), li1.end(), show);
	cout << '\n';

	list<ok> li2(li1);
	list<ok> li3(li2);
	list<ok> li4(li3);
	list<ok> li5(li1);
	list<ok> li6(li1);
	li6.push_front(ok(27, 'g'));
	li6.push_front(ok(27, 'g'));
	li6.push_front(ok(27, 'g'));
	li6.push_front(ok(26, 'n'));

//删除
{
	//1.头删除	pop_front
	{
		li1.pop_front();						//删除第一个元素
		for_each(li1.begin(), li1.end(), show);
		cout << '\n';
	}

	//2.尾删除	pop_back
	{
		li1.pop_back();							//删除末尾元素
		for_each(li1.begin(), li1.end(), show);
		cout << '\n';
	}

	//3.删除指定元素	erase
	{
		list<ok>::iterator ite = li2.begin();

		//删除一个
		li2.erase(ite);
		li2.erase(--li2.end());
		//li2.erase(ite);							//加上这行就崩溃了，我估计是迭代器失效，因为空间发生了变化
		list<ok>::iterator ite1 = li2.begin();		//重新定义迭代器
		ite1++;
		li2.erase(ite1);
		for_each(li2.begin(), li2.end(), show);
		cout << '\n';

		//删除一段
		list<ok>::iterator ite3 = li3.begin();
		ite3++;
		li3.erase(ite3, --li3.end());				//迭代器 ++ -- 是支持的，不支持+ - 地址偏移
													//因为list是双向链表，所以支持--，
		for_each(li3.begin(), li3.end(), show);		//end()是指向末尾元素的下一位，--end 就刚好指向末尾元素
		cout << '\n';								//end()-- 为先取值再计算，所以不要用
	}

	//4.全部删除 clear()
	{
		for_each(li4.begin(), li4.end(), show);
		cout << '\n';

		li4.clear();							//删除所有元素

		for_each(li4.begin(), li4.end(), show);
		cout << '\n';
	}

	//5.删除与参数相同的元素 remove()  （重要）
	{
		for_each(li5.begin(), li5.end(), show);
		cout << '\n';

		li5.remove(ok(28, 'e'));				//要先判断元素结构体与参数结构体是否相同，进行 == 判断
												//而结构体的 == 对比，必须要写运算符重载，我的VS2019，必须给函数加上const，否则报错
		for_each(li5.begin(), li5.end(), show);
		cout << '\n';
	}

	//6.删除重复的元素 unique	  （重要）			//删除的是连续的重复元素多余的，不连续就不会删除
	{


		for_each(li6.begin(), li6.end(), show);
		cout << '\n';

		li6.unique();							//删除的是连续的重复元素多余的，不连续就不会删除

		for_each(li6.begin(), li6.end(), show);
		cout << '\n';

	}
}

//修改
{
	//1.迭代器修改

	//2.赋值函数修改 assign
	{
		for_each(li6.begin(), li6.end(), show);
		cout << '\n';

		li6.assign(5, ok(28, 'f'));				//1.用num个值为val的元素给本对象赋值

		for_each(li6.begin(), li6.end(), show);
		cout << '\n';

		li6.assign(li1.begin(), li1.end());		//2.用另一个向量的一段来给本对象赋值

		for_each(li6.begin(), li6.end(), show);
		cout << '\n';
	}

	//3.赋值运算符赋值 =
	{
		li6 = li3;

		for_each(li6.begin(), li6.end(), show);
		cout << '\n';
	}

}
}

int main()
{
	STLdeletechange();


	system("pause");
	return 0;
}