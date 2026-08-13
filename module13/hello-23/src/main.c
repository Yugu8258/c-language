#include <stdio.h>
#include <stdlib.h>

int *global_ptr;

void function(void);

int main(void)
{
    // 指针的作用域与生命周期

    function();

    printf("Outside function: global_ptr points to %d\n", *global_ptr);

    free(global_ptr);
    
    return 0;
}

void function(void)
{
    int local = 5;

    int *local_ptr = &local; // 局部指针

    global_ptr = (int *)malloc(sizeof(int));

    if (global_ptr != NULL)
    {
        *global_ptr = 10;
    }

    printf("Inside function: local_ptr points to %d\n", *local_ptr);
}

