#include <iostream>
#include <string.h>			//����memset()��ͷ�ļ�

using namespace std;


//�ص�
void TeDian()
{
//1.�ռ�����
	//ÿ��Ԫ�ض������ڵģ���ַҲ�����������

//2.�ŵ㣺
	//*��������ʣ��ҷ����ٶȿ졣�±����
	//�±���ʱ�����ʵ���ǵ�ַ�����������Կ�

//3.ȱ�㣺
	//*����ɾ��Ч����
	//ԭ������ɾ�漰���¿ռ�����������ݵĸ���
	//�����м������ɾ��ʱ���漰�����ݵ�ǰ������

//ѡȡ��
 	//����������ɾ�죬������
	//��ʵ�������У����ݷ��ʴ���ռ��Ҫʱ��ѡ�������
	//���������޸ģ���ɾռ��Ҫʱ��ѡ��������Ϊ���ݽṹ����
	//�����������󣬻��������������ʱ��ѡ�ĸ�������
	//Ҳ�����е�ѡ�񣬾��Ǻ���������Ľ������ݽṹ��
	//��STL���map�������ٶȱ������ܶ࣬����������һ�㣻��ɾЧ�ʱ������ܶ࣬����������һ�㡣

//�Ҹ棺
	//�㷨������������ģ�����Ҫһ����ȥ�����ˣ��������ˣ���д��������ֱ�����ĸ�����
	//���ǵ������Լ���˼�����Լ�����ô���ˣ���ȥ���������ٲο�ѧϰ���˵����������ܳɳ�����
}

//����Ϊ��һԴ�ļ��ĳ�C++��ģ��������һ�ļ���ע�������ݣ��޸����£�
//1.�ṹ��ĳ��࣬�����Ž�ȥ������ʵ�ּ����������� DongShuZu::
//2.�������η�����
//3.ɾ����ǰ���ں����Ĳ���
//4.�޸Ķ�����ã����ṹ���Ϊ�����������ú�����
//5.new delete ���� malloc free		(new int[] : intΪԪ�����ͣ�[]����Ԫ�ظ���������ֵ�ǿռ��׵�ַ������ǿת)��delete[] �ռ��ַ : ���������ͷ���delete���[]����ͨ����ɲ��ӣ�Ϊ�˹淶���Ǽ��ϣ�
//6.��д���캯�� �� ��������	�����캯������������ʱִ�У�һ��������ʼ���������������������ʱ�Զ�ִ�У������ͷſռ䣩
//7.cout ��� printf			(cout �Ļ���Ҳ������ "\n" '\n' ���� endl ������Ч��'\n' > "\n" > endl)��Ϊendl�漰������������


//��
class DongShuZu					//��Ϊ��
{
private:						//˽��
	int* ShuuZuTou;				//����ͷ�������׵�ַ��
	unsigned int ZongCunLiang;	//�ܴ���
	unsigned int YiCunLiang;	//�Ѵ���
	void BianHua();				//�������������װ����	(�������Ϊ˽�еģ������ڻ���Ԫ�ܵ���)
	
public:							//�˴���������
	DongShuZu();				//���캯��	����������ʱִ�У�һ��������ʼ��
	~DongShuZu();				//��������	���������ʱ�Զ�ִ�У�һ�������ͷſռ�


public:							//���е�
	//���������ʼ������
	void ChuShiHua();			

	//β����Ӻ���
	void TianJia(int ShuJu);	//void TianJia(struct DongShuZu* idsz, int ShuJu);�Դ�Ϊ������Ϊ�����ڣ����Բ����ڴ����󣨽ṹ�壩ָ���������ˣ���ɾ����һ���ṹ��ָ�����

	//�м���뺯��
	void ChaRu(int ShuJu, unsigned int XiaBiao);

	//��ӡ�������
	void show();

	//ɾ��β
	void ShanChuWei();

	//ɾ��ȫ��
	void ShanChuQuanBu();

	//ɾ���м�
	void ShanChuZhongJian(unsigned int DiJiGe);

};

