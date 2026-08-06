#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

#define STUDENT_COUNT 5

int main(void)
{
    /**
     * 假如我们有五个学生的成绩, 我们需要计算平均成绩, 找出最高分和最低分
     */

    uint32_t grades[STUDENT_COUNT] = { 85, 92, 88, 96, 79 };

    // 总分
    uint32_t sum = 0;
    
    // 最高分
    uint32_t max_grade = grades[0];

    // 最低分
    uint32_t min_grade = grades[0];

    puts("所有人成绩如下:");

    for (uint32_t index = 0; index < STUDENT_COUNT; index++)
    {
        printf("学生 %" PRIu32 " 的成绩为: %-3" PRIu32 "\n", index + 1, grades[index]);

        sum += grades[index];

        if (grades[index] > max_grade)
        {
            max_grade = grades[index];
        }

        if (grades[index] < min_grade)
        {
            min_grade = grades[index];
        }
    }

    // 平均成绩
    double average = (double)sum / STUDENT_COUNT;

    printf("平均成绩: %.3f\n", average);

    printf("最高成绩: %" PRIu32 "\n", max_grade);
    printf("最低成绩: %" PRIu32 "\n", min_grade);

    printf("总成绩: %" PRIu32 "\n", sum);

    return 0;
}

