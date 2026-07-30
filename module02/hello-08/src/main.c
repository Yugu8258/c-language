#include <stdio.h>

int main(void)
{
    // size_t

    printf("Size of short : %zu byte(s)\n", sizeof(short));

    printf("Size of unsigned short: %zu byte(s)\n", sizeof(unsigned short));

    printf("Size of int : %zu byte(s)\n", sizeof(int));

    printf("Size of unsigned int : %zu byte(s)\n", sizeof(unsigned int));

    printf("Size of long : %zu byte(s)\n", sizeof(long));

    printf("Size of unsigned long : %zu byte(s)\n", sizeof(unsigned long));

    printf("Size of long long : %zu byte(s)\n", sizeof(long long));

    printf("Size of unsigned long long : %zu byte(s)\n", sizeof(unsigned long long));

    return 0;
}

