#include<stdio.h>

int *test()
{
    int a = 10;
    return &a;
}
int main()
{
    //编号-地址-指针(kno5) 地址存起来要有变量，变量存放地址/指针，称为指针变量
    int aa = 10; //a占4个字节
    int * ch = &aa; //拿到的是aa的4个字节的第一个字节
    //指针的大小在32位平台是4个字节，在64位平台是8个字节
    *ch = 20; //通过ch修改aa的值

    //指针和指针类型
    int * pa;
    char * pc;
    double * pd;
    float * pf;
    printf("%d\n", sizeof(pa));//8
    printf("%d\n", sizeof(pc));
    printf("%d\n", sizeof(pd));
    printf("%d\n", sizeof(pf));
    //既然都是8，那么指针类型有什么用

    //指针类型的意义

    //1.指针类型决定了：指针解引用的权限有多大
    //一个16进制位是4个二进制位 0 1 2 3 4 5 6 7 8 9 a b c d e f
    //1111 1111
    //     8421 -> 15 f
    int a = 0x11223344;
    int * p = &a;
    *p = 0; //a = 0 0 0 0

    int b = 0x11223344;
    char * pp = &b;
    *pp = 0;//b = 0 ~ ~ ~ ~
    
    //2.指针类型决定了：指针的移动单位是多大(步长)
    int arr[10] = {0};
    int * parr = arr;
    char * pchar = arr;

    printf("%p\n", parr); //C0 跳过一个整型 4个字节 double 8个字节
    printf("%p\n", parr + 1); //C4

    printf("%p\n", pchar); //C0 跳过一个字符型 1个字节
    printf("%p\n", pchar + 1); //C1

    int arr1[10] = {0};
    int * parr1 = arr1;
    int i = 0;
    for(i = 0; i < 10; i++)
    {
        *(parr1 + i) = 1;//char访问一个字节
    }

    //野指针：指针指向的位置是不可知的

    //1.指针没有初始化
    int * p1; //p1是一个局部的指针变量，局部变量不初始化的话，默认是随机值
    //*p1 = 10; //非法访问内存了(没有申请是不可以随便访问的)

    //2.指针越界访问
    /*
    int arr2[10] = {0}; //10
    int * parr2 = arr2;
    int i = 0;
    for(i = 0; i < 10; i++) //11次循环
    {
        *parr2 = i;//越界访问
        parr2++;
    }
    */

    //3.指针指向的空间释放
    /*      a = 10(0x11223344)
    int * p2 = test();      //p2 = 0x11223344 a释放
    *p2 = 20; //非法访问内存了(已经释放了)
    */

   //如何规避野指针
    //1.指针初始化
    //当前不知道p应该初始化为什么地址的时候，直接初始化为NULL
    int * p3 = NULL; //NULL是一个宏，是一个整型常量，值为0
    //明确知道初始化的值
    int a1 = 10;
    int * p4 = &a1;

    //2.小心越界(c语言本身是不会检查数据的越界行为)
    //3.指针指向的空间释放及时置NULL
    int * p5 = NULL;
    //*p5 = 10; 但是即使设置为NULL，也是非法访问内存了
    //4.指针使用之前检查有效性
    if(p5 != NULL)
    {
        *p5 = 10;
    }

    return 0;
}