#include <stdio.h>

int main(void)
{
    int result;

    int a = 5;
    int b = 3;
    int c = 2;

    result = a + b * c;
    printf("result : %d\n", result);

    result = (a + b) * c;
    printf("result : %d\n", result);

    return 0;
}

