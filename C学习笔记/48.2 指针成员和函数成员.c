#include <stdio.h>
#include <stdlib.h>


void fun(void)
{
	printf("keep going~\n");
}

struct Stu
{
	int* p;//ָ���Ա
};

struct Stu1
{
	int* p;//ָ���Ա
};

struct Stu2
{				//��������Ҫ���Լ���Ҫ���õĺ�����Ӧ��
	void (*p)(void);//���ǿ��Էź���ָ��


	/*void fun(void)  //�ṹ�嵱�в�����ֱ�ӷź���
	{
		printf("keep going~");
	}*/
};

int main(void)
{
	struct Stu sd = { NULL };//ָ���Ա�ĳ�ʼ���븳ֵ
	sd.p = (int*)malloc(8);//���ṹ�������ʼ��ΪNULLʱ��һ��Ҫ�ֶ�mallocһ��ռ�
	sd.p[0] = 45;  //����mallocһ��ռ䣬Ҫ���θ��ݿռ�������������ֵ
	sd.p[1] = 98;
	printf("%d, %d \n", sd.p[0], (&sd)->p[1]);
	free(sd.p);


	int a[6] = { 9, 8, 7, 6, 5, 4 };//ָ���Ա�ĳ�ʼ���븳ֵ
	struct Stu1 sd1 = { &a };//��a��&a[0]�����ԣ���������ʾͬһ����ַ
	////���ǳ�ʼ������Ϊ����ʱ��������ķ�ʽ
	printf("%d, %d, %d, %d \n", sd1.p[0], sd1.p[5], (&sd1)->p[3], (&sd1) -> p[2]);


				//��&funҲ����
	struct Stu2 sd2 = { fun };//�ڽṹ����ĳ�Ա�Ǻ���ָ�����ͣ��������ǰ���Ҫ�ĺ����ĵ�ַ��ֵ��ȥ
	sd2.p();//���������ܵ��ú�����
	//ע��.�루�������ȼ���һ���ģ�����Դ������ң���������.����p���

	system("pause");
	return 0;
}