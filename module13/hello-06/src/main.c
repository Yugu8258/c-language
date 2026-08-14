#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char *name;
    int *taskList;
    int taskCount;
} Employee;

Employee *create_employee(const char *name, int taskCount);

void free_empoyee(Employee *employee);

int main(void)
{
    Employee *developer = create_employee("Dijia", 5);
    if (developer == NULL)
    {
        return EXIT_FAILURE;
    }

    developer->taskList[0] = 101;

    for (size_t i = 0; i < 5; ++i)
    {
        printf("Assigned Task ID for %s : %d\n", developer->name, developer->taskList[i]);
    }

    free_empoyee(developer);

    return EXIT_SUCCESS;
}

Employee *create_employee(const char *name, int taskCount)
{
    Employee *new_employee = (Employee *)malloc(sizeof(Employee));
    if (new_employee == NULL)
    {
        perror("Failed to allocate memory for new employee.");
        return NULL;
    }

    new_employee->name = (char *)malloc(strlen(name) + 1);
    if (new_employee->name == NULL)
    {
        perror("Failed to allocate memory for new employee name.");
        free(new_employee);
        return NULL;
    }

    size_t name_len = strlen(name);
    strncpy(new_employee->name, name, name_len);
    new_employee->name[name_len] = '\0';

    new_employee->taskList = (int *)calloc(taskCount, sizeof(int));
    if (new_employee->taskList == NULL)
    {
        perror("Failed to allocate memory for task list.");
        free(new_employee->name);
        free(new_employee);
        return NULL;
    }

    new_employee->taskCount = taskCount;
    
    return new_employee;
}

void free_empoyee(Employee *employee)
{
    if (employee != NULL)
    {
        free(employee->name);
        free(employee->taskList);
        free(employee);
    }
}

