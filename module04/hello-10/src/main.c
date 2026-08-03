#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>

bool check_access_for_manager(void);
bool check_access_for_emp(uint8_t completed_tasks);
bool check_access_for_intern(uint8_t completed_tasks, bool is_manager_approved);

int main(void)
{
    /**
     * 公司内部的权限问题
     * 员工可以访问不同的系统资源, 这取决与他们的职位和完成数量. 权限规则如下:
     *
     *  1. 经理Manager 总是可以访问所有资源
     *  2. 普通员工Employee如果完成5个以上的任务以后, 或者经理批准, 则可以访问资源
     *  3. 实习生Intern如果完成10个以上的任务一个, 必须经过经理的批准才能访问
     */

    uint8_t role = 2; // 1->Manager; 2->Employee; 3->Intern

    uint8_t completed_tasks = 6; // 完成任务的数量

    bool is_manager_approved = false; // 经理是否批准

    bool access_allowed = false; // 是否满足访问权限

    switch (role)
    {
        case 1:
            access_allowed = check_access_for_manager();
            break;
        case 2:
            access_allowed = check_access_for_emp(completed_tasks);
            break;
        case 3:
            access_allowed = check_access_for_intern(completed_tasks, is_manager_approved);
            break;
        default:
            access_allowed = false;
            break;
    }

    if (access_allowed)
    {
        puts("允许访问!");
    }
    else
    {
        puts("拒绝访问!");
    }

    return 0;
}

bool check_access_for_manager(void)
{
    return true;
}

bool check_access_for_emp(uint8_t completed_tasks)
{
    return completed_tasks >= 5;
}

bool check_access_for_intern(uint8_t completed_tasks, bool is_manager_approved)
{
    return completed_tasks >= 10 && is_manager_approved;
}

