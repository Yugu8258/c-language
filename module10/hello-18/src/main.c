#include <stdio.h>
#include <string.h>

int main(void)
{
    // strscpn()

    const char *str1 = "abcdef123456";
    const char *str2 = "1234567890";

    size_t len = strcspn(str1, str2);

    printf("%zu\n", len);

    return 0;
}

