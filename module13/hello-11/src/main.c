#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node * next;
} Node;

// CRUD函数声明
void add_at_tail(Node **head, int data);                // 尾插
void add_at_head(Node **head, int data);                // 头插
int insert_at_index(Node **head, int idx, int data);    // 指定下标插入
Node *find_node(Node *head, int val);                   // 按值查找
int update_by_index(Node *head, int idx, int new_val);  // 修改下标数据
void delete_head(Node **head);                          // 删除头结点
void delete_tail(Node **head);                          // 删除尾节点
int delete_by_index(Node **head, int idx);              // 按下标删除
int delete_by_value(Node **head, int val);              // 删除第一个匹配值
void print_list(Node *head);                            // 遍历打印
void clear_list(Node **head);                           // 清空整条链表

int main(void)
{
    // 动态数据机构的管理, 函数修改指向结构体的指针, 轻松添加修改删除节点, 不需要返回额外新的头指针
    Node *head = NULL;

    add_at_tail(&head, 10);
    add_at_tail(&head, 20);
    add_at_tail(&head, 30);
    printf("尾插 10, 20, 30:");
    print_list(head);

    add_at_head(&head, 5);
    printf("头插 5:");
    print_list(head);

    insert_at_index(&head, 2, 15);
    printf("下标2插入15:");
    print_list(head);

    update_by_index(head, 3, 25);
    printf("下标3修改为25:");
    print_list(head);
    
    delete_by_index(&head, 1);
    printf("删除下标1:");
    print_list(head);

    delete_by_value(&head, 25);
    printf("删除值25:");
    print_list(head);

    delete_head(&head);
    printf("删除头节点:");
    print_list(head);

    delete_tail(&head);
    printf("删除尾节点:");
    print_list(head);

    clear_list(&head);
    printf("清空链表: ");
    print_list(head);
    
    return EXIT_SUCCESS;
}

void add_at_tail(Node **head, int data)
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    if (new_node == NULL)
    {
        perror("Faild to allocate memory for new node\n");
        return;
    }

    new_node->data = data;
    new_node->next = *head;     // 新节点指向原头结点
    *head = new_node;           // 更新头结点为新节点
}


void add_at_head(Node **head, int data)
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    if (new_node == NULL)
    {
        perror("malloc new node failed");
        return;
    }

    new_node->data = data;
    new_node->next = NULL;

    if (*head == NULL)
    {
        *head = new_node;
        return;
    }

    Node *cur = *head;
    while (cur->next != NULL)
    {
        cur = cur->next;
    }
    cur->next = new_node;
}

int insert_at_index(Node **head, int idx, int data)
{
    if (idx < 0) { return 0; }

    if (idx == 0)
    {
        add_at_head(head, data);
        return 1;
    }

    Node *cur = *head;
    int pos = 0;
    while (cur != NULL && pos < idx - 1)
    {
        cur = cur->next;
        pos++;
    }
    if (cur == NULL) { return 0; } // 下标越界

    Node *new_node = (Node *)malloc(sizeof(Node));
    if (new_node == NULL)
    {
        perror("malloc failed");
        return 0;
    }

    new_node->data = data;
    new_node->next = cur->next;
    cur->next = new_node;

    return 1;
}

Node *find_node(Node *head, int val)
{
    Node *cur = head;
    while (cur != NULL)
    {
        if (cur->data == val)
        {
            return cur;
        }
        cur = cur->next;
    }

    return NULL;
}

int update_by_index(Node *head, int idx, int new_val)
{
    if (idx < 0) { return 0; }

    Node *cur = head;
    int pos = 0;
    while (cur != NULL && pos < idx)
    {
        cur = cur->next;
        pos++;
    }

    if (cur == NULL) { return 0; }

    cur->data = new_val;

    return 1;
}

void delete_head(Node **head)
{
    if (*head == NULL) { return; }

    Node *temp = *head;
    *head = (*head)->next;
    free(temp);
}

void delete_tail(Node **head)
{
    if (*head == NULL) { return; }

    // 只有一个节点
    if ((*head)->next == NULL)
    {
        free(*head);
        *head = NULL;
        return;
    }

    Node *cur = *head;
    while (cur->next->next != NULL)
    {
        cur = cur->next;
    }
    free(cur->next);
    cur->next = NULL;
}

int delete_by_index(Node **head, int idx)
{
    if (idx < 0 || *head == NULL) { return 0; }
    
    if (idx == 0)
    {
        delete_head(head);
        return 1;
    }

    Node *cur = *head;
    int pos = 0;
    while (cur->next != NULL && pos < idx - 1)
    {
        cur = cur->next;
        pos++;
    }
    if (cur->next == NULL) { return 0; }
    
    Node *temp = cur->next;
    cur->next = temp->next;

    free(temp);

    return 1;
}

int delete_by_value(Node **head, int val)
{
    if (*head == NULL) { return 0; }

    // 头结点匹配
    if ((*head)->data == val)
    {
        delete_head(head);
        return 1;
    }

    Node *cur = *head;
    while (cur->next != NULL && cur->next->data != val)
    {
        cur = cur->next;
    }
    if (cur->next == NULL) { return 0; }

    Node *temp = cur->next;
    cur->next = temp->next;
    free(temp);

    return 1;
}

void print_list(Node *head)
{
    Node *current = head;
    while (current != NULL)
    {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

void clear_list(Node **head)
{
    Node *temp;
    while (*head != NULL)
    {
        temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}

