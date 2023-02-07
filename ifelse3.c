#include<stdio.h>
#include<string.h> //strlen strcmp
//strcmp 比较ASCII码 eg:abcde abccqqq d>c 所以 >
#include<windows.h> //Sleep
#include<stdlib.h> //system srand rand
#include<time.h> //time
void menu()
{
    printf("*************************\n");
    printf("***** 1.play  0.exit *****\n");
    printf("*************************\n");
}
void game()
{   //猜数字游戏的实现

    //1.生成随机数

    // rand函数 返回一个0-32767之间的随机数 每次启动程序时会出现一次性整体相同的随机数
    // srand() 设置随机数种子 srand()里面是固定的数的话
    //会给随机的数，但每次都给同一个 srand(100) 365
    // 时间-时间戳 time 整型 time_t ->__time64_t ->__int64(结构体定义类型)
    //srand((unsigned int)time(NULL)); //不给参数 null 空
    //给的数离得近 且速度快 值可能相同 因为srand放在函数里面，srand起点一直在重来，起点一次就行 放在主函数开头即可
    
    int ret = rand()%100+1; //%100的余数是0-99 +1 1-100
    //不是说32767/100->99 而是0-32767这个范围%100 余数的可能性在0-99之间 因为32767超过100
    //printf("ret = %d\n",ret);

    //2.猜数字
    int guess = 0;
    while(1)
    {
        printf("请输入一个数字：");
        scanf("%d",&guess);
        if(guess < ret)
        {
            printf("猜小了\n");
        }
        else if(guess > ret)
        {
            printf("猜大了\n");
        }
        else
        {
            printf("猜对了\n");
            break;
        }
    }
}

int func(int a)
{
    int b;
    switch(a)
    {
        case 1: b=1;
        case 2: b=2;
        case 3: b=3;
        default: b=0;
    }
    return b;
}
// func(1) -> 0 没有break

int main()
{
    // 在一个有序数组中查找具体的某个数字n(二分查找)
    //最坏要查找log2n次

    int a[10] = {1,2,3,4,5,6,7,8,9,10};
    int k = 7; //要查找的数字
    int sz = sizeof(a) / sizeof(a[0]); //数组元素个数
    int left = 0;
    int right = sz -1;
    while(left <= right)
    {
        int mid = (left + right) / 2;
        if(a[mid]<k)
        {
            left = mid +1;
        }
        else if(a[mid]>k)
        {
            right = mid -1;
        }
        else
        {
            printf("找到了，下标是%d\n",mid);
            break;
        }
    }
    if(left > right)
    {
        printf("没找到");
    }
    
    // 编写代码，演示多个字符从两端移动，向中间汇聚
    /*
    char arr1[] ="welcome to bit!!!!!!";
    char arr2[] ="####################";
    int left1 = 0;
    int right1 = strlen(arr1) -1;

    while(left1 <= right1)
    {
        arr2[left1] = arr1[left1];
        arr2[right1] = arr1[right1];
        printf("%s\n",arr2);
        Sleep(1000); //体现动态效果，单位：毫秒 多行
        system("cls"); //清屏 一行
        
        left1++;
        right1--;
    }
    printf("%s\n",arr2);
    */

    // 模拟用户登录，三次机会，如果登录成功，提示登录成功，如果三次登录失败，退出程序
    int i = 0;
    char password[20] = {0};
    for(i=0;i<3;i++)
    {
        printf("请输入密码：");
        scanf("%s",password);
        if(strcmp(password,"123456")==0) // strcmp 字符串比较函数
        //两个字符串比较，不可以使用==， 即password=="123456" 这是地址比较
        {
            printf("登录成功\n");
            break;
        }
        else
        {
            printf("密码错误，请重新输入:\n");
        
        }
    }
    if(i==3)
    {
        printf("三次密码输入错误，退出程序\n");
    }
    
    //猜数字游戏 自动产生1-100之间的随机数，用户输入数字，提示大了还是小了，直到猜对为止 游戏可以一直玩
    int input = 0;
    srand((unsigned int)time(NULL)); //不给参数 null 空
    do //一直玩 用do 可以先玩
    {
        menu();//打印菜单
        printf("请选择：");
        scanf("%d",&input);
        switch (input)
        {
        case 1:
            game();
            printf("猜数字游戏\n");
            break;
        case 0:
            printf("退出游戏\n");
            break;
        default:
            printf("选择错误,重新选择\n");
            break;
        }
    }while(input); //为0 为假 退出循环


// 三个整数 从大到小
    int count1 = 0;
    int count2 = 0;
    int count3 = 0;
    //输入
    scanf("%d %d %d",&count1,&count2,&count3);
    //调整顺序
    if(count1 < count2)
    {
        int tmp = count1;
        count1 = count2;
        count2 = tmp;
    }
    if(count1 < count3)
    {
        int tmp = count1;
        count1 = count3;
        count3 = tmp;
    }
    if(count2 < count3)
    {
        int tmp = count2;
        count2 = count3;
        count3 = tmp;
    }
    //三个代码非常相似，后期改善
    printf("%d %d %d",count1,count2,count3);


//打印1-100 3的倍数
    int c = 0;
    for(c=1;c<=100;c++)
    {
        if(c%3==0)
        {
            printf("%d ",c);
        }
    }

    for(c=3;c<=100;c+=3)
    {
        printf("%d ",c);
    }

//最大公约数
    int d = 0;
    int e = 0;
    scanf("%d %d",&d,&e);
    //1.不会超过两个数中较小的那个数 2.从大到小开始判断
    int max = d>e?e:d;
    while(1)
    {
        if(d % max==0 && e % max==0)
        {
            printf("最大公约数是：%d\n",max);
            break;
        }
        max--;
    }

    //辗转相除法 24和18： f:24 % g:18=6  f:18 % g:6=0 6就是最大公约数
    int f = 0;
    int g = 0;
    scanf("%d %d",&f,&g);
    int temp = 0;
    while(temp = f%g) //不判断两数大小原因：18和24 18%24=18 24%18=6 18%6=0 只是多一步
    {
        f = g;
        g = temp;
    }
    printf("最大公约数是：%d",g);
    //最小公倍数：两个数的乘积除以最大公约数
    return 0;
}