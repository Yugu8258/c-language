#pragma once

#include <stddef.h>

// 定义内存分配和释放的安全操作接口

// 安全分配内存
void *safe_malloc(size_t size);

// 安全重新分配内存
void *safe_realloc(void *ptr, size_t new_size);

// 安全释放内存
void safe_free(void **ptr);

// 打印当前内存的使用情况
void print_memory_usage(void);

// 将内存管理信息写入到文件的函数声明
void memory_management_dump_to_file(const char *filename);

