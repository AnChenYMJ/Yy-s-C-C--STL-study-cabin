#include <stdio.h>
#include <stdlib.h>

//枚举的定义  enum是关键字  color是名字 enum_blue加上enum是为了我们引用时知道是枚举
enum color{enum_blue, enum_white, enum_yellow, enum_green, enum_black, enum_red};
//枚举就是有名字的int类型的常量，起名字是为了方便标识，提高可读性
//比如程序员用0123代表东南西北，直接使用数字，别人或自己乍一看不知道这个数字是代表什么
//用枚举给常量起个名字，我们就知道它代表什么了


//这是没名字的枚举  //系统默认从0开始增加，就是012345
enum { enum_blue1, enum_white1, enum_yellow1, enum_green1, enum_black1, enum_red1 };
//一定要注意，如 enum_blue1这些不是变量，是int类型的常数，


//我们可以指定枚举的范围，这里就从50开始增加：50，51，52，53，54，55
enum { enum_blue2 = 50, enum_white2, enum_yellow2, enum_green2, enum_black2, enum_red2 };


//这里从中间指定，那就变成了：0，1，10，11，12，13
enum { enum_blue3, enum_white3, enum_yellow3 = 10, enum_green3, enum_black3, enum_red3 };


//我们也可以每个都指定
enum { enum_blue4 = 58, enum_white4 = 88, enum_yellow4 = 98, enum_green4 = 48, enum_black4 = 56, enum_red4 = 23 };
//

int main(void)
{					//我们能通过enum_blue打印出0，但0打印不出enum_blue
	printf("%d, %d, %d, %d, %d, %d \n", enum_blue, enum_white, enum_yellow, enum_green, enum_black, enum_red);
					//要注意，每个枚举的名字只能存在一次
	system("pause");
	return 0;
}