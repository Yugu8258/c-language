#include "generic_queue.h"

#include <stdlib.h>
#include <string.h>

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

void queue_print(GenericQueue *queue);

