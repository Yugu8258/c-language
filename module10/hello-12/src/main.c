#include <stdio.h>
#include <string.h>

int main(void)
{
    // strtok
    // 按照要求分解字符串

    char buf[] = "a,b,c,d";
    const char *delim = ",";

    char *tok = strtok(buf, delim);
    while (tok != NULL)
    {
        printf("%s\n", tok);
        tok = strtok(NULL, delim); // 后续传入NULL
    }

    return 0;
}

