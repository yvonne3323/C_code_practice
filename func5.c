#include<stdio.h>

void test(int arr[])
{
    arr[0] = 1;
    arr[1] = 2;
}

void test1(int* p, int *p2)
{
    *p = 1;
    *p2 = 2;
}

int g_val1 = 0;
int g_val2 = 0;
void test3()
{
    g_val1 = 1;
    g_val2 = 2;
}

void print_table(int num)
{
    int g = 0;
    int h = 0;
    for (g = 1; g <= num; g++) //行
    {
        for (h = 1; h <= g; h++)
        { //打印一行
            printf("%d*%d=%-2d ", h, g, h*g);
        }
        printf("\n");
    }
}

int main()
{
    //条件表达式的执行次数总是比循环体的执行次数多一次
    int i = 0;
    //0-9 10 判断11次，循环10次
    for (i = 0; i < 10; i++)
    {
        printf("i = %d", i);
    }
    //1.编写程序数一下1-100的所有整数中出现多少个数字9
    // 9 19 29 39 49 59 69 79 89 99 
    //91 92 93 94 95 96 97 98 99
    int count = 0;
    int m = 0;
    for (m = 1; m <= 100; m++)
    {
        if (m % 10 == 9)
            count++;
        if (m / 10 == 9)
            count++;
    } //99算了两次，但本身有两个9，所以没有问题
    //用|| 99算一次
    printf("count = %d\n", count);


    //2.计算1/1-1/2+1/3-1/4+1/5......+1/99-1/100的值
    //方法一
    int n = 0;
    double sum = 0.0; //结果才会可以出现小数
    int flag = 1;
    for (n = 1; n <= 100; n++)
    {
        sum += flag * 1.0 / n; // 两整数数相除，结果为整数
        flag = -flag;
    }
    printf("sum = %lf\n", sum);

    //方法二
    int a = 0;
    double sum1 = 0.0;
    for (a = 1; a <= 100; a++)
    {
        if (a % 2 == 0)
            sum1 -= 1.0 / a;
        else
            sum1 += 1.0 / a;
    }
    printf("sum1 = %lf\n", sum1);

    //3.求十个整数中最大值
    int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
    int max = arr[0]; //不能写int max = 0;因为数组中可能有负数(结果会为0)
    int b = 0;
    for(b = 0; b < 10; b++)
    {
        if (arr[b] > max)
            max = arr[b];
    }
    printf("max = %d\n", max);

    //4.输出乘法口诀表
    //1*1=1
    //1*2=2 2*2=4
    //1*3=3 2*3=6 3*3=9
    int c = 0;
    int d = 0;
    for (c = 1; c <= 9; c++)
    {
        for (d = 1; d <= c; d++) //行数
        {
            printf("%d*%d=%-2d ", d, c, d*c);//对齐写2d(两格),-2d左对齐
        }
        printf("\n");
    }

    //设计函数时，尽量做到谁申请的资源就由谁来释放
    //函数可以没有参数 main() 

    //函数处理结果的两个数据返回给主函数
    //A.return这两个数: 不可以：因为return只能返回一个数
    //B.形参用数组
    int arr1[10] = { 0 };
    test(arr1);
    //C.形参用指针
    int e = 0;
    int f = 0;
    test1(&e, &f);
    //D.用两个全局变量(不建议) 全局变量声明：int g_val1 = 0;->int g_val1;
    test3();

    //逗号表达式
    //exec((v1,v2),(v3,v4),v5,v6);=>exec(v2,v4,v5,v6); 四个实参

    //5.输入12,输出12*12的乘法口诀表
    //方法一
    int g = 0;
    int h = 0;
    int num = 0;
    scanf("%d", &num);
    for (g = 1; g <= num; g++)
    {
        for (h = 1; h <= g; h++)
        {
            printf("%d*%d=%-2d ", h, g, h*g);
        }
        printf("\n");
    }
    //方法二(函数)
    int j = 0;
    scanf("%d", &j);
    print_table(j);//函数起名非常关键，名字最好能体现函数功能



    return 0; 
}
