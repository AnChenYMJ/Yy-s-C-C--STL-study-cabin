#include <iostream>
#include <vector>
using namespace std;

//��ͨ��
class Ctre
{
public:
	int i;
	float g;
};

void DeFine()
{

	struct str
	{
		int a = 56;
		double b;
		char c;
		float f;
	};

//����vector
{
	//vector��������������̬���飩������
	//��string���ڴ������һ���ģ���������ռ�ʱ��������ʧЧ��(��ʼ�ռ���������������Ĵ�С��һ��)
	//vectorҪ��<>�мӲ�����������Ҫ�����������������͡�
	//string��Ϊ��ר������ַ������ַ��ģ����Բ��ؼӲ�����
	
	//vector�������ݵ����������ࣺ�����������ͣ��ṹ�����ͣ�ָ�����ͣ��������͡�
	//�����������ͣ�
	vector<int>		vec;		//������������int

	vector<float>	vecf;		//������������float

	//�ṹ�����ͣ�
	vector<str>		vecs;		//�ṹ������

	//ָ�����ͣ�
	vector<double*> vecb;		//ָ������

	//�������ͣ�
	vector<Ctre>	vecc;		//��ͨ���������

	vector<string>	veci;		//����������������
								//vector<string> �����þ���string������������һ�����ˣ����Ƕ��ַ������в�����
								//����string�������ַ������Ĺ���Ҫ���࣬�����á�
}
	
//����㣺s
{
	//��vector�⣬������������У�
	//array���̶����飩��ĳЩ�汾��֧��array��VS2013�Ժ����֧�֡�
	//valarray��������ѧ�������������<cmath.h>�ĺ�����װ�ġ����翪�������ݣ�log�ȡ�

	//vector����õģ�����һ����˵������vector���á�
}



}


int main()
{
	DeFine();



	system("pause");
	return 0;
}