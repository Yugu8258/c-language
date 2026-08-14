#include <stdio.h>
#include <stdlib.h>

#define ROWS 3
#define COLS 4
#define MAX_NAME 50

typedef struct
{
    char name[MAX_NAME];
    int age;
} Person;

// static
static void print_2d_array(int rows, int cols, int (*arr)[COLS]);

static void modify_person_array(Person *people, size_t size);

static int compare_persons(const void *a, const void *b);

int main(void)
{
    int matrix[ROWS][COLS] = {
        { 1, 2, 3, 4 },
        { 2, 3, 4, 5 },
        { 3, 4, 5, 6 },
    };

    printf("2D Array:\n");
    print_2d_array(ROWS, COLS, matrix);

    Person people[] = {
        { "Alice", 30 },
        { "Bob", 25 },
        { "Charlie", 35 },
    };

    size_t num_people = sizeof(people) / sizeof(people[0]);

    printf("Before modification:\n");

    for (size_t i = 0; i < num_people; ++i)
    {
        printf("%s: %d\n", people[i].name, people[i].age);
    }

    printf("\nAfter modificatrion:\n");

    modify_person_array(people, num_people);

    for (size_t i = 0; i < num_people; ++i)
    {
        printf("%s: %d\n", people[i].name, people[i].age);
    }

    qsort(people, num_people, sizeof(Person), compare_persons);

    printf("\nAfter sorting by age:\n");

    for (size_t i = 0; i < num_people; ++i)
    {
        printf("%s: %d\n", people[i].name, people[i].age);
    }

    return 0;
}

static void print_2d_array(int rows, int cols, int (*arr)[COLS])
{
    for (size_t i = 0; i < rows; ++i)
    {
        for (size_t j = 0; j < cols; ++j)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

static void modify_person_array(Person *people, size_t size)
{
    for (size_t i = 0; i < size; ++i)
    {
        people[i].age += 1;
    }
}

static int compare_persons(const void *a, const void *b)
{
    // qsort
    return ((const Person *)a)->age - ((const Person *)b)->age;
}

