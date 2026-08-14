#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdarg.h>

typedef enum
{
    LOG_INFO,
    LOG_WARNING,
    LOG_ERROR
} LogLevel;

const char *get_current_time(void);

void log_message(LogLevel level, const char* format, ...);

int main(void)
{
    // 自定义日志函数
    // log_message
    // 日志级别, 格式化字符串, 自动添加时间戳

    log_message(LOG_INFO, "This is an information message with a number: %d", 42);
    log_message(LOG_WARNING, "This is an warning message for users: %s", "Frank");
    log_message(LOG_INFO, "This is an error message related to file: %s", "example.txt");

    return EXIT_SUCCESS;
}

const char *get_current_time(void)
{
    static char buffer[20];
    time_t now = time(NULL);
    struct tm *tm_info = localtime(&now);
    strftime(buffer, 20, "%Y-%m-%d %H:%M:%S", tm_info);

    return buffer;
}

void log_message(LogLevel level, const char* format, ...)
{
    const char *level_str;

    switch (level)
    {
        case LOG_INFO:      level_str = "INFO";     break;
        case LOG_WARNING:   level_str = "WARNING";  break;
        case LOG_ERROR:     level_str = "ERROR";    break;
        default:            level_str = "UNKNOW";   break;
    }

    printf("[%s] [%s] ", get_current_time(), level_str);

    va_list args;
    va_start(args, format);
    vprintf(format, args);
    va_end(args);

    printf("\n");
}

