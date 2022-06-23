#include <stdio.h>
#include <stdlib.h>

enum color{ enum_blue = 56, enum_white, enum_black, enum_green, enum_yellow, enum_red};


int main(void)
{
	enum color oc = enum_blue;//这就是声明了一个枚举变量，实际就是一个整型变量
	printf("%d \n\n", oc);

	oc = 89;  //完全可以当作int类型的变量使用
	printf("%d \n\n", oc);//理论上应赋值枚举里起了名字的数字，但实际上赋值别的数也没问题

	int a = enum_white;//同上，普通变量也能被赋值枚举里的起了名字的数
	printf("%d \n\n", a);


	printf("a = %d\nenum_blue = %d\nenum color = %d\n\n", sizeof(a), sizeof(enum_blue), sizeof(enum color));
	//会发现都是4字节大小，enum color可以看作类似int一样的类型，int类型大小为4字节
	//而枚举本质就是int，那枚举的类型也是4字节，只是枚举类型表现形式是：enum color
	system("pause");
	return 0;
}