#include <stdio.h>
#include <stdlib.h>

struct Stu
{
	char fullname[10];
	int age;
};

struct Stu1
{
	char truename[10];
	struct Stu st;      //����ǽṹ��Ƕ�ף������ڽṹ�嶨����������һ���ṹ��ı��������Լ��ĳ�Ա
	double height;
};


struct Stu2
{

	struct Stu3
	{
		char fullname[10];//������һ���ṹ��1�����ж�����һ���ṹ��1
		int age;		//������2�еĳ�Ա���൱��1�еĳ�Աֱ�ӵ���ʹ����we.fullname
	};
	struct Stu3 de;//������we.de.fullname���������Ϊ0��������δ��ʼ��
};					//���Ƴ�Ա�Ǵ������µ�˳��2�Ľṹ�嶨��Ŀ�ܾͱ���ȥ�ˣ���2�ĳ�Ա�����Լ��ĳ�Ա


int main(void)
{
	struct Stu1 at = { "�ֿ�˹", {"�����к�", 18}, 1.65 };//��ʼ��ʱ��Ƕ�׵Ĳ����û����������������Ķ�
	printf("������ %s\nӢ������ %s\n���䣺 %d\n��ߣ� %lf\n\n", at.truename, at.st.fullname, at.st.age, at.height);
	                                      //ȡǶ�׳�Ա����at.st.fullname������ʽ

	struct Stu2 we = {"������", 30 };  
	printf("Ӣ������ %s\n���䣺 %d\n\n", we.fullname, we.age);


	system("pause");
	return 0;
}