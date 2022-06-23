//#include <stdio.h>
//#include <stdlib.h>
//#include <stdarg.h> //va_语句的头文件  //不加头文件会提示：“va_start”未定义；假设外部返回 int
//
//
//	//这里的int a是参数的个数，后面接...，这就是参数不确定的函数的函数头
//void fun(int a, ...)
//{
//	va_list ap; //这个函数的作用是声明一个参数数组，就是声明一个装参数的数组空间
//	va_start(ap, a);  //这个函数的作用是将参数装入数组空间，a是参数个数，ap是数组名
//	printf("%d \n", va_arg(ap, int));  //va_arg的作用是取参数，将参数按顺序取出来
//	printf("%.3lf \n", va_arg(ap, double));//当执行完第一个va_arg，取完的那个数就不再取了
//	printf("%d \n", va_arg(ap, int));	//执行第二个第三个va_arg时就是按顺序取第二个第三个参数
//	printf("%lf \n", va_arg(ap, double));//注意类型与顺序要与参数对应上，测试的时候错了一个，后面的也会跟着错
//	//printf("%f \n", va_arg(ap, float)); //不知道为什么不能输出float类型的：答案如下
//	// 变参函数调用时，float会提升至double。所以不要在va_arg中使用float类型
//
//	//这个问题问的很经典，非常有代表性，印象中《C陷阱与缺陷》里面有涉及到。
//	/*简单的说，用va_arg(ap, type)取出一个参数的时候，
//		type绝对不能为以下类型：
//		char、signed char、unsigned char
//		short、unsigned short
//		signed short、short int、signed short int、unsigned short int
//		float
//
//		原因是会对每个参数执行“默认实际参数提升(default argument promotions)”机制，
//		char、short和相应的signed、unsigned类型的实际参数提升到int
//		如果int不能存储原值，则提升到unsigned int
//		float类型的实际参数将提升到double*/
//	
//}
//
//
//int main(void)
//{	//这里第一个数是函数参数的个数
//	fun(4, 98, 52.052, 65, 654.3221);
//	printf("%d %lf %d \n", 12, 56.2354, 123);//如果后面给的数少于前面定义的数，则会补一个不知道哪来的数值
//	//如果后面给的数个数超出前面定义的个数，则会有警告，提示传递参数（内建函数也是函数也叫参数）太多，但运行正常
//	//这里的打印就跟参数不确定函数头类似，前面多少个%d或%lf，是确定数的多少与类型
//
//	system("pause");
//	return 0;
//}

////另提示知识点：[]的三种用法：1.作为声明数组类型的形式 
////2.作为在自定义函数的有参数时数组做参数时表示指针的形式（可见函数数组做参数.c）
////3.地址+[]:表示下标运算