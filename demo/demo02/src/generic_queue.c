#include "generic_queue.h"

#include <stdlib.h>
#include <stdio.h>

GenericQueue *queue_create(void)
{
    GenericQueue *queue = (GenericQueue *)malloc(sizeof(GenericQueue));
    if (queue == NULL) { return NULL; }

    queue->head = queue->tail = NULL;

    queue->size = 0;

    return queue;
}

void queue_destroy(GenericQueue *queue)
{
    if (queue == NULL) { return; }

    GenericQueueNode *current = queue->head;

    while (current != NULL)
    {
        GenericQueueNode *next = current->next;
        free(current);
        current = next;
    }

    free(queue);
}

bool queue_enqueue(GenericQueue *queue, GenericValue value, DataType type)
{
    if (queue == NULL) { return false; }

    GenericQueueNode *new_node = (GenericQueueNode *)malloc(sizeof(GenericQueueNode));

    if (new_node == NULL) { return false; }

    new_node->value = value;
    new_node->type = type;
    new_node->next = NULL;

    if (queue->tail == NULL)
    {
        queue->head = queue->tail = new_node;
    }
    else
    {
        queue->tail->next = new_node;
        queue->tail = new_node;
    }

    queue->size++;

    return true;
}

bool queue_dequeue(GenericQueue *queue, GenericValue *value, DataType *type)
{
    if (queue == NULL || queue->head == NULL) { return false; }
    if (value == NULL || type == NULL) { return false; }

    GenericQueueNode *node_to_remove = queue->head;

    *value = node_to_remove->value;
    *type = node_to_remove->type;
    
    queue->head = queue->head->next;
    if (queue->head == NULL)
    {
        queue->tail = NULL;
    }

    free(node_to_remove);
    queue->size--;

    return true;
}

size_t queue_size(const GenericQueue *queue)
{
    return queue ? queue->size : 0;
}

bool queue_is_empty(GenericQueue *queue)
{
    return queue ? (queue->size == 0) : true;
}

void queue_print(GenericQueue *queue)
{
    if (queue == NULL || queue_is_empty(queue))
    {
        printf("Queue empty or null.\n");
        return;
    }

    GenericQueueNode *cur = queue->head;
    size_t idx = 0;

    while (cur)
    {
        printf("[%zu] type:%d ", idx++, cur->type);
        switch (cur->type)
        {
            case TYPE_I32:  printf("%d", cur->value.i32Value);                          break;
            case TYPE_U32:  printf("%u", cur->value.u32Value);                          break;
            case TYPE_I64:  printf("%lld", (long long)cur->value.i64Value);             break;
            case TYPE_U64:  printf("%llu", (unsigned long long)cur->value.u64Value);    break;
            case TYPE_F32:  printf("%f", cur->value.f32Value);                          break;
            case TYPE_F64:  printf("%lf", cur->value.f64Value);                         break;
            case TYPE_CHAR: printf("'%c'", cur->value.charValue);                       break;
            case TYPE_PTR:  printf("%p", cur->value.ptrValue);                          break;
            default:        printf("unknown");                                          break;
        }
        printf("\n");
        cur = cur->next;
    }
}

