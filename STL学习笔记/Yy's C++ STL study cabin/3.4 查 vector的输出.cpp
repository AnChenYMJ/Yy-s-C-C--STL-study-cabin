#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void show(int i)		//��������Ĳ��������ͣ�����Ҫ��������Ԫ������һ�£���д��char���������
{
	cout << i << ' ';
}

void STLost()
{
//�������
{
	//at()
	{
		vector<int> vec1;

		//ѭ�����Ԫ��
		for (int i = 0; i < 11; i++)
		{
			vec1.push_back(i);			//push_back()	������β�����һ��Ԫ�أ����������Ԫ�ص�ֵ
		}

		//at() �������
		cout << vec1.at(7)  << endl;

		//cout << vec1.at(11) << endl;	//Խ��ʱat�������׳�һ���쳣�����ǿ��Զ�����쳣���д��������

		//at ѭ���������
		for (size_t i = 0; i < vec1.size(); i++)
		{
			cout << vec1.at(i) << ' ';
		}
		cout << endl;
		
	}

	//[] �±�����
	{
		vector<int> vec1;

		//ѭ�����Ԫ��
		for (int i = 0; i < 7; i++)
		{
			vec1.push_back(i + 2);			//push_back() ��β�����һ��Ԫ�أ������Ǵ�Ԫ�ص�ֵ
		}

		//�������Ԫ��
		cout << vec1[6] << endl;

		//cout << vec1[7] << endl;			//�±�Խ��ֱ�Ӿͱ�����	//at����Խ�����׳�һ���쳣

		//[]ѭ���������
		for (size_t i = 0; i < vec1.size(); i++)	//size()�ķ���ֵ��size_t���͵ģ���unsigned int
		{
			cout << vec1[i] << ' ';
		}
		cout << endl;
	}

	//back() ����β�͵�Ԫ��
	{
		vector<int> vec1;

		//ѭ�����Ԫ��
		for (int i = 0; i < 5; i++)
		{
			vec1.push_back(i * i);
		}

		//�������Ԫ��
		cout << vec1.back() << endl;	//16

		cout << vec1.back()-3 << endl;	//16-3 ==13
		//back����û�в�����Ҳ���ܽ��е�ַƫ��

	}

	//begin��������ͷ��������
	{
		vector<int> vec1;

		//ѭ�����Ԫ��
		for (int i = 0; i < 8; i++)
		{
			vec1.push_back(i * i * i * i);
		}

		//�������Ԫ��
		cout << vec1.begin()[0]		<< endl;

		cout << (vec1.begin()+2)[0] << endl;	//begin()�ܹ����е�ַƫ�ƣ����д����*(vec1.begin() + 2)Ч��һ��

		//ѭ���������
		for (size_t i = 0; i < vec1.size(); i++)
		{
			cout << *(vec1.begin() + i) << ' ';	//���������ʾ���ָ�룬�������õ�ַ������
		}
		cout << endl;
	}
}

//ȫ�����
{
//ѭ�� ������  �� �±�
{
	vector<int> vec1;

	//ѭ�����Ԫ��
	for (int i = 0; i < 7; i++)
	{
		vec1.push_back(i * i * i * i * i * i);			//push_back() ��β�����һ��Ԫ�أ������Ǵ�Ԫ�ص�ֵ
	}

	vector<int>::iterator ite = vec1.begin();

	//�±�ѭ���������
	for (size_t i = 0; i < vec1.size(); i++)	//size()�ķ���ֵ��size_t���͵ģ���unsigned int
	{
		cout << vec1[i] << ' ';
	}
	cout << endl;

	//begin����ѭ���������
	for (size_t i = 0; i < vec1.size(); i++)
	{
		cout << *(vec1.begin() + i) << ' ';	//���������ʾ���ָ�룬�������õ�ַ������
	}
	cout << endl;

	//������ѭ���������
	for (ite; ite != vec1.end(); ite++)
	{
		cout << *ite << ' ';
	}
	cout << endl;
}

//for_each �㷨�������	//����ͷ�ļ���<algorithm>
{
	vector<int> vec1(12);

	//ѭ�����Ԫ��
	for (int i = 0; i < vec1.size(); i++)
	{
		vec1[i] = (i * i * i * i * i * i);			//push_back() ��β�����һ��Ԫ�أ������Ǵ�Ԫ�ص�ֵ
	}

	//for_each �㷨���
	for_each(vec1.begin(), vec1.end(), show);		//���һ������Ϊ�������Ҳ���Ҫд������for_each�Զ��Ὣ��������

	cout << endl;
}
}


}

int main()
{
	STLost();			//ѧϰ��Ҫʹ�÷������֣�������ṹ��������Ҫ�ӷֺŵȾ��������������ֵĻ���
						//�ͻ��Ժ󻻱��������ͻ��������Ҳ��������Ǽ���ؼ��ֵ�
						//�����Ժ����б�д���̣�����Ա��˼���ᱻһЩ�﷨С�������ϣ�������ܡ�
						//����ЩС���⣬��������ʹ�÷������ִ����ĸ����á�

						//ĳЩʱ���������д���ʱ������ʾ���Ƿ���������ϴγɹ�ʱ��...
						//�� �񣬲�Ҫ�� �ǣ���Ϊ �� �����г���Ķ�ǰû����ĳ��򡣾Ϳ�������ǰ�����������


	system("pause");
	return 0;
}