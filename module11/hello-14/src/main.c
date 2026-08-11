#define _XOPEN_SOURCE 700

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

#define BUFFER_SIZE 2048 // 缓冲区可以大一些以处理更长的行

#define MSG_SIZE 256

int update_log_record_s(const char *filename, const char *search_str, const char *replace_str);

int main(void)
{
    const char *log_file = "123.log";

    const char *search_str = "Memory usage exceeds";

    const char *replace_str = "2025-09-10 14:33:10 [INFO] High memory usage detected. Threshold: 80%";

    // --- 步骤 2: 打印修改前的文件内容
    printf("--- Content of 123.log BEFORE upate ---\n\n");
    system("cat 123.log"); // "cat" 是Linux命令中显示文件内容的命令 Windows使用type

    // --- 步骤 3: 调用核心函数执行替换操作
    int result = update_log_record_s(log_file, search_str, replace_str);

    // --- 步骤 4: 检查结果并打印修改后的文件内容
    if (result != 0)
    {
        char error_msg[MSG_SIZE];
        strerror_r(result, error_msg, sizeof(error_msg));
        fprintf(stderr, "\n\nAn error occurred: %s (Error code: %d)\n", error_msg, result);
    }
    else
    {
        printf("\n\nRecord updated successfully.\n");
        printf("\n--- Content of 123.log AFTER update ---\n\n");
        system("cat 123.log");
    }

    return EXIT_SUCCESS;
}

/**
 * @brief 安全的更新日志文件中的一行记录
 *
 * 该函数通过创建临时文件的方式来替换包含 search_str 的第一行
 *
 * @param filename 要更新的日志文件的路径
 * @param search_str 要搜索的字符串, 用于定位需要替换的行.
 * @param replace_str 用于替换整行的目标字符串(不包含换行符)
 *
 * @return 成功时返回0, 失败时返回一个非零的错误码.
 */
int update_log_record_s(const char *filename, const char *search_str, const char *replace_str)
{
    if (filename == NULL || search_str == NULL || replace_str == NULL || *filename == '\0')
    {
        return EINVAL; // invalid argument
    }

    // 1. 创建一个唯一的临时文件名
    char temp_filename[] = "./.tmp_XXXXXX";
    int fd = mkstemp(temp_filename);
    if (fd == -1)
    {
        perror("mkstemp");
        return -1;
    }

    FILE *file_ptr = NULL;
    FILE *temp_file_ptr = NULL;

    // 2. 打开原始文件用于读取
    file_ptr = fopen(filename, "r");
    if (file_ptr == NULL)
    {
        char err[MSG_SIZE];
        strerror_r(errno, err, sizeof(err));
        fprintf(stderr, "r open failed: %s\n", err);
        return -1;
    }

    // 3. 打开临时文件用于写入
    temp_file_ptr = fopen(temp_filename, "w");
    if (temp_file_ptr == NULL)
    {
        fclose(file_ptr);
        return -1;
    }

    char buffer[BUFFER_SIZE];
    int found = 0;

    // 4. 逐行读取原文件, 处理后写入临时文件
    while (fgets(buffer, BUFFER_SIZE, file_ptr) != NULL)
    {
        if (found == 0 && strstr(buffer, search_str) != NULL)
        {
            found = 1;
            fprintf(temp_file_ptr, "%s\n", replace_str);
        }
        else
        {
            fputs(buffer, temp_file_ptr);
        }
    }

    fclose(file_ptr);
    fclose(temp_file_ptr);

    // 5. 如果找到匹配项, 则用新文件替换旧文件
    if (found)
    {
        // 删除原文件
        if (remove(filename) != 0)
        {
            char err[MSG_SIZE];
            strerror_r(errno, err, sizeof(err));
            fprintf(stderr, "remove original file failed: %s\n", err);
            remove(temp_filename); // 尽力清理
            return -1;
        }
        // 删除临时文件重命名覆盖原文件
        if (rename(temp_filename, filename) != 0)
        {
            char err[MSG_SIZE];
            strerror_r(errno, err, sizeof(err));
            fprintf(stderr, "remove original file failed: %s\n", err);
            remove(temp_filename); // 尽力清理
            return -1;
        }
    }
    else
    {
        remove(temp_filename); // 未找到匹配项, 删除临时文件
        return ENOENT; // "No such file or directory" or, in this context, "entry not found"
    }

    return 0; // Success
}

