#include <stdio.h>

int g_static_var = 10;

void access_g(void);

void try_access_g(void);

int main(void)
{
    printf("Main before : %d\n", g_static_var);

    access_g();

    try_access_g();

    return 0;
}

void access_g(void)
{
    g_static_var += 5;
    printf("Inside access_g : %d\n", g_static_var);
}

