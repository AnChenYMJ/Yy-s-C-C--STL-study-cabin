#include <stdio.h>
#include <stdlib.h>

//ö�ٵĶ���  enum�ǹؼ���  color������ enum_blue����enum��Ϊ����������ʱ֪����ö��
enum color{enum_blue, enum_white, enum_yellow, enum_green, enum_black, enum_red};
//ö�پ��������ֵ�int���͵ĳ�������������Ϊ�˷����ʶ����߿ɶ���
//�������Ա��0123������������ֱ��ʹ�����֣����˻��Լ�էһ����֪����������Ǵ���ʲô
//��ö�ٸ�����������֣����Ǿ�֪��������ʲô��


//����û���ֵ�ö��  //ϵͳĬ�ϴ�0��ʼ���ӣ�����012345
enum { enum_blue1, enum_white1, enum_yellow1, enum_green1, enum_black1, enum_red1 };
//һ��Ҫע�⣬�� enum_blue1��Щ���Ǳ�������int���͵ĳ�����


//���ǿ���ָ��ö�ٵķ�Χ������ʹ�50��ʼ���ӣ�50��51��52��53��54��55
enum { enum_blue2 = 50, enum_white2, enum_yellow2, enum_green2, enum_black2, enum_red2 };


//������м�ָ�����Ǿͱ���ˣ�0��1��10��11��12��13
enum { enum_blue3, enum_white3, enum_yellow3 = 10, enum_green3, enum_black3, enum_red3 };


//����Ҳ����ÿ����ָ��
enum { enum_blue4 = 58, enum_white4 = 88, enum_yellow4 = 98, enum_green4 = 48, enum_black4 = 56, enum_red4 = 23 };
//

int main(void)
{					//������ͨ��enum_blue��ӡ��0����0��ӡ����enum_blue
	printf("%d, %d, %d, %d, %d, %d \n", enum_blue, enum_white, enum_yellow, enum_green, enum_black, enum_red);
					//Ҫע�⣬ÿ��ö�ٵ�����ֻ�ܴ���һ��
	system("pause");
	return 0;
}