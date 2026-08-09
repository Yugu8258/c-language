#include <stdio.h>

typedef struct Date
{
    int day;
    int month;
    int year;
} Date;

struct Person
{
    char name[50];
    int age;
    float height;
    // ...
};

int main(void)
{
    // 结构体

    // 初始化结构体变量
    Date today = { 12, 2, 2024 };

    // 通过.访问成员
    printf("Today's date is : %d-%d-%d\n", today.day, today.month, today.year);

    // 创建
    struct Person tai_luo = { "TaiLuo", 12000, 89.88f };
    struct Person *ptr = &tai_luo;

    // 通过->访问成员 指针
    printf("%s 的年龄: %d, 身高: %.2f\n", ptr->name, ptr->age, ptr->height);

    return 0;
}

