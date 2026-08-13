#include "logger.h"

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

static FILE *logFile = NULL;
static LogLevel currentLevel = LOG_INFO;

// 初始化日志模块
bool logger_init(const char *logFilePath)
{
    if (logFilePath == NULL)
    {
        logFile = stdout;
    }
    else
    {
        logFile = fopen(logFilePath, "a");
        if (logFile == NULL || errno)
        {
            fprintf(stderr, "Failed to open %s file, and error msg is %s\n", logFilePath, strerror(errno));
            return false;
        }
    }

    return true;
}

// 终止日志模块
void logger_close(void)
{
    if (logFile && logFile != stdout)
    {
        fclose(logFile);
    }

    logFile = NULL;
}

// 写日志
void log_message(LogLevel level, const char *format, ...)
{
    // 如果日志级别低于当前设置的级别, 或者日志文件尚未打开, 则不记录
    if (level < currentLevel || !logFile)
    {
        return;
    }

    // 打印时间戳
    char time_buf[20];
    time_t now = time(NULL);
    struct tm *now_tm = localtime(&now);
    strftime(time_buf, 20, "%Y-%m-%d %H:%M:%S", now_tm);
    fprintf(logFile, "[%s] ", time_buf);

    // 日志级别
    switch (level)
    {
        case LOG_DEBUG:     fprintf(logFile, "[DEBUG] ");   break;
        case LOG_INFO:      fprintf(logFile, "[INFO] ");    break;
        case LOG_WARNING:   fprintf(logFile, "[WARNING] "); break;
        case LOG_ERROR:     fprintf(logFile, "[ERROR] ");   break;
        case LOG_FATAL:     fprintf(logFile, "[FATAL] ");   break;
        default:            fprintf(logFile, "[UNKNOWN] "); break;
    }

    va_list args;
    va_start(args, format);
    vfprintf(logFile, format, args);
    va_end(args);

    fprintf(logFile, "\n");
    fflush(logFile); // 确保日志信息被立刻写入!
}

// 设置当前日志级别
void set_log_level(LogLevel level)
{
    currentLevel = level;
}

