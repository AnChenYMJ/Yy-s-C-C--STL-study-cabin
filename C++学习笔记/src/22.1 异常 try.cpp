#include <iostream>
#include <cstdlib>	//cstdlib ��C++�ı�׼ͷ�ļ�д������ӦC���Ե�stdlib.h
#include <stdio.h>	//C++Ҳ������C���Ե�.hͷ�ļ� ��C++�ı�׼��cstdio
using namespace std;

void fun(int a)
{
	while (a < 10)
	{
		if (a == 8)		//��ô���쳣��Ҳ������Ϊ������
		{
			throw a;	//�������Ƕ�����쳣ʱ���׳�һ��ֵ��try��catch��ס
		}
		if (a == 5)
		{
			throw 'a';
		}
		if (a == 6)		
		{
			throw 123.689;	
		}
		a++;
	}
}


class Cfather
{
public:
	int fj;
	Cfather():fj(2)
	{}
};

void fun1(Cfather& a)	//��ס�����û���ָ�룬���⿽�����죬�ظ��ͷ�
{
	while (a.fj < 10)
	{
		if (a.fj == 8)		
		{
			throw a;	//�׳�����
		}
		if (a.fj == 5)		
		{
			throw &a;	//�׳�ָ��
		}
		a.fj++;
	}
}


int main()
{
	//int b;
	//cin >> b;
	//if (b == 1)	//����쳣��ֹ������Ϊ�����һ�������ʾ
	//{			
	//	abort();//��ִ���������ʱ������ִ��ʱ�ͻ��쳣����������ǰ�ĳ�������ı���һ��
	//}
		

	//try��һ���쳣����Ĺ��ܣ��Ա�abort��abortֻ��һ����ʾ��û�д���
	try  //ֻдtry�Ļ������д����Ͽ�ʼ�ġ�try����û�� catch �������
	{
		fun(1);		//�쳣�׳����쳣��������try�ڵ��õĺ�������Ч
	}
	catch(int c)	//�쳣����	//throw��ֵ���ݵ���������쳣����
	{
		cout << c << endl;//��ô����Ҳ������Ϊ������
	}
	catch (char b)	//�쳣����	//throw��ֵ���ݵ���������쳣����
	{
		cout << b << endl;//��ô����Ҳ������Ϊ������
		try		//try�ͺ�ȫ�� �ֲ�����һ�������������tryֻ�����catch����Ч
		{
			fun(5 + 1);//�쳣����������try�������Ǹ��쳣ֵ
		}
		catch (int c)
		{
			cout << c << endl;
		}
		catch(...)	//������ֵ��ȷ��ʱ����������������ס
		{
			cout << "default" << endl;
		}
	}
	

	Cfather fa;

	try
	{
		fun1(fa);
	}
	catch (Cfather& c)	//ʹ�����û���ָ�룬���⿽������
	{
		cout << "����" << endl;
	}
	catch (Cfather* c)
	{
		c->fj++;		//ָ�����
		cout << "ָ��" << endl;
	}


	system("pause");
	return 0;
}