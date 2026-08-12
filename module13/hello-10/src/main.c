#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void add_string(char ***array, int *size, char *str);

void print_string(char **array, int size);

int main(void)
{
    char **str_array = NULL; // 初始化字符串数组

    int size = 0;

    add_string(&str_array, &size, "Hello,");
    add_string(&str_array, &size, " Wrold");
    add_string(&str_array, &size, "!");

    print_string(str_array, size);

    for (size_t i = 0; i < size; ++i)
    {
        free(str_array[i]);
    }
    free(str_array);

    return EXIT_SUCCESS;
}

void add_string(char ***array, int *size, char *str)
{
    char **temp = (char **)realloc(*array, (*size + 1) * sizeof(char *));

    if (temp == NULL)
    {
        printf("Failed to allocate memory!\n");
        return;
    }

    *array = temp;

    // 分配内存并且复制字符串
    (*array)[*size] = (char *)malloc(strlen(str) + 1);
    if ((*array)[*size] == NULL)
    {
        perror("malloc string failed");
        return;
    }

    strcpy((*array)[*size], str);
    (*size)++;
}

void print_string(char **array, int size)
{
    for (size_t i = 0; i < size; ++i)
    {
        printf("%s", array[i]);
    }
    printf("\n");
}

