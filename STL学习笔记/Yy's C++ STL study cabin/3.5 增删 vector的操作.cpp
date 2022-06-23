#include <iostream>
#include <vector>
#include <algorithm>		//for_each()  ��ͷ�ļ�
#include <functional>		//greater<> ()��ͷ�ļ�	
using namespace std;

void show(int i)			//���޷���ֵ�����ԣ�����Ҫ������Ԫ������һ��
{	
	cout << i << ' ';
}

void STLadd()
{
//���
{
	vector<int> vec1;
	vector<int> vec2(5, 99);
	vector<int> vec3(4, 18);

	//β���
	{
		vec1.push_back(55);			//����������β�����һ��ֵ

		for (size_t i = 0; i < vec1.size(); i++)
		{
			cout << vec1[i] << ' ';
		}
		cout << endl;

		vec1.push_back(55);
		vec1.push_back(55);
	}

	//�м����
	{
		for_each(vec2.begin(), vec2.end(), show);
		cout << endl;

		vec2.insert(vec2.begin()+2, 26);		//��ָ��λ�����һ��Ԫ��
		for_each(vec2.begin(), vec2.end(), show);
		cout << endl;

		vec2.insert(vec2.begin() + 5, 6, 30);	//��ָ��λ�����num��ֵΪval��Ԫ��
		for_each(vec2.begin(), vec2.end(), show);
		cout << endl;

		vec2.insert(vec2.end() - 2, vec3.begin() + 1, vec3.begin() + 3);
		for_each(vec2.begin(), vec2.end(), show);//��ָ��λ�������һ��������һ��
		cout << endl;

		vec2.insert(vec2.end(), 11);			//Ҳ�������ù�����β�����
		for_each(vec2.begin(), vec2.end(), show);
		cout << endl;
	}

	//�ܽ�
	{
		//���鲻�������������Լ���������װ����
		//�������ʱ�������м����ͻ����鷳������λ��֮���ֵҪ������ơ�
		//����push_back Ҫ�� insert ��Ч�����ø��ߡ�
		//β����� �� �м���� Ч�ʸ��ߣ����ؿ����������ӿռ䡣
	}
}

//ɾ
{
	vector<int> vec2(5, 99);
	vector<int> vec3(4, 18);

	//βɾ��		pop_back()
	{
		for_each(vec3.begin(), vec3.end(), show);
		cout << endl;

		vec3.pop_back();			//һ��ɾ��һ��

		for_each(vec3.begin(), vec3.end(), show);
		cout << endl;

		vec3.erase(vec3.end()-1);	//����-1 ��Ϊend����ָ�����һ��Ԫ�ص���һλ�������±���

		for_each(vec3.begin(), vec3.end(), show);
		cout << endl;
	}

	//ɾ��ָ��	erase()
	{
		vec2.erase(vec2.begin() + 4);

		for_each(vec2.begin(), vec2.end(), show);
		cout << endl;

		vec2.erase(vec2.begin() + 1, vec2.begin() + 3);

		for_each(vec2.begin(), vec2.end(), show);
		cout << endl;

		vec2.erase(vec2.end() - 1);				//ɾ��β��������-1����Ϊ������ָ��ĩβԪ�ص���һλ��Խ������ˡ�

		for_each(vec2.begin(), vec2.end(), show);
		cout << endl;
	}

	//ɾ��ȫ��	clear()
	{
		cout << "ɾ��ȫ�� clear��" << endl;
		for_each(vec2.begin(), vec2.end(), show);
		cout << endl;
		for_each(vec3.begin(), vec3.end(), show);
		cout << endl;

		vec2.clear();				//clear������ɾ��ȫ��
		vec3.clear();				//Ҳ�Ǻܳ��õĺ���

		for_each(vec2.begin(), vec2.end(), show);
		cout << endl;
		for_each(vec3.begin(), vec3.end(), show);
		cout << endl;
	}
}

//�޸�
{
	//����3.4�е������֪ʶȥ�޸�

	//����assign ���¸�ֵ
	vector<int> vec2(5, 99);
	vector<int> vec3(4, 18);

	vec2.assign(45, 5);								//45��5��������ֵ,����Ҳ��5�����45
	vec3.assign(vec2.begin() + 1, vec2.begin() + 7);//����һ��������ĳһ�θ���������ֵ

	cout << "�޸ĸ�ֵ assign��" << endl;
	for_each(vec2.begin(), vec2.end(), show);
	cout << endl;
	for_each(vec3.begin(), vec3.end(), show);
	cout << endl;
	cout << vec2.capacity() << endl;				//���������45

	vec2 = vec3;									//����һ������ֱ�Ӹ�ֵ��������

	for_each(vec2.begin(), vec2.end(), show);
	cout << endl;		
	cout << vec2.capacity() << endl;				//������û�б仯�������������
}

//����
{
	vector<int> vec2(5, 99);
	vector<int> vec3(4, 18);

	for_each(vec2.begin(), vec2.end(), show);
	cout << endl;

	for_each(vec3.begin(), vec3.end(), show);
	cout << endl;

	//����
	vec2.swap(vec3);			//����������������

	for_each(vec2.begin(), vec2.end(), show);
	cout << endl;

	for_each(vec3.begin(), vec3.end(), show);
	cout << endl;
}

//��������� �Ƚ� �� []
{
	vector<int> vec2(5, 99);
	vector<int> vec3(4, 18);

	//�Ƚ�
	{
		cout << (vec2 >= vec3) << endl;		//�ɹ����� 1 

		cout << (vec2 <= vec3) << endl;		//ʧ�ܷ��� 0

		cout << (vec2 == vec3) << endl;		//ʧ�ܷ��� 0
	}

	//�±������
	{
		cout << vec2[2] << endl;
	}
}

//�����㷨
{
	vector<int> vec2(5, 99);
	vector<int> vec3(4, 18);

	//�㷨һ��for_each ����
	{
		for_each(vec3.begin(), vec3.end(), show);		//��stringһ�����÷�
		cout << endl;
	}

	//�㷨����sort ����
	{
		vec2.push_back(46);
		vec2.push_back(7);
		vec2.push_back(32);
		vec2.push_back(27);
			
		vec2.insert(vec2.begin() + 1, 135);				//ָ��λ�ò���Ԫ��
		vec2.insert(vec2.begin() + 3, 65);

		sort(vec2.begin()+4, vec2.end()-1);				//��stringһ�����÷����ܣ�ָ����Χ������
														//Ĭ�ϴ�С��������
		for_each(vec2.begin(), vec2.end(), show);		
		cout << endl;

		sort(vec2.begin(), vec2.end(), greater<int>());	//�Ӵ�С����Ҫ��ӵ���������greater<>()α����
														//greater<int>() <>�ڵ�����Ҫ��Ԫ������һ��
		for_each(vec2.begin(), vec2.end(), show);
		cout << endl;
	}
}

}

int main()
{
	STLadd();				//����vector������array��valarray��������
							//array��VS2015�в�֧�֣�2013�Ժ�֧�֣�������
							//valarray��һЩ��ѧ�����ķ�װ���õ���ѧ����Ļ�������ֱ�ӵ��ú�����
							//��������������󣬹�ʽ�࣬�϶�����valarrayҪ����Ч�ʷ��㡣


	system("pause");
	return 0;
}