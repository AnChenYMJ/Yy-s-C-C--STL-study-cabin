#define  _crt_secure_no_warnings
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stu
{
	char name[10];
	int age;
	double height;
};


int main(void)
{
	struct stu sd = { "��", 24, 1.65 };
					//�������֤������ַ�� -> ���ʳ�Ա�� ��ʵ�������ñ�����+.���ʳ�Ա
	printf("%s, %u, %lf \n", (&sd)->name, sd.age, sd.height);//����ʵ���������пռ�ľ���ʵ������
	//sd.age ������+.+��Ա��������ȡ��Ա����ʽ�ˣ���Ա����������ֱ��ʹ��
	//int a = 12;//�ṹ������͸��������ݱ���һ����ʹ�÷���


	struct stu* p = (struct stu*)malloc(sizeof(struct stu));//��������һ��ռ䣬����Ϊstruct stu*
	//��СΪsizeof(struct stu)�����ռ�ĵ�ַ��ָ��pװ��

	p->age = 18;//* &�����ȼ�Ҫ�� . ->�ͣ�����һ��Ҫע������������ȼ�
	(*p).height = 1.75;//�������֤������ַ�� -> ���ʳ�Ա�� ��ʵ�������ñ�����+.���ʳ�Ա
	strcpy(p->name, "yu");//��*p�����Ǳ����������Ծ���ʵ������

	printf("%s, %u, %lf \n", (*p).name, (*p).age, (*p).height);
	//* &�����ȼ�Ҫ�� . ->�ͣ�����һ��Ҫע������������ȼ�

	system("pause");
	return 0;
}