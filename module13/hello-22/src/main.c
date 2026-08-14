#include "person.h"
#include "sort.h"
#include "compare.h"

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    /**
     * 设计概念:
     *  1. 抽象层
     *  2. 策略模式
     *  3. 模块化
     *  4. 安全性与跨平
     */

    int intArr[] = { 1, 6, 3, 4, 65, 532, 511, 543, 89, 234 };
    size_t intArrSize = sizeof(intArr) / sizeof(intArr[0]);

    genericSort(intArr, intArrSize, sizeof(int), intCompare, NULL);

    puts("intArr[] = { ");
    for (size_t i = 0; i < intArrSize; ++i)
    {
        printf("%d ", intArr[i]);
    }
    printf(" }\n");

    const char *stringArr[] = { "google", "apple", "frank", "xiaomi", "microsoft", "tencent" };
    size_t stringArrSize = sizeof(stringArr) / sizeof(stringArr[0]);

    genericSort(stringArr, stringArrSize, sizeof(char *), stringCompare, NULL);

    puts("stringArr[] = { ");
    for (size_t i = 0; i < stringArrSize; ++i)
    {
        printf("%s ", stringArr[i]);
    }
    printf(" }\n");

    Person personArr[] = {
        { "Frank", 30 },
        { "Me", 23 },
        { "Alice", 89 },
        { "Charlie", 32 },
        { "Dave", 61 },
        { "You", 1 },
    };

    size_t peopleCount = sizeof(personArr) / sizeof(personArr[0]);

    CompareFunc compareFuctions[] = { compareByName, compareByAge };

    int compareChoice = 1; // 0 for name, 1 for age;

    genericSort(personArr, peopleCount, sizeof(Person), compareFuctions[compareChoice], NULL);

    puts("personArr[] = ");
    for (size_t i = 0; i <  peopleCount; ++i)
    {
        printf("%s, %d\n", personArr[i].name, personArr[i].age);
    }
    printf("\n");

    return EXIT_SUCCESS;
}

