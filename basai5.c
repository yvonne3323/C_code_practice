//给定一天是一周中的哪天，请问 n 天后是一周中的哪天
#include <stdio.h>
int main()
{
    int n, day;
    scanf("%d\n%d", &n, &day);
    printf("%d", (n + day - 1) % 7 + 1);
    return 0;
}