#include <iostream>
using namespace std;

class CStu
{
public:
	CStu()
	{
		cout << "���캯��" << endl;
	}

	~CStu()
	{
		cout << "��������" << endl;
	}

};

int main()
{
	//CStu st;//���캯�����������������Զ�����

	//CStu* ft = new CStu;
	//delete ft;//new�Ķ���ռ�ֻ��delete�ͷ�ʱ�Ż������������
	//free (ft);//free�ͷſռ䲻�������������

	//CStu* rt = malloc (sizeof(CStu));//: �޷��ӡ�void *��ת��Ϊ��CStu *��,��Ϊmalloc���صĵ�ַ��ͨ�õĵ�ַ
	CStu* rt = (CStu *)malloc(sizeof(CStu));//������Ҫǿתָ������
	//delete rt;//���Է��֣�malloc�Ķ���ռ乹���ǲ��ᴥ�����캯����
				//��delete�ͷſռ��ǿ��Դ�������������
	free (rt);	//��free�ͷſռ䲻�ᴥ����������

	system("pause");
	return 0;
}