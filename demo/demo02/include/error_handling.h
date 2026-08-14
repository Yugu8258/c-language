#pragma once

#include <stddef.h>
#include <errno.h>

typedef enum
{
    ERROR_NONE = 0,                     // 无错误
    ERROR_MEMORY_ALLOCATION_FAILED,     // 内存错误
    ERROR_INVALID_OPERATION,            // 无效参数
    ERROR_BOUNDS,                       // 越界错误
    // 可以根据需要添加更多的错误码
} ErrorCode;

// 错误处理函数声明

// 设置当前的错误码
void set_error_code(ErrorCode code);

// 获取当前的错误码
ErrorCode get_error_code(void);

// 获取当前的错误信息
const char *get_error_string(ErrorCode code);

ErrorCode check_not_null(void *ptr);

void handle_error(ErrorCode code);

