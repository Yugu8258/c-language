#include <stdio.h>

int main(void)
{
    int a = 5, b = 3, c = 2, d = 4, e = 1;

    int result;

    result = (a * b + c) << d > e ? b : c * ++e - sizeof(d) / sizeof(int);

    printf("Result : %d\n", result);

    return 0;
}

