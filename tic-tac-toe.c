//数组作为函数传参的时候：
//形参可以写成两种形式：
//int arr[10]; char ch[3][5]; test1(arr); test2(ch);
//1.数组形式 本质是指针
//void test1(int arr[10]) { } void test1(int arr[]) { }
//void test2(char ch[3][5]) { } void test2(char ch[][5]) { }
//2.指针形式
//void test1(int* arr) { }
//
#include"tic.h"
void menu()
{
    printf("******************************\n");
    printf("*******  1.play  *************\n");
    printf("*******  0.exit  *************\n");
    printf("******************************\n");
}

void game()
{
    //存储数据-二维数组
    //char board[3][3] = {0};不方便：改动时需要改动多处
    char board[ROW][COL] = {0};
    //初始化棋盘-初始化空格
    InitBoard(board,ROW,COL);
    //打印棋盘-本质：打印二维数组
    DisplayBoard(board,ROW,COL);
    
    char ret = 0;
    while(1)
    {//(游戏进行的过程)：1.玩家赢-* 2.电脑赢-# 3.平局-Q 4.继续-C
        //玩家下棋
        PlayerMove(board,ROW,COL);
        DisplayBoard(board,ROW,COL);

        //判断玩家是否赢
        ret = IsWin(board,ROW,COL);
        if (ret != 'C')
            break;
        //电脑下棋
        ComputerMove(board,ROW,COL);
        DisplayBoard(board,ROW,COL);

        //判断电脑是否赢
        ret = IsWin(board,ROW,COL);
        if (ret != 'C')
            break;
    }
    //判断输赢
    if (ret == '*')
        printf("玩家赢\n");
    else if (ret == '#')
        printf("电脑赢\n");
    else
        printf("平局\n");
    DisplayBoard(board,ROW,COL);
}

int main()
//三子棋游戏
{
    int input = 0;
    srand((unsigned int)time(NULL));//随机数种子
    do
    {
        menu();
        printf("请选择：");
        scanf("%d",&input);
        switch (input)
        {
        case 1:
            printf("三子棋游戏\n");
            game();
            break;//break跳出的是switch语句
        case 0:
            printf("退出游戏\n");
            break;
        default:
            printf("选择错误，请重新选择\n");
            break;
        }
    } while (input);
    
    return 0;
}