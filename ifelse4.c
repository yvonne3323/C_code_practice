#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>

void test()
{
flage:
    printf("testa");

}


int main()
{
//打印1000-2000之间的闰年
    int y = 0;
    int count = 0;
    for(y = 1000; y <= 2000; y++)
    {
        //判断闰年 1：能被4整除，不能被100整除 2：能被400整除
        if((y%4==0 && y%100!=0) || y%400==0)
        {
            printf("%d ",y);
            count++;
        }
    }
    printf("\ncount = %d\n",count); //243哦

//打印100-200之间的素数(只能被1和自身整除的数)
    int i = 0;
    int j = 0;
    //补充方法 flag = 1;
    int count1 = 0;
    for(i = 100; i <= 200; i++)
    {
        for(j = 2; j < i; j++)
        {
            if(i%j == 0)
            {
                //flag = 0;
                break; //跳出的是for循环
            }
        }
        if(j == i) //flag == 1
        {
            printf("%d ",i);
            count1++;
        }
    }
    printf("\ncount1 = %d\n",count1); //21哦

    //优化
    int i1 = 0;
    int j1 = 0;
    // m=a*b; a<=b; a<=sqrt(m)
    int flag1 = 1;
    int count2 = 0;
    for(i1 = 100; i1 <= 200; i1++)
    //优化2：偶数不可能是素数 for(i1 = 101;i1<200;i+=2)
    {
        for(j1 = 2; j1 < sqrt(i1); j1++)
        {
            if(i1%j1 == 0)
            {
                flag1 = 0;
                break;
            }
        }
        if(flag1 == 1)
        {
            printf("%d ",i1);
            count2++;
        }
    }
    printf("\ncount2 = %d\n",count2);

// goto语句 容易凌乱

// flag:
//     printf("hello world!\n");
//     printf("hello\n");
//     goto flag; //跳转到flag处执行 死循环

// 关机程序
//运行：一分钟后关机，输入：我是猪 就关机
//在命令窗口中：shutdown -s -t 60 关机，shutdown -a 取消关机
    //C语言 提供了system函数，可以调用系统命令
    char input[20] = {0}; //存放输入的信息
    system("shutdown -s -t 60"); //system-stdlib.h

again:
    printf("一分钟后关机 输入：我是猪，就取消关机\n");
    scanf("%s",input);
    if(strcmp(input,"我是猪") == 0) //strcmp-string.h
    {
        system("shutdown -a");
    }
    else
    {
        goto again;
    }
//没有必要一定要goto, while(1)也可以

//goto语句可以让在循环里一次性跳出多层循环
// for(...)
//     for(...)
//     {
//         for(...)
//         {
//             if(disaster)
//             {
//                 goto end;
//             }
//         }
//     }
// end:
//     if(disaster)
//         //处理错误情况

//goto语句只能在一个函数范围内跳转，不能跨函数
//   goto flage 是错的 flage在test函数里
    return 0;
}
//exe文件由debug变为release(开放)，可以发给别人使用
//exe文件放在服务里且改为自动启动，开机就会自动运行