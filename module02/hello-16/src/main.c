#include <stdio.h>

int main(void)
{
    float num = 123.456f;

    // %f
    printf("Using %%f: %f\n", num);

    // %e %E 科学计数法格式化输出
    printf("Using %%e: %e\n", num);
    printf("Using %%E: %E\n", num);

    // %a %A 十六进制浮点数, p计数法
    printf("Using %%a: %a\n", num);
    printf("Using %%A: %A\n", num);

    return 0;
}

