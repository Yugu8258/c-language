#include <stdio.h>
#include <string.h>

int main(void)
{
    // strspn()

    const char *str1 = "12345abcdefghi679010";
    const char *str2 = "12345678910";

    size_t len = strspn(str1, str2);

    printf("%zu\n", len);

    return 0;
}

