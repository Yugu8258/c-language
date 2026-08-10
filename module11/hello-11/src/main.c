#define _XOPEN_SOURCE 700

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define LINE_BUF_LEN 256

void append_log_safe(const char *filename, const char *msg);

int main(void)
{
    // a模式追加

    const char *filename = "log.txt";

    const char *str = "select * from student;";

    append_log_safe(filename, str);

    return 0;
}

void append_log_safe(const char *filename, const char *msg)
{
    if (filename == NULL || *filename == '\0' || msg == NULL)
    {
        fprintf(stderr, "Error: file name invalid\n");
        exit(EXIT_FAILURE);
    }

    FILE *file_ptr = NULL;
    file_ptr = fopen(filename, "a");
    if (file_ptr == NULL)
    {
        char error_msg[LINE_BUF_LEN];
        strerror_r(errno, error_msg, sizeof(error_msg));
        fprintf(stderr, "Failed to open file for append: %s\n", error_msg);
        exit(EXIT_FAILURE);
    }

    fputs(msg, file_ptr);
    fflush(file_ptr); // 强制刷新缓冲区

    if (ferror(file_ptr))
    {
        char error_msg[LINE_BUF_LEN];
        strerror_r(errno, error_msg, sizeof(error_msg));
        fprintf(stderr, "Append write error: %s\n", error_msg);
        fclose(file_ptr);
        exit(EXIT_FAILURE);
    }

    if (fclose(file_ptr) != 0)
    {
        perror("Error closing file.");
        exit(EXIT_FAILURE);
    }

    file_ptr = NULL;
}

