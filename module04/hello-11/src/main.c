#include <stdio.h>
#include <stdint.h>

int main(void)
{
    uint32_t score = 88;

    char grade;

    grade = (score >= 90) ? 'A' :
        (score >= 80) ? 'B' :
        (score >= 60) ? 'C' : 'D';

    printf("得分: %u, 等级: %c\n", score, grade);

    return 0;
}

