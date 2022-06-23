#include <iostream>
#include <map>
#include <algorithm>
#include <functional>	//�º���greater��ͷ�ļ� 

using namespace std;

//����
void STLmap1()
{
	
	//1.����
	//��listһ����map��û�������ĸ���ģ�������ǰ����ռ䣬���һ��Ԫ�ؾ����һ���ռ�

	typedef pair<int, char> in_pair;	//��������ʹ��pair<int, char>���򻯳� ��in_pair����ʹ��
	map<int, char> mp;					//����һ��map

	mp.insert(in_pair(5, 'o'));			//��map��ֵ������Ԫ�صķ�ʽ
	mp.insert(in_pair(1, 'g'));			
	mp.insert(in_pair(3, 'k'));
	mp.insert(in_pair(9, 't'));
	mp.insert(in_pair(7, 'u'));

	//2.�õ�Ԫ�ظ���	size()
	cout << mp.size() << endl;			//��ӡmp��Ԫ�ظ���
	cout << "�����ǵõ�Ԫ�ظ���" << endl << endl;

	//3.����ĳһ����ֵ�Ƿ����	count����
	cout << mp.count(3) << endl;		//���Ҽ�ֵΪ3��Ԫ���Ƿ���ڣ�����1 �� 0
	cout << mp.count(7) << endl;		//MultiMap���Ƿ��������ֵ���ֵĴ�������ΪMultiMap��ֵ���ظ���map��ֵ�����ظ�
	cout << mp.count(11) << endl;
	cout << "�����ǲ���ָ����ֵ�Ƿ���ڣ�����1��0" << endl << endl;
		
	//4.�ж�map�Ƿ�Ϊ��
	map<int, char> mp1;					//������map������
	cout << mp.empty() << endl;
	cout << mp1.empty() << endl;
	cout << "�������ж�map�Ƿ�Ϊ�գ�����1��0" << endl << endl;

	//5.ͷβ������ iterator
	map<int, char>::iterator ite = mp.begin();				//����һ������������ֵΪmp��β��

	for (ite; ite != mp.end(); ite++)
	{														//���������൱��ָ�룬ָ����ó�ԱҪ��->
		cout << ite->first << ' ' << ite->second << endl;	//������ӡmp��Ԫ�أ�map��Ϊ��ֵ��ʵֵ������Ҫ�ֱ��ӡ��firstΪ��ֵ��secondΪʵֵ
	}
	cout << "�����ǵ�����������ӡԪ��" << endl << endl;		//�ƺ����ܵ��Ŵ�ӡ��������

	

}

