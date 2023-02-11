//数组：一组相同类型元素的集合
//一维数组的创建和初始化
// type_t array_name[const_n];
// 数组的元素类型 数组名 [常量表达式](数组的大小)
#include <stdio.h>
#include <string.h>
int main()
{
    int a = 10;//初始化
    int arr[10] = { 0 }; //数组的初始化
    int arr1[10] = { 1,2,3,4,5,6,7,8,9,10 };//完全初始化
    int arr2[10] = { 1,2,3,4,5 };//不完全初始化

    int n=8;
    int arr3[n]; //变量不能作为数组的大小
    //C99语法支持变长数组-数组的大小是变量，但是不能初始化
    //gcc-对C99的支持的比较好
    
    int arr4[] = { 1,2,3,4,5,6,7,8,9,10 }; //=arr4[10]
    
    char ch1[5] = {'a','b','c'}; //[3]:0 '\0'
    char ch2[] = {'a','b','c'};//=ch2[3]
    char ch3[5] = "abc";// a b c \0 0(\0)
    char ch4[] = "abc";// a b c \0 (4个元素)
// \0是字符数组里的东西，整型数组里没有\0
    printf("%s\n", ch2); //abc(后面未知)所以会有随机值
    printf("%s\n", ch4); //abc

    printf("%d\n", strlen(ch2)); //随机值
    printf("%d\n", strlen(ch4)); //3

    int arr5[10] = { 0 };
    arr5[4] = 5; //[] - 下标引用操作符
    printf("%d\n", arr5[4]); //5

    int i = 0;
    printf("%d\n",sizeof(arr5)); //40
    printf("%d\n",sizeof(arr5[0])); //4
    int sz = sizeof(arr5) / sizeof(arr5[0]);
    for (i = 0; i < sz; i++)
    {
        printf("%d ", arr5[i]);
        //这里是访问数组元素，不是创建数组，创建数组[]里一定是常量
    }

    //一维数组在内存中的存储
    //%p - 按地址的格式打印 - 16进制
    printf("%x\n", 0x12); //16进制-12
    printf("%p\n", 0x12); //0000 0012
    //一个16进制位-4个二进制位 32个二进制位-4个字节的空间大小(1字节-8bit)
    int arr6[10] = { 0 };
    int m = 0;
    for (m = 0; m < 10; m++)
    {
        printf("&arr[%d] = %p\n",m, &arr6[m]);//相差四->一个整型四个字节
    } // 0-9 a(10) b(11) c(12) d(13) e(14) f(15)

    //一维数组在内存中是连续存放的
    //随着数组下标的增长，地址是由低到高变化的

    int arr7[10] = {1,2,3,4,5,6,7,8,9,10};
    int* p = arr7; //数组名是数组首元素的地址
    //int* p = &arr7[0];
    int b = 0;
    for (b = 0; b < 10; b++)
    {
        printf("%d ", *p);
        p++; //整型指针加一跳一个整型
    }

    return 0;
}