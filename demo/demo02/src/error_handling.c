#include "error_handling.h"

#include <stdio.h>
#include <stdlib.h>

// 注意: 静态全局变量非线程安全
static ErrorCode current_error_code = ERROR_NONE;

// 设置当前的错误码
void set_error_code(ErrorCode code)
{
    current_error_code = code;
}

// 获取当前的错误码
ErrorCode get_error_code(void)
{
    return current_error_code;
}

// 获取当前的错误信息
const char *get_error_string(ErrorCode code)
{
    switch (code)
    {
        case ERROR_NONE:                        return "No error.";
        case ERROR_MEMORY_ALLOCATION_FAILED:    return "Memory allocation failed.";
        case ERROR_INVALID_OPERATION:           return "Invalid operation.";
        case ERROR_BOUNDS:                      return "Bounds error.";
        default:                                return "Unknown error.";
    }
}

ErrorCode check_not_null(void *ptr)
{
    if (ptr == NULL)
    {
        set_error_code(ERROR_MEMORY_ALLOCATION_FAILED);
        return ERROR_MEMORY_ALLOCATION_FAILED;
    }

    return ERROR_NONE;
}

void handle_error(ErrorCode code)
{
    const char *error_string = get_error_string(code);
    fprintf(stderr, "Error: %s\n", error_string);
    if (code != ERROR_NONE)
    {
        exit(EXIT_FAILURE);
    }
}

