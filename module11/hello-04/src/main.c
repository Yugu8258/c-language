#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 256

int main(void)
{
    // fopen()

    // 打开文件
    // 设定文件路径(要读写的文件), 设定文件的操作模式(r) r -> read
    FILE *fp = fopen("123.txt", "r");
    // 文件路径不对, 文件不存在, 文件出现了异常, 文件没有权限访问
    if (fp == NULL)
    {
        perror("fopen 123.txt failed.");
        return EXIT_FAILURE;
    }

    char buf[BUFFER_SIZE];

    // fgetc 一个字节的读取 -> putchar 输出字符

    // 逐行读取文件
    while (fgets(buf, sizeof(buf), fp) != NULL)
    {
        fputs(buf, stdout);
    }

    // 判断是否发生读写错误
    if (ferror(fp))
    {
        perror("read file error.");
    }
    
    fclose(fp);

    fp = NULL;

    return EXIT_SUCCESS;
}

