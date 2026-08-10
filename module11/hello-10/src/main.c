#define _XOPEN_SOURCE 700

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define LINE_BUF_LEN 256

// 函数定义
void read_config_safe(const char *file_name);

int main(void)
{
    // 抽离读写函数

    const char *file_name = "game_config.txt";

    read_config_safe(file_name);

    return EXIT_SUCCESS;
}

void read_config_safe(const char *file_name)
{
    if (file_name == NULL || *file_name == '\0')
    {
        fprintf(stderr, "Error: file name invalid\n");
        exit(EXIT_FAILURE);
    }

    FILE *file_ptr = NULL;

    file_ptr = fopen(file_name, "r");

    // 打开文件失败
    if (file_ptr == NULL)
    {
        char error_msg[LINE_BUF_LEN];

        // 将错误信息安全存入缓冲区(线程安全优于直接strerror)
        strerror_r(errno, error_msg, sizeof(error_msg));

        fprintf(stderr, "Failed to open config file for reading: %s\n", error_msg);
        exit(EXIT_FAILURE);
    }

    // 文件读取业务
    char buffer[LINE_BUF_LEN];
    while (fgets(buffer, sizeof(buffer), file_ptr) != NULL)
    {
        // 解析配置逻辑
        printf("%s", buffer);
    }

    // 判断循环退出原因: 正常结束 / IO错误
    if (ferror(file_ptr))
    {
        char error_msg[LINE_BUF_LEN];
        strerror_r(errno, error_msg, sizeof(error_msg));
        fprintf(stderr, "Error while reading config file: %s\n", error_msg);
        fclose(file_ptr);
        exit(EXIT_FAILURE);
    }

    // 关闭流
    fclose(file_ptr);
    file_ptr = NULL; // 置空
}

