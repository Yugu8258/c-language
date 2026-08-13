#include <stdlib.h>
#include "application_logic.h"
#include "logger.h"

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

    // 初始化应用程序
    if (!app_init())
    {
        log_message(LOG_ERROR, "Application initialization failed.");
        logger_close();
        return EXIT_FAILURE;
    }

    if (!app_execute())
    {
        log_message(LOG_ERROR, "Application execution failed.");
        app_cleanup();
        logger_close();
        return EXIT_FAILURE;
    }

    log_message(LOG_INFO, "Application exited successfully.");

    app_cleanup();
    
    logger_close();

    return EXIT_SUCCESS;
}

