#include <iostream>
#include <vector>
using namespace std;

void STLConstructors()
{
//������ʼ��
	vector<int> vec1;								//�޲���

	vector<int> vec2(7);							//7��Ԫ�ظ�������ʼ����7��Ԫ��Ĭ�ϳ�ʼ��Ϊ0

	vector<int> vec3(6, 'y');						//6�� 'y'��������ʼ��������Ԫ��int����

	vector<char> vecc(6, 'y');						//6�� 'y'��������ʼ��������Ԫ��char����

	vector<int> vec4(vec3);							//��һ��������������ʼ��

	vector<int> vec5(vec3.begin() + 2, vec3.end());	//�õ��������������ʼ��

	vector<char>::iterator ite1 = vecc.begin()+1;
	vector<char>::iterator ite2 = vecc.end();
	vector<char> vec6(ite1, ite2);					//�õ��������������ʼ��

//�����������������
{
	//cout << vec1[0] << endl;					//�����ˣ��޲�����û�����ݣ���Ȼ�޷����

	for (int i = 0; i < vec2.size(); i++)
	{
		cout << vec2[i] << ' ';						//����7��Ԫ��Ĭ�ϳ�ʼ��Ϊ0
	}
	cout << endl;

	for (int i = 0; i < vec3.size(); i++)
	{
		cout << vec3[i] << ' ';						//6��Ԫ�ض���121����Ӧy��ASC�����
	}												//��Ϊ�˶���vector����������������int
	cout << endl;

	for (int i = 0; i < vecc.size(); i++)
	{
		cout << vecc[i] << ' ';						//6��Ԫ�ش�ӡ���ַ�y
	}												//��Ϊ�˶���vector����������������char
	cout << endl;

	for (int i = 0; i < vec4.size(); i++)
	{
		cout << vec4[i] << ' ';						//6��Ԫ�ش�ӡ���ַ�y
	}												//��Ϊ�˶����ǿ���������vec3
	cout << endl;

	for (int i = 0; i < vec5.size(); i++)
	{
		cout << vec5[i] << ' ';						//4��Ԫ�ش�ӡ��121����Ӧy��ASC�����
	}												//���õ�������ȡ��vec3��һ������������ʼ��
	cout << endl;									//vec3.begin() + 2 ~ vec3.end()
		
	for (int i = 0; i < vec6.size(); i++)
	{
		cout << vec6[i] << ' ';						//5��Ԫ�ش�ӡ��y
	}												//���õ�������ȡ��vecc��һ������������ʼ��
	cout << endl;									//vecc.begin()+1~vecc.end();
}

//������ʼ����ע���
{
	//����Ϊ����ʱ��������������������ͱ���Ҫһ��
	vector<char> vec7(6, 'o');

	vector<int> vec8(vec7.begin() + 2, vec7.end());	//����ʦ����ʾ�vec7��vec8�������������ͱ���һ��
													//����ᱨ��
	for (int i = 0; i < vec8.size(); i++)
	{
		cout << vec8[i] << ' ';						//4��Ԫ�ش�ӡ��111,'o'��ASC��
	}												
	cout << endl;


	//��ҪԽ�����
	//cout << vec7[6] << endl;						//Խ���ȡ�����������


	//stringû�������������Ͳ����б��Ƚ����⣬�Ժ�����ѧ����������������������б�
	//string�кܶ��±�������ĺ�����Ҳ������ģ�������������������õ��������±���١�
	//���е�������begin������ end������Щ��������ͨ�õ�
	//����capacity()�� reserve��Щ��Ա����Ҳ��ͨ�õ�

}

}

int main()
{
	STLConstructors();



	system("pause");
	return 0;
}