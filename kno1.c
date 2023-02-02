#include <stdio.h>  //引用头文件 stdio.h

#define MAX 10000

int i = 100; //全局变量
//printf("%d\n",i); 不能放在函数外面

enum Sex{
    //枚举常量，这种枚举类型的变量只能取这三个值
    MALE,  //若赋初值MALE=1,则FEMALE=2,SECRET=3
    FEMALE,
    SECRET
};

int main()
{
    //局部变量
    char ch ='A'; //字符类型

    int i = 10; //整型
    printf("%d\n",i); //10
    //局部变量的优先级高于全局变量,不建议名字相同

    float f = 1.2; //浮点型
    double d = 1.2; //双精度浮点型
    short s = 1; //短整型
    long l = 1; //长整型
    long long ll = 1; //长长整型

    int age = 18; //定义一个变量age，类型为int，值为18,推荐给初始化值
    age = age + 1; //变量的值可以改变
    printf("%d\n",age); 

    double weight = 60.5;
    printf("%lf\n",weight); //默认保留6位小数

    // %d - int    %lf - double    %f - float    %c - char    %s - string
    

    printf("Hello World\n"); 
    //printf 库函数，打印字符串

    printf("%d\n",100); //打印一个整数


    printf("%d\n",sizeof(char)); // 1
    //sizeof - 关键字 - 操作符 - 计算类型或变量所占空间的大小
    printf("%d\n",sizeof(short));// 2
    printf("%d\n",sizeof(int)); // 4
    printf("%d\n",sizeof(long)); // 4  sizeof(long) >= sizeof(int)
    printf("%d\n",sizeof(long long)); // 8
    printf("%d\n",sizeof(float)); // 4
    printf("%d\n",sizeof(double)); // 8
    //数字后跟着的单位是字节
    //计算机中的单位： 字节（byte） - 8位（bit）一个比特位存放一个二进制位
    //kb -1024byte mb - 1024kb gb - 1024mb tb - 1024gb pb - 1024tb 
    
    //计算两个数的和
    int a = 0;
    int b = 0;
    int sum = 0;
    scanf("%d %d",&a,&b); //输入函数
    sum = a + b;
    printf("sum = %d\n",sum);
    
    //作用域：变量的有效范围
    //全局变量：在整个程序中都有效,整个工程
    //局部变量：在定义的大括号中有效
    {
        int c = 10;
        printf("c = %d\n",c);
    }
    //printf("c = %d\n",c); //c的作用域在大括号内，超出大括号后，c就失效了
    
    //extern int g_val; //引用全局变量
    //printf("g_val = %d\n",g_val);
    //因为vscode 单文件编译，所以不能引用全局变量
    
    //变量的生命周期：变量从创建到销毁的过程
    //全局变量的生命周期：程序的生命周期
    //局部变量的生命周期：从定义的大括号开始到大括号结束
    
    //常量

    //1.字面常量
    3.14;

    //2.const修饰的常变量
    const int g_val = 10; //常变量-具有常属性（不能被改变的属性）
    
    //为什么仍叫变：
    int arr2[10] = {0};
    //int arr[g_val] = {0}; g_val是变量，不能作为数组的大小
    
    //g_val = 20; //常量不能修改
    printf("g_val = %d\n",g_val); //10

    //3.#define定义的标识符常量
    //MAX = 10;  不能修改
    int n = MAX;
    printf("n = %d\n",n); //10000

    //4.枚举常量：可以一一列举的常量 eg:三原色
    //前面enum已定义
    enum Sex k = MALE;
    printf("k = %d\n",k); //0 默认从0开始
    printf("%d\n",FEMALE); //1
    printf("%d\n",SECRET); //2
    //MALE = 10; //枚举常量不能修改

    return 0;
}