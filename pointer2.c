#include<string.h>
#include<stdio.h>
//计数器
int my_strlen(char* str)
{
    int count = 0;
    while(*str != '\0')
    {
        count++;
        str++;
    }
    return count;
}
//递归方法已记录
//指针方法
int my_strlen2(char* str)
{
    char* start = str;
    while(*str != '\0')
    {
        str++;
    }
    return str - start;
}
int main()
{
    //指针运算
    //指针+-整数
    float values[5];
    float * vp;
    for(vp = &values[0]; vp < &values[5];)//指针的关系运算
    {
        *vp++ =0;//指针+整数
    }

    int arr[10] = {1,2,3,4,5,6,7,8,9,10};
    int * p = arr;
    int * pend = arr + 9;
    while(p <= pend)
    {
        printf("%d\n", *p);
        p++;
    }
    //指针-指针
    //前提：两个指针指向同一块空间
    int arr1[10] = {1,2,3,4,5,6,7,8,9,10};
    printf("%d\n", arr1[9] - arr1[0]);//9
    //指针减去指针，得到的是两个指针之间的元素个数

    //strlen() - 求字符串长度
    //递归
    int len = strlen("hello");
    int len2 = my_strlen2("hello");
    int len3 = my_strlen("hello");
    printf("%d\n", len);

    //指针的关系运算
    //指针+指针？ NO eg:日期+/-天数 日期-日期 日期+日期？？
    for(vp = &values[5]; vp > &values[0];)
    {
        *--vp = 0;
    }
    //简化
    for(vp = &values[4]; vp >= &values[0]; vp--)
    {
        *vp = 0;
    }
    //标准规定：允许指向数组元素的指针与指向数组最后一个元素后面的那个内存位置的指针比较
    //但是不允许与指向第一个元素之前的那个内存位置的指针进行比较

    return 0;
}