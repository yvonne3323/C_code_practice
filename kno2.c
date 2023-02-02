//Ctrl +V  快速复制到下一行
//Ctrl +L 快速引用该行
//Ctrl + / 注释
#include<stdio.h>
#include<string.h>
int main()
{
    //字符数组 - 数组是一组相同类型的元素
    char arr[]="abcde";//字符串———用双引号括起来的一串字符
    //arr[0]='a';arr[5]='\0';
    //字符串的结束标志是\0,在计算字符串长度时不计算\0

    char arr1[]="abc";
    char arr2[]={'a','b','c'}; //dev c++中不会出现问题
    char arr3[]={'a','b','c','\0'};

    printf("%s\n",arr1);
    printf("%s\n",arr2); //没有结束标志\0 会出现乱码
    printf("%s\n",arr3);

    //字符串的长度 - 需要引用头文件string.h
    int len= strlen("abc"); //string length
    printf("%d\n",len);// \0不计算在内

    printf("%d\n",strlen(arr1));
    printf("%d\n",strlen(arr2)); //随机值
    printf("%d\n",strlen(arr3));

    //转义字符

    printf("c:\test\test.c"); // \t -> tab
    printf("c:\\test\\test.c"); // \\ -> \ 即防止解释为转义字符

    //printf("(are you ok??)"); //如果支持三字母词， ??) -> ] 
    printf("(are you ok\?\?)");// \? -> ?

    //打印'字符
    printf("%c\n",'\'');
    printf("%s\n","\"");
    printf("%s\n","'");
    
    printf("%d\n",'\130'); 
    printf("%c\n",'\130'); 
    //八进制 130 -> 十进制 88 -> X ASCII码表

    printf("%d\n",'\x41');
    printf("%c\n",'\x41');
    //十六进制 41 -> 十进制 65 -> A ASCII码表
    //ASCII 48-57 0-9 65-90 A-Z 97-122 a-z

    printf("%d\n",strlen("c:\test\328\test.c"));
    // \t 算一个字符， \32算一个字符(8进制没有数字8)

    /*
    C语言的注释风格——不支持嵌套
    */

}


