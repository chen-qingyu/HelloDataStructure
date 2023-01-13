#include "LinkedQueue.h"

#include <limits.h> // INT_MAX
#include <stdlib.h> // malloc free NULL

#include "../common/check_empty.h"
#include "../common/check_full.h"
#include "../common/check_pointer.h"

struct LinkedQueueNode
{
    /// Data stored in the node.
    LinkedQueueItem data;

    /// Successor.
    struct LinkedQueueNode* next;
};

struct LinkedQueue
{
    /// Number of elements.
    int size;

    /// Pointer to the front element.
    struct LinkedQueueNode* front;

    /// Pointer to the rear element.
    struct LinkedQueueNode* rear;
};

/*******************************
Helper functions implementation.
*******************************/

/*******************************
Interface functions implementation.
*******************************/

LinkedQueue* LinkedQueue_Create(void)
{
    LinkedQueue* queue = (LinkedQueue*)malloc(sizeof(LinkedQueue));
    check_pointer(queue);

    queue->front = (struct LinkedQueueNode*)malloc(sizeof(struct LinkedQueueNode));
    check_pointer(queue->front);

    queue->rear = queue->front;
    queue->front->next = NULL;
    queue->size = 0;

    return queue;
}

void LinkedQueue_Destroy(LinkedQueue* self)
{
    while (self->front)
    {
        struct LinkedQueueNode* current = self->front->next;
        free(self->front);
        self->front = current;
    }
    free(self);
}

int LinkedQueue_Size(const LinkedQueue* self)
{
    return self->size;
}

bool LinkedQueue_IsEmpty(const LinkedQueue* self)
{
    return self->size == 0;
}

void LinkedQueue_Enqueue(LinkedQueue* self, LinkedQueueItem data)
{
    check_full(self->size, INT_MAX);

    struct LinkedQueueNode* add = (struct LinkedQueueNode*)malloc(sizeof(struct LinkedQueueNode));
    check_pointer(add);

    add->data = data;
    add->next = NULL;

    self->rear->next = add;
    self->rear = add;

    ++self->size;
}

LinkedQueueItem LinkedQueue_Dequeue(LinkedQueue* self)
{
    check_empty(self->size);

    if (self->rear == self->front->next)
    {
        self->rear = self->front;
    }

    struct LinkedQueueNode* del = self->front->next;
    LinkedQueueItem data = del->data;

    self->front->next = del->next;
    free(del);

    --self->size;

    return data;
}

LinkedQueueItem LinkedQueue_Front(LinkedQueue* self)
{
    check_empty(self->size);

    return self->front->next->data;
}
