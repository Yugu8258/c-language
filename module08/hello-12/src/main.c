#include <stdio.h>
#include <inttypes.h>

int main(void)
{
    uint32_t department1[] = { 1001, 1002, 1003 }; // 第一个部门的员工id
    uint32_t department2[] = { 2001, 2002 };
    uint32_t department3[] = { 3001, 3002, 3003, 3004 };

    /*
     * uint32_t *p1 = &department1;
     * uint32_t *p2 = &department2;
     * uint32_t *p3 = &department3;
     */

    uint32_t *department_ptrs[3] = { department1, department2, department3 };

    size_t size = sizeof(department_ptrs) / sizeof(department_ptrs[0]);

    uint32_t department_sizes[3] = {
        sizeof(department1) / sizeof(uint32_t),
        sizeof(department2) / sizeof(uint32_t),
        sizeof(department3) / sizeof(uint32_t),
    };

    for (size_t i = 0; i < size; ++i)
    {
        printf("Department %" PRIuMAX ": ", i + 1);
        for (size_t j = 0; j < department_sizes[i]; j++)
        {
            printf("%" PRIu32 " ", department_ptrs[i][j]);
        }
        printf("\n");
    }

    return 0;
}

