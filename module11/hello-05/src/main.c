#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    FILE *fp = fopen("123.txt", "w");

    if (fp == NULL)
    {
        perror("failed to open.");
        return EXIT_FAILURE;
    }

    // 1. fputs: 输出字符串, 不会自动追加换行
    fputs("first line content", fp);
    // 手动添加换行
    fputs("\n", fp);
    
    // 2. fprintf: 格式化输出, 支持占位符
    int num = 2026;
    double pi = 3.1415926;
    fprintf(fp, "year = %d, pi = %.4f\n", num, pi);

    // 3. 再次fputs
    fputs("third line: hello C stdio\n", fp);

    // 刷新缓冲区
    fflush(fp);

    // 关闭文件(自动刷新缓冲区)
    fclose(fp);

    fp = NULL;

    printf("写入完成\n");

    return EXIT_SUCCESS;
}

