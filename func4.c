//函数的递归 主要思考方式:大事化小
#include<stdio.h>
#include<string.h>

void print(unsigned int n)
{
    if(n>9) //限制条件
    {
        print(n/10); //n一直在变小，越来越接近条件
    }
    printf("%d ", n%10); //空格
}
//递归的两个必要条件
//存在限制条件，当满足这个限制条件的时候，递归便不再继续
//每次递归调用之后越来越接近这个限制条件。

void test(int n)
{
    if(n<10000)
    {
        test(n+1);
    }
}

int my_strlen(char* str) //计算长度是个整型
{ //指针指的是第一个元素的地址
    if(*str != '\0')
    {
        return 1 + my_strlen(str+1); //用str++,++str都会有副作用：改变了str的值
    }
    else
    {
        return 0;
    }
}

int my_strlen2(char*str) //创建了临时变量
{
    int count = 0;
    while (*str != '\0')
    {
        count++;
        str++;
    }
    return count;
}

int Fac(int n)
{
    if(n<=1)
        return 1;
    else
        return n*Fac(n-1);
}

int count = 0;
int Fib(int n)
{
    if (n==3) //统计第三个斐波那契数的计算次数
        count++;
    if(n<=2)
        return 1;
    else
        return Fib(n-1)+Fib(n-2);
}

int Fib2(int n)
{
    int f1 = 1;
    int f2 = 1;
    int f3 = 1;
    while(n>2)
    {
        f3 = f1+f2;
        f1 = f2;
        f2 = f3;
        n--;
    }
    return f3;
}
int main()
{
    //最简单的递归 Stack overflow 栈溢出
    //printf("hehe\n");
    //main();

    //练习一 接受一个整型值(无符号)，按照顺序打印，eg:1233->1 2 3 4
    unsigned int num = 0;
    scanf("%u", &num);
    //递归 - 函数自己调用自己
    print(num); //print 函数可以打印参数部分数字的每一位

    //test(1); //栈溢出 - 内存的栈区空间不够用了(栈区分给main的栈帧空间(局部变量)，函数空间)
    //写递归:1.不能死递归，都有跳出条件，每次递归逼近跳出条件
    //2.递归层次不能太深


    //练习二：编写函数不允许创建临时变量，求字符串的长度
    char arr[] = "bit"; // ['a'] ['b'] ['c'] ['\0']
    //模拟实现一个strlen函数
    printf("%d\n", my_strlen2(arr));
    printf("%d\n", my_strlen(arr));

    printf("%d\n",strlen(arr));

    //递归与迭代(循环是迭代的一种):有一些功能均可以用递归和迭代实现
    //练习三：n的阶乘(不考虑溢出)
    int m = 0;
    scanf("%d", &m);
    int ret = Fac(m);
    printf("%d\n", ret);

    //练习四：求第n个斐波那契数(不考虑溢出)
    //1 1 2 3 5 8 13 21 34 55 前两个数之和等于第三个数
    int a = 0;
    scanf("%d", &a);

    int ret3 = Fib2(a);
    printf("%d\n",ret3); //50-出来的很快，但是结果错误

    int ret2 = Fib(a);
    printf("%d\n", ret2);
    //如果填50 结果出来的很慢 因为效率低 重复大量的计算
    //二叉树 50(49(48,47),48(47,46)....) 2^49
    printf("%d\n", count); //40-102334155-3908816912
    
    //汉诺塔-A(三个依次变大的盘子) B C-一次移动一个 A移到C
    //青蛙跳台阶-一次跳一级或者两级-跳上n级台阶有多少种跳法(斐波那契数列问题)
    


    
    
    return 0;
}