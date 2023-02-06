// 指针就是地址
//内存 属于 空间  内存分许多格子 格子有编号
// 32(64)位—— 32根地址线 —— 物理线 —— 通电 —— 0/1(负/正)
//电信号转换成数字信息：1和0组成的二进制序列
//0000 0000 0000 0000 0000 0000 0000 0000到1111 1111 1111 1111 1111 1111 1111 1111
// 2^32 作为内存的编号 即内存单元的地址
//假设一个内存单元的大小为1bit 2^32bit = 2^29byte = 2^19KB = 2^9MB = 0.5GB
//这样的话char 八个地址 浪费 最终 一个字节一个单位


//结构体可以让C语言创建新的类型出来
//创建一个学生
struct Stu
{
    char name[20];
    int age;
    double score;
};

//创建一个书的类型
struct Book
{
    char name[20];
    double price;
    char id[30];
};

#include <stdio.h>
int main()
{
    int a = 10; //a 在内存中要分配空间 —— 4个字节
    //打印a的地址
    printf("a = %d, a的地址是%p\n", a, &a); // %p 专门打印地址
    //000000000061FE1C 地址是16进制 打印第一个字节的地址
    int * pa = &a; //pa存放地址, pa是一个指针变量 
    // * 说明pa是一个指针变量 int 说明pa执行的对象是int类型
    
    char ch = 'w';
    char * pc = &ch; //创建一个指针变量 pc, pc指向ch
    printf("ch = %c, ch的地址是%p\n", ch, &ch);

    *pa = 20; //通过pa修改a的值 解引用操作
    // *pa 就是通过pa里面的地址，找到a的值
    printf("a = %d, a的地址是%p\n", a, &a);
    // 内存存了a:10 pa:000000000061FE1C pa指向a, *pa更改a的值

    //指针变量大小
    printf("%d\n", sizeof(int*));
    printf("%d\n", sizeof(char*));
    printf("%d\n", sizeof(double*));
    printf("%d\n", sizeof(float*));
    printf("%d\n", sizeof(short*));
    printf("%d\n", sizeof(long*));
    printf("%d\n", sizeof(long long*));
    // 64位 64bit 8byte 
    
    //结构体
    struct Stu s = {"张三", 20, 85.5}; //结构体的创建和初始化
    
    printf("1:%s %d %lf\n", s.name, s.age, s.score); //结构体变量.成员变量
    
    struct Stu * ps = &s; //创建一个指针变量 ps, ps指向s
    
    printf("2:%s %d %lf\n", (*ps).name, (*ps).age, (*ps).score);
    printf("3:%s %d %lf\n", ps->name, ps->age, ps->score); //结构体指针->成员变量


    
    
    




    return 0;
}