//������
int main()
{
	class DongShuZu CeShi;

	CeShi.TianJia(3);
	CeShi.TianJia(8);
	CeShi.TianJia(4);
	CeShi.TianJia(2);
	CeShi.TianJia(7);
	CeShi.TianJia(1);
	CeShi.show();				//��ӡ

	//�����м����
	CeShi.ChaRu(9, 1);
	cout << "�м����� \n";
	CeShi.show();

	//�����±�����Ѵ���ʱ
	CeShi.ChaRu(56, 11);
	cout << "�����±�����Ѵ���ʱ�� \n";
	CeShi.show();

	//����ɾ��β					
	CeShi.ShanChuWei();
	cout << "ɾ��βʱ�� \n";
	CeShi.show();

	//����ɾ��βȻ�������
	CeShi.TianJia(77);
	cout << "ɾ��β����Ӻ� \n";
	CeShi.show();

	//����ɾ��ȫ��				//�ĳ�C++��֮��ɾ��ȫ�����շ���3��ShuuZuTou���NULL�����³���
	CeShi.ShanChuQuanBu();		//��ΪShuuZuTouֻ��һ���������NULL��Ҫ���¸�ShuuZuTou����ռ����
	cout << "ɾ��ȫ��ʱ�� \n";
	CeShi.show();

	//����ɾ��ȫ��Ȼ�������		
	CeShi.ChuShiHua();			//��Ϊɾ��ȫ���ͷ���ָ�룬���Գ�ʼ������������ռ�
	CeShi.TianJia(88);
	cout << "ɾ��ȫ������Ӻ� \n";
	CeShi.show();

	//ɾ���м����
	CeShi.TianJia(8);
	CeShi.TianJia(4);
	CeShi.TianJia(2);
	CeShi.TianJia(7);
	CeShi.TianJia(1);
	cout << "ɾ���м�ǰ�� \n";
	CeShi.show();

	cout << "ɾ���м�� \n";
	CeShi.ShanChuZhongJian(2);
	CeShi.show();

	//����ɾ���м䣬��������
	CeShi.ShanChuZhongJian(9);
	CeShi.show();


	//free(CeShi.ShuuZuTou);	//C++���ͷſռ�ŵ������������У��Ҹĳ���delete

	return 0;
}

//���캯��
DongShuZu::DongShuZu()
{
	ChuShiHua();		//��ʼ��
}

//��������
DongShuZu::~DongShuZu()
{
	delete[] ShuuZuTou;	//�ͷſռ�
}

//���������ʼ������		//�������������� DongShuZu::
void DongShuZu::ChuShiHua()					//�Դ�Ϊ�������������������Ҫ���DongShuZu::����������
{
	//if (ShuuZuTou == NULL)				//��Ϊɾ��ȫ���ķ���3Ҫ�ͷŵ�ShuuZuTou����ΪNULL�����³���ס
	//{										//����Ϊ�˼�������Ĳ��ԣ�ȡ�������Ϸ��Լ�⣬�ó�ʼ��ֱ����������ռ�
	//	cout << "��ʼ����������������\n";
	//	return;
	//}

	/*if (ShuuZuTou)
	{*/
		ZongCunLiang = 4;					//idsz->ZongCunLiang = 4;�Դ�Ϊ����ֱ�ӵ������ڳ�ԱZongCunLiang���ɣ�����ָ�����
		ShuuZuTou = new int[sizeof(int) * ZongCunLiang];	
		YiCunLiang = 0;						//(new int[] : intΪԪ�����ͣ�[]����Ԫ�ظ���������ֵ�ǿռ��׵�ַ������ǿת)
	//}
}

//�������������װ����
void DongShuZu::BianHua()		//����ָ�롢���ݡ��±�
{

	//�쳣����
	if (ShuuZuTou == NULL)
	{
		cout << "Ԫ�ر仯�����������������\n";
		return;
	}

	if (ShuuZuTou)	//��ֹNULLָ�����
	{
		//����ܴ����Ƿ�����
		if (ZongCunLiang == YiCunLiang)
		{
			//1.�ܴ������
			ZongCunLiang += 5;

			//2.�����¿ռ�
			int* newTou = new int[sizeof(int) * ZongCunLiang];
			//memset(newTou, 0, sizeof(int) * idsz->ZongCunLiang);		//��ʦ����Ƶ��memset��newTou��ֵ��ʼ���ˣ�д��д����
		//3.��ԭ�ռ����ݸ��Ƶ��¿ռ�
			for (unsigned int i = 0; i < YiCunLiang; i++)			//i < (YiCunLiang-1)֮ǰ��ôд����ӡ�������,
			{															//�ҷ�����һ�¸պ��ǵ�4�����ݳ�����Ϊi=3ʱ��֮ǰ��д���Ͳ�ִ������ˣ�
				if (newTou)	//��ֹNULLָ�����							//ʵ����ִֻ����3�Σ����Ե�4������û�и��ƹ�ȥ������Ū����ˣ�����
				{
					newTou[i] = ShuuZuTou[i];
				}
			}

			//4.�ͷ�ԭ�ռ�
			delete[] ShuuZuTou;

			//5.ָ���¿ռ�����ͷ
			ShuuZuTou = newTou;
		}

	}

}

//β����Ӻ���
void DongShuZu::TianJia(int ShuJu)
{
	BianHua();		//��Ϊ�����ڣ�����ָ�����
						
	//β���������
	ShuuZuTou[YiCunLiang] = ShuJu;

	//�Ѵ�����С�仯
	YiCunLiang++;
}

//�м���뺯��
void DongShuZu::ChaRu(int ShuJu, unsigned int XiaBiao)
{

	////�±�����Ѵ�������ӵ�β������д��
	//if (XiaBiao >= idsz->YiCunLiang)
	//{	
	//	TianJia(idsz, ShuJu);
	//	return;			//�˳���ִ������
	//}

	//�±������ʦ�ķ��������
	if (XiaBiao > YiCunLiang)		//���±�����Ѵ���ʱ������ƵĲ�����Ϊi > XiaBiao��ִ��
	{									//ֱ�Ӿ���ӵ���β��
		XiaBiao = YiCunLiang;
	}

	//�±�ĺ������������һλ
	for (unsigned int i = YiCunLiang; i > XiaBiao; i--)
	{
		ShuuZuTou[i] = ShuuZuTou[i - 1];
	}

	//�±�λ�ò���ָ��������
	ShuuZuTou[XiaBiao] = ShuJu;

	//�Ѵ�����С�仯
	YiCunLiang++;

}

