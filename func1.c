#include <stdio.h>
#include <string.h>
// 函数分为库函数和自定义函数
// 库函数：系统提供的函数，如printf()，scanf()等
// 库函数分为IO函数(printf,scanf,getchar,putchar),字符串操作函数(strcmp,strlen)
// 字符操作函数(tolower,toupper-小写转大写),内存操作函数(memcpy,memset,memcmp),时间/日期函数(time) 数学函数(abs,pow(求次方),rand,sqrt)

int Max(int x, int y) //只有当被调用时才会给参数创建空间
{
    //函数的定义
    if (x > y)
    {
        return x;
    }
    else
    {
        return y;
    }
} //形参当函数调用完成之后自动销毁 类似生命周期


//传值调用
void Swap(int x, int y) //void表示无返回值
{ //当x=10,y=20时，实际上xy的地址不是ab的地址 被调用时，形参是实参的一份临时拷贝
    int tmp = x;
    x = y;
    y = tmp;
    //xy交换 与ab交换无关
}


//传址调用
void Swap1(int* pa, int* pb)  //形式参数-形参
{ //*pa能找到c的地址
    int tmp = *pa;
    *pa = *pb;
    *pb = tmp;
}

int main()
{
    // strcpy()函数 用于拷贝字符串 - 头文件#include<string.h>
    // char * strcpy ( char * destination, const char * source );
    // char* 函数的返回类型 strcpy 函数名 () 函数参数
    // Copy string
    // Copies the C string pointed by source into the array pointed by destination,
    // including the terminating null character (and stopping at that point).
    char arr1[20] = {0};
    char arr2[] = "hello";
    strcpy(arr1, arr2);
    printf("%s\n", arr1); //%s - 字符串

    // memset()函数 用于初始化内存 - 头文件#include<string.h>
    // memory 记忆 内存
    // void * memset ( void * ptr, int value, size_t num );
    // Fill block of memory
    // Sets the first num bytes of the block of memory pointed by ptr to the specified value (interpreted as an unsigned char).
    char arr3[] = "hello bit";
    memset(arr3, '*', 5);
    printf("%s\n", arr3);

    // 自定义函数
    // ret_type(返回类型) func_name(函数名) (para1(函数参数),*)
    //{
    //     statement//函数体
    // }


//输出较大值
    int a = 10;
    int b = 20;
    //函数的调用
    int max = Max(a, b);
    printf("max=%d\n", max);


//交换两个值
    int c = 10; //4个字节的空间
    //int* pa = &c; //pa就是一个指针变量 *pa就是c
    int d = 20;

    printf("交换前:c=%d,d=%d\n", c, d);
    Swap(c,d);// 无效 
    Swap1(&c,&d); // &c,&d 与上面的c,d均叫实际参数-实参
    //实参可以是常量，变量，表达式，函数等 至少是确定的值
    printf("交换后:c=%d,d=%d\n", c, d);

//什么时候用指针：参数值不变不用指针



    return 0;
}