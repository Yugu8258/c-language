#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>

int main(void)
{
    /**
     * 公司内部的权限问题
     * 员工可以访问不同的系统资源, 这取决与他们的职位和完成数量. 权限规则如下:
     *
     *  1. 经理Manager总是可以访问所有的资源
     *  2. 普通员工Employee如果完成5个以上的任务以后, 则可以访问资源
     *  3. 实习生Intern如果完成10个以上的任务, 必须经过经理的批准才能访问
     */

    uint8_t role = 2; // 1->Manager; 2->Employee; 3->Intern

    uint8_t completed_tasks = 6; // 完成任务的数量
    
    bool is_manager_approved = false; // 经理是否批准

    // 访问允许
    bool access_allowed = false;

    switch (role)
    {
        case 1: // role = 1 Manager
            access_allowed = true;
            break; // 跳出
        case 2: // role = 2 Employee
            if (completed_tasks >= 5)
            {
                access_allowed = true;
            }
            break;
        case 3: // role = 3 Intern
            if (completed_tasks >= 10 && is_manager_approved)
            {
                access_allowed = true;
            }
            break;
        // ....
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