//����
void STLmap2()
{
	//��		���ַ�ʽ
	{
	typedef pair<int, char> in_pair;	//����pair<int, char>��������������ʹ��
	map<int, char> mp;					//����һ��map����


	//1.���ӵ���Ԫ��
	mp.insert(in_pair(3, 'f'));			//���ӵ���Ԫ��
	mp.insert(in_pair(7, 'r'));
	mp.insert(in_pair(1, 'y'));
	mp.insert(in_pair(5, 'o'));
	mp.insert(in_pair(9, 'i'));

	map<int, char>::iterator ite = mp.begin();				//����һ������������ֵΪmp����ʼλ
	for (ite; ite != mp.end(); ite++)
	{														
		cout << ite->first << ' ' << ite->second << endl;	//���õ�����������ӡ
	}
	cout << "������ֱ�Ӳ���һ��Ԫ��" << endl << endl;


	//2.ָ��λ�ò���һ��Ԫ�أ�pair��	�з���ֵ
	map<int, char> mp1;
	mp1.insert(in_pair(6, 'j'));

	map<int, char>::iterator ite1 = mp1.begin();			//����һ������������ֵΪmp1����ʼλ
	ite1++;													//������ƫ�ƣ�ʵ��ָ��λ��

	mp1.insert(in_pair(2, 'r'));							//ָ��λ�����Ԫ��
	mp1.insert(in_pair(4, 'p'));
				
	map<int, char>::iterator ite2 = mp1.begin();
	for (ite2; ite2 != mp1.end(); ite2++)
	{
		cout << ite2->first << ' ' << ite2->second << endl;	//���õ�����������ӡ
	}
	cout << "������ָ��λ�ò���һ��Ԫ��" << endl << endl;


	//3.������һ�����һ��
	map<int, char> mp3;

	mp3.insert(++mp.begin(), --mp.end());					//���õ�����ƫ��ʵ�ֲ�����һ�����һ��

	map<int, char>::iterator ite3 = mp3.begin();
	for (ite3; ite3 != mp3.end(); ite3++)
	{
		cout << ite3->first << ' ' << ite3->second << endl;	//���õ�����������ӡ
	}
	cout << "�����ǲ�����һ�����һ��" << endl << endl;

	}

	//��
	{
	//ע�⣺��--ֻ�ܸ�ʵֵ�����ܸļ�ֵ����Ϊ��ֵ�غ�����������Ľṹ����Ϊ�Ǻ����ɶ�ģ��ڵ㲻������䶯
	//�������ݽṹ�е�֪ʶ����ס��ֵ���˾ͻ��ƻ��ṹ������ֻ�ܸ�ʵֵ


		typedef pair<int, char> in_pair;	//��������ʹ��pair<int, char>���򻯳� ��in_pair����ʹ��
		map<int, char> mo;					//����һ��map

		mo.insert(in_pair(5, 'o'));			//��map��ֵ������Ԫ�صķ�ʽ
		mo.insert(in_pair(1, 'g'));
		mo.insert(in_pair(3, 'k'));
		mo.insert(in_pair(9, 't'));
		mo.insert(in_pair(7, 'u'));

map<int, char>::iterator ito = mo.begin();				//����һ������������ֵΪmp����ʼλ
for (ito; ito != mo.end(); ito++)
{
	cout << ito->first << ' ' << ito->second << endl;	//���õ�����������ӡ
}
cout << "�޸ĺ�" << endl;

mo.begin()->second = 'f';								//�޸�ʵֵ
//mo.end()->second	= 'f';								//���������б����ˣ������ԭ��
//++mo.begin()->second = 'f';							//������û���޸ĳɹ����ƺ���Ҫ����������Ȼ��ƫ��
ito = mo.begin();
ito++; ito++;											//������ƫ��
ito->second = 'f';

map<int, char>::iterator it = mo.begin();
for (it; it != mo.end(); it++)
{
	cout << it->first << ' ' << it->second << endl;	//���õ�����������ӡ
}
cout << "�������޸�ʵֵ" << endl << endl;
	}

	//��		�����������ѭ��������for_each�������������find��������������
	{
	typedef pair<int, char> in_pair;	//��������ʹ��pair<int, char>���򻯳� ��in_pair����ʹ��
	map<int, char> mo;					//����һ��map

	mo.insert(in_pair(5, 'o'));			//��map��ֵ������Ԫ�صķ�ʽ
	mo.insert(in_pair(1, 'g'));
	mo.insert(in_pair(3, 'k'));
	mo.insert(in_pair(9, 't'));
	mo.insert(in_pair(7, 'u'));

	map<int, char>::iterator ui = mo.find(9);		//ʹ��find�������Ҽ�ֵ��û���������غ�����ֻ������ʹ�ü�ֵ���ҵķ�ʽ
	cout << ui->first << ' ' << ui->second << endl;	//���õ�����������ӡ
	cout << "����Ϊ��ʹ��find�����������" << endl << endl;
	}

	//ɾ		���ַ�ʽ
	{
		typedef pair<int, char> in_pair;	//��������ʹ��pair<int, char>���򻯳� ��in_pair����ʹ��
		map<int, char> my;					//����һ��map

		my.insert(in_pair(5, 'o'));			//��map��ֵ������Ԫ�صķ�ʽ
		my.insert(in_pair(1, 'g'));
		my.insert(in_pair(3, 'k'));
		my.insert(in_pair(9, 't'));
		my.insert(in_pair(7, 'u'));

		map<int, char>::iterator ite1 = my.begin();				//����һ������������ֵΪmp����ʼλ
		for (ite1; ite1 != my.end(); ite1++)
		{
			cout << ite1->first << ' ' << ite1->second << endl;	//���õ�����������ӡ
		}
		cout << "����Ϊɾ��ǰ" << endl;

		//erase	���������
			//1.������ɾ��ָ��Ԫ��
		my.erase(my.begin());

		ite1 = my.begin();										//������ָ�����	
		for (ite1; ite1 != my.end(); ite1++)
		{
			cout << ite1->first << ' ' << ite1->second << endl;	//���õ�����������ӡ
		}
		cout << "����Ϊ��������ɾ��ָ��Ԫ��" << endl;

		//2.������ɾ��ָ��һ��
		ite1 = my.begin();
		ite1++;
		my.erase(ite1, my.end());								//ָ��ɾ��������ite1��my.end()�Ĳ���

		ite1 = my.begin();
		for (ite1; ite1 != my.end(); ite1++)
		{
			cout << ite1->first << ' ' << ite1->second << endl;	//���õ�����������ӡ
		}
		cout << "����Ϊ��������ɾ��ָ��һ��" << endl;


		//3.���ݼ�ֵ��ɾ�����Ԫ��
		my.insert(in_pair(2, 'p'));
		my.insert(in_pair(8, 'b'));

		my.erase(3);											//ɾ����ֵΪ3��Ԫ��

		ite1 = my.begin();
		for (ite1; ite1 != my.end(); ite1++)
		{
			cout << ite1->first << ' ' << ite1->second << endl;	//���õ�����������ӡ
		}
		cout << "����Ϊ�����ݼ�ֵ��ɾ�����Ԫ��" << endl;
	}



}

