#include <stdio.h>

typedef enum
{
    MONDAY,     // 0
    TUESDAY,    // 1
    WEDNESDAY,  // 2
    THURSDAY,   // 3
    FRIDAY,     // 4
    SATURDAY,   // 5
    SUNDAY      // 6
} Weekday;

int main(void)
{
    // 枚举 Enumeration

    printf("%d\n", SATURDAY);

    return 0;
}

