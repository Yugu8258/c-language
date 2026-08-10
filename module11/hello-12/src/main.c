#define _XOPEN_SOURCE 700

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define LINE_BUF_LEN 256

void write_over_fiel(const char *filename, const char *text);

int main(void)
{
    const char *file = "log.txt";
    const char *msg = "server start success.\n";

    write_over_fiel(file, msg);

    return EXIT_SUCCESS;
}

void write_over_fiel(const char *filename, const char *text)
{
    if (filename == NULL || *filename == '\0' || text == NULL)
    {
        fprintf(stderr, "invalid argument.\n");
        exit(EXIT_FAILURE);
    }

    FILE *fp = fopen(filename, "w");
    if (fp == NULL)
    {
        char err_buf[LINE_BUF_LEN];
        strerror_r(errno, err_buf, sizeof(err_buf));
        fprintf(stderr, "open w failed: %s\n", err_buf);
        exit(EXIT_FAILURE);
    }

    fputs(text, fp);
    fflush(fp);

    if (ferror(fp))
    {
        perror("wirte error");
        fclose(fp);
        exit(EXIT_FAILURE);
    }

    if (fclose(fp) != 0)
    {
        perror("close failed.");
        exit(EXIT_FAILURE);
    }

    fp = NULL;
}

