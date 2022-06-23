#include <stdio.h>
#include <malloc.h>
#include <string.h>			//����memset()��ͷ�ļ�

//ʵ��Ӧ�û�Ҫ����Ӷ��Ԫ��
//ԭ����һ���ģ���һ��ѭ����������Ӽ��ɣ����ɽ��ù��ܷ�װ�ɺ�����


//2.5 ��̬�����м����Ԫ��	
//2.6 �±�̫������ô����
//2.7.1�������ģ���������������װ�����������ԡ�
//2.7.2�������ŵ����������棬������������Ͳ��ؿ����߼������ˣ�˭��˭�£�
//�໥���ú�����һ��ָ������ָ����������ļ�ָ�붼�ǿ��Ե�

//2.8~9 ɾ		�����������
//ɾ��������ʽ��1.ɾ��β	2.ɾ���м�	3.ɾ��ȫ��


//�м����Ԫ��Ҫ��
//�±��Ժ�������������Ųһλ
//Ȼ�����±괦�������
//���±�����Ѵ���ʱ�������ַ�ʽ��1.�쳣����2.��ӵ�β��
//����һЩ�߽���������Ҫ�˷�ʱ�������棬��д�������������ٵ���
//�����˺ܾúܾ��ҲŰѱ߽�����Ū��
//VS2019�ľ���ܾ�ϸ������û�б�Ҫȫ��������˷�ʱ�䣬����Ҫȷ�����ǳ����߼�������
//*�����г��õĲ��ǵ���Ԫ�����ӣ����Ƕ�������ǿ��԰�����Ԫ��˼·��д��ѭ������ѭ����װ�ɺ�������ʵ���˶��Ԫ�ز��롣


//��̬����������Ҫ����		//�ṹ�岻�ܷŵ�����Ȼ��������
struct DongShuZu
{
	int* ShuuZuTou;				//����ͷ�������׵�ַ��
	unsigned int ZongCunLiang;	//�ܴ���
	unsigned int YiCunLiang;	//�Ѵ���
};	   


//���������ʼ������
void ChuShiHua(struct DongShuZu* idsz);

//�������������װ����
void BianHua(struct DongShuZu* idsz);		//����ָ�롢���ݡ��±�

//β����Ӻ���
void TianJia(struct DongShuZu* idsz, int ShuJu);

//�м���뺯��
void ChaRu(struct DongShuZu* idsz, int ShuJu, unsigned int XiaBiao);

//��ӡ�������
void show(struct DongShuZu* idsz);

//ɾ��β
void ShanChuWei(struct DongShuZu* idsz);

//ɾ��ȫ��
void ShanChuQuanBu(struct DongShuZu* idsz);

//ɾ���м�
void ShanChuZhongJian(struct DongShuZu* idsz, unsigned int DiJiGe);



//������
int main(void)
{
	struct DongShuZu CeShi;
	ChuShiHua(&CeShi);			//��ʼ��

	TianJia(&CeShi, 3);
	TianJia(&CeShi, 8);
	TianJia(&CeShi, 4);
	TianJia(&CeShi, 2);
	TianJia(&CeShi, 7);
	TianJia(&CeShi, 1);
	show(&CeShi);				//��ӡ

	//�����м����
	ChaRu(&CeShi, 9, 1);		
	printf("�м����� \n");
	show(&CeShi);

	//�����±�����Ѵ���ʱ
	ChaRu(&CeShi, 56, 11);		
	printf("�����±�����Ѵ���ʱ�� \n");
	show(&CeShi);

	//����ɾ��β					//�����ԣ�3�ַ�ʽ���ɹ����
	ShanChuWei(&CeShi);
	printf("ɾ��βʱ�� \n");
	show(&CeShi);

	//����ɾ��βȻ�������
	TianJia(&CeShi, 77);
	printf("ɾ��β����Ӻ� \n");
	show(&CeShi);

	//����ɾ��ȫ��				//�����ԣ�3�ַ�ʽ���ɹ����
	ShanChuQuanBu(&CeShi);
	printf("ɾ��ȫ��ʱ�� \n");
	show(&CeShi);

	//����ɾ��ȫ��Ȼ�������		///�ϸ������������ɾ��ȫ���ĵ�3�ַ������ͷź�����Ӧ�ó�ʼ������û��ʼ��Ҳ���ԣ���֪��Ϊʲô
	TianJia(&CeShi, 88);
	printf("ɾ��ȫ������Ӻ� \n");
	show(&CeShi);

	//ɾ���м����
	TianJia(&CeShi, 8);
	TianJia(&CeShi, 4);
	TianJia(&CeShi, 2);
	TianJia(&CeShi, 7);
	TianJia(&CeShi, 1);
	printf("ɾ���м�ǰ�� \n");
	show(&CeShi);

	printf("ɾ���м�� \n");	//���Գɹ�
	ShanChuZhongJian(&CeShi, 2);
	show(&CeShi);

	//����ɾ���м䣬��������
	ShanChuZhongJian(&CeShi, 9);//���Գɹ�
	show(&CeShi);



	free(CeShi.ShuuZuTou);		//֮ǰд��free(&CeShi.ShuuZuTou),�����˺ܾã���Ҫ����д�����жϱ���

	return 0;
}


