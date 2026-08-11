#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    FILE *source_file = NULL;
    FILE *target_file = NULL;

    char source_path[] = "123.txt";
    char target_path[] = "234.txt";

    char buffer[1024];

    size_t bytes_read;

    source_file = fopen(source_path, "rb");
    if (source_file == NULL)
    {
        perror("无法打开源文件");
        return EXIT_FAILURE;
    }

    target_file = fopen(target_path, "wb");
    if (target_file == NULL)
    {
        perror("无法打开目标文件");
        fclose(source_file);
        return EXIT_FAILURE;
    }

    while ((bytes_read = fread(buffer, 1, sizeof(buffer), source_file)) > 0)
    {
        fwrite(buffer, 1, bytes_read, target_file);
    }

    fclose(source_file);
    fclose(target_file);

    return EXIT_SUCCESS;
}

