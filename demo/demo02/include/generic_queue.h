#pragma once

#include "type_definitions.h"

#include <stdbool.h>

// 泛型队列节点结构体
typedef struct GenericQueueNode
{
    GenericValue value;             // 存储实际的数据
    DataType type;                  // 数据类型
    struct GenericQueueNode *next;  // 指向下一个节点的指针
} GenericQueueNode;

typedef struct
{
    GenericQueueNode *head;
    GenericQueueNode *tail;
    size_t size;
} GenericQueue;

GenericQueue *queue_create(void);

void queue_destroy(GenericQueue *queue);

bool queue_enqueue(GenericQueue *queue, GenericValue value, DataType type);

bool queue_dequeue(GenericQueue *queue, GenericValue *value, DataType *type);

size_t queue_size(const GenericQueue *queue);

bool queue_is_empty(GenericQueue *queue);

void queue_print(GenericQueue *queue);

