#include <iostream>
using namespace std;

class SCC
{
public:
	int pou;
};

template <typename T, typename Y>
class Ctea
{
public:
	Ctea(SCC& v)		//���ݲ���Ϊ���������
	{

	}
};


template <typename T, typename U>
class SXX
{
public:
	int pou;
};

template <typename T, typename Y>
class Cstu
{
public:
	Cstu(SXX<char, const char*>& v)		//���ݲ���Ϊ���������
	{

	}
};

int main()
{
	SCC sc;		//�������ģ��
	Ctea<char, SCC> ta(sc);//���ݲ���Ϊ���������

	SXX<char, const char*> sx;	//�������ģ��
	Cstu<const char*, SXX<char, const char*>> tsx(sx);
			//��ģ��ʱ��ֻҪ��������SXX���ͱ������ģ������б�

			//<char, const char*>��������ʵ�����ͣ���typename T���ֲ�����ʵ������

	system("pause");
	return 0;
}