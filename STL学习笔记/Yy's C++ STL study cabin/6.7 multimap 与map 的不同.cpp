#include <iostream>
#include <map>			//multimap��ͷ�ļ�Ҳ��map

using namespace std;

void STLmultmap()
{
	//��������
	{
	//����������map�Ķ�һ��
	}

	//��map������
	{
	//1.�����ֵ�ظ�
		typedef pair<int, char> in_pair;
		multimap<int, char> mmap;

		mmap.insert(in_pair(1, 'a'));
		mmap.insert(in_pair(1, 'b'));
		mmap.insert(in_pair(3, 'c'));
		mmap.insert(in_pair(3, 'c'));
		mmap.insert(in_pair(3, 'd'));
		mmap.insert(in_pair(5, 'e'));
		mmap.insert(in_pair(7, 'f'));
		mmap.insert(in_pair(7, 'f'));

		multimap<int, char>::iterator ite = mmap.begin();		//��������������Ԫ��
		for (ite; ite != mmap.end(); ite++)
		{
			cout << ite->first << ' ' << ite->second << endl;	//����������������ɼ��ɹ���ӡ�ظ�����
		}
		cout << "����Ϊ�������" << endl << endl;


	//2.����		count()
		//ǰ����map��count�������鿴Ԫ���Ƿ���ڣ�������ʵ������Ӧ���Ǽ������Ԫ���ڶ����г��ֵĴ���
		//��Ϊmap��ֵ�������ظ�������ֻ�ܷ���0��1������multimap�����ܷ�����ͬ��ֵ�ĸ�����
		cout << mmap.count(1) << endl;
		cout << mmap.count(3) << endl;
		cout << mmap.count(5) << endl;
		cout << mmap.count(7) << endl;
		cout << mmap.count(9) << endl;							//û�������ֵ�򷵻�0
		cout << "����Ϊcount����" << endl << endl;


	//3.find����		�ҵ�Ԫ�أ��򷵻ص�һ���ҵ���Ԫ�صĵ������������ظ��Ĳ��ֵ�����������
		//���û�ҵ�������mapһ��������βԪ�صĵ�����
		cout << mmap.find(1)->first << ' ' << mmap.find(1)->second << endl;		//���ַ��ص��ǵ�һ�����ֵļ�ֵΪ1��Ԫ�أ�����������1û��ӡ
		cout << mmap.find(3)->first << ' ' << mmap.find(3)->second << endl;
		cout << mmap.find(5)->first << ' ' << mmap.find(5)->second << endl;
		cout << mmap.find(7)->first << ' ' << mmap.find(7)->second << endl;
		//cout << mmap.find(9)->first << ' ' << mmap.find(9)->second << endl;	//�����ڵļ�ֵ����������ӡ
		if (mmap.find(9) == mmap.end())
		{
			cout << "�����ڵļ�ֵ��find����βԪ��mmap.end()" << endl;
		}
		cout << "����Ϊfind()����" << endl << endl;
	}
}

int main()
{
	STLmultmap();

	return 0;
}