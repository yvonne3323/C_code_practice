//前 26 列用一个字母，依次为 A 到 Z，接下来 26*26 列使用两个字母的组合，依次为 AA 到 ZZ。
//请问第 2022 列的名称是什么
#include<stdio.h>
int main()
{
    int n = 2022;
    char a[26] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
     b[26][26];
    char c[26][26][26];
    int i,j,k;
    for(i=0;i<26;i++)
    {
        for(j=0;j<26;j++)
        {
            b[i][j] = a[i];
            b[i][j] = b[i][j] + a[j];
        }
    }
    for(i=0;i<26;i++)
    {
        for(j=0;j<26;j++)
        {
            for(k=0;k<26;k++)
            {
                c[i][j][k] = a[i];
                c[i][j][k] = c[i][j][k] + b[j][k];
            }
        }
    }
    for(i=0;i<26;i++)
    {
        for(j=0;j<26;j++)
        {
            for(k=0;k<26;k++)
            {
                if(n == 1)
                {
                    printf("%d",a[i]);
                    return 0;
                }
                n--;
                if(n == 1)
                {
                    printf("%d",b[i][j]);
                    return 0;
                }
                n--;
                if(n == 1)
                {
                    printf("%d",c[i][j][k]);
                    return 0;
                }
                n--;
            }
        }
    }

    return 0;
}