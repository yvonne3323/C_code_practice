#include <stdio.h>
int main()
{

// for 循环
// 基本语法
// for(初始化语句;循环条件(判断);循环后的操作(调整))
//     循环语句; 


// 1-10
int a = 0;
for ( a = 1; a <=10; a++)
{
    if(a==5)
        break;

    printf("%d ", a);
}

int b = 0;
for ( b = 1; b <=10; b++)
{
    if(b==5)
        continue;

    printf("%d ", b);
}
// 不可在for循环体内修改循环变量，防止for 循环失去控制
//建议控制变量的取值采用前闭后开区间写法 
    int arr[10] = {0};
    int c = 0;
    for ( c = 0; c < 10; c++) //左闭右开 循环10次 10是有意义的
    {
        arr[c] = c;
    } 
    {
        printf("%d ", arr[c]);
    }

//变种
    //判断部分(2)的省略- 判断部分恒为真 -死循环

    int d = 0;
    int e = 0;
    for(;d<3;d++)
    {
        for(;e<3;e++)
        {
            printf("hehe\n");
        }
    } //省略了:3个hehe 没省略时 9个hehe

    int f,g;
    for(f=0,g=0;f<2&&g<5;++f,++g) //两个变量
    {
        printf("hehe\n");
    } 

    // int h = 0;
    // int i = 0;
    // for(h =0,i=0;i=0;h++,i++) //中间的判断部分是赋值 赋值为0 表达式为0 为假 循环0次
    //     i++;

    // do while 循环
    // 基本语法
    // do
    //     循环语句;
    // while(循环条件(判断));
    //特点：循环体至少执行一次

    // 1-10
    int j = 1;
    do
    {
        if(j==5)
            break;
            //continue; 1 2 3 4 卡住
        printf("%d ", j);
        j++;
    } while (j<=10);

//计算n的阶乘
    int n = 0;
    int k = 0;
    int sum = 1;
    printf("请输入一个整数：");
    scanf("%d", &n);
    for ( k = 1; k <= n; k++)
    {
        sum *= k;
    }
    printf("%d的阶乘是%d\n", n, sum);

//计算1！+2！+...+10!
    int l = 0;
    int m = 0;
    int sum1 = 0;
    int sum2 = 1;
    for ( l = 1; l <= 10; l++)
    {
        sum2 = 1; //计算阶乘之前，先把sum2初始化
        for ( m = 1; m <= l; m++)
        {
            sum2 *= m;
        }
        sum1 += sum2;
    }

    // 3！=2！*3
    int n = 0;
    int ret = 1;
    int sum = 0;
    for(n=1;n<=10;n++)
    {
        ret*=n;
        sum+=ret;
    }
    printf("%d\n",sum);

    return 0;
}















