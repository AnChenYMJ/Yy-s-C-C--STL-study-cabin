#include <stdio.h>
#include <stdlib.h>


//�����㷨
//˳����ң�ʱ�临�Ӷ�O(2n)
int Sq_Search(int* a, int n, int key)//aΪҪ���ҵ����飬nΪҪ���ҵ�����ĳ��ȣ�keyΪҪ���ҵĹؼ���
{
	for (int i = 0; i < n; i++)
	{
		if (a[i] == key)
			return i;
	}
	return 0;
}
//˳������Ż��棺ʱ�临�Ӷ�O(n)
int Sq_Search2(int* a, int n, int key)
{
	int i = n;
	a[0] = key;
	while (a[i] != key)
		i--;
	return i;
}
//���������ѧ�ţ��ɼ�
struct XueSheng
{
	int XH;
	char* XM;
	int CJ;
};
int ShuChu(struct XueSheng wo[], int n, int key)
{

	for (int i = 0; i < n; i++)
	{
		if (wo[i].XH == key)
			return i;
	}
	return -1;
}




int main(void)
{
	//�����㷨
	{
		struct XueSheng XS[4] = { {2012, "С����", 88},
							  {2013, "Yy", 30},
							  {2014, "dream", 90}
		};
		int a = ShuChu(XS, 4, 2013);
		printf("%d\n%s\n%d", XS[a].XH, XS[a].XM, XS[a].CJ);
	}
	

	system("pause>0");
	return 0;
}