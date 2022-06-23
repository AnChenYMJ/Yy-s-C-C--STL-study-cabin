#include <iostream>
#include <list>
#include <algorithm>
#include <forward_list>					//��������
using namespace std;

struct okea								//��Ϊ��ຯ����Ҫ�õ���������أ������ýṹ�嵱Ԫ�أ�����ѧϰ��
{
	int a;
	const char* c;

	okea(int i, const char* cc)
	{
		a = i;
		c = cc;
	}

	bool operator< (const okea& p) const		//����3.���� �� 4.�ϲ�
	{
		if (this->a < p.a)
			return true;
		else
			return false;
	}

	bool operator== (const okea& p) const		//����7.�㷨 �Ĳ��Һ��� find
	{
		if (this->a == p.a && this->c == p.c)
			return true;
		else
			return false;
	}
};

void show(okea o)
{
	cout << o.a << ' ' << o.c << '\n';
}

void STLother()
{	
	list<okea> li1;							
	li1.push_front(okea(5, "blurry"));		//blurry : ģ��
	li1.push_front(okea(6, "crying"));		//cry	 : ����
	li1.push_front(okea(7, "guilt"));		//guilt	 : ����
	li1.push_front(okea(8, "earnest"));		//earnest: ���棬����
	li1.push_front(okea(9, "consern"));		//consern: ���ģ�����
	li1.push_front(okea(10, "dirverse"));	//dirverse:���֣����ָ�����
	li1.push_front(okea(11, "desire"));		//desire : ����Ը��
	li1.push_front(okea(12, "dream and humiliation"));	//humiliation : ���裬 ���裬 ����

	list<okea> li2;
	li2.push_back(okea(27, "hope is on the way."));
	li2.push_back(okea(26, "Try to save"));
	li2.push_back(okea(25, "vague"));		//vague : ģ��������
	li2.push_back(okea(24, "lost"));		//lost  : ��ʧ

//1.����	swap����
{
		list<okea> li3(li1);
		list<okea> li4(li2);

		for_each(li3.begin(), li3.end(), show);
		cout << '\n';
		for_each(li4.begin(), li4.end(), show);
		cout << '\n';

		li3.swap(li4);							//��������������

		for_each(li3.begin(), li3.end(), show);
		cout << '\n';
		for_each(li4.begin(), li4.end(), show);
		cout << '\n';
}

//2.Ԫ�ص���	reverse() 
{
	list<okea> li5(li1);

	for_each(li5.begin(), li5.end(), show);
	cout << '\n';
											//reverse ���� reserve listû��reserve���޸�������С��
	li5.reverse();							//�����Ƿ�ת���������򣬼���ǰ��ͷβ˳��ߵ�����

	for_each(li5.begin(), li5.end(), show);
	cout << '\n';


}

//3.����		sort����
{
	//�������
	list<okea> li6;
	li6.push_front(okea(12, "dream and humiliation"));	
	li6.push_front(okea(8, "earnest"));	
	li6.push_front(okea(11, "desire"));
	li6.push_front(okea(7, "guilt"));		
	li6.push_front(okea(6, "crying"));
	li6.push_front(okea(10, "dirverse"));	
	li6.push_front(okea(5, "blurry"));	
	li6.push_front(okea(9, "consern"));

	for_each(li6.begin(), li6.end(), show);
	cout << '\n';

	li6.sort();								//��Ϊ������Ҫ���бȽϣ�������Ҫ���� < �����(����ֻ������<��������У���������涨�İ�)
											//��ô���򣬾Ϳ��Լ���ô�Զ����ˣ�������д����ֻ�Ƚϵ�һ��Ԫ�أ���С��������
	for_each(li6.begin(), li6.end(), show);
	cout << '\n';

	//��Ҫ�ѵ�ǰ��˳�򷴹���
	//1.���������������غ����ڣ��л�< > ���ż��ɣ���ע�⣬���صķ���ֻ���� < ֻ���ڲ���ִ�бȽϿ��л�
	//2.����reverse����Ԫ�ص���������
	li6.reverse();

	for_each(li6.begin(), li6.end(), show);
	cout << '\n';
}

//4.�ϲ�		merge
{
	//ע�⣺1.�Զ����� 2.����С�ں� 3.���������������
	list<okea> li8(li2);
	list<okea> li7;
	li7.push_front(okea(12, "dream and humiliation"));
	li7.push_front(okea(8, "earnest"));
	li7.push_front(okea(11, "desire"));
	li7.push_front(okea(7, "guilt"));
	li7.push_front(okea(6, "crying"));
	li7.push_front(okea(10, "dirverse"));
	li7.push_front(okea(5, "blurry"));
	li7.push_front(okea(9, "consern"));

	for_each(li7.begin(), li7.end(), show);
	cout << '\n';

	//li7.merge(li2);							//�˴�li7���������У����Ժϲ��ͱ�����

	/*li7.sort();
	li7.merge(li2);*/							//�˴���Ϊ�����Ǵ�С���󣬶�li2�ǴӴ�С�������ֱ�����

	li7.sort();									//ʹli7��С��������
	//li7.reverse();								//ʹli7�Ӵ�С���򣬵����Ǳ����ˣ������ԭ��
	li8.reverse();								//ʹli8Ҳ��С������������û�б���
	li7.merge(li8);								//�ϲ��󣬲�����li8�ϲ�li7�����������Ǵ�С����
	
	for_each(li7.begin(), li7.end(), show);		//C3˵������д����ܾ��о��飬��Ȼ��������ԭ������֪����ô�þͺ���
	cout << '\n';
}

//5.ƴ��		splice
{
//1.�ڵ�����ָ��λ�ò�����һ����
	list<okea> li9(li1);
	list<okea> li10(li2);
	list<okea>::iterator ite = li9.begin();
	ite++; ite++; ite++;

	for_each(li9.begin(), li9.end(), show);
	cout << '\n';

	li9.splice(ite, li10);					//1.�ڵ�����ָ��λ�ò�����һ����

	/*for_each(li9.begin(), li9.end(), show);
	cout << '\n';*/


//2.�ڵ�����ָ��λ�ò�����һ�����ĳһ���ڵ�
	list<okea> li11(li2);

	li9.splice(++ite, li11, li11.begin());	//2.�ڵ�����ָ��λ�ò�����һ�����ĳһ���ڵ�

	for_each(li10.begin(), li10.end(), show);	//�˴�li10�������Ѿ�������ƴ�ӵ�li9�ˣ�����li10�Ѿ�����û��Ԫ��
	cout << '\n';								//���Բ�������10��ƴ�ӣ�����������Ǹ�10�����Ԫ��

	for_each(li9.begin(), li9.end(), show);	//�ᷢ�ֵ�����ָ���λ��Խ����֮ǰƴ�ӵ�li10������9����ƴ��ǰli9�ĵ��ĸ�Ԫ��λ��
	cout << '\n';

	for_each(li11.begin(), li11.end(), show);	//ƴ�Ӻ�li11�ĵ�һ��Ԫ�ر�����ƴ�ӵ�li9�ˣ����Դ�ʱli11ֻʣ3��Ԫ��
	cout << '\n';


//3.�ڵ�����ָ��λ��ƴ����һ�����һ��
	++ite; ++ite;
	list<okea>::iterator ite1 = li11.begin();
	//li9.splice(ite, li11, ++ite1, ++ite);		//�����ˣ���ѭ�Լ��Լ�������һ��������ظ�����
	li9.splice(ite, li11, ++ite1, li11.end());	//3.�ڵ�����ָ��λ��ƴ����һ�����һ��

	for_each(li9.begin(), li9.end(), show);	
	cout << '\n';

	for_each(li11.begin(), li11.end(), show);	
	cout << '\n';

}

//6.���������
{
	//1. == != <= >= < >	֮ǰ�γ��н���

	//2. = ��ֵ���������		֮ǰҲ����
}

//7.�㷨
{
	//1.����		sort	(ע�⣺list��sort�ǳ�Ա����)

	//2.����		for_each

	//���Һ���	find	(ͷ�� β�� ֵ)�ڷ�Χ�ڲ��ҵ���Ӧ��ֵ����᷵�����ֵ�ĵ�����		//��Ҫ==���������
	list<okea>::iterator ite2 = find(li1.begin(), li1.end(), okea(8, "earnest"));	//��ΪҪ���� == �Ƚϣ�������Ҫ���������
	//���ط�Χ���ҵ���ֵ�ĵ�������������ite2��ס

	cout << ite2->a << ' ' << ite2->c << endl;		//��ɵ�ˣ�һֱ��ite2.���ԣ��Բ�������ָ����ó�ԱҪ��->��������������ָ��


	//list<okea>::iterator ite3 = find(li1.begin(), li1.end(), okea(99, "bone"));		//bone: ��ͷ

	//cout << ite3->a << ' ' << ite3->c << endl;		//��Ϊli1��û������Ҫ�ҵ�ֵ��û�з��ص������������ٴ�ӡ�ͱ�����
}

//��������		forward_list
{
	forward_list<okea> fo1;
					//����list����forward_list����ǰ��������������
					//��VS2005��֧�֣�ֻ��VS2012����֧��
}
}

int main()
{
	STLother();		


	system("pause");
	return 0;
}