//���������ʼ������
void ChuShiHua(struct DongShuZu* idsz)
{
	if (idsz == NULL)
	{
		printf("��ʼ����������������\n");
		return;
	}

	if (idsz)
	{
		idsz->ZongCunLiang = 4;
		idsz->ShuuZuTou = (int*)malloc(sizeof(int) * idsz->ZongCunLiang);
		idsz->YiCunLiang = 0;
	}
}

//�������������װ����
void BianHua(struct DongShuZu* idsz)		//����ָ�롢���ݡ��±�
{

	//�쳣����
	if (idsz == NULL)
	{
		printf("Ԫ�ر仯�����������������\n");
		return;
	}

	if (idsz)	//��ֹNULLָ�����
	{
		//����ܴ����Ƿ�����
		if (idsz->ZongCunLiang == idsz->YiCunLiang)
		{
			//1.�ܴ������
			idsz->ZongCunLiang += 5;

			//2.�����¿ռ�
			int* newTou = (int*)malloc(sizeof(int) * idsz->ZongCunLiang);
			//memset(newTou, 0, sizeof(int) * idsz->ZongCunLiang);		//��ʦ����Ƶ��memset��newTou��ֵ��ʼ���ˣ�д��д����
		//3.��ԭ�ռ����ݸ��Ƶ��¿ռ�
			for (unsigned int i = 0; i < idsz->YiCunLiang; i++)			//i < (idsz->YiCunLiang-1)֮ǰ��ôд����ӡ�������,
			{															//�ҷ�����һ�¸պ��ǵ�4�����ݳ�����Ϊi=3ʱ��֮ǰ��д���Ͳ�ִ������ˣ�
				if (newTou)	//��ֹNULLָ�����							//ʵ����ִֻ����3�Σ����Ե�4������û�и��ƹ�ȥ������Ū����ˣ�����
				{
					newTou[i] = idsz->ShuuZuTou[i];
				}
			}

			//4.�ͷ�ԭ�ռ�
			free(idsz->ShuuZuTou);

			//5.ָ���¿ռ�����ͷ
			idsz->ShuuZuTou = newTou;
		}

	}

}

//β����Ӻ���
void TianJia(struct DongShuZu* idsz, int ShuJu)
{
	BianHua(idsz);		//������һ��ָ������ָ�붼�ǿ��Եģ�һ��ָ��������ָ���ⲿ�Ķ�̬���飬��ַ��һ����
						//����ָ��Ļ��������õ��õ��Ƕ�̬����ĵ�ַ�ĵ�ַ��Ч����һ����
	//β���������
	idsz->ShuuZuTou[idsz->YiCunLiang] = ShuJu;

	//�Ѵ�����С�仯
	idsz->YiCunLiang++;
}

//�м���뺯��
void ChaRu(struct DongShuZu* idsz, int ShuJu, unsigned int XiaBiao)
{

	////�±�����Ѵ�������ӵ�β������д��
	//if (XiaBiao >= idsz->YiCunLiang)
	//{	
	//	TianJia(idsz, ShuJu);
	//	return;			//�˳���ִ������
	//}

	//�±������ʦ�ķ��������
	if (XiaBiao > idsz->YiCunLiang)		//���±�����Ѵ���ʱ������ƵĲ�����Ϊi > XiaBiao��ִ��
	{									//ֱ�Ӿ���ӵ���β��
		XiaBiao = idsz->YiCunLiang;
	}

	//�±�ĺ������������һλ
	for (unsigned int i = idsz->YiCunLiang; i > XiaBiao; i--)
	{
		idsz->ShuuZuTou[i] = idsz->ShuuZuTou[i - 1];
	}

	//�±�λ�ò���ָ��������
	idsz->ShuuZuTou[XiaBiao] = ShuJu;

	//�Ѵ�����С�仯
	idsz->YiCunLiang++;

}

