#include<stdio.h>
#include<string.h>

//冒泡排序的思想：两两相邻的元素进行排序，并且可能的话需要交换
// 9876543210 -> 8765432109 一趟冒泡排序 10个数需要9趟
//第一趟：10个数字待排序 9对比较
void bubble_sort(int arr[],int len)
{
    //len 不等于 sizeof(arr)/sizeof(arr[0]) 因为arr是指针
    int sz = sizeof(arr)/sizeof(arr[0]);
    printf("%d",sz); //2
    int i;
    for(i = 0;i < len - 1;i++)
    {
        int j;
        int flag = 1;
        for(j = 0;j < len - 1 - i;j++)
        {
            if(arr[j] > arr[j + 1])
            {
                //交换 不要与& 取地址交换 混淆
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                flag = 0;
            }
        }
        if(flag == 1)
        {
            break;
        } //优化 如果一趟排序没有发生交换，说明已经有序了
    }
    for(i = 0;i < len;i++)
    {
        printf("%d ",arr[i]);
    }
}

int main()
{
    int arr1[3][4];//三行四列 创建
    int arr2[3][4] = {1,2,3,4,5,6,7,8,9,10,11,12};//初始化
    int arr3[3][4] = {1,2,3,4,5,6,7};//不完全初始化 补0
    int arr4[3][4] = {{1,2},{5,6},{9,10}};//对应行数不够补0
    int arr5[][4] = {{1,2},{3,4},{5,6}};//行数可以省略,但是列数不能省略

    //二维数组的使用 (均从0开始)
    int arr6[][4] = {{1,2},{3,4},{5,6}};
    int i,j;
    for(i = 0;i < 3;i++)
    {
        for(j = 0;j < 4;j++)
        {
            printf("%d ",arr6[i][j]);
        }
        printf("\n");
    }

    //二维数组在数组中的存储
    int arr7[][4] = {{1,2},{3,4},{5,6}};
    int m,n;
    for(m = 0;m < 3;m++)
    {
        for(n = 0;n < 4;n++)
        {
            printf("&arr7[%d][%d] = %p\n",m,n,&arr7[m][n]);
        } //均差4 
    }
    int a;
    int *p = &arr7[0][0];
    for(a = 0;a < 12;a++)
    {
        printf("%d ",*p);
        p++;
    }
    
    //二维数组在内存中也是连续存储的 一行内部连续，跨行也是连续的
    //说明如果列不确定，第二行就不知道往哪里存了
    //arr[0]代表第一行 可以代表一个一维数组

    //数组作为函数参数
    int arr8[] = {9,8,7,6,5,4,3,2,1,0};
    //排序为升序 - 冒泡排序
    //计算数组元素个数
    int len = sizeof(arr8)/sizeof(arr8[0]);

    bubble_sort(arr8,10);

    int arr9[10] = {0};
    printf("%p\n",&arr9[0]);
    printf("%p\n",arr9);
    //数组名代表数组首元素的地址 答案一致
    //例外1：sizeof(数组名)--数组名代表整个数组 -计算整个数组的大小，单位是字节
    int sz = sizeof(arr9);
    printf("%d\n",sz);
    //例外2：&数组名--数组名代表整个数组 -取出的是整个数组的地址
    printf("%p\n",&arr9); //与前面一致，但是&arr9取出的是数组的地址

    printf("%p\n",&arr9+1); //&arr9->&arr9+1 0x28->40
    printf("%p\n",arr9+1); //arr9->arr9+1 4
    
    return 0;
}