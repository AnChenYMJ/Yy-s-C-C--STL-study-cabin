#include <iostream>
using namespace std;

	//TT���������в������ͣ���ʽ�����������������κ����֣��ô�д�Ƚ������ֶ���
template <typename TT>		//����ģ�����ʽ����̬��ģ���Ƿ��ͱ�̵�˼��
void cat(TT o)				//���ͱ�̼�ͬ���Ĵ���ʵ�ֲ�ͬ�Ĺ���
{
	cout << o << endl;		//�Ա�����ĺ������أ��ᷢ�ֺ���ģ�������˺ܶ���룬ֻ��һ�δ��뼴��
}							//����ʵ�ֵĹ��ܸ�ȫ��

//template:ģ��    //class��typename��������һ���ģ���type�о���������ģ�壬����һ��
template <class TT, typename TR>		//��һ��ֻ�԰��ŵĴ������Ч
void cat1(TT o, TR i)				
{
	cout << o << ' ' << i << endl;		
}							


void dog(int a)		//�������أ�C++֧�֣�C���Բ�֧��
{
	cout << a << endl;
}
void dog(double b)	//�ֶ��ַ��������ڴ��ݽ����Ĳ���
{
	cout << b << endl;
}
void dog(char c)
{
	cout << c << endl;
}

int main()
{
	cat(12.98);

	cat1("Yy keep going", "26���ˣ��������˰�");



	system("pause");
	return 0;
}