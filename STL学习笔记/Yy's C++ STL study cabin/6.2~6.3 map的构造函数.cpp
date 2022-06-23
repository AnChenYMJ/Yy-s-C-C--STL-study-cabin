#include <iostream>
#include <map>
#include <algorithm>		//�㷨��ͷ�ļ�
using namespace std;

//error���޷������� 1 �ӡ�std::pair<const int,char>��ת��Ϊ��std::pair<int,char> &��
void show(pair<int, char> pa)		//����Ĳ��������������ã����������������
{
	cout << pa.first << ' ' << pa.second << endl;	//��ֵ�Ǹýṹ���first��ʵֵ�Ǹýṹ���second
}

void STLmap()
{
//���캯��
{
//�޲ι���					//�޲εĻ�ʲô��û��
	map<int, char> mp;		//��Ϊ<Ky | ʵ> ��ֵ�����������ݣ���������Ҫд��������
							//�������ü�ֵ�����бȽ�������ҵģ����Լ�ֵһ��д��int��char����
							//ʵֵ�Ϳ������������ͣ����������ṹ�壬����Ԫ��ɶ��

//һ������ ����һ��������������ʼ��

	map<int, char> mp3;							//��������typedef������
	typedef pair<int, char> in_pair;			//pair�Ǳ���������õ�����ģ�弴mapԪ�ص�����
												//ʹ��pair�����ʽ������
	mp3.insert(pair<int, char>(5, 'e'));
	mp3.insert(pair<int, char>(9, 'g'));		//���Զ�����ֵ����Ĭ�ϴ�С����
	mp3.insert(pair<int, char>(7, 'f'));		//��ֵ�����ظ�����ֵ��ͻ�Ļ�
	mp3.insert(pair<int, char>(3, 'e'));

	map<int, char> mp4(mp3);
	
	for_each(mp4.begin(), mp4.end(), show);		//for_each������show�������
	cout << "��������һ������������ʼ��" << '\n';

	//��MSDN��map��list��Щ��ע��Ҫ��class�Ĳ���c++�����ȥ����������Ƿ���c++��

//�������� ����һ�������һ�θ��������ʼ��
	map<int, char>::iterator ite = mp4.begin();
	ite++;

	map<int, char> mp5(ite, --mp4.end());

	for_each(mp5.begin(), mp5.end(), show);
	cout << "��������һ�����һ�θ��������ʼ��" << '\n';

}

//����Ԫ��					//��1���õ���࣬��23���õ���
{
	map<int, char> mp1;
	pair<map<int, char>::iterator, bool> pr;		//���ǲ���ķ���ֵ�����ͣ�������ס����Ԫ�ط��ص�true��false
													//MSDN��һ������ֻ����iterator����������Ҫ����֪ʶ�Ƶ�����������
	typedef pair<int, char> in_pair;				//�������Ļ����ͷ��������������д��

	//����һ��Ԫ��			�з���ֵ					//�������ﷵ������ĵ�����
		mp1.insert(pair<int, char> (5, 'e'));		//��Ϊmapһ��Ԫ�ذ���������Ԫ�أ���ֵ��ʵֵ��������������Ӧ����һ���ṹ������
													//C++�����ֽṹ�嶨���ˣ�����pair<> ע�⣺����ṹ��Ĳ�������Ҫ�������Ĳ�������һ��
		mp1.insert(pair<int, char> (9, 'g'));		//���Զ�����ֵ����Ĭ�ϴ�С����
		pr = mp1.insert(pair<int, char> (7, 'f'));	//��pr����ס����ֵ
		cout << pr.second << endl;					//1��true��//�������ֵ
		pr = mp1.insert(pair<int, char> (7, 'l'));	//��ֵ�������ظ����ظ����޷���ӡ����second�᷵��һ��false
		cout << pr.second << endl;					//0��false��
		pr = mp1.insert(pair<int, char>(3, 'e'));
		cout << pr.second << endl;					//1��true��ʵֵ�����ظ�

		for_each(mp1.begin(), mp1.end(), show);
		cout << '\n';
	

	//ָ��λ�ò���һ��Ԫ�أ�pair��	�з���ֵ
		map<int, char>::iterator mit = mp1.begin();	//map�ĵ�����������list��һ����������+1  +5������ַƫ�ƣ�ֻ��++ --
		mit++; mit++; mit++; mit++;					//�������������������ʾ����������ǽṹ��ɲ�һ��
													//������һ���ڵ�ָ�������ڵ㣬�������ָ�����ڵ�
		mp1.insert(mit, in_pair(1, 'j'));
		mp1.insert(--mit, in_pair(11, 'u'));		//���Թ۲⵽���������������Լ��Լ�ƫ���˵���������
			
		for_each(mp1.begin(), mp1.end(), show);		//���ǲ���󣬻��ǰ��ռ�ֵ��С�Զ�������		
		cout << endl;								//����ע�ⲻҪԽ�磬�������


	//������һ�������һ��	�޷���ֵ
		map<int, char> mp2;
		mp2.insert(in_pair(2, 'y'));
		mp2.insert(in_pair(4, 'Y'));
		mp2.insert(in_pair(6, 't'));
		mp2.insert(in_pair(0, 'Z'));

		mp1.insert(++mp2.begin(), --mp2.end());		//������mp2��ֵ������ 2 4 �� ��2 3��pair
													//��mp2������Ȼ���ٰ�˳������mp1
		for_each(mp1.begin(), mp1.end(), show);		
		cout << endl;

}

}

int main()
{
	STLmap();		//���飺MSDN������������ʱ���㿪һ��Ҫ�����Ϸ��Ƿ���C++��
					//��Ϊ�п�����java ���� FMC�����Ŀ�



	system("pause");
	return 0;
}