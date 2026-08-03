#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>

int main(void)
{
    /**
     *  公司内部的权限问题
     *  员工可以访问不同的系统资源, 这取决与他们的职位和完成数量, 权限规则如下:
     *
     *  1. 经理Manager总是可以访问所有的资源.
     *  2. 普通员工Employee如果完成5个以上的任务以后, 或者经理批准, 则可以访问资源
     *  3. 实习生Intern如果完成10个以上的任务以后, 必须经过经理的批准以后, 则可以访问资源
     */

    uint8_t role = 2; // 1->Manger; 2->Employee; 3->Intern

    uint8_t completed_tasks = 6; // 完成的任务数量

    bool is_manager_approved = false; // 经理批准

    // 检查允许访问的条件 
    bool access_allowed = (role == 1) || (((role == 2) && completed_tasks >= 5 ) || is_manager_approved) || (role == 3 && completed_tasks >= 10 && is_manager_approved);

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

