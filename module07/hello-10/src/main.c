#include <stdio.h>

#define GRADE_COUNT 11

const char* get_grade(int score);

int main(void)
{
    printf("grade 100 ---> %s\n", get_grade(100));
    return 0;
}

const char* get_grade(int score)
{
    static const char* invalid_grade = "X";

    static const char* grades[GRADE_COUNT] = { "F", "F", "F", "F", "F", "F", "D", "C", "B", "A", "A+"};

    if (score < 0 || score > 100)
    {
        return invalid_grade;
    }

    return grades[score / 10];
}

