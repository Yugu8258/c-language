#include <stdio.h>
#include <stdlib.h>

void printBudgets(double *budgets, int size);

int main(void)
{
    // 动态调整部门预算列表
    int size = 3; // 初始的预算项数

    double *budgets = (double *)malloc(size * sizeof(double));
    if (budgets == NULL)
    {
        perror("Failed to allocaete initial budgets");
        return EXIT_FAILURE;
    }

    // 假设的初始预算分配
    budgets[0] = 10000;
    budgets[1] = 15000;
    budgets[2] = 12000;

    printBudgets(budgets, size);

    // 新的一年, 需要增加预算项
    int newSize = 5;
    double *newBudgets = (double *)realloc(budgets, newSize * sizeof(double));
    if (newBudgets == NULL)
    {
        perror("Failed to reallocate budgets.");
        free(budgets);
        return EXIT_FAILURE;
    }

    budgets = newBudgets; // 更新指针

    budgets[3] = 20000;
    budgets[4] = 16000;

    printBudgets(budgets, newSize);

    free(budgets);

    return EXIT_SUCCESS;
}

void printBudgets(double *budgets, int size)
{
    printf("Current budgets:\n");
    for (size_t i = 0; i < size; ++i)
    {
        printf("Department %zu: $%.2f\n", i + 1, budgets[i]);
    }
}