//��ӡ�������
void DongShuZu::show()
{
	if (ShuuZuTou == NULL)
	{
		cout << "��ӡ�����������������\n";
		return;
	}

	if (ShuuZuTou)	//��ֹNULLָ�����
	{
		cout << "�ܴ���Ϊ��" << ZongCunLiang << ' ' << "�Ѵ���Ϊ��" << YiCunLiang << '\n';
		cout << "����Ϊ��";
		for (unsigned int i = 0; i < YiCunLiang; i++)
		{
			cout << ShuuZuTou[i] << ' ';
		}
		cout << "\n\n";
	}
}

//ɾ��β
void DongShuZu::ShanChuWei()
{
	//�����Ϸ��Լ�⣨�����б��õ��ģ�
	if (ShuuZuTou == NULL)
	{
		cout << "ɾ��β�����������������\n";
		return;
	}

	//��ʽ1	�����Ѵ�������	���ı�������Ҳ����ĩβԪ�ع�0
	//YiCunLiang--;

	//��ʽ2	��ĩβԪ������Ϊ0�����ı������������Ѵ���
		ShuuZuTou[YiCunLiang - 1] = 0;
		YiCunLiang--;

		//��ʽ3	��������ı��������ҽ�ĩβԪ�ع�0���޳�		д���ο�β���
			//if (ZongCunLiang >= YiCunLiang - 1)
			//{

			//	ZongCunLiang = YiCunLiang-1;

			//	int* newTou = new int[sizeof(int) * ZongCunLiang];

			//	YiCunLiang--;						//���Ѵ�������д�������ʹ�����ٸ���

			//	for (unsigned int i = 0; i < YiCunLiang; i++)				
			//	{																
			//		if (newTou)	//��ֹNULLָ�����							
			//		{
			//			newTou[i] = ShuuZuTou[i];
			//		}
			//	}
			//	delete[] ShuuZuTou;
			//	ShuuZuTou = newTou;
			//}

		//���ַ�ʽ����ʽ1����ʣ���Ϊ2��3���������ˣ�ʵ��������ǲ����ܲ����޸�������飬������ܲ�����ӣ�
		//�������ʱ��Ҳ��ֱ�Ӹ��ǵ�ĩβԪ�ص�ֵ��0�ͱ����û�������Թ�0û��Ҫ���޸������󣬿������Ԫ��ʱ��Ҫ������������Ӱ��Ч��
		//����ֱ���Ѵ���-1��һ�������������Ч�������ķ���
}

//ɾ��ȫ��
void DongShuZu::ShanChuQuanBu()
{
	//�����Ϸ��Լ�⣨�����б��õ��ģ�
	if (ShuuZuTou == NULL)
	{
		cout << "ɾ��ȫ���������������\n";
		return;
	}

	//��ʽ1�����Ѵ�����Ϊ0����	���ı�������Ҳ�������ݹ�0
		/*YiCunLiang = 0;*/

	//��ʽ2��ȫ�����ݹ�0���Ѵ�����Ϊ0�����ı�����
		/*memset(ShuuZuTou, 0, sizeof(int)*YiCunLiang);
		YiCunLiang = 0;*/

	//��ʽ3���ͷŵ����������ȫ����գ�ʹָ��ΪNULL
	YiCunLiang = 0;
	ZongCunLiang = 0;
	delete[] ShuuZuTou;
	ShuuZuTou = NULL;		//�ĳ�C++��֮��NULLָ��͵����޷������ˣ���ΪShuuZuTouֻ��һ���������NULL��Ҫ��������ռ����

	//�����ֶ����ԣ���1�ָ���Ч��������Ҳ��������ģ����������Ƿ��ͷ�
}

//ɾ���м�
void DongShuZu::ShanChuZhongJian(unsigned int DiJiGe)
{
	//��������Ϸ��Լ��
	if (ShuuZuTou == NULL || DiJiGe > YiCunLiang)		//�������������ΪNULL�ļ��
	{																//����ɾ����������Ӳ�������ɾ������
		cout << "ɾ���м����������Ч\n";								//���Բ�������һ����Ҫ���⴦��
		return;
	}

	//����Ҫɾ����λ�ú����������ǰ��
	for (unsigned int i = DiJiGe - 1; i < YiCunLiang - 1; i++)
	{
		ShuuZuTou[i] = ShuuZuTou[i + 1];				//�߽������ȳ���д���Ժ��������ԣ����˷�ʱ��
	}																//i���±꣬����ֻ���ƶ����±�Ϊi+1���������±�Ϊi+1�������Ѵ�����λ��
																	//i+1 = Y-1 ����������±���ͬ������i < Y-1û���⣬�պõ��߽磬ע��߽粻Ҫ��
	//�Ѵ���-1
	YiCunLiang--;

}