#include <stdio.h>

#define MONTH_COUNT 12

// 函数将传递一个月份, 返回一个月份有多少天的结果
int get_days_in_month(int month, int year);
int is_leap_year(int year);

int main(void)
{
    // 表驱动法

    int res_day = get_days_in_month(2, 2024);
    printf("%d\n", res_day);

    return 0;
}

int get_days_in_month(int month, int year)
{
    const int days_in_month[MONTH_COUNT] = {
        31, is_leap_year(year) ? 29 : 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
    };

    return days_in_month[month - 1];
}

int is_leap_year(int year)
{
    /*
        if (year % 400 == 0)
        {
            return 1;
        }
        else if (year % 100 == 0)
        {
            return 0;
        }
        else if (year % 4 == 0)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    */

    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

