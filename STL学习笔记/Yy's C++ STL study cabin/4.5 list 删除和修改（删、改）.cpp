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

	//��һ��û�и���������غ����������const�������ˣ�������ʾ���£�����const���������
	//��error C2678: �����ơ�==��: û���ҵ����ܡ�const _Ty�����͵���������������(��û�пɽ��ܵ�ת��)
	bool operator== (const ok& o) const			//== ����������أ�����ֵ��bool���͵�
	{											//�������أ���һ�������ǵ�ǰ�����thisָ��
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

//ɾ����
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

//ɾ��
{
	//1.ͷɾ��	pop_front
	{
		li1.pop_front();						//ɾ����һ��Ԫ��
		for_each(li1.begin(), li1.end(), show);
		cout << '\n';
	}

	//2.βɾ��	pop_back
	{
		li1.pop_back();							//ɾ��ĩβԪ��
		for_each(li1.begin(), li1.end(), show);
		cout << '\n';
	}

	//3.ɾ��ָ��Ԫ��	erase
	{
		list<ok>::iterator ite = li2.begin();

		//ɾ��һ��
		li2.erase(ite);
		li2.erase(--li2.end());
		//li2.erase(ite);							//�������оͱ����ˣ��ҹ����ǵ�����ʧЧ����Ϊ�ռ䷢���˱仯
		list<ok>::iterator ite1 = li2.begin();		//���¶��������
		ite1++;
		li2.erase(ite1);
		for_each(li2.begin(), li2.end(), show);
		cout << '\n';

		//ɾ��һ��
		list<ok>::iterator ite3 = li3.begin();
		ite3++;
		li3.erase(ite3, --li3.end());				//������ ++ -- ��֧�ֵģ���֧��+ - ��ַƫ��
													//��Ϊlist��˫����������֧��--��
		for_each(li3.begin(), li3.end(), show);		//end()��ָ��ĩβԪ�ص���һλ��--end �͸պ�ָ��ĩβԪ��
		cout << '\n';								//end()-- Ϊ��ȡֵ�ټ��㣬���Բ�Ҫ��
	}

	//4.ȫ��ɾ�� clear()
	{
		for_each(li4.begin(), li4.end(), show);
		cout << '\n';

		li4.clear();							//ɾ������Ԫ��

		for_each(li4.begin(), li4.end(), show);
		cout << '\n';
	}

	//5.ɾ���������ͬ��Ԫ�� remove()  ����Ҫ��
	{
		for_each(li5.begin(), li5.end(), show);
		cout << '\n';

		li5.remove(ok(28, 'e'));				//Ҫ���ж�Ԫ�ؽṹ��������ṹ���Ƿ���ͬ������ == �ж�
												//���ṹ��� == �Աȣ�����Ҫд��������أ��ҵ�VS2019���������������const�����򱨴�
		for_each(li5.begin(), li5.end(), show);
		cout << '\n';
	}

	//6.ɾ���ظ���Ԫ�� unique	  ����Ҫ��			//ɾ�������������ظ�Ԫ�ض���ģ��������Ͳ���ɾ��
	{


		for_each(li6.begin(), li6.end(), show);
		cout << '\n';

		li6.unique();							//ɾ�������������ظ�Ԫ�ض���ģ��������Ͳ���ɾ��

		for_each(li6.begin(), li6.end(), show);
		cout << '\n';

	}
}

//�޸�
{
	//1.�������޸�

	//2.��ֵ�����޸� assign
	{
		for_each(li6.begin(), li6.end(), show);
		cout << '\n';

		li6.assign(5, ok(28, 'f'));				//1.��num��ֵΪval��Ԫ�ظ�������ֵ

		for_each(li6.begin(), li6.end(), show);
		cout << '\n';

		li6.assign(li1.begin(), li1.end());		//2.����һ��������һ������������ֵ

		for_each(li6.begin(), li6.end(), show);
		cout << '\n';
	}

	//3.��ֵ�������ֵ =
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