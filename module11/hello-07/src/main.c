#include <stdio.h>

int main(void)
{
    FILE *fp = fopen("123.txt", "r");
    if (fp == NULL)
    {
        perror("打开文件失败");
        return 1;
    }

    int a;
    double b;
    char str[32];

    // 从文件读取
    int ret = fscanf(fp, "%d %lf %s", &a, &b, str);
    printf("匹配数量 = %d\n", ret);
    printf("a = %d, b = %.2lf, str = %s\n", a, b, str);

    fclose(fp);

    return 0;
}

