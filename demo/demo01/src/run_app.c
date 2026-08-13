#include <stdio.h>
#include <stdlib.h>

#include "types.h"

int main(void)
{
    /**
     * 日志错误系统
     * 模块
     *  1. 跨平台的基础数据类型
     *  2. 日志模块
     *  3. 日志级别模块
     *  4. 封装内存分配和释放安全操作
     *  5. 同意错误处理策略, 记录错误, 就警告, 致命错误
     *  6. 检查指针
     *  7. 包含主要运行逻辑
     */

    i32 number = 100;
    printf("numbe : %d\n", number);

    return EXIT_SUCCESS;
}

