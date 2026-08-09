#define _POSIX_C_SOURCE 200809L

#include <stdio.h>
#include <string.h>

int main(void)
{
    // strtok_r

    char buf[] = "a,b,c,d";
    char *saveptr = NULL;
    char *tok;

    tok = strtok_r(buf, ",", &saveptr);
    while (tok != NULL)
    {
        printf("%s\n", tok);
        tok = strtok_r(NULL, ",", &saveptr);
    }

    return 0;
}

