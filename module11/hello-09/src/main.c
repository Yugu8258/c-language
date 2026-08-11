#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    // ferror
    // feof
    // clearerr

    FILE *fp = fopen("123.txt", "r");
    if (fp == NULL)
    {
        perror("文件打开失败");
        return EXIT_FAILURE;
    }

    char buffer[100];

    while (fgets(buffer, sizeof(buffer), fp) != NULL)
    {
        printf("%s\n", buffer);
    }

    if (ferror(fp))
    {
        perror("读取文件时候发生了错误!");
        clearerr(fp);
    }

    if (feof(fp))
    {
        printf("已经达到了文件的末尾...\n");
    }
    else
    {
        printf("文件未达到末尾, 可能因为发生了错误.\n");
    }

    // 关闭文件
    fclose(fp);
    fp = NULL;

    return EXIT_SUCCESS;
}

