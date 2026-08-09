#include <stdio.h>
#include <inttypes.h>

// typedef 起别名
// 匿名结构体
typedef struct
{
    char name[50];
    uint32_t age;
    float score;
} Student;

void print_stu(Student stu);

void update_score_by_value(Student *stu, float new_score);

int main(void)
{
    Student stu = { "John Doe", 13, 89.5 };

    puts("Before update:\n");

    print_stu(stu);

    puts("\nAfter update bu value:\n");

    update_score_by_value(&stu, 81.5f);

    print_stu(stu);

    return 0;
}

void print_stu(Student stu)
{
    printf("Student Name: %s\n", stu.name);

    printf("Student age: %" PRIu32 "\n", stu.age);

    printf("Student Score: %.2f\n", stu.score);
}

void update_score_by_value(Student *stu, float new_score)
{
    stu->score = new_score;
}

