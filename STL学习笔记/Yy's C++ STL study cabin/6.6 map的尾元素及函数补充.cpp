#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

void STLmap()
{
	//βԪ�ص������˽�
	{
	typedef pair<int, char> in_pair;
	map<int, char> mp;

	mp.insert(in_pair(1, 'a'));
	mp.insert(in_pair(3, 'a'));
	mp.insert(in_pair(5, 'a'));
	mp.insert(in_pair(9, 'a'));
	mp.insert(in_pair(12, 'a'));

	//cout << mp.find(6)->first << endl;		//��ΪԪ���в�����6�����ֵ�������д�����
				//ע��==���ǵ��ڣ�=�Ǹ�ֵ
	if (mp.find(6) == mp.end())					//�ɹ���ӡ��֤����findû�ҵ���ӦԪ�أ��򷵻�βԪ�صĵ�����
	{
		cout << "findû�ж�ӦԪ�صĻ����򷵻�βԪ�أ���mp.end()" << endl << endl;
	}

	if (mp.find(6) == mp.find(12))				//û�д�ӡ����֤���˶�����βԪ��end�����������һ��Ԫ�أ��������һ��Ԫ�ص���һλ
	{
		cout << "findû�ж�ӦԪ�صĻ����򷵻�βԪ�أ���mp.end()" << endl << endl;
	}

	}
	
	//��������	//���ϽڿεĲ��䣨����Ҫ��
	{
		typedef pair<int, char> in_pair;
		map<int, char> mp;

		mp.insert(in_pair(1, 'a'));
		mp.insert(in_pair(3, 'a'));
		mp.insert(in_pair(5, 'a'));
		mp.insert(in_pair(9, 'a'));
		mp.insert(in_pair(12, 'a'));

		//1.lower_bound()
			//���ز�����λ�ã�����Ϊ��ֵkey�����û�������ֵ����᷵�ش�����������Ĵ��ڵļ�ֵ
			//����7�����������7�����ֵ���򷵻�9��������key <= ����ֵ
			//���������ã�1.ȷ������ڵ��Ƿ���ڡ�2.û������ڵ㣬������ڵ�Ӧ�ò����λ��
		cout << mp.lower_bound(7)->first << endl;		//�ɹ�����9��ע�⣬��Ϊ���ص��ǵ����������������м�ֵʵֵ������Ҫָ��first����second

		//2.upper_bound()
		//��lower_bound�Աȣ�key < ����ֵ		�����ش��ڲ����ļ�ֵ
		cout << mp.upper_bound(9)->first << endl;		//c�ɹ�����12

		//3.equal_range()
		//����һ������:�����ص�����������������ĳ�ԱҲ�ǵ�������������Ԫ�ص���������lower_bound()��upper_bound()�Ľ���������
		cout << mp.equal_range(9).first->first << ' ' << mp.equal_range(9).second->first << endl;
	}

}

int main()
{
	STLmap();

	return 0;
}