#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	float f = 12.11;              //float 4�ֽ�  ��Сֵ�� 6��ʵ��7λ���ӷ��������ʼ����6λ��
	double d = 1.556;             //double 8�ֽ� ��Сֵ��10��ʵ��16λ
	long double ld = 0.56564;     //long double ����8�ֽڲ�ͬ��������һ����
	long double le = 0.111155;    //����10�ֽڣ�����12�ֽ� 2���������ֽڣ�ANSI C��׼�涨��Сֵ��10��windows��18λ
                                  vs��double��long double�ķ�Χ��һ����
                                   
	printf("%f %lf %lf %e \n", f, d, ld, le);    //ע��printf��������ı���������ʱ�����ʼ��������һ��ֵ��
	                                      //%f��flost���������%lf��double��long double �������
	                                      //%e�ǿ�ѧ���������������������������,������������

	system("pause");     //ÿдʮ���д���ǵñ���һ�£�����ʾ���׸ģ�����д���ϰ����ٸľͻ����Ѻܶࡣ
	return 0;
}                      //�����͵���ֵ���ܽ���ֱ�ӱȽϣ���Ϊ���Ǿ�ȷ��ֵ