int main(void)         //c99标准    调试后提示：源.obj : error LNK2005: _main 已经在 main.obj 中定义
                       //单文件还是多文件，都只能有一个主函数
                       //一个项目中只能有一个主函数，不管是在源文件还是在头文件新建，只要在first yy这个项目中，就只能有一个主函数，现在  源.c中已经有一个主函数了
{
    return 0;          //0 表示程序正常结束，协议中规定就算你不写，系统也会加上去
}


int main(int argc, char* argv[])    //标准主函数，命令行
                     
{

    return 0;
}

int main()    //c++标准形式  //老版本编译器，c语言可以不加void

{

    return 0;
}



void main()    //错误的，虽然书上有但不建议写

{
 
    return 0;
}