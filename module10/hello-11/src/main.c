#define _POSIX_C_SOURCE 200809L

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char *line = NULL;

    size_t cap = 0;
    ssize_t n;

    n = getline(&line, &cap, stdin);
    if (n >= 0)
    {
        // n包含换行符: getline同样会把'\n'读入buffer
        if (n > 0 && line[n - 1] == '\n')
        {
            line[n - 1] = '\0';
        }
        
        printf("input: %s\n", line);
    }

    free(line); // 释放内存, 必须

    return 0;
}