//��������
void STLmap3()
{
	//��	��	��find��������������
	{
		typedef pair<int, char> in_pair;	//��������ʹ��pair<int, char>���򻯳� ��in_pair����ʹ��
		map<int, char> mo;					//����һ��map

		mo.insert(in_pair(5, 'o'));			//��map��ֵ������Ԫ�صķ�ʽ
		mo.insert(in_pair(1, 'g'));
		mo.insert(in_pair(3, 'k'));
		mo.insert(in_pair(9, 't'));
		mo.insert(in_pair(7, 'u'));

		map<int, char>::iterator ui = mo.find(9);		//ʹ��find�������Ҽ�ֵ��û���������غ�����ֻ������ʹ�ü�ֵ���ҵķ�ʽ
		cout << ui->first << ' ' << ui->second << endl;	//���õ�����������ӡ
		cout << "����Ϊ��ʹ��find�����������" << endl << endl;
	}

	//���� swap����
	{
		//����֮ǰѧ��һ������������ͬԪ�����͵�������Ԫ��
	}

	//Ĭ������	����Ҫ
	{
		//mapһ���Ǵ�С���������
		//�ָ�Ϊ�Ӵ�С����
		typedef pair<int, char> in_pair;	
		map<int, char, greater<int>> mo;	//��һ���º���greater<int>	//ע������Ĳ��������ͣ������Ĳ�����ʵ�Σ�����߲�ͬ

		mo.insert(in_pair(5, 'o'));			//��map��ֵ������Ԫ�صķ�ʽ
		mo.insert(in_pair(1, 'g'));
		mo.insert(in_pair(3, 'k'));
		mo.insert(in_pair(9, 't'));
		mo.insert(in_pair(7, 'u'));

		map<int, char, greater<int>>::iterator ito = mo.begin();//������������Ҫ����������һ�£�����ҲҪ��greater<int>
		for (ito; ito != mo.end(); ito++)
		{
			cout << ito->first << ' ' << ito->second << endl;	//���õ�����������ӡ
		}
		cout << "����Ϊ���޸�Ĭ������Ӵ�С" << endl << endl;

	}
}

int main()
{
	//STLmap1();		//����

	//STLmap2();		//����

	STLmap3();			//��������

	return 0;

}