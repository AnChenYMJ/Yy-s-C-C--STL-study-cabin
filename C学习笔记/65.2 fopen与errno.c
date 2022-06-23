#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>


int main(void)
{

	FILE* pfile = NULL;
	errno_t a = fopen_s(&pfile, "65.2 测试.txt", "r");//我们把文件删除用r测试下返回的错误码
	//截断调试，得到a的返回值是2，我们通过上方：工具>错误查找>输入错误码查找，得到：系统找不到指定的文件。
			//fopen_s的功能跟fopen是一样的
	//区别，fopen：通过返回值返回文件指针
	//区别，fopen_s:通过参数1返回文件指针，它的返回值作为错误码返回
	fclose(pfile);//记得关闭保存文件，fclose的功能是：关闭并保存
	//close：关闭



	FILE* ffile = fopen("65.2 测试.txt", "r");//fopen能通过以下方式返回错误码
	if (ffile == NULL)				//我们删除文件用r测试错误码
	{
		printf("文件打开失败。");
	}
	int b = errno;		//调试截断看b的值，然后在工具的错误查找看对应的值的意思
	//这不是必须使用，是一种找错误的方式，方便我们查找错误
	fclose(ffile);//记得关闭保存文件，fclose的功能是：关闭并保存
	//close：关闭


	system("pause");
	return 0;
}