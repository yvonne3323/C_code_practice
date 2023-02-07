#include<stdio.h>
#include<math.h>

int is_prime(int n)
{
    //2->n-1 之间的数字
    int j = 0;
    for(j=2;j<=sqrt(n);j++)
    {
        if(n%j==0)
            return 0;
    }
    //printf("%d ",n); 不建议在函数里面打印
    return 1;
}

int is_leap_year(int year) //函数不写类型 默认int
{
    if((year%4==0 && year%100!=0) || year%400==0)
        return 1;
    else
        return 0;
}

int is_leap_year2(int year)
{
    return (year%4==0 && year%100!=0) || year%400==0;
}

//int binary_seach(int* a,int k,int s) 本质上是指针，因为传地址
int binary_seach(int a[],int k,int s) //一个数据存储空间首地址 sizeof(a)就是8(指针变量大小 64位) sz=2 所以不要把sz放在函数里   
{
    int left = 0;
    int right = s-1;
    while(left<=right)
    {
        int mid = (left+right)/2;
        if(a[mid]>k)
        {
            right = mid-1;
        }
        else if(a[mid]<k)
        {
            left = mid+1;
        }
        else
        {
            return mid;
        }
    }
    return -1;
}




int main()
{

    //打印100-200之间的素数
    int i = 0;
    int count = 0;
    for(i=100;i<=200;i++)
    {
        //判断i是否是素数
        if(is_prime(i)==1)
        {
            count++;
            printf("%d ",i);
        }
    }
    printf("\ncount=%d\n",count);

    //判断是否为闰年
    int year = 0;
    for(year=1000;year<=2000;year++)
    {
        if(is_leap_year(year)==1)
        {
            printf("%d ",year);
        }
    }

    //确定顺序大小数组找确定数字
    int arr[] = {1,2,3,4,5,6,7,8,9,10};
    int key = 7;
    int sz = sizeof(arr)/sizeof(arr[0]);
        //找到返回下标 找不到返回-1
    int ret = binary_search(arr,key,sz);
    //数组arr传参，实际不是传递数组本身，而是传递数组的首地址
    if(ret == -1)
        printf("找不到\n");
    else
        printf("找到了 下标是%d\n",ret);



    return 0;
}