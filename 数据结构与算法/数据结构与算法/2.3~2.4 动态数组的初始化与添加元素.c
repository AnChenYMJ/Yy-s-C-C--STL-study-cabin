#include <stdio.h>		//��׼�������������ͷ�ļ�
#include <malloc.h>		//malloc��ͷ�ļ�


//����
void jiangjie()	
{
//β�������һ���ڵ�Ľ���˼·
// 
	//����Ҫ����һ����̬���飬��Ҫ�������������⣨��Ҫ��

	//1.��̬������׵�ַ �׵�ַ��¼������	
	//2.�ɴ�ŵ��������� ����������¼������
	//3.�Ѵ洢���������� �Ѿ���ŵ����ݵ�������¼����
	//�ش���һ���ṹ�彫��������ͳһ��������ʹ��

//�������⣺����Ҫ��		���������
	//1.��ָ̬��			�����׵�ַ�⣬����һ���ܱ仯��ָ��������������ָ������������
	//2.Ԫ�ش�С			����Ԫ�ص�����������double�ģ������ǿ���Ҫ��¼double�� 8 �ֽڣ�����
}

//�ṹ�������������������
struct DongTaiShuZu							//�ṹ�������������������
{
	int* ShouDiZhi;							//�׵�ַ		��¼�ռ��׵�ַ
	unsigned int ZongCunLiang;				//�ܴ���		�ռ������ܴ�ŵ�����
	unsigned int YiCunLiang;				//�Ѵ���		��ռ�õ�����
};		

//��ʼ������
void ChuShiHua(struct DongTaiShuZu* pDSZ)	//��ʼ������
{
	//NULLָ����ʾ	//�Ժ�д���룬�������Ҫ��ֻҪ������ָ�룬��Ҫ����
	if (pDSZ == NULL)
	{
		printf("��ʼ�����������쳣\n");
		return;
	}
	if (pDSZ)		//��ֹNULLָ��
	{
		pDSZ->ZongCunLiang = 5;					//��ʼ������Ϊ5	//�������������ó�ʼ����
		pDSZ->YiCunLiang = 0;					//��ʼ��Ϊ��
		pDSZ->ShouDiZhi = (int*)malloc(sizeof(int) * pDSZ->ZongCunLiang);	//malloc����ռ䣬���ҽ��ռ��׵�ַ���ظ�ShouDiZhi
												//ע����������Ŀռ��С���ܴ�����С����Ҫ��malloc����ֵǿת��ָ��
	}
}	

//���Ԫ��		//��Ҫ
void TianJia(struct DongTaiShuZu* pDSZ, int iShuJu)
{
	//NULLָ����ʾ	
	if (pDSZ == NULL)
	{
		printf("����Ԫ�غ��������쳣\n");
		return;
	}
	//��ֹ����NULLָ��
	if (pDSZ)			//�������Ƚ���Ҫ���ǵ�д
	{
		//�ж������Ƿ�����
		if (pDSZ->ZongCunLiang == pDSZ->YiCunLiang)
		{
			//1.�������
			pDSZ->ZongCunLiang += 10;
			//2.�����¿ռ�
			int* newShou = (int*)malloc(sizeof(int) * pDSZ->ZongCunLiang);

			//3..��������
			for (unsigned int i = 0; i < (pDSZ->YiCunLiang-1); i++)			//��һ�����о���
			{	
				if (newShou)						//��ֹNULLָ��
				{
					newShou[i] = pDSZ->ShouDiZhi[i];//��ԭ���ݸ��Ƶ��¿ռ�
				}
				
			}
			//4.�ͷ�ԭ�ռ�
			free(pDSZ->ShouDiZhi);
			if (newShou)							//��ֹNULLָ�������о���
			{
			//5.������ͷָ��ָ���µ�ַ
				pDSZ->ShouDiZhi = newShou;
			}
		}

		//д������
		pDSZ->ShouDiZhi[pDSZ->YiCunLiang] = iShuJu;
		//�Ѵ����仯
		pDSZ->YiCunLiang++;	
	}
	
}

//��ӡ����
void show(struct DongTaiShuZu* pDSZ)	//���Բ���ָ�룬�����Ļ����൱�ڴ���һ����ʱ�ṹ�������Ȼ������ݸ��Ƶ���ʱ�����ٴ���Ч�ʵ���
{
					//NULLָ����ʾ	
	if (pDSZ == NULL)
	{
		printf("��ӡ���������쳣");
		return;		//�˳�����
	}

	if (pDSZ)		//��ֹNULLָ��
	{
		printf("�ܴ�����%u, �Ѵ�����%u \n", pDSZ->ZongCunLiang, pDSZ->YiCunLiang);
		printf("�������ݣ�");
		for (unsigned int i = 0; i < pDSZ->YiCunLiang; i++)
		{
			printf("%d ", pDSZ->ShouDiZhi[i]);
		}
	}	

}

int main(void)
{
	struct DongTaiShuZu DSZ;				//�����ṹ�����

	ChuShiHua(&DSZ);						//��ʼ������

	TianJia(&DSZ, 6);						//д������
	TianJia(&DSZ, 3);
	/*TianJia(&DSZ, 4);
	TianJia(&DSZ, 6);
	TianJia(&DSZ, 9);
	TianJia(&DSZ, 8);*/
	TianJia(NULL,5);						//����NULL����쳣����
	TianJia(&DSZ, 6);
	TianJia(&DSZ, 9);

	show(&DSZ);								//��ӡ
	show(NULL);								//����NULL����쳣����

	free(DSZ.ShouDiZhi);					//�ͷſռ�	һ��Ҫ�ͷţ���������Ŀռ佫��Զռ��
	//free(&DSZ);							//����Ҳ���ԣ�����ĸ����߼�����Ϊ��ShouDiZhi����Ŀռ�
	return 0;
}