#include <iostream>
#include <string>
#include <list>
#include <vector>
using namespace std;

void STLfalse()
{
	string st;
	st.resize(3);		//resize() ���������ַ���С������ڵ�ǰ������Χ�ڣ��򲻸ı�������С��
						//����������ᰴ�ն�Ӧ�������������ӹ��ɱ仯��string��ʼ��������15���˺���16Ϊ��λ����
	cout << st.capacity() << endl;		//15
	st.resize(16);
	cout << st.capacity() << endl;		//31
	st.resize(32);
	cout << st.capacity() << endl;		//47
	st.resize(77);
	cout << st.capacity() << endl;		//79


	vector<int> ve;
	ve.resize(3);		//vector���������ַ���С�ڵ�ǰ�����ڣ��򲻸ı�������С�������ᰴ��1.5����������
						//ע�⣬�ҵ�VS2019���������ֵ�����仯һ�κ���������Ͳ��������ˣ������ַ����٣��Ͷ������
	cout << ve.capacity() << endl;		//3
	ve.resize(16);
	cout << ve.capacity() << endl;		//16		
	ve.resize(32);
	cout << ve.capacity() << endl;		//32		//16����һ����24�������õĳ���������һ�εĽ�����������ó�32��������32
	ve.resize(77);
	cout << ve.capacity() << endl;		//77		//ͬ��������32����һ�εĽ��48�����ó�77�������ͱ�Ϊ77
	ve.resize(80);
	cout << ve.capacity() << endl;		//115		//û�г���77�仯һ�εĽ�������԰���1.5�����ӣ����77+77/2 ==115


	list<int> li;
	li.resize(4);								//���óɶ����ַ��Ͷ���ַ��ռ�
	cout << li.size() << endl;		//4			//listû��capacity��Ҳ������������ֻ����size������
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
		cout << *ite << endl;		//���Կ�����û�г�ʼ��ʱ��Ĭ�ϳ�ʼ����0
	}
}

int main()
{
	STLfalse();


	system("pause");
	return 0;
}