#include <iostream>

void fun();


int main()
{			
	{				//error C2065: ��cout��: δ�����ı�ʶ��
		using namespace std;//���ѱ�׼�����ռ�д�ھֲ�����ô�ֲ�֮��Ͳ���ʹ������
	}

	std::cout << "����������" << std::endl;//����ʹ��cout �� endl ֻ��ͨ��std����������


	fun();

	system("pause");
	return 0;
}

void fun()
{		
	std::cout << "������" << std::endl; //ֻ��ͨ��std������ʵ�ֵ���
}