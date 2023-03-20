//从 1900 年 1 月 1 日至 9999 年 12 月 31 日
//总共有多少天，年份的数位数字之和等于月的数位数字之和加日的数位数字之和
//的天数
#include <stdio.h>
int main()
{
    int year, month, day, sum, sum2,count;
    count = 0;
    for (year = 1900; year <= 9999; year++)
    {
        sum = year / 1000 + year % 1000 / 100 + year % 100 / 10 + year % 10 ;
        for (month = 1; month <= 12; month++)
        {
            if (month == 2)
            {
                if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
                {
                    for (day = 1; day <= 29; day++)
                    {
                        sum2 = month / 10 + month % 10 + day / 10 + day % 10;
                        if (sum == sum2)
                        {
                            count++;
                            printf("%d-%d-%d\n", year, month, day);
                        }
                    }
                }
                else
                {
                    for (day = 1; day <= 28; day++)
                    {
                        sum2 = month / 10 + month % 10 + day / 10 + day % 10;
                        if (sum == sum2)
                        {
                            count++;
                            printf("%d-%d-%d\n", year, month, day);
                        }
                    }
                }
            }
            else if (month == 4 || month == 6 || month == 9 || month == 11)
            {
                for (day = 1; day <= 30; day++)
                {
                    sum2 = month / 10 + month % 10 + day / 10 + day % 10;
                    if (sum == sum2)
                    {
                        count++;
                        printf("%d-%d-%d\n", year, month, day);
                    }
                }
            }
            else
            {
                for (day = 1; day <= 31; day++)
                {
                    sum2 = month / 10 + month % 10 + day / 10 + day % 10;
                    if (sum == sum2)
                    {
                        count++;
                        printf("%d-%d-%d\n", year, month, day);
                    }
                }
            }
            
        }
    }
    printf("count = %d\n", count);
    return 0;
}