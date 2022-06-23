#include <iostream>
#include <vector>			//C++��׼��ͷ�ļ���������.h��������Ϊ����C�������ֿ���ĳЩͷ�ļ�������ʵ�ǲ���
#include <algorithm>		//for_each()  ��ͷ�ļ�
#include <ctime>			//time()������ͷ�ļ�
using namespace std;

void show(int i)
{
	cout << i << ' ';
}

void STLran()
{
	vector<int> vec1;

	//ѭ���������Ԫ��
	for (size_t i = 0; i < 16; i++)
	{
		vec1.push_back(i * i * i);
	}
	//��ӡ
	for_each(vec1.begin(), vec1.end(), show);
	cout << endl;

	//�����㷨 random_shuffle()			//���򲻱�����
	random_shuffle(vec1.begin(), vec1.end());
	//��ӡ
	for_each(vec1.begin(), vec1.end(), show);
	cout << endl;				//��������һ�����⣬ÿ�����г�����Ȼ˳�����ˣ���ÿ�δ򿪵�˳����һģһ����
								//ԭ��������㷨�����������������������������������������
								//������һ�����ϱ仯���ظ��Ĵ���ֵ�����򴥷�ֵ��ͬ������Ҳ����ͬ
		

	//�����㷨 random_shuffle()			//����仯�����
	srand((unsigned int)time(0));		//������ôһ�������õ�ǰ��ϵͳʱ������������ֵ
										//��Ϊʱ���Ǳ仯�ģ��Ҳ����ظ�������ÿһ�ε����򶼲�ͬ

	random_shuffle(vec1.begin(), vec1.end());
	//��ӡ
	for_each(vec1.begin(), vec1.end(), show);
	cout << endl;

}

int main()
{
	STLran();



	system("pause");
	return 0;
}