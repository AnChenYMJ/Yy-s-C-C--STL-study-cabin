#include <iostream>
#include <set>
#include <string>
#include <algorithm>

using namespace std;

//ע�⣺��ʱ�������һ�����飬�����滻����Ҫ���ع����INS�����ʼǱ���ctrl+F12

void show(string pt)
{
	cout << pt << endl;
}

void STLset()
{
//��飺
	//ͨ��ʵֵ��������map��multimap��ͬ����ֵ��
	//��ֵ��ʵֵ�϶�Ϊһ�ˣ���ֵ����ʵֵ��ֻ��һ����
	//�ص㣺��Ч����
	//�ײ�ṹ��ƽ�� ��������������������x = log2^N  ( N������������x�ǲ��Ҵ�����

	set<string> st;

	st.insert(string("abc"));
	st.insert(string("aba"));
	st.insert(string("abb"));
	st.insert(string("abg"));
	st.insert(string("abd"));

	set<string>::iterator ite = st.begin();

	for (ite; ite != st.end(); ite++)		//��ӡ�����Զ������ˣ���ͱ����漰���Ƚ�����������ˣ��������>С��<�����أ�
	{
		cout << *ite << endl;				//������ʦ��ʾ��ֱ������д�����ˣ�Ҫ���һ��ͷ�ļ�<string>
	}										//һ��˵����ʲôû�ҵ�����ͷ�ļ�δ���(ע��������⣬���鿴MSDN)
	cout << "�����Ǳ������" << endl << endl;

//����
	//û������									��map��ͬ
	//�õ�Ԫ�ظ���	size����						��map��ͬ
	//�õ�Ԫ������������˵�ж�Ԫ���Ƿ����	count()	��map��ͬ
	//�ж��Ƿ�Ϊ��	empty�����շ�1���ǿշ�0		��map��ͬ
	//ͷβ������		begin����	end����			��map��ͬ

//���
	//1.�������������
	//2.�㷨����for__each()ʵ�ֱ������

//����
	//����ɾ���ġ���								���˸ģ�������map��ͬ
	//��ʾɾ		erase����						����clear�����������Ԫ��
	st.erase(string("abg"));					//���Ǳ�׼д��
	st.erase("abb");							//������������������أ���װ��set�������ˣ���Ҳ�ǿ��е�

	ite = st.begin();
	for_each(ite, st.end(), show);
	cout << "�����ǣ�ɾ��ָ��Ԫ�غ�����for_each���" << endl << endl;

	st.clear();
	for_each(st.begin(), st.end(), show);
	cout << "clear()�������Ԫ�غ����" << endl << endl;

	//��			
	//��Ϊset�ļ�ֵ��ʵֵ��һ���ģ����߲������ң������޸��˼�ֵ��ʵֵ��������Ϊ��ֵ�޸Ķ��ı�����ṹ
	//���Բ�Ҫ�޸ģ���Ҫ�޸�ʵֵ������map��
}


int main()
{
	STLset();


	return 0;
}