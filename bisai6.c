//a[1], a[2], ..., a[n]
//给定一个正整数 k，请问对于每一个 1 到 n 之间的序号 i，a[i-k], a[i-k+1], ..., a[i+k] 这 2k+1 个数中
//最小值是多少,当某个下标超过 1 到 n 的范围时，数不存在，求最小值时只取存在的那些值。
#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
#define MAXN 1000000
int a[MAXN];
int main()
{
    int n, k;
    scanf("%d\n", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }
    scanf("%d", &k);
    for (int i = 1; i <= n; i++)
    {
        int min = 1000000000;
        for (int j = i - k; j <= i + k; j++)
        {
            if (j >= 1 && j <= n && a[j] < min)
                min = a[j];
        }
        printf("%d ", min);
    }
    return 0;
}