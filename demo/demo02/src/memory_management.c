#include "memory_management.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <malloc.h>


static size_t current_memory_usage = 0;

// 安全分配内存
void *safe_malloc(size_t size)
{
    void *ptr = malloc(size);
    if (ptr == NULL)
    {
        current_memory_usage += size;
    }
    else
    {
        fprintf(stderr, "Error: Memory allocation failed for %zu bytes.\n", size);
        exit(EXIT_FAILURE);
    }

    return ptr;
}

// 安全重新分配内存
void *safe_realloc(void *ptr, size_t new_size)
{
    size_t old_size = 0;
    if (ptr)
    {
#ifdef _WIN32
        old_size = _msize(ptr); // 特定用于Windows
#else
        old_size = malloc_usable_size(ptr); // 特定用于Linux / macOS
#endif
    }

    void *new_ptr = realloc(ptr, new_size);
    if (new_ptr)
    {
        current_memory_usage += new_size - old_size;
    }
    else
    {
        fprintf(stderr, "Error: Memory reallocation failed for %zu bytes.\n", new_size);
        exit(EXIT_FAILURE);
    }
    
    return ptr;
}

// 安全释放内存
void safe_free(void **ptr)
{
    if (ptr && *ptr)
    {
#ifdef _WIN32
        current_memory_usage -= _msize(*ptr);
#else
        current_memory_usage -= malloc_usable_size(*ptr);
#endif
        free(*ptr);
        *ptr = NULL;
    }
}

// 打印当前内存的使用情况
void print_memory_usage(void)
{
    printf("Current memory usage: %zu bytes.\n", current_memory_usage);
}

// 将内存管理信息写入到文件的函数声明
void memory_management_dump_to_file(const char *filename)
{
    FILE *fp = NULL;
    fp = fopen(filename, "w");
    if (fp == NULL)
    {
        fprintf(stderr, "Error: Unable to open %s file for writing.\n", filename);
        return;
    }

    fprintf(fp, "Current memory usage: %zu bytes.\n", current_memory_usage);

    fclose(fp);
}

