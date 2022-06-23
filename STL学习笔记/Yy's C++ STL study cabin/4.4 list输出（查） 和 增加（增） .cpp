#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

struct ok
{
	int a;
	double b;
	const char* c;

	ok(int i, double o, const char* l)				//�ṹ��������һ�֣�������д���캯�����ǽṹ��Ͳ����� = ����ʼ����
	{												//ֻ����ok(i, o, l) ������ʽ����ʼ��
		a = i;
		b = o;
		c = l;
	}
};

void show(ok o)
{
	cout << o.a << ' ' << o.b << ' ' << o.c << '\n';
}

void STLcoutadd()
{
//������飩
{
	//ȫ�����
	{
		//ѭ�����										//ʹ����д�ṹ�幹�캯����ʡ�����Ͳ���ÿ�ζ�����һ���ṹ�������
		//ok ok1 = { 27, 165, "keep going!" };			//��д�˽ṹ��Ĺ��캯��ʱ���Ͳ��������ֳ�ʼ����ʽ��
		list<ok> li1(4, ok(27, 165, "keep going!"));	//ֻ����ok(27, 165, "keep going!")������ʽ��ʼ��
		//list�ĵ�����ֻ���Լӣ�����+1 +2 ����ƫ��
		for (list<ok>::iterator ite = li1.begin(); ite != li1.end(); ite++)	//�ѵ�����������д��ѭ���ڣ�������ƣ���Ϊite�Լӱ仯��
		{
			cout << ite->a << ' ' << ite->b << ' ' << ite->c << '\n';		//������������ָ�룬ָ����ó�ԱҪ��->
		}
		cout << endl;

		//for_each���
		for_each(li1.begin(), li1.end(), show);
		cout << endl;
	}

	//�������
	{
		list<ok> li1(1, ok(28, 163, "nothing."));				//ʹ����д�ṹ�幹�캯����ʡ�����Ͳ���ÿ�ζ�����һ���ṹ�������
		li1.push_back(ok(15, 155, "child."));
		//���βԪ�� back()
		cout << li1.back().a << ' ' << li1.back().c << endl;	//��Ϊback���ص������ã���Ԫ���Ǳ�����������. ������->

		//���ͷԪ�� front����
		cout << li1.front().a << ' ' << li1.front().c << endl;	//���ͷԪ�صĳ�Ա
	}
}

//���
{
	list<ok> li2(2, ok(20, 165, "iedot"));
	for_each(li2.begin(), li2.end(), show);

	//ͷ��� push_front()			//��ӵ���һ��Ԫ��λ��	front������
	{
		li2.push_front(ok(9, 130, "so small"));
		for_each(li2.begin(), li2.end(), show);
	}

	//β��� push_back()				//��ӵ�ĩβԪ��
	{
		li2.push_back(ok(3, 50, "how?"));
		for_each(li2.begin(), li2.end(), show);
	}
	
	//�м���� insert()				//list��֧���±�����
	{
		list<ok>::iterator ite = li2.begin();
		ite++;											//��Ϊlist������+1 +2�����ĵ�ַƫ�ƣ�list��֧���±�����
		ite++;											//ֻ����++������λ�õ�ȷ��


		li2.insert(ite, ok(14, 154, "lovely"));			//1.�ڵ�����ָ��λ�����һ��Ԫ��
		for_each(li2.begin(), li2.end(), show);

		li2.insert(ite, 2, ok(30, 161, "have a girl friend."));
		for_each(li2.begin(), li2.end(), show);			//2.��ָ��λ�����num��ֵΪval��Ԫ��

		list<ok> li3(5, ok(40, 160, "along"));		
		li2.insert(--ite, ++li3.begin(), li3.end());	//3.��ָ��λ�������һ��������һ�Σ���list����������++�� ����--
		for_each(li2.begin(), li2.end(), show);

	}


}

}

int main()
{
	STLcoutadd();


	system("pause");
	return 0;
}