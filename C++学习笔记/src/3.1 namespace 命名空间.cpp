#include <iostream>
using namespace std;//���Ǵ�std�������ռ䣬���ǳ��õ�cout cin������std�������������Ҫ��
//�����ռ�

//using std::cout;//ָ�����ſռ�ĳһ��Ա�������ã�ע���ǿ��Ų��ǵ���

//using namespace���ܷ��ڱ����õ������ռ�֮ǰ

namespace stu //�����ռ����ܷŶ����������Ա�������������ռ�ĺ���������һ��
			//�������ռ�����ֲ�����ͬ 
{
	void stop()
	{
		cout << "Keep going! yy." << endl;
	}
}

;;;;//�����ǲ������ģ��ֺ������Ľ���������д����һ�ѿ���䣬�Ƿ����߼���

namespace stu1
{
	void stop()
	{			//  :: �����������
		std::cout << "Don't waver,you're strong." << std::endl;
	}	//������д��û���⣬�ܷ����߼���cout��endl��std�ռ���Ķ���

}

using namespace stu;//�����ռ�ĵ�������ȫ�������ã���ע�ⲻ���������ռ䶨��֮ǰ����

int main()
{
	//using namespace stu;//�ȵ��������ռ䣬//��һ�ֵ��÷�ʽ
	stop(); //�ٵ��ÿռ���ĺ��� 

	//using namespace stu1;
	//stop();//�����������ռ��ڵĺ���ͬ�����������ռ䶼����ʱ���Ͳ��������ַ�ʽ���ú�����

	stu1::stop();//����ǵڶ��ֵ��÷�ʽ������������������ռ���ĳ�Ա��
	stu ::stop();

	using stu::stop;//ָ�����ſռ����ĳһ��Ա��ע�ⲻ�ǵ��ã��ǿ��ţ����ǿ��ź���ܵ��������Ա��
					//���������

	std::cout << "Keep going~" << std::endl;
	system("pause");
	return 0;
}