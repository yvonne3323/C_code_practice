
#include "tic.h"

void InitBoard(char board[ROW][COL], int row, int col)
{
    int i = 0;
    int j = 0;
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
            board[i][j] = ' ';
    }
}

void DisplayBoard(char board[ROW][COL], int row, int col)
{
    int i = 0;
    for (i = 0; i < row; i++)
    {
        //打印一行的数据
        //printf(" %c | %c | %c ", board[i][0], board[i][1], board[i][2]);不通用
        int j = 0;
        for (j = 0; j < col; j++)
        {
            printf(" %c ", board[i][j]);
            if (j < col - 1)
                printf("|");
        }
        printf("\n");
        //打印分割行
        if (i < row - 1)
        {
            //printf("\n---|---|---\n");
            for (int j = 0; j < col; j++)
            {
                printf("---");
                if (j < col - 1)
                    printf("|");
            }
            printf("\n");
        }
    }
}

void PlayerMove(char board[ROW][COL], int row, int col)
{
    int x = 0;
    int y = 0;
    printf("玩家走：\n");

    while (1)
    {
        printf("请输入坐标：>");
        scanf("%d%d", &x, &y);
        //坐标合法性判断
        if (x >= 1 && x <= row && y >= 1 && y <= col)
        {
            //判断坐标是否已经被占用
            if (board[x - 1][y - 1] == ' ')
            {
                board[x - 1][y - 1] = '*';
                break;
            }
            else
                printf("坐标被占用，请重新输入！\n");
        }
        else
            printf("坐标非法，请重新输入！\n");
    }
}

void ComputerMove(char board[ROW][COL], int row, int col)
{
    int x = 0;
    int y = 0;
    printf("电脑走：\n");

    while (1)
    {
        x = rand() % row;//0-2
        y = rand() % col;
        //判断坐标是否已经被占用
        if (board[x][y] == ' ')
        {
            board[x][y] = '#';
            break;
        }
    }
}

char IsFull(char board[ROW][COL], int row, int col)
{
    int i = 0;
    int j = 0;
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            if (board[i][j] == ' ')
                return 0;
        }
    }
    return 1;
}

char IsWin(char board[ROW][COL], int row, int col)
{
    int i = 0;
    for (i = 0; i < row; i++)
    {
        //判断横三行
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
            return board[i][0];//不需再判断    
    }
    for (i = 0; i < col; i++)
    {
        //判断竖三列
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
            return board[0][i];
    }
    //判断两个对角线
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
        return board[0][0];
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')
        return board[0][2];
    //判断平局
    //如果棋盘满了返回1，否则返回0
    int ret = IsFull(board, row, col);
    if (ret == 1)
        return 'Q';
    //既没有赢也没有平局，继续游戏
    return 'C';
}


