#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    int score = 90;

    printf("你的成绩等级: %s\n", score >= 90 ? "优秀" : "良好");

    return 0;
}

