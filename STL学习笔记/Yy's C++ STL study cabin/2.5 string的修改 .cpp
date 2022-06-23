#include <iostream>
using namespace std;

//���
void StrOut()
{
//����������<< ����
	string stc("Don't be afraid! GO the distance!");
	cout << stc << endl;			//string�������������

//����������c_str()������ԭ��					//�еı�����û��<<���أ�������c_strҪ��ͨ��һЩ
	cout << stc.c_str() << endl;	//c_str()�ǽ��ַ������Ƶ���һ���ռ��У�Ȼ�󷵻��¿ռ�ĵ�ַ�������Ⲣ����ԭ�����ַ����ռ�


//string������±�����				//ָ������ַ�����һ���ַ�
	cout << stc[12] << endl;		//�����ǲ������±�������ģ����������������±������[]
									//��Խ�����ʱ�����л�����������˼�д�ĺð���

//at()����	//at()��������һ�����ã�ָ����indexλ�õ��ַ�
	cout << stc.at(12) << endl;
									
	try								//��index������Χ����Խ�����ʱ�������쳣��ʾ"out of range"����
	{
		cout << stc.at(36) << endl;	// ���׳�out_of_range�쳣
	}
	catch (out_of_range)			//���ֲ�֪���쳣��������out_of_range//�ò������ö����ԣ�����ֱ��дout_of_range
	{
		cout << "at��������Խ������ˣ�" << endl;
	}
	
}

//�޸�
void Strchange()
{
	string go("Don't be afraid! Yy. Go the distance.");
	string yes("You are strong!");

//�޸�ָ��Ԫ��
{
	//[]�±������޸�
	go[18] = 'Y';
	cout << go << endl;

	//at()�޸�					//at():����ָ��λ�õ�����
	go.at(18) = 'y';
	cout << go.c_str() << endl;	//c_str()�ǽ�ԭ�ַ����ռ临�Ƶ�һ���¿ռ��У��ٷ����¿ռ�ĵ�ַ
}

//insert�м�����ַ�				//����0��ʼ������			//insert: ��		����Ŷ��
{
	//�м�������
	go.insert(20, yes);			//�ڵ�20���ַ���index����ǰ�濪ʼ���루��0��ʼ������
	cout << go << endl;

	//indexλ��ǰ�����һ���ַ���
	go.insert(20, "is't be OK. ");
	cout << go << endl;			//�ڵ�20���ַ���ǰ�����һ���ַ�������0��ʼ������

	//index1λ��ǰ�������һ�������ĳһ���ַ���
	go.insert(47, yes, 8, 15);	//�ڵ�47���ַ�ǰ�棬������һ������ĵ�8���ַ�~14�ַ�����15�ַ���ǰ�棩����0��ʼ������
	cout << go << endl;

	//indexλ��ǰ������ַ�����ǰ�����ַ�		
	go.insert(55, "Don't be afraid! ", 17);
	cout << go << endl;			//��55���ַ�ǰ����0��ʼ�����������ַ�����ǰ17���ַ�

	//indexλ��ǰ�����num��ch
	go.insert(55, 6, 'a');
	cout << go << endl;

	//insertʵ��β������			//������ʵ��ͷ�����룬ƴ�ӵ�
	go.insert(go.length(), 6, 'a');//length()�����ַ�������
	cout << go << endl;			//��β��������6��a
}

//β�Ͳ��� +=ƴ��  ��  appendƴ��
{
	string go("Don't be afraid! Yy. Go the distance.");
	string yes("You are strong!");

	//+= ƴ��
	go += yes;			//ƴ�Ӷ���
	go += "keep going.";//ƴ���ַ���
	cout << go << endl;


	//appendƴ��
		//β��ƴ��һ������
	go.append(yes);
	cout << go << endl;

	//β��ƴ��һ���ַ���
	go.append(" Don't be worry.");
	cout << go << endl;

	//β��ƴ��һ�������ĳһ��
	go.append(yes, 8, 15);
	cout << go << endl;

	//β��ƴ���ַ���ǰ����
	go.append("keep going! Yy.", 11);
	cout << go << endl;

	//β��ƴ��num��ch
	yes.append(5, 'h');
	cout << yes << endl;
}


//���¸�ֵ =��ֵ  ��  >>���븳ֵ  ��  assign��ֵ
{
	string go("Don't be afraid! Yy. Go the distance.");
	string yes("You are strong!");

// = ��ֵ
	go = yes;				//����ֵ
	cout << go << endl;
	go = "Don't be worry.";	//�ַ�����ֵ
	cout << go << endl;

//>>���븳ֵ
	/*cin >> go;
	cout << go << endl;*/

//assign��ֵ
	//����ֵ
	go.assign(yes);
	cout << go << endl;

	//�ַ�����ֵ
	go.assign("lie.");
	cout << go << endl;

	//����ĳһ�θ�ֵ
	go.assign(yes, 8, 15);
	cout << go << endl;

	//�ַ���ǰ�����ַ���ֵ
	go.assign("your are lie.", 12);
	cout << go << endl;

	//num��ch��ֵ
	go.assign(6, 'o');
	cout << go << endl;
}

//ɾ��ָ��λ���ַ�
{
	string go("Don't be afraid! Yy. Go the distance.");
	string yes("You are strong!");

	//ɾ��ָ��λ�ã�ָ������
	go.erase(17, 4);		//��17���ַ���ɾ��4���ַ�����1��ʼ��
	cout << go << endl;

	//ɾ����������
	go.erase(0, go.length());//��0���ַ���ɾ���ַ������ȵ����ݣ��൱�����
	cout << go << endl;
}

}

int main()		//ע����ͬ������֮��ֻ��Դ�ļ���ͷ�ļ���ͨ����Ҫ��ֲ���Ͱ�����ͷ�ļ���Դ�ļ���ֲ��ȥ
{
	Strchange();//ͨ���Աȷ���
				//insert ����  ��  appendƴ��  ��  assign��ֵ
				//��·������ͬ�������ݲ�����£�
				//1.����֮��
				//2.�ַ���
				//3.����ĳһ��
				//4.�ַ���ǰ����
				//5.num��ch



	system("pause");
	return 0;
}