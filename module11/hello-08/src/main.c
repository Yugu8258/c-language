#include <stdio.h>

int main(void)
{
    FILE *fp = fopen("123.txt", "w");
    if (fp == NULL)
    {
        perror("fopen");
        return 1;
    }

    int a = 100;
    double pi = 3.1415;
    char name[] = "C Language";

    fprintf(fp, "整数 a = %d\n", a);
    fprintf(fp, "PI = %.2lf\n", pi);
    fprintf(fp, "字符串: %s\n", name);
    
    fclose(fp);
    fp = NULL;

    return 0;
}

