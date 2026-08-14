#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <string.h>
#include <errno.h>

typedef enum
{
    SUCCESS = 0,
    MEMORY_ERROR,
    INVALID_PARAMS,
    DUPLICATE_ID,
    NOT_DOUND
} ErrorCode;

typedef struct
{
    uint32_t id;
    char *title; // 聚合 Aggregation
    // char title[50]; -> 动态分配的书名
    double price;
} Book;

// 析构 Destructor -> 析构函数 Cpp

// 组合 Composition 或 包含 Containment

// 动态数组 Dynamic Array
typedef struct
{
    size_t count;       // 当前书籍的数量
    size_t capacity;    // 当前可容纳的最大的书籍数量
    Book *books;        // 当前的书籍
    // Book books[50];
    // books -> 指向一个动态分配的书籍数组
    
    // Book book; // -> 嵌套, 在一个结构体里调用另一个结构体
} Library;

// 自引用 Self-Referencing
// 链式结构 Linked Structure

// 构造函数 Constructor
// Book create_book(uint32_t id, const char *title, double price);

// void print_book(Book *book)

// void free_book(Book *book);

void print_library(const Library *lib);

Library create_library(size_t initial_capacity, ErrorCode *error);

ErrorCode add_book(Library *lib, uint32_t id, const char *title, double price);

Book *find_book(const Library *lib, uint32_t id, ErrorCode *error);

void free_library(Library *lib);

int main(void)
{
    ErrorCode error;

    Library lib = create_library(2, &error);

    if (error != SUCCESS)
    {
        printf("创建图书馆失败, 错误码: %d\n", error);
        return 1;
    }

    error = add_book(&lib, 1, "C++", 560.00);
    if (error != SUCCESS)
    {
        printf("添加图书失败, 错误码: %d\n", error);
        free_library(&lib);
        return 1;
    }

    error = add_book(&lib, 2, "Java", 256.00);
    if (error != SUCCESS)
    {
        printf("添加图书失败, 错误码: %d\n", error);
        free_library(&lib);
        return 1;
    }

    error = add_book(&lib, 3, "Linux", 324.00);
    if (error != SUCCESS)
    {
        printf("添加图书失败, 错误码: %d\n", error);
        free_library(&lib);
        return 1;
    }

    print_library(&lib);

    free_library(&lib);

    return EXIT_SUCCESS;
}

/*
Book create_book(uint32_t id, const char *title, double price)
{
    Book book;
    book.id = id;
    book.title = (char *)malloc(strlen(title) + 1);
    if (book.title == NULL)
    {
        fprintf(stderr, "内存分配失败!\n");
        exit(EXIT_FAILURE);
    }

    strcpy(book.title, title);
    book.price = price;

    return book;
}
*/

/*
void print_book(Book *book)
{
    printf("Book ID: %" PRIu32 "\n", book->id);
    printf("Book Title: %s\n", book->title);
    printf("Book Price: %lf\n", book->price);
}
*/

/*
void free_book(Book *book)
{
    if (book->title != NULL)
    {
        free(book->title);
        book->title = NULL;
    }
}
*/

Library create_library(size_t initial_capacity, ErrorCode *error)
{
    Library lib = { 0 };

    if (initial_capacity == 0)
    {
        *error = INVALID_PARAMS;
        return lib;
    }

    lib.books = (Book *)malloc(initial_capacity * sizeof(Book));
    if (lib.books == NULL)
    {
        *error = MEMORY_ERROR;
        return lib;
    }

    lib.count = 0;
    lib.capacity = initial_capacity;

    *error = SUCCESS;
    
    return lib;
}

ErrorCode add_book(Library *lib, uint32_t id, const char *title, double price)
{
    if (lib == NULL || title == NULL || price < 0)
    {
        return INVALID_PARAMS;
    }
    
    for (size_t i = 0; i < lib->count; i++)
    {
        if (lib->books[i].id == id)
        {
            return DUPLICATE_ID;
        }
    }

    // 是否需要扩容
    if (lib->count >= lib->capacity)
    {
        size_t new_capacity = lib->capacity << 1;
        Book *temp = (Book *)realloc(lib->books, new_capacity * sizeof(Book));
        if (temp == NULL)
        {
            return MEMORY_ERROR;
        }

        lib->books = temp;
        lib->capacity = new_capacity;
    }

    // 分配书名的内存
    char *new_title = (char *)malloc(strlen(title) + 1);
    if (new_title == NULL)
    {
        return MEMORY_ERROR;
    }
    strcpy(new_title, title);

    lib->books[lib->count].id = id;
    lib->books[lib->count].title = new_title;
    lib->books[lib->count].price = price;
    
    lib->count++;

    return SUCCESS;
}

Book *find_book(const Library *lib, uint32_t id, ErrorCode *error)
{
    if (lib == NULL)
    {
        *error = INVALID_PARAMS;
        return NULL;
    }

    for (size_t i = 0; i < lib->count; i++)
    {
        if (lib->books[i].id == id)
        {
            *error = SUCCESS;
            return &lib->books[i];
        }
    }

    *error = NOT_DOUND;
    return NULL;
}

void print_library(const Library *lib)
{
    if (lib == NULL)
    {
        printf("错误: 无效的图书馆!\n");
        return;
    }

    printf("\n图书馆藏书数量: %" PRIuMAX "\n", lib->count);
    for (size_t i = 0; i < lib->count; i++)
    {
        printf("书籍 #%" PRIuMAX "\n", i + 1);
        printf("\tID: %" PRIu32 "\n", lib->books[i].id);
        printf("\tTitle: %s\n", lib->books[i].title);
        printf("\tPrice: $%.2lf\n", lib->books[i].price);
        printf("--------------------\n");
    }

}

void free_library(Library *lib)
{
    if (lib == NULL || lib->books == NULL) { return; }

    if (lib->books)
    {
        for (size_t i = 0; i < lib->count; i++)
        {
            if (lib->books[i].title)
            {
                free(lib->books[i].title);
                lib->books[i].title = NULL;
            }
        }
        free(lib->books);
    }

    lib->books = NULL;
    lib->count = 0;
    lib->capacity = 0;
}