//��ӡ�������
void show(struct DongShuZu* idsz)
{
	if (idsz == NULL)
	{
		printf("��ӡ�����������������\n");
		return;
	}

	if (idsz)	//��ֹNULLָ�����
	{
		printf("�ܴ���Ϊ��%u, �Ѵ���Ϊ��%u \n", idsz->ZongCunLiang, idsz->YiCunLiang);
		printf("����Ϊ��");
		for (unsigned int i = 0; i < idsz->YiCunLiang; i++)
		{
			printf("%u ", idsz->ShuuZuTou[i]);
		}
		printf("\n\n");
	}
}

//ɾ��β
void ShanChuWei(struct DongShuZu* idsz)
{
	//�����Ϸ��Լ�⣨�����б��õ��ģ�
	if (idsz == NULL)
	{
		printf("ɾ��β�����������������\n");
		return;
	}

	//��ʽ1	�����Ѵ�������	���ı�������Ҳ����ĩβԪ�ع�0
		idsz->YiCunLiang--;

	//��ʽ2	��ĩβԪ������Ϊ0�����ı������������Ѵ���
		/*idsz->ShuuZuTou[idsz->YiCunLiang - 1] = 0;
		idsz->YiCunLiang--;*/

	//��ʽ3	��������ı��������ҽ�ĩβԪ�ع�0���޳�		д���ο�β���
		//if (idsz->ZongCunLiang >= idsz->YiCunLiang - 1)
		//{

		//	idsz->ZongCunLiang = idsz->YiCunLiang-1;

		//	int* newTou = (int*)malloc(sizeof(int) * idsz->ZongCunLiang);

		//	idsz->YiCunLiang--;						//���Ѵ�������д�������ʹ�����ٸ���

		//	for (unsigned int i = 0; i < idsz->YiCunLiang; i++)				
		//	{																
		//		if (newTou)	//��ֹNULLָ�����							
		//		{
		//			newTou[i] = idsz->ShuuZuTou[i];
		//		}
		//	}
		//	free(idsz->ShuuZuTou);
		//	idsz->ShuuZuTou = newTou;
		//}

	//���ַ�ʽ����ʽ1����ʣ���Ϊ2��3���������ˣ�ʵ��������ǲ����ܲ����޸�������飬������ܲ�����ӣ�
	//�������ʱ��Ҳ��ֱ�Ӹ��ǵ�ĩβԪ�ص�ֵ��0�ͱ����û�������Թ�0û��Ҫ���޸������󣬿������Ԫ��ʱ��Ҫ������������Ӱ��Ч��
	//����ֱ���Ѵ���-1��һ�������������Ч�������ķ���
}

//ɾ��ȫ��
void ShanChuQuanBu(struct DongShuZu* idsz)
{
	//�����Ϸ��Լ�⣨�����б��õ��ģ�
	if (idsz == NULL)
	{
		printf("ɾ��ȫ���������������\n");
		return;
	}

//��ʽ1�����Ѵ�����Ϊ0����	���ı�������Ҳ�������ݹ�0
	/*idsz->YiCunLiang = 0;*/

//��ʽ2��ȫ�����ݹ�0���Ѵ�����Ϊ0�����ı�����
	/*memset(idsz->ShuuZuTou, 0, sizeof(int)*idsz->YiCunLiang);
	idsz->YiCunLiang = 0;*/

//��ʽ3���ͷŵ����������ȫ����գ�ʹָ��ΪNULL
	idsz->YiCunLiang = 0;
	idsz->ZongCunLiang = 0;
	free(idsz->ShuuZuTou);
	idsz->ShuuZuTou = NULL;

//�����ֶ����ԣ���1�ָ���Ч��������Ҳ��������ģ����������Ƿ��ͷ�
}

//ɾ���м�
void ShanChuZhongJian(struct DongShuZu* idsz, unsigned int DiJiGe)
{
	//��������Ϸ��Լ��
	if (idsz->ShuuZuTou == NULL || DiJiGe > idsz->YiCunLiang)		//�������������ΪNULL�ļ��
	{																//����ɾ����������Ӳ�������ɾ������
		printf("ɾ���м����������Ч\n");								//���Բ�������һ����Ҫ���⴦��
		return;
	}

	//����Ҫɾ����λ�ú����������ǰ��
	for (unsigned int i = DiJiGe - 1; i < idsz->YiCunLiang - 1; i++)
	{
		idsz->ShuuZuTou[i] = idsz->ShuuZuTou[i + 1];				//�߽������ȳ���д���Ժ��������ԣ����˷�ʱ��
	}																//i���±꣬����ֻ���ƶ����±�Ϊi+1���������±�Ϊi+1�������Ѵ�����λ��
																	//i+1 = Y-1 ����������±���ͬ������i < Y-1û���⣬�պõ��߽磬ע��߽粻Ҫ��
	//�Ѵ���-1
	idsz->YiCunLiang--;

}
