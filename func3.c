#include<stdio.h>
#include<string.h>

#include"sub.h" //改c_cpp_properties.json: "includePath"和tasks.json: "args": "-I" 

void Add(int *p)
{
    (*p)++;
}

void new_line()
{
    printf("hehe\n");
}

void three_line()
{
    int i = 0;
    for(i=0;i<3;i++)
    {
        new_line();
    }
}

//导入静态库
// #pragma comment(lib,"sub.lib")

int main()
{
    //记录调用次数
    int num = 0;
    Add(&num);
    printf("%d\n",num);

    Add(&num);
    printf("%d\n",num);

    Add(&num);
    printf("%d\n",num);

    //函数的嵌套调用(函数不可以嵌套定义)
    three_line();

    
    int len = strlen("hello");
    printf("%d\n",len);
    
    //链式访问(把一个函数的返回值作为另一个函数的参数)
    printf("%d\n",strlen("hello"));

    char arr1[20] = {0};
    char arr2[] = "bit";
    strcpy(arr1,arr2);
    printf("%s\n",arr1);
    
    printf("%s\n",strcpy(arr1,arr2));
    
    printf("%d",printf("%d",printf("%d",43)));
    //printf 返回类型是int, return value:each of these functions returns the number of characters printed,or a negative value if an error occurs.
    //函数返回的是打印在屏幕上的字符个数
    // 4321 第三个返回值是2 第二个返回值是1(被第一个printf打印)

    //函数的声明和定义
    int a = 10;
    int b = 20;
        //函数放后面会警告，代码从前往后识别(先声明后定义)(前提:函数定义再后面)
    //函数声明一下-告知 (声明只是告诉有,真的有要看定义)
    int Add1(int x,int y); //xy想加就加

    int sum = Add1(a,b);
    printf("%d\n",sum);

    //函数声明
    //写计算机:A-加法 B-减法 C-乘法 D-除法(写.h和.c文件,这里引用头文件)
    int sub = Sub(10,20);
    printf("%d\n",sub);

    //静态库：把项目-属性-常规-配置类型改为静态库(debug-sub.lib)
    //得到sub.lib文件和sub.h文件
    //函数前导入静态库即可使用

    return 0;
}

//函数的定义
int Add1(int x,int y)
{
    return x+y;
}