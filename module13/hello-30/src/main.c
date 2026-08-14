#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    // C语言中环境变量的访问
    const char *path = getenv("PATH");
    if (path != NULL)
    {
        printf("PATH: %s\n", path);
    }
    else
    {
        return -1;
    }

    return 0;
}

