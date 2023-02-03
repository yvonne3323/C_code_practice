#include <stdio.h>

#define ADD(x,y) x+y
#define ADD2(x,y) ((x)+(y))

typedef unsigned int u_int;// 类型重命名

void test()
{
    static int f = 1; 
    //f 是局部变量，原来出函数f就会销毁，现在有static f 不会销毁，只会初始化一次
    f++;
    printf("%d",f);
}

int main()
{
    // 关键字 不能使用于变量名

    // int int = 10;

    int a = 10; // 自动创建 自动销毁的 自动变量
    // auto 省略掉了

    // register 寄存器变量
    //register int b = 20; // 建议b的值放在寄存器中
    // 计算机中 数据可以存放在 网盘(2T 免费的) 硬盘(500G 买的) 内存(8~16G) 高速缓存(几十MB) 寄存器
    // 越到后面，空间越小，速度越快，价格越贵 
    // CPU 中央处理器 数据处理 cpu速度变快 内存读取数据一般
    // 现在 cpu读取寄存器，寄存器从高速缓存读取，高速缓存从内存读取 效率高
    // cpu 寄存器没有就去高速缓存，高速缓存没有就去内存
    // 大量使用的数据 想放在寄存器中 提升效率，现在编译器会选择放入寄存器


    // signed 有符号的 unsigned 无符号的  union 联合体(共用体) void 空的 volatile 易变的
    unsigned int c = 30;
    u_int d = 40; 

    //define include 预处理指令 非关键字

    //static 静态的
    // 1. 修饰局部变量 改变了局部变量的生命周期(本质上是改变了变量的存储类型)
    //内存划为三个区域：栈区(局部变量，函数参数)，静态区(全局变量，static修饰的静态变量)，堆区(动态内存分配) 

    int e = 0;
    while (e<10)
    {
        test();
        e++;
    } // 没有static,打印10个2

    // 2. 修饰全局变量
    // 使得全局变量只能在自己所在的源文件内部使用，extern没有用
    // 全局变量 在其他源文件内部可以被使用，是因为全局变量具有外部链接属性，但是被static 修饰之后，就变成了内部链接属性 
    
    // 3. 修饰函数 使得函数只能在自己所在的源文件内部使用，extern没有用 本质上是改变了函数的链接属性(和全局变量一样)
    //外面写 extern int Add(int x,int y); 可以用函数
    //如果函数前加了static，就只能在本文件中使用，外面就不能用了
    int f1 = 10;
    int f2 = 20;
    //int sum = Add(f1,f2);
    //printf("%d",sum);

    //define 
    // 1. 定义符号常量
    // 2. 定义宏
    printf("%d",4*ADD(2,3)); // 4*2+3 只是替代了，没有做运算
    printf("%d",4*ADD2(2+3,3)); // 4*((2+3)+3)

    
    return 0;
}