#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

int main(void)
{
	int* p = (int*)malloc(sizeof(int) * 5);

	size_t a = _msize(p);//新函数，_msize（）表达出小括号里参数的空间大小

	printf("%d \n", a);



	//申请完新空间后，跟malloc一样也会返回一个地址	，
	//如果原本空间所在的空闲内存碎片大小支持修改后的空间，则返回的地址不变
	//如果原本所在的内存空间不足拓展，则会寻找另一块足够大的新内存作为新空间，返回的地址就会改变
	//所以往往用新参数作为新返回地址的指针，
	int* p1 = (int*)realloc(p, 40);//realloc（ ，）括号里第一个参数是要修改的空间名称，
									//后一位参数是希望改成的空间的大小
	if (NULL == p1)		//与malloc一样，不要越界
	{				//为了防止拓展的空间超出内存能给的上限，返回NULL（0值），要加上if判断
		//特殊处理
	}
	size_t b = _msize(p);

	printf("%d \n", b);

	free(p); //注意即时释放内存

	system("pause");
	return 0;
}