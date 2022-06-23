#include <iostream>
#include <vector>
using namespace std;

void STLCapacity()
{
	//������������
	vector<int> vec1;
	vector<int> vec2(7);
	vector<int> vec3(3);

//���Գ�ʼ�������������仯����
{
	//��ӡ��ʼ������С
	cout << vec1.capacity() << endl;		//0		//û�в�����û��Ԫ��Ҳû�пռ�
	cout << vec2.capacity() << endl;		//7
	cout << vec3.capacity() << endl;		//3
	//���ֳ�ʼ�������ݳ�ʼ���Ĳ�����������ʼ������Ԫ�أ����ж��ٿռ䣬û�в�����û�пռ䡣
	//��string�ĳ�ʼ������һ����string��ʼ��������15.


	//���±��������Ԫ��
	{
		//cout << vec1[0] << endl;				//�����ˣ��±�����ֻ��Դ��ڵ�Ԫ�أ������ڵ�Ԫ�ز����������

		vec2[3] = 88;
		cout << vec2[3] << endl;				//�ɹ�����

		//cout << vec3[3] << endl;				//Խ����ʲ������±�����
	}
	
	//push_back()��β�����һ��Ԫ�أ������������鿴�����仯����
	{
		vec1.push_back(1);						//push_back()���ֵΪval��Ԫ�ص���ǰvectorĩβ����ֻ���һ��Ԫ��

		cout << vec1.capacity() << endl;		//1		//��0����1��

		vec1.push_back(1);
		cout << vec1.capacity() << endl;		//2		//��1����1��

		vec1.push_back(1);
		cout << vec1.capacity() << endl;		//3		//��2���� 2/2 == 1��

		vec1.push_back(1);
		cout << vec1.capacity() << endl;		//4		//��3���� 3/2 == 1�� 

		vec1.push_back(1);
		cout << vec1.capacity() << endl;		//6		��4����	  4/2 == 2��

		vec1.push_back(1);
		vec1.push_back(1);
		cout << vec1.capacity() << endl;		//9		//��6���� 6/2 == 3��

		vec1.push_back(1);
		vec1.push_back(100);//push_back������β�����һ��ֵΪ100��Ԫ��
		vec1.push_back(1);
		cout << vec1.capacity() << endl;		//13	��9����  9/2 == 4��

		//vectorû�й̶��ĳ�ʼ�ռ䣬��ʼ�����٣��Ͷ��ռ䡣
		//�ɴ˿ɼ�����VS2019��2005����ʦ��Ƶ���У�vector�������ʱ�����ӵĿռ��ǵ�ǰ����ֵ��һ��
		//VC6.0�� �������������ֵΪ��ǰֵ��2����5 -> 10 -> 20 - >40
		//VC��win8��win10�ﲻ̫���ݣ�����ֱ�����У������ȱ��룬�����������⡣��win7�е������еúܺ�

	}

	//reserve�޸�������С
	{
		vec2.reserve(6);
		cout << vec2.size()		<< endl;		//7
		cout << vec2.capacity() << endl;		//7

		vec2.reserve(8);
		cout << vec2.size()		<< endl;		//7
		cout << vec2.capacity() << endl;		//8		//vector��reserve�����ı仯������string��һ��

		vec2.reserve(15);
		cout << vec2.size()		<< endl;		//7
		cout << vec2.capacity() << endl;		//15	//vector��reserve�Ǳ�ɶ��پ��Ƕ���

		//���ϲ��Կɼ���reserve����ֻ�ܽ�������󣬲��ܱ�С��
		//�Ҳ���ı�Ԫ�صĸ�����
		//vector��reserve�Ǳ�ɶ��پ��Ƕ��٣�������Ԥ���ռ䡣
		//string�ǻ���Ԥ���ռ䣬���Ԥ���ռ�֮�󣬰�һ���ռ䵥λ���ӣ�VSΪ16����

		//ע��㣺��ͬ�����ı仯�����ǲ�һ���ġ�
		//������Щ�仯���ɻ��Ǿ����Ŀ��㡣

	}

	//������ʧЧ
	{
		vector<int>::iterator ite = vec3.begin();
		ite[1] = 99;
		cout << vec3[1] << endl;
		cout << vec3.capacity() << endl;	//3

		vec3.insert(ite+1, 56);				//��ʱ������ֵΪ56��Ԫ�أ����������˿ռ�
		cout << vec3.capacity() << endl;	//4
		//cout << ite[1] << endl;			//������ʧЧ�����쳣���쳣�Ļ������ǿ��Դ���Ҳ���Թ��˵���

		//��������ռ�ʱ��ָ��ԭ�ռ�ĵ������ͻ�ʧЧ
	}

	//resize�ı�Ԫ�ظ���
	{
		vec3.resize(2);
		cout << vec3.size() << ' ' << vec3.capacity() << endl;	//2 4

		vec3.resize(4);
		cout << vec3.size() << ' ' << vec3.capacity() << endl;	//4 4

		vec3.resize(7);
		cout << vec3.size() << ' ' << vec3.capacity() << endl;	//7 7	//�μ�5��˵��

		vec3.resize(8); 
		cout << vec3.size() << ' ' << vec3.capacity() << endl;	//8 10

		vec3.resize(11);
		cout << vec3.size() << ' ' << vec3.capacity() << endl;	//11 15

		vec3.resize(25);
		cout << vec3.size() << ' ' << vec3.capacity() << endl;	//25 25	//�μ�5��˵��

		//1.����������Կɹ۲⵽
		//2.�ı�Ԫ�ش�С���Ǹı�������С��
		//3.��������Χ�ڣ��޸�Ԫ�ظ��������޸�������С��
		//4.��Ԫ�ظ����������ʱ���ᰴ��vector�������仯�������仯�������ӵ�ǰ����ֵ��һ��.
		//5.�������������һ�εı仯����ʱ��Ԫ�ظı�ɶ��٣������ͱ�Ϊ���٣����ᰴ�չ��ɱ仯��
	}

	//empty�����鿴�Ƿ���Ԫ��	//��Ԫ�ط���0	��Ԫ�ط���1
	{
		vector<int> vec4;				//��Ԫ�ض���

		cout << vec3.empty() << endl;	//��Ԫ�ط���0

		cout << vec4.empty() << endl;	//��Ԫ�ط���1
	}
}
}

int main()
{
	STLCapacity();


	system("pause");
	return 0;
}