#include <stdio.h>
#include <stdlib.h>

typedef struct queueElement
{
    int value;
    struct queueElement *next;
} queueElement;

typedef struct
{
    queueElement *head;
    queueElement *tail;
} Queue;

void initQueue(Queue *q)
{
    q->head = NULL;
    q->tail = NULL;
}

void enqueue(Queue *q, int value)
{
    queueElement *queueElementIn = malloc(sizeof *queueElementIn);
    queueElementIn->value = value;
    queueElementIn->next = NULL;

    if (q->head == NULL)
    {
        q->head = queueElementIn;
        q->tail = queueElementIn;
    }
    else
    {
        q->tail->next = queueElementIn;
        q->tail = queueElementIn;
    }
}

int dequeue(Queue *q)
{
    if (q->head == NULL)
    {
        return -1;
    }

    queueElement *queueElementOut = q->head;
    int value = queueElementOut->value;
    q->head = queueElementOut->next;

    if (q->head == NULL)
    {
        q->tail = NULL;
    }

    free(queueElementOut);

    return value;
}

void deleteQueue(Queue *q)
{
    while (q->head != NULL)
    {
        dequeue(q);
    }
}

int main()
{

    Queue *queue = malloc(sizeof *queue);
    if (!queue)
    {
        return 1;
    }

    initQueue(queue);

    enqueue(queue, 10);
    enqueue(queue, 4);

    printf("%d\n", dequeue(queue));
    printf("%d\n", dequeue(queue));

    deleteQueue(queue);

    free(queue);
}