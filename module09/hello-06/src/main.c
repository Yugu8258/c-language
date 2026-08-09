#include <stdio.h>
#include <inttypes.h>

typedef struct
{
    char street[50];
    char city[50];
    char country[50];
} Address;

typedef struct
{
    char name[50];
    uint32_t age;
    Address address; // 嵌套结构体
} Person;

int main(void)
{
    Person Jim = { "Jim", 42, { "SAIO", "WENGEHUA", "CANADA" }};

    printf("Name: %s\n", Jim.name);
    printf("Age: %" PRIu32 "\n", Jim.age);
    printf("Address: %s, %s, %s\n", Jim.address.street, Jim.address.city, Jim.address.country);

    Person *ptr = &Jim;
    
    printf("Name: %s\n", ptr->name);
    printf("Age: %" PRIu32 "\n", ptr->age);
    printf("Address: %s, %s, %s\n", ptr->address.street, ptr->address.city, ptr->address.country);

    return 0;
}

